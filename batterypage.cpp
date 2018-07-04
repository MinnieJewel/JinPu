#include "batterypage.h"
#include "ui_batterypage.h"
#include "vehiclelogo.h"
#include <QDebug>
#include "global.h"

#define _GREEN ("background-color: rgb(0,255,0);border: 2px groove, gray; border-color: gray;")
#define _BLUE ("background-color: rgb(0,0,255);border: 2px groove, gray; border-color: gray;")
#define _YELLOW ("background-color: yellow;border: 2px groove, gray; border-color: gray;")
#define _STOP ("background-color: black;border: 2px groove, gray; border-color: gray;")

BatteryPage::BatteryPage(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::BatteryPage)
{
    ui->setupUi(this);
     _LOG << "BatteryPage constructor";
    this->vehicleLogo = new VehicleLogo(this);
    this->vehicleLogo->setGeometry(0, 10, this->vehicleLogo->width(), this->vehicleLogo->height());
}

BatteryPage::~BatteryPage()
{
    delete ui;
}

void BatteryPage::updatePage()
{

    this->chargeVoltage(ui->label_chargeVoltage1, this->database->BM1CT_ChargeVolVal);
    this->vehicleLogo->updateVehicleState(this->database->CTHM_TC1Active, this->database->CTHM_TC2Active, this->database->CTHM_Forward, this->database->CTHM_Backward,
    this->database->CTHM_Mp1RIOMGWOn, this->database->CTHM_Mp2RIOMGWOn, this->database->RIOM3_DIM1Ch18, this->database->RIOM3_DIM1Ch19, this->database->RIOM4_DIM1Ch18,
    this->database->RIOM4_DIM1Ch19, this->database->DICT_Tc1DI1I15AllDoorClosed_A1 | this->database->DICT_Tc2DI1I15AllDoorClosed_A2);
    this->vehicleLogo->updateVehicleNo(this->database->lineNo, this->database->vehicleNo);
    this->vehicleLogo->updateHSCB(this->database->TR3CT_HSCBState, this->database->TR4CT_HSCBState);
    this->chargeVoltage(ui->label_chargeVoltage4, this->database->BM2CT_ChargeVolVal);
    this->dischargeVoltage(ui->label_dischargeVoltage1, this->database->BM1CT_DischargeVolVal);
    this->dischargeVoltage(ui->label_dischargeVoltage4, this->database->BM2CT_DischargeVolVal);
    this->boxTemperature(ui->label_temperature1, this->database->BM1CT_InsetTempVal);
    this->boxTemperature(ui->label_temperature4, this->database->BM2CT_InsetTempVal);
    this->chargeCurrent(ui->label_chargeCurrent1, this->database->BM1CT_ChargeCurVal);
    this->chargeCurrent(ui->label_chargeCurrent4, this->database->BM2CT_ChargeCurVal);
    this->dischargeCurrent(ui->label_dischargeCurrent1, this->database->BM1CT_DischargeCurVal);
    this->dischargeCurrent(ui->label_dischargeCurrent4, this->database->BM2CT_DischargeCurVal);
    this->overVolBattery(ui->label_overVoltage1, this->database->BM1CT_OverVolBattNum);
    this->overVolBattery(ui->label_overVoltage4, this->database->BM2CT_OverVolBattNum);
    this->lowVolBattery(ui->label_lowerVoltage1, this->database->BM1CT_LowVolBattNum);
    this->lowVolBattery(ui->label_lowerVoltage4, this->database->BM2CT_LowVolBattNum);
    this->overTempBattery(ui->label_overTemperature1, this->database->BM1CT_OverTempBattNum);
    this->overTempBattery(ui->label_overTemperature4, this->database->BM2CT_OverTempBattNum);
    this->overResBattery(ui->label_overResistance1, this->database->BM1CT_OverResBattNum);
    this->overResBattery(ui->label_overResistance4, this->database->BM2CT_OverResBattNum);
    this->alertState(ui->label_lightState1, this->database->BM1CT_AlarmLampSta);
    this->alertState(ui->label_lightState4, this->database->BM2CT_AlarmLampSta);
    this->alertValue(ui->label_overAlarmVol1_1, this->database->BM1CT_OverVolAlarmBatt1Val);
    this->alertValue(ui->label_overAlarmVol1_2, this->database->BM1CT_OverVolAlarmBatt2Val);
    this->alertValue(ui->label_overAlarmVol4_1, this->database->BM2CT_OverVolAlarmBatt1Val);
    this->alertValue(ui->label_overAlarmVol4_2, this->database->BM2CT_OverVolAlarmBatt2Val);
    this->alertValue(ui->label_lowerAlarmVol1_1, this->database->BM1CT_LowVolAlarmBatt1Val);
    this->alertValue(ui->label_lowerAlarmVol1_2, this->database->BM1CT_LowVolAlarmBatt2Val);
    this->alertValue(ui->label_lowerAlarmVol4_1, this->database->BM2CT_LowVolAlarmBatt1Val);
    this->alertValue(ui->label_lowerAlarmVol4_2, this->database->BM2CT_LowVolAlarmBatt2Val);
    this->alertValue(ui->label_overAlarmTemp1_1, this->database->BM1CT_OverTempAlarmBatt1Val);
    this->alertValue(ui->label_overAlarmTemp1_2, this->database->BM1CT_OverTempAlarmBatt2Val);
    this->alertValue(ui->label_overAlarmTemp4_1, this->database->BM2CT_OverTempAlarmBatt1Val);
    this->alertValue(ui->label_overAlarmTemp4_2, this->database->BM2CT_OverTempAlarmBatt2Val);
    this->alertValue(ui->label_overAlarmRes1_1, this->database->BM1CT_OverResAlarmBatt1Val);
    this->alertValue(ui->label_overAlarmRes1_2, this->database->BM1CT_OverResAlarmBatt2Val);
    this->alertValue(ui->label_overAlarmRes4_1, this->database->BM2CT_OverResAlarmBatt1Val);
    this->alertValue(ui->label_overAlarmRes4_2, this->database->BM2CT_OverResAlarmBatt2Val);
}


void BatteryPage::chargeVoltage(QLabel *label, unsigned short chargeVoltage)
{
    label->setText(QString::number(chargeVoltage));
}

void BatteryPage::dischargeVoltage(QLabel *label, unsigned short dischargeVoltage)
{
    label->setText(QString::number(dischargeVoltage));
}

void BatteryPage::boxTemperature(QLabel *label, unsigned short temperature)
{
    label->setText(QString::number(temperature));
}

void BatteryPage::chargeCurrent(QLabel *label, unsigned short chargeCurrent)
{
    label->setText(QString::number(chargeCurrent));
}

void BatteryPage::dischargeCurrent(QLabel *label, unsigned short dischargeCurrent)
{
    label->setText(QString::number(dischargeCurrent));
}

void BatteryPage::overVolBattery(QLabel *label, unsigned char overVolBatteryNum)
{
    label->setText(QString::number(overVolBatteryNum));
}

void BatteryPage::lowVolBattery(QLabel *label, unsigned char lowVolBatteryNum)
{
    label->setText(QString::number(lowVolBatteryNum));
}

void BatteryPage::overTempBattery(QLabel *label, unsigned char overBatteryNum)
{
    label->setText(QString::number(overBatteryNum));
}

void BatteryPage::overResBattery(QLabel *label, unsigned char overResBatteryNum)
{
    label->setText(QString::number(overResBatteryNum));
}

void BatteryPage::alertState(QLabel *label, unsigned char state)
{
    if(1 == state)
    {
        label->setStyleSheet(_GREEN);
        return;
    }else if(2 == state)
    {
        label->setStyleSheet(_BLUE);
        return;
    }else if(3 == state)
    {
        label->setStyleSheet(_YELLOW);
        return;
    }
    else
        label->setStyleSheet(_STOP);
}

void BatteryPage::alertValue(QLabel *label, unsigned short value)
{
    label->setText(QString::number(value));
}



void BatteryPage::on_btn_EmergencyBroadcast_clicked()
{
    emit this->changePage(uEmergencyBroadcast);
}
