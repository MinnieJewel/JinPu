#include "riomdebug.h"
#include "ui_riomdebug.h"
#include "vehiclelogo.h"
#include <QDebug>
#include "global.h"

#define _FAULT ("background-color: red; border: 2px groove, gray; border-color: gray;")
#define _STOP ("background-color: black; border: 2px groove, gray; border-color: gray;")

RIOMDebug::RIOMDebug(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::RIOMDebug)
{
    this->vehicleLogo = new VehicleLogo(this);
    this->vehicleLogo->setGeometry(0, 10, this->vehicleLogo->width(), this->vehicleLogo->height());

    ui->setupUi(this);
    _LOG << "RIOMDebug constructor";
    QList<QString> rowsName ;
    rowsName << QString("DI1") << QString("DI2")<< QString("DI3") << QString("DI4") << QString("DO") << QString("AX");

    QList<QLabel *>labels;

    labels << ui->label_DI1 << ui->label_DI1 << ui->label_DI1 << ui->label_DI1 << ui->label_DI1 << ui->label_DI1;
    //this->lifeSignalsTable->setColumnWidth(0, 130);
    //initialLabel();

}

RIOMDebug::~RIOMDebug()
{
    delete ui;
}

void RIOMDebug::updatePage()
{
    this->vehicleLogo->updateVehicleState(this->database->CTHM_TC1Active, this->database->CTHM_TC2Active, this->database->CTHM_Forward, this->database->CTHM_Backward,
    this->database->CTHM_Mp1RIOMGWOn, this->database->CTHM_Mp2RIOMGWOn, this->database->RIOM3_DIM1Ch18, this->database->RIOM3_DIM1Ch19, this->database->RIOM4_DIM1Ch18,
    this->database->RIOM4_DIM1Ch19, this->database->DICT_Tc1DI1I15AllDoorClosed_A1 | this->database->DICT_Tc2DI1I15AllDoorClosed_A2);
    this->vehicleLogo->updateVehicleNo(this->database->lineNo, this->database->vehicleNo);
    this->vehicleLogo->updateHSCB(this->database->TR3CT_HSCBState, this->database->TR4CT_HSCBState);
    QList<QLabel *>lifeSignals;
    lifeSignals << ui->label_CAR1_DI1 << ui->label_CAR2_DI1 << ui->label_CAR3_DI1 << ui->label_CAR4_DI1 << ui->label_CAR1_DI2 << ui->label_CAR2_DI2 << ui->label_CAR3_DI2 << ui->label_CAR4_DI2
                << ui->label_CAR1_DI3 << ui->label_CAR2_DI3 << ui->label_CAR3_DI3 << ui->label_CAR4_DI3<< ui->label_CAR1_DI4 << ui->label_CAR2_DI4 << ui->label_CAR3_DI4 << ui->label_CAR4_DI4
                << ui->label_CAR1_DO << ui->label_CAR2_DO << ui->label_CAR3_DO << ui->label_CAR4_DO << ui->label_CAR1_AX << ui->label_CAR2_AX << ui->label_CAR3_AX << ui->label_CAR4_AX
                << ui->label_CAR1_GW << ui->label_CAR2_GW << ui->label_CAR3_GW << ui->label_CAR4_GW << ui->label_CAR1_LAT << ui->label_CAR2_LAT << ui->label_CAR3_LAT << ui->label_CAR4_LAT
                << ui->label_CAR1_RLD << ui->label_CAR2_RLD << ui->label_CAR3_RLD << ui->label_CAR4_RLD;


QList<QString> lifeSignalsList;

lifeSignalsList << QString::number(this->database->DICT_RIOMTc1LfSignDI1_A1) << QString::number(this->database->DICT_RIOMMp1LfSignDI1_A1) << QString::number(this->database->DICT_RIOMMp2LfSignDI1_A2) << QString::number(this->database->DICT_RIOMTc2LfSignDI1_A2)
                << QString::number(this->database->DICT_RIOMTc1LfSignDI2_A1) << QString("--") << QString("--") << QString::number(this->database->DICT_RIOMTc2LfSignDI2_A2)
                << QString::number(this->database->DICT_RIOMTc1LfSignDI3_A1) << QString("--") << QString("--") << QString::number(this->database->DICT_RIOMTc2LfSignDI3_A2)
                << QString::number(this->database->DICT_RIOMTc1LfSignDI4_A1) << QString("--") << QString("--") << QString::number(this->database->DICT_RIOMTc2LfSignDI4_A2)
                << QString::number(this->database->DOCT_RIOMTc1LfSignDO1_A1) << QString::number(this->database->DOCT_RIOMMp1LfSignDO1_A1) << QString::number(this->database->DOCT_RIOMMp2LfSignDO1_A2) << QString::number(this->database->DOCT_RIOMTc2LfSignDO1_A2)
                << QString::number(this->database->AICT_RIOMTc1LfSignAX1_A1) << QString("--") << QString("--") << QString::number(this->database->AICT_RIOMTc2LfSignAX1_A2)
                << QString::number(this->database->GWCT_RIOMTc1GWLfSign_A1) << QString::number(this->database->GWCT_RIOMMp1GWLfSign_A1) << QString::number(this->database->GWCT_RIOMMp2GWLfSign_A2) << QString::number(this->database->GWCT_RIOMTc2GWLfSign_A2)
                << QString::number(this->database->GWCT_RIOMTc1LAT_A1) << QString::number(this->database->GWCT_RIOMMp1LAT_A1) << QString::number(this->database->GWCT_RIOMMp2LAT_A2) << QString::number(this->database->GWCT_RIOMTc2LAT_A2);

this->RLDState(ui->label_CAR1_RLD, this->database->GWCT_RIOMTc1RLD_A1);
this->RLDState(ui->label_CAR2_RLD, this->database->GWCT_RIOMMp1RLD_A1);
this->RLDState(ui->label_CAR3_RLD, this->database->GWCT_RIOMMp2RLD_A2);
this->RLDState(ui->label_CAR4_RLD, this->database->GWCT_RIOMTc2RLD_A2);

    for(int signalListSize = 0; signalListSize < lifeSignalsList.size(); signalListSize++)
    {
        lifeSignals.at(signalListSize)->setText(lifeSignalsList[signalListSize]);
    }

    lifeSignalsList.clear();
}

void RIOMDebug::on_btn_back_clicked()
{
    emit this->changePage(uDebugPage);
}

void RIOMDebug::RLDState(QLabel *label, bool state)
{
    label->setText(QString::number(state));
    if (state)
    {
        label->setStyleSheet(_FAULT);
    }
    else
    {
        label->setStyleSheet(_STOP);
    }
}
