#include "publishsetpage.h"
#include "ui_publishsetpage.h"
#include "myfunction.h"
#include "database.h"
#include <QDebug>
#include "global.h"

PublishSetPage::PublishSetPage(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::PublishSetPage)
{
    ui->setupUi(this);
    _LOG << "PublishSetPage constructor";
}

PublishSetPage::~PublishSetPage()
{
    delete ui;
}


void PublishSetPage::on_btn_Tc1_clicked()
{
    MyFunction::set(QString("Position/position"), 1);
    this->database->hmiPosition = 1;

    this->showEvent(NULL);
    _LOG << "the hmi position has been set to" << this->database->hmiPosition;
}

void PublishSetPage::on_btn_Tc2_clicked()
{
    MyFunction::set(QString("/Position/position"), 2);
    this->database->hmiPosition = 2;

    this->showEvent(NULL);

    _LOG << "the hmi position has been set to" << this->database->hmiPosition;
}

void PublishSetPage::showEvent(QShowEvent *)
{
    ui->btn_Tc1->setStyleSheet(BUTTON_UP);
    ui->btn_Tc2->setStyleSheet(BUTTON_UP);

    if (1 == this->database->hmiPosition)
    {
        ui->btn_Tc1->setStyleSheet(BUTTON_DOWN);
    }
    else if(2 == this->database->hmiPosition)
    {
        ui->btn_Tc2->setStyleSheet(BUTTON_DOWN);
    }
}


void PublishSetPage::on_btn_Restart_clicked()
{
    system("reboot");
}

void PublishSetPage::on_btn_Back_clicked()
{
     emit this->changePage(uDebugPage);
}
