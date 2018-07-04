#include "setparameterpage.h"
#include "ui_setparameterpage.h"
#include <QDebug>
#include "global.h"

SetParameterPage::SetParameterPage(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::SetParameterPage)
{
    ui->setupUi(this);
    _LOG << "SetParameterPage constructor";
}

SetParameterPage::~SetParameterPage()
{
    delete ui;
}

void SetParameterPage::on_btn_wheelDia_clicked()
{
    emit this->changePage(uWheelDiaSet);
}

void SetParameterPage::on_btn_Back_clicked()
{
    emit this->changePage(uMaintainancePage);
}

void SetParameterPage::on_btn_setTime_clicked()
{
    emit this->changePage(uTimeSetPage);
}


void SetParameterPage::on_pushButton_3_clicked()
{
    emit this->changePage(uSetpasswordPage);
}

void SetParameterPage::on_btn_setVehicleNo_clicked()
{
    emit this->changePage(uSetVehicleNo);
}

void SetParameterPage::on_btn_tractionIsolate_clicked()
{
    emit this->changePage(uTractionIsolate);
}
