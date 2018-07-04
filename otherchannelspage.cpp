#include "otherchannelspage.h"
#include "ui_otherchannelspage.h"
#include "vehiclelogo.h"
#include <QDebug>
#include "global.h"

#define _CLOSE ("font: 15px; color: rgb(0,0,0); background-color: rgb(0, 255, 0); border: 2px groove, gray; border-color: gray;")
#define _BRAKE ("font: 15px; color: rgb(0,0,0); background-color: yellow; border: 2px groove, gray; border-color: gray;")

OtherChannelsPage::OtherChannelsPage(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::OtherChannelsPage)
{
    ui->setupUi(this);
    _LOG << "OtherChannelsPage constructor";
    this->vehicleLogo = new VehicleLogo(this);
    this->vehicleLogo->setGeometry(0, 10, this->vehicleLogo->width(), this->vehicleLogo->height());
}

OtherChannelsPage::~OtherChannelsPage()
{
    delete ui;
}

void OtherChannelsPage::updatePage()
{
    this->vehicleLogo->updateVehicleState(this->database->CTHM_TC1Active, this->database->CTHM_TC2Active, this->database->CTHM_Forward, this->database->CTHM_Backward,
    this->database->CTHM_Mp1RIOMGWOn, this->database->CTHM_Mp2RIOMGWOn, this->database->RIOM3_DIM1Ch18, this->database->RIOM3_DIM1Ch19, this->database->RIOM4_DIM1Ch18,
    this->database->RIOM4_DIM1Ch19, this->database->DICT_Tc1DI1I15AllDoorClosed_A1 | this->database->DICT_Tc2DI1I15AllDoorClosed_A2);
    this->vehicleLogo->updateVehicleNo(this->database->lineNo, this->database->vehicleNo);
    this->vehicleLogo->updateHSCB(this->database->TR3CT_HSCBState, this->database->TR4CT_HSCBState);
    this->brakeNoRemission(ui->label_car1BrakeNoRemission, this->database->DICT_Tc1DI3I5BrkNotRelByPass_A1);
    this->brakeNoRemission(ui->label_car4BrakeNoRemission, this->database->DICT_Tc2DI3I5BrkNotRelByPass_A2);
    this->parkBrake(ui->label_car1ParkBrake, this->database->DICT_Tc1DI3I4ParkingBrkByPass_A1);
    this->parkBrake(ui->label_car4ParkBrake, this->database->DICT_Tc2DI3I4ParkingBrkByPass_A2);
    this->doorSafe(ui->label_car1DoorSafe, this->database->DICT_Tc1DI3I2DoorSafeByPass_A1);
    this->doorSafe(ui->label_car4DoorSafe, this->database->DICT_Tc2DI3I2DoorSafeByPass_A2);
    this->alert(ui->label_emeByPass1, this->database->DICT_Tc1DI3I3EmcByPass_A1);
    this->alert(ui->label_emeByPass4, this->database->DICT_Tc2DI3I3EmcByPass_A2);
    this->ATPCutOff(ui->label_car1ATPCutOff, this->database->DICT_Tc1DI4I3ATCCut_A1);
    this->ATPCutOff(ui->label_car4ATPCutOff, this->database->DICT_Tc2DI4I3ATCCut_A2);
}

void OtherChannelsPage::brakeNoRemission(QLabel *label, bool remission)
{
    if(remission)
    {
        label->setStyleSheet(_CLOSE);
        return;
    }
    else
    {
        label->setStyleSheet(_BRAKE);
        return;
    }
}

void OtherChannelsPage::parkBrake(QLabel *label, bool parkBrake)
{
    if(parkBrake)
    {
        label->setStyleSheet(_CLOSE);
        return;
    }
    else
    {
        label->setStyleSheet(_BRAKE);
        return;
    }
}

void OtherChannelsPage::doorSafe(QLabel *label, bool safe)
{
    if(safe)
    {
        label->setStyleSheet(_CLOSE);
        return;
    }
    else
    {
        label->setStyleSheet(_BRAKE);
        return;
    }
}

void OtherChannelsPage::alert(QLabel *label, bool alert)
{
    if(alert)
    {
        label->setStyleSheet(_CLOSE);
        return;
    }
    else
    {
        label->setStyleSheet(_BRAKE);
        return;
    }
}

void OtherChannelsPage::ATPCutOff(QLabel *label, bool cutoff)
{
    if(cutoff)
    {
        label->setStyleSheet(_CLOSE);
    }
    else
    {
        label->setStyleSheet(_BRAKE);
    }
}

void OtherChannelsPage::on_btn_EmergencyBroadcast_clicked()
{
    emit this->changePage(uEmergencyBroadcast);
}
