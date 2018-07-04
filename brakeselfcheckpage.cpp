#include "brakeselfcheckpage.h"
#include "ui_brakeselfcheckpage.h"
#include <QButtonGroup>
#include <QPushButton>
#include <QTimer>
#include <QDebug>
#include "global.h"

#define BTN_UNSELECTED ("font: 20px, SimHei; color: black; background-color: rgb(250, 250, 250); border-radius: 5px;")
#define BTN_SELECTED ("font: 20px, SimHei; color: white; background-color: rgb(0, 0, 250); border-radius: 5px;")
#define _INVALID ("font: 15px; color: rgb(0,0,0); background-color: grey; border: 2px groove, gray; border-color: gray;")
#define _VALID ("font: 15px; color: rgb(0,0,0); background-color: black; border: 2px groove, gray; border-color: gray;")
#define _OFFLINE ("font: 15px; color: rgb(0,0,0); background-color: white; border: 2px groove, gray; border-color: gray;")
#define _CUT ("border-image: url(:/image/cut.png);")
#define _SATIFIED ("background-color: rgb(0, 255, 0);")
#define _UNSATIFIED ("background-color: red;")


enum detectNo
{
    serial = 1,
    brake,
    antiSlip
};

BrakeSelfCheckPage::BrakeSelfCheckPage(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::BrakeSelfCheckPage)
{
    ui->setupUi(this);
    _LOG << "BrakeSelfCheckPage constructor";
    this->timer = new QTimer;
    this->detectModeGroup = new QButtonGroup(this);
    this->detectModeGroup->setExclusive(true);
    this->detectModeGroup->addButton(ui->btn_serialDetect, serial);
    this->detectModeGroup->addButton(ui->btn_brakeDetect, brake);
    this->detectModeGroup->addButton(ui->btn_antiSlip, antiSlip);
    this->detectMode = false;
    this->modeNo = 0;
    connect(this->detectModeGroup, SIGNAL(buttonClicked(int)), this, SLOT(setSelectedButton(int)));
    connect(this->timer, SIGNAL(timeout()), this, SLOT(resetDetectFlag()));
    ui->btn_start->setEnabled(false);
    ui->label_errorInfo->hide();
    ui->label_timeout->hide();
    ui->btn_keepBrake->setCheckable(true);
    connect(ui->btn_keepBrake, SIGNAL(toggled(bool)), this, SLOT(setToggleButton(bool)));
}

BrakeSelfCheckPage::~BrakeSelfCheckPage()
{
    delete ui;
}

void BrakeSelfCheckPage::updatePage()
{
   if(this->database->getBool(0xF413, 4, 3))
       ui->label_time1->setText(QString("超过24小时未自检"));
   else if(this->database->getBool(0xF413, 5, 2))
       ui->label_time1->setText(QString("零点之后未自检"));
   else
       ui->label_time1->setText(QString("小于24小时未自检"));

   if(this->database->getBool(0xF443, 4, 3))
       ui->label_time2->setText(QString("超过24小时未自检"));
   else if(this->database->getBool(0xF443, 5, 2))
       ui->label_time2->setText(QString("零点之后未自检"));
   else
       ui->label_time2->setText(QString("小于24小时未自检"));

   if (!this->database->getBool(0xF410, 29, 4))
   {
       ui->label_errorInfo->show();
       ui->label_prepare1->setStyleSheet(_UNSATIFIED);
   }
   else
   {
       ui->label_prepare1->setStyleSheet(_SATIFIED);
   }

   if (!this->database->getBool(0xF440, 29, 4))
   {
       ui->label_errorInfo->show();
       ui->label_prepare2->setStyleSheet(_UNSATIFIED);
   }
   else
   {
       ui->label_prepare2->setStyleSheet(_SATIFIED);
   }

   if (this->database->getBool(0xF410, 29, 4) && this->database->getBool(0xF440, 29, 4))
   {
       ui->label_errorInfo->hide();
   }

    this->testState(ui->label_Bogie1_1, this->database->getBool(0xF410, 29, 5), this->database->getBool(0xF411, 13, 4), this->database->getBool(0xF411, 12, 6));
    this->testState(ui->label_Bogie1_2, this->database->getBool(0xF410, 29, 5), this->database->getBool(0xF411, 29, 4), this->database->getBool(0xF411, 28, 6));
    this->testState(ui->label_Bogie2_1, this->database->getBool(0xF410, 29, 5), this->database->getBool(0xF412, 13, 4), this->database->getBool(0xF412, 12, 6));
    this->testState(ui->label_Bogie2_2, this->database->getBool(0xF410, 29, 5), this->database->getBool(0xF412, 29 ,4), this->database->getBool(0xF412, 28, 6));
    this->testState(ui->label_Bogie4_1, this->database->getBool(0xF440, 29, 5), this->database->getBool(0xF441, 13, 4), this->database->getBool(0xF441, 12, 6));
    this->testState(ui->label_Bogie4_2, this->database->getBool(0xF440, 29, 5), this->database->getBool(0xF441, 29, 4), this->database->getBool(0xF441, 28, 6));
    this->testState(ui->label_Bogie3_1, this->database->getBool(0xF440, 29, 5), this->database->getBool(0xF442, 13, 4), this->database->getBool(0xF442, 12, 6));
    this->testState(ui->label_Bogie3_2, this->database->getBool(0xF440, 29, 5), this->database->getBool(0xF442, 29 ,4), this->database->getBool(0xF442, 28, 6));

    if(this->database->CTHM_BCUSTOverTime)
        ui->label_timeout->show();
    else
        ui->label_timeout->hide();
}

void BrakeSelfCheckPage::setSelectedButton(int id)
{

    this->modeNo = id;
    this->detectMode = true;
        for(int i = 1; i <= this->detectModeGroup->buttons().size(); i++)
        {
            this->detectModeGroup->button(i)->setStyleSheet(BTN_UNSELECTED);
        }
            this->detectModeGroup->button(id)->setStyleSheet(BTN_SELECTED);

    ui->btn_start->setEnabled(this->detectMode);
}


void BrakeSelfCheckPage::on_btn_exit_clicked()
{
    this->resetDetectFlag();
    this->detectMode = false;
    if(0 != this->modeNo)
    {
        this->detectModeGroup->button(this->modeNo)->setStyleSheet(BTN_UNSELECTED);
    }
    ui->btn_start->setEnabled(this->detectMode);
    this->changePage(uTestPage);
}

void BrakeSelfCheckPage::on_btn_start_clicked()
{
    this->setDetectFlag();
}

void BrakeSelfCheckPage::setDetectFlag()
{
    this->database->bcuSelfTest = true;
    this->database->hmiBcuTestCode = this->modeNo;
    this->database->flagChecker = 0xAA;
    this->timer->start(5000);
    ui->btn_start->setEnabled(false);
}

void BrakeSelfCheckPage::resetDetectFlag()
{
    this->database->bcuSelfTest = false;
    this->database->flagChecker = 0x55;
    this->timer->stop();
    ui->btn_start->setEnabled(true);
}

void BrakeSelfCheckPage::on_btn_cease_clicked()
{
    this->resetDetectFlag();
}

void BrakeSelfCheckPage::testState(QLabel *label, bool underWay, bool failure, bool succeed)
{
    if(underWay)
        label->setText(QString("自检中..."));
    else
        if(failure)
            label->setText(QString("故障"));
    else
        if(succeed)
            label->setText(QString("正常"));
    else
        label->setText(QString("无效"));
}

void BrakeSelfCheckPage::setToggleButton(bool checked)
{
    if(checked)
    {
        ui->btn_keepBrake->setStyleSheet(BTN_SELECTED);
        //this->database->hmiCutSIV1 = true;
    }
    else
    {
        ui->btn_keepBrake->setStyleSheet(BTN_UNSELECTED);
        //this->database->hmiCutSIV1 = false;
    }
}
