#include "tractionhelppage2.h"
#include "ui_tractionhelppage2.h"
#include <QDebug>
#include "global.h"

TractionHelpPage2::TractionHelpPage2(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::TractionHelpPage2)
{
    ui->setupUi(this);
    _LOG << "TractionHelpPage2 constructor";
}

TractionHelpPage2::~TractionHelpPage2()
{
    delete ui;
}

void TractionHelpPage2::on_btn_back_clicked()
{
    emit this->changePage(uTractionPage);
}

void TractionHelpPage2::on_btn_prePage_clicked()
{
    emit this->changePage(uTractionHelpPage);
}
