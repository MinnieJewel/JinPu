#include "runningrecordclearpage.h"
#include "ui_runningrecordclearpage.h"
#include <QDebug>
#include "global.h"
#include <QButtonGroup>
#include <QTimer>
enum buttonId
{
    serviceButton = 0,
    tractionButton,
    ap1Button,
    ap2Button,
    auxButton
};

RunningRecordClearPage::RunningRecordClearPage(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::RunningRecordClearPage)
{
    ui->setupUi(this);
    _LOG << "RunningRecordClearPage constructor";

    this->buttonGroup = new QButtonGroup(this);
    this->buttonGroup->addButton(ui->btn_ServiceDistance, serviceButton);
    this->buttonGroup->addButton(ui->btn_TractionCost, tractionButton);
    this->buttonGroup->addButton(ui->btn_Ap1Time, ap1Button);
    this->buttonGroup->addButton(ui->btn_Ap2Time, ap2Button);
    this->buttonGroup->addButton(ui->btn_AuxCost, auxButton);

    this->timerERMAP1 = new QTimer;
    this->timerERMAP2 = new QTimer;
    this->timerTraction = new QTimer;
    this->timerService = new QTimer;
    this->timerAux = new QTimer;

    this->timerERMAP1->stop();
    this->timerERMAP2->stop();
    this->timerTraction->stop();
    this->timerService->stop();
    this->timerAux->stop();
    // store the number of the timer started.
    this->timerCounter = 0;

    connect(this->buttonGroup, SIGNAL(buttonClicked(int)), SLOT(onClearButtonClick(int)));
    connect(this->timerERMAP1, SIGNAL(timeout()), SLOT(resetERMAP1Flag()));
    connect(this->timerERMAP2, SIGNAL(timeout()), SLOT(resetERMAP2Flag()));
    connect(this->timerTraction, SIGNAL(timeout()), SLOT(resetTractionFlag()));
    connect(this->timerService, SIGNAL(timeout()), SLOT(resetServiceFlag()));
    connect(this->timerAux, SIGNAL(timeout()), SLOT(resetAuxFlag()));
    ui->label_tractionDisableInfo->hide();
    ui->label_SIVDisableInfo->hide();
    ui->label_TractionCapacity->hide();
    ui->label_AuxCostCapacity->hide();
    ui->btn_TractionCost->hide();
    ui->btn_AuxCost->hide();
}

void RunningRecordClearPage::updatePage()
{
    //ui->label_serviceTime->setText(QString::number(this->database->serviceDistanceYear) + QString("-") + QString::number(this->database->serviceDistanceMonth) + QString("-") + QString::number(this->database->serviceDistanceDay));
    //ui->label_tractionTime->setText(QString::number(this->database->VVVFECYear)+ QString("-") + QString::number(this->database->VVVFECMonth) + QString("-") + QString::number(this->database->VVVFECDay)+ "\n"
                                    //+ QString::number(this->database->reEngyYear) + QString("-") + QString::number(this->database->reEngyMonth) + QString("-") + QString::number(this->database->reEngyDay));
    //ui->label_AP1Time->setText(QString::number(this->database->AP1ECYear) + QString("-") + QString::number(this->database->AP1ECMonth) + QString("-") + QString::number(this->database->AP1ECDay));
    //ui->label_Ap2Time->setText(QString::number(this->database->AP2ECYear) + QString("-") + QString::number(this->database->AP2ECMonth) + QString("-") + QString::number(this->database->AP2ECDay));
    //ui->label_AuxCostTime->setText(QString::number(this->database->SIVECYear) + QString("-") + QString::number(this->database->SIVECMonth) + QString("-") + QString::number(this->database->SIVECDay));

    ui->label_ServiceCapacity->setText(QString::number(this->database->ServiceDistance));
    //ui->label_TractionCapacity->setText(QString::number(this->database->VVVFEngyConsumption) + "\n" + QString::number(this->database->ReEngy));
    ui->label_Ap1Capacity->setText(QString::number(this->database->AP1RunningTime));
    ui->label_Ap2Capacity->setText(QString::number(this->database->AP2RunningTime));
    //ui->label_AuxCostCapacity->setText(QString::number(this->database->SIVEngyConsumption));
}


void RunningRecordClearPage::onClearButtonClick(int button)
{
    this->buttonGroup->button(button)->setEnabled(false);
    switch(button)
    {
    case serviceButton:
        this->database->hmiClearServiceDistance = true;
        this->database->flagChecker = 0xAA;
        this->timerService->start(8000);
        this->timerCounter++;
        break;

    case tractionButton:
//        if(!this->database->CTHM_ClaarVVVFECEnable)
//        {
//            ui->label_tractionDisableInfo->show();
//            break;
//        }
//        else
//        {
            this->database->hmiClearTractionCost = true;
            this->database->flagChecker = 0xAA;
            this->timerTraction->start(8000);
            this->timerCounter++;
            ui->label_tractionDisableInfo->hide();
            break;
        //}

    case ap1Button:
        this->database->hmiClearERMAP1Time = true;
        this->database->flagChecker = 0xAA;
        this->timerERMAP1->start(8000);
        this->timerCounter++;
        break;

    case ap2Button:
        this->database->hmiClearERMAP2Time = true;
        this->database->flagChecker = 0xAA;
        this->timerERMAP2->start(8000);
        this->timerCounter++;
        break;

    case auxButton:
//        if (!this->database->CTHM_ClearSIVECEnable)
//        {
//            ui->label_SIVDisableInfo->show();
//            break;
//        }
//        else
//        {
            this->database->hmiClearAuxCost = true;
            this->database->flagChecker = 0xAA;
            this->timerAux->start(8000);
            this->timerCounter++;
            break;
        //}
    }
}

RunningRecordClearPage::~RunningRecordClearPage()
{
    delete ui;
}


void RunningRecordClearPage::resetServiceFlag()
{
    this->database->hmiClearServiceDistance = false;
    this->timerService->stop();
    this->timerCounter--;
    this->buttonGroup->button(serviceButton)->setEnabled(true);
    if(0 >= this->timerCounter)
        this->database->flagChecker = 0x55;
}

void RunningRecordClearPage::resetTractionFlag()
{
    this->database->hmiClearTractionCost = false;
    this->timerTraction->stop();
    this->timerCounter--;
    this->buttonGroup->button(tractionButton)->setEnabled(true);
    if(0 >= this->timerCounter)
        this->database->flagChecker = 0x55;
}

void RunningRecordClearPage::resetERMAP1Flag()
{
    this->database->hmiClearERMAP1Time = false;
    this->timerERMAP1->stop();
    this->timerCounter--;
    this->buttonGroup->button(ap1Button)->setEnabled(true);
    if(0 >= this->timerCounter)
        this->database->flagChecker = 0x55;
}

void RunningRecordClearPage::resetERMAP2Flag()
{
    this->database->hmiClearERMAP2Time = false;
    this->timerERMAP2->stop();
    this->timerCounter--;
    this->buttonGroup->button(ap2Button)->setEnabled(true);
    if(0 >= this->timerCounter)
        this->database->flagChecker = 0x55;
}

void RunningRecordClearPage::resetAuxFlag()
{
    this->database->hmiClearAuxCost = false;
    this->timerAux->stop();
    this->timerCounter--;
    this->buttonGroup->button(auxButton)->setEnabled(true);
    if(0 >= this->timerCounter)
        this->database->flagChecker = 0x55;
}

void RunningRecordClearPage::on_btn_back_clicked()
{
    emit this->changePage(uMaintainancePage);
}
