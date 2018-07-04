#include "datamoniter.h"
#include "ui_datamoniter.h"
#include <QButtonGroup>
#include <QTableWidget>
#include <QDebug>
#include "global.h"

#define _ROWS ("color: black; background-color: rgb(222, 234, 246); alternate-background-color: rgb(189, 214, 238);")
#define BTN_UNSELECTED ("font: 20px, SimHei; color: black; background-color: rgb(250, 250, 250); border-radius: 5px;")
#define BTN_SELECTED ("font: 20px, SimHei; color: white; background-color: rgb(68, 114, 196); border-radius: 5px;")
#define ROWS 32
#define COLUMN 18
#define TABLEWIDTH 880
#define TABLEHEIGHT 710

enum btnNo
{
    hmi = 0,
    ccu1,
    ccu2,
    riom,
    erm,
    bcu,
    dcu,
    siv,
    edcu1,
    edcu2,
    pis,
    hvac,
    atc,
    pds,
    bcg,
    bms,
    fau
};


DataMoniter::DataMoniter(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::DataMoniter)
{
    ui->setupUi(this);
     _LOG << "DataMoniter constructor";
    this->buttonGroup = new QButtonGroup(this);
    this->buttonGroup->addButton(ui->btn_hmi, hmi);
    this->buttonGroup->addButton(ui->btn_ccu1, ccu1);
    this->buttonGroup->addButton(ui->btn_ccu2, ccu2);
    this->buttonGroup->addButton(ui->btn_riom, riom);
    this->buttonGroup->addButton(ui->btn_erm, erm);
    this->buttonGroup->addButton(ui->btn_bcu, bcu);
    this->buttonGroup->addButton(ui->btn_dcu, dcu);
    this->buttonGroup->addButton(ui->btn_siv, siv);
    this->buttonGroup->addButton(ui->btn_edcu1, edcu1);
    this->buttonGroup->addButton(ui->btn_edcu2, edcu2);
    this->buttonGroup->addButton(ui->btn_pis, pis);
    this->buttonGroup->addButton(ui->btn_hvac, hvac);
    this->buttonGroup->addButton(ui->btn_atc, atc);
    this->buttonGroup->addButton(ui->btn_pds, pds);
    this->buttonGroup->addButton(ui->btn_bcg, bcg);
    this->buttonGroup->addButton(ui->btn_bms, bms);
    this->buttonGroup->addButton(ui->btn_fau, fau);

    this->buttonGroup->setExclusive(true);
    //default show hmi data
    this->selectPort = hmi;
    //this->onBtnClicked(hmi);
    connect(this->buttonGroup, SIGNAL(buttonClicked(int)), this, SLOT(onBtnClicked(int)));

    //set table
    this->portDataTable = new QTableWidget(ROWS, COLUMN, this);
    this->portDataTable->setGeometry(15, 25, TABLEWIDTH, TABLEHEIGHT);
    this->portDataTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //set last column to fill the table
    this->portDataTable->horizontalHeader()->setStretchLastSection(true);
    //set every column's width is equal
    this->portDataTable->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
    this->portDataTable->verticalHeader()->setStretchLastSection(true);
    this->portDataTable->verticalHeader()->setResizeMode(QHeaderView::Stretch);
    this->portDataTable->horizontalHeader()->hide();
    this->portDataTable->verticalHeader()->hide();
    this->portDataTable->setAlternatingRowColors(true);
    this->portDataTable->setStyleSheet(_ROWS);
    QFont font;
    font.setFamily("SimHei");
    font.setPixelSize(15);
    this->portDataTable->setFont(font);
    this->setTableTitle();
    this->setTableContent();
    this->portDataTable->show();
}

DataMoniter::~DataMoniter()
{
    delete ui;
}

void DataMoniter::setTableTitle()
{
    if (NULL == this->portDataTable)
    {
        _LOG << "portDataTable is null in setTableTitle";
        return;
    }

    //set table's header
    for(int i = 0; i < COLUMN; i++)
    {
        QString text;
        if(i == 0)
            text = "port";
        else if (i == 17)
            text = "cycle";
        else
            text.sprintf("%02d %02d",(i - 1) * 2, (i - 1) * 2 + 1);
        QTableWidgetItem *tableItem = new QTableWidgetItem("");
        tableItem->setText(text);
        tableItem->setBackgroundColor(QColor(91, 155, 213));
        tableItem->setTextColor("white");
        this->portDataTable->setItem(0, i, tableItem);
    }
}

void DataMoniter::setTableContent()
{
    if (NULL == this->portDataTable)
    {
        _LOG << "portDataTable is null in initialTable;";
    }

    else
    {
        for (int row = 1; row < this->portDataTable->rowCount(); row ++)
        {
            for (int column = 0; column < this->portDataTable->columnCount(); column ++)
            {
                QTableWidgetItem *tableItem = new QTableWidgetItem("");
                tableItem->setText("");
                this->portDataTable->setItem(row, column, tableItem);
            }
        }
    }
}

void DataMoniter::cleanContent()
{
    if (NULL == this->portDataTable)
    {
        _LOG << "portDataTable is null in cleanContent.";
        return;
    }

    for (int row = 1; row < this->portDataTable->rowCount(); row ++)
    {
        for (int column = 0; column < this->portDataTable->columnCount(); column ++)
        {
            this->portDataTable->item(row, column)->setText("");
            //this->portDataTable->item(row, column)->setTextColor();
        }
    }
    //this->portDataTable->setStyleSheet(_ROWS);
}


void DataMoniter::onBtnClicked(int id)
{
    for(int i = 0; i < this->buttonGroup->buttons().size(); i++)
    {
        buttonGroup->button(i)->setStyleSheet(BTN_UNSELECTED);
    }
    buttonGroup->button(id)->setStyleSheet(BTN_SELECTED);
    this->selectPort = id;
    this->cleanContent();
}

void DataMoniter::updatePage()
{
    this->showPortData(this->selectPort);
    QMapIterator<unsigned short int, struct port_data> iterator(this->devicePorts);
    bool flag = false;
    QString text;

    for (int i = 1; i < this->portDataTable->rowCount(); i++)
    {
        if(iterator.hasNext())
        {
            iterator.next();
            flag = true;
        }
        else
        {
            flag = false;
        }

        for (int j = 0; j < this->portDataTable->columnCount(); j++)
        {
            //QTableWidgetItem *tableItem = new QTableWidgetItem("");
            //the first column display the port No.
            if(0 == j)
            {

                if(flag)
                    text.sprintf("%03x", iterator.key());
                else
                    text = QString("");
                this->portDataTable->item(i, j)->setText(text);
                //tableItem->setText(text);
            }

            //the last column display the port refresh time
            else if(this->portDataTable->columnCount() - 1 == j)
            {            
                if(flag)
                {
                    //the mvb port is dead
                    if (65535 - iterator.value().time > this->database->getMvbCycleByPort(iterator.key()))
                    {
                        this->portDataTable->item(i, j)->setBackgroundColor(Qt::red);
                        this->portDataTable->item(i, j)->setTextColor(Qt::white);
                    }
                    else
                    {
                        if (i > 0 && (i % 2 == 0))
                            this->portDataTable->item(i, j)->setBackgroundColor(QColor(222, 234, 246));//
                        else if (i > 0 && (i % 2 == 1))
                            this->portDataTable->item(i, j)->setBackgroundColor(QColor(189, 214, 238));//

                        this->portDataTable->item(i, j)->setTextColor(Qt::black);
                    }
                    text = QString::number(65535 - iterator.value().time);
                }
                else
                {
                    text = QString("");

                    if (i > 0 && (i % 2 == 0))
                        this->portDataTable->item(i, j)->setBackgroundColor(QColor(222, 234, 246));//
                    else if (i > 0 && (i % 2 == 1))
                        this->portDataTable->item(i, j)->setBackgroundColor(QColor(189, 214, 238));//
                }
                //tableItem->setText(text);
                this->portDataTable->item(i ,j)->setText(text);              
            }
            else // mvb data
            {                
                if (flag)
                {
                    text.sprintf("%02X %02X", iterator.value().data[j - 1] / 256, iterator.value().data[j - 1] % 256);
                }
                else
                {
                    text = QString("");
                }
                //tableItem->setText(text);
                this->portDataTable->item(i, j)->setText(text);                
            }
            //this->portDataTable->setItem(i, j, tableItem);
        }
    }
}
void DataMoniter::showPortData(int deviceNo)
{
    QList<struct port *> bcuPorts;
    bcuPorts = this->database->bcu1Ports;
    bcuPorts.append(this->database->bcu3Ports);
    bcuPorts.append(this->database->bcu4Ports);
    bcuPorts.append(this->database->bcu6Ports);
    //edcuPorts = this->database->edcu1Ports;
    //edcuPorts.append(this->database->edcu2Ports);
    switch(deviceNo)
    {
    case hmi:
        if (1 == this->database->hmiPosition)
        {
            this->getDataByPorts(this->database->hmiA1Ports);
        }
        else if(2 == this->database->hmiPosition)
        {
            this->getDataByPorts(this->database->hmiA2Ports);
        }
        break;

    case ccu1:
        this->getDataByPorts(this->database->ccuPortsA);
        break;

    case ccu2:
        this->getDataByPorts(this->database->ccuPortsB);
        break;

    case riom:
        this->getDataByPorts(this->database->riomPorts);
        break;

    case erm:
        this->getDataByPorts(this->database->ermPorts);
        break;

    case bcu:
        this->getDataByPorts(bcuPorts);
        break;

    case dcu:
        this->getDataByPorts(this->database->dcuPorts);
        break;

    case siv:
        this->getDataByPorts(this->database->sivPorts);
        break;

    case edcu1:
        this->getDataByPorts(this->database->edcu1Ports);
        break;

    case edcu2:
        this->getDataByPorts(this->database->edcu2Ports);
        break;

    case pis:
        this->getDataByPorts(this->database->pisPorts);
        break;

    case hvac:
        this->getDataByPorts(this->database->hvacPorts);
        break;

    case atc:
        this->getDataByPorts(this->database->atcPorts);
        break;

    case pds:
        this->getDataByPorts(this->database->pdsPorts);
        break;

    case bcg:
        this->getDataByPorts(this->database->bcgPorts);
        break;

    case bms:
        this->getDataByPorts(this->database->bmsPorts);
        break;

    case fau:
        this->getDataByPorts(this->database->fauPorts);
        break;
    }
}

void DataMoniter::getDataByPorts(QList<port *> ports)
{
    this->devicePorts.clear();

    foreach (unsigned short int address, this->database->ports.keys())
    {

        foreach (struct port *pointer, ports)
        {
            if(address == pointer->address)
            {
                this->devicePorts.insert(pointer->address, *(this->database->ports[pointer->address]));
            }
        }
    }
}


void DataMoniter::on_btn_back_clicked()
{
    this->changePage(uDebugPage);
}


