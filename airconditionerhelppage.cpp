#include "airconditionerhelppage.h"
#include "ui_airconditionerhelppage.h"
#include <QDebug>
#include "global.h"

AirConditionerHelpPage::AirConditionerHelpPage(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::AirConditionerHelpPage)
{
    ui->setupUi(this);
    _LOG << "AirConditionerHelpPage constructor";
}

AirConditionerHelpPage::~AirConditionerHelpPage()
{
    delete ui;
}

void AirConditionerHelpPage::on_btn_back_clicked()
{
    emit this->changePage(uAirConditionerPage);
}
