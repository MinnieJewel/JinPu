#include "testpage.h"
#include "ui_testpage.h"
#include <QDebug>
#include "global.h"

TestPage::TestPage(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::TestPage)
{
    ui->setupUi(this);
    _LOG << "TestPage constructor";
}

TestPage::~TestPage()
{
    delete ui;
}

void TestPage::on_btn_tractionTest_clicked()
{
    emit this->changePage(uTractionTestPage);
}

void TestPage::on_btn_breakTest_clicked()
{
    emit this->changePage(uBrakeSelfCheckPage);
}

void TestPage::on_btn_back_clicked()
{
    emit this->changePage(uMaintainancePage);
}

void TestPage::on_btn_driverTest_clicked()
{
    emit this->changePage(uDriverTestPage);
}

void TestPage::on_btn_speedTest_clicked()
{
    emit this->changePage(uSpeedTestPage);
}
