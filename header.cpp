#include "header.h"
#include "ui_header.h"

#include <QTimer>
#include <QDateTime>
#include <QLabel>
#include <QPushButton>
#include <QDebug>
#include "crrcfault.h"
#include "global.h"

#define _NOFAULT ("font:20px; color: white; background-color:black;border: 2px groove, gray; border-color: gray;")
#define _FAULT ("border:1px solid white; border-image: url(:/image/FaultRed.PNG);border: 2px groove, gray; border-color: gray;")
#define _GREEN ("font: 20px, SimHei; color: rgb(0,0,0); background-color: rgb(0, 255, 0); border: 2px groove, gray; border-color: gray;")
#define _DARKRED ("font: 20px, SimHei; color: black; background-color: rgb(170, 0, 0); border: 2px groove, gray; border-color: gray;")
#define _BLACK ("font: 20px, SimHei; color: white; background-color: black; border: 2px groove, gray; border-color: gray;")
#define _RED ("font: 20px, SimHei; color: black; background-color: red; border: 2px groove, gray; border-color: gray;")

Header::Header(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::Header)
{
    ui->setupUi(this);
     _LOG << "Header constructor";
    this->levelList << "" << "B7" << "B6" << "B5" << "B4" << "B3" << "B2"
            << "B1" << "FB" << "无" << "惰行" << "P1" << "P2" << "P3" << "P4";
}

Header::~Header()
{
    delete ui;
}

void Header::setNetVoltage(int voltage)
{
    ui->netVoltageValue->setText(QString::number(voltage) + QString("V"));
}

void Header::setNetCurrent(int current)
{
    ui->netCurrentValue->setText(QString::number(current) + QString("A"));
}

void Header::setSpeed(double speed)
{
    ui->speedValue->setText(QString::number(speed) + QString("km/h"));
}

void Header::setLevel(int level)
{
    if (0 > level || level > 14)
    {
        _LOG << "in wrong level!";
        return;
    }

    if (this->database->CTHM_EmgyBrake)
    {
        ui->levelValue->setText("紧急制动");
        ui->levelValue->setStyleSheet(_RED);
    }
    else if (10 == level)
    {
        ui->levelValue->setText("惰行");
        ui->levelValue->setStyleSheet(_BLACK);
    }

    else if ( 10 < level)
    {
        ui->levelValue->setText("牵引：" + this->levelList.at(level));
        ui->levelValue->setStyleSheet(_GREEN);
    }

    else if (9 > level && 0 < level)
    {
        ui->levelValue->setText("制动：" + this->levelList.at(level));
        ui->levelValue->setStyleSheet(_DARKRED);
    }
    else
    {
        ui->levelValue->setText("无效");
        ui->levelValue->setStyleSheet(_BLACK);
    }
}

void Header::setCurrentStation(unsigned char station)
{
    ui->currentStationValue->setText("");
    //ui->currentStationValue->setText(QString(station));
}

void Header::updatePage()
{
    ui->dataTime->setText(QDateTime::currentDateTime().toString("hh:mm:ss") +"\n"+
                          QDateTime::currentDateTime().toString("yyyy-MM-dd"));

    //ui->dataTime->setText("2018-01-01\n10:20:30");
    this->setNetVoltage(this->database->CTHM_CatenaryVoltage);
    this->setNetCurrent(this->database->CTHM_CatenaryCurrent);
    this->setSpeed(this->database->CTHM_TrainSpeed/10.0);
    this->setLevel(int(this->database->CTHM_Grade));
    this->setCurrentStation(this->database->CTHM_CurrentStation);

    if (0 != this->crrcFault->getCurrentFaultListSize())
    {
        ui->faultButton->setStyleSheet(_FAULT);
        ui->faultButton->setText("");
    }
    else
    {
        ui->faultButton->setStyleSheet(_NOFAULT);
        ui->faultButton->setText("故障\n按钮");
    }
}

void Header::installCrrcFault(CrrcFault *crrcFault)
{
    this->crrcFault = crrcFault;
}

void Header::setPageName(QString name)
{
    ui->pageName->setText(name);
}


void Header::on_faultButton_clicked()
{
    emit this->changePage(uCurrentFaultList);
}
