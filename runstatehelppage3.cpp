#include "runstatehelppage3.h"
#include "ui_runstatehelppage3.h"
#include <QDebug>
#include "global.h"

RunstateHelpPage3::RunstateHelpPage3(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::RunstateHelpPage3)
{
    ui->setupUi(this);
    _LOG << "RunstateHelpPage3 constructor";
}

RunstateHelpPage3::~RunstateHelpPage3()
{
    delete ui;
}

void RunstateHelpPage3::on_btn_back_clicked()
{
    emit this->changePage(uRunStatePage);
}

void RunstateHelpPage3::on_btn_prePage_clicked()
{
    emit this->changePage(uRunStateHelpPage2);
}

void RunstateHelpPage3::on_btn_nextPage_clicked()
{
    emit this->changePage(uRunStateHelpPage4);
}

void RunstateHelpPage3::updatePage()
{

}
