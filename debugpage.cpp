#include "debugpage.h"
#include "ui_debugpage.h"
#include <QDebug>
#include "global.h"

DebugPage::DebugPage(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::DebugPage)
{
    ui->setupUi(this);
     _LOG << "DebugPage constructor";
}

DebugPage::~DebugPage()
{
    delete ui;
}

void DebugPage::on_btn_Back_clicked()
{
    emit this->changePage(uNetWorkPage);
}

void DebugPage::on_btn_RIOMDetailInfo_clicked()
{
    emit this->changePage(uAllportsPage);
}

void DebugPage::on_btn_LifeSignal_clicked()
{
    emit this->changePage(uLifeSignalsPage);
}

void DebugPage::on_btn_RIOMDebug_clicked()
{
    emit this->changePage(uRIOMDebugPage);
}

void DebugPage::on_btn_PublishSet_clicked()
{
    emit this->changePage(uPublishSetPage);
}

void DebugPage::on_btn_versionInfo_clicked()
{
    emit this->changePage(uVersionInfoPage);
}

void DebugPage::on_btn_DataMoniter_clicked()
{
    emit this->changePage(uDataMoniter);
}
