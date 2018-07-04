#include "runstatepage.h"
#include "ui_runstatepage.h"
#include "vehiclelogo.h"
#include <QDebug>
#include "global.h"

#define _OFFLINE ("font: 15px, SimHei; color: rgb(0,0,0); background-color: white; border: 2px groove, gray; border-color: gray;")
#define _CUT ("image: url(:/image/cut.png); border: 2px groove, gray; border-color: gray;")
#define _OVERLOAD ("font: 15px, SimHei;color: white; background-color: rgb(0, 255, 255); border: 2px groove, gray; border-color: gray;")
#define _BLACK ("font: 15px, SimHei;color: white; background-color: black; border: 2px groove, gray; border-color: gray;")
#define _RED ("font: 15px, SimHei; color: white; background-color: red; border: 2px groove, gray; border-color: gray;")
#define _SLIGHT_FAULT ("font: 20px, SimHei; color: blue; background-color: rgb(244 ,128, 17); border: 2px groove, gray; border-color: gray;")
#define _GREEN ("font: 15px, SimHei; color: rgb(0,0,0); background-color: rgb(0, 255, 0); border: 2px groove, gray; border-color: gray;")
#define _YELLOW ("font: 15px, SimHei; color: rgb(0,0,0); background-color: yellow; border: 2px groove, gray; border-color: gray;")
#define _EMERGENCY_BRAKE ("image: url(:/image/STOP.png); border: 2px groove, gray; border-color: gray;")
#define _AIR_BRAKE ("font: 15px, SimHei; color: rgb(0,0,0); background-color: rgb(153,0,51); border: 2px groove, gray; border-color: gray;")
#define _FAST_BRAKE ("font: 15px, SimHei; color: rgb(255,255,255); background-color: rgb(204,0,255); border: 2px groove, gray; border-color: gray;")
#define _DOOR_BLOCK ("font: 20px, SimHei; color: blue; image: url(:/image/doorBlock.png); border: 2px groove, gray; border-color: gray;")
#define _DOOR_EMERGENCY ("font: 20px, SimHei; color: blue; image: url(:/image/doorEmergency.png); border: 2px groove, gray; border-color: gray;")
#define _DOOR_OPENERROR ("font: 20px, SimHei; color: blue; image: url(:/image/doorOpenError.png); border: 2px groove, gray; border-color: gray;")
#define _DOOR_LOCK ("font: 20px, SimHei; color: blue; image: url(:/image/lock.png); border: 2px groove, gray; border-color: gray;")
#define _DOOR_CLOSE ("font: 20px, SimHei; color: blue; background-color: gray; border: 2px groove, gray; border-color: gray;")

enum doorMaster
{
    Master1 = 1,
    Master2
};

RunStatePage::RunStatePage(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::RunStatePage)
{
    ui->setupUi(this); 
    _LOG << "RunStatePage constructor";
    this->vehicleLogo = new VehicleLogo(this);
    this->vehicleLogo->setGeometry(0, 10, this->vehicleLogo->width(), this->vehicleLogo->height());
    this->tractionStates <<false << false << false << false << false << false << false << false;
    //ui->label_washing->hide();
    //this->airBrakeState << false << false << false << false << false << false << false << false;
    //this->airBrakeStateError << false << false << false << false << false << false << false << false;
    //this->currentAirBrakeState = false;
    this->airBrake1 = false;
    this->airBrake2 = false;
    this->airBrake3 = false;
    this->airBrake4 = false;
    this->airBrake5 = false;
    this->airBrake6 = false;
    this->airBrake7 = false;
    this->airBrake8 = false;

    this->parkBrake1 = false;
    this->parkBrake2 = false;
    this->parkBrake3 = false;
    this->parkBrake4 = false;
}

RunStatePage::~RunStatePage()
{
    delete ui;
}


void RunStatePage::updatePage()
{
    this->vehicleLogo->updateVehicleState(this->database->CTHM_TC1Active, this->database->CTHM_TC2Active, this->database->CTHM_Forward, this->database->CTHM_Backward,
    this->database->CTHM_Mp1RIOMGWOn, this->database->CTHM_Mp2RIOMGWOn, this->database->RIOM3_DIM1Ch18, this->database->RIOM3_DIM1Ch19, this->database->RIOM4_DIM1Ch18,
    this->database->RIOM4_DIM1Ch19, this->database->DICT_Tc1DI1I15AllDoorClosed_A1 | this->database->DICT_Tc2DI1I15AllDoorClosed_A2);
    this->vehicleLogo->updateVehicleNo(this->database->lineNo, this->database->vehicleNo);
    this->vehicleLogo->updateHSCB(this->database->TR3CT_HSCBState, this->database->TR4CT_HSCBState);
    this->setAssistantState(ui->label_car1AssistantState, this->database->CTHM_SIV1On, this->database->AX1CT_Stop, this->database->AX1CT_Fault, this->database->AX1CT_Running, this->database->AX1CT_OutputVoltAC);
    this->setAssistantState(ui->label_car4AssistantState, this->database->CTHM_SIV2On, this->database->AX2CT_Stop, this->database->AX2CT_Fault, this->database->AX2CT_Running, this->database->AX2CT_OutputVoltAC);
    //assistant extend power
    this->setExtentPower(ui->label_car2AssistantState, this->database->DICT_M1DI1I15ExpandPowerFB_A1);
    //this->setExtentPower(ui->label_car3AssistantState, this->database->CTAX2_ExtendPowerValid);
    //TCU1-1
    this->tractionStates[0] = this->database->TR3CT_T1RadOverTemp|| this->database->TR3CT_T1HSCBNotClosed || this->database->TR3CT_T1LB1NotClosed || this->database->TR3CT_T1LB2NotClosed
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

    this->setTractionState(ui->label_car2TractionSystem1, this->database->CTHM_Mp1DCUOn, this->database->TR3CT_T1CutOff, this->tractionStates.at(0), this->database->TR3CT_T1InverterCurrent);
    this->setTractionState(ui->label_car2TractionSystem2, this->database->CTHM_Mp1DCUOn, this->database->TR3CT_T2CutOff, this->tractionStates.at(1), this->database->TR3CT_T2InverterCurrent);
    this->setTractionState(ui->label_car2TractionSystem3, this->database->CTHM_Mp1DCUOn, this->database->TR3CT_T3CutOff, this->tractionStates.at(2), this->database->TR3CT_T3InverterCurrent);
    this->setTractionState(ui->label_car2TractionSystem4, this->database->CTHM_Mp1DCUOn, this->database->TR3CT_T4CutOff, this->tractionStates.at(3), this->database->TR3CT_T4InverterCurrent);
    this->setTractionState(ui->label_car3TractionSystem1, this->database->CTHM_Mp2DCUOn, this->database->TR4CT_T1CutOff, this->tractionStates.at(4), this->database->TR4CT_T1InverterCurrent);
    this->setTractionState(ui->label_car3TractionSystem2, this->database->CTHM_Mp2DCUOn, this->database->TR4CT_T2CutOff, this->tractionStates.at(5), this->database->TR4CT_T2InverterCurrent);
    this->setTractionState(ui->label_car3TractionSystem3, this->database->CTHM_Mp2DCUOn, this->database->TR4CT_T3CutOff, this->tractionStates.at(6), this->database->TR4CT_T3InverterCurrent);
    this->setTractionState(ui->label_car3TractionSystem4, this->database->CTHM_Mp2DCUOn, this->database->TR4CT_T4CutOff, this->tractionStates.at(7), this->database->TR4CT_T4InverterCurrent);

    //BCU
    bool brakeOnLine1, brakeOnLine2;
    brakeOnLine1 = this->database->CTHM_Tc1BCUOn || this->database->CTHM_Mp1BCUOn;
    brakeOnLine2 = this->database->CTHM_Tc2BCUOn || this->database->CTHM_Mp2BCUOn;

    this->airBrake1 = this->setAirBrakeState(this->database->getBool(0xF411, 12, 3), this->database->getBool(0xF411, 12, 4));
    this->airBrake2 = this->setAirBrakeState(this->database->getBool(0xF411, 28, 3), this->database->getBool(0xF411, 28, 4));
    this->airBrake3 = this->setAirBrakeState(this->database->getBool(0xF412, 12, 3), this->database->getBool(0xF412, 12, 4));
    this->airBrake4 = this->setAirBrakeState(this->database->getBool(0xF412, 28, 3), this->database->getBool(0xF412, 28, 4));
    this->airBrake6 = this->setAirBrakeState(this->database->getBool(0xF442, 28, 3), this->database->getBool(0xF442, 28, 4));
    this->airBrake5 = this->setAirBrakeState(this->database->getBool(0xF442, 12, 3), this->database->getBool(0xF442, 12, 4));
    this->airBrake8 = this->setAirBrakeState(this->database->getBool(0xF441, 28, 3), this->database->getBool(0xF441, 28, 4));
    this->airBrake7 = this->setAirBrakeState(this->database->getBool(0xF441, 12, 3), this->database->getBool(0xF441, 12, 4));

    this->parkBrake1 = this->setParkBrakeState(this->database->getBool(0xF410, 29, 7), this->database->getBool(0xF410, 29, 6));
    this->parkBrake2 = this->setParkBrakeState(this->database->getBool(0xF410, 27, 7), this->database->getBool(0xF410, 27, 6));
    this->parkBrake3 = this->setParkBrakeState(this->database->getBool(0xF440, 27, 7), this->database->getBool(0xF440, 27, 6));
    this->parkBrake4 = this->setParkBrakeState(this->database->getBool(0xF440, 29, 7), this->database->getBool(0xF440, 29, 6));

    this->setBrakeState(ui->label_car1Brake1, brakeOnLine1, this->database->getBool(0xF411, 12, 7), this->database->getBool(0xF411, 13, 1), airBrake1, parkBrake1);
    this->setBrakeState(ui->label_car1Brake2, brakeOnLine1, this->database->getBool(0xF411, 28, 7), this->database->getBool(0xF411, 29, 1), airBrake2, parkBrake1);
    this->setBrakeState(ui->label_car2Brake1, brakeOnLine1, this->database->getBool(0xF412, 12, 7), this->database->getBool(0xF412, 13, 1), airBrake3, parkBrake2);
    this->setBrakeState(ui->label_car2Brake2, brakeOnLine1, this->database->getBool(0xF412, 28, 7), this->database->getBool(0xF412, 29, 1), airBrake4, parkBrake2);
    this->setBrakeState(ui->label_car3Brake2, brakeOnLine2, this->database->getBool(0xF442, 28, 7), this->database->getBool(0xF442, 29, 1), airBrake6, parkBrake3);
    this->setBrakeState(ui->label_car3Brake1, brakeOnLine2, this->database->getBool(0xF442, 12, 7), this->database->getBool(0xF442, 13, 1), airBrake5, parkBrake3);
    this->setBrakeState(ui->label_car4Brake2, brakeOnLine2, this->database->getBool(0xF441, 28, 7), this->database->getBool(0xF441, 29, 1), airBrake8, parkBrake4);
    this->setBrakeState(ui->label_car4Brake1, brakeOnLine2, this->database->getBool(0xF441, 12, 7), this->database->getBool(0xF441, 13, 1), airBrake7, parkBrake4);

    //HVAC
    this->getTemperature(ui->label_car1InnerTemperature, this->database->CTHM_Tc1HVACOn, QString::number(this->database->AC1CT_TempInside - 40));
    this->getTemperature(ui->label_car2InnerTemperature, this->database->CTHM_Mp1HVACOn, QString::number(this->database->AC3CT_TempInside - 40));
    this->getTemperature(ui->label_car3InnerTemperature, this->database->CTHM_Mp2HVACOn, QString::number(this->database->AC4CT_TempInside - 40));
    this->getTemperature(ui->label_car4InnerTemperature, this->database->CTHM_Tc2HVACOn, QString::number(this->database->AC6CT_TempInside - 40));

    this->getTemperature(ui->label_car1outerTemperature, this->database->CTHM_Tc1HVACOn, QString::number(this->database->AC1CT_TempOutside - 40));
    this->getTemperature(ui->label_car2outerTemperature, this->database->CTHM_Mp1HVACOn, QString::number(this->database->AC3CT_TempOutside - 40));
    this->getTemperature(ui->label_car3outerTemperature, this->database->CTHM_Mp2HVACOn, QString::number(this->database->AC4CT_TempOutside - 40));
    this->getTemperature(ui->label_car4outerTemperature, this->database->CTHM_Tc2HVACOn, QString::number(this->database->AC6CT_TempOutside - 40));

//    //brakePressure
//    this->getBrakePressure(ui->label_car1BrakePressure1, this->database->getSignedInt(0xF410, 8));
//    this->getBrakePressure(ui->label_car1BrakePressure2, this->database->getSignedInt(0xF410, 10));
//    this->getBrakePressure(ui->label_car2BrakePressure1, this->database->getSignedInt(0xF410, 24));
//    this->getBrakePressure(ui->label_car2BrakePressure2, this->database->getSignedInt(0xF410, 26));
//    this->getBrakePressure(ui->label_car3BrakePressure1, this->database->getSignedInt(0xF410, 26));
//    this->getBrakePressure(ui->label_car3BrakePressure2, this->database->getSignedInt(0xF410, 26));
//    this->getBrakePressure(ui->label_car4BrakePressure1, this->database->getSignedInt(0xF410, 26));
//    this->getBrakePressure(ui->label_car4BrakePressure2, this->database->hmiBrake2_BCP1TCjBg2_A2);

    //doors
    this->setDoorState(ui->label_car1Valve1, this->database->getBool(0xF711, 22, 0) && (((Master1 == this->database->doorsOnLine1[0]) && this->database->CTHM_EDCU1On) || ((Master2 == this->database->doorsOnLine1[0]) && this->database->CTHM_EDCU2On)
                       || (this->database->CTHM_EDCU1On && this->database->CTHM_EDCU2On)),
                       this->database->hmiEDCU1_Door1Cut, this->database->hmiEDCU1_Door1SeriousFlt, this->database->hmiEDCU1_Door1SlightFlt, this->database->hmiEDCU1_Door1EMCunclock,
                       this->database->hmiEDCU1_Door1OpenHinder || this->database->hmiEDCU1_Door1CloseHinder, this->database->hmiEDCU1_Door1NotOandCFB, this->database->hmiEDCU1_Door1Opened,
                       this->database->hmiEDCU1_Door1CloseFB, this->database->hmiEDCU1_Door1Closed);
    this->setDoorState(ui->label_car1Valve2, this->database->getBool(0xF711, 22, 1) && (((Master1 == this->database->doorsOnLine1[1]) && this->database->CTHM_EDCU1On) || ((Master2 == this->database->doorsOnLine1[1]) && this->database->CTHM_EDCU2On)
                       || (this->database->CTHM_EDCU1On && this->database->CTHM_EDCU2On)),
                       this->database->hmiEDCU1_Door2Cut, this->database->hmiEDCU1_Door2SeriousFlt, this->database->hmiEDCU1_Door2SlightFlt, this->database->hmiEDCU1_Door2EMCunclock,
                       this->database->hmiEDCU1_Door2OpenHinder || this->database->hmiEDCU1_Door2CloseHinder, this->database->hmiEDCU1_Door2NotOandCFB, this->database->hmiEDCU1_Door2Opened,
                       this->database->hmiEDCU1_Door2CloseFB, this->database->hmiEDCU1_Door2Closed);
    this->setDoorState(ui->label_car1Valve3, this->database->getBool(0xF711, 22, 2) && (((Master1 == this->database->doorsOnLine1[2]) && this->database->CTHM_EDCU1On) || ((Master2 == this->database->doorsOnLine1[2]) && this->database->CTHM_EDCU2On)
                       || (this->database->CTHM_EDCU1On && this->database->CTHM_EDCU2On)),
                       this->database->hmiEDCU1_Door3Cut, this->database->hmiEDCU1_Door3SeriousFlt, this->database->hmiEDCU1_Door3SlightFlt, this->database->hmiEDCU1_Door3EMCunclock,
                       this->database->hmiEDCU1_Door3OpenHinder || this->database->hmiEDCU1_Door3CloseHinder, this->database->hmiEDCU1_Door3NotOandCFB, this->database->hmiEDCU1_Door3Opened,
                       this->database->hmiEDCU1_Door3CloseFB, this->database->hmiEDCU1_Door3Closed);
    this->setDoorState(ui->label_car1Valve4, this->database->getBool(0xF711, 22, 3) && (((Master1 == this->database->doorsOnLine1[3]) && this->database->CTHM_EDCU1On) || ((Master2 == this->database->doorsOnLine1[3]) && this->database->CTHM_EDCU2On)
                       || (this->database->CTHM_EDCU1On && this->database->CTHM_EDCU2On)),
                       this->database->hmiEDCU1_Door4Cut, this->database->hmiEDCU1_Door4SeriousFlt, this->database->hmiEDCU1_Door4SlightFlt, this->database->hmiEDCU1_Door4EMCunclock,
                       this->database->hmiEDCU1_Door4OpenHinder || this->database->hmiEDCU1_Door4CloseHinder, this->database->hmiEDCU1_Door4NotOandCFB, this->database->hmiEDCU1_Door4Opened,
                       this->database->hmiEDCU1_Door4CloseFB, this->database->hmiEDCU1_Door4Closed);
    this->setDoorState(ui->label_car1Valve5, this->database->getBool(0xF711, 22, 4) && (((Master1 == this->database->doorsOnLine1[4]) && this->database->CTHM_EDCU1On) || ((Master2 == this->database->doorsOnLine1[4]) && this->database->CTHM_EDCU2On)
                       || (this->database->CTHM_EDCU1On && this->database->CTHM_EDCU2On)),
                       this->database->hmiEDCU1_Door5Cut, this->database->hmiEDCU1_Door5SeriousFlt, this->database->hmiEDCU1_Door5SlightFlt, this->database->hmiEDCU1_Door5EMCunclock,
                       this->database->hmiEDCU1_Door5OpenHinder || this->database->hmiEDCU1_Door5CloseHinder, this->database->hmiEDCU1_Door5NotOandCFB, this->database->hmiEDCU1_Door5Opened,
                       this->database->hmiEDCU1_Door5CloseFB, this->database->hmiEDCU1_Door5Closed);
    this->setDoorState(ui->label_car1Valve6, this->database->getBool(0xF711, 22, 5) && (((Master1 == this->database->doorsOnLine1[5]) && this->database->CTHM_EDCU1On) || ((Master2 == this->database->doorsOnLine1[5]) && this->database->CTHM_EDCU2On)
                       || (this->database->CTHM_EDCU1On && this->database->CTHM_EDCU2On)),
                       this->database->hmiEDCU1_Door6Cut, this->database->hmiEDCU1_Door6SeriousFlt, this->database->hmiEDCU1_Door6SlightFlt, this->database->hmiEDCU1_Door6EMCunclock,
                       this->database->hmiEDCU1_Door6OpenHinder || this->database->hmiEDCU1_Door6CloseHinder, this->database->hmiEDCU1_Door6NotOandCFB, this->database->hmiEDCU1_Door6Opened,
                       this->database->hmiEDCU1_Door6CloseFB, this->database->hmiEDCU1_Door6Closed);
    this->setDoorState(ui->label_car1Valve7, this->database->getBool(0xF711, 22, 6) && (((Master1 == this->database->doorsOnLine1[6]) && this->database->CTHM_EDCU1On) || ((Master2 == this->database->doorsOnLine1[6]) && this->database->CTHM_EDCU2On)
                       || (this->database->CTHM_EDCU1On && this->database->CTHM_EDCU2On)),
                       this->database->hmiEDCU1_Door7Cut, this->database->hmiEDCU1_Door7SeriousFlt, this->database->hmiEDCU1_Door7SlightFlt, this->database->hmiEDCU1_Door7EMCunclock,
                       this->database->hmiEDCU1_Door7OpenHinder || this->database->hmiEDCU1_Door7CloseHinder, this->database->hmiEDCU1_Door7NotOandCFB, this->database->hmiEDCU1_Door7Opened,
                       this->database->hmiEDCU1_Door7CloseFB, this->database->hmiEDCU1_Door7Closed);
    this->setDoorState(ui->label_car1Valve8, this->database->getBool(0xF711, 22, 7) && (((Master1 == this->database->doorsOnLine1[7]) && this->database->CTHM_EDCU1On) || ((Master2 == this->database->doorsOnLine1[7]) && this->database->CTHM_EDCU2On)
                       || (this->database->CTHM_EDCU1On && this->database->CTHM_EDCU2On)),
                       this->database->hmiEDCU1_Door8Cut, this->database->hmiEDCU1_Door8SeriousFlt, this->database->hmiEDCU1_Door8SlightFlt, this->database->hmiEDCU1_Door8EMCunclock,
                       this->database->hmiEDCU1_Door8OpenHinder || this->database->hmiEDCU1_Door8CloseHinder, this->database->hmiEDCU1_Door8NotOandCFB, this->database->hmiEDCU1_Door8Opened,
                       this->database->hmiEDCU1_Door8CloseFB, this->database->hmiEDCU1_Door8Closed);

    this->setDoorState(ui->label_car2Valve1, this->database->getBool(0xF751, 22, 0) && (((Master1 == this->database->doorsOnLine3[0]) && this->database->CTHM_EDCU5On) || ((Master2 == this->database->doorsOnLine3[0]) && this->database->CTHM_EDCU6On)
                       || (this->database->CTHM_EDCU5On && this->database->CTHM_EDCU6On)),
                       this->database->hmiEDCU3_Door1Cut, this->database->hmiEDCU3_Door1SeriousFlt, this->database->hmiEDCU3_Door1SlightFlt, this->database->hmiEDCU3_Door1EMCunclock,
                       this->database->hmiEDCU3_Door1OpenHinder || this->database->hmiEDCU3_Door1CloseHinder, this->database->hmiEDCU3_Door1NotOandCFB, this->database->hmiEDCU3_Door1Opened,
                       this->database->hmiEDCU3_Door1CloseFB, this->database->hmiEDCU3_Door1Closed);
    this->setDoorState(ui->label_car2Valve2, this->database->getBool(0xF751, 22, 1) && (((Master1 == this->database->doorsOnLine3[1]) && this->database->CTHM_EDCU5On) || ((Master2 == this->database->doorsOnLine3[1]) && this->database->CTHM_EDCU6On)
                       || (this->database->CTHM_EDCU5On && this->database->CTHM_EDCU6On)),
                       this->database->hmiEDCU3_Door2Cut, this->database->hmiEDCU3_Door2SeriousFlt, this->database->hmiEDCU3_Door2SlightFlt, this->database->hmiEDCU3_Door2EMCunclock,
                       this->database->hmiEDCU3_Door2OpenHinder || this->database->hmiEDCU3_Door2CloseHinder, this->database->hmiEDCU3_Door2NotOandCFB, this->database->hmiEDCU3_Door2Opened,
                       this->database->hmiEDCU3_Door2CloseFB, this->database->hmiEDCU3_Door2Closed);
    this->setDoorState(ui->label_car2Valve3, this->database->getBool(0xF751, 22, 2) && (((Master1 == this->database->doorsOnLine3[2]) && this->database->CTHM_EDCU5On) || ((Master2 == this->database->doorsOnLine3[2]) && this->database->CTHM_EDCU6On)
                       || (this->database->CTHM_EDCU5On && this->database->CTHM_EDCU6On)),
                       this->database->hmiEDCU3_Door3Cut, this->database->hmiEDCU3_Door3SeriousFlt, this->database->hmiEDCU3_Door3SlightFlt, this->database->hmiEDCU3_Door3EMCunclock,
                       this->database->hmiEDCU3_Door3OpenHinder || this->database->hmiEDCU3_Door3CloseHinder, this->database->hmiEDCU3_Door3NotOandCFB, this->database->hmiEDCU3_Door3Opened,
                       this->database->hmiEDCU3_Door3CloseFB, this->database->hmiEDCU3_Door3Closed);
    this->setDoorState(ui->label_car2Valve4, this->database->getBool(0xF751, 22, 3) && (((Master1 == this->database->doorsOnLine3[3]) && this->database->CTHM_EDCU5On) || ((Master2 == this->database->doorsOnLine3[3]) && this->database->CTHM_EDCU6On)
                       || (this->database->CTHM_EDCU5On && this->database->CTHM_EDCU6On)),
                       this->database->hmiEDCU3_Door4Cut, this->database->hmiEDCU3_Door4SeriousFlt, this->database->hmiEDCU3_Door4SlightFlt, this->database->hmiEDCU3_Door4EMCunclock,
                       this->database->hmiEDCU3_Door4OpenHinder || this->database->hmiEDCU3_Door4CloseHinder, this->database->hmiEDCU3_Door4NotOandCFB, this->database->hmiEDCU3_Door4Opened,
                       this->database->hmiEDCU3_Door4CloseFB, this->database->hmiEDCU3_Door4Closed);
    this->setDoorState(ui->label_car2Valve5, this->database->getBool(0xF751, 22, 4) && (((Master1 == this->database->doorsOnLine3[4]) && this->database->CTHM_EDCU5On) || ((Master2 == this->database->doorsOnLine3[4]) && this->database->CTHM_EDCU6On)
                       || (this->database->CTHM_EDCU5On && this->database->CTHM_EDCU6On)),
                       this->database->hmiEDCU3_Door5Cut, this->database->hmiEDCU3_Door5SeriousFlt, this->database->hmiEDCU3_Door5SlightFlt, this->database->hmiEDCU3_Door5EMCunclock,
                       this->database->hmiEDCU3_Door5OpenHinder || this->database->hmiEDCU3_Door5CloseHinder, this->database->hmiEDCU3_Door5NotOandCFB, this->database->hmiEDCU3_Door5Opened,
                       this->database->hmiEDCU3_Door5CloseFB, this->database->hmiEDCU3_Door5Closed);
    this->setDoorState(ui->label_car2Valve6, this->database->getBool(0xF751, 22, 5) && (((Master1 == this->database->doorsOnLine3[5]) && this->database->CTHM_EDCU5On) || ((Master2 == this->database->doorsOnLine3[5]) && this->database->CTHM_EDCU6On)
                       || (this->database->CTHM_EDCU5On && this->database->CTHM_EDCU6On)),
                       this->database->hmiEDCU3_Door6Cut, this->database->hmiEDCU3_Door6SeriousFlt, this->database->hmiEDCU3_Door6SlightFlt, this->database->hmiEDCU3_Door6EMCunclock,
                       this->database->hmiEDCU3_Door6OpenHinder || this->database->hmiEDCU3_Door6CloseHinder, this->database->hmiEDCU3_Door6NotOandCFB, this->database->hmiEDCU3_Door6Opened,
                       this->database->hmiEDCU3_Door6CloseFB, this->database->hmiEDCU3_Door6Closed);
    this->setDoorState(ui->label_car2Valve7, this->database->getBool(0xF751, 22, 6) && (((Master1 == this->database->doorsOnLine3[6]) && this->database->CTHM_EDCU5On) || ((Master2 == this->database->doorsOnLine3[6]) && this->database->CTHM_EDCU6On)
                       || (this->database->CTHM_EDCU5On && this->database->CTHM_EDCU6On)),
                       this->database->hmiEDCU3_Door7Cut, this->database->hmiEDCU3_Door7SeriousFlt, this->database->hmiEDCU3_Door7SlightFlt, this->database->hmiEDCU3_Door7EMCunclock,
                       this->database->hmiEDCU3_Door7OpenHinder || this->database->hmiEDCU3_Door7CloseHinder, this->database->hmiEDCU3_Door7NotOandCFB, this->database->hmiEDCU3_Door7Opened,
                       this->database->hmiEDCU3_Door7CloseFB, this->database->hmiEDCU3_Door7Closed);
    this->setDoorState(ui->label_car2Valve8, this->database->getBool(0xF751, 22, 7) && (((Master1 == this->database->doorsOnLine3[7]) && this->database->CTHM_EDCU5On) || ((Master2 == this->database->doorsOnLine3[7]) && this->database->CTHM_EDCU6On)
                       || (this->database->CTHM_EDCU5On && this->database->CTHM_EDCU6On)),
                       this->database->hmiEDCU3_Door8Cut, this->database->hmiEDCU3_Door8SeriousFlt, this->database->hmiEDCU3_Door8SlightFlt, this->database->hmiEDCU3_Door8EMCunclock,
                       this->database->hmiEDCU3_Door8OpenHinder || this->database->hmiEDCU3_Door8CloseHinder, this->database->hmiEDCU3_Door8NotOandCFB, this->database->hmiEDCU3_Door8Opened,
                       this->database->hmiEDCU3_Door8CloseFB, this->database->hmiEDCU3_Door8Closed);

    this->setDoorState(ui->label_car3Valve1, this->database->getBool(0xF771, 22, 0) && (((Master1 == this->database->doorsOnLine4[0]) && this->database->CTHM_EDCU7On) || ((Master2 == this->database->doorsOnLine4[0]) && this->database->CTHM_EDCU8On)
                       || (this->database->CTHM_EDCU7On && this->database->CTHM_EDCU8On)),
                       this->database->hmiEDCU4_Door1Cut, this->database->hmiEDCU4_Door1SeriousFlt, this->database->hmiEDCU4_Door1SlightFlt, this->database->hmiEDCU4_Door1EMCunclock,
                       this->database->hmiEDCU4_Door1OpenHinder || this->database->hmiEDCU4_Door1CloseHinder, this->database->hmiEDCU4_Door1NotOandCFB, this->database->hmiEDCU4_Door1Opened,
                       this->database->hmiEDCU4_Door1CloseFB, this->database->hmiEDCU4_Door1Closed);
    this->setDoorState(ui->label_car3Valve2, this->database->getBool(0xF771, 22, 1) && (((Master1 == this->database->doorsOnLine4[1]) && this->database->CTHM_EDCU7On) || ((Master2 == this->database->doorsOnLine4[1]) && this->database->CTHM_EDCU8On)
                       || (this->database->CTHM_EDCU7On && this->database->CTHM_EDCU8On)),
                       this->database->hmiEDCU4_Door2Cut, this->database->hmiEDCU4_Door2SeriousFlt, this->database->hmiEDCU4_Door2SlightFlt, this->database->hmiEDCU4_Door2EMCunclock,
                       this->database->hmiEDCU4_Door2OpenHinder || this->database->hmiEDCU4_Door2CloseHinder, this->database->hmiEDCU4_Door2NotOandCFB, this->database->hmiEDCU4_Door2Opened,
                       this->database->hmiEDCU4_Door2CloseFB, this->database->hmiEDCU4_Door2Closed);
    this->setDoorState(ui->label_car3Valve3, this->database->getBool(0xF771, 22, 2) && (((Master1 == this->database->doorsOnLine4[2]) && this->database->CTHM_EDCU7On) || ((Master2 == this->database->doorsOnLine4[2]) && this->database->CTHM_EDCU8On)
                       || (this->database->CTHM_EDCU7On && this->database->CTHM_EDCU8On)),
                       this->database->hmiEDCU4_Door3Cut, this->database->hmiEDCU4_Door3SeriousFlt, this->database->hmiEDCU4_Door3SlightFlt, this->database->hmiEDCU4_Door3EMCunclock,
                       this->database->hmiEDCU4_Door3OpenHinder || this->database->hmiEDCU4_Door3CloseHinder, this->database->hmiEDCU4_Door3NotOandCFB, this->database->hmiEDCU4_Door3Opened,
                       this->database->hmiEDCU4_Door3CloseFB, this->database->hmiEDCU4_Door3Closed);
    this->setDoorState(ui->label_car3Valve4, this->database->getBool(0xF771, 22, 3) && (((Master1 == this->database->doorsOnLine4[3]) && this->database->CTHM_EDCU7On) || ((Master2 == this->database->doorsOnLine4[3]) && this->database->CTHM_EDCU8On)
                       || (this->database->CTHM_EDCU7On && this->database->CTHM_EDCU8On)),
                       this->database->hmiEDCU4_Door4Cut, this->database->hmiEDCU4_Door4SeriousFlt, this->database->hmiEDCU4_Door4SlightFlt, this->database->hmiEDCU4_Door4EMCunclock,
                       this->database->hmiEDCU4_Door4OpenHinder || this->database->hmiEDCU4_Door4CloseHinder, this->database->hmiEDCU4_Door4NotOandCFB, this->database->hmiEDCU4_Door4Opened,
                       this->database->hmiEDCU4_Door4CloseFB, this->database->hmiEDCU4_Door4Closed);
    this->setDoorState(ui->label_car3Valve5, this->database->getBool(0xF771, 22, 4) && (((Master1 == this->database->doorsOnLine4[4]) && this->database->CTHM_EDCU7On) || ((Master2 == this->database->doorsOnLine4[4]) && this->database->CTHM_EDCU8On)
                       || (this->database->CTHM_EDCU7On && this->database->CTHM_EDCU8On)),
                       this->database->hmiEDCU4_Door5Cut, this->database->hmiEDCU4_Door5SeriousFlt, this->database->hmiEDCU4_Door5SlightFlt, this->database->hmiEDCU4_Door5EMCunclock,
                       this->database->hmiEDCU4_Door5OpenHinder || this->database->hmiEDCU4_Door5CloseHinder, this->database->hmiEDCU4_Door5NotOandCFB, this->database->hmiEDCU4_Door5Opened,
                       this->database->hmiEDCU4_Door5CloseFB, this->database->hmiEDCU4_Door5Closed);
    this->setDoorState(ui->label_car3Valve6, this->database->getBool(0xF771, 22, 5) && (((Master1 == this->database->doorsOnLine4[5]) && this->database->CTHM_EDCU7On) || ((Master2 == this->database->doorsOnLine4[5]) && this->database->CTHM_EDCU8On)
                       || (this->database->CTHM_EDCU7On && this->database->CTHM_EDCU8On)),
                       this->database->hmiEDCU4_Door6Cut, this->database->hmiEDCU4_Door6SeriousFlt, this->database->hmiEDCU4_Door6SlightFlt, this->database->hmiEDCU4_Door6EMCunclock,
                       this->database->hmiEDCU4_Door6OpenHinder || this->database->hmiEDCU4_Door6CloseHinder, this->database->hmiEDCU4_Door6NotOandCFB, this->database->hmiEDCU4_Door6Opened,
                       this->database->hmiEDCU4_Door6CloseFB, this->database->hmiEDCU4_Door6Closed);
    this->setDoorState(ui->label_car3Valve7, this->database->getBool(0xF771, 22, 6) && (((Master1 == this->database->doorsOnLine4[6]) && this->database->CTHM_EDCU7On) || ((Master2 == this->database->doorsOnLine4[6]) && this->database->CTHM_EDCU8On)
                       || (this->database->CTHM_EDCU7On && this->database->CTHM_EDCU8On)),
                       this->database->hmiEDCU4_Door7Cut, this->database->hmiEDCU4_Door7SeriousFlt, this->database->hmiEDCU4_Door7SlightFlt, this->database->hmiEDCU4_Door7EMCunclock,
                       this->database->hmiEDCU4_Door7OpenHinder || this->database->hmiEDCU4_Door7CloseHinder, this->database->hmiEDCU4_Door7NotOandCFB, this->database->hmiEDCU4_Door7Opened,
                       this->database->hmiEDCU4_Door7CloseFB, this->database->hmiEDCU4_Door7Closed);
    this->setDoorState(ui->label_car3Valve8, this->database->getBool(0xF771, 22, 7) && (((Master1 == this->database->doorsOnLine4[7]) && this->database->CTHM_EDCU7On) || ((Master2 == this->database->doorsOnLine4[7]) && this->database->CTHM_EDCU8On)
                       || (this->database->CTHM_EDCU7On && this->database->CTHM_EDCU8On)),
                       this->database->hmiEDCU4_Door8Cut, this->database->hmiEDCU4_Door8SeriousFlt, this->database->hmiEDCU4_Door8SlightFlt, this->database->hmiEDCU4_Door8EMCunclock,
                       this->database->hmiEDCU4_Door8OpenHinder || this->database->hmiEDCU4_Door8CloseHinder, this->database->hmiEDCU4_Door8NotOandCFB, this->database->hmiEDCU4_Door8Opened,
                       this->database->hmiEDCU4_Door8CloseFB, this->database->hmiEDCU4_Door8Closed);

    this->setDoorState(ui->label_car4Valve1, this->database->getBool(0xF7B1, 22, 0) && (((Master1 == this->database->doorsOnLine6[0]) && this->database->CTHM_EDCU11On) || ((Master2 == this->database->doorsOnLine6[0]) && this->database->CTHM_EDCU12On)
                       || (this->database->CTHM_EDCU11On && this->database->CTHM_EDCU12On)),
                       this->database->hmiEDCU6_Door1Cut, this->database->hmiEDCU6_Door1SeriousFlt, this->database->hmiEDCU6_Door1SlightFlt, this->database->hmiEDCU6_Door1EMCunclock,
                       this->database->hmiEDCU6_Door1OpenHinder || this->database->hmiEDCU6_Door1CloseHinder, this->database->hmiEDCU6_Door1NotOandCFB, this->database->hmiEDCU6_Door1Opened,
                       this->database->hmiEDCU6_Door1CloseFB, this->database->hmiEDCU6_Door1Closed);
    this->setDoorState(ui->label_car4Valve2, this->database->getBool(0xF7B1, 22, 1) && (((Master1 == this->database->doorsOnLine6[1]) && this->database->CTHM_EDCU11On) || ((Master2 == this->database->doorsOnLine6[1]) && this->database->CTHM_EDCU12On)
                       || (this->database->CTHM_EDCU11On && this->database->CTHM_EDCU12On)),
                       this->database->hmiEDCU6_Door2Cut, this->database->hmiEDCU6_Door2SeriousFlt, this->database->hmiEDCU6_Door2SlightFlt, this->database->hmiEDCU6_Door2EMCunclock,
                       this->database->hmiEDCU6_Door2OpenHinder || this->database->hmiEDCU6_Door2CloseHinder, this->database->hmiEDCU6_Door2NotOandCFB, this->database->hmiEDCU6_Door2Opened,
                       this->database->hmiEDCU6_Door2CloseFB, this->database->hmiEDCU6_Door2Closed);
    this->setDoorState(ui->label_car4Valve3, this->database->getBool(0xF7B1, 22, 2) && (((Master1 == this->database->doorsOnLine6[2]) && this->database->CTHM_EDCU11On) || ((Master2 == this->database->doorsOnLine6[2]) && this->database->CTHM_EDCU12On)
                       || (this->database->CTHM_EDCU11On && this->database->CTHM_EDCU12On)),
                       this->database->hmiEDCU6_Door3Cut, this->database->hmiEDCU6_Door3SeriousFlt, this->database->hmiEDCU6_Door3SlightFlt, this->database->hmiEDCU6_Door3EMCunclock,
                       this->database->hmiEDCU6_Door3OpenHinder || this->database->hmiEDCU6_Door3CloseHinder, this->database->hmiEDCU6_Door3NotOandCFB, this->database->hmiEDCU6_Door3Opened,
                       this->database->hmiEDCU6_Door3CloseFB, this->database->hmiEDCU6_Door3Closed);
    this->setDoorState(ui->label_car4Valve4, this->database->getBool(0xF7B1, 22, 3) && (((Master1 == this->database->doorsOnLine6[3]) && this->database->CTHM_EDCU11On) || ((Master2 == this->database->doorsOnLine6[3]) && this->database->CTHM_EDCU12On)
                       || (this->database->CTHM_EDCU11On && this->database->CTHM_EDCU12On)),
                       this->database->hmiEDCU6_Door4Cut, this->database->hmiEDCU6_Door4SeriousFlt, this->database->hmiEDCU6_Door4SlightFlt, this->database->hmiEDCU6_Door4EMCunclock,
                       this->database->hmiEDCU6_Door4OpenHinder || this->database->hmiEDCU6_Door4CloseHinder, this->database->hmiEDCU6_Door4NotOandCFB, this->database->hmiEDCU6_Door4Opened,
                       this->database->hmiEDCU6_Door4CloseFB, this->database->hmiEDCU6_Door4Closed);
    this->setDoorState(ui->label_car4Valve5, this->database->getBool(0xF7B1, 22, 4) && (((Master1 == this->database->doorsOnLine6[4]) && this->database->CTHM_EDCU11On) || ((Master2 == this->database->doorsOnLine6[4]) && this->database->CTHM_EDCU12On)
                       || (this->database->CTHM_EDCU11On && this->database->CTHM_EDCU12On)),
                       this->database->hmiEDCU6_Door5Cut, this->database->hmiEDCU6_Door5SeriousFlt, this->database->hmiEDCU6_Door5SlightFlt, this->database->hmiEDCU6_Door5EMCunclock,
                       this->database->hmiEDCU6_Door5OpenHinder || this->database->hmiEDCU6_Door5CloseHinder, this->database->hmiEDCU6_Door5NotOandCFB, this->database->hmiEDCU6_Door5Opened,
                       this->database->hmiEDCU6_Door5CloseFB, this->database->hmiEDCU6_Door5Closed);
    this->setDoorState(ui->label_car4Valve6, this->database->getBool(0xF7B1, 22, 5) && (((Master1 == this->database->doorsOnLine6[5]) && this->database->CTHM_EDCU11On) || ((Master2 == this->database->doorsOnLine6[5]) && this->database->CTHM_EDCU12On)
                       || (this->database->CTHM_EDCU11On && this->database->CTHM_EDCU12On)),
                       this->database->hmiEDCU6_Door6Cut, this->database->hmiEDCU6_Door6SeriousFlt, this->database->hmiEDCU6_Door6SlightFlt, this->database->hmiEDCU6_Door6EMCunclock,
                       this->database->hmiEDCU6_Door6OpenHinder || this->database->hmiEDCU6_Door6CloseHinder, this->database->hmiEDCU6_Door6NotOandCFB, this->database->hmiEDCU6_Door6Opened,
                       this->database->hmiEDCU6_Door6CloseFB, this->database->hmiEDCU6_Door6Closed);
    this->setDoorState(ui->label_car4Valve7, this->database->getBool(0xF7B1, 22, 6) && (((Master1 == this->database->doorsOnLine6[6]) && this->database->CTHM_EDCU11On) || ((Master2 == this->database->doorsOnLine6[6]) && this->database->CTHM_EDCU12On)
                       || (this->database->CTHM_EDCU11On && this->database->CTHM_EDCU12On)),
                       this->database->hmiEDCU6_Door7Cut, this->database->hmiEDCU6_Door7SeriousFlt, this->database->hmiEDCU6_Door7SlightFlt, this->database->hmiEDCU6_Door7EMCunclock,
                       this->database->hmiEDCU6_Door7OpenHinder || this->database->hmiEDCU6_Door7CloseHinder, this->database->hmiEDCU6_Door7NotOandCFB, this->database->hmiEDCU6_Door7Opened,
                       this->database->hmiEDCU6_Door7CloseFB, this->database->hmiEDCU6_Door7Closed);
    this->setDoorState(ui->label_car4Valve8, this->database->getBool(0xF7B1, 22, 7) && (((Master1 == this->database->doorsOnLine6[7]) && this->database->CTHM_EDCU11On) || ((Master2 == this->database->doorsOnLine6[7]) && this->database->CTHM_EDCU12On)
                       || (this->database->CTHM_EDCU11On && this->database->CTHM_EDCU12On)),
                       this->database->hmiEDCU6_Door8Cut, this->database->hmiEDCU6_Door8SeriousFlt, this->database->hmiEDCU6_Door8SlightFlt, this->database->hmiEDCU6_Door8EMCunclock,
                       this->database->hmiEDCU6_Door8OpenHinder || this->database->hmiEDCU6_Door8CloseHinder, this->database->hmiEDCU6_Door8NotOandCFB, this->database->hmiEDCU6_Door8Opened,
                       this->database->hmiEDCU6_Door8CloseFB, this->database->hmiEDCU6_Door8Closed);

    //riding Rate
    this->setRidingRate(ui->label_car1RidingRate, QString::number(this->database->ridingRateTc1) + "%");
    this->setRidingRate(ui->label_car2RidingRate, QString::number(this->database->ridingRateMp1) + "%");
    this->setRidingRate(ui->label_car3RidingRate, QString::number(this->database->ridingRateMp2) + "%");
    this->setRidingRate(ui->label_car4RidingRate, QString::number(this->database->ridingRateTc2) + "%");

    //air compressor
    this->getAPAbnormal(ui->label_APAbnormal1, this->database->DICT_Tc1DI4I12AirCmpPowerFlt_A1);
    this->getAPAbnormal(ui->label_APAbnormal4, this->database->DICT_Tc2DI4I12AirCmpPowerFlt_A2);
    this->getPreStart(ui->label_APPreStart1, this->database->DICT_Tc1DI4I11AirCmpPreStart_A1);
    this->getPreStart(ui->label_APPreStart4, this->database->DICT_Tc2DI4I11AirCmpPreStart_A2);
    this->getOverLoad(ui->label_APOverLoad1, this->database->DICT_Tc1DI4I10AirCmpHotOverload_A1);
    this->getOverLoad(ui->label_APOverLoad4, this->database->DICT_Tc2DI4I10AirCmpHotOverload_A2);
    this->getRun(ui->label_APRun1, this->database->DICT_Tc1DI4I9AirCmpRun_A1);
    this->getRun(ui->label_APRun4, this->database->DICT_Tc2DI4I9AirCmpRun_A2);
}

void RunStatePage::setRidingRate(QLabel *label, QString rate)
{
    label->setText(rate);
}
void RunStatePage::setAssistantState(QLabel *label, bool onState, bool stopState, bool faultState, bool runState, int outputVoltage)
{
    if(!onState)
    {
        label->setStyleSheet(_OFFLINE);
        label->setText("");
        return;
    }
    else if(stopState)
    {
        label->setStyleSheet(_BLACK);
        label->setText(QString("停机"));
        return;
    }
    else if(faultState)
    {
        label->setStyleSheet(_RED);
        label->setText("");
        return;
    }
    else if(runState)
    {
        label->setStyleSheet(_GREEN);
        label->setText(QString::number(outputVoltage));
        return;
    }
    else
    {
        label->setStyleSheet(_BLACK);
        label->setText(" ");
        _LOG << "RunState in error state" ;
        return;
    }
}

void RunStatePage::setTractionState(QLabel *label, bool onState, bool cutOffState, bool faultState, int current)
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
        label->setStyleSheet(_RED);
        label->setText("");
        return;
    }
    else
    {
        label->setStyleSheet(_GREEN);
        label->setText(QString::number(current));
        return;
    }
}

void RunStatePage::setBrakeState(QLabel *label, bool onState, bool emergencyState, bool keepState, bool airState, bool stayState)
{
    if(!onState)
    {
        label->setStyleSheet(_OFFLINE);
        label->setText("");
        return;
    }
//    else if(faultState)
//    {
//        label->setStyleSheet(_RED);
//        label->setText("");
//        return;
//    }
    else if(emergencyState || keepState || airState || stayState)
    {
        label->setStyleSheet(_RED);
        label->setText("制动");
        return;
    }

//    else if(airState)
//    {
//        label->setStyleSheet(_AIR_BRAKE);
//        label->setText("空气制动");
//        return;
//    }
//    else if(keepState)
//    {
//        label->setStyleSheet(_RED);
//        label->setText("保持制动");
//        return;
//    }
//    else if(airStateError)
//    {
//        label->setStyleSheet(_RED);
//        label->setText("空气制动故障");
//        return;
//    }
    else
    {
        label->setStyleSheet(_GREEN);
        label->setText("缓解");
        return;
    }
}

void RunStatePage::getTemperature(QLabel *label, bool onState, QString temperature)
{
    if(!onState)
    {
        label->setStyleSheet(_OFFLINE);
        return;
    }
    else
    {
        label->setStyleSheet(_BLACK);
        label->setText(temperature);
    }
}

void RunStatePage::getOuterTemperature(QLabel *label, bool onState, int temperature)
{
    if(!onState)
    {
        label->setStyleSheet(_OFFLINE);
        return;
    }
    else
    {
        int realTemperature = temperature - 40;
        label->setStyleSheet(_BLACK);
        label->setText(QString::number(realTemperature));
    }

}



//void RunStatePage::getBrakePressure(QLabel *label, signed short pressureValue)
//{
//    double currentPressure = pressureValue * 0.1;
//    label->setStyleSheet(_BLACK);
//    label->setText(QString::number(currentPressure, 'f', 1));
//    return;

//}

void RunStatePage::setWashMode(QLabel *label, bool washMode)
{
    if(washMode)
    {
        label->show();
        label->setStyleSheet(_GREEN);
        return;
    }
    else
    {
        label->hide();
        return;
    }
}

void RunStatePage::on_btn_EmergencyBroadcast_clicked()
{
    emit this->changePage(uEmergencyBroadcast);
}

bool RunStatePage::setAirBrakeState(bool release, bool apply)
{
    if(release)
    {
        //this->currentAirBrakeState = false;
        return false;
    }
    else if(apply)
    {
        //this->currentAirBrakeState = false;
        return true;
    }
    else
    {
        //this->currentAirBrakeState = true;
        return false;
    }
}
bool RunStatePage::setParkBrakeState(bool release, bool apply)
{
    if (release)
    {
        return false;
    }
    else if (apply)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void RunStatePage::setDoorState(QLabel *label, bool onLine, bool cut, bool seriousFault, bool slightFault, bool emergencyUnlock, bool obstacle, bool notInPlace, bool open, bool close, bool lock)
{
    if (!onLine)
    {
        label->setStyleSheet(_OFFLINE);
        return;
    }
    else if(cut)
    {
        label->setStyleSheet(_CUT);
        return;
    }
    else if(seriousFault)
    {
        label->setStyleSheet(_RED);
        return;
    }
    else if(slightFault)
    {
        label->setStyleSheet(_SLIGHT_FAULT);
        return;
    }
    else if(emergencyUnlock)
    {
        label->setStyleSheet(_DOOR_EMERGENCY);
        return;
    }
    else if(obstacle)
    {
        label->setStyleSheet(_DOOR_BLOCK);
        return;
    }
    else if(notInPlace)
    {
        label->setStyleSheet(_DOOR_OPENERROR);
        return;
    }
    else if(open)
    {
        label->setStyleSheet(_GREEN);
        return;
    }
    else if(close)
    {
        label->setStyleSheet(_DOOR_CLOSE);
        return;
    }
    else if(lock)
    {
        label->setStyleSheet(_DOOR_LOCK);
        return;
    }
    else
    {
        label->setStyleSheet(_BLACK);
        _LOG << label->text() << "  is in fault state, please check ";
        return;
    }
}

void RunStatePage::getAPAbnormal(QLabel *label, bool abnormal)
{
    if (abnormal)
    {
        label->setStyleSheet(_RED);
    }
    else
    {
        label->setStyleSheet(_BLACK);
    }
}


void RunStatePage::getPreStart(QLabel *label, bool start)
{
    if (start)
    {
        label->setStyleSheet(_YELLOW);
    }
    else
    {
        label->setStyleSheet(_BLACK);
    }
}

void RunStatePage::getOverLoad(QLabel *label, bool overLoad)
{
    if (overLoad)
    {
        label->setStyleSheet(_OVERLOAD);
    }
    else
    {
        label->setStyleSheet(_BLACK);
    }
}

void RunStatePage::getRun(QLabel *label, bool run)
{
    if (run)
    {
        label->setStyleSheet(_GREEN);
    }
    else
    {
        label->setStyleSheet(_BLACK);
    }
}

void RunStatePage::setExtentPower(QLabel *label, bool valid)
{
    if (valid)
    {
        label->setStyleSheet(_GREEN);
        label->setText("扩展供电有效");
    }
    else
    {
        label->setStyleSheet(_BLACK);
        label->setText("扩展供电无效");
    }
}
