#include "brakestatehelppage2.h"
#include "ui_brakestatehelppage2.h"
#include <QDebug>
#include "global.h"

BrakestateHelpPage2::BrakestateHelpPage2(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::BrakestateHelpPage2)
{
    ui->setupUi(this);
    _LOG << "BrakestateHelpPage2 constructor";
}

BrakestateHelpPage2::~BrakestateHelpPage2()
{
    delete ui;
}
