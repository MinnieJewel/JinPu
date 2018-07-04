#include "runstatehelppage4.h"
#include "ui_runstatehelppage4.h"
#include <QDebug>
#include "global.h"

RunstateHelpPage4::RunstateHelpPage4(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::RunstateHelpPage4)
{
    ui->setupUi(this);
    _LOG << "RunstateHelpPage4 constructor";
}

RunstateHelpPage4::~RunstateHelpPage4()
{
    delete ui;
}

void RunstateHelpPage4::updatePage()
{

}

void RunstateHelpPage4::on_btn_back_clicked()
{
    emit this->changePage(uRunStatePage);
}

void RunstateHelpPage4::on_btn_prePage_clicked()
{
    emit this->changePage(uRunStateHelpPage3);
}
