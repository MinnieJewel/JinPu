#include "chargerhelppage.h"
#include "ui_chargerhelppage.h"
#include <QDebug>
#include "global.h"

ChargerHelpPage::ChargerHelpPage(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::ChargerHelpPage)
{
    ui->setupUi(this);
    _LOG << "ChargerHelpPage constructor";
}

ChargerHelpPage::~ChargerHelpPage()
{
    delete ui;
}

void ChargerHelpPage::on_btn_back_clicked()
{
    emit this->changePage(uChargerPage);
}
