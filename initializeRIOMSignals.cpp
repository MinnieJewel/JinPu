#include "database.h"
#include "global.h"
#include <QDebug>

void Database::initializeRIOMSignals()
{
    this->riomRM = false;
    this->riomATP = false;
    this->riomATO = false;
    this->riomATCCutOff = false;
    this->riomWashMode = false;
    this->riomATB = false;
    this->riomIATP = false;
}

void Database::synchronizeRIOMSignals()
{
    // port 0x110
    this->GWCT_RIOMTc1GWLfSign_A1 = getUnsignedChar(0x110,0);
    if(this->CTHM_TC1RIOMGWOn)
        this->gwVersionTc1.sprintf("%2d.%-d", getUnsignedChar(0x110,1) / 10, getUnsignedChar(0x110,1) % 10);
    else
        this->gwVersionTc1 = QString("0");

    if(this->CTHM_TC1DI1On && this->CTHM_TC1DI2On && this->CTHM_TC1DI3On && this->CTHM_TC1DI4On)
        this->diVersionTc1.sprintf("%2d.%-d", getUnsignedChar(0x110,2) / 10, getUnsignedChar(0x110,2) % 10);
    else
        this->diVersionTc1 = QString("0");

    if(this->CTHM_TC1DO1On)
        this->doVersionTc1.sprintf("%2d.%-d", getUnsignedChar(0x110,3) / 10, getUnsignedChar(0x110,3) % 10);
    else
        this->doVersionTc1 = QString("0");

    if(this->CTHM_TC1AX1On)
        this->axVersionTc1.sprintf("%2d.%-d", getUnsignedChar(0x110,4) / 10, getUnsignedChar(0x110,4) % 10);
    else
        this->axVersionTc1 = QString("0");

    this->DICT_RIOMTc1LfSignDI1_A1 = getUnsignedChar(0x110,6);
    this->DICT_RIOMTc1LfSignDI2_A1 = getUnsignedChar(0x110,7);
    this->DICT_RIOMTc1LfSignDI3_A1 = getUnsignedChar(0x110,8);
    this->DICT_RIOMTc1LfSignDI4_A1 = getUnsignedChar(0x110,9);
    this->DOCT_RIOMTc1LfSignDO1_A1 = getUnsignedChar(0x110,14);
    this->AICT_RIOMTc1LfSignAX1_A1 = getUnsignedChar(0x110,18);
    this->DICT_RIOMTc1Flt1500DIM1_A1 = getBool(0x110,24,0);
    this->DICT_RIOMTc1Flt1500DIM2_A1 = getBool(0x110,24,1);
    this->DICT_RIOMTc1Flt1500DIM3_A1 = getBool(0x110,24,2);
    this->DICT_RIOMTc1Flt1500DIM4_A1 = getBool(0x110,24,3);
    this->DOCT_RIOMTc1Flt1500DOM1_A1 = getBool(0x110,25,0);
    this->AICT_RIOMTc1Flt1500AXM1_A1 = getBool(0x110,25,4);
    this->DICT_RIOMTc1Flt3000DIM1_A1 = getBool(0x110,27,0);
    this->DICT_RIOMTc1Flt3000DIM2_A1 = getBool(0x110,27,1);
    this->DICT_RIOMTc1Flt3000DIM3_A1 = getBool(0x110,27,2);
    this->DICT_RIOMTc1Flt3000DIM4_A1 = getBool(0x110,27,3);
    this->DOCT_RIOMTc1Flt3000DOM1_A1 = getBool(0x110,28,0);
    this->AICT_RIOMTc1Flt3000AXM1_A1 = getBool(0x110,28,4);
    this->GWCT_RIOMTc1LAT_A1 = getBool(0x110,30,0);
    this->GWCT_RIOMTc1RLD_A1 = getBool(0x110,30,1);

    // port 0x111
    this->AICT_Tc1AI1ATCLevelA_A1 = getUnsignedInt(0x111,0);
    this->AICT_Tc1AI2ATCLevelB_A1 = getUnsignedInt(0x111,2);
    this->AICT_Tc1AI5DCLevelADup_A1 = getUnsignedInt(0x111,8);
    this->AICT_Tc1AI6DCLevelBDup_A1 = getUnsignedInt(0x111,10);
    this->AICT_Tc1AI7DriverControllerLevelA_A1 = getUnsignedInt(0x111,12);
    this->AICT_Tc1AI8DriverControllerLevelB_A1 = getUnsignedInt(0x111,14);
    this->DICT_Tc1DI1I20DrLCloseCmd_A1 = getBool(0x111,20,4);
    this->DICT_Tc1DI1I19DrRCloseCmd_A1 = getBool(0x111,20,5);
    this->DICT_Tc1DI1I18EmgyDoorStatus_A1 = getBool(0x111,20,6);
    this->DICT_Tc1DI1I17CabDrRightStatus_A1 = getBool(0x111,20,7);
    this->DICT_Tc1DI1I16CabDrLeftStatus_A1 = getBool(0x111,21,0);
    this->DICT_Tc1DI1I15AllDoorClosed_A1 = getBool(0x111,21,1);
    this->DICT_Tc1DI1I14DrLOpenCmd_A1 = getBool(0x111,21,2);
    this->DICT_Tc1DI1I13DrROpenCmd_A1 = getBool(0x111,21,3);
    this->DICT_Tc1DI1I12DrLeftEnable_A1 = getBool(0x111,21,4);
    this->DICT_Tc1DI1I11DrRightEnable_A1 = getBool(0x111,21,5);
    this->DICT_Tc1DI1I8Brake_A1 = getBool(0x111,22,0);
    this->DICT_Tc1DI1I7Traction_A1 = getBool(0x111,22,1);
    this->DICT_Tc1DI1I6FastBrk_A1 = getBool(0x111,22,2);
    this->DICT_Tc1DI1I5Brake_A1 = getBool(0x111,22,3);
    this->DICT_Tc1DI1I4Traction_A1 = getBool(0x111,22,4);
    this->DICT_Tc1DI1I3DriverRoomAct_A1 = getBool(0x111,22,5);
    this->DICT_Tc1DI1I2Backward_A1 = getBool(0x111,22,6);
    this->DICT_Tc1DI1I1Forward_A1 = getBool(0x111,22,7);
    this->DICT_Tc1DI2I23LuminairePower4_A1 = getBool(0x111,23,1);
    this->DICT_Tc1DI2I22LuminairePower3_A1 = getBool(0x111,23,2);
    this->DICT_Tc1DI2I21LuminairePower2_A1 = getBool(0x111,23,3);
    this->DICT_Tc1DI2I20LuminairePower1_A1 = getBool(0x111,23,4);
    this->DICT_Tc1DI2I19ParkingBrkCutOut_A1 = getBool(0x111,23,5);
    this->DICT_Tc1DI2I18Bogie2Cut_A1 = getBool(0x111,23,6);
    this->DICT_Tc1DI2I17Bogie1Cut_A1 = getBool(0x111,23,7);
    this->DICT_Tc1DI2I16BCUCut_A1 = getBool(0x111,24,0);
    this->DICT_Tc1DI2I15VVVFCut_A1 = getBool(0x111,24,1);
    this->DICT_Tc1DI2I14VVVFReset_A1 = getBool(0x111,24,2);
    this->DICT_Tc1DI2I13WindPressBtn_A1 = getBool(0x111,24,3);
    this->DICT_Tc1DI2I12BCUMainFlt_A1 = getBool(0x111,24,4);
    this->DICT_Tc1DI2I11EBCutBtn_A1 = getBool(0x111,24,5);
    this->DICT_Tc1DI2I8Brake_A1 = getBool(0x111,25,0);
    this->DICT_Tc1DI2I7Traction_A1 = getBool(0x111,25,1);
    this->DICT_Tc1DI2I6FastBrk_A1 = getBool(0x111,25,2);
    this->DICT_Tc1DI2I5Brake_A1 = getBool(0x111,25,3);
    this->DICT_Tc1DI2I4Traction_A1 = getBool(0x111,25,4);
    this->DICT_Tc1DI2I3DriverRoomAct_A1 = getBool(0x111,25,5);
    this->DICT_Tc1DI2I2Backward_A1 = getBool(0x111,25,6);
    this->DICT_Tc1DI2I1Forward_A1 = getBool(0x111,25,7);
    this->DICT_Tc1DI3I19BatCtrlBreakerSta_A1 = getBool(0x111,26,5);
    this->DICT_Tc1DI3I18BatBreakerSta_A1 = getBool(0x111,26,6);
    this->DICT_Tc1DI3I16EmgySta_A1 = getBool(0x111,27,0);
    this->DICT_Tc1DI3I15ForceRelBtn_A1 = getBool(0x111,27,1);
    this->DICT_Tc1DI3I14ParkingBrk_A1 = getBool(0x111,27,2);
    this->DICT_Tc1DI3I13HSCBConBtn_A1 = getBool(0x111,27,3);
    this->DICT_Tc1DI3I12ADDByPass_A1 = getBool(0x111,27,4);
    this->DICT_Tc1DI3I11EmgyBrkButton_A1 = getBool(0x111,27,5);
    this->DICT_Tc1DI3I9WindWhistleBtn_A1 = getBool(0x111,27,7);
    this->DICT_Tc1DI3I8EleWhistleBtn_A1 = getBool(0x111,28,0);
    this->DICT_Tc1DI3I7StopBrkRelBtn_A1 = getBool(0x111,28,1);
    this->DICT_Tc1DI3I6StopBrkInBtn_A1 = getBool(0x111,28,2);
    this->DICT_Tc1DI3I5BrkNotRelByPass_A1 = getBool(0x111,28,3);
    this->DICT_Tc1DI3I4ParkingBrkByPass_A1 = getBool(0x111,28,4);
    this->DICT_Tc1DI3I3EmcByPass_A1 = getBool(0x111,28,5);
    this->DICT_Tc1DI3I2DoorSafeByPass_A1 = getBool(0x111,28,6);
    this->DICT_Tc1DI3I1NotZeroSpeed_A1 = getBool(0x111,28,7);


    // port 0x112
    this->DICT_Tc1DI4I23DC24V = getBool(0x112,20,1);
    this->DICT_Tc1DI4I22SivRun_A1 = getBool(0x112,20,2);
    this->DICT_Tc1DI4I21SivFlt_A1 = getBool(0x112,20,3);
    this->DICT_Tc1DI4I20SendBackSta_A1 = getBool(0x112,20,4);
    this->DICT_Tc1DI4I19EMCMode_A1 = getBool(0x112,20,5);
    this->DICT_Tc1DI4I18HeaterNetCtrl_A1 = getBool(0x112,20,6);
    this->DICT_Tc1DI4I17HeaterCh2_A1 = getBool(0x112,20,7);
    this->DICT_Tc1DI4I16HeaterCh1_A1 = getBool(0x112,21,0);
    this->DICT_Tc1DI4I15HighAcceMode_A1 = getBool(0x112,21,1);
    this->DICT_Tc1DI4I14DeadmanPress_A1 = getBool(0x112,21,2);
    this->DICT_Tc1DI4I13DeadmanLoosen_A1 = getBool(0x112,21,3);
    this->DICT_Tc1DI4I12AirCmpPowerFlt_A1 = getBool(0x112,21,4);
    this->DICT_Tc1DI4I11AirCmpPreStart_A1 = getBool(0x112,21,5);
    this->DICT_Tc1DI4I10AirCmpHotOverload_A1 = getBool(0x112,21,6);
    this->DICT_Tc1DI4I9AirCmpRun_A1 = getBool(0x112,21,7);
    this->DICT_Tc1DI4I8ATOSwitch_A1 = getBool(0x112,22,0);
    this->DICT_Tc1DI4I7ATBMode_A1 = getBool(0x112,22,1);
    this->DICT_Tc1DI4I6ATPMode_A1 = getBool(0x112,22,2);
    this->DICT_Tc1DI4I5IATPMode_A1 = getBool(0x112,22,3);
    this->DICT_Tc1DI4I4RMMode_A1 = getBool(0x112,22,4);
    this->DICT_Tc1DI4I3ATCCut_A1 = getBool(0x112,22,5);
    this->Tc1DI4I2 = getBool(0x112,22,6);
    this->DICT_Tc1DI4I1WorkShopPower_A1 = getBool(0x112,22,7);


    // port 0x120

    this->GWCT_RIOMM1GWVer_A1 = getUnsignedChar(0x120,1);
    this->DICT_RIOMM1DIMVer_A1 = getUnsignedChar(0x120,2);
    this->DOCT_RIOMM1DOMVer_A1 = getUnsignedChar(0x120,3);
    this->DICT_RIOMM1LfSignDI1_A1 = getUnsignedChar(0x120,6);
    this->DOCT_RIOMM1LfSignDO1_A1 = getUnsignedChar(0x120,14);
    this->DICT_RIOMM1Flt1500DIM1_A1 = getBool(0x120,24,0);
    this->DOCT_RIOMM1Flt1500DOM1_A1 = getBool(0x120,25,0);
    this->DICT_RIOMM1Flt3000DIM1_A1 = getBool(0x120,27,0);
    this->DOCT_RIOMM1Flt3000DOM1_A1 = getBool(0x120,28,0);
    this->GWCT_RIOMM1LAT_A1 = getBool(0x120,30,0);
    this->GWCT_RIOMM1RLD_A1 = getBool(0x120,30,1);

    // port 0x130

    if(this->CTHM_Mp1RIOMGWOn)
        this->gwVersionMp1.sprintf("%2d.%-d", getUnsignedChar(0x130,1) / 10, getUnsignedChar(0x130,1) % 10);
    else
        this->gwVersionMp1 = QString("0");

    if(this->CTHM_M1DI1On)
        this->diVersionMp1.sprintf("%2d.%-d", getUnsignedChar(0x130,2) / 10, getUnsignedChar(0x130,2) % 10);
    else
        this->diVersionMp1 = QString("0");

    if(this->CTHM_M1DO1On)
        this->doVersionMp1.sprintf("%2d.%-d", getUnsignedChar(0x130,3) / 10, getUnsignedChar(0x130,3) % 10);
    else
        this->doVersionMp1 = QString("0");

    this->GWCT_RIOMMp1GWLfSign_A1 = getUnsignedChar(0x130,0);

    this->DICT_RIOMMp1LfSignDI1_A1 = getUnsignedChar(0x130,6);
    this->DOCT_RIOMMp1LfSignDO1_A1 = getUnsignedChar(0x130,14);
    this->DICT_RIOMMp1Flt1500DIM1_A1 = getBool(0x130,24,0);
    this->DOCT_RIOMMp1Flt1500DOM1_A1 = getBool(0x130,25,0);
    this->DICT_RIOMMp1Flt3000DIM1_A1 = getBool(0x130,27,0);
    this->DOCT_RIOMMp1Flt3000DOM1_A1 = getBool(0x130,28,0);
    this->GWCT_RIOMMp1LAT_A1 = getBool(0x130,30,0);
    this->GWCT_RIOMMp1RLD_A1 = getBool(0x130,30,1);

    // port 0x131
    this->DICT_Mp1DI1I21FirstRisePanPump_A1 = getBool(0x131,20,3);
    this->DICT_Mp1DI1I20ADDDropPan_A1 = getBool(0x131,20,4);
    this->DICT_Mp1DI1I19PanDropped_A1 = getBool(0x131,20,5);
    this->DICT_Mp1DI1I18PanRised_A1 = getBool(0x131,20,6);
    this->DICT_Mp1DI1I17ExPowerSta_A1 = getBool(0x131,20,7);
    this->DICT_M1DI1I16ExpandPower_A1 = getBool(0x131,21,0);
    this->DICT_M1DI1I15ExpandPowerFB_A1 = getBool(0x131,21,1);
    this->DICT_M1DI1I14BHBStaFB_A1 = getBool(0x131,21,2);
    this->DICT_M1DI1I13MainFuseOn_A1 = getBool(0x131,21,3);
    this->DICT_M1DI1I11BCUMainFlt_A1 = getBool(0x131,21,5);
    this->DICT_M1DI1I10BCUCut_A1 = getBool(0x131,21,6);
    this->DICT_Mp1DI1I9HeaterCh2_A1 = getBool(0x131,21,7);
    this->DICT_Mp1DI1I8HeaterCh1_A1 = getBool(0x131,22,0);
    this->DICT_Mp1DI1I7LuminairePower4_A1 = getBool(0x131,22,1);
    this->DICT_Mp1DI1I6LuminairePower3_A1 = getBool(0x131,22,2);
    this->DICT_Mp1DI1I5LuminairePower2_A1 = getBool(0x131,22,3);
    this->DICT_Mp1DI1I4LuminairePower1_A1 = getBool(0x131,22,4);
    this->DICT_Mp1DI1I3ParkingBrkCutOut_A1 = getBool(0x131,22,5);
    this->DICT_Mp1DI1I2Bogie2Cut_A1 = getBool(0x131,22,6);
    this->DICT_Mp1DI1I1Bogie1Cut_A1 = getBool(0x131,22,7);

    // port 0x160
    this->GWCT_RIOMTc2GWLfSign_A2 = getUnsignedChar(0x160,0);
    if(this->CTHM_TC2RIOMGWOn)
        this->gwVersionTc2.sprintf("%2d.%-d", getUnsignedChar(0x160,1) / 10, getUnsignedChar(0x160,1) % 10);
    else
        this->gwVersionTc2 = QString("0");

    if(this->CTHM_TC2DI1On && this->CTHM_TC2DI2On && this->CTHM_TC2DI3On && this->CTHM_TC2DI4On)
        this->diVersionTc2.sprintf("%2d.%-d", getUnsignedChar(0x160,2) / 10, getUnsignedChar(0x160,2) % 10);
    else
        this->diVersionTc2 = QString("0");

    if(this->CTHM_TC2DO1On)
        this->doVersionTc2.sprintf("%2d.%-d", getUnsignedChar(0x160,3) / 10, getUnsignedChar(0x160,3) % 10);
    else
        this->doVersionTc2 = QString("0");

    if(this->CTHM_TC2AX1On)
        this->axVersionTc2.sprintf("%2d.%-d", getUnsignedChar(0x160,4) / 10, getUnsignedChar(0x160,4) % 10);
    else
        this->axVersionTc2 = QString("0");

    this->DICT_RIOMTc2LfSignDI1_A2 = getUnsignedChar(0x160,6);
    this->DICT_RIOMTc2LfSignDI2_A2 = getUnsignedChar(0x160,7);
    this->DICT_RIOMTc2LfSignDI3_A2 = getUnsignedChar(0x160,8);
    this->DICT_RIOMTc2LfSignDI4_A2 = getUnsignedChar(0x160,9);
    this->DOCT_RIOMTc2LfSignDO1_A2 = getUnsignedChar(0x160,14);
    this->AICT_RIOMTc2LfSignAX1_A2 = getUnsignedChar(0x160,18);
    this->DICT_RIOMTc2Flt1500DIM1_A2 = getBool(0x160,24,0);
    this->DICT_RIOMTc2Flt1500DIM2_A2 = getBool(0x160,24,1);
    this->DICT_RIOMTc2Flt1500DIM3_A2 = getBool(0x160,24,2);
    this->DICT_RIOMTc2Flt1500DIM4_A2 = getBool(0x160,24,3);
    this->DOCT_RIOMTc2Flt1500DOM1_A2 = getBool(0x160,25,0);
    this->AICT_RIOMTc2Flt1500AXM1_A2 = getBool(0x160,25,4);
    this->DICT_RIOMTc2Flt3000DIM1_A2 = getBool(0x160,27,0);
    this->DICT_RIOMTc2Flt3000DIM2_A2 = getBool(0x160,27,1);
    this->DICT_RIOMTc2Flt3000DIM3_A2 = getBool(0x160,27,2);
    this->DICT_RIOMTc2Flt3000DIM4_A2 = getBool(0x160,27,3);
    this->DOCT_RIOMTc2Flt3000DOM1_A2 = getBool(0x160,28,0);
    this->AICT_RIOMTc2Flt3000AXM1_A2 = getBool(0x160,28,4);
    this->GWCT_RIOMTc2LAT_A2 = getBool(0x160,30,0);
    this->GWCT_RIOMTc2RLD_A2 = getBool(0x160,30,1);

    // port 0x161
    this->AICT_Tc2AI1ATCLevelA_A2 = getUnsignedInt(0x161,0);
    this->AICT_Tc2AI2ATCLevelB_A2 = getUnsignedInt(0x161,2);
    this->AICT_Tc2AI5DCLevelADup_A2 = getUnsignedInt(0x161,8);
    this->AICT_Tc2AI6DCLevelBDup_A2 = getUnsignedInt(0x161,10);
    this->AICT_Tc2AI7DriverControllerLevelA_A2 = getUnsignedInt(0x161,12);
    this->AICT_Tc2AI8DriverControllerLevelB_A2 = getUnsignedInt(0x161,14);
    this->DICT_Tc2DI1I20DrLCloseCmd_A2 = getBool(0x161,20,4);
    this->DICT_Tc2DI1I19DrRCloseCmd_A2 = getBool(0x161,20,5);
    this->DICT_Tc2DI1I18EmgyDoorStatus_A2 = getBool(0x161,20,6);
    this->DICT_Tc2DI1I17CabDrRightStatus_A2 = getBool(0x161,20,7);
    this->DICT_Tc2DI1I16CabDrLeftStatus_A2 = getBool(0x161,21,0);
    this->DICT_Tc2DI1I15AllDoorClosed_A2 = getBool(0x161,21,1);
    this->DICT_Tc2DI1I14DrLOpenCmd_A2 = getBool(0x161,21,2);
    this->DICT_Tc2DI1I13DrROpenCmd_A2 = getBool(0x161,21,3);
    this->DICT_Tc2DI1I12DrLeftEnable_A2 = getBool(0x161,21,4);
    this->DICT_Tc2DI1I11DrRightEnable_A2 = getBool(0x161,21,5);
    this->DICT_Tc2DI1I8Brake_A2 = getBool(0x161,22,0);
    this->DICT_Tc2DI1I7Traction_A2 = getBool(0x161,22,1);
    this->DICT_Tc2DI1I6FastBrk_A2 = getBool(0x161,22,2);
    this->DICT_Tc2DI1I5Brake_A2 = getBool(0x161,22,3);
    this->DICT_Tc2DI1I4Traction_A2 = getBool(0x161,22,4);
    this->DICT_Tc2DI1I3DriverRoomAct_A2 = getBool(0x161,22,5);
    this->DICT_Tc2DI1I2Backward_A2 = getBool(0x161,22,6);
    this->DICT_Tc2DI1I1Forward_A2 = getBool(0x161,22,7);
    this->DICT_Tc2DI2I23LuminairePower4_A2 = getBool(0x161,23,1);
    this->DICT_Tc2DI2I22LuminairePower3_A2 = getBool(0x161,23,2);
    this->DICT_Tc2DI2I21LuminairePower2_A2 = getBool(0x161,23,3);
    this->DICT_Tc2DI2I20LuminairePower1_A2 = getBool(0x161,23,4);
    this->DICT_Tc2DI2I19ParkingBrkCutOut_A2 = getBool(0x161,23,5);
    this->DICT_Tc2DI2I18Bogie2Cut_A2 = getBool(0x161,23,6);
    this->DICT_Tc2DI2I17Bogie1Cut_A2 = getBool(0x161,23,7);
    this->DICT_Tc2DI2I16BCUCut_A2 = getBool(0x161,24,0);
    this->DICT_Tc2DI2I15VVVFCut_A2 = getBool(0x161,24,1);
    this->DICT_Tc2DI2I14VVVFReset_A2 = getBool(0x161,24,2);
    this->DICT_Tc2DI2I13WindPressBtn_A2 = getBool(0x161,24,3);
    this->DICT_Tc2DI2I12BCUMainFlt_A2 = getBool(0x161,24,4);
    this->DICT_Tc2DI2I11EBCutBtn_A2 = getBool(0x161,24,5);
    this->DICT_Tc2DI2I8Brake_A2 = getBool(0x161,25,0);
    this->DICT_Tc2DI2I7Traction_A2 = getBool(0x161,25,1);
    this->DICT_Tc2DI2I6FastBrk_A2 = getBool(0x161,25,2);
    this->DICT_Tc2DI2I5Brake_A2 = getBool(0x161,25,3);
    this->DICT_Tc2DI2I4Traction_A2 = getBool(0x161,25,4);
    this->DICT_Tc2DI2I3DriverRoomAct_A2 = getBool(0x161,25,5);
    this->DICT_Tc2DI2I2Backward_A2 = getBool(0x161,25,6);
    this->DICT_Tc2DI2I1Forward_A2 = getBool(0x161,25,7);
    this->DICT_Tc2DI3I19BatCtrlBreakerSta_A2 = getBool(0x161,26,5);
    this->DICT_Tc2DI3I18BatBreakerSta_A2 = getBool(0x161,26,6);
    this->DICT_Tc2DI3I16EmgySta_A2 = getBool(0x161,27,0);
    this->DICT_Tc2DI3I15ForceRelBtn_A2 = getBool(0x161,27,1);
    this->DICT_Tc2DI3I14ParkingBrk_A2 = getBool(0x161,27,2);
    this->DICT_Tc2DI3I13HSCBConBtn_A2 = getBool(0x161,27,3);
    this->DICT_Tc2DI3I12ADDByPass_A2 = getBool(0x161,27,4);
    this->DICT_Tc2DI3I11EmgyBrkButton_A2 = getBool(0x161,27,5);
    this->DICT_Tc2DI3I9WindWhistleBtn_A2 = getBool(0x161,27,7);
    this->DICT_Tc2DI3I8EleWhistleBtn_A2 = getBool(0x161,28,0);
    this->DICT_Tc2DI3I7StopBrkRelBtn_A2 = getBool(0x161,28,1);
    this->DICT_Tc2DI3I6StopBrkInBtn_A2 = getBool(0x161,28,2);
    this->DICT_Tc2DI3I5BrkNotRelByPass_A2 = getBool(0x161,28,3);
    this->DICT_Tc2DI3I4ParkingBrkByPass_A2 = getBool(0x161,28,4);
    this->DICT_Tc2DI3I3EmcByPass_A2 = getBool(0x161,28,5);
    this->DICT_Tc2DI3I2DoorSafeByPass_A2 = getBool(0x161,28,6);
    this->DICT_Tc2DI3I1NotZeroSpeed_A2 = getBool(0x161,28,7);

    // port 0x162
    this->DICT_TC2DI4I23DC24V = getBool(0x162,20,1);
    this->DICT_Tc2DI4I22SivRun_A2 = getBool(0x162,20,2);
    this->DICT_Tc2DI4I21SivFlt_A2 = getBool(0x162,20,3);
    this->DICT_Tc2DI4I20SendBackSta_A2 = getBool(0x162,20,4);
    this->DICT_Tc2DI4I19EMCMode_A2 = getBool(0x162,20,5);
    this->DICT_Tc2DI4I18HeaterNetCtrl_A2 = getBool(0x162,20,6);
    this->DICT_Tc2DI4I17HeaterCh2_A2 = getBool(0x162,20,7);
    this->DICT_Tc2DI4I16HeaterCh1_A2 = getBool(0x162,21,0);
    this->DICT_Tc2DI4I15HighAcceMode_A2 = getBool(0x162,21,1);
    this->DICT_Tc2DI4I14DeadmanPress_A2 = getBool(0x162,21,2);
    this->DICT_Tc2DI4I13DeadmanLoosen_A2 = getBool(0x162,21,3);
    this->DICT_Tc2DI4I12AirCmpPowerFlt_A2 = getBool(0x162,21,4);
    this->DICT_Tc2DI4I11AirCmpPreStart_A2 = getBool(0x162,21,5);
    this->DICT_Tc2DI4I10AirCmpHotOverload_A2 = getBool(0x162,21,6);
    this->DICT_Tc2DI4I9AirCmpRun_A2 = getBool(0x162,21,7);
    this->DICT_Tc2DI4I8ATOSwitch_A2 = getBool(0x162,22,0);
    this->DICT_Tc2DI4I7ATBMode_A2 = getBool(0x162,22,1);
    this->DICT_Tc2DI4I6ATPMode_A2 = getBool(0x162,22,2);
    this->DICT_Tc2DI4I5ATPMode_A2 = getBool(0x162,22,3);
    this->DICT_Tc2DI4I4RMMode_A2 = getBool(0x162,22,4);
    this->DICT_Tc2DI4I3ATCCut_A2 = getBool(0x162,22,5);
    this->Tc2DI4I2 = getBool(0x162,22,6);
    this->DICT_Tc2DI4I1WorkShopPower_A2 = getBool(0x162,22,7);

    // port 0x150
    this->GWCT_RIOMM2GWLfSign_A2 = getUnsignedChar(0x150,0);
    this->GWCT_RIOMM2GWVer_A2 = getUnsignedChar(0x150,1);
    this->DICT_RIOMM2DIMVer_A2 = getUnsignedChar(0x150,2);
    this->DOCT_RIOMM2DOMVer_A2 = getUnsignedChar(0x150,3);
    this->DICT_RIOMM2LfSignDI1_A2 = getUnsignedChar(0x150,6);
    this->DOCT_RIOMM2LfSignDO1_A2 = getUnsignedChar(0x150,14);
    this->DICT_RIOMM2Flt1500DIM1_A2 = getBool(0x150,24,0);
    this->DOCT_RIOMM2Flt1500DOM1_A2 = getBool(0x150,25,0);
    this->DICT_RIOMM2Flt3000DIM1_A2 = getBool(0x150,27,0);
    this->DOCT_RIOMM2Flt3000DOM1_A2 = getBool(0x150,28,0);
    this->GWCT_RIOMM2LAT_A2 = getBool(0x150,30,0);
    this->GWCT_RIOMM2RLD_A2 = getBool(0x150,30,1);

    // port 0x140
    this->GWCT_RIOMMp2GWLfSign_A2 = getUnsignedChar(0x140,0);

    if(this->CTHM_Mp2RIOMGWOn)
        this->gwVersionMp2.sprintf("%2d.%-d", getUnsignedChar(0x140,1) / 10, getUnsignedChar(0x140,1) % 10);
    else
        this->gwVersionMp2 = QString("0");

    if(this->CTHM_M2DI1On)
        this->diVersionMp2.sprintf("%2d.%-d", getUnsignedChar(0x140,2) / 10, getUnsignedChar(0x140,2) % 10);
    else
        this->diVersionMp2 = QString("0");

    if(this->CTHM_M2DO1On)
        this->doVersionMp2.sprintf("%2d.%-d", getUnsignedChar(0x140,3) / 10, getUnsignedChar(0x140,3) % 10);
    else
        this->doVersionMp2 = QString("0");

    this->DICT_RIOMMp2LfSignDI1_A2 = getUnsignedChar(0x140,6);
    this->DOCT_RIOMMp2LfSignDO1_A2 = getUnsignedChar(0x140,14);
    this->DICT_RIOMMp2Flt1500DIM1_A2 = getBool(0x140,24,0);
    this->DOCT_RIOMMp2Flt1500DOM1_A2 = getBool(0x140,25,0);
    this->DICT_RIOMMp2Flt3000DIM1_A2 = getBool(0x140,27,0);
    this->DOCT_RIOMMp2Flt3000DOM1_A2 = getBool(0x140,28,0);
    this->GWCT_RIOMMp2LAT_A2 = getBool(0x140,30,0);
    this->GWCT_RIOMMp2RLD_A2 = getBool(0x140,30,1);

    // port 0x141
    this->DICT_Mp2DI1I21FirstRisePanPump_A2 = getBool(0x141,20,3);
    this->DICT_Mp2DI1I20ADDDropPan_A2 = getBool(0x141,20,4);
    this->DICT_Mp2DI1I19PanDropped_A2 = getBool(0x141,20,5);
    this->DICT_Mp2DI1I18PanRised_A2 = getBool(0x141,20,6);
    this->DICT_Mp2DI1I17ExPowerSta_A2 = getBool(0x141,20,7);
    this->DICT_M2DI1I16ExpandPower_A2 = getBool(0x141,21,0);
    this->DICT_M2DI1I15ExpandPowerFB_A2 = getBool(0x141,21,1);
    this->DICT_M2DI1I14BHBStaFB_A2 = getBool(0x141,21,2);
    this->DICT_M2DI1I13MainFuseOn_A2 = getBool(0x141,21,3);
    this->DICT_M2DI1I11BCUMainFlt_A2 = getBool(0x141,21,5);
    this->DICT_M2DI1I10BCUCut_A2 = getBool(0x141,21,6);
    this->DICT_Mp2DI1I9HeaterCh2_A2 = getBool(0x141,21,7);
    this->DICT_Mp2DI1I8HeaterCh1_A2 = getBool(0x141,22,0);
    this->DICT_Mp2DI1I7LuminairePower4_A2 = getBool(0x141,22,1);
    this->DICT_Mp2DI1I6LuminairePower3_A2 = getBool(0x141,22,2);
    this->DICT_Mp2DI1I5LuminairePower2_A2 = getBool(0x141,22,3);
    this->DICT_Mp2DI1I4LuminairePower1_A2 = getBool(0x141,22,4);
    this->DICT_Mp2DI1I3ParkingBrkCutOut_A2 = getBool(0x141,22,5);
    this->DICT_Mp2DI1I2Bogie2Cut_A2 = getBool(0x141,22,6);
    this->DICT_Mp2DI1I1Bogie1Cut_A2 = getBool(0x141,22,7);

    //Reservation
    //DI
    this->RIOM1_DIM1Ch9 = getBool(0x111,21,7);
    this->RIOM1_DIM1Ch10 = getBool(0x111,21,6);
    this->RIOM1_DIM1Ch21 = getBool(0x111,20,3);
    this->RIOM1_DIM1Ch22 = getBool(0x111,20,2);
    this->RIOM1_DIM1Ch23 = getBool(0x111,20,1);
    this->RIOM1_DIM1Ch24 = getBool(0x111,20,0);
    this->RIOM6_DIM1Ch9 = getBool(0x161,21,7);
    this->RIOM6_DIM1Ch10 = getBool(0x161,21,6);
    this->RIOM6_DIM1Ch21 = getBool(0x161,20,3);
    this->RIOM6_DIM1Ch22 = getBool(0x161,20,2);
    this->RIOM6_DIM1Ch23 = getBool(0x161,20,1);
    this->RIOM6_DIM1Ch24 = getBool(0x161,20,0);
    this->RIOM1_DIM2Ch9 = getBool(0x111,24,7);
    this->RIOM1_DIM2Ch10 = getBool(0x111,24,6);
    this->RIOM1_DIM2Ch24 = getBool(0x111,23,0);
    this->RIOM6_DIM2Ch9 = getBool(0x161,24,7);
    this->RIOM6_DIM2Ch10 = getBool(0x161,24,6);
    this->RIOM6_DIM2Ch24 = getBool(0x161,23,0);
    this->RIOM1_DIM3Ch10 = getBool(0x111,27,6);
    this->RIOM1_DIM3Ch17 = getBool(0x111,26,7);
    this->RIOM1_DIM3Ch20 = getBool(0x111,26,4);
    this->RIOM1_DIM3Ch21 = getBool(0x111,26,3);
    this->RIOM1_DIM3Ch22 = getBool(0x111,26,2);
    this->RIOM1_DIM3Ch23 = getBool(0x111,26,1);
    this->RIOM1_DIM3Ch24 = getBool(0x111,26,0);
    this->RIOM6_DIM3Ch10 = getBool(0x161,27,6);
    this->RIOM6_DIM3Ch17 = getBool(0x161,26,7);
    this->RIOM6_DIM3Ch20 = getBool(0x161,26,4);
    this->RIOM6_DIM3Ch21 = getBool(0x161,26,3);
    this->RIOM6_DIM3Ch22 = getBool(0x161,26,2);
    this->RIOM6_DIM3Ch23 = getBool(0x161,26,1);
    this->RIOM6_DIM3Ch24 = getBool(0x161,26,0);
    //this->RIOM1_DIM4Ch23 = getBool(0x112,20,1);
    this->RIOM1_DIM4Ch24 = getBool(0x112,20,0);
    //this->RIOM6_DIM4Ch23 = getBool(0x162,20,1);
    this->RIOM6_DIM4Ch24 = getBool(0x162,20,0);

    this->RIOM3_DIM1Ch10 = getBool(0x131,21,6);
    this->RIOM3_DIM1Ch11 = getBool(0x131,21,5);
    this->RIOM3_DIM1Ch12 = getBool(0x131,21,4);
    this->RIOM3_DIM1Ch18 = getBool(0x131,20,6);
    this->RIOM3_DIM1Ch19 = getBool(0x131,20,5);
    this->RIOM3_DIM1Ch22 = getBool(0x131,20,2);
    this->RIOM3_DIM1Ch23 = getBool(0x131,20,1);
    this->RIOM3_DIM1Ch24 = getBool(0x131,20,0);

    this->RIOM4_DIM1Ch10 = getBool(0x141,21,6);
    this->RIOM4_DIM1Ch11 = getBool(0x141,21,5);
    this->RIOM4_DIM1Ch12 = getBool(0x141,21,4);
    this->RIOM4_DIM1Ch18 = getBool(0x141,20,6);
    this->RIOM4_DIM1Ch19 = getBool(0x141,20,5);
    this->RIOM4_DIM1Ch22 = getBool(0x141,20,2);
    this->RIOM4_DIM1Ch23 = getBool(0x141,20,1);
    this->RIOM4_DIM1Ch24 = getBool(0x141,20,0);


    this->RIOM2_DIM1Ch10 = getBool(0x121,21,6);
    this->RIOM2_DIM1Ch11 = getBool(0x121,21,5);
    this->RIOM2_DIM1Ch12 = getBool(0x121,21,4);
    this->RIOM2_DIM1Ch19 = getBool(0x121,20,5);
    this->RIOM2_DIM1Ch22 = getBool(0x121,20,2);
    this->RIOM2_DIM1Ch23 = getBool(0x121,20,1);
    this->RIOM2_DIM1Ch24 = getBool(0x121,20,0);

    this->RIOM5_DIM1Ch10 = getBool(0x151,21,6);
    this->RIOM5_DIM1Ch11 = getBool(0x151,21,5);
    this->RIOM5_DIM1Ch12 = getBool(0x151,21,4);
    this->RIOM5_DIM1Ch19 = getBool(0x151,20,5);
    this->RIOM5_DIM1Ch22 = getBool(0x151,20,2);
    this->RIOM5_DIM1Ch23 = getBool(0x151,20,1);
    this->RIOM5_DIM1Ch24 = getBool(0x151,20,0);

    this->RIOM1_DOMIC4 = getBool(0x118,20,4);
    this->RIOM1_DOMIC5 = getBool(0x118,20,3);
    this->RIOM1_DOMIC6 = getBool(0x118,20,2);
    this->RIOM1_DOMIC7 = getBool(0x118,20,1);
    this->RIOM1_DOMIC8 = getBool(0x118,20,0);
    this->RIOM1_DOMIC9 = getBool(0x118,19,7);

    this->RIOM1_DOMIC10 = getBool(0x118,19,6);
    this->RIOM1_DOMIC11 = getBool(0x118,19,5);
    this->RIOM1_DOMIC12 = getBool(0x118,19,4);
    this->RIOM1_DOMIC13 = getBool(0x118,19,3);
    this->RIOM1_DOMIC14 = getBool(0x118,19,2);
    this->RIOM1_DOMIC15 = getBool(0x118,19,1);
    this->RIOM1_DOMIC16 = getBool(0x118,19,0);

    this->RIOM6_DOMIC4 = getBool(0x168,20,4);
    this->RIOM6_DOMIC5 = getBool(0x168,20,3);
    this->RIOM6_DOMIC6 = getBool(0x168,20,2);
    this->RIOM6_DOMIC7 = getBool(0x168,20,1);
    this->RIOM6_DOMIC8 = getBool(0x168,20,0);
    this->RIOM6_DOMIC9 = getBool(0x168,19,7);

    this->RIOM6_DOMIC10 = getBool(0x168,19,6);
    this->RIOM6_DOMIC11 = getBool(0x168,19,5);
    this->RIOM6_DOMIC12 = getBool(0x168,19,4);
    this->RIOM6_DOMIC13 = getBool(0x168,19,3);
    this->RIOM6_DOMIC14 = getBool(0x168,19,2);
    this->RIOM6_DOMIC15 = getBool(0x168,19,1);
    this->RIOM6_DOMIC16 = getBool(0x168,19,0);

    this->RIOM2_DOMIC1 = getBool(0x128,20,7);
    this->RIOM2_DOMIC2 = getBool(0x128,20,6);
    this->RIOM2_DOMIC3 = getBool(0x128,20,5);
    this->RIOM2_DOMIC4 = getBool(0x128,20,4);
    this->RIOM2_DOMIC5 = getBool(0x128,20,3);
    this->RIOM2_DOMIC6 = getBool(0x128,20,2);
    this->RIOM2_DOMIC7 = getBool(0x128,20,1);
    this->RIOM2_DOMIC8 = getBool(0x128,20,0);
    this->RIOM2_DOMIC9 = getBool(0x128,19,7);

    this->RIOM2_DOMIC10 = getBool(0x128,19,6);
    this->RIOM2_DOMIC11 = getBool(0x128,19,5);
    this->RIOM2_DOMIC12 = getBool(0x128,19,4);
    this->RIOM2_DOMIC13 = getBool(0x128,19,3);
    this->RIOM2_DOMIC14 = getBool(0x128,19,2);
    this->RIOM2_DOMIC15 = getBool(0x128,19,1);
    this->RIOM2_DOMIC16 = getBool(0x128,19,0);

    this->RIOM5_DOMIC1 = getBool(0x158,20,7);
    this->RIOM5_DOMIC2 = getBool(0x158,20,6);
    this->RIOM5_DOMIC3 = getBool(0x158,20,5);
    this->RIOM5_DOMIC4 = getBool(0x158,20,4);
    this->RIOM5_DOMIC5 = getBool(0x158,20,3);
    this->RIOM5_DOMIC6 = getBool(0x158,20,2);
    this->RIOM5_DOMIC7 = getBool(0x158,20,1);
    this->RIOM5_DOMIC8 = getBool(0x158,20,0);
    this->RIOM5_DOMIC9 = getBool(0x158,19,7);

    this->RIOM5_DOMIC10 = getBool(0x158,19,6);
    this->RIOM5_DOMIC11 = getBool(0x158,19,5);
    this->RIOM5_DOMIC12 = getBool(0x158,19,4);
    this->RIOM5_DOMIC13 = getBool(0x158,19,3);
    this->RIOM5_DOMIC14 = getBool(0x158,19,2);
    this->RIOM5_DOMIC15 = getBool(0x158,19,1);
    this->RIOM5_DOMIC16 = getBool(0x158,19,0);

    this->RIOM3_DOMIC3 = getBool(0x138,20,5);
    this->RIOM3_DOMIC4 = getBool(0x138,20,4);
    this->RIOM3_DOMIC5 = getBool(0x138,20,3);
    this->RIOM3_DOMIC6 = getBool(0x138,20,2);
    this->RIOM3_DOMIC7 = getBool(0x138,20,1);
    this->RIOM3_DOMIC8 = getBool(0x138,20,0);
    this->RIOM3_DOMIC9 = getBool(0x138,19,7);
    this->RIOM3_DOMIC10 = getBool(0x138,19,6);
    this->RIOM3_DOMIC11 = getBool(0x138,19,5);
    this->RIOM3_DOMIC12 = getBool(0x138,19,4);
    this->RIOM3_DOMIC13 = getBool(0x138,19,3);
    this->RIOM3_DOMIC14 = getBool(0x138,19,2);
    this->RIOM3_DOMIC15 = getBool(0x138,19,1);
    this->RIOM3_DOMIC16 = getBool(0x138,19,0);

    this->RIOM4_DOMIC3 = getBool(0x148,20,5);
    this->RIOM4_DOMIC4 = getBool(0x148,20,4);
    this->RIOM4_DOMIC5 = getBool(0x148,20,3);
    this->RIOM4_DOMIC6 = getBool(0x148,20,2);
    this->RIOM4_DOMIC7 = getBool(0x148,20,1);
    this->RIOM4_DOMIC8 = getBool(0x148,20,0);
    this->RIOM4_DOMIC9 = getBool(0x148,19,7);
    this->RIOM4_DOMIC10 = getBool(0x148,19,6);
    this->RIOM4_DOMIC11 = getBool(0x148,19,5);
    this->RIOM4_DOMIC12 = getBool(0x148,19,4);
    this->RIOM4_DOMIC13 = getBool(0x148,19,3);
    this->RIOM4_DOMIC14 = getBool(0x148,19,2);
    this->RIOM4_DOMIC15 = getBool(0x148,19,1);
    this->RIOM4_DOMIC16 = getBool(0x148,19,0);

    this->RIOM1_AXC3 = getBool(0x111,4,0);
    this->RIOM1_AXC4 = getBool(0x111,6,0);
    this->RIOM6_AXC3 = getBool(0x161,4,0);
    this->RIOM6_AXC4 = getBool(0x161,6,0);

    if (1 == this->hmiPosition)
    {
        this->riomRM = this->DICT_Tc1DI4I4RMMode_A1;
        this->riomATP = this->DICT_Tc1DI4I6ATPMode_A1;
        this->riomIATP = this->DICT_Tc1DI4I5IATPMode_A1;
        this->riomATB = this->DICT_Tc1DI4I7ATBMode_A1;
        this->riomATO = this->DICT_Tc1DI4I8ATOSwitch_A1;
        this->riomATCCutOff = this->DICT_Tc1DI4I3ATCCut_A1;
        this->riomWashMode = this->RIOM1_DIM3Ch20;
    }
    else if (2 == this->hmiPosition)
    {
        this->riomRM = this->DICT_Tc2DI4I4RMMode_A2;
        this->riomATP = this->DICT_Tc2DI4I6ATPMode_A2;
        this->riomIATP = this->DICT_Tc2DI4I5ATPMode_A2;
        this->riomATB = this->DICT_Tc2DI4I7ATBMode_A2;
        this->riomATO = this->DICT_Tc2DI4I8ATOSwitch_A2;
        this->riomATCCutOff = this->DICT_Tc2DI4I3ATCCut_A2;
        this->riomWashMode = this->RIOM6_DIM3Ch20;
    }
}
