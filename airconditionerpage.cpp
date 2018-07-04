#include "airconditionerpage.h"
#include "ui_airconditionerpage.h"
#include <QDebug>
#include <QTimer>
#include <QButtonGroup>
#include "vehiclelogo.h"
#include "global.h"

enum vehicle_flag
{
    uWhole = 0,
    u1,
    u2,
    u3,
    u4
};

enum mode_flag
{
    uCease = 0,
    uAutoCold,
    uHalfCold,
    uWholeCold,
    uAutoHeat = 5,
    uHalfHeat,
    uWholeHeat,
    uVent = 9,
    uMergencyVent
};

enum newWind
{
    autoControl = 0,
    allClose,
    set13Wind,
    set23Wind,
    allOpen
};

enum windSpeed
{
    low = 0,
    high
};

#define _OFFLINE ("font: 15px; color: rgb(0,0,0); background-color: white; border: 2px groove, gray; border-color: gray;")
#define _OFF ("border-color: blue;")
#define _CUT ("font: 15px; color: rgb(0,0,0); background-image: url(:/image/cut.png); border: 2px groove, gray; border-color: gray;")
#define _FAULT ("font: 15px; color: rgb(0,0,0); background-color: red; border: 2px groove, gray; border-color: gray;")
#define _RUN ("font: 15px; color: rgb(0,0,0); background-color: rgb(0, 255, 0); border: 2px groove, gray; border-color: gray;")
#define _STOP ("font: 20px, SimHei;color: white; background-color: black; border: 2px groove, gray; border-color: gray;")

AirConditionerPage::AirConditionerPage(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::AirConditionerPage)
{
    ui->setupUi(this);
    _LOG << "AirConditionerPage constructor";
    this->vehicleLogo = new VehicleLogo(this);
    this->vehicleLogo->setGeometry(0, 10, this->vehicleLogo->width(), this->vehicleLogo->height());

    this->vehicleButtons = new QButtonGroup(this);
    this->vehicleButtons->addButton(ui->btn_wholeCar, uWhole);
    this->vehicleButtons->addButton(ui->btn_car1, u1);
    this->vehicleButtons->addButton(ui->btn_car2, u2);
    this->vehicleButtons->addButton(ui->btn_car3, u3);
    this->vehicleButtons->addButton(ui->btn_car4, u4);
    this->vehicleButtons->setExclusive(true);

    connect(this->vehicleButtons, SIGNAL(buttonClicked(int)), this, SLOT(selectVehicle(int)));

    this->currentVehicle = uWhole;
    this->vehicleButtons->button(uWhole)->setStyleSheet(BUTTON_DOWN);

    this->modeButtons = new QButtonGroup(this);
    this->modeButtons->addButton(ui->btn_Cease, 0);
    this->modeButtons->addButton(ui->btn_autoCold, 1);
    this->modeButtons->addButton(ui->btn_halfCold, 2);
    this->modeButtons->addButton(ui->btn_wholeCold, 3);
    this->modeButtons->addButton(ui->btn_autoHeat, 4);
    this->modeButtons->addButton(ui->btn_halfHeat, 5);
    this->modeButtons->addButton(ui->btn_wholeHeat, 6);
    this->modeButtons->addButton(ui->btn_Vent, 7);
    this->modeButtons->addButton(ui->btn_mergencyVent, 8);
    this->modeButtons->setExclusive(true);

    this->newWindButtons = new QButtonGroup(this);
    this->newWindButtons->addButton(ui->btn_autowind, autoControl);
    this->newWindButtons->addButton(ui->btn_ALLClose, allClose);
    this->newWindButtons->addButton(ui->btn_13NewWind, set13Wind);
    this->newWindButtons->addButton(ui->btn_23NewWind, set23Wind);
    this->newWindButtons->addButton(ui->btn_AllOpen, allOpen);
    this->newWindButtons->setExclusive(true);

    connect(this->modeButtons, SIGNAL(buttonClicked(int)), this, SLOT(selectMode(int)));
    connect(this->newWindButtons, SIGNAL(buttonClicked(int)), this, SLOT(selectWind(int)));
    //set default autoMode is autoHeat
    this->autoMode = false;

    //allow to set cold mode by default
    this->coldForbidden = false;
    this->temp = 18;
    ui->label_inputTemperature->setText(QString::number(this->temp));
    ui->btn_add->setEnabled(false);
    ui->btn_reduse->setEnabled(false);
    ui->btn_confirm->setEnabled(false);

    this->timerMode = new QTimer();
    this->timerMode->stop();
    connect(this->timerMode, SIGNAL(timeout()), this, SLOT(resetFlag()));

    this->timerTemp = new QTimer();
    this->timerTemp->stop();
    connect(this->timerTemp, SIGNAL(timeout()), this, SLOT(resetTempFlag()));

    this->timerWind = new QTimer();
    this->timerWind->stop();
    connect(this->timerWind, SIGNAL(timeout()), this, SLOT(resetWindFlag()));

    //ui->btn_Speed->setCheckable(true);

    this->windSpd = new QButtonGroup(this);
    this->windSpd->addButton(ui->btn_Speed_low, low);
    this->windSpd->addButton(ui->btn_Speed_high, high);
    this->windSpd->setExclusive(true);

    connect(this->windSpd, SIGNAL(buttonClicked(int)), this, SLOT(setSpeedState(int)));

    this->currentWind = 0;
    this->currentMode = 0;
    this->currentWindSpd = 0;
    //ui->btn_Speed->setText("低速");
}

AirConditionerPage::~AirConditionerPage()
{
    delete ui;
}

void AirConditionerPage::updatePage()
{
    this->vehicleLogo->updateVehicleState(this->database->CTHM_TC1Active, this->database->CTHM_TC2Active, this->database->CTHM_Forward, this->database->CTHM_Backward,
    this->database->CTHM_Mp1RIOMGWOn, this->database->CTHM_Mp2RIOMGWOn, this->database->RIOM3_DIM1Ch18, this->database->RIOM3_DIM1Ch19, this->database->RIOM4_DIM1Ch18,
    this->database->RIOM4_DIM1Ch19, this->database->DICT_Tc1DI1I15AllDoorClosed_A1 | this->database->DICT_Tc2DI1I15AllDoorClosed_A2);

    this->vehicleLogo->updateVehicleNo(this->database->lineNo, this->database->vehicleNo);
    this->vehicleLogo->updateHSCB(this->database->TR3CT_HSCBState, this->database->TR4CT_HSCBState);
    setControlState(ui->label_controlState1, this->database->CTHM_Tc1HVACOn, QString::number(this->database->AC1CT_Mode));
    setControlState(ui->label_controlState2, this->database->CTHM_Mp1HVACOn, QString::number(this->database->AC3CT_Mode));
    setControlState(ui->label_controlState3, this->database->CTHM_Mp2HVACOn, QString::number(this->database->AC4CT_Mode));
    setControlState(ui->label_controlState4, this->database->CTHM_Tc2HVACOn, QString::number(this->database->AC6CT_Mode));

    getTemperature(ui->label_setTemperature1, QString::number(this->database->AC1CT_TargetTemp));
    getTemperature(ui->label_setTemperature2, QString::number(this->database->AC3CT_TargetTemp));
    getTemperature(ui->label_setTemperature3, QString::number(this->database->AC4CT_TargetTemp));
    getTemperature(ui->label_setTemperature4, QString::number(this->database->AC6CT_TargetTemp));

    setControlMode(ui->label_control1, this->database->CTHM_Tc1HVACOn, this->database->AC1CT_WorkingStste);
    setControlMode(ui->label_control2, this->database->CTHM_Mp1HVACOn, this->database->AC3CT_WorkingStste);
    setControlMode(ui->label_control3, this->database->CTHM_Mp2HVACOn, this->database->AC4CT_WorkingStste);
    setControlMode(ui->label_control4, this->database->CTHM_Tc2HVACOn, this->database->AC6CT_WorkingStste);

//    getTemperature(ui->label_innerTemperature1, QString::number(this->database->AC1CT_TempInside - 40));
//    getTemperature(ui->label_innerTemperature2, QString::number(this->database->AC3CT_TempInside - 40));
//    getTemperature(ui->label_innerTemperature3, QString::number(this->database->AC4CT_TempInside - 40));
//    getTemperature(ui->label_innerTemperature4, QString::number(this->database->AC6CT_TempInside - 40));

//    getTemperature(ui->label_outerTemperature1, QString::number(this->database->AC1CT_TempOutside - 40));
//    getTemperature(ui->label_outerTemperature2, QString::number(this->database->AC3CT_TempOutside - 40));
//    getTemperature(ui->label_outerTemperature3, QString::number(this->database->AC4CT_TempOutside - 40));
//    getTemperature(ui->label_outerTemperature4, QString::number(this->database->AC6CT_TempOutside - 40));

    //compressor
    getEquipmentState(ui->label_pressure1_1, this->database->AC1CT_Compressor11State, this->database->AC1CT_Compressor11Fault);
    getEquipmentState(ui->label_pressure1_2, this->database->AC1CT_Compressor12State, this->database->AC1CT_Compressor12Fault);
    getEquipmentState(ui->label_pressure1_3, this->database->AC1CT_Compressor21State, this->database->AC1CT_Compressor21Fault);
    getEquipmentState(ui->label_pressure1_4, this->database->AC1CT_Compressor22State, this->database->AC1CT_Compressor22Fault);

    getEquipmentState(ui->label_pressure2_1, this->database->AC3CT_Compressor11State, this->database->AC3CT_Compressor11Fault);
    getEquipmentState(ui->label_pressure2_2, this->database->AC3CT_Compressor12State, this->database->AC3CT_Compressor12Fault);
    getEquipmentState(ui->label_pressure2_3, this->database->AC3CT_Compressor21State, this->database->AC3CT_Compressor21Fault);
    getEquipmentState(ui->label_pressure2_4, this->database->AC3CT_Compressor22State, this->database->AC3CT_Compressor22Fault);

    getEquipmentState(ui->label_pressure3_1, this->database->AC4CT_Compressor11State, this->database->AC4CT_Compressor11Fault);
    getEquipmentState(ui->label_pressure3_2, this->database->AC4CT_Compressor12State, this->database->AC4CT_Compressor12Fault);
    getEquipmentState(ui->label_pressure3_3, this->database->AC4CT_Compressor21State, this->database->AC4CT_Compressor21Fault);
    getEquipmentState(ui->label_pressure3_4, this->database->AC4CT_Compressor22State, this->database->AC4CT_Compressor22Fault);

    getEquipmentState(ui->label_pressure4_1, this->database->AC6CT_Compressor11State, this->database->AC6CT_Compressor11Fault);
    getEquipmentState(ui->label_pressure4_2, this->database->AC6CT_Compressor12State, this->database->AC6CT_Compressor12Fault);
    getEquipmentState(ui->label_pressure4_3, this->database->AC6CT_Compressor21State, this->database->AC6CT_Compressor21Fault);
    getEquipmentState(ui->label_pressure4_4, this->database->AC6CT_Compressor22State, this->database->AC6CT_Compressor22Fault);

    //conden
    getEquipmentState(ui->label_conden1_1, this->database->AC1CT_Conden11State, this->database->AC1CT_Conden11Fault);
    getEquipmentState(ui->label_conden1_2, this->database->AC1CT_Conden12State, this->database->AC1CT_Conden12Fault);
    getEquipmentState(ui->label_conden1_3, this->database->AC1CT_Conden21State, this->database->AC1CT_Conden21Fault);
    getEquipmentState(ui->label_conden1_4, this->database->AC1CT_Conden22State, this->database->AC1CT_Conden22Fault);

    getEquipmentState(ui->label_conden2_1, this->database->AC3CT_Conden11State, this->database->AC3CT_Conden11Fault);
    getEquipmentState(ui->label_conden2_2, this->database->AC3CT_Conden12State, this->database->AC3CT_Conden12Fault);
    getEquipmentState(ui->label_conden2_3, this->database->AC3CT_Conden21State, this->database->AC3CT_Conden21Fault);
    getEquipmentState(ui->label_conden2_4, this->database->AC3CT_Conden22State, this->database->AC3CT_Conden22Fault);

    getEquipmentState(ui->label_conden3_1, this->database->AC4CT_Conden11State, this->database->AC4CT_Conden11Fault);
    getEquipmentState(ui->label_conden3_2, this->database->AC4CT_Conden12State, this->database->AC4CT_Conden12Fault);
    getEquipmentState(ui->label_conden3_3, this->database->AC4CT_Conden21State, this->database->AC4CT_Conden21Fault);
    getEquipmentState(ui->label_conden3_4, this->database->AC4CT_Conden22State, this->database->AC4CT_Conden22Fault);

    getEquipmentState(ui->label_conden4_1, this->database->AC6CT_Conden11State, this->database->AC6CT_Conden11Fault);
    getEquipmentState(ui->label_conden4_2, this->database->AC6CT_Conden12State, this->database->AC6CT_Conden12Fault);
    getEquipmentState(ui->label_conden4_3, this->database->AC6CT_Conden21State, this->database->AC6CT_Conden21Fault);
    getEquipmentState(ui->label_conden4_4, this->database->AC6CT_Conden22State, this->database->AC6CT_Conden22Fault);

    //vent
    getEquipmentState(ui->label_vent1_1, this->database->AC1CT_Vent11State, this->database->AC1CT_Vent11Fault);
    getEquipmentState(ui->label_vent1_2, this->database->AC1CT_Vent12State, this->database->AC1CT_Vent12Fault);
    getEquipmentState(ui->label_vent1_3, this->database->AC1CT_Vent21State, this->database->AC1CT_Vent21Fault);
    getEquipmentState(ui->label_vent1_4, this->database->AC1CT_Vent22State, this->database->AC1CT_Vent22Fault);

    getEquipmentState(ui->label_vent2_1, this->database->AC3CT_Vent11State, this->database->AC3CT_Vent11Fault);
    getEquipmentState(ui->label_vent2_2, this->database->AC3CT_Vent12State, this->database->AC3CT_Vent12Fault);
    getEquipmentState(ui->label_vent2_3, this->database->AC3CT_Vent21State, this->database->AC3CT_Vent21Fault);
    getEquipmentState(ui->label_vent2_4, this->database->AC3CT_Vent22State, this->database->AC3CT_Vent22Fault);

    getEquipmentState(ui->label_vent3_1, this->database->AC4CT_Vent11State, this->database->AC4CT_Vent11Fault);
    getEquipmentState(ui->label_vent3_2, this->database->AC4CT_Vent12State, this->database->AC4CT_Vent12Fault);
    getEquipmentState(ui->label_vent3_3, this->database->AC4CT_Vent21State, this->database->AC4CT_Vent21Fault);
    getEquipmentState(ui->label_vent3_4, this->database->AC4CT_Vent22State, this->database->AC4CT_Vent22Fault);

    getEquipmentState(ui->label_vent4_1, this->database->AC6CT_Vent11State, this->database->AC6CT_Vent11Fault);
    getEquipmentState(ui->label_vent4_2, this->database->AC6CT_Vent12State, this->database->AC6CT_Vent12Fault);
    getEquipmentState(ui->label_vent4_3, this->database->AC6CT_Vent21State, this->database->AC6CT_Vent21Fault);
    getEquipmentState(ui->label_vent4_4, this->database->AC6CT_Vent22State, this->database->AC6CT_Vent22Fault);

    //preHeater
    getEquipmentState(ui->label_preHeater1_1, this->database->AC1CT_PreHeater11State, this->database->AC1CT_PreHeater11Fault);
    getEquipmentState(ui->label_preHeater1_2, this->database->AC1CT_PreHeater12State, this->database->AC1CT_PreHeater12Fault);
    getEquipmentState(ui->label_preHeater1_3, this->database->AC1CT_PreHeater21State, this->database->AC1CT_PreHeater21Fault);
    getEquipmentState(ui->label_preHeater1_4, this->database->AC1CT_PreHeater22State, this->database->AC1CT_PreHeater22Fault);

    getEquipmentState(ui->label_preHeater2_1, this->database->AC3CT_PreHeater11State, this->database->AC3CT_PreHeater11Fault);
    getEquipmentState(ui->label_preHeater2_2, this->database->AC3CT_PreHeater12State, this->database->AC3CT_PreHeater12Fault);
    getEquipmentState(ui->label_preHeater2_3, this->database->AC3CT_PreHeater21State, this->database->AC3CT_PreHeater21Fault);
    getEquipmentState(ui->label_preHeater2_4, this->database->AC3CT_PreHeater22State, this->database->AC3CT_PreHeater22Fault);

    getEquipmentState(ui->label_preHeater3_1, this->database->AC4CT_PreHeater11State, this->database->AC4CT_PreHeater11Fault);
    getEquipmentState(ui->label_preHeater3_2, this->database->AC4CT_PreHeater12State, this->database->AC4CT_PreHeater12Fault);
    getEquipmentState(ui->label_preHeater3_3, this->database->AC4CT_PreHeater21State, this->database->AC4CT_PreHeater21Fault);
    getEquipmentState(ui->label_preHeater3_4, this->database->AC4CT_PreHeater22State, this->database->AC4CT_PreHeater22Fault);

    getEquipmentState(ui->label_preHeater4_1, this->database->AC6CT_PreHeater11State, this->database->AC6CT_PreHeater11Fault);
    getEquipmentState(ui->label_preHeater4_2, this->database->AC6CT_PreHeater12State, this->database->AC6CT_PreHeater12Fault);
    getEquipmentState(ui->label_preHeater4_3, this->database->AC6CT_PreHeater21State, this->database->AC6CT_PreHeater21Fault);
    getEquipmentState(ui->label_preHeater4_4, this->database->AC6CT_PreHeater22State, this->database->AC6CT_PreHeater22Fault);
}

void AirConditionerPage::setLimits()
{
    //judge autowarm mode configurable
    if (database->CTHM_AutoWarmHibt)
    {
        this->modeButtons->button(4)->setEnabled(false);
        ui->label_remindInfo1->setText(QString("禁止自动制暖"));
    }
    else
    {
        this->modeButtons->button(4)->setEnabled(true);
        ui->label_remindInfo1->setText("");
    }

    //judge cold mode configurable
    if (database->CTHM_ColdHibt)
    {
        this->coldForbidden = true;
        ui->label_remindInfo->setText(QString("禁止制冷"));
    }
    else
    {
        switch(this->currentVehicle)
        {
        case uWhole:
            if(this->database->CTHM_Tc1HVACColdHibt || this->database->CTHM_Mp1HVACColdHibt
               || this->database->CTHM_Mp2HVACColdHibt || this->database->CTHM_Tc2HVACColdHibt)
            {
                this->coldForbidden = true;
                ui->label_remindInfo->setText(QString("禁止整车制冷"));
            }
            else
            {
                this->coldForbidden = false;
                ui->label_remindInfo->setText("");
            }
            break;
        case u1:
            if(this->database->CTHM_Tc1HVACColdHibt)
            {
                this->coldForbidden = true;
                ui->label_remindInfo->setText(QString("TC1车禁止制冷"));
            }
            else
            {
                this->coldForbidden = false;
                ui->label_remindInfo->setText("");
            }
            break;

        case u2:
            if(this->database->CTHM_Mp1HVACColdHibt)
            {
                this->coldForbidden = true;
                ui->label_remindInfo->setText(QString("MP1车禁止制冷"));
            }
            else
            {
                this->coldForbidden = false;
                ui->label_remindInfo->setText("");
            }
            break;

        case u3:
            if(this->database->CTHM_Mp2HVACColdHibt)
            {
                this->coldForbidden = true;
                ui->label_remindInfo->setText(QString("MP2车禁止制冷"));
            }
            else
            {
                this->coldForbidden = false;
                ui->label_remindInfo->setText("");
            }
            break;

        case u4:
            if(this->database->CTHM_Tc2HVACColdHibt)
            {
                this->coldForbidden = true;
                ui->label_remindInfo->setText(QString("TC2车禁止制冷"));
            }
            else
            {
                this->coldForbidden = false;
                ui->label_remindInfo->setText("");
            }
            break;
        }
    }

    if(this->coldForbidden)
    {
        this->modeButtons->button(1)->setEnabled(false);
        this->modeButtons->button(2)->setEnabled(false);
        this->modeButtons->button(3)->setEnabled(false);
    }
    else
    {
        this->modeButtons->button(1)->setEnabled(true);
        this->modeButtons->button(2)->setEnabled(true);
        this->modeButtons->button(3)->setEnabled(true);
    }
}
void AirConditionerPage::setControlState(QLabel *label, bool onState, QString controlState)
{
    if(!onState)
    {
        label->setStyleSheet(_OFFLINE);
        label->setText(" ");
        return;
    }

    else
    {
        label->setStyleSheet(_STOP);
        int state = controlState.toInt();
        switch(state)
        {
        case uCease:
            label->setText("停止");
            break;

        case uAutoCold:
            label->setText("自动冷");
            break;

        case uHalfCold:
            label->setText("半冷");
            break;

        case uWholeCold:
            label->setText("全冷");
            break;

        case uAutoHeat:
            label->setText("自动暖");
            break;

        case uHalfHeat:
            label->setText("半暖");
            break;

        case uWholeHeat:
            label->setText("全暖");
            break;

        case uVent:
            label->setText("通风");
            break;

        case uMergencyVent:
            label->setText("紧急通风");
            break;

        default:
            label->setText("无效");
            break;
        }
    }
}

void AirConditionerPage::setControlMode(QLabel *label, bool onState, bool controlState)
{
    if(!onState)
    {
        label->setStyleSheet(_OFFLINE);
        return;
    }

    if(controlState)
    {
        label->setText(QString("网络控制"));
        label->setStyleSheet(_STOP);
        return;
    }
    else
    {
        label->setText(QString("面板控制"));
        label->setStyleSheet(_STOP);
        return;
    }
}

void AirConditionerPage::getTemperature(QLabel *label, QString temperature)
{
    label->setText(temperature);
}

void AirConditionerPage::getEquipmentState(QLabel *label, bool equipState, bool equipFault)
{
    if(equipFault)
    {
        label->setStyleSheet(_FAULT);
        return;
    }
    else if(equipState)
    {
        label->setStyleSheet(_RUN);
        return;
    }
    else
        label->setStyleSheet(_OFF);
}

void AirConditionerPage::selectMode(int modeNo)
{
    if(NULL == this->modeButtons)
    {
        _LOG << "modeButtons is null!";
        return;
    }
    this->modeSet(modeNo);
    switch(modeNo)
    {
    case 0 :
        this->setModeFlag(uCease);
        disableSetTemp(false);
        break;

    case 1:
        this->setModeFlag(uAutoCold);
        this->autoMode = true;
        disableSetTemp(true);
        break;

    case 2:
        this->setModeFlag(uHalfCold);
        disableSetTemp(false);
        break;

    case 3:
        this->setModeFlag(uWholeCold);
        disableSetTemp(false);
        break;

    case 4:
        this->setModeFlag(uAutoHeat);
        this->autoMode = false;
        disableSetTemp(true);
        break;

    case 5:
        this->setModeFlag(uHalfHeat);
        disableSetTemp(false);
        break;

    case 6:
        this->setModeFlag(uWholeHeat);
        disableSetTemp(false);
        break;

    case 7:
        this->setModeFlag(uVent);
        disableSetTemp(false);
        break;

    case 8:
        this->setModeFlag(uMergencyVent);
        disableSetTemp(false);
        break;
    }
}

/*
 name: on_btn_reduse_clicked(); on_btn_add_clicked()
 function:if current mode is "auto" set vehicle temperature;
 autoHeat: 12-20;  autoCold:22-28
 autoMode: 0:autoHeat 1:autoCold
*/
void AirConditionerPage::on_btn_reduse_clicked()
{
    if((this->autoMode && temp > 22) || (!this->autoMode && temp > 12))
    //if(this->temp > 12)
    {
        this->temp--;
    }
    ui->label_inputTemperature->setText(QString::number(this->temp));
}

void AirConditionerPage::on_btn_add_clicked()
{
    if((this->autoMode && temp < 28) || (!this->autoMode && temp < 20))
    //if(this->temp < 28)
    {
        this->temp++;
    }
    ui->label_inputTemperature->setText(QString::number(this->temp));
}


void AirConditionerPage::modeSet(int modeNo)
{
    for(int i = 0; i < this->modeButtons->buttons().size(); i++)
    {
        this->modeButtons->button(i)->setStyleSheet(BUTTON_UP);
    }
    this->modeButtons->button(modeNo)->setStyleSheet(BUTTON_DOWN);
}


/*
 function:view the selected vehicle's mode that get from MVB
*/
void AirConditionerPage::displayModeState()
{
    switch(this->currentMode)
    {
    case uCease:
        this->modeButtons->button(0)->setStyleSheet(BUTTON_DOWN);
        break;

    case uAutoCold:
        this->modeButtons->button(1)->setStyleSheet(BUTTON_DOWN);
        break;

    case uHalfCold:
        this->modeButtons->button(2)->setStyleSheet(BUTTON_DOWN);
        break;

    case uWholeCold:
        this->modeButtons->button(3)->setStyleSheet(BUTTON_DOWN);
        break;

    case uAutoHeat:
        this->modeButtons->button(4)->setStyleSheet(BUTTON_DOWN);
        break;

    case uHalfHeat:
        this->modeButtons->button(5)->setStyleSheet(BUTTON_DOWN);
        break;

    case uWholeHeat:
        this->modeButtons->button(6)->setStyleSheet(BUTTON_DOWN);
        break;

    case uVent:
        this->modeButtons->button(7)->setStyleSheet(BUTTON_DOWN);
        break;

    case uMergencyVent:
        this->modeButtons->button(8)->setStyleSheet(BUTTON_DOWN);
        break;
    }
}


void AirConditionerPage::displayNewWindState()
{
    switch(this->currentWind)
    {
    case autoControl:
        this->newWindButtons->button(autoControl)->setStyleSheet(BUTTON_DOWN);
        break;

    case allClose:
        this->newWindButtons->button(allClose)->setStyleSheet(BUTTON_DOWN);
        break;

    case set13Wind:
        this->newWindButtons->button(set13Wind)->setStyleSheet(BUTTON_DOWN);
        break;

    case set23Wind:
        this->newWindButtons->button(set23Wind)->setStyleSheet(BUTTON_DOWN);
        break;

    case allOpen:
        this->newWindButtons->button(allOpen)->setStyleSheet(BUTTON_DOWN);
        break;
    }
}

/*
set the temperature and autoMode state
*/
void AirConditionerPage::on_btn_confirm_clicked()
{
    int currentAutoMode;
    if(this->autoMode)
    {
        currentAutoMode = 1;
    }
    else
    {
        currentAutoMode = 5;
    }

    if(uWhole == this->currentVehicle)
    {
        this->database->hmiTc1Temperature = this->temp;
        this->database->hmiMp1Temperature = this->temp;
        this->database->hmiMp2Temperature = this->temp;
        this->database->hmiTc2Temperature = this->temp;

        this->database->hmiAirconditionerModeTc1 = currentAutoMode;
        this->database->hmiAirconditionerModeMp1 = currentAutoMode;
        this->database->hmiAirconditionerModeMp2 = currentAutoMode;
        this->database->hmiAirconditionerModeTc2 = currentAutoMode;

        this->database->hmiSaveAirConditionerTc1 = true;
        this->database->hmiSaveAirConditionerMp1 = true;
        this->database->hmiSaveAirConditionerMp2 = true;
        this->database->hmiSaveAirConditionerTc2 = true;
        this->setFlag(uWhole);
    }
    else  if(u1 == this->currentVehicle)
    {
        this->database->hmiTc1Temperature = this->temp;
        this->database->hmiAirconditionerModeTc1 = currentAutoMode;
        this->database->hmiSaveAirConditionerTc1 = true;
        this->setFlag(u1);
    }
    else if(u2 == this->currentVehicle)
    {
        this->database->hmiMp1Temperature = this->temp;
        this->database->hmiAirconditionerModeMp1 = currentAutoMode;
        this->database->hmiSaveAirConditionerMp1 = true;
        this->setFlag(u2);
    }
    else if(u3 == this->currentVehicle)
    {       
        this->database->hmiMp2Temperature = this->temp;
        this->database->hmiAirconditionerModeMp2 = currentAutoMode;
        this->database->hmiSaveAirConditionerMp2 = true;
        this->setFlag(u3);
    }
    else if(u4 == this->currentVehicle)
    {
        this->database->hmiTc2Temperature = this->temp;
        this->database->hmiAirconditionerModeTc2 = currentAutoMode;
        this->database->hmiSaveAirConditionerTc2 = true;
        this->setFlag(u4);
    }
}

/*
name:disableSetTemp
function:make temperature configurable or not
parameter:ifAutoMode
*/
void AirConditionerPage::disableSetTemp(bool ifAutoMode)
{
    if(ifAutoMode)
    {
        ui->btn_add->setEnabled(true);
        ui->btn_reduse->setEnabled(true);
        ui->btn_confirm->setEnabled(true);
        if (this->autoMode && this->temp < 22)
        {
            this->temp = 22;
            ui->label_inputTemperature->setText(QString::number(this->temp));
        }
        else if (!this->autoMode && this->temp > 20)
        {
            this->temp = 20;
            ui->label_inputTemperature->setText(QString::number(this->temp));
        }
    }
    else
    {
        ui->btn_add->setEnabled(false);
        ui->btn_reduse->setEnabled(false);
        ui->btn_confirm->setEnabled(false);
    }
}


void AirConditionerPage::setFlag(int vehicleNo)
{

    if (this->timerTemp->isActive())
    {
        _LOG << "fail to set the air-conditioner temperature, please check it";
        return;
    }

    switch (vehicleNo)
    {
    case uWhole:
        this->database->hmiSaveAirConditionerTempTc1 = true;
        this->database->hmiSaveAirConditionerTempMp1 = true;
        this->database->hmiSaveAirConditionerTempMp2 = true;
        this->database->hmiSaveAirConditionerTempTc2 = true;

        this->currentVehicle = uWhole;
        break;
    case u1:
        this->database->hmiSaveAirConditionerTempTc1 = true;
        this->currentVehicle = u1;
        break;
    case u2:
        this->database->hmiSaveAirConditionerTempMp1 = true;
        this->currentVehicle = u2;
        break;
    case u3:
        this->database->hmiSaveAirConditionerTempMp2 = true;
        this->currentVehicle = u3;
        break;
    case u4:
        this->database->hmiSaveAirConditionerTempTc2 = true;
        this->currentVehicle = u4;
        break;
    }
    this->database->flagChecker = 0xAA;
    ui->btn_confirm->setEnabled(false);
    this->timerTemp->start(5000);
}

void AirConditionerPage::setModeFlag(int mode)
{

    if (this->timerMode->isActive())
    {
        _LOG << "fail to set the air-conditioner temperature, please check it";
        return;
    }
    switch (this->currentVehicle)
    {
    case uWhole:
        this->database->hmiAirconditionerModeTc1 = mode;
        this->database->hmiAirconditionerModeMp1 = mode;
        this->database->hmiAirconditionerModeMp2 = mode;
        this->database->hmiAirconditionerModeTc2 = mode;
        this->database->hmiSaveAirConditionerTc1 = true;
        this->database->hmiSaveAirConditionerMp1 = true;
        this->database->hmiSaveAirConditionerMp2 = true;
        this->database->hmiSaveAirConditionerTc2 = true;

        this->database->flagChecker = 0xAA;
        break;

    case u1:
        this->database->hmiAirconditionerModeTc1 = mode;
        this->database->hmiSaveAirConditionerTc1 = true;
        this->database->flagChecker = 0xAA;
        break;

    case u2:
        this->database->hmiAirconditionerModeMp1 = mode;
        this->database->hmiSaveAirConditionerMp1 = true;
        this->database->flagChecker = 0xAA;
        break;

    case u3:
        this->database->hmiAirconditionerModeMp2 = mode;
        this->database->hmiSaveAirConditionerMp2 = true;
        this->database->flagChecker = 0xAA;
        break;

    case u4:
        this->database->hmiAirconditionerModeTc2 = mode;
        this->database->hmiSaveAirConditionerTc2 = true;
        this->database->flagChecker = 0xAA;
        break;
    }
    this->timerMode->start(5000);
}

/*
function: if timer goes off restore the flags
*/
void AirConditionerPage::resetFlag()
{
    this->database->hmiSaveAirConditionerTc1 = false;
    this->database->hmiSaveAirConditionerMp1 = false;
    this->database->hmiSaveAirConditionerMp2 = false;
    this->database->hmiSaveAirConditionerTc2 = false;
    this->database->flagChecker = 0x55;
    this->timerMode->stop();
}

void AirConditionerPage::resetTempFlag()
{

    this->database->hmiSaveAirConditionerTempTc1 = false;
    this->database->hmiSaveAirConditionerTempMp1 = false;
    this->database->hmiSaveAirConditionerTempMp2 = false;
    this->database->hmiSaveAirConditionerTempTc2 = false;
    this->database->flagChecker = 0x55;
    ui->btn_confirm->setEnabled(true);
    _LOG << "set temperature flag false";
    this->timerTemp->stop();
}

void AirConditionerPage::selectVehicle(int vehicleNo)
{
    if(NULL == this->vehicleButtons)
    {
        _LOG << "vehicleButtons is null!";
        return;
    }

    for(int i = 0; i < this->vehicleButtons->buttons().size(); i++)
    {
        this->vehicleButtons->button(i)->setStyleSheet(BUTTON_UP);
    }

    this->vehicleButtons->button(vehicleNo)->setStyleSheet(BUTTON_DOWN);

    for(int j = 0; j < this->modeButtons->buttons().size(); j++)
    {
        this->modeButtons->button(j)->setStyleSheet(BUTTON_UP);
    }

    for(int windMode = 0; windMode < this->newWindButtons->buttons().size(); windMode++)
    {
        this->newWindButtons->button(windMode)->setStyleSheet(BUTTON_UP);
    }

    switch (vehicleNo)
    {
    case uWhole:
        this->vehicleButtons->button(uWhole)->text() = "";
        this->currentVehicle = uWhole;
        break;

    case u1:
        this->vehicleButtons->button(u1)->text() = this->database->AC1CT_TargetTemp;
        this->currentMode = this->database->AC1CT_Mode;
        this->currentWind = this->database->hmiTc1WindMode;
        this->currentWindSpd = this->database->hmiTc1WindSpd;
        this->currentVehicle = u1;
        break;

    case u2:
        this->vehicleButtons->button(u2)->text() = this->database->AC3CT_TargetTemp;
        this->currentMode = this->database->AC3CT_Mode;
        this->currentWind = this->database->hmiMp1WindMode;
        this->currentWindSpd = this->database->hmiMp1WindSpd;
        this->currentVehicle = u2;
        break;

    case u3:
        this->vehicleButtons->button(u3)->text() = this->database->AC4CT_TargetTemp;
        this->currentMode = this->database->AC4CT_Mode;
        this->currentWind = this->database->hmiMp2WindMode;
        this->currentWindSpd = this->database->hmiMp2WindSpd;
        this->currentVehicle = u3;
        break;

    case u4:
        this->vehicleButtons->button(u4)->text() = this->database->AC6CT_TargetTemp;
        this->currentMode = this->database->AC6CT_Mode;
        this->currentWind = this->database->hmiTc2WindMode;
        this->currentWindSpd = this->database->hmiTc2WindSpd;
        this->currentVehicle = u4;
        break;
    }
    if (this->currentWindSpd)
    {
        ui->btn_Speed_high->setStyleSheet(BUTTON_DOWN);
        ui->btn_Speed_low->setStyleSheet(BUTTON_UP);
    }
    else
    {
        ui->btn_Speed_high->setStyleSheet(BUTTON_UP);
        ui->btn_Speed_low->setStyleSheet(BUTTON_DOWN);
    }

    if((this->currentMode != uAutoCold) || (this->currentMode != uAutoCold))
        this->disableSetTemp(false);

    this->displayModeState();
    this->displayNewWindState();
}

void AirConditionerPage::on_btn_EmergencyBroadcast_clicked()
{
    emit this->changePage(uEmergencyBroadcast);
}

void AirConditionerPage::selectWind(int windMode)
{
    this->newWindSet(windMode);
    switch(this->currentVehicle)
    {
    case uWhole:
        this->database->hmiTc1WindMode = windMode;
        this->database->hmiTc2WindMode = windMode;
        this->database->hmiMp1WindMode = windMode;
        this->database->hmiMp2WindMode = windMode;
        this->database->hmiNewWindSave = true;
        this->database->flagChecker = 0xAA;
        break;

    case u1:
        this->database->hmiTc1WindMode  = windMode;
        this->database->hmiNewWindSave = true;
        this->database->flagChecker = 0xAA;
        break;

    case u2:
        this->database->hmiMp1WindMode = windMode;
        this->database->hmiNewWindSave = true;
        this->database->flagChecker = 0xAA;
        break;

    case u3:
        this->database->hmiMp2WindMode = windMode;
        this->database->hmiNewWindSave = true;
        this->database->flagChecker = 0xAA;
        break;

    case u4:
        this->database->hmiTc2WindMode = windMode;
        this->database->hmiNewWindSave = true;
        this->database->flagChecker = 0xAA;
        break;
    }

    this->timerWind->start(5000);
    for (int buttonId = 0; buttonId < this->newWindButtons->buttons().size(); buttonId ++)
    {
        this->newWindButtons->button(buttonId)->setEnabled(false);
    }
}

void AirConditionerPage::newWindSet(int id)
{
    for (int selectWindId = 0; selectWindId < this->newWindButtons->buttons().size(); selectWindId ++)
    {
        this->newWindButtons->button(selectWindId)->setStyleSheet(BUTTON_UP);
    }
    this->newWindButtons->button(id)->setStyleSheet(BUTTON_DOWN);
}

void AirConditionerPage::resetWindFlag()
{
    this->database->hmiNewWindSave = false;
    this->database->flagChecker = 0x55;
    for (int buttonId = 0; buttonId < this->newWindButtons->buttons().size(); buttonId ++)
    {
        this->newWindButtons->button(buttonId)->setEnabled(true);
    }
     _LOG << "set newWind timer stop";
    this->timerWind->stop();
}

void AirConditionerPage::setSpeedState(int state)
{
        if (1 == state)
        {
            ui->btn_Speed_high->setStyleSheet(BUTTON_DOWN);
            ui->btn_Speed_low->setStyleSheet(BUTTON_UP);
        }

        else
        {
            ui->btn_Speed_high->setStyleSheet(BUTTON_UP);
            ui->btn_Speed_low->setStyleSheet(BUTTON_DOWN);
        }


    this->saveSpeedState(state);
}

void AirConditionerPage::saveSpeedState(bool state)
{
    switch (this->currentVehicle)
    {
    case uWhole:
        this->database->hmiTc1WindSpd = state;
        this->database->hmiMp1WindSpd = state;
        this->database->hmiMp2WindSpd = state;
        this->database->hmiTc2WindSpd = state;
        this->database->hmiNewWindSave = true;
        break;

    case u1:
        this->database->hmiTc1WindSpd = state;
        this->database->hmiNewWindSave = true;
        break;

    case u2:
        this->database->hmiMp1WindSpd = state;
        this->database->hmiNewWindSave = true;
        break;

    case u3:
        this->database->hmiMp2WindSpd = state;
        this->database->hmiNewWindSave = true;
        break;

    case u4:
        this->database->hmiTc2WindSpd = state;
        this->database->hmiNewWindSave = true;
        break;
    }
}
