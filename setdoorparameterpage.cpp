#include "setdoorparameterpage.h"
#include "ui_setdoorparameterpage.h"
#include <QDebug>
#include "global.h"

SetDoorParameterPage::SetDoorParameterPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SetDoorParameterPage)
{
    ui->setupUi(this);
    _LOG << "SetDoorParameterPage constructor";
}

SetDoorParameterPage::~SetDoorParameterPage()
{
    delete ui;
}
