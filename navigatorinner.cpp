#include "navigatorinner.h"
#include "ui_navigatorinner.h"
#include <QDebug>
#include "global.h"

NavigatorInner::NavigatorInner(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NavigatorInner)
{
    ui->setupUi(this);
    _LOG << "NavigatorInner constructor";
}

NavigatorInner::~NavigatorInner()
{
    delete ui;
}
