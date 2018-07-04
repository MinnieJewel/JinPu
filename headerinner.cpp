#include "headerinner.h"
#include "ui_headerinner.h"
#include <QTimer>
#include <QDateTime>
#include "global.h"
#include <QDebug>


HeaderInner::HeaderInner(QWidget *parent) :
     MyBase(parent),
    ui(new Ui::HeaderInner)
{
    ui->setupUi(this);
     _LOG << "HeaderInner constructor";
}

HeaderInner::~HeaderInner()
{
    delete ui;
}

void HeaderInner::updatePage()
{
    ui->labelTime->setText(QDateTime::currentDateTime().toString("hh:mm:ss  ") +
                          QDateTime::currentDateTime().toString("  yyyy-MM-dd"));
}


void HeaderInner::setPageName(QString name)
{
    ui->labelName->setText(name);
}
