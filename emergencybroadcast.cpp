#include "emergencybroadcast.h"
#include "ui_emergencybroadcast.h"
#include <QDebug>
#include <QButtonGroup>
#include <QTimer>
#include <QDebug>
#include "global.h"


#define BTN_UNSELECTED ("font: 30px, SimHei; color: black; background-color: rgb(250, 250, 250); border-radius: 5px;")
#define BTN_SELECTED ("font: 30px, SimHei; color: white; background-color: rgb(0, 0, 250); border-radius: 5px;")
enum broadCastID
{
    none = 0,
    faultPlatFormClear,
    clearAlert,
    savePlatFormClear,
    intervalClear,
    otherClear,
    channelExchange,
    currentPark,
    otherPark
};

EmergencyBroadcast::EmergencyBroadcast(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::EmergencyBroadcast)
{
     ui->setupUi(this);
     _LOG << "EmergencyBroadcast constructor";
     this->broadCastButtons = new QButtonGroup(this);
     this->broadCastButtons->setExclusive(true);
     this->broadCastButtons->addButton(ui->btn0, none);
     this->broadCastButtons->addButton(ui->btn1, faultPlatFormClear);
     this->broadCastButtons->addButton(ui->btn2, clearAlert);
     this->broadCastButtons->addButton(ui->btn3, savePlatFormClear);
     this->broadCastButtons->addButton(ui->btn4, intervalClear);
     this->broadCastButtons->addButton(ui->btn5, otherClear);
     this->broadCastButtons->addButton(ui->btn6, channelExchange);
     this->broadCastButtons->addButton(ui->btn7, currentPark);
     this->broadCastButtons->addButton(ui->btn8, otherPark);

     this->broadcastCode = none;
     connect(this->broadCastButtons, SIGNAL(buttonClicked(int)), this, SLOT(setEmergencyBroadcastCode(int)));

     //set timer
     this->timer = new QTimer;
     connect(this->timer, SIGNAL(timeout()), this, SLOT(resetHmiBroadcastCommand()));

     this->broadcastStopTimer = new QTimer;
     connect(this->broadcastStopTimer, SIGNAL(timeout()), this, SLOT(setBroadcastStopCommand()));
}

EmergencyBroadcast::~EmergencyBroadcast()
{
    delete ui;
}

void EmergencyBroadcast::on_btn_Back_clicked()
{
    emit this->changePage(uMainPage);
}

void EmergencyBroadcast::setEmergencyBroadcastCode(int code)
{
    this->broadcastCode = code;
    this->setButtonStyle(code);
    this->sendBroadcastCode(this->broadcastCode);
}

void EmergencyBroadcast::setButtonStyle(int buttonId)
{
    if(NULL == this->broadCastButtons)
    {
        _LOG << "broadCastButtons is null!";
        return;
    }

    for(int i = 0; i < this->broadCastButtons->buttons().size(); i++)
    {
        this->broadCastButtons->button(i)->setStyleSheet(BTN_UNSELECTED);
    }

    this->broadCastButtons->button(buttonId)->setStyleSheet(BTN_SELECTED);
}

void EmergencyBroadcast::sendBroadcastCode(int code)
{
    if(this->timer->isActive())
        this->resetHmiBroadcastCommand();

    this->database->hmiEmergencyCode = code;
    this->database->hmiEmergencyCommand = true;
    this->database->flagChecker = 0xAA;
    this->timer->start(5000);
    _LOG << "send broadcast code :" << code;
}

void EmergencyBroadcast::resetHmiBroadcastCommand()
{
    this->database->hmiEmergencyCode = 0;
    this->database->hmiEmergencyCommand = false;
    this->database->flagChecker = 0x55;
    this->timer->stop();
    _LOG << "reset broadcast code.";
}


void EmergencyBroadcast::on_btn_cease_clicked()
{
    if(this->timer->isActive())
        this->resetHmiBroadcastCommand();

    this->broadCastButtons->button(this->broadcastCode)->setStyleSheet(BTN_UNSELECTED);
    this->database->hmiEmergencyStop = true;
    this->database->flagChecker = 0xAA;
    this->broadcastStopTimer->start(5000);
    _LOG << "send broadcast stop command.";
}

void EmergencyBroadcast::setBroadcastStopCommand()
{
    this->database->hmiEmergencyStop = false;
    this->database->flagChecker = 0x55;
    this->broadcastStopTimer->stop();
    _LOG << "broadcast stoped.";
}
