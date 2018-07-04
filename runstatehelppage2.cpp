#include "runstatehelppage2.h"
#include "ui_runstatehelppage2.h"
#include <QDebug>
#include "global.h"

RunstateHelpPage2::RunstateHelpPage2(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::RunstateHelpPage2)
{
    ui->setupUi(this);
    _LOG << "RunstateHelpPage2 constructor";
}

RunstateHelpPage2::~RunstateHelpPage2()
{
    delete ui;
}

void RunstateHelpPage2::on_btn_back_clicked()
{
    emit this->changePage(uRunStatePage);
}

void RunstateHelpPage2::on_btn_nextPage_clicked()
{
    emit this->changePage(uRunStateHelpPage3);
}

void RunstateHelpPage2::on_btn_prePage_clicked()
{
    emit this->changePage(uRunStateHelpPage1);
}

void RunstateHelpPage2::updatePage()
{

}
