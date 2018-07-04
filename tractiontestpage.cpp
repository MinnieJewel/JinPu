#include "tractiontestpage.h"
#include "ui_tractiontestpage.h"
#include <QDebug>
#include "global.h"
#include "vehiclelogo.h"

#define _VALID ("background-color: green;")
#define _INVALID ("background-color: white;")

TractionTestPage::TractionTestPage(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::TractionTestPage)
{
    ui->setupUi(this);
    _LOG << "TractionTestPage constructor";    
    this->vehicleLogo = new VehicleLogo(this);
    this->vehicleLogo->setGeometry(0, 10, this->vehicleLogo->width(), this->vehicleLogo->height());
}

void TractionTestPage::updatePage()
{
    this->vehicleLogo->updateVehicleState(this->database->CTHM_TC1Active, this->database->CTHM_TC2Active, this->database->CTHM_Forward, this->database->CTHM_Backward,
    this->database->CTHM_Mp1RIOMGWOn, this->database->CTHM_Mp2RIOMGWOn, this->database->RIOM3_DIM1Ch18, this->database->RIOM3_DIM1Ch19, this->database->RIOM4_DIM1Ch18,
    this->database->RIOM4_DIM1Ch19, this->database->DICT_Tc1DI1I15AllDoorClosed_A1 | this->database->DICT_Tc2DI1I15AllDoorClosed_A2);
    this->vehicleLogo->updateVehicleNo(this->database->lineNo, this->database->vehicleNo);
    this->vehicleLogo->updateHSCB(this->database->TR3CT_HSCBState, this->database->TR4CT_HSCBState);
    this->testState(ui->label_emergencyBrake2, this->database->CTTR3_EmBrake);
    this->testState(ui->label_emergencyBrake3, this->database->CTTR4_EmBrake);
    this->testState(ui->label_brake2, this->database->CTTR3_Brake);
    this->testState(ui->label_brake3, this->database->CTTR4_Brake);
    this->testState(ui->label_traction2, this->database->CTTR3_Traction);
    this->testState(ui->label_traction3, this->database->CTTR4_Traction);
    this->testState(ui->label_backward2, this->database->CTTR3_Backward);
    this->testState(ui->label_backward3, this->database->CTTR4_Backward);
    this->testState(ui->label_forward2, this->database->CTTR3_Forward);
    this->testState(ui->label_forward3, this->database->CTTR4_Forward);
    this->testState(ui->label_ecut2, this->database->CTTR3_EBCutOff);
    this->testState(ui->label_ecut3, this->database->CTTR4_EBCutOff);
    this->testState(ui->label_isolate2_1, this->database->CTTR3_TCU1CutOff);
    this->testState(ui->label_isolate2_2, this->database->CTTR3_TCU2CutOff);
    this->testState(ui->label_isolate2_3, this->database->CTTR3_TCU3CutOff);
    this->testState(ui->label_isolate2_4, this->database->CTTR3_TCU4CutOff);
    this->testState(ui->label_isolate3_1, this->database->CTTR4_TCU1CutOff);
    this->testState(ui->label_isolate3_2, this->database->CTTR4_TCU2CutOff);
    this->testState(ui->label_isolate3_3, this->database->CTTR4_TCU3CutOff);
    this->testState(ui->label_isolate3_4, this->database->CTTR4_TCU4CutOff);
}

TractionTestPage::~TractionTestPage()
{
    delete ui;
}

void TractionTestPage::testState(QLabel *label, bool state)
{
    if(state)
    {
        label->setStyleSheet(_VALID);
    }
    else
    {
        label->setStyleSheet(_INVALID);
    }
}

void TractionTestPage::on_btn_back_clicked()
{
    emit this->changePage(uTestPage);
}
