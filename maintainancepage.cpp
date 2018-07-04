#include "maintainancepage.h"
#include "ui_maintainancepage.h"
#include <QDebug>
#include "global.h"

MaintainancePage::MaintainancePage(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::MaintainancePage)
{
    ui->setupUi(this);
    ui->btn_setRecord->hide();
    _LOG << "MaintainancePage constructor";
}

MaintainancePage::~MaintainancePage()
{
    delete ui;
}

void MaintainancePage::on_btn_mainpage_clicked()
{
    emit this->changePage(uMainPage);
}


void MaintainancePage::on_btn_paraSet_clicked()
{
    emit this->changePage(uSetParameterPage);
}


void MaintainancePage::on_btn_test_clicked()
{
    emit this->changePage(uTestPage);
}

void MaintainancePage::on_btn_RunningRecordClear_clicked()
{
    emit this->changePage(uRunningRecordClearPage);
}

void MaintainancePage::on_btn_setRecord_clicked()
{
    emit this->changePage(uRunningRecordSet);
}

void MaintainancePage::on_btn_RunningRecord_clicked()
{
    emit this->changePage(uRunningRecordPage);
}

void MaintainancePage::on_btn_historyRecord_clicked()
{
    emit this->changePage(uHistoryFault);
}
