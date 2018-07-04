#include "brakestatepage.h"
#include "ui_brakestatepage.h"
#include <QDebug>
#include "vehiclelogo.h"
#include "global.h"

#define _RUN ("font: 15px; color: rgb(0,0,0); background-color: rgb(0, 255, 0); border: 2px groove, gray; border-color: gray;")
#define _OFFLINE ("font: 15px; color: rgb(0,0,0); background-color: white; border: 2px groove, gray; border-color: gray;")
#define _STOP ("font: 15px; color: white; background-color: black; border: 2px groove, gray; border-color: gray;")
#define _EMERGENCY_BRAKE ("image: url(:/image/STOP.png); border: 2px groove, gray; border-color: gray;")
#define _DARKRED ("font: 15px; color: white; background-color: rgb(153,0,51); border: 2px groove, gray; border-color: gray;")


BrakeStatePage::BrakeStatePage(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::BrakeStatePage)
{
    ui->setupUi(this);
    _LOG << "BrakeStatePage constructor";
    this->vehicleLogo = new VehicleLogo(this);
    this->vehicleLogo->setGeometry(0, 10, this->vehicleLogo->width(), this->vehicleLogo->height());
    this->airBrake1 = false;
    this->airBrake2 = false;
    this->airBrake3 = false;
    this->airBrake4 = false;
    this->airBrake5 = false;
    this->airBrake6 = false;
    this->airBrake7 = false;
    this->airBrake8 = false;
    this->parkBrake1 = false;
    this->parkBrake2 = false;
    this->parkBrake3 = false;
    this->parkBrake4 = false;
}

BrakeStatePage::~BrakeStatePage()
{
    delete ui;
}

void BrakeStatePage::updatePage()
{
    this->vehicleLogo->updateVehicleState(this->database->CTHM_TC1Active, this->database->CTHM_TC2Active, this->database->CTHM_Forward, this->database->CTHM_Backward,
    this->database->CTHM_Mp1RIOMGWOn, this->database->CTHM_Mp2RIOMGWOn, this->database->RIOM3_DIM1Ch18, this->database->RIOM3_DIM1Ch19, this->database->RIOM4_DIM1Ch18,
    this->database->RIOM4_DIM1Ch19, this->database->DICT_Tc1DI1I15AllDoorClosed_A1 | this->database->DICT_Tc2DI1I15AllDoorClosed_A2);
    this->vehicleLogo->updateVehicleNo(this->database->lineNo, this->database->vehicleNo);
    this->vehicleLogo->updateHSCB(this->database->TR3CT_HSCBState, this->database->TR4CT_HSCBState);
    this->electBrakeCutOff(ui->label_car2ElecBrakeCutOff, this->database->getBool(0xF410, 28, 0));
    this->electBrakeCutOff(ui->label_car3ElecBrakeCutOff, this->database->getBool(0xF440, 28, 0));
    this->getLoad(ui->label_car1Load1, this->database->getSignedInt(0xF410, 2));
    this->getLoad(ui->label_car1Load2, this->database->getSignedInt(0xF410, 4));
    this->getLoad(ui->label_car2Load1, this->database->getSignedInt(0xF410, 10));
    this->getLoad(ui->label_car2Load2, this->database->getSignedInt(0xF410, 12));
    this->getLoad(ui->label_car3Load1, this->database->getSignedInt(0xF440, 10));
    this->getLoad(ui->label_car3Load2, this->database->getSignedInt(0xF440, 12));
    this->getLoad(ui->label_car4Load1, this->database->getSignedInt(0xF440, 2));
    this->getLoad(ui->label_car4Load2, this->database->getSignedInt(0xF440, 4));

    //this->getZeroSpeed(ui->label_car1ZeroSpeed, this->database->getBool(0x410, 28, 5) && this->database->getBool(0x430, 28, 5));
    //this->getZeroSpeed(ui->label_car3ZeroSpeed, this->database->getBool(0x440, 28, 5) && this->database->getBool(0x460, 28, 5));

    this->getAirReedPress(ui->label_car1AirReedPress1_1, this->database->getSignedInt(0xF411, 0));
    this->getAirReedPress(ui->label_car1AirReedPress1_2, this->database->getSignedInt(0xF411, 14));
    this->getAirReedPress(ui->label_car1AirReedPress2_1, this->database->getSignedInt(0xF411, 16));
    this->getAirReedPress(ui->label_car1AirReedPress2_2, this->database->getSignedInt(0xF411, 30));

    this->getAirReedPress(ui->label_car2AirReedPress1_1, this->database->getSignedInt(0xF412, 0));
    this->getAirReedPress(ui->label_car2AirReedPress1_2, this->database->getSignedInt(0xF412, 14));
    this->getAirReedPress(ui->label_car2AirReedPress2_1, this->database->getSignedInt(0xF412, 16));
    this->getAirReedPress(ui->label_car2AirReedPress2_2, this->database->getSignedInt(0xF412, 30));

    this->getAirReedPress(ui->label_car3AirReedPress1_1, this->database->getSignedInt(0xF442, 0));
    this->getAirReedPress(ui->label_car3AirReedPress1_2, this->database->getSignedInt(0xF442, 14));
    this->getAirReedPress(ui->label_car3AirReedPress2_1, this->database->getSignedInt(0xF442, 16));
    this->getAirReedPress(ui->label_car3AirReedPress2_2, this->database->getSignedInt(0xF442, 30));

    this->getAirReedPress(ui->label_car4AirReedPress1_1, this->database->getSignedInt(0xF441, 0));
    this->getAirReedPress(ui->label_car4AirReedPress1_2, this->database->getSignedInt(0xF441, 14));
    this->getAirReedPress(ui->label_car4AirReedPress2_1, this->database->getSignedInt(0xF441, 16));
    this->getAirReedPress(ui->label_car4AirReedPress2_2, this->database->getSignedInt(0xF441, 30));

//    this->getAxleSlid(ui->label_car1AxleSlid1, this->database->getBool(0xF411, 12, 5));
//    this->getAxleSlid(ui->label_car1AxleSlid2, this->database->getBool(0xF411, 29, 5));
//    this->getAxleSlid(ui->label_car1AxleSlid3, this->database->getBool(0xF411, 28, 5));
//    this->getAxleSlid(ui->label_car1AxleSlid4, this->database->getBool(0xF411, 29, 6));

//    this->getAxleSlid(ui->label_car2AxleSlid1, this->database->getBool(0xF412, 12, 5));
//    this->getAxleSlid(ui->label_car2AxleSlid2, this->database->getBool(0xF412, 29, 5));
//    this->getAxleSlid(ui->label_car2AxleSlid3, this->database->getBool(0xF412, 28, 5));
//    this->getAxleSlid(ui->label_car2AxleSlid4, this->database->getBool(0xF412, 29 ,6));

//    this->getAxleSlid(ui->label_car3AxleSlid1, this->database->getBool(0xF440, 28, 0));
//    this->getAxleSlid(ui->label_car3AxleSlid2, this->database->getBool(0xF441, 29, 5));
//    this->getAxleSlid(ui->label_car3AxleSlid3, this->database->getBool(0xF441, 28, 5));
//    this->getAxleSlid(ui->label_car3AxleSlid4, this->database->getBool(0xF441, 29, 6));

//    this->getAxleSlid(ui->label_car4AxleSlid1, this->database->getBool(0xF442, 12, 5));
//    this->getAxleSlid(ui->label_car4AxleSlid2, this->database->getBool(0xF442, 29, 5));
//    this->getAxleSlid(ui->label_car4AxleSlid3, this->database->getBool(0xF442, 28, 5));
//    this->getAxleSlid(ui->label_car4AxleSlid4, this->database->getBool(0xF442, 29 ,6));

    this->getBCP(ui->label_cylPressureTc1_11, this->database->getSignedInt(0xF411, 8));
    this->getBCP(ui->label_cylPressureTc1_12, this->database->getSignedInt(0xF411, 10));
    this->getBCP(ui->label_cylPressureTc1_21, this->database->getSignedInt(0xF411, 24));
    this->getBCP(ui->label_cylPressureTc1_22, this->database->getSignedInt(0xF411, 26));
    this->getBCP(ui->label_cylPressureMp1_11, this->database->getSignedInt(0xF412, 8));
    this->getBCP(ui->label_cylPressureMp1_12, this->database->getSignedInt(0xF412, 10));
    this->getBCP(ui->label_cylPressureMp1_21, this->database->getSignedInt(0xF412, 24));
    this->getBCP(ui->label_cylPressureMp1_22, this->database->getSignedInt(0xF412, 26));

    this->getBCP(ui->label_cylPressureMp2_11, this->database->getSignedInt(0xF442, 8));
    this->getBCP(ui->label_cylPressureMp2_12, this->database->getSignedInt(0xF442, 10));
    this->getBCP(ui->label_cylPressureMp2_21, this->database->getSignedInt(0xF442, 24));
    this->getBCP(ui->label_cylPressureMp2_22, this->database->getSignedInt(0xF442, 26));
    this->getBCP(ui->label_cylPressureTc2_11, this->database->getSignedInt(0xF441, 8));
    this->getBCP(ui->label_cylPressureTc2_12, this->database->getSignedInt(0xF441, 10));
    this->getBCP(ui->label_cylPressureTc2_21, this->database->getSignedInt(0xF441, 24));
    this->getBCP(ui->label_cylPressureTc2_22, this->database->getSignedInt(0xF441, 26));

//    this->getAxleSpeed(ui->label_car1AxleSpeed, this->database->getSignedInt(0xF411, 4), this->database->getSignedInt(0xF411, 6),
//                       this->database->getSignedInt(0xF411, 20), this->database->getSignedInt(0xF411, 22));
//    this->getAxleSpeed(ui->label_car2AxleSpeed, this->database->getSignedInt(0xF412, 4), this->database->getSignedInt(0xF412, 6),
//                       this->database->getSignedInt(0xF412, 20), this->database->getSignedInt(0xF412, 22));
//    this->getAxleSpeed(ui->label_car3AxleSpeed, this->database->getSignedInt(0xF441, 4), this->database->getSignedInt(0xF441, 6),
//                       this->database->getSignedInt(0xF441, 20), this->database->getSignedInt(0xF441, 22));
//    this->getAxleSpeed(ui->label_car4AxleSpeed, this->database->getSignedInt(0xF442, 4), this->database->getSignedInt(0xF442, 6),
//                       this->database->getSignedInt(0xF442, 20), this->database->getSignedInt(0xF442, 22));
    this->getMainReservoirPress(ui->label_TotalWindPress1, this->database->getSignedInt(0xF413, 14));
    this->getMainReservoirPress(ui->label_TotalWindPress2, this->database->getSignedInt(0xF443, 14));

    this->getEmergencyBrake(ui->label_car1EmergencyBrake1, this->database->getBool(0xF411, 12, 7), this->database->getBool(0xF411, 13, 0));
    this->getEmergencyBrake(ui->label_car1EmergencyBrake2, this->database->getBool(0xF411, 28, 7), this->database->getBool(0xF411, 29, 0));
    this->getEmergencyBrake(ui->label_car2EmergencyBrake1, this->database->getBool(0xF412, 12, 7), this->database->getBool(0xF412, 13, 0));
    this->getEmergencyBrake(ui->label_car2EmergencyBrake2, this->database->getBool(0xF412, 28, 7), this->database->getBool(0xF412, 29, 0));
    this->getEmergencyBrake(ui->label_car3EmergencyBrake1, this->database->getBool(0xF442, 12, 7), this->database->getBool(0xF442, 13, 0));
    this->getEmergencyBrake(ui->label_car3EmergencyBrake2, this->database->getBool(0xF442, 28, 7), this->database->getBool(0xF442, 29, 0));
    this->getEmergencyBrake(ui->label_car4EmergencyBrake1, this->database->getBool(0xF441, 12, 7), this->database->getBool(0xF441, 13, 0));
    this->getEmergencyBrake(ui->label_car4EmergencyBrake2, this->database->getBool(0xF441, 28, 7), this->database->getBool(0xF441, 29, 0));

    this->getAirBrake(ui->label_airBrake11, this->database->getBool(0xF411, 12, 3), this->database->getBool(0xF411, 12, 4));
    this->getAirBrake(ui->label_airBrake12, this->database->getBool(0xF411, 28, 3), this->database->getBool(0xF411, 28, 4));
    this->getAirBrake(ui->label_airBrake21, this->database->getBool(0xF412, 12, 3), this->database->getBool(0xF412, 12, 4));
    this->getAirBrake(ui->label_airBrake22, this->database->getBool(0xF412, 28, 3), this->database->getBool(0xF412, 28, 4));
    this->getAirBrake(ui->label_airBrake32, this->database->getBool(0xF442, 28, 3), this->database->getBool(0xF442, 28, 4));
    this->getAirBrake(ui->label_airBrake31, this->database->getBool(0xF442, 12, 3), this->database->getBool(0xF442, 12, 4));
    this->getAirBrake(ui->label_airBrake42, this->database->getBool(0xF441, 28, 3), this->database->getBool(0xF441, 28, 4));
    this->getAirBrake(ui->label_airBrake41, this->database->getBool(0xF441, 12, 3), this->database->getBool(0xF441, 12, 4));

    this->getKeepBrake(ui->keepBrake11, this->database->getBool(0xF411, 13, 1));
    this->getKeepBrake(ui->keepBrake12, this->database->getBool(0xF411, 29, 1));
    this->getKeepBrake(ui->keepBrake21, this->database->getBool(0xF412, 13, 1));
    this->getKeepBrake(ui->keepBrake22, this->database->getBool(0xF412, 29, 1));
    this->getKeepBrake(ui->keepBrake31, this->database->getBool(0xF442, 13, 1));
    this->getKeepBrake(ui->keepBrake32, this->database->getBool(0xF442, 29, 1));
    this->getKeepBrake(ui->keepBrake41, this->database->getBool(0xF441, 13, 1));
    this->getKeepBrake(ui->keepBrake42, this->database->getBool(0xF441, 29, 1));

    this->setParkBrakeState(ui->stayBrake1, this->database->getBool(0xF410, 29, 7), this->database->getBool(0xF410, 29, 6));
    this->setParkBrakeState(ui->stayBrake2, this->database->getBool(0xF410, 27, 7), this->database->getBool(0xF410, 27, 6));
    this->setParkBrakeState(ui->stayBrake3, this->database->getBool(0xF440, 27, 7), this->database->getBool(0xF440, 27, 6));
    this->setParkBrakeState(ui->stayBrake4, this->database->getBool(0xF440, 29, 7), this->database->getBool(0xF440, 29, 6));
}

void BrakeStatePage::getEmergencyBrake(QLabel *label, bool active, bool available)
{
    if (active)
        label->setStyleSheet(_EMERGENCY_BRAKE);
    else if (available)
        label->setStyleSheet(_RUN);
    else
        label->setStyleSheet(_STOP);
}

void BrakeStatePage::electBrakeCutOff(QLabel *label, bool cutOff)
{
    if(cutOff)
    {
        label->setStyleSheet(_RUN);
        return;
    }
    else
    {
        label->setStyleSheet(_STOP);
        return;
    }
}
/*
view the maximal speed from four axles'
*/
void BrakeStatePage::getAxleSpeed(QLabel *label, signed short speed1, signed short speed2, signed short int speed3, signed short int speed4)
{
    signed short int axleSpeed1 = speed1 > speed2 ? speed1 : speed2;
    signed short int axleSpeed2 = speed3 > speed4 ? speed3 : speed4;
    signed short int axleSpeed = axleSpeed1 > axleSpeed2 ? axleSpeed1 : axleSpeed2;
    axleSpeed /= 100;
    label->setText(QString::number(axleSpeed * 0.01, 'f', 2));
    return;
}

void BrakeStatePage::getMainReservoirPress(QLabel *label, signed short press)
{
    label->setText(QString::number(press * 0.1, 'f', 1));
    return;
}

void BrakeStatePage::getAirReedPress(QLabel *label, signed short ASP)
{
    label->setText(QString::number(ASP * 0.1, 'f', 1));
    return;
}

void BrakeStatePage::getZeroSpeed(QLabel *label, bool zeroSpeed)
{
    if(zeroSpeed)
    {
        label->setStyleSheet(_RUN);
        return;
    }
    else
    {
        label->setStyleSheet(_STOP);
        return;
    }
}

void BrakeStatePage::getAxleSlid(QLabel *label, bool slid)
{

    if(slid)
    {
        label->setStyleSheet(_RUN);
        return;
    }
    else
    {
        label->setStyleSheet(_STOP);
    }
}

void BrakeStatePage::getLoad(QLabel *label, signed short load)
{
    {
        label->setStyleSheet(_STOP);
        label->setText(QString::number(load * 2));
    }
}

void BrakeStatePage::on_btn_EmergencyBroadcast_clicked()
{
    emit this->changePage(uEmergencyBroadcast);
}


void BrakeStatePage::getBCP(QLabel *label, signed short pressure)
{
    label->setText(QString::number(pressure * 0.1, 'f', 1));
}

void BrakeStatePage::getAirBrake(QLabel *label, bool release, bool apply)
{
    if(release)
    {
        label->setStyleSheet(_RUN);
        label->setText(QString(" "));
    }
    else if(apply)
    {
        label->setStyleSheet(_DARKRED);
        label->setText(QString(" "));
    }
    else
    {
        label->setStyleSheet(_STOP);
        label->setText(QString("无效"));
    }
}

void BrakeStatePage::getKeepBrake(QLabel *label, bool keep)
{
    if (keep)
    {
        label->setStyleSheet(_DARKRED);
    }
    else
    {
        label->setStyleSheet(_RUN);
    }
}



void BrakeStatePage::setParkBrakeState(QLabel *label, bool release, bool apply)
{
    if (release)
    {
       label->setStyleSheet(_RUN);
       label->setText(QString(" "));
    }
    else if (apply)
    {
       label->setStyleSheet(_DARKRED);
       label->setText(QString(" "));
    }
    else
    {
       label->setStyleSheet(_STOP);
       label->setText(QString("无效"));
    }
}
