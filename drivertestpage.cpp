#include "drivertestpage.h"
#include "ui_drivertestpage.h"
#include "global.h"
#include <QDebug>
#include "vehiclelogo.h"

#define _VALID ("background-color: green;")
#define _INVALID ("background-color: white;")

DriverTestPage::DriverTestPage(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::DriverTestPage)
{
    ui->setupUi(this);
    _LOG << "DriverTestPage constructor";
    this->vehicleLogo = new VehicleLogo(this);
    this->vehicleLogo->setGeometry(0, 10, this->vehicleLogo->width(), this->vehicleLogo->height());
    this->perBrFrc = "";
}

DriverTestPage::~DriverTestPage()
{
    delete ui;
}

void DriverTestPage::updatePage()
{
    this->vehicleLogo->updateVehicleState(this->database->CTHM_TC1Active, this->database->CTHM_TC2Active, this->database->CTHM_Forward, this->database->CTHM_Backward,
    this->database->CTHM_Mp1RIOMGWOn, this->database->CTHM_Mp2RIOMGWOn, this->database->RIOM3_DIM1Ch18, this->database->RIOM3_DIM1Ch19, this->database->RIOM4_DIM1Ch18,
    this->database->RIOM4_DIM1Ch19, this->database->DICT_Tc1DI1I15AllDoorClosed_A1 | this->database->DICT_Tc2DI1I15AllDoorClosed_A2);
    this->vehicleLogo->updateVehicleNo(this->database->lineNo, this->database->vehicleNo);
    this->vehicleLogo->updateHSCB(this->database->TR3CT_HSCBState, this->database->TR4CT_HSCBState);
    //this->setState(ui->label_brakeCut1, this->database->CTBR_CutHoldBrk);
    this->setState(ui->label_brake1, this->database->CTBR_Braking);
    this->setState(ui->label_traction1, this->database->CTBR_Driving);

    this->perBrFrc.sprintf("%2d.%-2d", this->database->CTBR_PerBrFrc / 100, this->database->CTBR_PerBrFrc % 100);
    ui->label_brakePercent1->setText(this->perBrFrc + "%");
    ui->label_Level1->setText("级位1：" + QString::number(this->database->AICT_Tc1AI7DriverControllerLevelA_A1)
                              + "\n级位2：" + QString::number(this->database->AICT_Tc1AI8DriverControllerLevelB_A1));

    ui->label_Level2->setText("级位1：" + QString::number(this->database->AICT_Tc2AI7DriverControllerLevelA_A2)
                              + "\n级位2：" + QString::number(this->database->AICT_Tc2AI8DriverControllerLevelB_A2));
}

void DriverTestPage::setState(QLabel *label, bool state)
{
    if(state)
        label->setStyleSheet(_VALID);
    else
        label->setStyleSheet(_INVALID);
}

void DriverTestPage::on_btn_back_clicked()
{
    emit this->changePage(uTestPage);
}
