#include "wheeldiaset.h"
#include "ui_wheeldiaset.h"
#include <QButtonGroup>
#include <QTimer>
#include <QDebug>
#include "global.h"


#define BTN_UNSELECTED ("font: 20px, SimHei; color: black; background-color: rgb(250, 250, 250); border-radius: 0px;")
#define BTN_SELECTED ("font: 20px, SimHei; color: white; background-color: rgb(0, 0, 250); border-radius: 0px;")

WheelDiaSet::WheelDiaSet(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::WheelDiaSet)
{
    ui->setupUi(this);
    _LOG << "WheelDiaSet constructor";
    buttonGroup = new QButtonGroup(this);
    buttonGroup->setExclusive(true);
    buttonGroup->addButton(ui->btn_wheelDia1, 0);
    buttonGroup->addButton(ui->btn_wheelDia2, 1);
    buttonGroup->addButton(ui->btn_wheelDia3, 2);
    buttonGroup->addButton(ui->btn_wheelDia4, 3);
    connect(buttonGroup, SIGNAL(buttonClicked(int)), this, SLOT(setSelectedButton(int)));

    this->counter = 0;
    this->setSelectedButton(counter);

    QPushButton *buttons[] = {
                                ui->btn_0,
                                ui->btn_1,
                                ui->btn_2,
                                ui->btn_3,
                                ui->btn_4,
                                ui->btn_5,
                                ui->btn_6,
                                ui->btn_7,
                                ui->btn_8,
                                ui->btn_9,
                                ui->btn_clear,
                                ui->btn_confirm,
                                ui->btn_back
    };

       for(unsigned int i = 0; i < (sizeof buttons / sizeof (QPushButton *)); i++)
    {
        connect(buttons[i], SIGNAL(clicked()), this, SLOT(mykeyPressEvent()));
    }

       this->timer = new QTimer;
       this->timer->stop();
       connect(this->timer, SIGNAL(timeout()), this, SLOT(resetHmiSetWheelDiaCommand()));
}

WheelDiaSet::~WheelDiaSet()
{
    delete ui;
}

void WheelDiaSet::showEvent(QShowEvent *)
{
    this->database->wheelDiameterTc1 = this->database->CTHM_WheelDigTc1FedBk;
    this->database->wheelDiameterMp1 = this->database->CTHM_WheelDigMp1FedBk;
    this->database->wheelDiameterMp2 = this->database->CTHM_WheelDigMp2FedBk;
    this->database->wheelDiameterTc2 = this->database->CTHM_WheelDigTc2FedBk;

    ui->btn_wheelDia1->setText(QString::number(this->database->CTHM_WheelDigTc1FedBk));
    ui->btn_wheelDia2->setText(QString::number(this->database->CTHM_WheelDigMp1FedBk));
    ui->btn_wheelDia3->setText(QString::number(this->database->CTHM_WheelDigMp2FedBk));
    ui->btn_wheelDia4->setText(QString::number(this->database->CTHM_WheelDigTc2FedBk));

    ui->label_errorInfo->hide();
}

void WheelDiaSet::mykeyPressEvent()
{
    if(this->sender() == ui->btn_clear)
    {
        this->buttonGroup->button(counter)->setText(QString(""));
    }
    else if(this->sender() == ui->btn_back)
    {
        emit this->changePage(uSetParameterPage);
    }
    else if(this->sender() == ui->btn_confirm)
    {
        if(!this->checkValue())
        {
            ui->label_errorInfo->show();
        }
        else
        {
            QString text = this->buttonGroup->button(this->counter)->text();

            if(this->timer->isActive() == false)
            {
                this->ui->btn_confirm->setEnabled(false);
                this->ui->btn_back->setEnabled(false);

                this->setWheelDiameter();
                this->timer->start(5000);
            }
            qDebug() << __DATE__ << __TIME__ << "vehicle" << this->counter + 1 << "\'s wheel diameter has been set to"<< text;
        }
    }
    else
    {
        QString text = this->buttonGroup->button(this->counter)->text();
        if (text.length() >= 3)
        {
            text.clear();
        }
        this->buttonGroup->button(this->counter)->setText(text.append(((QPushButton *)this->sender())->text()));
    }
}

bool WheelDiaSet::checkValue()
{
    for(int i = 0; i < buttonGroup->buttons().size(); i++)
    {
        unsigned short int setDiameter = this->buttonGroup->button(i)->text().toUShort();
        if (setDiameter > 840 || setDiameter < 770)
        {
             return false;
        }
    }
    return true;
}

void WheelDiaSet::setWheelDiameter()
{
    ui->label_errorInfo->hide();
    this->database->flagChecker = 0xAA;

    this->database->wheelDiameterTc1 = this->buttonGroup->button(0)->text().toUShort() - 700;
    this->database->saveWheelDigflag_Tc1 = true;

    this->database->wheelDiameterMp1 = this->buttonGroup->button(1)->text().toUShort() - 700;
    this->database->saveWheelDigflag_Mp1 = true;

    this->database->wheelDiameterMp2 = this->buttonGroup->button(2)->text().toUShort() - 700;
    this->database->saveWheelDigflag_Mp2 = true;

    this->database->wheelDiameterTc2 = this->buttonGroup->button(3)->text().toUShort() - 700;
    this->database->saveWheelDigflag_Tc2 = true;
}

void WheelDiaSet::resetHmiSetWheelDiaCommand()
{
    this->timer->stop();
    this->database->saveWheelDigflag_Tc1 = false;
    this->database->saveWheelDigflag_Mp1 = false;
    this->database->saveWheelDigflag_Mp2 = false;
    this->database->saveWheelDigflag_Tc2 = false;

    this->database->flagChecker = 0x55;
    ui->btn_confirm->setEnabled(true);
    ui->btn_back->setEnabled(true);
}
void WheelDiaSet::updatePage()
{
    ui->label_original1->setText(QString::number(this->database->CTHM_WheelDigTc1FedBk));
    ui->label_original2->setText(QString::number(this->database->CTHM_WheelDigMp1FedBk));
    ui->label_original3->setText(QString::number(this->database->CTHM_WheelDigMp2FedBk));
    ui->label_original4->setText(QString::number(this->database->CTHM_WheelDigTc2FedBk));
}
/*
name:setSelectedButton
function:set label's style which want be set.
*/
void WheelDiaSet::setSelectedButton(int index)
{
    this->counter = index;

    for(int i = 0; i < this->buttonGroup->buttons().size(); i++)
    {
        this->buttonGroup->button(i)->setStyleSheet(BTN_UNSELECTED);
    }
    if(buttonGroup->button(index))
    {
       buttonGroup->button(index)->setStyleSheet(BTN_SELECTED);
    }
}



