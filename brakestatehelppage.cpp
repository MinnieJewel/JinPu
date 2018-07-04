#include "brakestatehelppage.h"
#include "ui_brakestatehelppage.h"
#include <QDebug>
#include "global.h"

BrakestateHelpPage::BrakestateHelpPage(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::BrakestateHelpPage)
{
    ui->setupUi(this);
    _LOG << "BrakestateHelpPage constructor";
}

BrakestateHelpPage::~BrakestateHelpPage()
{
    delete ui;
}

void BrakestateHelpPage::on_btn_back_clicked()
{
    emit this->changePage(uBrakeStatePage);
}
