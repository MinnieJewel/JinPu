#include "mainpage.h"
#include "ui_mainpage.h"
#include "vehiclelogo.h"
#include <QDebug>
#include "global.h"
#include <QPainter>
#include "panel.h"

enum mode
{
    RM = 0,
    ATP,
    ATO,
    ATB,
    IATP,
    ATCCUTOFF,
    WASH,
    OTHER
};

MainPage::MainPage(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::MainPage)
{
    ui->setupUi(this);
    _LOG << "MainPage constructor";
    this->vehicleLogo = new VehicleLogo(this);
    this->vehicleLogo->setGeometry(0, 10, this->vehicleLogo->width(), this->vehicleLogo->height());
    this->speedPanel = new Panel(this);
    this->speedPanel->setGeometry(215, 150, 600, 430);
    this->speedPanel->show();
    ui->label_EmergencyBrake->hide();
    ui->label_idleMp1->hide();
    ui->label_idleMp2->hide();
    ui->label_slideTC1->hide();
    ui->label_slideTC2->hide();
    ui->label_slideMP1->hide();
    ui->label_slideMP2->hide();
    ui->label_washing->hide();
    ui->label_BHBBreak->hide();
}

MainPage::~MainPage()
{
    delete ui;
}

void MainPage::on_btn_EmergencyBroadcast_clicked()
{
    emit this->changePage(uEmergencyBroadcast);
}

void MainPage::updatePage()
{
    //qDebug()<<"step1";
    this->vehicleLogo->updateVehicleState(this->database->CTHM_TC1Active, this->database->CTHM_TC2Active, this->database->CTHM_Forward, this->database->CTHM_Backward,
    this->database->CTHM_Mp1RIOMGWOn, this->database->CTHM_Mp2RIOMGWOn, this->database->RIOM3_DIM1Ch18, this->database->RIOM3_DIM1Ch19, this->database->RIOM4_DIM1Ch18,
    this->database->RIOM4_DIM1Ch19, this->database->DICT_Tc1DI1I15AllDoorClosed_A1 | this->database->DICT_Tc2DI1I15AllDoorClosed_A2);
    this->vehicleLogo->updateVehicleNo(this->database->lineNo, this->database->vehicleNo);
    this->vehicleLogo->updateHSCB(this->database->TR3CT_HSCBState, this->database->TR4CT_HSCBState);
    this->speedPanel->setCurrentSpeed(this->database->CTHM_TrainSpeed / 10.0);
    //qDebug()<<"step2";

    //ui->label_totalHours->hide();
    //ui->label_totalKilometers->hide();
   // ui->label_totalKilometers->setText(QString::number(this->database->ServiceDistance) + " m");
    //ui->label_totalHours->setText(QString::number(this->database->TCMSTotalTime) + " s");
    //ui->label_totalHours->setText(QString::number(this->database->getUnsignedInt32(0x211, 28)));
    //qDebug()<<"step3";

    this->judgeIdle(ui->label_idleMp1, this->database->TR3CT_A1Slide || this->database->TR3CT_A2Slide || this->database->TR3CT_A3Slide || this->database->TR3CT_A4Slide,
                    this->database->TR3CT_A1EBSlide || this->database->TR3CT_A2EBSlide || this->database->TR3CT_A3EBSlide || this->database->TR3CT_A4EBSlide);
    this->judgeIdle(ui->label_idleMp2, this->database->TR4CT_A1Slide || this->database->TR4CT_A2Slide || this->database->TR4CT_A3Slide || this->database->TR4CT_A4Slide,
                    this->database->TR4CT_A1EBSlide || this->database->TR4CT_A2EBSlide || this->database->TR4CT_A3EBSlide || this->database->TR4CT_A4EBSlide);
    this->judgeSlide(ui->label_slideTC1, this->database->getBool(0xF411, 12, 5) || this->database->getBool(0xF411, 29, 5) || this->database->getBool(0xF411, 28, 5) || this->database->getBool(0xF411, 29, 6));
    this->judgeSlide(ui->label_slideTC2, this->database->getBool(0xF441, 12, 5) || this->database->getBool(0xF441, 29, 5) || this->database->getBool(0xF441, 28, 5) || this->database->getBool(0xF441, 29, 6));
    this->judgeSlide(ui->label_slideMP1, this->database->getBool(0xF412, 12, 5) || this->database->getBool(0xF412, 29, 5) || this->database->getBool(0xF412, 28, 5) || this->database->getBool(0xF412, 29, 6));
    this->judgeSlide(ui->label_slideMP2, this->database->getBool(0xF442, 12, 5) || this->database->getBool(0xF442, 29, 5) || this->database->getBool(0xF442, 28, 5) || this->database->getBool(0xF442, 29, 6));
    //qDebug()<<"step4";

    if (this->database->CTHM_EmgyBrake)
    {
        ui->label_EmergencyBrake->show();
    }
    else
    {
        ui->label_EmergencyBrake->hide();
    }
    //qDebug()<<"step5";

    if (this->database->pisAutoMode)
        ui->label_Broadcast->setText(QString("全自动\n广播"));
    else
        ui->label_Broadcast->setText(QString("半自动\n广播"));
    //qDebug()<<"step6";

    if (this->database->riomRM)
        this->setMode(RM);
    else if (this->database->riomATP)
        this->setMode(ATP);
    else if (this->database->riomATO)
        this->setMode(ATO);
    else if (this->database->riomATB)
        this->setMode(ATB);
    else if (this->database->riomIATP)
        this->setMode(IATP);
    else if (this->database->riomATCCutOff)
        this->setMode(ATCCUTOFF);
    else if (this->database->riomWashMode)
        this->setMode(WASH);
    else
        this->setMode(OTHER);
    //qDebug()<<"step7";

    this->setBHB(this->database->DICT_M2DI1I14BHBStaFB_A2);
}

void MainPage::judgeSlide(QLabel *label, bool slide)
{
    if (slide)
        label->show();
    else
        label->hide();
}

void MainPage::judgeIdle(QLabel *label, bool idle, bool ebSlide)
{
    if (idle)
    {
        label->setText(QString("空转"));
        label->show();
    }
    else if (ebSlide)
    {
        label->setText(QString("滑行"));
        label->show();
    }
    else
    {
        label->setText("");
        label->hide();
    }
}

void MainPage::setMode(int mode)
{
    switch (mode)
    {
    case RM:
        ui->label_washing->setText(QString("RM模式"));
        ui->label_washing->show();
        break;
    case ATP:
        ui->label_washing->setText(QString("ATP模式"));
        ui->label_washing->show();
        break;
    case ATO:
        ui->label_washing->setText(QString("ATO模式"));
        ui->label_washing->show();
        break;
    case ATB:
        ui->label_washing->setText(QString("ATB模式"));
        ui->label_washing->show();
        break;
    case IATP:
        ui->label_washing->setText(QString("IATP模式"));
        ui->label_washing->show();
        break;
    case ATCCUTOFF:
        ui->label_washing->hide();
//        ui->label_washing->setText(QString("人工模式"));
//        ui->label_washing->show();
        break;
    case WASH:
        ui->label_washing->setText(QString("洗车模式"));
        ui->label_washing->show();
        break;
    default:
        ui->label_washing->setText("");
        ui->label_washing->hide();
        break;
    }
}

void MainPage::setBHB(bool bhbState)
{
    if (!bhbState)
    {
        ui->label_BHBBreak->show();
    }
    else
    {
        ui->label_BHBBreak->hide();
    }
}
