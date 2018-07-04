#include "tractionhelppage.h"
#include "ui_tractionhelppage.h"
#include <QDebug>
#include "global.h"

TractionHelpPage::TractionHelpPage(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::TractionHelpPage)
{
    ui->setupUi(this);
    _LOG << "TractionHelpPage constructor";
}

TractionHelpPage::~TractionHelpPage()
{
    delete ui;
}

void TractionHelpPage::on_btn_back_clicked()
{
    emit this->changePage(uTractionPage);
}

void TractionHelpPage::on_btn_nextPage_clicked()
{
    emit this->changePage(uTractionHelpPage2);
}
