#include "runstatehelppage1.h"
#include "ui_runstatehelppage1.h"
#include <QDebug>
#include "global.h"

RunstateHelpPage1::RunstateHelpPage1(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::RunstateHelpPage1)
{
    ui->setupUi(this);
    _LOG << "RunstateHelpPage1 constructor";
}

RunstateHelpPage1::~RunstateHelpPage1()
{
    delete ui;
}

void RunstateHelpPage1::on_btn_nextPage_clicked()
{
    emit this->changePage(uRunStateHelpPage2);
}

void RunstateHelpPage1::on_btn_back_clicked()
{
    emit this->changePage(uRunStatePage);
}

void RunstateHelpPage1::updatePage()
{

}
