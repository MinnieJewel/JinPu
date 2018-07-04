#include "lifesignals.h"
#include "ui_lifesignals.h"
#include "vehiclelogo.h"
#include <QDebug>
#include "global.h"

LifeSignals::LifeSignals(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::LifeSignals)
{
    ui->setupUi(this);
     _LOG << "LifeSignals constructor";
    this->vehicleLogo = new VehicleLogo(this);
    this->vehicleLogo->setGeometry(0, 10, this->vehicleLogo->width(), this->vehicleLogo->height());
    QList<QString> rowsName ;
    rowsName << QString("CCU") << QString("ERM")<< QString("IO-GW") << QString("BCU") << QString("DCU") << QString("EDCU") << QString("HVAC")
             << QString("PIS") << QString("FAU") << QString("ATC") << QString("HMI") << QString("PDS") << QString("SIV") << QString("BCG");

    QList<QLabel *>labels;
    this->hmi1Lfsign = 0;
    this->hmi2Lfsign = 0;

    labels << ui->label_CCU << ui->label_ERM << ui->label_IOGW << ui->label_BCU << ui->label_DCU << ui->label_EDCU << ui->label_HVAC
           << ui->label_PIS << ui->label_FAU << ui->label_ATC << ui->label_HMI << ui->label_PDS << ui->label_SIV << ui->label_BCG;
    //this->lifeSignalsTable->setColumnWidth(0, 130);
    //initialLabel();

   }

LifeSignals::~LifeSignals()
{
    delete ui;
}


void LifeSignals::updatePage()
{
    this->vehicleLogo->updateVehicleState(this->database->CTHM_TC1Active, this->database->CTHM_TC2Active, this->database->CTHM_Forward, this->database->CTHM_Backward,
    this->database->CTHM_Mp1RIOMGWOn, this->database->CTHM_Mp2RIOMGWOn, this->database->RIOM3_DIM1Ch18, this->database->RIOM3_DIM1Ch19, this->database->RIOM4_DIM1Ch18,
    this->database->RIOM4_DIM1Ch19, this->database->DICT_Tc1DI1I15AllDoorClosed_A1 | this->database->DICT_Tc2DI1I15AllDoorClosed_A2);
    this->vehicleLogo->updateVehicleNo(this->database->lineNo, this->database->vehicleNo);
    this->vehicleLogo->updateHSCB(this->database->TR3CT_HSCBState, this->database->TR4CT_HSCBState);
    QList<QLabel *>lifeSignals;
    lifeSignals << ui->label_CCU1
                << ui->label_ERM1 << ui->label_ERM2 << ui->label_ERM3 << ui->label_ERM4
                << ui->label_IOGW1 << ui->label_IOGW2 << ui->label_IOGW3 << ui->label_IOGW4 << ui->label_BCU1 << ui->label_BCU2 << ui->label_BCU3 << ui->label_BCU4
                << ui->label_DCU1 << ui->label_DCU2_1 << ui->label_DCU2_2 << ui->label_DCU2_3 << ui->label_DCU2_4<< ui->label_DCU3_1 << ui->label_DCU3_2 << ui->label_DCU3_3 << ui->label_DCU3_4 <<ui->label_DCU4
                << ui->label_car1EDCU1 << ui->label_car1EDCU2 << ui->label_car2EDCU1 << ui->label_car2EDCU2 << ui->label_car3EDCU1 << ui->label_car3EDCU2 << ui->label_car4EDCU1 << ui->label_car4EDCU2
                << ui->label_HVAC1 << ui->label_HVAC2 << ui->label_HVAC3 << ui->label_HVAC4 << ui->label_PIS1 << ui->label_PIS2 << ui->label_PIS3 << ui->label_PIS4
                << ui->label_FAU1 << ui->label_FAU2 << ui->label_FAU3 << ui->label_FAU4 << ui->label_ATC1 << ui->label_ATC2 << ui->label_ATC3 << ui->label_ATC4
                << ui->label_HMI1 << ui->label_HMI2 << ui->label_HMI3 << ui->label_HMI4 << ui->label_PDS1 << ui->label_PDS2 << ui->label_PDS3 << ui->label_PDS4
                << ui->label_SIV1 << ui->label_SIV2 << ui->label_SIV3 << ui->label_SIV4 << ui->label_SIVGW1 << ui->label_SIVGW2 << ui->label_SIVGW3 << ui->label_SIVGW4
                << ui->label_BCG1 << ui->label_BCG2 << ui->label_BCG3 << ui->label_BCG4;

    QList<QString> lifeSignalsList;

    if(1 == this->database->hmiPosition)
    {
        this->hmi1Lfsign = this->database->hmiLifeSignal;
        this->hmi2Lfsign = this->database->HM2CT_LifeSignal_A2;
    }
    else if(2 == this->database->hmiPosition)
    {
        this->hmi1Lfsign = this->database->HM1CT_LifeSignal_A1;
        this->hmi2Lfsign = this->database->hmiLifeSignal;
    }

    lifeSignalsList << QString::number(this->database->PUBPORT_TMSLifeSignal)
            << QString::number(this->database->DT1CT_ERMLfSginal_A1) << QString("--") << QString("--") << QString::number(this->database->DT6CT_ERMLfSginal_A2)
            << QString::number(this->database->GWCT_RIOMTc1GWLfSign_A1) << QString::number(this->database->GWCT_RIOMMp1GWLfSign_A1)
            << QString::number(this->database->GWCT_RIOMMp2GWLfSign_A2) << QString::number(this->database->GWCT_RIOMTc2GWLfSign_A2)
            //BCU
            << QString::number(this->database->BR1CT_LfSgn_A1) << QString::number(this->database->BR3CT_LfSgn_Mp1)
            << QString::number(this->database->BR4CT_LfSgn_Mp2) << QString::number(this->database->BR6CT_LfSgn_A2)
            //DCU
            << QString("--")
            << QString::number(this->database->TR3CT_T1LifeSignal) << QString::number(this->database->TR3CT_T2LifeSignal)
            << QString::number(this->database->TR3CT_T3LifeSignal) << QString::number(this->database->TR3CT_T4LifeSignal)
            << QString::number(this->database->TR4CT_T1LifeSignal) << QString::number(this->database->TR4CT_T2LifeSignal)
            << QString::number(this->database->TR4CT_T3LifeSignal) << QString::number(this->database->TR4CT_T4LifeSignal)
            << QString("--")
            //EDCU
            << QString::number(this->database->DR1CT_LifeSign) << QString::number(this->database->DR2CT_LifeSign)
            << QString::number(this->database->DR5CT_LifeSign) << QString::number(this->database->DR6CT_LifeSign)
            << QString::number(this->database->DR7CT_LifeSign) << QString::number(this->database->DR8CT_LifeSign)
            << QString::number(this->database->DRBCT_LifeSign) << QString::number(this->database->DRCCT_LifeSign)

            //HVAC
            << QString::number(this->database->AC1CT_Lifesignal) << QString::number(this->database->AC3CT_Lifesignal)
            << QString::number(this->database->AC4CT_Lifesignal) << QString::number(this->database->AC6CT_Lifesignal)

            //PIS
            << QString::number(this->database->PA1CT_LifeSignal) << QString("--") << QString("--") << QString::number(this->database->PA2CT_LifeSignal)
            //FAU
            << QString::number(this->database->FA1CT_Lifesignal) << QString("--") << QString("--") << QString::number(this->database->FA2CT_Lifesignal)
            //ATC
            << QString::number(this->database->AT1CT_LfSign) << QString("--") << QString("--") << QString::number(this->database->AT2CT_LfSign)
            //HMI
            << QString::number(this->hmi1Lfsign) << QString("--") << QString("--") << QString::number(this->hmi2Lfsign)
            //PDS
            << QString::number(this->database->PDS1CT_LfSign) << QString("--") << QString("--") << QString::number(this->database->PDS2CT_LfSign)
            //SIV
            << QString::number(this->database->AX1CT_LifeSignal) << QString("--") << QString("--") << QString::number(this->database->AX2CT_LifeSignal)
            << QString::number(this->database->AX1CT_GWLifeSig) << QString("--") << QString("--") << QString::number(this->database->AX2CT_GWLifeSig)
            //BCG
            << QString::number(this->database->BC1CT_LifeSignal) << QString("--") << QString("--") << QString::number(this->database->BC2CT_LifeSignal);

    for(int signalListSize = 0; signalListSize < lifeSignalsList.size(); signalListSize++)
    {
        lifeSignals.at(signalListSize)->setText(lifeSignalsList[signalListSize]);
    }

    lifeSignalsList.clear();
}

void LifeSignals::on_btn_back_clicked()
{
    emit this->changePage(uDebugPage);
}
