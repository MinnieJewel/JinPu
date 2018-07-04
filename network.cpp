#include "network.h"
#include "ui_network.h"
#include <stdlib.h>
#include <QTimer>
#include <QLabel>
#include <QPushButton>
#include <QPainter>
#include <QDebug>
#include "global.h"
#include "vehiclelogo.h"
#include "crrcfault.h"

#define _ONLINE ("font: 15px; color: rgb(0,0,0); background-color: green; border: 0px;")
#define _OFFLINE ("font: 15px; color: rgb(0,0,0); background-color: gray; border: 1px groove, black;")
#define _SLAVE_ONLINE ("font: 15px; color: rgb(0,0,0); background-color: yellow; border: 0px;")
#define _FAULT ("background-color: red; border: 1px groove, black;")

enum doorMaster
{
    Master1 = 1,
    Master2
};

NetWork::NetWork(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::NetWork)
{
    ui->setupUi(this);
    _LOG << "NetWork constructor";
    this->vehicleLogo = new VehicleLogo(this);
    this->vehicleLogo->setGeometry(0, 10, this->vehicleLogo->width(), this->vehicleLogo->height());
    this->labels.append(ui->label_door11);
    this->labels.append(ui->label_door12);
    this->labels.append(ui->label_door13);
    this->labels.append(ui->label_door14);
    this->labels.append(ui->label_door15);
    this->labels.append(ui->label_door16);
    this->labels.append(ui->label_door17);
    this->labels.append(ui->label_door18);
    this->labels.append(ui->label_door21);
    this->labels.append(ui->label_door22);
    this->labels.append(ui->label_door23);
    this->labels.append(ui->label_door24);
    this->labels.append(ui->label_door25);
    this->labels.append(ui->label_door26);
    this->labels.append(ui->label_door27);
    this->labels.append(ui->label_door28);
    this->labels.append(ui->label_door31);
    this->labels.append(ui->label_door32);
    this->labels.append(ui->label_door33);
    this->labels.append(ui->label_door34);
    this->labels.append(ui->label_door35);
    this->labels.append(ui->label_door36);
    this->labels.append(ui->label_door37);
    this->labels.append(ui->label_door38);
    this->labels.append(ui->label_door41);
    this->labels.append(ui->label_door42);
    this->labels.append(ui->label_door43);
    this->labels.append(ui->label_door44);
    this->labels.append(ui->label_door45);
    this->labels.append(ui->label_door46);
    this->labels.append(ui->label_door47);
    this->labels.append(ui->label_door48);
}

NetWork::~NetWork()
{
    delete ui;
}

void NetWork::installCrrcFault(CrrcFault *crrcFault)
{
    this->crrcFault = crrcFault;
}
void NetWork::paintEvent(QPaintEvent *)
{
    QPainter paint(this);
    QPen pen;
    pen.setWidth(6);
    pen.setColor(QColor(70,119,191));
    paint.setPen(pen);
    //rpt line
    static const QPointF points[4] = {QPointF(150.0,150.0), QPointF(150.0,100),QPointF(875.0,100), QPointF(875.0,150.0)};
    paint.drawPolyline(points, 4);
	
        paint.drawLine(QPointF(363,150.0),QPointF(363,100));
        paint.drawLine(QPointF(665,150.0),QPointF(665,100));

    //tc1 main line
    static const QPointF pointTc1[2] = {QPointF(150.0,173.0), QPointF(150.0,560.0)};
    paint.drawPolyline(pointTc1, 2);
    // draw equiptment lines
         paint.drawLine(113,210,187,210);
         paint.drawLine(113,260,187,260);
         paint.drawLine(113,310,187,310);
         paint.drawLine(113,360,187,360);
         paint.drawLine(113,410,187,410);
         paint.drawLine(113,460,187,460);
         paint.drawLine(113,510,187,510);
         paint.drawLine(134,560,187,560);
	 
    //mp1 main line
    static const QPointF pointMp1[3] = {QPointF(363.0,173.0), QPointF(363.0,523.0),QPointF(382.0,523.0)};
    paint.drawPolyline(pointMp1, 3);
	 //draw equiptment lines
         paint.drawLine(363,210,400,210);
         paint.drawLine(363,260,400,260);
         paint.drawLine(363,310,400,310);
         paint.drawLine(363,360,400,360);
         paint.drawLine(363,410,400,410);
         paint.drawLine(363,460,400,460);


     //mp2 main line
     static const QPointF pointMp2[3] = {QPointF(665.0,173.0), QPointF(665.0,523.0),QPointF(649.0,523.0)};
     paint.drawPolyline(pointMp2, 3);
	 //draw equiptment lines 
         paint.drawLine(625,210,665,210);
         paint.drawLine(625,260,665,260);
         paint.drawLine(625,310,665,310);
         paint.drawLine(625,360,665,360);
         paint.drawLine(625,410,665,410);
         paint.drawLine(625,460,665,460);

     //tc2 main line
     static const QPointF pointTc2[2] = {QPointF(875.0,173.0), QPointF(875.0,560.0)};
     paint.drawPolyline(pointTc2, 2);
	 //draw equiptment lines
         paint.drawLine(836,210,907,210);
         paint.drawLine(836,260,907,260);
         paint.drawLine(836,310,907,310);
         paint.drawLine(836,360,907,360);
         paint.drawLine(836,410,907,410);
         paint.drawLine(836,460,907,460);
         paint.drawLine(836,510,907,510);
         paint.drawLine(836,560,892,560);
    //paint.drawLine();
}


void NetWork::updatePage()
{
    this->vehicleLogo->updateVehicleState(this->database->CTHM_TC1Active, this->database->CTHM_TC2Active, this->database->CTHM_Forward, this->database->CTHM_Backward,
    this->database->CTHM_Mp1RIOMGWOn, this->database->CTHM_Mp2RIOMGWOn, this->database->RIOM3_DIM1Ch18, this->database->RIOM3_DIM1Ch19, this->database->RIOM4_DIM1Ch18,
    this->database->RIOM4_DIM1Ch19, this->database->DICT_Tc1DI1I15AllDoorClosed_A1 | this->database->DICT_Tc2DI1I15AllDoorClosed_A2);
    this->vehicleLogo->updateVehicleNo(this->database->lineNo, this->database->vehicleNo);
    this->vehicleLogo->updateHSCB(this->database->TR3CT_HSCBState, this->database->TR4CT_HSCBState);
    if (1 == this->database->hmiPosition)
    {
        this->setDeviceState(ui->hmi1, true, false);
        this->setDeviceState(ui->hmi2, this->database->CTHM_HMI2On, false);
    }

    else if (2 == this->database->hmiPosition)
    {
        this->setDeviceState(ui->hmi1, this->database->CTHM_HMI1On, false);
        this->setDeviceState(ui->hmi2, true, false);
    }
    this->setDeviceState(ui->rpt1, this->database->CTHM_TC1RIOMGWOn, false);
    this->setDeviceState(ui->rpt2, this->database->CTHM_Mp1RIOMGWOn, false);
    this->setDeviceState(ui->rpt3, this->database->CTHM_Mp2RIOMGWOn, false);
    this->setDeviceState(ui->rpt4, this->database->CTHM_TC2RIOMGWOn, false);
    this->setDeviceStateMaster(ui->ccu1, this->database->CTHM_CCU1On && this->database->hmiCcuOnlineState, this->database->CTHM_CCU1Active, false);
    this->setDeviceStateMaster(ui->ccu2, this->database->CTHM_CCU2On && this->database->hmiCcuOnlineState, this->database->CTHM_CCU2Active, false);
    this->setDeviceState(ui->erm1, this->database->CTHM_ERM1On, false);
    this->setDeviceState(ui->erm2, this->database->CTHM_ERM2On, false);
    this->setDeviceState(ui->edcu1, this->database->CTHM_EDCU1On, this->crrcFault->deviceFault("TC1", "EDCU"));
    this->setDeviceState(ui->edcu2, this->database->CTHM_EDCU2On, this->crrcFault->deviceFault("TC1", "EDCU"));
    this->setDeviceState(ui->edcu3, this->database->CTHM_EDCU5On, this->crrcFault->deviceFault("MP1", "EDCU"));
    this->setDeviceState(ui->edcu4, this->database->CTHM_EDCU6On, this->crrcFault->deviceFault("MP1", "EDCU"));
    this->setDeviceState(ui->edcu5, this->database->CTHM_EDCU7On, this->crrcFault->deviceFault("MP2", "EDCU"));
    this->setDeviceState(ui->edcu6, this->database->CTHM_EDCU8On, this->crrcFault->deviceFault("MP2", "EDCU"));
    this->setDeviceState(ui->edcu7, this->database->CTHM_EDCU11On, this->crrcFault->deviceFault("TC2", "EDCU"));
    this->setDeviceState(ui->edcu8, this->database->CTHM_EDCU12On, this->crrcFault->deviceFault("TC2", "EDCU"));
    this->setDeviceStateMaster(ui->atc1, this->database->CTHM_ATC1On, this->database->CTHM_ATC1Active, this->crrcFault->deviceFault("TC1", "ATO"));
    this->setDeviceStateMaster(ui->atc2, this->database->CTHM_ATC2On, this->database->CTHM_ATC2Active, this->crrcFault->deviceFault("TC2", "ATO"));
    this->setDeviceState(ui->bcg1, this->database->CTHM_BCG1On, this->crrcFault->deviceFault("TCMS", "BCG"));
    this->setDeviceState(ui->bcg2, this->database->CTHM_BCG2On, this->crrcFault->deviceFault("TCMS", "BCG"));
    this->setDeviceState(ui->riom1, this->database->CTHM_TC1RIOMGWOn, false);
    this->setDeviceState(ui->riom2, this->database->CTHM_Mp1RIOMGWOn, false);
    this->setDeviceState(ui->riom3, this->database->CTHM_Mp2RIOMGWOn, false);
    this->setDeviceState(ui->riom4, this->database->CTHM_TC2RIOMGWOn, false);
    this->setDeviceState(ui->HVAC1, this->database->CTHM_Tc1HVACOn, this->crrcFault->deviceFault("TC1", "HVAC"));
    this->setDeviceState(ui->HVAC2, this->database->CTHM_Mp1HVACOn, this->crrcFault->deviceFault("MP1", "HVAC"));
    this->setDeviceState(ui->HVAC3, this->database->CTHM_Mp2HVACOn, this->crrcFault->deviceFault("MP2", "HVAC"));
    this->setDeviceState(ui->HVAC4, this->database->CTHM_Tc2HVACOn, this->crrcFault->deviceFault("TC2", "HVAC"));
    this->setDeviceStateMaster(ui->pis1, this->database->CTHM_PIS1On, this->database->PA1CT_MasterActive, this->crrcFault->deviceFault("TC1", "PIS"));
    this->setDeviceStateMaster(ui->pis2, this->database->CTHM_PIS2On, this->database->PA2CT_MasterActive, this->crrcFault->deviceFault("TC2", "PIS"));
    this->setDeviceState(ui->fau1, this->database->CTHM_FAU1On, this->crrcFault->deviceFault("TC1", "FAU") || this->crrcFault->deviceFault("MP1", "FAU")
                                                                || this->crrcFault->deviceFault("MP2", "FAU") || this->crrcFault->deviceFault("TC2", "FAU"));
    this->setDeviceState(ui->fau2, this->database->CTHM_FAU2On, this->crrcFault->deviceFault("TC1", "FAU") || this->crrcFault->deviceFault("MP1", "FAU")
                                                                || this->crrcFault->deviceFault("MP2", "FAU") || this->crrcFault->deviceFault("TC2", "FAU"));
    this->setDeviceStateMaster(ui->bcu1, this->database->CTHM_Tc1BCUOn, this->database->BR1CT_MstrBCU, this->crrcFault->deviceFault("TC1", "BCU") || this->crrcFault->deviceFault("MP1", "BCU"));
    this->setDeviceStateMaster(ui->bcu2, this->database->CTHM_Mp1BCUOn, this->database->BR3CT_MstrBCU_Mp1, this->crrcFault->deviceFault("TC1", "BCU") || this->crrcFault->deviceFault("MP1", "BCU"));
    this->setDeviceStateMaster(ui->bcu3, this->database->CTHM_Mp2BCUOn, this->database->BR4CT_MstrBCU_Mp2, this->crrcFault->deviceFault("TC2", "BCU") || this->crrcFault->deviceFault("MP2", "BCU"));
    this->setDeviceStateMaster(ui->bcu4, this->database->CTHM_Tc2BCUOn, this->database->BR6CT_MstrBCU_A2, this->crrcFault->deviceFault("TC2", "BCU") || this->crrcFault->deviceFault("MP2", "BCU"));
    this->setDeviceState(ui->siv1, this->database->CTHM_SIV1On, this->crrcFault->deviceFault("TC1", "SIV"));
    this->setDeviceState(ui->siv2, this->database->CTHM_SIV2On, this->crrcFault->deviceFault("TC2","SIV"));
    this->setDeviceState(ui->dcu1, this->database->CTHM_Mp1DCUOn, this->crrcFault->deviceFault("MP1", "TCU"));
    this->setDeviceState(ui->dcu2, this->database->CTHM_Mp2DCUOn, this->crrcFault->deviceFault("MP2", "TCU"));
    this->setDeviceState(ui->BMS1, this->database->CTHM_BMS1On, this->crrcFault->deviceFault("TC1", "BMS"));
    this->setDeviceState(ui->BMS2, this->database->CTHM_BMS2On, this->crrcFault->deviceFault("TC2", "BMS"));
    this->setDeviceState(ui->PDS1, this->database->CTHM_PDS1On, false);
    this->setDeviceState(ui->PDS2, this->database->CTHM_PDS2On, false);
    // doors
    if (this->labels.size() != 32)
    {
        _LOG << "doors label list in fault size";
        return;
    }
    for(int door1Counter = 0; door1Counter < 8; door1Counter++)
    {
        this->setDeviceState(this->labels[door1Counter], ((Master1 == this->database->doorsOnLine1[door1Counter]) && this->database->CTHM_EDCU1On)
                                             || ((Master2 == this->database->doorsOnLine1[door1Counter]) && this->database->CTHM_EDCU2On)
                                             || (this->database->CTHM_EDCU1On && this->database->CTHM_EDCU2On), false);

        this->setDeviceState(this->labels[door1Counter + 8], ((Master1 == this->database->doorsOnLine3[door1Counter]) && this->database->CTHM_EDCU5On)
                                             || ((Master2 == this->database->doorsOnLine3[door1Counter]) && this->database->CTHM_EDCU6On)
                                             || (this->database->CTHM_EDCU5On && this->database->CTHM_EDCU6On), false);

        this->setDeviceState(this->labels[door1Counter + 2 * 8], ((Master1 == this->database->doorsOnLine4[door1Counter]) && this->database->CTHM_EDCU7On)
                                             || ((Master2 == this->database->doorsOnLine4[door1Counter]) && this->database->CTHM_EDCU8On)
                                             || (this->database->CTHM_EDCU7On && this->database->CTHM_EDCU8On), false);

        this->setDeviceState(this->labels[door1Counter + 3 * 8], ((Master1 == this->database->doorsOnLine6[door1Counter]) && this->database->CTHM_EDCU11On)
                                             || ((Master2 == this->database->doorsOnLine6[door1Counter]) && this->database->CTHM_EDCU12On)
                                             || (this->database->CTHM_EDCU11On && this->database->CTHM_EDCU12On), false);
    }
}

void NetWork::setDeviceState(QLabel *label, bool state, bool faultState)
{
    if (!state)
    {
        label->setStyleSheet(_OFFLINE);
    }
    else if (faultState)
    {
        label->setStyleSheet(_FAULT);
    }
    else
    {
        label->setStyleSheet(_ONLINE);
    }
}


void NetWork::setDeviceStateMaster(QLabel *label, bool state, bool master, bool faultState)
{
    if (!state)
    {
        label->setStyleSheet(_OFFLINE);
    }
    else if (faultState)
    {
        label->setStyleSheet(_FAULT);
    }
    else if (state && master)
    {
        label->setStyleSheet(_ONLINE);
    }
    else if (state && !master)
    {
        label->setStyleSheet(_SLAVE_ONLINE);
    }
}

void NetWork::showEvent(QShowEvent *)
{
}
