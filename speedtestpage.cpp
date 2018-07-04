#include "speedtestpage.h"
#include "ui_speedtestpage.h"
#include <QTableWidget>
#include <QDebug>
#include "global.h"
#include <QTimer>
#include <QDateTime>

#define _LOCAL 5, 5, 1000, 560
#define _TABLESIZE 10
#define _ROWS ("color: black; background-color: rgb(222, 234, 246); alternate-background-color: rgb(189, 214, 238);")

SpeedTestPage::SpeedTestPage(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::SpeedTestPage)
{
    ui->setupUi(this);
    this->speedTable = new QTableWidget(11, 8, this);
    QFont font;
    font.setFamily("SimHei");
    font.setPixelSize(20);
    this->speedTable->setFont(font);
    this->speedTable->horizontalHeader()->setVisible(false);
    this->speedTable->verticalHeader()->setVisible(false);
    this->speedTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    this->speedTable->setGeometry(_LOCAL);
    this->speedTable->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    this->speedTable->verticalHeader()->setStretchLastSection(true);
    this->speedTable->verticalHeader()->setResizeMode(QHeaderView::Stretch);
    this->title << "序 号" << "时 间" << "再 生" << "距 离(m)" << "种 类" << "级 位" << "初 速(km/h)" << "加减速度";
    this->setTableHeader();
    this->setTableContent();
    this->speedTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->speedTable->horizontalHeader()->setStretchLastSection(true);
    this->speedTable->setAlternatingRowColors(true);
    this->speedTable->setStyleSheet(_ROWS);
    this->validState = this->database->hmiTestDataValid;
}

SpeedTestPage::~SpeedTestPage()
{
    delete ui;
}

void SpeedTestPage::on_btn_back_clicked()
{
    emit this->changePage(uTestPage);
}

/*
 function：set the display of title
*/
void SpeedTestPage::setTableHeader()
{
    for(int column = 0; column < this->speedTable->columnCount(); column++)
    {
        QTableWidgetItem *tableItem = new QTableWidgetItem("");
        tableItem->setText(this->title[column]);
        tableItem->setTextColor(QColor(255, 255, 255));
        tableItem->setTextAlignment(Qt::AlignCenter);
        tableItem->setBackgroundColor(QColor(91, 155, 213));
        speedTable->setItem(0, column, tableItem);
    }
    speedTable->setColumnWidth(0, 70);
    speedTable->setColumnWidth(1, 220);
    speedTable->setColumnWidth(6, 150);
}

/*
 function : initial table items
*/
void SpeedTestPage::setTableContent()
{
    for (int row = 1; row < this->speedTable->rowCount(); row ++)
    {
        for (int column = 0; column < this->speedTable->columnCount(); column ++)
        {
            QTableWidgetItem *itemContext = new QTableWidgetItem("");
            itemContext->setText("");
            this->speedTable->setItem(row, column, itemContext);
        }
    }
}

/*
 function：judge rising edge
 return:
    ture: detect the rising edge
    false: does not detect the rising edge
*/
bool SpeedTestPage::judgeTest()
{
    if (this->database->hmiTestDataValid)
    {
        if (!this->validState)
        {
            this->validState = this->database->hmiTestDataValid;
            return true;
        }
    }
    this->validState = this->database->hmiTestDataValid;
    return false;
}

void SpeedTestPage::updatePage()
{

    if(!this->database->CTHM_ERM1On && !this->database->CTHM_ERM2On)
    {
        _LOG << "Neither ERM is online !";
        return;
    }

    else if(this->judgeTest())
    {
        // declare 'data' to store signal test data
        QList<QString> data;
        data << QString(QDateTime::currentDateTime().toString("hh:mm:ss") +" "+ QDateTime::currentDateTime().toString("yyyy-MM-dd"))
                << this->database->hmiRegeneration << QString::number(this->database->hmiBrakeDistance) << this->database->hmiRunClass
                << QString::number(this->database->hmiLevel) << QString::number(this->database->hmiBrakeStartSpeed) << QString::number(this->database->hmiAccerate);

        this->dataList.insert(0, data);
        if(this->dataList.size() == _TABLESIZE)
            this->dataList.removeLast();
        for (int row = 1; row < dataList.size() + 1; row ++)
        {
            for (int column = 0; column < this->speedTable->columnCount(); column ++)
            {
                //QTableWidgetItem *itemContext = new QTableWidgetItem("");
                if (column == 0)
                {
                    this->speedTable->item(row, column)->setText(QString::number(row));
                    //itemContext->setText(QString::number(row));
                }
                else
                {
                    this->speedTable->item(row, column)->setText(this->dataList[row - 1][column - 1]);
                }
                //this->speedTable->setItem(row, column, itemContext);
            }
        }
    }
}

void SpeedTestPage::on_btn_start_clicked()
{
    this->database->hmiAcTeststart = true;
    this->database->hmiAcTestStop = false;
    ui->btn_start->setStyleSheet(BUTTON_DOWN);
    ui->btn_cease->setStyleSheet(BUTTON_UP);
}

void SpeedTestPage::on_btn_cease_clicked()
{
    this->database->hmiAcTeststart = false;
    this->database->hmiAcTestStop = true;
    ui->btn_start->setStyleSheet(BUTTON_UP);
    ui->btn_cease->setStyleSheet(BUTTON_DOWN);
}
