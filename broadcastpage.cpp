#include "broadcastpage.h"
#include "ui_broadcastpage.h"
#include <QDebug>
#include "global.h"

BroadCastPage::BroadCastPage(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::BroadCastPage)
{
    ui->setupUi(this);
    _LOG << "BroadCastPage constructor";
}

BroadCastPage::~BroadCastPage()
{
    delete ui;
}
