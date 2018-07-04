#include "navigator.h"
#include "ui_navigator.h"
#include <QDebug>
#include <QLabel>
#include <QPushButton>
#include "global.h"

#define _ONFIRE ("font: 20px, SimHei; color: rgb(0,0,0); background-color: red; border: 1px solid gray;")
#define _ONSAFE ("font: 20px, SimHei; color: rgb(0,0,0); background-color: green; border: 1px solid gray;")

#define BTN_UNSELECTED ("font: 20px, SimHei; color: rgb(0,0,0); background-color: white; border: 1px solid gray;")
#define BTN_SELECTED ("font: 20px, SimHei; color: white; background-color: rgb(0, 0, 250); border-radius: 5px;")

Navigator::Navigator(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::Navigator)
{
    ui->setupUi(this);
    _LOG << "Navigator constructor";
    ui->nbtn1_1->installEventFilter(this);
    ui->nbtn1_2->installEventFilter(this);
    ui->nbtn1_3->installEventFilter(this);
    ui->nbtn1_4->installEventFilter(this);
    ui->nbtn1_5->installEventFilter(this);
    ui->nbtn1_6->installEventFilter(this);
    ui->nbtn1_7->installEventFilter(this);
    ui->nbtn1_8->installEventFilter(this);
    ui->nbtn1_9->installEventFilter(this);
    ui->nbtn1_10->installEventFilter(this);
    ui->nbtn1_11->installEventFilter(this);

    this->buttons.append(ui->nbtn1_1);
    this->buttons.append(ui->nbtn1_2);
    this->buttons.append(ui->nbtn1_3);
    this->buttons.append(ui->nbtn1_4);
    this->buttons.append(ui->nbtn1_5);
    this->buttons.append(ui->nbtn1_6);
    this->buttons.append(ui->nbtn1_7);
    this->buttons.append(ui->nbtn1_8);
    this->buttons.append(ui->nbtn1_9);
    this->buttons.append(ui->nbtn1_10);
    this->buttons.append(ui->nbtn1_11);

    this->ifFirePage = false;
}

Navigator::~Navigator()
{
    delete ui;
}

bool Navigator::eventFilter(QObject *target, QEvent *event)
{
    if (event->type() != QEvent::MouseButtonPress)
        return false;

    for (int i = 0; i < this->buttons.size(); i++)
    {
        buttons.at(i)->setStyleSheet(BTN_UNSELECTED);
        if (target == buttons.at(i))
        {
            if(target == ui->nbtn1_8)
                this->ifFirePage = true;
            else
                this->ifFirePage = false;
            if (i != this->buttons.size() - 1)
                buttons.at(i)->setStyleSheet(BTN_SELECTED);
            emit this->changePage(this->pageNoList.at(i));
        }
    }
    return false;
}

void Navigator::updatePage()
{
    if(this->database->ifFire)
    {
         ui->nbtn1_8->setStyleSheet(_ONFIRE);
    }
    else if (!this->ifFirePage)
    {
         ui->nbtn1_8->setStyleSheet(BTN_UNSELECTED);
    }
    else
    {
         ui->nbtn1_8->setStyleSheet(BTN_SELECTED);
    }
}

void Navigator::allButtonsDisplay()
{
    for(int i = 0; i < buttons.size(); i++)
    {
        buttons.at(i)->show();
    }
}

void Navigator::setButtonsDisplay(QList<QString> buttonsName, QList<int> pageNo)
{

    if(buttonsName.isEmpty() || pageNo.isEmpty())
    {
         _LOG << "buttonsName or pageNo is null";
         return;
    }
    else
        if((buttonsName.size() > 11) || (pageNo.size() > 11))
        {
             _LOG << "buttonsName or pageNo is out of edge";
             return;
        }
    else if(!(buttonsName.size()== pageNo.size()))
    {
             _LOG << "buttonsName and pageNo are not match";
             return;
    }

    for(int buttonCount = 0; buttonCount < buttonsName.size(); buttonCount++)
    {
        buttons.at(buttonCount)->setText(buttonsName.at(buttonCount));
    }
//    if(3 == pageNo.size())
//    {
//        _LOG << "pageNo size is 3";
//    }
    this->pageNoList = pageNo;

    this->allButtonsDisplay();
    for(int hideCount = 0; hideCount < (buttons.size() - buttonsName.size()); hideCount++)
    {
        buttons.at(buttonsName.size() + hideCount)->hide();
    }
}
