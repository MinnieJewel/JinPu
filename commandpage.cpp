#include "commandpage.h"
#include "ui_commandpage.h"
#include <QDebug>
#include "global.h"

CommandPage::CommandPage(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::CommandPage)
{
    ui->setupUi(this);
    _LOG << "CommandPage constructor";
}

CommandPage::~CommandPage()
{
    delete ui;
}
