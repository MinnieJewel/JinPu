#include "setvehicleno.h"
#include "ui_setvehicleno.h"
#include "global.h"
#include <QButtonGroup>
#include <QTimer>

#define BTN_UNSELECTED ("font: 20px, SimHei; color: black; background-color: rgb(250, 250, 250); border-radius: 0px;")
#define BTN_SELECTED ("font: 20px, SimHei; color: white; background-color: rgb(0, 0, 250); border-radius: 0px;")

enum inputNo
{
    button0 = 0,
    button1,
    button2,
    button3,
    button4,
    button5,
    button6,
    button7,
    button8,
    button9,
    buttonClear
};

SetVehicleNo::SetVehicleNo(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::SetVehicleNo)
{
    ui->setupUi(this);

    this->buttonGroup = new QButtonGroup(this);
    this->buttonGroup->addButton(ui->btn_0, button0);
    this->buttonGroup->addButton(ui->btn_1, button1);
    this->buttonGroup->addButton(ui->btn_2, button2);
    this->buttonGroup->addButton(ui->btn_3, button3);
    this->buttonGroup->addButton(ui->btn_4, button4);
    this->buttonGroup->addButton(ui->btn_5, button5);
    this->buttonGroup->addButton(ui->btn_6, button6);
    this->buttonGroup->addButton(ui->btn_7, button7);
    this->buttonGroup->addButton(ui->btn_8, button8);
    this->buttonGroup->addButton(ui->btn_9, button9);
    this->buttonGroup->addButton(ui->btn_Clear, buttonClear);
    this->buttonGroup->setExclusive(true);
    connect(this->buttonGroup, SIGNAL(buttonClicked(int)), this, SLOT(setCurrentNo(int)));

    //default set VehicleNo
    this->ifSetVehicleNo = true;
    ui->btn_vehicleNo->setStyleSheet(BUTTON_DOWN);
    this->timer = new QTimer;
    this->timer->stop();
    connect(this->timer, SIGNAL(timeout()), this, SLOT(resetHmiSetWheelDiaCommand()));
    ui->label_info->hide();
}

SetVehicleNo::~SetVehicleNo()
{
    delete ui;
}
/*
name:setCurrentNo
parameter:number
function: show the select number on the buttons' text.(vehicleNo/lineNo)
*/
void SetVehicleNo::setCurrentNo(int number)
{
    if(buttonClear == number)
    {
        if(this->ifSetVehicleNo)
            this->vehicleNo = "";
        else
            this->lineNo = "";
    }
    else
    {
        if(this->ifSetVehicleNo)
            this->vehicleNo += this->buttonGroup->button(number)->text();
        else
            this->lineNo += this->buttonGroup->button(number)->text();
    }
    if(this->ifSetVehicleNo)
        ui->btn_vehicleNo->setText(this->vehicleNo);
    else
        ui->btn_lineNo->setText(this->lineNo);
}

/*
name:setSelectedButton
function:set label's style which want be set.
parameter: record if current button is vehicle number button
*/
void SetVehicleNo::setSelectedButton(bool currentBtn)
{
    if(currentBtn)
    {
        ui->btn_vehicleNo->setStyleSheet(BTN_SELECTED);
        ui->btn_lineNo->setStyleSheet(BTN_UNSELECTED);
    }
    else
    {
        ui->btn_vehicleNo->setStyleSheet(BTN_UNSELECTED);
        ui->btn_lineNo->setStyleSheet(BTN_SELECTED);
    }
}


void SetVehicleNo::on_btn_vehicleNo_clicked()
{
    this->ifSetVehicleNo = true;
    this->setSelectedButton(this->ifSetVehicleNo);
}

void SetVehicleNo::on_btn_lineNo_clicked()
{
    this->ifSetVehicleNo = false;
    this->setSelectedButton(this->ifSetVehicleNo);
}

void SetVehicleNo::on_btn_confirm_clicked()
{
    if(ui->btn_lineNo->text().toUShort() > 255)
    {
        ui->label_info->show();
        ui->btn_lineNo->setText("");
        this->lineNo = "";
        return;
    }
    else if(ui->btn_vehicleNo->text().toUShort() < 1 || ui->btn_vehicleNo->text().toUShort() > 20)
    {
        ui->label_info->show();
        ui->btn_vehicleNo->setText("");
        this->vehicleNo = "";
        return;
    }
    else
    {
        ui->label_info->hide();
        this->database->hmiTrainNumber = ui->btn_vehicleNo->text().toUShort();
    }
    this->database->hmiLineNumber = ui->btn_lineNo->text().toUShort();
    this->database->hmiSaveTrainNum = true;
    this->database->hmiSaveLineNum = true;
    this->database->flagChecker = 0xAA;
    this->timer->start(5000);
    ui->btn_confirm->setEnabled(false);
    ui->btn_back->setEnabled(false);
}

void SetVehicleNo::resetHmiSetWheelDiaCommand()
{
    this->timer->stop();
    this->database->hmiSaveTrainNum = false;
    this->database->hmiSaveLineNum = false;
    this->database->flagChecker = 0x55;
    ui->btn_confirm->setEnabled(true);
    ui->btn_back->setEnabled(true);
}

void SetVehicleNo::on_btn_back_clicked()
{
    emit this->changePage(uSetParameterPage);
}
