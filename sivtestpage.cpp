#include "sivtestpage.h"
#include "ui_sivtestpage.h"
#include <QDebug>
#include "global.h"
#include "vehiclelogo.h"

#define _VALID ("background-color: green;")
#define _INVALID ("background-color: black;")

SIVTestPage::SIVTestPage(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::SIVTestPage)
{
    ui->setupUi(this);
    _LOG << "SIVTestPage constructor";
    this->vehicleLogo = new VehicleLogo(this);
    this->vehicleLogo->setGeometry(0, 10, this->vehicleLogo->width(), this->vehicleLogo->height());
}

SIVTestPage::~SIVTestPage()
{
    delete ui;
}

void SIVTestPage::updatePage()
{
    this->getState(ui->label_reset1, this->database->CTAX1_Reset);
    this->getState(ui->label_reset4, this->database->CTAX2_Reset);
    this->getState(ui->label_cut1, this->database->CTAX1_Cutoff);
    this->getState(ui->label_cut4, this->database->CTAX2_Cutoff);
}

void SIVTestPage::getState(QLabel *label, bool state)
{
    if(state)
        label->setStyleSheet(_VALID);
    else
        label->setStyleSheet(_INVALID);
}
