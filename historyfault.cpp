#include "historyfault.h"
#include "ui_historyfault.h"
#include <QTableWidget>
#include <QDebug>
#include "global.h"
#include <QTimer>
#include <QDateTime>
#include <QDesktopWidget>
#include "crrcfault.h"

#define _LOCAL 5, 25, 1000, 620
#define _TABLESIZE 13
#define _ROWS ("color: black; background-color: rgb(222, 234, 246); alternate-background-color: rgb(189, 214, 238);")
#define _HISTORY_FAULT_MAX_ITEM 12
#define _COLUMNNUM 6
HistoryFault::HistoryFault(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::HistoryFault)
{
    ui->setupUi(this);
    this->historyFaultListTable = new QTableWidget(_TABLESIZE, _COLUMNNUM, this);
    QFont font;
    font.setFamily("SimHei");
    font.setPixelSize(20);
    this->historyFaultListTable->setFont(font);
    this->historyFaultListTable->horizontalHeader()->setVisible(false);
    this->historyFaultListTable->verticalHeader()->setVisible(false);
    this->historyFaultListTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    this->historyFaultListTable->setGeometry(_LOCAL);
    this->historyFaultListTable->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->historyFaultListTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->historyFaultListTable->verticalHeader()->setStretchLastSection(true);
    this->historyFaultListTable->horizontalHeader()->setStretchLastSection(true);
    this->historyFaultListTable->verticalHeader()->setResizeMode(QHeaderView::Stretch);

    this->historyFaultListTable->setAlternatingRowColors(true);
    this->historyFaultListTable->setStyleSheet(_ROWS);
    this->title << "序 号" << "故障等级" << "故障代码" << "故障名称" << "开始时间" << "结束时间";
    this->setTableHeader();
    this->setTableItems();
    this->page = 1;
}

HistoryFault::~HistoryFault()
{
    delete ui;
}

/*
 function：set the display of title
*/
void HistoryFault::setTableHeader()
{
    for(int column = 0; column < this->historyFaultListTable->columnCount(); column++)
    {
        QTableWidgetItem *headerItem = new QTableWidgetItem("");
        headerItem->setText(this->title[column]);
        headerItem->setTextColor(QColor(255, 255, 255));
        headerItem->setTextAlignment(Qt::AlignCenter);
        headerItem->setBackgroundColor(QColor(91, 155, 213));
        historyFaultListTable->setItem(0, column, headerItem);
    }
      historyFaultListTable->setColumnWidth(0, 60);
      historyFaultListTable->setColumnWidth(3, 340);
      historyFaultListTable->setColumnWidth(4, 140);
      historyFaultListTable->setColumnWidth(5, 140);
      //historyFaultListTable->setColumnWidth(2, 120);
}

//initial table items
void HistoryFault::setTableItems()
{
    QFont font1;
    font1.setFamily("SimHei");
    font1.setPixelSize(17);
    for (int row = 1; row <= _HISTORY_FAULT_MAX_ITEM; row ++)
    {          
        for (int column = 0; column < _COLUMNNUM ; column ++)
        {
            QTableWidgetItem *contentItem = new QTableWidgetItem("");
            contentItem->setFont(font1);
            contentItem->setTextAlignment(Qt::AlignCenter);
            contentItem->setText("");
            this->historyFaultListTable->setItem(row, column, contentItem);
        }
    }
}

void HistoryFault::updatePage()
{
    if (this->crrcFault->getHistoryFaultListSize() == 0)
    {
        ui->label_page->setText(QString::number(this->page) + QString(" / ") + QString::number(1));
    }
    else
    if (this->crrcFault->getHistoryFaultListSize() % _HISTORY_FAULT_MAX_ITEM == 0)
    {
        ui->label_page->setText(QString::number(this->page) + QString("/") + QString::number(this->crrcFault->getHistoryFaultListSize() / _HISTORY_FAULT_MAX_ITEM));
    }
    else
    {
        ui->label_page->setText(QString::number(this->page) + QString("/") + QString::number(this->crrcFault->getHistoryFaultListSize() / _HISTORY_FAULT_MAX_ITEM + 1));
    }

   // this->historyFaultListTable->clear();
  //  this->setTableHeader();
    QFont font, font1;
    font.setFamily("SimHei");
    font.setPixelSize(17);

    font1.setFamily("SimHei");
    font1.setPixelSize(17);
    font1.setItalic(true);
    for (int i = 0; i < this->crrcFault->getHistoryFaultListSize(); i++)
    {
        QList<QString> content;
        if (this->page * _HISTORY_FAULT_MAX_ITEM > i && (this->page - 1) * _HISTORY_FAULT_MAX_ITEM <= i)
        {

            if (this->crrcFault->getHistoryFaultPosition(i).size() != 0)
            {
                content << QString::number(i + 1)
                        << QString::number(this->crrcFault->getHistoryFaultLevel(i))
                        << this->crrcFault->getHistoryFaultCode(i)
                        << this->crrcFault->getHistoryFaultPosition(i) + QString(" ") + this->crrcFault->getHistoryFaultDevice(i) + QString(" ") + this->crrcFault->getHistoryFaultName(i)
                        << (this->crrcFault->getHistoryFaultStartDate(i) + QString("\n") + this->crrcFault->getHistoryFaultStartTime(i))
                        << (this->crrcFault->getHistoryFaultEndDate(i) + QString("\n") + this->crrcFault->getHistoryFaultEndTime(i));
            }
            else
            {
                content << QString::number(i + 1)
                        << QString::number(this->crrcFault->getHistoryFaultLevel(i))
                        << this->crrcFault->getHistoryFaultCode(i)
                        << (this->crrcFault->getHistoryFaultPosition(i) + QString(" ") + this->crrcFault->getHistoryFaultDevice(i) + QString(" ") + this->crrcFault->getHistoryFaultName(i))
                        << (this->crrcFault->getHistoryFaultStartDate(i) + QString("\n") + this->crrcFault->getHistoryFaultStartTime(i))
                        << (this->crrcFault->getHistoryFaultEndDate(i) + QString("\n") + this->crrcFault->getHistoryFaultEndTime(i));
            }
            // show faultList info in the table
            for (int column = 0; column < _COLUMNNUM ; column ++)
            {
                this->historyFaultListTable->item(i % _HISTORY_FAULT_MAX_ITEM + 1, column)->setText(content.at(column));
                //this->historyFaultListTable->item(1,1)->setText("123");
            }
        }
    }

    int tableContentSize = this->page * _HISTORY_FAULT_MAX_ITEM;
    if (tableContentSize > this->crrcFault->getHistoryFaultListSize())
    {
        for(int lastPageSize = this->crrcFault->getHistoryFaultListSize(); lastPageSize < tableContentSize; lastPageSize ++)
        {
            for (int columnLast = 0; columnLast < _COLUMNNUM ; columnLast ++)
            {
                this->historyFaultListTable->item(lastPageSize % _HISTORY_FAULT_MAX_ITEM + 1, columnLast)->setText("");
            }
        }
    }
}



void HistoryFault::installCrrcFault(CrrcFault *crrcFault)
{
    this->crrcFault = crrcFault;
}

void HistoryFault::on_btn_firstPage_clicked()
{
    this->page = 1;
    //this->historyFaultListTable->clear();
    this->setTableHeader();
}

void HistoryFault::on_btn_lastPage_clicked()
{
    this->page = this->crrcFault->getHistoryFaultListSize() / _HISTORY_FAULT_MAX_ITEM + 1;
    //this->historyFaultListTable->clear();
    this->setTableHeader();
}

void HistoryFault::on_btn_pre_clicked()
{
    if (this->page > 1)
        this->page --;
    this->setTableHeader();
}

void HistoryFault::on_btn_next_clicked()
{
    if (this->crrcFault->getHistoryFaultListSize() / _HISTORY_FAULT_MAX_ITEM > this->page)
    {
        this->page ++;
    }
    else if (this->crrcFault->getHistoryFaultListSize() / _HISTORY_FAULT_MAX_ITEM == this->page
             && this->crrcFault->getHistoryFaultListSize() % _HISTORY_FAULT_MAX_ITEM != 0)
    {
        this->page ++;
    }
    this->setTableHeader();
}

void HistoryFault::on_btn_back_clicked()
{
    emit this->changePage(uMaintainancePage);
}
