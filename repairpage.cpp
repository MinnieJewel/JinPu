#include "repairpage.h"
#include "ui_repairpage.h"
#include <QDebug>
#include "global.h"

RepairPage::RepairPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RepairPage)
{
    ui->setupUi(this);
    _LOG << "RepairPage constructor";
}

RepairPage::~RepairPage()
{
    delete ui;
}
