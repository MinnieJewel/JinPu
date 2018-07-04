#include "assistantpage.h"
#include "ui_assistantpage.h"
#include <QDebug>
#include "vehiclelogo.h"
#include "global.h"
#include <QTimer>

#define _OFFLINE ("background-color: white; border: 2px groove, gray; border-color: gray;")
#define _CUT ("background-image: url(:/image/cut.png); 2px groove, gray; border-color: gray;")
#define _STOP ("background-color: black;2px groove, gray; border-color: gray;")
#define _FAULT ("background-color: red; 2px groove, gray; border-color: gray;")
#define _RUN ("background-color: rgb(0, 255, 0); 2px groove, gray; border-color: gray;")
#define BTN_UNSELECTED ("font: 20px, SimHei; color: black; background-color: rgb(250, 250, 250); border-radius: 5px;")
#define BTN_SELECTED ("font: 20px, SimHei; color: white; background-color: rgb(0, 0, 250); border-radius: 5px;")

AssistantPage::AssistantPage(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::AssistantPage)
{
    ui->setupUi(this);
    _LOG << "AssistantPage constructor";
    this->vehicleLogo = new VehicleLogo(this);
    this->vehicleLogo->setGeometry(0, 10, this->vehicleLogo->width(), this->vehicleLogo->height());
    this->timer = new QTimer;
    this->timer->stop();
    connect(this->timer, SIGNAL(timeout()), this, SLOT(resetFlag()));

    ui->btn_cut1->setCheckable(true);
    ui->btn_cut2->setCheckable(true);
    connect(ui->btn_cut1, SIGNAL(toggled(bool)), this, SLOT(setToggleButton1(bool)));
    connect(ui->btn_cut2, SIGNAL(toggled(bool)), this, SLOT(setToggleButton2(bool)));
}

AssistantPage::~AssistantPage()
{
    delete ui;
}

void AssistantPage::updatePage()
{
    this->vehicleLogo->updateVehicleState(this->database->CTHM_TC1Active, this->database->CTHM_TC2Active, this->database->CTHM_Forward, this->database->CTHM_Backward,
    this->database->CTHM_Mp1RIOMGWOn, this->database->CTHM_Mp2RIOMGWOn, this->database->RIOM3_DIM1Ch18, this->database->RIOM3_DIM1Ch19, this->database->RIOM4_DIM1Ch18,
    this->database->RIOM4_DIM1Ch19, this->database->DICT_Tc1DI1I15AllDoorClosed_A1 | this->database->DICT_Tc2DI1I15AllDoorClosed_A2);
    this->vehicleLogo->updateVehicleNo(this->database->lineNo, this->database->vehicleNo);
    this->vehicleLogo->updateHSCB(this->database->TR3CT_HSCBState, this->database->TR4CT_HSCBState);
    //this->getAssistantState(ui->label_car1AssistantState, this->database->CTHM_SIV1On, this->database->AX1CT_Fault, this->database->AX1CT_Stop, this->database->AX1CT_Running, "TC1");
    //this->getAssistantState(ui->label_car4AssistantState, this->database->CTHM_SIV2On, this->database->AX2CT_Fault, this->database->AX2CT_Stop, this->database->AX2CT_Running, "TC2");
    this->getSIVInputVoltage(ui->label_car1SIVInputVoltage, this->database->CTHM_SIV1On, this->database->AX1CT_InputVoltage);
    this->getSIVInputVoltage(ui->label_car4SIVInputVoltage, this->database->CTHM_SIV2On, this->database->AX2CT_InputVoltage);
    this->getSIVOutputVoltage(ui->label_car1SIVOutputVoltage, this->database->CTHM_SIV1On, this->database->AX1CT_OutputVoltAC);
    this->getSIVOutputVoltage(ui->label_car4SIVOutputVoltage, this->database->CTHM_SIV2On, this->database->AX2CT_OutputVoltAC);
    this->getSIVOutputRate(ui->label_car1SIVOutputRate, this->database->CTHM_SIV1On, this->database->AX1CT_OutputACFrenq);
    this->getSIVOutputRate(ui->label_car4SIVOutputRate, this->database->CTHM_SIV2On, this->database->AX2CT_OutputACFrenq);
    this->getSIVOutputCurrent(ui->label_car1SIVOutputCurrent, this->database->CTHM_SIV1On, this->database->AX1CT_OutputCurAC);
    this->getSIVOutputCurrent(ui->label_car4SIVOutputCurrent, this->database->CTHM_SIV2On, this->database->AX2CT_OutputCurAC);
    this->getExtendEnable(ui->label_extendEnable1, this->database->CTHM_SIV1On, this->database->AX1CT_ExtendEnable);
    this->getExtendEnable(ui->label_extendEnable2, this->database->CTHM_SIV2On, this->database->AX2CT_ExtendEnable);
    //this->getDropPantStop(ui->label_DropPantStop1, this->database->CTHM_SIV1On, this->database->AX1CT_DropPantStop);
    //this->getDropPantStop(ui->label_DropPantStop2, this->database->CTHM_SIV2On, this->database->AX2CT_DropPantStop);
    this->getLineVoltage(ui->label_lineVoltage1, this->database->CTHM_SIV1On, this->database->AX1CT_LineVoltageDC);
    this->getLineVoltage(ui->label_lineVoltage2, this->database->CTHM_SIV2On, this->database->AX2CT_LineVoltageDC);
}

void AssistantPage::getAssistantState(QLabel *label, bool onState, bool fault, bool stop, bool run, QString carNo)
{
    if(!onState)
    {
        label->setText(" ");
        label->setStyleSheet(_OFFLINE);
        return;
    }
    else if(fault)
    {
        label->setText(" ");
        label->setStyleSheet(_FAULT);
        return;
    }
    else if(stop)
    {      
        label->setStyleSheet(_STOP);
        label->setText(QString("停机"));
        return;
    }
    else if(run)
    {
        label->setText(" ");
        label->setStyleSheet(_RUN);
        return;
    }
    else
    {
        label->setText(" ");
        label->setStyleSheet(_STOP);
        _LOG << "SIV State is unknown: " << carNo;
    }
}

void AssistantPage::getSIVInputVoltage(QLabel *label, bool onState, unsigned short voltage)
{
    if(!onState)
    {
        label->setText(" ");
        label->setStyleSheet(_OFFLINE);
        return;
    }
    else
    {
        label->setStyleSheet(_STOP);
        label->setText(QString::number(voltage));
    }
}

void AssistantPage::getSIVOutputVoltage(QLabel *label, bool onState, unsigned short voltage)
{
    if(!onState)
    {
        label->setText(" ");
        label->setStyleSheet(_OFFLINE);
        return;
    }
    else
    {
        label->setStyleSheet(_STOP);
        label->setText(QString::number(voltage));
    }

}

void AssistantPage::getSIVOutputRate(QLabel *label, bool onState, unsigned short rate)
{
    if(!onState)
    {
        label->setText(" ");
        label->setStyleSheet(_OFFLINE);
        return;
    }
    else
    {
        label->setStyleSheet(_STOP);
        label->setText(QString::number(rate * 0.1));
    }

}

void AssistantPage::getSIVOutputCurrent(QLabel *label, bool onState, unsigned short current)
{
    if(!onState)
    {
        label->setText(" ");
        label->setStyleSheet(_OFFLINE);
        return;
    }
    else
    {
        label->setStyleSheet(_STOP);
        label->setText(QString::number(current));
    }

}

void AssistantPage::getExtendEnable(QLabel *label, bool onState, bool enable)
{
    if(!onState)
    {
        label->setStyleSheet(_OFFLINE);
        return;
    }
    else if(enable)
    {
        label->setStyleSheet(_RUN);
        return;
    }
    else
        label->setStyleSheet(_STOP);
}

void AssistantPage::getDropPantStop(QLabel *label, bool onState, bool stop)
{
    if(!onState)
    {
        label->setStyleSheet(_OFFLINE);
        return;
    }
    else if(stop)
    {
        label->setStyleSheet(_FAULT);
        return;
    }
    else
        label->setStyleSheet(_STOP);
}

void AssistantPage::getLineVoltage(QLabel *label, bool onState, unsigned short voltage)
{
    if(!onState)
    {
        label->setText(" ");
        label->setStyleSheet(_OFFLINE);
        return;
    }
    else
    {       
        label->setStyleSheet(_STOP);
        label->setText(QString::number(voltage));
    }
}

void AssistantPage::resetFlag()
{
    this->database->flagChecker = 0x55;
    this->database->hmiResetSIV1= false;
    this->database->hmiResetSIV2 = false;
    ui->btn_reset1->setEnabled(true);
    ui->btn_reset2->setEnabled(true);
    this->timer->stop();
}


void AssistantPage::on_btn_reset1_clicked()
{
    this->timer->stop();
    this->database->hmiResetSIV1 = true;
    this->database->flagChecker = 0xAA;
    this->timer->start(5000);
    ui->btn_reset1->setEnabled(false);
}


void AssistantPage::on_btn_reset2_clicked()
{
    this->timer->stop();
    this->database->hmiResetSIV2 = true;
    this->database->flagChecker = 0xAA;
    this->timer->start(5000);
    ui->btn_reset2->setEnabled(false);
}

void AssistantPage::setToggleButton1(bool checked)
{
    if(checked)
    {
        ui->btn_cut1->setStyleSheet(BTN_SELECTED);
        this->database->hmiCutSIV1 = true;
    }
    else
    {
        ui->btn_cut1->setStyleSheet(BTN_UNSELECTED);
        this->database->hmiCutSIV1 = false;
    }
}

void AssistantPage::setToggleButton2(bool checked)
{
    if(checked)
    {
        ui->btn_cut2->setStyleSheet(BTN_SELECTED);
        this->database->hmiCutSIV2 = true;
    }
    else
    {
        ui->btn_cut2->setStyleSheet(BTN_UNSELECTED);
        this->database->hmiCutSIV2 = false;
    }
}

void AssistantPage::on_pushButton_clicked()
{
    emit this->changePage(uEmergencyBroadcast);
}

void AssistantPage::on_btn_EmergencyBroadcast_clicked()
{
    emit this->changePage(uEmergencyBroadcast);
}
