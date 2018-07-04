#include "otherchannelshelppage.h"
#include "ui_otherchannelshelppage.h"
#include <QDebug>
#include "global.h"

OtherChannelsHelpPage::OtherChannelsHelpPage(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::OtherChannelsHelpPage)
{
    ui->setupUi(this);
    _LOG << "OtherChannelsHelpPage constructor";
}

OtherChannelsHelpPage::~OtherChannelsHelpPage()
{
    delete ui;
}

void OtherChannelsHelpPage::on_btn_back_clicked()
{
    emit this->changePage(uOtherChannelsPage);
}
