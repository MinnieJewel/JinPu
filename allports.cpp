#include "allports.h"
#include "ui_allports.h"
#include "global.h"
#include <QDebug>
#include <QColor>
#include <QTableWidget>
/*
  "_A1","_A2" stand for Tc1 and Tc2
  "_C1","_C2" stand for Mp1 and Mp2
  "_B1","_B2" stand for M1 and M2
*/

#define DI_LENGTH 24
#define DO_LENGTH 16
#define AX_LENGTH 8

#define _UP 35, 79, 980, 186
#define _MID 35, 286, 980, 186
#define _DOWN 35, 485, 980, 186

#define _DOMID 35, 286, 980, 126
#define _AXDOWN 35, 425, 980, 126

#define _UPLABEL 5, 79, 31, 186
#define _MIDLABEL 5, 286, 31, 186
#define _DOWNLABEL 5, 485, 31, 186

#define _DOMIDLABEL 5, 286, 31, 126
#define _AXDOWNLABEL 5, 425, 31, 126

AllPorts::AllPorts(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::AllPorts)
{
    ui->setupUi(this);

    _LOG << "AllPorts constructor";
    QList<QPushButton *>buttons;
    buttons << ui->btn_back << ui->btn_tc1 << ui->btn_mp1 << ui->btn_mp2
            << ui->btn_tc2 << ui->btn_prev << ui->btn_next;

    foreach (QPushButton *button, buttons)
    {
        connect(button, SIGNAL(pressed()), this, SLOT(myKeyPress()));
    }

    // initial vehicle is tc1
    this->currentVehicle = ubtnTc1;
    this->page = 1;

    ui->btn_prev->setEnabled(false);

    //initial tables of riom informations
    this->riomDI1InfoTable = new QTableWidget(6, 12, this);
    this->riomDI2InfoTable = new QTableWidget(6, 12, this);
    this->riomDI3InfoTable = new QTableWidget(6, 12, this);
    this->riomDI4InfoTable = new QTableWidget(6, 12, this);
    this->riomDO1InfoTable = new QTableWidget(4, 12, this);
    this->riomAXInfoTable = new QTableWidget(4, 6, this);

    this->initialView();

    this->riomDI1InfoTable->setGeometry(_UP);
    this->riomDI2InfoTable->setGeometry(_MID);
    this->riomDI3InfoTable->setGeometry(_DOWN);
    this->riomDI4InfoTable->setGeometry(_UP);
    this->riomDO1InfoTable->setGeometry(_DOMID);
    this->riomAXInfoTable->setGeometry(_AXDOWN);

    ui->label_DI1->setGeometry(_UPLABEL);
    ui->label_DI2->setGeometry(_MIDLABEL);
    ui->label_DI3->setGeometry(_DOWNLABEL);

    ui->label_DI1->show();
    ui->label_DI2->show();
    ui->label_DI3->show();

    this->riomDI1InfoTable->show();
    this->riomDI2InfoTable->show();
    this->riomDI3InfoTable->show();
    ui->btn_tc1->setStyleSheet(BUTTON_DOWN);

    // DI/DO channels list
    this->listDI << QString("IN1") << QString("IN2") << QString("IN3") << QString("IN4") << QString("IN5") << QString("IN6") << QString("IN7") << QString("IN8")
            << QString("IN9") << QString("IN10") << QString("IN11") << QString("IN12") << QString("IN13") << QString("IN14") << QString("IN15") << QString("IN16")
            << QString("IN17") << QString("IN18") << QString("IN19") << QString("IN20") << QString("IN21") << QString("IN22") << QString("IN23") << QString("IN24");

    this->listDO << QString("OUT1") << QString("OUT2") << QString("OUT3") << QString("OUT4") << QString("OUT5") << QString("OUT6") << QString("OUT7") << QString("OUT8")
           << QString("OUT9") << QString("OUT10") << QString("OUT11") << QString("OUT12") << QString("OUT13") << QString("OUT14") << QString("OUT15") << QString("OUT16");

    // channels name list
    this->a1DI1List << QString("向前") << QString("向后") << QString("司机室激活") << QString("牵引指令线1") << QString("制动指令线1") << QString("快速制动") << QString("信号门旁路") << QString("门模式－手动")
            << QString("门模式－自动开/手动关") << QString("门模式－自动") << QString("右门使能") << QString("左门使能") << QString("开右门指令") << QString("开左门指令") << QString("门全关好") << QString("司机室左门")
            << QString("司机室右门") << QString("紧急疏散门") << QString("关右门指令") << QString("关左门指令") << QString("牵引使能") << QString("保留") << QString("保留") << QString("保留");

    this->a1DI2List << QString("向前") << QString("向后") << QString("司机室激活") << QString("牵引指令线1") << QString("制动指令线1") << QString("快速制动") << QString("保留") << QString("自动折返按钮")
            << QString("列车完整性") << QString("发车按钮") << QString("电制动切除按钮") << QString("制动系统主要故障") << QString("总风压力开关") << QString("VVVF复位按钮") << QString("VVVF切除按钮") << QString("本车制动切除")
            << QString("转向架1切除（制动）") << QString("转向架2切除（制动）") << QString("停放制动切除（制动）") << QString("照明驱动电源1故障") << QString("照明驱动电源2故障") << QString("照明驱动电源3故障") << QString("照明驱动电源4故障") << QString("保留");

    this->a1DI3List << QString("非零速") << QString("门安全线旁路") << QString("紧急制动旁路") << QString("停放制动旁路") << QString("制动不缓解旁路") << QString("停放制动施加按钮") << QString("停放制动缓解按钮") << QString("电笛按钮")
            << QString("风笛按钮") << QString("警惕旁路按钮") << QString("紧急制动蘑菇按钮") << QString("ADD旁路按钮") << QString("母线高速断路器") << QString("停放制动施加状态") << QString("强迫缓解按钮") << QString("紧急制动施加状态")
            << QString("保留") << QString("蓄电池断路器") << QString("蓄电池控制断路器") << QString("洗车模式") << QString("扩展供电指令") << QString("保留") << QString("保留") << QString("保留");

    this->a1DI4List << QString("车间电源") << QString("保留") << QString("ATC切除") << QString("模式开关RM位") << QString("模式开关IATP位") << QString("模式开关ATP位") << QString("ATB模式（自动折返）") << QString("模式开关ATO位")
            << QString("空压机运行") << QString("空压机热过载") << QString("空压机预启动") << QString("空压机供电异常") << QString("保留") << QString("保留") << QString("高加速按钮") << QString("客室电暖器1路")
            << QString("客室电暖器2路") << QString("客室电暖集控") << QString("紧急运行按钮") << QString("回送模式") << QString("SIV故障") << QString("SIV正常") << QString("DC24V正常") << QString("保留");

    this->a1DOList << QString("BHB闭合保持") << QString("BHB闭合动作") << QString("空压机启动") << QString("保留") << QString("保留") << QString("保留") << QString("保留") << QString("保留")
           << QString("保留") << QString("保留") << QString("保留") << QString("保留") << QString("保留") << QString("保留") << QString("保留") << QString("保留");

    this->b1DIList << QString("转向架1切除（制动）") << QString("转向架2切除（制动）") << QString("停放制动切除（制动）") << QString("照明驱动电源1故障") << QString("照明驱动电源2故障") << QString("照明驱动电源3故障") << QString("照明驱动电源4故障") << QString("客室电暖器1路")
            << QString("客室电暖器2路") << QString("本车制动切除") << QString("系统制动主要故障") << QString("辅助熔断器状态") << QString("主熔断器导通") << QString("母线高速断路器状态") << QString("扩展供电接触器反馈") << QString("KM11状态")
            << QString("制动电阻风机接触器状态") << QString("升弓到位") << QString("降弓到位") << QString("ADD降弓动作") << QString("初次升弓泵") << QString("OCR状态") << QString("KM21状态") << QString("保留");

    this->b1DOList << QString("扩展供电闭合") << QString("保留") << QString("保留") << QString("保留") << QString("保留") << QString("保留") << QString("保留") << QString("保留")
            << QString("保留") << QString("保留") << QString("保留") << QString("保留") << QString("保留") << QString("保留") << QString("保留") << QString("保留");

    this->c1DIList << QString("转向架1切除（制动）") << QString("转向架2切除（制动）") << QString("停放制动切除（制动）") << QString("照明驱动电源1故障") << QString("照明驱动电源2故障") << QString("照明驱动电源3故障") << QString("照明驱动电源4故障") << QString("客室电暖器1路")
           << QString("客室电暖器2路") << QString("保留") << QString("保留") << QString("保留") << QString("主熔断器导通") << QString("升弓到位") << QString("降弓到位") << QString("ADD降弓动作")
           << QString("受电弓断路器闭合") << QString("初次升弓泵") << QString("保留") << QString("废排风机1路") << QString("废排风机2路") << QString("保留") << QString("保留") << QString("保留");

    this->c1DOList << QString("保留") << QString("保留") << QString("保留") << QString("保留") << QString("保留") << QString("保留") << QString("保留") << QString("保留")
           << QString("保留") << QString("保留") << QString("保留") << QString("保留") << QString("保留") << QString("保留") << QString("保留") << QString("保留");


    setTableView(this->riomDI1InfoTable, this->listDI, this->a1DI1List);
    setTableView(this->riomDI2InfoTable, this->listDI, this->a1DI2List);
    setTableView(this->riomDI3InfoTable, this->listDI, this->a1DI3List);
    setTableView(this->riomDI4InfoTable, this->listDI, this->a1DI4List);
    setTableView(this->riomDO1InfoTable, this->listDO, this->a1DOList);
    setAXTableView();

    ui->btn_prev->show();
    ui->btn_next->show();
    ui->btn_prev->setEnabled(false);
    ui->btn_next->setEnabled(true);
    ui->label_pageIndex->setText(QString("1/2"));
    ui->label_pageIndex->show();
}

AllPorts::~AllPorts()
{
    delete ui;
}

void AllPorts::hideAllTable()
{
    this->riomDI1InfoTable->hide();
    this->riomDI2InfoTable->hide();
    this->riomDI3InfoTable->hide();
    this->riomDI4InfoTable->hide();
    this->riomDO1InfoTable->hide();
    this->riomAXInfoTable->hide();

    ui->label_DI1->hide();
    ui->label_DI2->hide();
    ui->label_DI3->hide();
    ui->label_DI4->hide();
    ui->label_DO->hide();
    ui->label_AX->hide();

    this->cleanContent(this->riomDI1InfoTable);
    this->cleanContent(this->riomDI2InfoTable);
    this->cleanContent(this->riomDI3InfoTable);
    this->cleanContent(this->riomDI4InfoTable);
    this->cleanContent(this->riomDO1InfoTable);
    this->cleanContent(this->riomAXInfoTable);
}

void AllPorts::cleanContent(QTableWidget *table)
{
    if (NULL == table)
    {
        _LOG << "table is null in cleanContent";
        return;
    }
    for (int row = 0; row < table->rowCount(); row ++)
    {
        for (int column = 0; column < table->columnCount(); column ++)
        {
            if (NULL == table->item(row, column))
            {
                _LOG << "tableItem at " << row << ", " << column << " is null, in cleanContent.";
                return;
            }
            table->item(row, column)->setText("");
        }
    }
}

void AllPorts::myKeyPress()
{
    if (this->sender()->objectName() == QString("btn_back"))
    {
        emit this->changePage(uDebugPage);
    }

    else if (this->sender()->objectName() == QString("btn_tc1"))
    {
        this->hideAllTable();
        this->currentVehicle = ubtnTc1;
        this->updateButton(this->currentVehicle);
        ui->btn_tc1->setStyleSheet(BUTTON_DOWN);        

        ui->label_DI1->setGeometry(_UPLABEL);
        ui->label_DI2->setGeometry(_MIDLABEL);
        ui->label_DI3->setGeometry(_DOWNLABEL);

        ui->label_DI1->show();
        ui->label_DI2->show();
        ui->label_DI3->show();

        setTableView(this->riomDI1InfoTable, this->listDI, this->a1DI1List);
        setTableView(this->riomDI2InfoTable, this->listDI, this->a1DI2List);
        setTableView(this->riomDI3InfoTable, this->listDI, this->a1DI3List);
        setTableView(this->riomDI4InfoTable, this->listDI, this->a1DI4List);

        setTableView(this->riomDO1InfoTable, this->listDO, this->a1DOList);
        setAXTableView();

        this->riomDI1InfoTable->show();
        this->riomDI2InfoTable->show();
        this->riomDI3InfoTable->show();


        ui->btn_prev->show();
        ui->btn_next->show();
        ui->btn_prev->setEnabled(false);
        ui->btn_next->setEnabled(true);
        ui->label_pageIndex->setText(QString("1/2"));
        ui->label_pageIndex->show();

    }
    else if (this->sender()->objectName() == QString("btn_mp1"))
    {
        this->hideAllTable();
        this->currentVehicle = ubtnMp1;
        this->updateButton(this->currentVehicle);

        ui->label_DI1->setGeometry(_UPLABEL);
        ui->label_DO->setGeometry(_DOMIDLABEL);

        ui->label_DI1->show();
        ui->label_DO->show();
        setTableView(this->riomDI1InfoTable, this->listDI, this->b1DIList);
        setTableView(this->riomDO1InfoTable, this->listDO, this->b1DOList);

        this->riomDI1InfoTable->show();
        this->riomDO1InfoTable->show();

        this->currentVehicle = ubtnMp1;
        ui->btn_prev->hide();
        ui->btn_next->hide();
        ui->label_pageIndex->hide();
    }
    else if (this->sender()->objectName() == QString("btn_mp2"))
    {
        this->hideAllTable();
        this->currentVehicle = ubtnMp2;
        this->updateButton(this->currentVehicle);


        ui->label_DI1->setGeometry(_UPLABEL);
        ui->label_DO->setGeometry(_DOMIDLABEL);

        ui->label_DI1->show();
        ui->label_DO->show();

        this->riomDI1InfoTable->show();
        this->riomDO1InfoTable->show();

        setTableView(this->riomDI1InfoTable, this->listDI, this->b1DIList);
        setTableView(this->riomDO1InfoTable, this->listDO, this->b1DOList);
        ui->btn_prev->hide();
        ui->btn_next->hide();
        ui->label_pageIndex->hide();
    }
    else if (this->sender()->objectName() == QString("btn_tc2"))
    {
        this->hideAllTable();
        this->currentVehicle = ubtnTc2;
        this->updateButton(this->currentVehicle);

        ui->label_DI1->setGeometry(_UPLABEL);
        ui->label_DI2->setGeometry(_MIDLABEL);
        ui->label_DI3->setGeometry(_DOWNLABEL);

        ui->label_DI1->show();
        ui->label_DI2->show();
        ui->label_DI3->show();

        this->riomDI1InfoTable->show();
        this->riomDI2InfoTable->show();
        this->riomDI3InfoTable->show();

        setTableView(this->riomDI1InfoTable, this->listDI, this->a1DI1List);
        setTableView(this->riomDI2InfoTable, this->listDI, this->a1DI2List);
        setTableView(this->riomDI3InfoTable, this->listDI, this->a1DI3List);
        setTableView(this->riomDI4InfoTable, this->listDI, this->a1DI4List);
        setTableView(this->riomDO1InfoTable, this->listDO, this->a1DOList);
        setAXTableView();

        ui->btn_prev->show();
        ui->btn_next->show();
        ui->btn_prev->setEnabled(false);
        ui->btn_next->setEnabled(true);
        ui->label_pageIndex->setText(QString("1/2"));
        ui->label_pageIndex->show();
    }
    else if (this->sender()->objectName() == QString("btn_prev"))
    {
        this->hideAllTable();
        ui->label_DI1->setGeometry(_UPLABEL);
        ui->label_DI2->setGeometry(_MIDLABEL);
        ui->label_DI3->setGeometry(_DOWNLABEL);

        ui->label_DI1->show();
        ui->label_DI2->show();
        ui->label_DI3->show();

        this->riomDI1InfoTable->show();
        this->riomDI2InfoTable->show();
        this->riomDI3InfoTable->show();

        setTableView(this->riomDI1InfoTable, this->listDI, this->a1DI1List);
        setTableView(this->riomDI2InfoTable, this->listDI, this->a1DI2List);
        setTableView(this->riomDI3InfoTable, this->listDI, this->a1DI3List);
        setTableView(this->riomDI4InfoTable, this->listDI, this->a1DI4List);
        setTableView(this->riomDO1InfoTable, this->listDO, this->a1DOList);
        setAXTableView();

        ui->btn_prev->show();
        ui->btn_next->show();
        ui->btn_prev->setEnabled(false);
        ui->btn_next->setEnabled(true);
        ui->label_pageIndex->setText(QString("1/2"));
        ui->label_pageIndex->show();
    }
    else if (this->sender()->objectName() == QString("btn_next"))
    {
        this->hideAllTable();
        ui->label_DI4->setGeometry(_UPLABEL);
        ui->label_DO->setGeometry(_DOMIDLABEL);
        ui->label_AX->setGeometry(_AXDOWNLABEL);

        ui->label_DI4->show();
        ui->label_DO->show();
        ui->label_AX->show();

        this->riomDI4InfoTable->show();
        this->riomDO1InfoTable->show();
        this->riomAXInfoTable->show();

        setTableView(this->riomDI1InfoTable, this->listDI, this->a1DI1List);
        setTableView(this->riomDI2InfoTable, this->listDI, this->a1DI2List);
        setTableView(this->riomDI3InfoTable, this->listDI, this->a1DI3List);
        setTableView(this->riomDI4InfoTable, this->listDI, this->a1DI4List);
        setTableView(this->riomDO1InfoTable, this->listDO, this->a1DOList);
        setAXTableView();

        ui->btn_prev->show();
        ui->btn_next->show();
        ui->btn_prev->setEnabled(true);
        ui->btn_next->setEnabled(false);
        ui->label_pageIndex->setText(QString("2/2"));
        ui->label_pageIndex->show();
    }

}

void AllPorts::setAXTableView()
{
    this->listAX << QString("AIN1") << QString("AIN2") << QString("AIN3") << QString("AIN4") << QString("AIN5") << QString("AIN6") << QString("AIN7") << QString("AIN8");
    this->a1AXList << QString("信号系统牵引级位") << QString("信号系统牵引级位－冗余") << QString("保留") << QString("保留") << QString("司控器输入1参考") << QString("司控器输入1参考") << QString("司控器级位1") << QString("司控器级位2");
    for(int columnNo = 0; columnNo < this->riomAXInfoTable->columnCount();columnNo++)
   {
        int tempColumn = columnNo % 3;

        switch(tempColumn)
        {
        case 0:
            this->riomAXInfoTable->setColumnWidth(columnNo, 47);
            break;
        case 1:
            this->riomAXInfoTable->setColumnWidth(columnNo,205);
            break;
        case 2:
            this->riomAXInfoTable->setColumnWidth(columnNo,200);
            break;

        default:
            _LOG << "table columns fault :" << tempColumn;
            break;
        }
   }

    for(int row = 0; row < this->riomAXInfoTable->rowCount(); row++)
    {
        this->riomAXInfoTable->setRowHeight(row, 30);
        for(int column = 0; column < this->riomAXInfoTable->columnCount(); column++)
        {
            int tempColumn = column % 3;
            int tempChannel = column / 3;
            int listIndex = row * 2 + tempChannel;

            if(listIndex % 2)
            {
                this->riomAXInfoTable->item(row, column)->setTextColor(_WHITECOLOR);
                this->riomAXInfoTable->item(row, column)->setBackgroundColor(QColor(0 ,0, 0));
            }
            else
            {
                this->riomAXInfoTable->item(row, column)->setTextColor(_BLUECOLOR);
                this->riomAXInfoTable->item(row, column)->setBackgroundColor(QColor(0 ,0, 0));
            }

            switch(tempColumn)
            {
            case 0:
                this->riomAXInfoTable->item(row, column)->setText(QString(this->listAX.at(listIndex)));
                break;
            case 1:
                this->riomAXInfoTable->item(row, column)->setText(QString(this->a1AXList.at(listIndex)));
                break;
            case 2:
                break;
            default:
                _LOG << "table columns fault :" << column;
            }
        }
    }

   // this->riomAXInfoTable

}

/*
Author:zhumm
Name:setTableView
set DI/DO/AX table views
Variable:
    *table: the table to set
    channelNoList: the list of channels number
    channelNameList: the list of channels name
*/

void AllPorts::setTableView(QTableWidget *table, QList<QString> channelNoList, QList<QString> channelNameList)
{

    if(NULL == table)
    {
         _LOG << "table is null";
         return;
    }

         // set table columns width
     for(int columnNo = 0; columnNo < table->columnCount();columnNo++)
    {
         int tempColumn = columnNo % 3;

         switch(tempColumn)
         {
         case 0:
             table->setColumnWidth(columnNo, 59);
             break;
         case 1:
             table->setColumnWidth(columnNo,160);
             break;
         case 2:
             table->setColumnWidth(columnNo,24);
             break;

         default:
             _LOG << "table columns fault :" << tempColumn;
             break;
         }
    }
     // set rows' width and insert channel NO. and channel name
     for(int rows = 0; rows < table->rowCount(); rows++ )
     {
         table->setRowHeight(rows, 30);

         for(int column = 0; column < table->columnCount(); column++)
         {
             int tempColumn = column % 3;
             int tempChannel = column / 3;
             int listIndex = rows * 4 + tempChannel;

             if (NULL == table->item(rows, column))
             {
                _LOG << "table items at" << rows << " and" << column << " is null; row count is " << table->rowCount() << " and column is " << table->columnCount();
             }
             if(listIndex % 2)
             {
                 table->item(rows, column)->setTextColor(_WHITECOLOR);
                 table->item(rows, column)->setBackgroundColor(QColor(0 ,0, 0));
             }
             else
             {
                 table->item(rows, column)->setTextColor(_BLUECOLOR);
                 table->item(rows, column)->setBackgroundColor(QColor(0 ,0, 0));
             }

             switch(tempColumn)
             {
             case 0:
                 table->item(rows, column)->setText(QString(channelNoList.at(listIndex)));
                 break;
             case 1:
                 table->item(rows, column)->setText(QString(channelNameList.at(listIndex)));
                 break;
             case 2:
                 break;
             default:
                 _LOG << "table columns fault :" << column;
             }
         }
     }
}


void AllPorts::updatePage()
{

    QList<bool> states;

    QList<QString> axStates;

    if(ubtnTc1 == this->currentVehicle)
    {
     // riom A1 di1
    states << this->database->DICT_Tc1DI1I1Forward_A1 << this->database->DICT_Tc1DI1I2Backward_A1 << this->database->DICT_Tc1DI1I3DriverRoomAct_A1 << this->database->DICT_Tc1DI1I4Traction_A1
           << this->database->DICT_Tc1DI1I5Brake_A1 << this->database->DICT_Tc1DI1I6FastBrk_A1 << this->database->DICT_Tc1DI1I7Traction_A1 << this->database->DICT_Tc1DI1I8Brake_A1
           << this->database->RIOM1_DIM1Ch9 << this->database->RIOM1_DIM1Ch10 << this->database->DICT_Tc1DI1I11DrRightEnable_A1 << this->database->DICT_Tc1DI1I12DrLeftEnable_A1
           << this->database->DICT_Tc1DI1I13DrROpenCmd_A1 << this->database->DICT_Tc1DI1I14DrLOpenCmd_A1 << this->database->DICT_Tc1DI1I15AllDoorClosed_A1 << this->database->DICT_Tc1DI1I16CabDrLeftStatus_A1
           << this->database->DICT_Tc1DI1I17CabDrRightStatus_A1 << this->database->DICT_Tc1DI1I18EmgyDoorStatus_A1 << this->database->DICT_Tc1DI1I19DrRCloseCmd_A1 << this->database->DICT_Tc1DI1I20DrLCloseCmd_A1
           << this->database->RIOM1_DIM1Ch21 << this->database->RIOM1_DIM1Ch22 << this->database->RIOM1_DIM1Ch23 << this->database->RIOM1_DIM1Ch24;

    this->updateDio(this->riomDI1InfoTable, states);
    states.clear();

    // riom A1 di2
    states << this->database->DICT_Tc1DI2I1Forward_A1 << this->database->DICT_Tc1DI2I2Backward_A1<< this->database->DICT_Tc1DI2I3DriverRoomAct_A1 << this->database->DICT_Tc1DI2I4Traction_A1
           << this->database->DICT_Tc1DI2I5Brake_A1 << this->database->DICT_Tc1DI2I6FastBrk_A1<< this->database->DICT_Tc1DI2I7Traction_A1 << this->database->DICT_Tc1DI2I8Brake_A1
           << this->database->RIOM1_DIM2Ch9 << this->database->RIOM1_DIM2Ch10 << this->database->DICT_Tc1DI2I11EBCutBtn_A1<< this->database->DICT_Tc1DI2I12BCUMainFlt_A1
           << this->database->DICT_Tc1DI2I13WindPressBtn_A1 << this->database->DICT_Tc1DI2I14VVVFReset_A1 << this->database->DICT_Tc1DI2I15VVVFCut_A1 << this->database->DICT_Tc1DI2I16BCUCut_A1
           << this->database->DICT_Tc1DI2I17Bogie1Cut_A1 << this->database->DICT_Tc1DI2I18Bogie2Cut_A1 << this->database->DICT_Tc1DI2I19ParkingBrkCutOut_A1 << this->database->DICT_Tc1DI2I20LuminairePower1_A1
           << this->database->DICT_Tc1DI2I21LuminairePower2_A1 << this->database->DICT_Tc1DI2I22LuminairePower3_A1 << this->database->DICT_Tc1DI2I23LuminairePower4_A1 << this->database->RIOM1_DIM2Ch24;

    this->updateDio(this->riomDI2InfoTable, states);
    states.clear();

    // riom A1 di3
    states << this->database->DICT_Tc1DI3I1NotZeroSpeed_A1 << this->database->DICT_Tc1DI3I2DoorSafeByPass_A1 << this->database->DICT_Tc1DI3I3EmcByPass_A1 << this->database->DICT_Tc1DI3I4ParkingBrkByPass_A1
           << this->database->DICT_Tc1DI3I5BrkNotRelByPass_A1 << this->database->DICT_Tc1DI3I6StopBrkInBtn_A1 << this->database->DICT_Tc1DI3I7StopBrkRelBtn_A1 << this->database->DICT_Tc1DI3I8EleWhistleBtn_A1
           << this->database->DICT_Tc1DI3I9WindWhistleBtn_A1 << this->database->RIOM1_DIM3Ch10 << this->database->DICT_Tc1DI3I11EmgyBrkButton_A1 << this->database->DICT_Tc1DI3I12ADDByPass_A1
           << this->database->DICT_Tc1DI3I13HSCBConBtn_A1 << this->database->DICT_Tc1DI3I14ParkingBrk_A1 << this->database->DICT_Tc1DI3I15ForceRelBtn_A1 << this->database->DICT_Tc1DI3I16EmgySta_A1
           << this->database->RIOM1_DIM3Ch17 << this->database->DICT_Tc1DI3I18BatBreakerSta_A1 << this->database->DICT_Tc1DI3I19BatCtrlBreakerSta_A1<< this->database->RIOM1_DIM3Ch20
           << this->database->RIOM1_DIM3Ch21 << this->database->RIOM1_DIM3Ch22 << this->database->RIOM1_DIM3Ch23 << this->database->RIOM1_DIM3Ch24;

    this->updateDio(this->riomDI3InfoTable, states);
    states.clear();

    // riom A1 di4
    states << this->database->DICT_Tc1DI4I1WorkShopPower_A1 << this->database->Tc1DI4I2 << this->database->DICT_Tc1DI4I3ATCCut_A1 << this->database->DICT_Tc1DI4I4RMMode_A1
           << this->database->DICT_Tc1DI4I5IATPMode_A1 << this->database->DICT_Tc1DI4I6ATPMode_A1 << this->database->DICT_Tc1DI4I7ATBMode_A1 << this->database->DICT_Tc1DI4I8ATOSwitch_A1
           << this->database->DICT_Tc1DI4I9AirCmpRun_A1 << this->database->DICT_Tc1DI4I10AirCmpHotOverload_A1 << this->database->DICT_Tc1DI4I11AirCmpPreStart_A1 << this->database->DICT_Tc1DI4I12AirCmpPowerFlt_A1
           << this->database->DICT_Tc1DI4I13DeadmanLoosen_A1 << this->database->DICT_Tc1DI4I14DeadmanPress_A1 << this->database->DICT_Tc1DI4I15HighAcceMode_A1 << this->database->DICT_Tc1DI4I16HeaterCh1_A1
           << this->database->DICT_Tc1DI4I17HeaterCh2_A1 << this->database->DICT_Tc1DI4I18HeaterNetCtrl_A1 << this->database->DICT_Tc1DI4I19EMCMode_A1 << this->database->DICT_Tc1DI4I20SendBackSta_A1
           << this->database->DICT_Tc1DI4I21SivFlt_A1 << this->database->DICT_Tc1DI4I22SivRun_A1 << this->database->DICT_Tc1DI4I23DC24V << this->database->RIOM1_DIM4Ch24;

    this->updateDio(this->riomDI4InfoTable, states);
    states.clear();

    // riom A1 do
    states << this->database->CTDO_Tc1BHBMaintain << this->database->CTDO_Tc1BHBAction << this->database->CTDO_Tc1CmpStart << this->database->RIOM1_DOMIC4
           << this->database->RIOM1_DOMIC5 << this->database->RIOM1_DOMIC6 << this->database->RIOM1_DOMIC7<< this->database->RIOM1_DOMIC8
           << this->database->RIOM1_DOMIC9 << this->database->RIOM1_DOMIC10 << this->database->RIOM1_DOMIC11 << this->database->RIOM1_DOMIC12
           << this->database->RIOM1_DOMIC13 << this->database->RIOM1_DOMIC14 << this->database->RIOM1_DOMIC15 << this->database->RIOM1_DOMIC16;

    this->updateDio(this->riomDO1InfoTable, states);
    states.clear();

    // riom A1 ax
    axStates << QString::number(this->database->AICT_Tc1AI1ATCLevelA_A1) << QString::number(this->database->AICT_Tc1AI2ATCLevelB_A1) << QString::number(this->database->RIOM1_AXC3) << QString::number(this->database->RIOM1_AXC4)
             << QString::number(this->database->AICT_Tc1AI5DCLevelADup_A1) << QString::number(this->database->AICT_Tc1AI6DCLevelBDup_A1)
             << QString::number(this->database->AICT_Tc1AI7DriverControllerLevelA_A1) << QString::number(this->database->AICT_Tc1AI8DriverControllerLevelB_A1);
    this->updateAx(this->riomAXInfoTable, axStates);
    states.clear();
 }
    if(ubtnMp1 == this->currentVehicle)
    {

   // riom C1 di1
    states << this->database->DICT_Mp1DI1I1Bogie1Cut_A1 << this->database->DICT_Mp1DI1I2Bogie2Cut_A1<< this->database->DICT_Mp1DI1I3ParkingBrkCutOut_A1 << this->database->DICT_Mp1DI1I4LuminairePower1_A1
           << this->database->DICT_Mp1DI1I5LuminairePower2_A1 << this->database->DICT_Mp1DI1I6LuminairePower3_A1 << this->database->DICT_Mp1DI1I7LuminairePower4_A1 << this->database->DICT_Mp1DI1I8HeaterCh1_A1
           << this->database->DICT_Mp1DI1I9HeaterCh2_A1 << this->database->DICT_M1DI1I10BCUCut_A1 << this->database->DICT_M1DI1I11BCUMainFlt_A1 << this->database->RIOM3_DIM1Ch12
           << this->database->DICT_M1DI1I13MainFuseOn_A1 << this->database->DICT_M1DI1I14BHBStaFB_A1 << this->database->DICT_M1DI1I15ExpandPowerFB_A1 << this->database->DICT_M1DI1I16ExpandPower_A1
           << this->database->DICT_Mp1DI1I17ExPowerSta_A1 << this->database->DICT_Mp1DI1I18PanRised_A1 << this->database->DICT_Mp1DI1I19PanDropped_A1 << this->database->DICT_Mp1DI1I20ADDDropPan_A1
           << this->database->DICT_Mp1DI1I21FirstRisePanPump_A1 << this->database->RIOM3_DIM1Ch22 << this->database->RIOM3_DIM1Ch23 << this->database->RIOM3_DIM1Ch24;
 this->updateDio(this->riomDI1InfoTable, states);
 states.clear();

 // riom mp1 do
 states << this->database->CTDO_M3ExPowerCmd << this->database->RIOM3_DOMIC2 << this->database->RIOM3_DOMIC3 << this->database->RIOM3_DOMIC4 << this->database->RIOM3_DOMIC5 << this->database->RIOM3_DOMIC6 << this->database->RIOM3_DOMIC7 << this->database->RIOM3_DOMIC8
       << this->database->RIOM3_DOMIC9 << this->database->RIOM3_DOMIC10 << this->database->RIOM3_DOMIC11 << this->database->RIOM3_DOMIC12 << this->database->RIOM3_DOMIC13 << this->database->RIOM3_DOMIC14 << this->database->RIOM3_DOMIC15 << this->database->RIOM3_DOMIC16;
this->updateDio(this->riomDO1InfoTable, states);
 states.clear();

     }

    if (ubtnTc2 == this->currentVehicle)
    {
      // riom A2 di1
       states << this->database->DICT_Tc2DI1I1Forward_A2 << this->database->DICT_Tc2DI1I2Backward_A2 << this->database->DICT_Tc2DI1I3DriverRoomAct_A2 << this->database->DICT_Tc2DI1I4Traction_A2
              << this->database->DICT_Tc2DI1I5Brake_A2 << this->database->DICT_Tc2DI1I6FastBrk_A2 << this->database->DICT_Tc2DI1I7Traction_A2 << this->database->DICT_Tc2DI1I8Brake_A2
              << this->database->RIOM6_DIM1Ch9 << this->database->RIOM6_DIM1Ch10 << this->database->DICT_Tc2DI1I11DrRightEnable_A2 << this->database->DICT_Tc2DI1I12DrLeftEnable_A2
              << this->database->DICT_Tc2DI1I13DrROpenCmd_A2 << this->database->DICT_Tc2DI1I14DrLOpenCmd_A2 << this->database->DICT_Tc2DI1I15AllDoorClosed_A2 << this->database->DICT_Tc2DI1I16CabDrLeftStatus_A2
              << this->database->DICT_Tc2DI1I17CabDrRightStatus_A2 << this->database->DICT_Tc2DI1I18EmgyDoorStatus_A2 << this->database->DICT_Tc2DI1I19DrRCloseCmd_A2 << this->database->DICT_Tc2DI1I20DrLCloseCmd_A2
              << this->database->RIOM6_DIM1Ch21 << this->database->RIOM6_DIM1Ch22 << this->database->RIOM6_DIM1Ch23 << this->database->RIOM6_DIM1Ch24;

      this->updateDio(this->riomDI1InfoTable, states);
      states.clear();

      // riom A2 di2
      states << this->database->DICT_Tc2DI2I1Forward_A2 << this->database->DICT_Tc2DI2I2Backward_A2<< this->database->DICT_Tc2DI2I3DriverRoomAct_A2 << this->database->DICT_Tc2DI2I4Traction_A2
             << this->database->DICT_Tc2DI2I5Brake_A2 << this->database->DICT_Tc2DI2I6FastBrk_A2<< this->database->DICT_Tc2DI2I7Traction_A2 << this->database->DICT_Tc2DI2I8Brake_A2
             << this->database->RIOM6_DIM2Ch9 << this->database->RIOM6_DIM2Ch10 << this->database->DICT_Tc2DI2I11EBCutBtn_A2<< this->database->DICT_Tc2DI2I12BCUMainFlt_A2
             << this->database->DICT_Tc2DI2I13WindPressBtn_A2 << this->database->DICT_Tc2DI2I14VVVFReset_A2<< this->database->DICT_Tc2DI2I15VVVFCut_A2 << this->database->DICT_Tc2DI2I16BCUCut_A2
             << this->database->DICT_Tc2DI2I17Bogie1Cut_A2 << this->database->DICT_Tc2DI2I18Bogie2Cut_A2 << this->database->DICT_Tc2DI2I19ParkingBrkCutOut_A2 << this->database->DICT_Tc2DI2I20LuminairePower1_A2
             << this->database->DICT_Tc2DI2I21LuminairePower2_A2 << this->database->DICT_Tc2DI2I22LuminairePower3_A2 << this->database->DICT_Tc2DI2I23LuminairePower4_A2 << this->database->RIOM6_DIM2Ch24;

      this->updateDio(this->riomDI2InfoTable, states);
      states.clear();


      // riom A2 di3
      states << this->database->DICT_Tc2DI3I1NotZeroSpeed_A2 << this->database->DICT_Tc2DI3I2DoorSafeByPass_A2 << this->database->DICT_Tc2DI3I3EmcByPass_A2 << this->database->DICT_Tc2DI3I4ParkingBrkByPass_A2
             << this->database->DICT_Tc2DI3I5BrkNotRelByPass_A2 << this->database->DICT_Tc2DI3I6StopBrkInBtn_A2 << this->database->DICT_Tc2DI3I7StopBrkRelBtn_A2 << this->database->DICT_Tc2DI3I8EleWhistleBtn_A2
             << this->database->DICT_Tc2DI3I9WindWhistleBtn_A2 << this->database->RIOM6_DIM3Ch10 << this->database->DICT_Tc2DI3I11EmgyBrkButton_A2 << this->database->DICT_Tc2DI3I12ADDByPass_A2
             << this->database->DICT_Tc2DI3I13HSCBConBtn_A2 << this->database->DICT_Tc2DI3I14ParkingBrk_A2 << this->database->DICT_Tc2DI3I15ForceRelBtn_A2 << this->database->DICT_Tc2DI3I16EmgySta_A2
             << this->database->RIOM6_DIM3Ch17 << this->database->DICT_Tc2DI3I18BatBreakerSta_A2 << this->database->DICT_Tc2DI3I19BatCtrlBreakerSta_A2 << this->database->RIOM6_DIM3Ch20
             << this->database->RIOM6_DIM3Ch21 << this->database->RIOM6_DIM3Ch22 << this->database->RIOM6_DIM3Ch23 << this->database->RIOM6_DIM3Ch24;

      this->updateDio(this->riomDI3InfoTable, states);
      states.clear();

      // riom A2 di4
      states << this->database->DICT_Tc2DI4I1WorkShopPower_A2 << this->database->Tc2DI4I2 << this->database->DICT_Tc2DI4I3ATCCut_A2 << this->database->DICT_Tc2DI4I4RMMode_A2
             << this->database->DICT_Tc2DI4I5ATPMode_A2 << this->database->DICT_Tc2DI4I6ATPMode_A2 << this->database->DICT_Tc2DI4I7ATBMode_A2 << this->database->DICT_Tc2DI4I8ATOSwitch_A2
             << this->database->DICT_Tc2DI4I9AirCmpRun_A2 << this->database->DICT_Tc2DI4I10AirCmpHotOverload_A2 << this->database->DICT_Tc2DI4I11AirCmpPreStart_A2 << this->database->DICT_Tc2DI4I12AirCmpPowerFlt_A2
             << this->database->DICT_Tc2DI4I13DeadmanLoosen_A2 << this->database->DICT_Tc2DI4I14DeadmanPress_A2 << this->database->DICT_Tc2DI4I15HighAcceMode_A2 << this->database->DICT_Tc2DI4I16HeaterCh1_A2
             << this->database->DICT_Tc2DI4I17HeaterCh2_A2 << this->database->DICT_Tc2DI4I18HeaterNetCtrl_A2 << this->database->DICT_Tc2DI4I19EMCMode_A2 << this->database->DICT_Tc2DI4I20SendBackSta_A2
             << this->database->DICT_Tc2DI4I21SivFlt_A2 << this->database->DICT_Tc2DI4I22SivRun_A2 << this->database->DICT_TC2DI4I23DC24V << this->database->RIOM6_DIM4Ch24;

      this->updateDio(this->riomDI4InfoTable, states);
      states.clear();


      // riom A2 do
      states << this->database->CTDO_Tc2BHBMaintain << this->database->CTDO_Tc2BHBAction << this->database->CTDO_Tc2CmpStart << this->database->RIOM6_DOMIC4 << this->database->RIOM6_DOMIC5 << this->database->RIOM6_DOMIC6 << this->database->RIOM6_DOMIC7 << this->database->RIOM6_DOMIC8
             << this->database->RIOM6_DOMIC9 << this->database->RIOM6_DOMIC10 << this->database->RIOM6_DOMIC11 << this->database->RIOM6_DOMIC12 << this->database->RIOM6_DOMIC13 << this->database->RIOM6_DOMIC14 << this->database->RIOM6_DOMIC15 << this->database->RIOM6_DOMIC16;
      this->updateDio(this->riomDO1InfoTable, states);
      states.clear();


      // riom A2 ax
      axStates << QString::number(this->database->AICT_Tc2AI1ATCLevelA_A2) << QString::number(this->database->AICT_Tc2AI2ATCLevelB_A2) << QString::number(this->database->RIOM6_AXC3) << QString::number(this->database->RIOM6_AXC4)
               << QString::number(this->database->AICT_Tc2AI5DCLevelADup_A2) << QString::number(this->database->AICT_Tc2AI6DCLevelBDup_A2)
               << QString::number(this->database->AICT_Tc2AI7DriverControllerLevelA_A2) << QString::number(this->database->AICT_Tc2AI8DriverControllerLevelB_A2);
      this->updateAx(this->riomAXInfoTable, axStates);
      states.clear();
    }

    if(ubtnMp2 == this->currentVehicle)
    {

     // riom C2 di1
   states << this->database->DICT_Mp2DI1I1Bogie1Cut_A2 << this->database->DICT_Mp2DI1I2Bogie2Cut_A2 << this->database->DICT_Mp2DI1I3ParkingBrkCutOut_A2 << this->database->DICT_Mp2DI1I4LuminairePower1_A2
          << this->database->DICT_Mp2DI1I5LuminairePower2_A2 << this->database->DICT_Mp2DI1I6LuminairePower3_A2 << this->database->DICT_Mp2DI1I7LuminairePower4_A2 << this->database->DICT_Mp2DI1I8HeaterCh1_A2
          << this->database->DICT_Mp2DI1I9HeaterCh2_A2 << this->database->DICT_M2DI1I10BCUCut_A2 << this->database->DICT_M2DI1I11BCUMainFlt_A2 << this->database->RIOM4_DIM1Ch12
          << this->database->DICT_M2DI1I13MainFuseOn_A2 << this->database->DICT_M2DI1I14BHBStaFB_A2 << this->database->DICT_M2DI1I15ExpandPowerFB_A2 << this->database->DICT_M2DI1I16ExpandPower_A2
          << this->database->DICT_Mp2DI1I17ExPowerSta_A2 << this->database->DICT_Mp2DI1I18PanRised_A2 << this->database->DICT_Mp2DI1I19PanDropped_A2 << this->database->DICT_Mp2DI1I20ADDDropPan_A2
          << this->database->DICT_Mp2DI1I21FirstRisePanPump_A2 << this->database->RIOM4_DIM1Ch22 << this->database->RIOM4_DIM1Ch23 << this->database->RIOM4_DIM1Ch24;

   this->updateDio(this->riomDI1InfoTable, states);
   states.clear();



     // riom mp2 do
    states << this->database->CTDO_M4ExPowerCmd << this->database->RIOM4_DOMIC2 << this->database->RIOM4_DOMIC3 << this->database->RIOM4_DOMIC4 << this->database->RIOM4_DOMIC5 << this->database->RIOM4_DOMIC6 << this->database->RIOM4_DOMIC7 << this->database->RIOM4_DOMIC8
           << this->database->RIOM4_DOMIC9 << this->database->RIOM4_DOMIC10 << this->database->RIOM4_DOMIC11 << this->database->RIOM4_DOMIC12 << this->database->RIOM4_DOMIC13 << this->database->RIOM4_DOMIC14 << this->database->RIOM4_DOMIC15 << this->database->RIOM4_DOMIC16;
    this->updateDio(this->riomDO1InfoTable, states);
      states.clear();
     }

 // riom B2 di1
/*states << this->database->DICT_Mp2DI1I1Bogie1Cut_B2 << this->database->DICT_Mp2DI1I2Bogie2Cut_B2 << this->database->DICT_Mp2DI1I3ParkingBrkCutOut_B2 << this->database->DICT_Mp2DI1I4LuminairePower1_B2
       << this->database->DICT_Mp2DI1I5LuminairePower2_B2 << this->database->DICT_Mp2DI1I6LuminairePower3_B2 << this->database->DICT_Mp2DI1I7LuminairePower4_B2 << this->database->DICT_Mp2DI1I8HeaterCh1_B2
       << this->database->DICT_Mp2DI1I9HeaterCh2_B2 << this->database->RIOM5_DIM1Ch10 << this->database->RIOM5_DIM1Ch11 << this->database->RIOM5_DIM1Ch12
       << this->database->DICT_Mp2DI1I13MainFuseSta_B2 << this->database->DICT_Mp2DI1I14BowUpOK_B2 << this->database->DICT_Mp2DI1I15BowDownOK_B2 << this->database->DICT_Mp2DI1I16ADDBowDown_B2
       << this->database->DICT_Mp2DI1I17BowBreakerClosed_B2 << this->database->DICT_Mp2DI1I18BowUpPip_B2 << this->database->RIOM5_DIM1Ch19 << this->database->DICT_Mp2DI1I20AirExhaustM1_B2
       << this->database->DICT_Mp2DI1I21AirExhaustM2_B2 << this->database->RIOM5_DIM1Ch22 << this->database->RIOM5_DIM1Ch23 << this->database->RIOM5_DIM1Ch24;
      states.clear();
  // riom B1 di1
  states << this->database->DICT_Mp1DI1I1Bogie1Cut_B1 << this->database->DICT_Mp1DI1I2Bogie2Cut_B1 << this->database->DICT_Mp1DI1I3ParkingBrkCutOut_B1 << this->database->DICT_Mp1DI1I4LuminairePower1_B1
         << this->database->DICT_Mp1DI1I5LuminairePower2_B1 << this->database->DICT_Mp1DI1I6LuminairePower3_B1 << this->database->DICT_Mp1DI1I7LuminairePower4_B1 << this->database->DICT_Mp1DI1I8HeaterCh1_B1
         << this->database->DICT_Mp1DI1I9HeaterCh2_B1 << this->database->RIOM2_DIM1Ch10 << this->database->RIOM2_DIM1Ch11 << this->database->RIOM2_DIM1Ch12
         << this->database->DICT_Mp1DI1I13MainFuseSta_B1 << this->database->DICT_Mp1DI1I14BowUpOK_B1 << this->database->DICT_Mp1DI1I15BowDownOK_B1 << this->database->DICT_Mp1DI1I16ADDBowDown_B1
         << this->database->DICT_Mp1DI1I17BowBreakerClosed_B1 << this->database->DICT_Mp1DI1I18BowUpPip_B1 << this->database->RIOM2_DIM1Ch19 << this->database->DICT_Mp1DI1I20AirExhaustM1_B1
         << this->database->DICT_Mp1DI1I21AirExhaustM2_B1 << this->database->RIOM2_DIM1Ch22 << this->database->RIOM2_DIM1Ch23 << this->database->RIOM2_DIM1Ch24;
  states.clear();


  states << this->database->RIOM5_DOMIC1 << this->database->RIOM5_DOMIC2 << this->database->RIOM5_DOMIC3 << this->database->RIOM5_DOMIC4 << this->database->RIOM5_DOMIC5 << this->database->RIOM5_DOMIC6 << this->database->RIOM5_DOMIC7 << this->database->RIOM5_DOMIC8
         << this->database->RIOM5_DOMIC9 << this->database->RIOM5_DOMIC10 << this->database->RIOM5_DOMIC11 << this->database->RIOM5_DOMIC12 << this->database->RIOM5_DOMIC13 << this->database->RIOM5_DOMIC14 << this->database->RIOM5_DOMIC15 << this->database->RIOM5_DOMIC16;
  states.clear();
  states << this->database->RIOM5_DOMIC1 << this->database->RIOM5_DOMIC2 << this->database->RIOM5_DOMIC3 << this->database->RIOM5_DOMIC4 << this->database->RIOM5_DOMIC5 << this->database->RIOM5_DOMIC6 << this->database->RIOM5_DOMIC7 << this->database->RIOM5_DOMIC8
         << this->database->RIOM5_DOMIC9 << this->database->RIOM5_DOMIC10 << this->database->RIOM5_DOMIC11 << this->database->RIOM5_DOMIC12 << this->database->RIOM5_DOMIC13 << this->database->RIOM5_DOMIC14 << this->database->RIOM5_DOMIC15 << this->database->RIOM5_DOMIC16;
   states.clear();*/
}


/*
Author:zhumm
Name:updateDio
Function:update Dio table styleSheet recording to signals states
Variable:
    *table: the table which will change stylesheet
    &state: the list that stores the signals states
*/
void AllPorts::updateDio(QTableWidget *table,QList<bool> &state)
{

    int tableRow, tableColumn;
    for(int i = 0; i < state.length(); i++)
    {
        tableRow = i / 4;
        tableColumn = 3*(i % 4) + 2;

        if (state.at(i))
        {
            table->item(tableRow, tableColumn)->setTextAlignment(Qt::AlignLeft);
            table->item(tableRow, tableColumn)->setTextColor(QColor(0 ,0, 0));
            table->item(tableRow, tableColumn)->setBackgroundColor(QColor(0 ,255, 0));
            table->item(tableRow, tableColumn)->setText(QString("1"));
        }
        else
        {
            if(i % 2)
            {
                table->item(tableRow, tableColumn)->setTextColor(_WHITECOLOR);
                table->item(tableRow, tableColumn)->setBackgroundColor(QColor(0 ,0, 0));
            }
            else
            {
                table->item(tableRow, tableColumn)->setTextColor(_BLUECOLOR);
                table->item(tableRow, tableColumn)->setBackgroundColor(QColor(0 ,0, 0));
            }
            table->item(tableRow, tableColumn)->setText(QString("0"));
        }
    }
}

void AllPorts::updateAx(QTableWidget *table, QList<QString> &state)
{
    if (state.length() != AX_LENGTH)
    {
        _LOG << "the length ax not equal to" << AX_LENGTH;

        return;
    }
    int tableRow, tableColumn;

    for(int i = 0; i < state.length(); i++)
    {
        tableRow = i / 2;
        tableColumn = 3*(i % 2) + 2;        
        if(i % 2)
        {
            table->item(tableRow, tableColumn)->setTextColor(_WHITECOLOR);
            table->item(tableRow, tableColumn)->setBackgroundColor(QColor(0 ,0, 0));
        }
        else
        {
            table->item(tableRow, tableColumn)->setTextColor(_BLUECOLOR);
            table->item(tableRow, tableColumn)->setBackgroundColor(QColor(0 ,0, 0));
        }
        table->item(tableRow, tableColumn)->setText(state.at(i));
    }
}

void AllPorts::initialView()
{
    this->initialTableView(this->riomDI1InfoTable);
    this->initialTableView(this->riomDI2InfoTable);
    this->initialTableView(this->riomDI3InfoTable);
    this->initialTableView(this->riomDI4InfoTable);
    this->initialTableView(this->riomDO1InfoTable);
    this->initialTableView(this->riomAXInfoTable);

    this->hideAllTable();
    // set tables label
    ui->label_DI1->setText(QString("DI1"));
    ui->label_DI2->setText(QString("DI2"));
    ui->label_DI3->setText(QString("DI3"));
    ui->label_DI4->setText(QString("DI4"));
    ui->label_DO->setText(QString("DO"));
    ui->label_AX->setText(QString("AX"));
}


void AllPorts::initialTableView(QTableWidget *table)
{
    //table->setFont(font);
    table->horizontalHeader()->setVisible(false);
    table->verticalHeader()->setVisible(false);
    table->hide();
    table->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    table->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);

    for (int row = 0; row < table->rowCount(); row ++)
    {
        for (int column = 0; column < table->columnCount(); column ++)
        {
            QTableWidgetItem *tableItem = new QTableWidgetItem("");
            table->setItem(row, column, tableItem);
        }
    }

}


void AllPorts::updateButton(int currentVehicle)
{
     ui->btn_tc1->setStyleSheet(BUTTON_UP);
     ui->btn_mp1->setStyleSheet(BUTTON_UP);
     ui->btn_mp2->setStyleSheet(BUTTON_UP);
     ui->btn_tc2->setStyleSheet(BUTTON_UP);
     switch(currentVehicle)
     {
     case 0:
         ui->btn_tc1->setStyleSheet(BUTTON_DOWN);
         break;

     case 1:
         ui->btn_mp1->setStyleSheet(BUTTON_DOWN);
         break;

     case 2:
         ui->btn_mp2->setStyleSheet(BUTTON_DOWN);
         break;

     case 3:
         ui->btn_tc2->setStyleSheet(BUTTON_DOWN);
         break;
     }
}


