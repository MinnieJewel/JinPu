#include "batteryhelppage.h"
#include "ui_batteryhelppage.h"
#include <QDebug>
#include "global.h"

BatteryHelpPage::BatteryHelpPage(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::BatteryHelpPage)
{
    ui->setupUi(this);
    _LOG << "BatteryHelpPage constructor";
}

BatteryHelpPage::~BatteryHelpPage()
{
    delete ui;
}

void BatteryHelpPage::on_btn_back_clicked()
{
    emit this->changePage(uBatteryPage);
}
