#include "runningrecordpage.h"
#include "ui_runningrecordpage.h"
#include <QDebug>
#include "global.h"
#include <QTableWidget>

#define _LOCAL 7, 7, 1000, 560
#define _ROWS ("color: black; background-color: rgb(222, 234, 246); alternate-background-color: rgb(189, 214, 238);")
RunningRecordPage::RunningRecordPage(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::RunningRecordPage)
{
    ui->setupUi(this);
    _LOG << "RunningRecordPage constructor";
    this->recordTable = new QTableWidget(9, 4, this);
    QFont font;
    font.setFamily("SimHei");
    font.setPixelSize(20);
    this->recordTable->setFont(font);
    this->recordTable->setGeometry(_LOCAL);
    this->recordTable->setAlternatingRowColors(true);
    this->recordTable->setStyleSheet(_ROWS);
    this->recordTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    this->recordTable->horizontalHeader()->setVisible(false);
    this->recordTable->horizontalHeader()->setStretchLastSection(true);
    this->recordTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->recordTable->verticalHeader()->setVisible(false);
    this->recordTable->verticalHeader()->setStretchLastSection(true);
    this->recordTable->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->recordTable->verticalHeader()->setResizeMode(QHeaderView::Stretch);
    this->setTableHeader();
    this->setTableContent();

    this->StartTime << QString::number(this->database->VVVFECYear)+ QString("-") + QString::number(this->database->VVVFECMonth) + QString("-") + QString::number(this->database->VVVFECDay)
            << QString::number(this->database->SIVECYear) + QString("-") + QString::number(this->database->SIVECMonth) + QString("-") + QString::number(this->database->SIVECDay)
            << QString::number(this->database->reEngyYear) + QString("-") + QString::number(this->database->reEngyMonth) + QString("-") + QString::number(this->database->reEngyDay)
            << QString::number(this->database->serviceDistanceYear) + QString("-") + QString::number(this->database->serviceDistanceMonth) + QString("-") + QString::number(this->database->serviceDistanceDay)
            << QString::number(this->database->AP1ECYear) + QString("-") + QString::number(this->database->AP1ECMonth) + QString("-") + QString::number(this->database->AP1ECDay)
            << QString::number(this->database->AP2ECYear) + QString("-") + QString::number(this->database->AP2ECMonth) + QString("-") + QString::number(this->database->AP2ECDay)
            << QString::number(this->database->totalDistanceYear) + QString("-") + QString::number(this->database->totalDistanceMonth) + QString("-") + QString::number(this->database->totalDistanceDay)
            << QString::number(this->database->TCMSTotalTimeYear) + QString("-") + QString::number(this->database->TCMSTotalTimeMonth) + QString("-") + QString::number(this->database->TCMSTotalDay);

    this->recordCapacity << QString::number(this->database->VVVFEngyConsumption) << QString::number(this->database->SIVEngyConsumption) << QString::number(this->database->ReEngy) << QString::number(this->database->ServiceDistance)
            << QString::number(this->database->AP1RunningTime) << QString::number(this->database->AP2RunningTime) << QString::number(this->database->runningKilometers) << QString::number(this->database->TCMSTotalTime);

}

RunningRecordPage::~RunningRecordPage()
{
    delete ui;
}

void RunningRecordPage::updatePage()

{
    if (8 != this->StartTime.length())
    {
        _LOG << "RunningRecordPage StartTime length is 0;";
    }
    else
    {
        this->StartTime[0] = QString::number(this->database->VVVFECYear)+ QString("-") + QString::number(this->database->VVVFECMonth) + QString("-") + QString::number(this->database->VVVFECDay);
        this->StartTime[1] = QString::number(this->database->SIVECYear) + QString("-") + QString::number(this->database->SIVECMonth) + QString("-") + QString::number(this->database->SIVECDay);
        this->StartTime[2] = QString::number(this->database->reEngyYear) + QString("-") + QString::number(this->database->reEngyMonth) + QString("-") + QString::number(this->database->reEngyDay);
        this->StartTime[3] = QString::number(this->database->serviceDistanceYear) + QString("-") + QString::number(this->database->serviceDistanceMonth) + QString("-") + QString::number(this->database->serviceDistanceDay);
        this->StartTime[4] = QString::number(this->database->AP1ECYear) + QString("-") + QString::number(this->database->AP1ECMonth) + QString("-") + QString::number(this->database->AP1ECDay);
        this->StartTime[5] = QString::number(this->database->AP2ECYear) + QString("-") + QString::number(this->database->AP2ECMonth) + QString("-") + QString::number(this->database->AP2ECDay);
        this->StartTime[6] = QString::number(this->database->totalDistanceYear) + QString("-") + QString::number(this->database->totalDistanceMonth) + QString("-") + QString::number(this->database->totalDistanceDay);
        this->StartTime[7] = QString::number(this->database->TCMSTotalTimeYear) + QString("-") + QString::number(this->database->TCMSTotalTimeMonth) + QString("-") + QString::number(this->database->TCMSTotalDay);
    }

    if (8 != this->recordCapacity.length())
    {
        _LOG << "RunningRecordPage recordCapacity length is 0";
    }
    else
    {
        this->recordCapacity[0] = QString::number(this->database->VVVFEngyConsumption) + " kwh";
        this->recordCapacity[1] = QString::number(this->database->SIVEngyConsumption) + " kwh";
        this->recordCapacity[2] = QString::number(this->database->ReEngy)  + " kwh";
        this->recordCapacity[3] = QString::number(this->database->ServiceDistance) + " m";
        this->recordCapacity[4] = QString::number(this->database->AP1RunningTime) + " s";
        this->recordCapacity[5] = QString::number(this->database->AP2RunningTime) + " s";
        this->recordCapacity[6] = QString::number(this->database->runningKilometers) + " m";
        this->recordCapacity[7] = QString::number(this->database->TCMSTotalTime) + " s";
    }

    for(int row = 0; row < this->StartTime.length(); row++)
    {
        if (NULL != this->StartTime[row])
            this->recordTable->item(row + 1, 2)->setText(this->StartTime[row]);
        else
            this->recordTable->item(row + 1, 2)->setText("--");

        if (NULL != this->recordCapacity[row])
            this->recordTable->item(row + 1, 3)->setText(this->recordCapacity[row]);
        else
            this->recordTable->item(row + 1, 3)->setText("--");
    }
}

void RunningRecordPage::setTableHeader()
{
    this->title << "记录项目" << "记录状态" << "记录开始时刻" << "记录容量" ;

    //use "if" provents memory leaks
    if(this->title.length() <= this->recordTable->columnCount())
    {
        for(int column = 0; column < this->title.length(); column++)
        {
            QTableWidgetItem *itemColumn  = new QTableWidgetItem("");
            itemColumn->setText(this->title[column]);
            itemColumn->setTextColor(QColor(255, 255, 255));
            itemColumn->setTextAlignment(Qt::AlignCenter);
            itemColumn->setBackgroundColor(QColor(91, 155, 213));
            this->recordTable->setItem(0, column, itemColumn);
        }
    }    
}

void RunningRecordPage::setTableContent()
{
    for(int row = 1; row < this->recordTable->rowCount(); row++)
    {
        for (int column = 0; column < this->recordTable->columnCount(); column ++)
        {
            QTableWidgetItem *contentItem = new QTableWidgetItem("");
            contentItem->setText("");
            this->recordTable->setItem(row, column, contentItem);
        }
    }

    this->recordItem << "牵引能耗" << "辅助能耗" << "再生能耗" << "检修里程"
            << "空压机1运行时间" << "空压机2运行时间" << "总运行里程" << "总运行时间";
    this->recordState << "记录" << "记录" << "记录" << "记录"
            << "记录" << "记录" << "记录" << "记录";

    if(this->recordItem.length() <= this->recordState.length() && this->recordItem.length() <= this->recordTable->rowCount() - 1)
    {
        for(int row = 0; row < this->recordItem.length(); row++)
        {
            this->recordTable->item(row + 1, 0)->setText(this->recordItem[row]);
            this->recordTable->item(row + 1, 1)->setText(this->recordState[row]);
        }
    }
    this->recordTable->setColumnWidth(0, 200);
    this->recordTable->setColumnWidth(2, 200);
}

void RunningRecordPage::on_btn_back_clicked()
{
    emit this->changePage(uMaintainancePage);
}
