#include "mybase.h"
#include "global.h"
#include <QDebug>

MyBase::MyBase(QWidget *parent) :
        QWidget(parent)
{
    _LOG << "MyBase constructor";
    if (parent != NULL)
        connect(this, SIGNAL(changePage(int)), parent, SLOT(changePage(int)));
    this->ifFullScreen = false;
    this->ifInnerHeader = false;
    this->ifNoneNavigator = false;
}


int MyBase::currentPage = uNetWorkPage;
Database *MyBase::database = NULL;

void MyBase::setMyBase(pagePosition position, QString name)
{
    switch(position)
    {
    case 1:
        this->setGeometry(0, 80, this->width(), this->height());
        break;

    case 2:
        this->setGeometry(0, 698, this->width(), this->height());
        break;

    case 5:
        this->setGeometry(0, 60, this->width(), this->height());
        break;

    case 0:case 3:case 4:
        this->setGeometry(0, 0, this->width(), this->height());
        break;


    default:
        _LOG << "invalid position of " << position;
        break;
    }

    this->name = name;
    this->hide();
}

// for pages need navigator
void MyBase::setMyBase(QString name, QList<QString> navigatorList, QList<int> navigatorPageNo)
{

    this->setGeometry(0, 80, this->width(), this->height());
    this->navigatorList = navigatorList;
    this->navigatorPageNo = navigatorPageNo;
    this->name = name;
    this->hide();
}

void MyBase::updatePage()
{
}

void MyBase::setFullScreen()
{
    this->ifFullScreen = true;
}

bool MyBase::getFullScreen()
{
    return this->ifFullScreen;
}

bool MyBase::getInnerHeader()
{
    return this->ifInnerHeader;
}

void MyBase::setInnerHeader()
{
    this->ifInnerHeader = true;
}

void MyBase::setNoneNavigator()
{
    this->ifNoneNavigator = true;
}

bool MyBase::getNoneNavigator()
{
    return this->ifNoneNavigator;
}

