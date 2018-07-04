#include "chargerpage.h"
#include "ui_chargerpage.h"
#include "vehiclelogo.h"
#include <QDebug>
#include "global.h"
#include <QTimer>

#define _OFFLINE ("font: 15px; color: rgb(0,0,0); background-color: white; border: 2px groove, gray; border-color: gray;")
#define _CUT ("font: 15px; color: rgb(0,0,0); background-image: url(:/image/cut.png); border: 2px groove, gray; border-color: gray;")
#define _FAULT ("font: 15px; color: rgb(0,0,0); background-color: red; border: 2px groove, gray; border-color: gray;")
#define _RUN ("font: 15px; color: rgb(0,0,0); background-color: rgb(0, 255, 0); border: 2px groove, gray; border-color: gray;")
#define _STOP ("font: 20px, SimHei;color: red; background-color: black; border: 2px groove, gray; border-color: gray;")
#define BTN_UNSELECTED ("font: 20px, SimHei; color: black; background-color: rgb(250, 250, 250); border-radius: 5px;")
#define BTN_SELECTED ("font: 20px, SimHei; color: white; background-color: rgb(0, 0, 250); border-radius: 5px;")

ChargerPage::ChargerPage(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::ChargerPage)
{
    ui->setupUi(this);
    _LOG << "ChargerPage constructor";
    this->vehicleLogo = new VehicleLogo(this);
    this->vehicleLogo->setGeometry(0, 10, this->vehicleLogo->width(), this->vehicleLogo->height());

    this->timer = new QTimer();
    this->timer->stop();
    connect(this->timer, SIGNAL(timeout()), this, SLOT(resetFlag()));

    ui->btn_cut1->setCheckable(true);
    ui->btn_cut2->setCheckable(true);
    connect(ui->btn_cut1, SIGNAL(toggled(bool)), this, SLOT(setToggleButton1(bool)));
    connect(ui->btn_cut2, SIGNAL(toggled(bool)), this, SLOT(setToggleButton2(bool)));
}

ChargerPage::~ChargerPage()
{
    delete ui;
}

void ChargerPage::updatePage()
{
    this->vehicleLogo->updateVehicleState(this->database->CTHM_TC1Active, this->database->CTHM_TC2Active, this->database->CTHM_Forward, this->database->CTHM_Backward,
    this->database->CTHM_Mp1RIOMGWOn, this->database->CTHM_Mp2RIOMGWOn, this->database->RIOM3_DIM1Ch18, this->database->RIOM3_DIM1Ch19, this->database->RIOM4_DIM1Ch18,
    this->database->RIOM4_DIM1Ch19, this->database->DICT_Tc1DI1I15AllDoorClosed_A1 | this->database->DICT_Tc2DI1I15AllDoorClosed_A2);
    this->vehicleLogo->updateVehicleNo(this->database->lineNo, this->database->vehicleNo);
    this->vehicleLogo->updateHSCB(this->database->TR3CT_HSCBState, this->database->TR4CT_HSCBState);
    bool bcg1Fault = this->database->BC1CT_BatteryTempFlt || this->database->BC1CT_DC24VOutputFlt
                     || this->database->BC1CT_DC110VOutputOverFlt || this->database->BC1CT_DC110VOutputShortFlt
                     || this->database->BC1CT_RecOverLoadFlt || this->database->BC1CT_InputOverCurFlt
                     || this->database->BC1CT_InputOverVolFlt || this->database->BC1CT_InputLowVolFlt
                     || this->database->BC1CT_RadOverTempFlt || this->database->BC1CT_DC24VInputFuseFlt
                     || this->database->BC1CT_DC24VModuleFlt
                     || this->database->BC1CT_DC110VOutputFuseFlt || this->database->BC1CT_WholeInputFuseFlt;

    bool bcg2Fault = this->database->BC2CT_BatteryTempFlt || this->database->BC2CT_DC24VOutputFlt
                     || this->database->BC2CT_DC110VOutputOverFlt || this->database->BC2CT_DC110VOutputShortFlt
                     || this->database->BC2CT_RecOverLoadFlt || this->database->BC2CT_InputOverCurFlt
                     || this->database->BC2CT_InputOverVolFlt || this->database->BC2CT_InputLowVolFlt
                     || this->database->BC2CT_RadOverTempFlt || this->database->BC2CT_DC24VInputFuseFlt
                     || this->database->BC2CT_DC24VModuleFlt
                     || this->database->BC2CT_DC110VOutputFuseFlt || this->database->BC2CT_WholeInputFuseFlt;

    this->chargeState(ui->label_batteryState1, this->database->CTHM_BCG1On, bcg1Fault);
    this->chargeState(ui->label_batteryState4, this->database->CTHM_BCG2On, bcg2Fault);
    this->chargeTemperature(ui->label_batteryTemp1, this->database->BC1CT_BatteryTemp);
    this->chargeTemperature(ui->label_batteryTemp4, this->database->BC2CT_BatteryTemp);
    this->chargeVoltage(ui->label_batteryVoltage1, this->database->BC1CT_BatteryVoltage);
    this->chargeVoltage(ui->label_batteryVoltage4, this->database->BC2CT_BatteryVoltage);
    this->chargeCurrent(ui->label_batteryCurrent1, this->database->BC1CT_BatteryCurrent);
    this->chargeCurrent(ui->label_batteryCurrent4, this->database->BC2CT_BatteryCurrent);
    this->netVoltage(ui->label_netVoltage1, this->database->BC1CT_NetVoltage);
    this->netVoltage(ui->label_netVoltage4, this->database->BC2CT_NetVoltage);
    this->supportVoltage(ui->label_supportVoltage1, this->database->BC1CT_CapacityVoltage);
    this->supportVoltage(ui->label_supportVoltage4, this->database->BC2CT_CapacityVoltage);
    this->netCurrent(ui->label_netCurrent1, this->database->BC1CT_NetCurrent);
    this->netCurrent(ui->label_netCurrent4, this->database->BC2CT_NetCurrent);
}

void ChargerPage::chargeState(QLabel *label, bool onLine, bool fault)
{
    if(!onLine)
    {
        label->setStyleSheet(_OFFLINE);
        return;
    }
    else if(fault)
    {
        label->setStyleSheet(_FAULT);
        return;
    }
    else
        label->setStyleSheet(_RUN);
}

void ChargerPage::chargeTemperature(QLabel *label, unsigned short int temperature)
{
    label->setText(QString::number(temperature - 100));
}

void ChargerPage::chargeVoltage(QLabel *label, unsigned short int voltage)
{
    label->setText(QString::number(voltage));
}

void ChargerPage::chargeCurrent(QLabel *label, unsigned short int current)
{
    label->setText(QString::number(current));
}

void ChargerPage::supportVoltage(QLabel *label, unsigned short int supportVoltage)
{
    label->setText(QString::number(supportVoltage));
}

void ChargerPage::netVoltage(QLabel *label, unsigned short int netVoltage)
{
    label->setText(QString::number(netVoltage));
}

void ChargerPage::netCurrent(QLabel *label, unsigned short int netCurrent)
{
    label->setText(QString::number(netCurrent));
}

void ChargerPage::resetFlag()
{
    this->database->flagChecker = 0x55;
    this->database->hmiResetBCG1 = false;
    this->database->hmiResetBCG2 = false;
    ui->btn_reset1->setEnabled(true);
    ui->btn_reset2->setEnabled(true);
    this->timer->stop();
}

void ChargerPage::on_btn_reset1_clicked()
{
    this->timer->stop();
    this->database->hmiResetBCG1 = true;
    this->database->flagChecker = 0xAA;
    this->timer->start(5000);
    ui->btn_reset1->setEnabled(false);
}

void ChargerPage::on_btn_reset2_clicked()
{
    this->timer->stop();
    this->database->hmiResetBCG2 = true;
    this->database->flagChecker = 0xAA;
    this->timer->start(5000);
    ui->btn_reset2->setEnabled(false);
}

void ChargerPage::setToggleButton1(bool checked)
{
    if(checked)
    {
        ui->btn_cut1->setStyleSheet(BTN_SELECTED);
        this->database->hmiCutBCG1 = true;
    }
    else
    {
        ui->btn_cut1->setStyleSheet(BTN_UNSELECTED);
        this->database->hmiCutBCG1 = false;
    }
}

void ChargerPage::setToggleButton2(bool checked)
{
    if(checked)
    {
        ui->btn_cut2->setStyleSheet(BTN_SELECTED);
        this->database->hmiCutBCG2 = true;
    }
    else
    {
        ui->btn_cut2->setStyleSheet(BTN_UNSELECTED);
        this->database->hmiCutBCG2 = false;
    }
}

void ChargerPage::on_btn_EmergencyBroadcast_clicked()
{
    emit this->changePage(uEmergencyBroadcast);
}
