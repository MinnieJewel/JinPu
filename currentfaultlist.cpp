#include "currentfaultlist.h"
#include "ui_currentfaultlist.h"
#include "crrcfault.h"
#include <QTableWidget>
#include <QDebug>
#include "global.h"
#include <QTimer>
#include <QDateTime>
#include <QDesktopWidget>

#define _LOCAL 10, 25, 1000, 620
#define _TABLESIZE 13
#define _ROWS ("color: black; background-color: rgb(222, 234, 246); alternate-background-color: rgb(189, 214, 238);")
#define _CURRENT_FAULT_MAX_ITEM 12
#define _COLUMNNUM 5

CurrentFaultList::CurrentFaultList(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::CurrentFaultList)
{
    ui->setupUi(this);
    this->currentFaultListTable = new QTableWidget(_TABLESIZE, _COLUMNNUM, this);
    QFont font;
    font.setFamily("SimHei");
    font.setPixelSize(20);
    this->currentFaultListTable->setFont(font);
    this->currentFaultListTable->horizontalHeader()->setVisible(false);
    this->currentFaultListTable->verticalHeader()->setVisible(false);
    this->currentFaultListTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    this->currentFaultListTable->setGeometry(_LOCAL);
    this->currentFaultListTable->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->currentFaultListTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->currentFaultListTable->verticalHeader()->setStretchLastSection(true);
    this->currentFaultListTable->horizontalHeader()->setStretchLastSection(true);
    this->currentFaultListTable->verticalHeader()->setResizeMode(QHeaderView::Stretch);

    this->currentFaultListTable->setAlternatingRowColors(true);
    this->currentFaultListTable->setStyleSheet(_ROWS);
    this->title << "序 号" << "故障等级" << "故障代码" << "故障名称" << "开始时间";
    this->page = 1;
    this->setTableHeader();
    this->setTableItems();
}

CurrentFaultList::~CurrentFaultList()
{
    delete ui;
}

/*
 function：set the display of title
*/
void CurrentFaultList::setTableHeader()
{
    for(int column = 0; column < this->currentFaultListTable->columnCount(); column++)
    {
        QTableWidgetItem *headerItem = new QTableWidgetItem("");
        headerItem->setText(this->title[column]);
        headerItem->setTextColor(QColor(255, 255, 255));
        headerItem->setTextAlignment(Qt::AlignCenter);
        headerItem->setBackgroundColor(QColor(91, 155, 213));
        currentFaultListTable->setItem(0, column, headerItem);
    }
      currentFaultListTable->setColumnWidth(0, 60);
      currentFaultListTable->setColumnWidth(3, 440);
      currentFaultListTable->setColumnWidth(4, 140);
}

//initial table items
void CurrentFaultList::setTableItems()
{
    QFont font1;
    font1.setFamily("SimHei");
    font1.setPixelSize(17);
    for (int row = 1; row <= _CURRENT_FAULT_MAX_ITEM; row ++)
    {
          for (int column = 0; column < _COLUMNNUM ; column ++)
        {
            QTableWidgetItem *contentItem = new QTableWidgetItem("");
            contentItem->setFont(font1);
            contentItem->setTextAlignment(Qt::AlignCenter);
            contentItem->setText("");
            this->currentFaultListTable->setItem(row, column, contentItem);
        }
    }
}

void CurrentFaultList::updatePage()
{
   // _LOG << "AirConditionerPage update";
    if (this->crrcFault->getCurrentFaultListSize() == 0)
    {
        ui->label_page->setText(QString::number(this->page) + QString(" / ") + QString::number(1));
    }
    else
    if (this->crrcFault->getCurrentFaultListSize() % _CURRENT_FAULT_MAX_ITEM == 0)
    {
        ui->label_page->setText(QString::number(this->page) + QString("/") + QString::number(this->crrcFault->getCurrentFaultListSize() / _CURRENT_FAULT_MAX_ITEM));
    }
    else
    {
        ui->label_page->setText(QString::number(this->page) + QString("/") + QString::number(this->crrcFault->getCurrentFaultListSize() / _CURRENT_FAULT_MAX_ITEM + 1));
    }

    for (int i = 0; i < this->crrcFault->getCurrentFaultListSize(); i++)
    {
        QList<QString> content;
        if (this->page * _CURRENT_FAULT_MAX_ITEM > i && (this->page - 1) * _CURRENT_FAULT_MAX_ITEM <= i)
        {
            if (this->crrcFault->getCurrentFaultPosition(i).size() != 0)
            {
                content << QString::number(i + 1)
                        << QString::number(this->crrcFault->getCurrentFaultLevel(i))
                        << this->crrcFault->getCurrentFaultCode(i)
                        << this->crrcFault->getCurrentFaultPosition(i) + QString(" ") + this->crrcFault->getCurrentFaultDevice(i) + QString(" ") + this->crrcFault->getCurrentFaultName(i)
                        << (this->crrcFault->getCurrentFaultDate(i) + QString("\n") + this->crrcFault->getCurrentFaultTime(i));
            }
            else
            {
                content << QString::number(i + 1)
                        << QString::number(this->crrcFault->getCurrentFaultLevel(i))
                        << this->crrcFault->getCurrentFaultCode(i)
                        << this->crrcFault->getCurrentFaultPosition(i) + QString(" ") + this->crrcFault->getCurrentFaultDevice(i) + QString(" ") + this->crrcFault->getCurrentFaultName(i)
                        << (this->crrcFault->getCurrentFaultDate(i) + QString("\n") + this->crrcFault->getCurrentFaultTime(i));
            }

            // show faultList info in the table
            for (int column = 0; column < _COLUMNNUM ; column ++)
            {
                this->currentFaultListTable->item(i % _CURRENT_FAULT_MAX_ITEM + 1, column)->setText(content.at(column));
            }
        }
    }
    int tableContentSize = this->page * _CURRENT_FAULT_MAX_ITEM;
    if (tableContentSize > this->crrcFault->getCurrentFaultListSize())
    {
        for(int lastPageSize = this->crrcFault->getCurrentFaultListSize(); lastPageSize < tableContentSize; lastPageSize ++)
        {
            for (int columnLast = 0; columnLast < _COLUMNNUM ; columnLast ++)
            {
                this->currentFaultListTable->item(lastPageSize % _CURRENT_FAULT_MAX_ITEM + 1, columnLast)->setText("");
            }
        }
    }

    //qDebug() << "end" << QDateTime::currentDateTime().toString("mm:ss:z");
}

void CurrentFaultList::installCrrcFault(CrrcFault *crrcFault)
{
    this->crrcFault = crrcFault;
}

void CurrentFaultList::on_btn_firstPage_clicked()
{
    this->page = 1;
    //this->currentFaultListTable->clear();
    this->setTableHeader();
}

void CurrentFaultList::on_btn_lastPage_clicked()
{
    this->page = this->crrcFault->getCurrentFaultListSize() / _CURRENT_FAULT_MAX_ITEM + 1;
    //this->currentFaultListTable->clear();
    this->setTableHeader();
}

void CurrentFaultList::on_btn_pre_clicked()
{
    if (this->page > 1)
        this->page --;
    //this->currentFaultListTable->clear();
    this->setTableHeader();
}

void CurrentFaultList::on_btn_next_clicked()
{   
    if (this->crrcFault->getCurrentFaultListSize() / _CURRENT_FAULT_MAX_ITEM > this->page)
    {
        this->page ++;
    }
    else if (this->crrcFault->getCurrentFaultListSize() / _CURRENT_FAULT_MAX_ITEM == this->page
             && this->crrcFault->getCurrentFaultListSize() % _CURRENT_FAULT_MAX_ITEM != 0)
    {
        this->page ++;
    }
    //this->currentFaultListTable->clear();
    this->setTableHeader();
}

void CurrentFaultList::on_btn_back_clicked()
{
    emit this->changePage(uMainPage);
}
