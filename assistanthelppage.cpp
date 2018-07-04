#include "assistanthelppage.h"
#include "ui_assistanthelppage.h"
#include <QDebug>
#include "global.h"

AssistantHelpPage::AssistantHelpPage(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::AssistantHelpPage)
{
    _LOG << "AssistantHelpPage constructor";
    ui->setupUi(this);
}

AssistantHelpPage::~AssistantHelpPage()
{
    delete ui;
}

void AssistantHelpPage::on_btn_back_clicked()
{
    this->changePage(uAssistantPage);
}
