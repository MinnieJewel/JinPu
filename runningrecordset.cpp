#include "runningrecordset.h"
#include "ui_runningrecordset.h"
#include <QButtonGroup>
#include <QTimer>
#include <QDebug>
#include "global.h"


#define BTN_UNSELECTED ("font: 20px, SimHei; color: black; background-color: rgb(250, 250, 250); border-radius: 5px;")
#define BTN_SELECTED ("font: 20px, SimHei; color: white; background-color: rgb(68, 114, 196); border-radius: 5px;")

enum button_Id
{
    serviceKilometerId = 0,
    runningKilometerId
};

enum setNo
{
    button0,
    button1,
    button2,
    button3,
    button4,
    button5,
    button6,
    button7,
    button8,
    button9
};

enum setEnergery
{
    SIV1 = 0,
    SIV2,
    DCU1,
    DCU2,
    DCU3,
    DCU4
};

RunningRecordSet::RunningRecordSet(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::RunningRecordSet)
{
    ui->setupUi(this);
    //set service kilometers parameter by default
    this->currentSet = true;

    this->buttonGroup = new QButtonGroup(this);
    this->buttonGroup->addButton(ui->btn_setServiceKilometer, serviceKilometerId);
    this->buttonGroup->addButton(ui->btn_setTagRunningKilometer, runningKilometerId);
    this->buttonGroup->setExclusive(true);
    connect(this->buttonGroup, SIGNAL(buttonClicked(int)), SLOT(onBtnClicked(int)));
    //initial kilometers text
    this->serviceKilometers = QString::number(this->database->ServiceDistance);
    this->runningKilometers = QString::number(this->database->runningKilometers);
    this->buttonGroup->button(serviceKilometerId)->setText(this->serviceKilometers);
    this->buttonGroup->button(runningKilometerId)->setText(this->runningKilometers);

    this->buttonNoGroup = new QButtonGroup(this);
    this->buttonNoGroup->addButton(ui->btn_0, button0);
    this->buttonNoGroup->addButton(ui->btn_1, button1);
    this->buttonNoGroup->addButton(ui->btn_2, button2);
    this->buttonNoGroup->addButton(ui->btn_3, button3);
    this->buttonNoGroup->addButton(ui->btn_4, button4);
    this->buttonNoGroup->addButton(ui->btn_5, button5);
    this->buttonNoGroup->addButton(ui->btn_6, button6);
    this->buttonNoGroup->addButton(ui->btn_7, button7);
    this->buttonNoGroup->addButton(ui->btn_8, button8);
    this->buttonNoGroup->addButton(ui->btn_9, button9);

    this->buttonNoGroup->setExclusive(true);

    connect(this->buttonNoGroup, SIGNAL(buttonClicked(int)), SLOT(onBtnNoClicked(int)));

    this->timer = new QTimer;
    this->timer->stop();
    connect(this->timer, SIGNAL(timeout()),this, SLOT(resetFlag()));
    ui->label_errorInfo->hide();

    this->buttonResetEnergyGroup = new QButtonGroup(this);
    this->buttonResetEnergyGroup->addButton(ui->btn_resetSIV1, SIV1);
    this->buttonResetEnergyGroup->addButton(ui->btn_resetSIV2, SIV2);
    this->buttonResetEnergyGroup->addButton(ui->btn_resetDCU1, DCU1);
    this->buttonResetEnergyGroup->addButton(ui->btn_resetDCU2, DCU2);
    this->buttonResetEnergyGroup->addButton(ui->btn_resetDCU3, DCU3);
    this->buttonResetEnergyGroup->addButton(ui->btn_resetDCU4, DCU4);

    connect(this->buttonResetEnergyGroup, SIGNAL(buttonClicked(int)), this, SLOT(onResetEnergy(int)));
    this->resetTimer = new QTimer;
    this->resetTimer->stop();

    connect(this->resetTimer, SIGNAL(timeout()), this, SLOT(resetEngyFlag()));
}

RunningRecordSet::~RunningRecordSet()
{
    delete ui;
}

void RunningRecordSet::onBtnClicked(int id)
{
    for(int i = 0; i < this->buttonGroup->buttons().size(); i++)
    {
        buttonGroup->button(i)->setStyleSheet(BTN_UNSELECTED);
    }
    buttonGroup->button(id)->setStyleSheet(BTN_SELECTED);
    if (serviceKilometerId == id)
        this->currentSet = true;
    else if (runningKilometerId == id)
        this->currentSet = false;
}

void RunningRecordSet::on_btn_clear_clicked()
{
    if(this->currentSet)
    {
        this->buttonGroup->button(serviceKilometerId)->setText("");
        this->serviceKilometers = "";
    }

    else
    {
        this->buttonGroup->button(runningKilometerId)->setText("");
        this->runningKilometers = "";
    }
}

void RunningRecordSet::onBtnNoClicked(int number)
{
    if(this->currentSet)
    {
        this->serviceKilometers += this->buttonNoGroup->button(number)->text();
        this->buttonGroup->button(serviceKilometerId)->setText(this->serviceKilometers);
    }
    else
    {
        this->runningKilometers += this->buttonNoGroup->button(number)->text();
        this->buttonGroup->button(runningKilometerId)->setText(this->runningKilometers);
    }
}

void RunningRecordSet::on_btn_confirm_clicked()
{
    if(this->serviceKilometers.trimmed().toUInt() < (uint)65535 * 65535 && this->runningKilometers.trimmed().toUInt() < (uint)65535 * 65535)
    {
        this->database->hmiSetServiceKilometer = this->serviceKilometers.trimmed().toUInt();
        this->database->hmiSetRunningKilometer = this->runningKilometers.trimmed().toUInt();
        this->database->hmiSetTagServiceKilometer = 234;
        this->database->hmiSetTagRunningKilometer = 234;
        this->timer->start(8000);
        this->database->flagChecker = 0xAA;
        ui->btn_confirm->setEnabled(false);
        ui->btn_back->setEnabled(false);
        ui->label_errorInfo->hide();
        this->serviceKilometers = "";
        this->runningKilometers = "";
    }
    else
        ui->label_errorInfo->show();
    return;
}

void RunningRecordSet::resetFlag()
{
    this->timer->stop();
    this->database->hmiSetTagServiceKilometer = 0;
    this->database->hmiSetTagRunningKilometer = 0;
    this->database->flagChecker = 0x55;
    ui->btn_confirm->setEnabled(true);
    ui->btn_back->setEnabled(true);
}

void RunningRecordSet::on_btn_back_clicked()
{
    this->serviceKilometers = QString::number(this->database->ServiceDistance);
    this->runningKilometers = QString::number(this->database->runningKilometers);
    this->buttonGroup->button(serviceKilometerId)->setText(this->serviceKilometers);
    this->buttonGroup->button(runningKilometerId)->setText(this->runningKilometers);
    emit this->changePage(uMaintainancePage);
}

void RunningRecordSet::onResetEnergy(int number)
{
    this->buttonResetEnergyGroup->button(number)->setEnabled(false);
    this->database->flagChecker = 0xAA;
    switch (number)
    {
    case SIV1:
        this->database->hmiResetSIV1Egy = true;
        this->resetTimer->start(5000);
        break;

    case SIV2:
        this->database->hmiResetSIV2Egy = true;
        this->resetTimer->start(5000);
        break;

    case DCU1:
        this->database->hmiResetDCU1Egy = true;
        this->resetTimer->start(5000);
        break;

    case DCU2:
        this->database->hmiResetDCU2Egy = true;
        this->resetTimer->start(5000);
        break;

    case DCU3:
        this->database->hmiResetDCU3Egy = true;
        this->resetTimer->start(5000);
        break;

    case DCU4:
        this->database->hmiResetDCU4Egy = true;
        this->resetTimer->start(5000);
        break;
    }
}

void RunningRecordSet::resetEngyFlag()
{
    this->database->hmiResetSIV1Egy = false;
    this->database->hmiResetSIV2Egy = false;
    this->database->hmiResetDCU1Egy = false;
    this->database->hmiResetDCU2Egy = false;
    this->database->hmiResetDCU3Egy = false;
    this->database->hmiResetDCU4Egy = false;
    this->database->flagChecker = 0x55;
    this->resetTimer->stop();
    for (int resetbtnNo = 0; resetbtnNo < this->buttonResetEnergyGroup->buttons().size(); resetbtnNo ++)
    {
        this->buttonResetEnergyGroup->button(resetbtnNo)->setEnabled(true);
    }
}
