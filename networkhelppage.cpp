#include "networkhelppage.h"
#include "ui_networkhelppage.h"
#include <QDebug>
#include "global.h"

NetworkHelpPage::NetworkHelpPage(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::NetworkHelpPage)
{
    ui->setupUi(this);
    _LOG << "NetworkHelpPage constructor";
}

NetworkHelpPage::~NetworkHelpPage()
{
    delete ui;
}


void NetworkHelpPage::on_btn_Back_clicked()
{
     emit this->changePage(uNetWorkPage);
}
