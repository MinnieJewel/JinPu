#include "maintainloginpage.h"
#include "ui_maintainloginpage.h"
#include "global.h"
#include <QDebug>
#include <QDateTime>

#define BTN_UNSELECTED ("font: 20px, SimHei; color: black; background-color: rgb(250, 250, 250); border-radius: 0px;")
#define BTN_SELECTED ("font: 20px, SimHei; color: white; background-color: rgb(0, 0, 250); border-radius: 0px;")
MaintainLoginPage::MaintainLoginPage(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::MaintainLoginPage)
{
    ui->setupUi(this);
    _LOG << "MaintainLoginPage constructor";
    this->password = QString("");
    this->targetPage = 0;

    ui->label_remindInfo->hide();

    QPushButton *buttons[] = {
                                ui->pushButton0,
                                ui->pushButton1,
                                ui->pushButton2,
                                ui->pushButton3,
                                ui->pushButton4,
                                ui->pushButton5,
                                ui->pushButton6,
                                ui->pushButton7,
                                ui->pushButton8,
                                ui->pushButton9,
                                ui->pushButton_clear,
                                ui->btn_confirm,
                                ui->btn_back
                             };

    for (unsigned int i = 0; i < (sizeof buttons) / (sizeof buttons[0]); i++)
    {
        connect(buttons[i], SIGNAL(clicked()), this, SLOT(keyboardEvent()));
    }
}

MaintainLoginPage::~MaintainLoginPage()
{
    delete ui;
}


void MaintainLoginPage::keyboardEvent()
{
   if(this->sender() == ui->btn_confirm)
    {
       if(this->password == this->input)
       {
        ui->label_remindInfo->hide();
        this->input.clear();
        ui->label_input->setText("");
        emit this->changePage(this->targetPage);
       }
       else
       {
        this->input.clear();
        ui->label_input->setText("");
        ui->label_remindInfo->show();
       }
    }
   else if(this->sender() == ui->pushButton_clear)
   {
       this->input.clear();
       ui->label_input->setText("");
       ui->label_remindInfo->hide();
   }
   else if(this->sender() == ui->btn_back)
   {
       this->input.clear();
       ui->label_input->setText("");
       ui->label_remindInfo->hide();
       emit this->changePage(uMainPage);
   }
   else if(this->input.length() < 6)
   {
       this->input += ((QPushButton *)this->sender())->text();
   }

   ui->label_input->setText("");
   for(int i = 0; i < this->input.length(); i++)
   {
     ui->label_input->setText(ui->label_input->text() + QString("*"));
   }
}

void MaintainLoginPage::setPassword(QString password)
{
    this->password = password;
}
void MaintainLoginPage::showEvent(QShowEvent *)
{
    this->setPassword(this->database->troubleShootingPassword);
    this->targetPage = uMaintainancePage;
}
