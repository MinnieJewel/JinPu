#include "setpasswordpage.h"
#include "ui_setpasswordpage.h"
#include <QDebug>
#include "global.h"
#include <QButtonGroup>
#include "myfunction.h"

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

enum passwordNo
{
    curPasswordId = 0,
    newPasswordId,
    confPasswordId
};

SetPasswordPage::SetPasswordPage(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::SetPasswordPage)
{
    ui->setupUi(this);
    _LOG << "SetPasswordPage constructor";

    this->inputButtons = new QButtonGroup(this);
    this->inputButtons->addButton(ui->btn_0, button0);
    this->inputButtons->addButton(ui->btn_1, button1);
    this->inputButtons->addButton(ui->btn_2, button2);
    this->inputButtons->addButton(ui->btn_3, button3);
    this->inputButtons->addButton(ui->btn_4, button4);
    this->inputButtons->addButton(ui->btn_5, button5);
    this->inputButtons->addButton(ui->btn_6, button6);
    this->inputButtons->addButton(ui->btn_7, button7);
    this->inputButtons->addButton(ui->btn_8, button8);
    this->inputButtons->addButton(ui->btn_9, button9);
    this->inputButtons->addButton(ui->btn_clear, buttonClear);
    this->inputButtons->setExclusive(true);

    connect(this->inputButtons, SIGNAL(buttonClicked(int)), this, SLOT(typeInPassword(int)));

    this->passwordButtons = new QButtonGroup(this);
    this->passwordButtons->addButton(ui->btn_currentPwd, curPasswordId);
    this->passwordButtons->addButton(ui->btn_newPwd, newPasswordId);
    this->passwordButtons->addButton(ui->btn_confirmPwd, confPasswordId);
    this->passwordButtons->setExclusive(true);

    connect(this->passwordButtons, SIGNAL(buttonClicked(int)), this, SLOT(selectInsert(int)));

    this->initialValues();
}



SetPasswordPage::~SetPasswordPage()
{
    delete ui;
}

void SetPasswordPage::initialValues()
{
    //default input old password button is down
    this->currentButton = curPasswordId;
    this->passwordButtons->button(this->currentButton)->setStyleSheet(BUTTON_DOWN);
    //record the password that put in
    this->oldPassword = QString("");
    this->newPassword = QString("");
    this->confirmPassword = QString("");
    ui->label_pwdConfirm->hide();
    ui->label_confirm2->hide();
}

/*
function:
 change buttons style when selected;
 verify if oldpassword is correct;
*/
void SetPasswordPage::typeInPassword(int pwd)
{
    if(buttonClear == pwd)
    {
        if(curPasswordId == this->currentButton)
        {
            this->oldPassword = "";
        }
        else if (newPasswordId == this->currentButton)
        {
            this->newPassword = "";
        }
        else if (confPasswordId == this->currentButton)
        {
            this->confirmPassword = "";
        }
        this->passwordButtons->button(this->currentButton)->setText("");
        return;
    }
    QString input = "";
    if(curPasswordId == this->currentButton)
    {
        this->oldPassword += this->inputButtons->button(pwd)->text();
        input = this->oldPassword;
    }
    else
        if(newPasswordId == this->currentButton)
        {
            this->newPassword += this->inputButtons->button(pwd)->text();
            input = this->newPassword;
        }
    else
        if(confPasswordId == this->currentButton)
        {
            this->confirmPassword += this->inputButtons->button(pwd)->text();
            input = this->confirmPassword;
        }
    if(input.length() < 6)
        this->passwordButtons->button(this->currentButton)->setText(this->passwordButtons->button(this->currentButton)->text() + QString("*"));
}

void SetPasswordPage::selectInsert(int currentBtn)
{
    this->currentButton = currentBtn;
    for(int i = 0; i < this->passwordButtons->buttons().size(); i++)
        this->passwordButtons->button(i)->setStyleSheet(BUTTON_UP);

    this->passwordButtons->button(this->currentButton)->setStyleSheet(BUTTON_DOWN);
    if(1 == this->currentButton)
    {
        if(!checkPwdValue())
        {
            ui->label_pwdConfirm->setStyleSheet("border-image: url(:/image/wrongFlug.png);");
        }
        else
        {
            ui->label_pwdConfirm->setStyleSheet("border-image: url(:/image/rightFlug.png);");
        }
        ui->label_pwdConfirm->show();
    }
}


bool SetPasswordPage::checkPwdValue()
{
    if(this->database->troubleShootingPassword == this->oldPassword)
        return true;
    else
        return false;
}


void SetPasswordPage::on_btn_confirm_clicked()
{
    //check oldpassword again
    if(!checkPwdValue())
    {
         ui->label_pwdConfirm->setStyleSheet("border-image: url(:/image/wrongFlug.png);");
         return;
    }
    if(this->passwordButtons->button(newPasswordId)->text() == this->passwordButtons->button(confPasswordId)->text())
    {
        ui->label_pwdConfirm->hide();
        MyFunction::set(QString("/Password/troubleShooting"), this->newPassword);
        this->database->troubleShootingPassword = this->newPassword;
        _LOG << "the date record set password has been changed to" << this->newPassword;

        ui->label_confirm2->setText("密码设置成功！");
    }
    else
    {
        ui->label_confirm2->setText("新密码输入不一致，请重新输入。");
    }
    ui->label_confirm2->show();
}

void SetPasswordPage::on_btn_back_clicked()
{
    this->initialValues();
    emit this->changePage(uSetParameterPage);
}
