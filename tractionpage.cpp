#include "tractionpage.h"
#include "ui_tractionpage.h"
#include "vehiclelogo.h"
#include <QDebug>
#include "global.h"

#define _OFFLINE ("background-color: white; border: 2px groove, gray; border-color: gray;")
#define _CUT ("image: url(:/image/cut.png); border: 2px groove, gray; border-color: gray;")
#define _STOP ("background-color: black; border: 2px groove, gray; border-color: gray;")
#define _FAULT ("background-color: red; border: 2px groove, gray; border-color: gray;")
#define _RUN ("background-color: rgb(0, 255, 0); border: 2px groove, gray; border-color: gray;")
#define _BRAKE ("background-color: rgb(153,0,51); border: 2px groove, gray; border-color: gray;")
#define _BRAKEDECREASE ("image: url(:/image/lower.png); border: 2px groove, gray; border-color: gray;")
#define _BRAKESLIDE ("image: url(:/image/slide.png); border: 2px groove, gray; border-color: gray;")

TractionPage::TractionPage(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::TractionPage)
{
    ui->setupUi(this);
    _LOG << "TractionPage constructor";
    this->vehicleLogo = new VehicleLogo(this);
    this->vehicleLogo->setGeometry(0, 10, this->vehicleLogo->width(), this->vehicleLogo->height());
    this->tractionStates << false << false << false << false << false << false << false << false;
}

TractionPage::~TractionPage()
{
    delete ui;
}
void TractionPage::updatePage()
{
    this->vehicleLogo->updateVehicleState(this->database->CTHM_TC1Active, this->database->CTHM_TC2Active, this->database->CTHM_Forward, this->database->CTHM_Backward,
    this->database->CTHM_Mp1RIOMGWOn, this->database->CTHM_Mp2RIOMGWOn, this->database->RIOM3_DIM1Ch18, this->database->RIOM3_DIM1Ch19, this->database->RIOM4_DIM1Ch18,
    this->database->RIOM4_DIM1Ch19, this->database->DICT_Tc1DI1I15AllDoorClosed_A1 | this->database->DICT_Tc2DI1I15AllDoorClosed_A2);
    this->vehicleLogo->updateVehicleNo(this->database->lineNo, this->database->vehicleNo);
    this->vehicleLogo->updateHSCB(this->database->TR3CT_HSCBState, this->database->TR4CT_HSCBState);
    //TCU1-1
    this->tractionStates[0] = this->database->TR3CT_T1RadOverTemp || this->database->TR3CT_T1HSCBNotClosed || this->database->TR3CT_T1LB1NotClosed || this->database->TR3CT_T1LB2NotClosed
                     || this->database->TR3CT_T1OverCurrent || this->database->TR3CT_T1OverSpeed || this->database->TR3CT_T1TMCSFault || this->database->TR3CT_T1LineOverVolt
                     || this->database->TR3CT_T1InverterOverCur || this->database->TR3CT_T1NetOverCur || this->database->TR3CT_T1NetOverVolt || this->database->TR3CT_T1OverTime
                     || this->database->TR3CT_T1ChargeFault || this->database->TR3CT_T1DriverFlt || this->database->TR3CT_T1MotorOverTem || this->database->TR3CT_T1DirectionFlt
                     || this->database->TR3CT_T1InstructionFlt || this->database->TR3CT_T1OverCurU || this->database->TR3CT_T1OverCurV || this->database->TR3CT_T1SpeedSensorFlt
                     || this->database->TR3CT_T1BrkNotRealesed || this->database->TR3CT_T1LineOverVoltSet || this->database->TR3CT_T1LineOverCur || this->database->TR3CT_T1DriverFltU
                     || this->database->TR3CT_T1DriverFltV || this->database->TR3CT_T1DriverFltW || this->database->TR3CT_T1PhaseLess || this->database->TR3CT_T1NetUnderVolt;

    //TCU1-2
    this->tractionStates[1] = this->database->TR3CT_T2RadOverTemp || this->database->TR3CT_T2HSCBNotClosed || this->database->TR3CT_T2LB1NotClosed || this->database->TR3CT_T2LB2NotClosed
                     || this->database->TR3CT_T2OverCurrent || this->database->TR3CT_T2OverSpeed || this->database->TR3CT_T2TMCSFault || this->database->TR3CT_T2LineOverVolt
                     || this->database->TR3CT_T2InverterOverCur || this->database->TR3CT_T2NetOverCur || this->database->TR3CT_T2NetOverVolt || this->database->TR3CT_T2OverTime
                     || this->database->TR3CT_T2ChargeFault || this->database->TR3CT_T2DriverFlt || this->database->TR3CT_T2MotorOverTem || this->database->TR3CT_T2DirectionFlt
                     || this->database->TR3CT_T2InstructionFlt || this->database->TR3CT_T2OverCurU || this->database->TR3CT_T2OverCurV || this->database->TR3CT_T2SpeedSensorFlt
                     || this->database->TR3CT_T2BrkNotRealesed || this->database->TR3CT_T2LineOverVoltSet || this->database->TR3CT_T2LineOverCur || this->database->TR3CT_T2DriverFltU
                     || this->database->TR3CT_T2DriverFltV || this->database->TR3CT_T2DriverFltW || this->database->TR3CT_T2PhaseLess || this->database->TR3CT_T2NetUnderVolt;

    //TCU1-3
    this->tractionStates[2] = this->database->TR3CT_T3RadOverTemp || this->database->TR3CT_T3HSCBNotClosed || this->database->TR3CT_T3LB1NotClosed || this->database->TR3CT_T3LB2NotClosed
                     || this->database->TR3CT_T3OverCurrent || this->database->TR3CT_T3OverSpeed || this->database->TR3CT_T3TMCSFault || this->database->TR3CT_T3LineOverVolt
                     || this->database->TR3CT_T3InverterOverCur || this->database->TR3CT_T3NetOverCur || this->database->TR3CT_T3NetOverVolt || this->database->TR3CT_T3OverTime
                     || this->database->TR3CT_T3ChargeFault || this->database->TR3CT_T3DriverFlt || this->database->TR3CT_T3MotorOverTem || this->database->TR3CT_T3DirectionFlt
                     || this->database->TR3CT_T3InstructionFlt || this->database->TR3CT_T3OverCurU || this->database->TR3CT_T3OverCurV || this->database->TR3CT_T3SpeedSensorFlt
                     || this->database->TR3CT_T3BrkNotRealesed || this->database->TR3CT_T3LineOverVoltSet || this->database->TR3CT_T3LineOverCur || this->database->TR3CT_T3DriverFltU
                     || this->database->TR3CT_T3DriverFltV || this->database->TR3CT_T3DriverFltW || this->database->TR3CT_T3PhaseLess || this->database->TR3CT_T3NetUnderVolt;

    //TCU1-4
    this->tractionStates[3] = this->database->TR3CT_T4RadOverTemp || this->database->TR3CT_T4HSCBNotClosed || this->database->TR3CT_T4LB1NotClosed || this->database->TR3CT_T4LB2NotClosed
                     || this->database->TR3CT_T4OverCurrent || this->database->TR3CT_T4OverSpeed || this->database->TR3CT_T4TMCSFault || this->database->TR3CT_T4LineOverVolt
                     || this->database->TR3CT_T4InverterOverCur || this->database->TR3CT_T4NetOverCur || this->database->TR3CT_T4NetOverVolt || this->database->TR3CT_T4OverTime
                     || this->database->TR3CT_T4ChargeFault || this->database->TR3CT_T4DriverFlt || this->database->TR3CT_T4MotorOverTem || this->database->TR3CT_T4DirectionFlt
                     || this->database->TR3CT_T4InstructionFlt || this->database->TR3CT_T4OverCurU || this->database->TR3CT_T4OverCurV || this->database->TR3CT_T4SpeedSensorFlt
                     || this->database->TR3CT_T4BrkNotRealesed || this->database->TR3CT_T4LineOverVoltSet || this->database->TR3CT_T4LineOverCur || this->database->TR3CT_T4DriverFltU
                     || this->database->TR3CT_T4DriverFltV || this->database->TR3CT_T4DriverFltW || this->database->TR3CT_T4PhaseLess || this->database->TR3CT_T4NetUnderVolt;

    //TCU2-1
    this->tractionStates[4] = this->database->TR4CT_T1RadOverTemp || this->database->TR4CT_T1HSCBNotClosed || this->database->TR4CT_T1LB1NotClosed || this->database->TR4CT_T1LB2NotClosed
                     || this->database->TR4CT_T1OverCurrent || this->database->TR4CT_T1OverSpeed || this->database->TR4CT_T1TMCSFault || this->database->TR4CT_T1LineOverVolt
                     || this->database->TR4CT_T1InverterOverCur || this->database->TR4CT_T1NetOverCur || this->database->TR4CT_T1NetOverVolt || this->database->TR4CT_T1OverTime
                     || this->database->TR4CT_T1ChargeFault || this->database->TR4CT_T1DriverFlt || this->database->TR4CT_T1MotorOverTem || this->database->TR4CT_T1DirectionFlt
                     || this->database->TR4CT_T1InstructionFlt || this->database->TR4CT_T1OverCurU || this->database->TR4CT_T1OverCurV || this->database->TR4CT_T1SpeedSensorFlt
                     || this->database->TR4CT_T1BrkNotRealesed || this->database->TR4CT_T1LineOverVoltSet || this->database->TR4CT_T1LineOverCur || this->database->TR4CT_T1DriverFltU
                     || this->database->TR4CT_T1DriverFltV || this->database->TR4CT_T1DriverFltW || this->database->TR4CT_T1PhaseLess || this->database->TR4CT_T1NetUnderVolt;

    //TCU2-2
    this->tractionStates[5] = this->database->TR4CT_T2RadOverTemp || this->database->TR4CT_T2HSCBNotClosed || this->database->TR4CT_T2LB1NotClosed || this->database->TR4CT_T2LB2NotClosed
                     || this->database->TR4CT_T2OverCurrent || this->database->TR4CT_T2OverSpeed || this->database->TR4CT_T2TMCSFault || this->database->TR4CT_T2LineOverVolt
                     || this->database->TR4CT_T2InverterOverCur || this->database->TR4CT_T2NetOverCur || this->database->TR4CT_T2NetOverVolt || this->database->TR4CT_T2OverTime
                     || this->database->TR4CT_T2ChargeFault || this->database->TR4CT_T2DriverFlt || this->database->TR4CT_T2MotorOverTem || this->database->TR4CT_T2DirectionFlt
                     || this->database->TR4CT_T2InstructionFlt || this->database->TR4CT_T2OverCurU || this->database->TR4CT_T2OverCurV || this->database->TR4CT_T2SpeedSensorFlt
                     || this->database->TR4CT_T2BrkNotRealesed || this->database->TR4CT_T2LineOverVoltSet || this->database->TR4CT_T2LineOverCur || this->database->TR4CT_T2DriverFltU
                     || this->database->TR4CT_T2DriverFltV || this->database->TR4CT_T2DriverFltW || this->database->TR4CT_T2PhaseLess || this->database->TR4CT_T2NetUnderVolt;

    //TCU2-3
    this->tractionStates[6] = this->database->TR4CT_T3RadOverTemp || this->database->TR4CT_T3HSCBNotClosed || this->database->TR4CT_T3LB1NotClosed || this->database->TR4CT_T3LB2NotClosed
                     || this->database->TR4CT_T3OverCurrent || this->database->TR4CT_T3OverSpeed || this->database->TR4CT_T3TMCSFault || this->database->TR4CT_T3LineOverVolt
                     || this->database->TR4CT_T3InverterOverCur || this->database->TR4CT_T3NetOverCur || this->database->TR4CT_T3NetOverVolt || this->database->TR4CT_T3OverTime
                     || this->database->TR4CT_T3ChargeFault || this->database->TR4CT_T3DriverFlt || this->database->TR4CT_T3MotorOverTem || this->database->TR4CT_T3DirectionFlt
                     || this->database->TR4CT_T3InstructionFlt || this->database->TR4CT_T3OverCurU || this->database->TR4CT_T3OverCurV || this->database->TR4CT_T3SpeedSensorFlt
                     || this->database->TR4CT_T3BrkNotRealesed || this->database->TR4CT_T3LineOverVoltSet || this->database->TR4CT_T3LineOverCur || this->database->TR4CT_T3DriverFltU
                     || this->database->TR4CT_T3DriverFltV || this->database->TR4CT_T3DriverFltW || this->database->TR4CT_T3PhaseLess || this->database->TR4CT_T3NetUnderVolt;

    //TCU2-4
    this->tractionStates[7] = this->database->TR4CT_T4RadOverTemp || this->database->TR4CT_T4HSCBNotClosed || this->database->TR4CT_T4LB1NotClosed || this->database->TR4CT_T4LB2NotClosed
                     || this->database->TR4CT_T4OverCurrent || this->database->TR4CT_T4OverSpeed || this->database->TR4CT_T4TMCSFault || this->database->TR4CT_T4LineOverVolt
                     || this->database->TR4CT_T4InverterOverCur || this->database->TR4CT_T4NetOverCur || this->database->TR4CT_T4NetOverVolt || this->database->TR4CT_T4OverTime
                     || this->database->TR4CT_T4ChargeFault || this->database->TR4CT_T4DriverFlt || this->database->TR4CT_T4MotorOverTem || this->database->TR4CT_T4DirectionFlt
                     || this->database->TR4CT_T4InstructionFlt || this->database->TR4CT_T4OverCurU || this->database->TR4CT_T4OverCurV || this->database->TR4CT_T4SpeedSensorFlt
                     || this->database->TR4CT_T4BrkNotRealesed || this->database->TR4CT_T4LineOverVoltSet || this->database->TR4CT_T4LineOverCur || this->database->TR4CT_T4DriverFltU
                     || this->database->TR4CT_T4DriverFltV || this->database->TR4CT_T4DriverFltW || this->database->TR4CT_T4PhaseLess || this->database->TR4CT_T4NetUnderVolt;



//    this->setTractionState(ui->label_car2TractionSystem1, this->database->CTHM_Mp1DCUOn, this->database->TR3CT_T1CutOff, this->tractionStates.at(0));
//    this->setTractionState(ui->label_car2TractionSystem2, this->database->CTHM_Mp1DCUOn, this->database->TR3CT_T2CutOff, this->tractionStates.at(1));
//    this->setTractionState(ui->label_car2TractionSystem3, this->database->CTHM_Mp1DCUOn, this->database->TR3CT_T3CutOff, this->tractionStates.at(2));
//    this->setTractionState(ui->label_car2TractionSystem4, this->database->CTHM_Mp1DCUOn, this->database->TR3CT_T4CutOff, this->tractionStates.at(3));
//    this->setTractionState(ui->label_car3TractionSystem1, this->database->CTHM_Mp2DCUOn, this->database->TR4CT_T1CutOff, this->tractionStates.at(4));
//    this->setTractionState(ui->label_car3TractionSystem2, this->database->CTHM_Mp2DCUOn, this->database->TR4CT_T2CutOff, this->tractionStates.at(5));
//    this->setTractionState(ui->label_car3TractionSystem3, this->database->CTHM_Mp2DCUOn, this->database->TR4CT_T3CutOff, this->tractionStates.at(6));
//    this->setTractionState(ui->label_car3TractionSystem4, this->database->CTHM_Mp2DCUOn, this->database->TR4CT_T4CutOff, this->tractionStates.at(7));

    this->setTractionAllowed(ui->label_car2tractionAllowed, this->database->CTTR3_TractionAllowed);
    this->setTractionAllowed(ui->label_car3tractionAllowed, this->database->CTTR4_TractionAllowed);
    this->setHSCB(ui->label_car2HSCB, this->database->CTHM_Mp1DCUOn, this->database->TR3CT_HSCBState);
    this->setHSCB(ui->label_car3HSCB, this->database->CTHM_Mp2DCUOn, this->database->TR4CT_HSCBState);

    this->setAllBrakeReleased(ui->label_car2AllBR1, this->database->TR3CT_AllBrkReleased1);
    this->setAllBrakeReleased(ui->label_car2AllBR2, this->database->TR3CT_AllBrkReleased2);
    this->setAllBrakeReleased(ui->label_car2AllBR3, this->database->TR3CT_AllBrkReleased3);
    this->setAllBrakeReleased(ui->label_car2AllBR4, this->database->TR3CT_AllBrkReleased4);
    this->setAllBrakeReleased(ui->label_car3AllBR1, this->database->TR4CT_AllBrkReleased1);
    this->setAllBrakeReleased(ui->label_car3AllBR2, this->database->TR4CT_AllBrkReleased2);
    this->setAllBrakeReleased(ui->label_car3AllBR3, this->database->TR4CT_AllBrkReleased3);
    this->setAllBrakeReleased(ui->label_car3AllBR4, this->database->TR4CT_AllBrkReleased4);

    this->setEBState(ui->label_car2EBState1, this->database->TR3CT_A1EBOK, this->database->TR3CT_A1EBAvailable, this->database->TR3CT_A1EBSlide, this->database->TR3CT_A1EBDecrease, this->database->TR3CT_A1EBCutOff);
    this->setEBState(ui->label_car2EBState2, this->database->TR3CT_A2EBOK, this->database->TR3CT_A2EBAvailable, this->database->TR3CT_A2EBSlide, this->database->TR3CT_A2EBDecrease, this->database->TR3CT_A2EBCutOff);
    this->setEBState(ui->label_car2EBState3, this->database->TR3CT_A3EBOK, this->database->TR3CT_A3EBAvailable, this->database->TR3CT_A3EBSlide, this->database->TR3CT_A3EBDecrease, this->database->TR3CT_A3EBCutOff);
    this->setEBState(ui->label_car2EBState4, this->database->TR3CT_A4EBOK, this->database->TR3CT_A4EBAvailable, this->database->TR3CT_A4EBSlide, this->database->TR3CT_A4EBDecrease, this->database->TR3CT_A4EBCutOff);
    this->setEBState(ui->label_car3EBState1, this->database->TR4CT_A1EBOK, this->database->TR4CT_A1EBAvailable, this->database->TR4CT_A1EBSlide, this->database->TR4CT_A1EBDecrease, this->database->TR4CT_A1EBCutOff);
    this->setEBState(ui->label_car3EBState2, this->database->TR4CT_A2EBOK, this->database->TR4CT_A2EBAvailable, this->database->TR4CT_A2EBSlide, this->database->TR4CT_A2EBDecrease, this->database->TR4CT_A2EBCutOff);
    this->setEBState(ui->label_car3EBState3, this->database->TR4CT_A3EBOK, this->database->TR4CT_A3EBAvailable, this->database->TR4CT_A3EBSlide, this->database->TR4CT_A3EBDecrease, this->database->TR4CT_A3EBCutOff);
    this->setEBState(ui->label_car3EBState4, this->database->TR4CT_A4EBOK, this->database->TR4CT_A4EBAvailable, this->database->TR4CT_A4EBSlide, this->database->TR4CT_A4EBDecrease, this->database->TR4CT_A4EBCutOff);

    this->setSafetyBrake(ui->label_car2safety1, this->database->TR3CT_T1SafetyBrk);
    this->setSafetyBrake(ui->label_car2safety2, this->database->TR3CT_T2SafetyBrk);
    this->setSafetyBrake(ui->label_car2safety3, this->database->TR3CT_T3SafetyBrk);
    this->setSafetyBrake(ui->label_car2safety4, this->database->TR3CT_T4SafetyBrk);
    this->setSafetyBrake(ui->label_car3safety1, this->database->TR4CT_T1SafetyBrk);
    this->setSafetyBrake(ui->label_car3safety2, this->database->TR4CT_T2SafetyBrk);
    this->setSafetyBrake(ui->label_car3safety3, this->database->TR4CT_T3SafetyBrk);
    this->setSafetyBrake(ui->label_car3safety4, this->database->TR4CT_T4SafetyBrk);

    this->setLineCurr(ui->label_car2lineCurr1, this->database->TR3CT_M1LineCur);
    this->setLineCurr(ui->label_car2lineCurr2, this->database->TR3CT_M2LineCur);
    this->setLineCurr(ui->label_car3lineCurr1, this->database->TR4CT_M1LineCur);
    this->setLineCurr(ui->label_car3lineCurr2, this->database->TR4CT_M2LineCur);

    this->setInverterCurr(ui->label_car2inverterCurr1, this->database->TR3CT_T1InverterCurrent);
    this->setInverterCurr(ui->label_car2inverterCurr2, this->database->TR3CT_T2InverterCurrent);
    this->setInverterCurr(ui->label_car2inverterCurr3, this->database->TR3CT_T3InverterCurrent);
    this->setInverterCurr(ui->label_car2inverterCurr4, this->database->TR3CT_T4InverterCurrent);
    this->setInverterCurr(ui->label_car3inverterCurr1, this->database->TR4CT_T1InverterCurrent);
    this->setInverterCurr(ui->label_car3inverterCurr2, this->database->TR4CT_T2InverterCurrent);
    this->setInverterCurr(ui->label_car3inverterCurr3, this->database->TR4CT_T3InverterCurrent);
    this->setInverterCurr(ui->label_car3inverterCurr4, this->database->TR4CT_T4InverterCurrent);

    this->setEBEffect(ui->label_car2EBEffect1, this->database->TR3CT_T1ActualEBEffort);
    this->setEBEffect(ui->label_car2EBEffect2, this->database->TR3CT_T2ActualEBEffort);
    this->setEBEffect(ui->label_car2EBEffect3, this->database->TR3CT_T3ActualEBEffort);
    this->setEBEffect(ui->label_car2EBEffect4, this->database->TR3CT_T4ActualEBEffort);
    this->setEBEffect(ui->label_car3EBEffect1, this->database->TR4CT_T1ActualEBEffort);
    this->setEBEffect(ui->label_car3EBEffect2, this->database->TR4CT_T2ActualEBEffort);
    this->setEBEffect(ui->label_car3EBEffect3, this->database->TR4CT_T3ActualEBEffort);
    this->setEBEffect(ui->label_car3EBEffect4, this->database->TR4CT_T4ActualEBEffort);

    this->setContector(ui->label_car2Contactor1, this->database->TR3CT_M1MainConState);
    this->setContector(ui->label_car2Contactor2, this->database->TR3CT_M2MainConState);
    this->setContector(ui->label_car3Contactor1, this->database->TR4CT_M1MainConState);
    this->setContector(ui->label_car3Contactor2, this->database->TR4CT_M2MainConState);

    this->setChargeContector(ui->label_car2chargeContactor1, this->database->TR3CT_M1CharConState);
    this->setChargeContector(ui->label_car2chargeContactor2, this->database->TR3CT_M2CharConState);
    this->setChargeContector(ui->label_car3chargeContactor1, this->database->TR4CT_M1CharConState);
    this->setChargeContector(ui->label_car3chargeContactor2, this->database->TR4CT_M2CharConState);

    this->setIsolateState(ui->label_car2IsolateState1, this->database->TR3CT_T1CutOff);
    this->setIsolateState(ui->label_car2IsolateState2, this->database->TR3CT_T2CutOff);
    this->setIsolateState(ui->label_car2IsolateState3, this->database->TR3CT_T3CutOff);
    this->setIsolateState(ui->label_car2IsolateState4, this->database->TR3CT_T4CutOff);
    this->setIsolateState(ui->label_car3IsolateState1, this->database->TR4CT_T1CutOff);
    this->setIsolateState(ui->label_car3IsolateState2, this->database->TR4CT_T2CutOff);
    this->setIsolateState(ui->label_car3IsolateState3, this->database->TR4CT_T3CutOff);
    this->setIsolateState(ui->label_car3IsolateState4, this->database->TR4CT_T4CutOff);
 }

void TractionPage::setTractionState(QLabel *label, bool onState, bool cutOffState, bool faultState)
{
    if(!onState)
    {
        label->setStyleSheet(_OFFLINE);
        label->setText("");
        return;
    }
    else if(cutOffState)
    {
        label->setStyleSheet(_CUT);
        label->setText("");
        return;
    }
    else if(faultState)
    {
        label->setStyleSheet(_FAULT);
        label->setText("");
        return;
    }
    else
    {
        label->setStyleSheet(_RUN);
       // label->setText(QString::number(current));
        return;
    }
}

void TractionPage::setTractionAllowed(QLabel *label, bool tractionAllowed)
{
    if(tractionAllowed)
    {
        label->setStyleSheet(_RUN);
        return;
    }
    else
    {
        label->setStyleSheet(_STOP);
        return;
    }
}

void TractionPage::setEBState(QLabel *label, bool EBEffect, bool EBAvailable, bool EBSlide, bool EBDecrease, bool EBCut)
{
    if(EBEffect)
    {
        if(EBCut)
        {
            label->setStyleSheet(_CUT);
            label->setText("");
            return;
        }
        else if(EBDecrease)
        {
            label->setStyleSheet(_BRAKEDECREASE);
            label->setText("");
            return;
        }
        else if(EBSlide)
        {
            label->setStyleSheet(_BRAKESLIDE);
            label->setText("");
            return;
        }
        else if(EBAvailable)
        {
            label->setStyleSheet(_RUN);
            label->setText("");
            return;
        }
        else
        {
            label->setStyleSheet(_STOP);
            label->setText(QString("有效"));
            return;
        }
    }
    else
    {
        label->setStyleSheet(_STOP);
        label->setText("");
    }
}

void TractionPage::setHSCB(QLabel *label, bool onState, bool HSCBState)
{
    if(!onState)
    {
        label->setStyleSheet(_OFFLINE);
        return;
    }
    else if(!HSCBState)
    {
        label->setStyleSheet(_STOP);
        return;
    }
    else
    {
        label->setStyleSheet(_RUN);
        return;
    }
}

void TractionPage::setAllBrakeReleased(QLabel *label, bool allBrakeReleased)
{
    if(allBrakeReleased)
    {
        label->setStyleSheet(_RUN);
    }
    else
    {
        label->setStyleSheet(_BRAKE);
    }
}



void TractionPage::setEBEffect(QLabel *label, unsigned short EBEffect)
{
    label->setText(QString::number(EBEffect * 10));
}

void TractionPage::setSafetyBrake(QLabel *label, bool safetyBrake)
{
    if(safetyBrake)
    {
        label->setStyleSheet(_FAULT);
        return;
    }
    else
    {
        label->setStyleSheet(_STOP);
        return;
    }
}

void TractionPage::setLineCurr(QLabel *label, unsigned int lineCurr)
{
    label->setText(QString::number(lineCurr));
}

void TractionPage::setInverterCurr(QLabel *label, unsigned int inverterCurr)
{
    label->setText(QString::number(inverterCurr));
}

void TractionPage::setChargeContector(QLabel *label, bool chargeContectorState)
{
    if(chargeContectorState)
    {
        label->setStyleSheet(_RUN);
    }
    else
    {
        label->setStyleSheet(_STOP);
    }
}

void TractionPage::setContector(QLabel *label, bool contectorState)
{
    if(contectorState)
    {
        label->setStyleSheet(_RUN);
    }
    else
    {
        label->setStyleSheet(_STOP);
    }
}

void TractionPage::setIsolateState(QLabel *label, bool isolateState)
{
    if(isolateState)
    {
        label->setStyleSheet(_CUT);
    }
    else
    {
        label->setStyleSheet(_STOP);
    }
}


void TractionPage::on_btn_EmergencyBroadcast_clicked()
{
    emit this->changePage(uEmergencyBroadcast);
}
