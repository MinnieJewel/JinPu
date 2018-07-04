#ifndef DATABASE_H
#define DATABASE_H

#include "global.h"
#include "PixyTypes.h"
#include "PixyMvbLib.h"
#include <QList>
#include <QMap>
#include "edcudefaultlist.h"
#include "pisdefaultlist.h"
#include "bcudefaultlist.h"
#include "ermdefaultlist.h"

class Database
{
public:
    Database();

public:
    void synchronize();
    void installPorts();
    void initializeRIOMSignals();
    void initializeERMSignals();
    void initializePisSignals();
    void synchronizeBcuSignals();
    void synchronizeEDCUSignals();
    void synchronizeERMSignals();
    void synchronizePISSignals();
    void synchronizeRIOMSignals();

public:
    // software version of all device
    QString hmiVersionA1, hmiVersionA2;
    QString ccu1OsVersion, ccu1MvbVersion, ccu1SdbVersion, ccu1VxWorksVersion;
    QString ccu2OsVersion, ccu2MvbVersion, ccu2SdbVersion, ccu2VxWorksVersion;

    QString erm1OsVersion, erm2OsVersion;
    QString gwVersionTc1, gwVersionTc2, gwVersionMp1, gwVersionMp2;
    QString diVersionTc1, diVersionTc2, diVersionMp1, diVersionMp2;
    QString doVersionTc1, doVersionTc2, doVersionMp1, doVersionMp2;
    QString axVersionTc1, axVersionTc2;

    QString siv1Version, siv2Version, sivGW1Version, sivGW2version;
    QString bcuCB01Version1, bcuMVBVersion1, bcuEB01Version1;
    QString bcuCB01Version2, bcuMVBVersion2, bcuEB01Version2;

    QString dcuGwVersionMp1, dcuGwVersionMp2;
    QString dcu1VersionMp1, dcu2VersionMp1, dcu3VersionMp1, dcu4VersionMp1;
    QString dcu1VersionMp2, dcu2VersionMp2, dcu3VersionMp2, dcu4VersionMp2;

    QString hvacVersionTc1, hvacVersionTc2, hvacVersionMp1, hvacVersionMp2;
    QString edcu1VersionTc1, edcu2VersionTc1, edcu3VersionTc1, edcu4VersionTc1,
    edcu5VersionTc1, edcu6VersionTc1, edcu7VersionTc1, edcu8VersionTc1;

    QString edcu1VersionTc2, edcu2VersionTc2, edcu3VersionTc2, edcu4VersionTc2,
    edcu5VersionTc2, edcu6VersionTc2, edcu7VersionTc2, edcu8VersionTc2;

    QString edcu1VersionMp1, edcu2VersionMp1, edcu3VersionMp1, edcu4VersionMp1,
    edcu5VersionMp1, edcu6VersionMp1, edcu7VersionMp1, edcu8VersionMp1;

    QString edcu1VersionMp2, edcu2VersionMp2, edcu3VersionMp2, edcu4VersionMp2,
    edcu5VersionMp2, edcu6VersionMp2, edcu7VersionMp2, edcu8VersionMp2;

    QString pisVersion1, pisVersion2;
    QString fauVersion1, fauVersion2;

    QString bcgVersion1, bcgVersion2;
    QString bmsVersion1, bmsVersion2;

    // device online state  
    unsigned short int hmiLifeSignal;
    unsigned short int CTDO_Tc1CCULifeSign, CTDO_Tc2CCULifeSign;

    //vehicle numbers
    QString vehicleNumberA1, vehicleNumberB1, vehicleNumberC1, vehicleNumberC2, vehicleNumberB2, vehicleNumberA2;
    QString lineNo, vehicleNo;

    //the position of HMI
    int hmiPosition;

    // air-conditioner mode
    //unsigned char hmiAirconditionerMode;
    unsigned char hmiAirconditionerModeTc1;
    unsigned char hmiAirconditionerModeMp1;
    unsigned char hmiAirconditionerModeMp2;
    unsigned char hmiAirconditionerModeTc2;

    unsigned char hmiTc1Temperature;
    unsigned char hmiMp1Temperature;
    unsigned char hmiMp2Temperature;
    unsigned char hmiTc2Temperature;

    bool hmiSaveAirConditionerTc1;
    bool hmiSaveAirConditionerMp1;
    bool hmiSaveAirConditionerMp2;
    bool hmiSaveAirConditionerTc2;

    bool hmiSaveAirConditionerTempTc1;
    bool hmiSaveAirConditionerTempMp1;
    bool hmiSaveAirConditionerTempMp2;
    bool hmiSaveAirConditionerTempTc2;

    //the login password
    QString troubleShootingPassword, dataRecordSetPassword;
    //some parameters about the hardware
    //the light level -1 means it is in auto adjust mode
    int lightLevel, shoundLevel;

    // mvb ports of all devices
    QList<struct port *> hmiA1Ports, hmiA2Ports, ccuPortsA, ccuPortsB, ermPorts, riomPorts;
    QList<struct port *> bcu1Ports, bcu3Ports,bcu4Ports, bcu6Ports, dcuPorts, tcuPorts, sivPorts, edcu1Ports, edcu2Ports, pisPorts, fauPorts,
                         hvacPorts, atcPorts, pdsPorts, bcgPorts, bmsPorts, userDefinePort, pisDefaultPort, bcuDefaultPort, ermDefaultPort;
    // signals of HMI to CCU
    unsigned char setTemperature, currentTempTc1, currentTempTc2, currentTempMp1, currentTempMp2, flagChecker,                   
                  hmiBcuTestCode, hmiEmergencyCode, hmiTrainNumber, hmiLineNumber, hmiSetTagServiceKilometer, hmiSetTagRunningKilometer,
                  hmiTc1WindMode, hmiTc2WindMode, hmiMp1WindMode, hmiMp2WindMode;
    bool saveWheelDigflag_Tc1, saveWheelDigflag_Tc2, saveWheelDigflag_Mp1, saveWheelDigflag_Mp2, HVACModeTc1, HVACModeTc2,
    HVACModeMp1, HVACModeMp2, TimeSetMode, bcuSelfTest, hmiEmergencyCommand, hmiEmergencyStop,
    hmiCutBCG1, hmiCutBCG2, hmiResetBCG1, hmiResetBCG2, hmiSaveTrainNum, hmiSaveLineNum,
    hmiMuteFau, hmiResetFau, hmiResetSIV1, hmiResetSIV2, hmiCutSIV1, hmiCutSIV2, hmiClearERMAP1Time, hmiClearERMAP2Time,
    hmiClearTractionCost, hmiClearServiceDistance, hmiClearAuxCost, hmiTc1WindSpd, hmiMp1WindSpd, hmiMp2WindSpd, hmiTc2WindSpd, hmiNewWindSave,
    hmiResetSIV1Egy, hmiResetSIV2Egy, hmiResetDCU1Egy, hmiResetDCU2Egy, hmiResetDCU3Egy, hmiResetDCU4Egy,keepBrakeState;
    unsigned short int wheelDiameterTc1, wheelDiameterTc2, wheelDiameterMp1, wheelDiameterMp2;
    quint32 hmiSetServiceKilometer, hmiSetRunningKilometer;

    bool mp1Tcu1Isolate, mp1Tcu2Isolate, mp1Tcu3Isolate, mp1Tcu4Isolate, mp2Tcu1Isolate, mp2Tcu2Isolate, mp2Tcu3Isolate, mp2Tcu4Isolate;
    QDateTime hmisetDateTime;
public:
    //all data ports
    QMap<unsigned short int, struct port_data *> ports;
    QList<struct port *> allPorts;

public:
    void insertPort(const QList<struct port *> ports);
    bool getBool(unsigned short int port, unsigned short int byteOffset, unsigned short int bitOffset);
    unsigned char getUnsignedChar(unsigned short int port, unsigned short int byteOffset);
    signed char getSignedChar(unsigned short int port, unsigned short int byteOffset);
    unsigned short int getUnsignedInt(unsigned short int port, unsigned short int byteOffset);
    signed short int getSignedInt(unsigned short int port, unsigned short int byteOffset);
    quint32 getUnsignedInt32(unsigned short int port, unsigned short int byteOffset);
    void setUnsignedInt32(unsigned short int port, unsigned short int byteOffset, quint32 signal);
    void setBool(unsigned short int port, unsigned short int byteOffset, unsigned short int bitOffset, bool signal);
    void setUnsignedChar(unsigned short int port, unsigned short int byteOffset, unsigned char signal);
    void setSignedChar(unsigned short int port, unsigned short int byteOffset, signed char signal);
    void setUnsignedInt(unsigned short int port, unsigned short int byteOffset, unsigned short int signal);
    void setSignedInt(unsigned short int port, unsigned short int byteOffset, signed short int signal);
    unsigned short int getMvbCycleByPort(unsigned short int portNumber);
    void synchronizeCcuSignals();
    //set fireAlert
    void setFireButtonState(bool);
    bool getFireButtonState();
    int checkCcuSwitch(unsigned short int lifeSignal);
private:
    bool checkCcuOnline(unsigned short int lifeSignal);    
    void initializeSignals();

public:

    // riom do
    bool CTDO_Tc1BHBMaintain, CTDO_Tc2BHBMaintain, CTDO_Tc1BHBAction, CTDO_Tc2BHBAction, CTDO_Tc1CmpStart, CTDO_Tc2CmpStart;
    bool CTDO_M3ExPowerCmd, CTDO_M4ExPowerCmd;


    //0x110
    unsigned char GWCT_RIOMTc1GWLfSign_A1,GWCT_RIOMTc1GWVer_A1,DICT_RIOMTc1DIMVer_A1,DOCT_RIOMTc1DOMVer_A1,
    AICT_RIOMTc1AXMVer_A1,DICT_RIOMTc1LfSignDI1_A1,DICT_RIOMTc1LfSignDI2_A1,DICT_RIOMTc1LfSignDI3_A1,
    DICT_RIOMTc1LfSignDI4_A1,DOCT_RIOMTc1LfSignDO1_A1,AICT_RIOMTc1LfSignAX1_A1;
    bool DICT_RIOMTc1Flt1500DIM1_A1,
    DICT_RIOMTc1Flt1500DIM2_A1,DICT_RIOMTc1Flt1500DIM3_A1,DICT_RIOMTc1Flt1500DIM4_A1,DOCT_RIOMTc1Flt1500DOM1_A1,
    AICT_RIOMTc1Flt1500AXM1_A1,DICT_RIOMTc1Flt3000DIM1_A1,DICT_RIOMTc1Flt3000DIM2_A1,DICT_RIOMTc1Flt3000DIM3_A1,
    DICT_RIOMTc1Flt3000DIM4_A1,DOCT_RIOMTc1Flt3000DOM1_A1,AICT_RIOMTc1Flt3000AXM1_A1,GWCT_RIOMTc1LAT_A1,
    GWCT_RIOMTc1RLD_A1;

    //0x160
    bool riomRM, riomATP, riomATO, riomATB, riomIATP, riomATCCutOff, riomWashMode;
    unsigned char GWCT_RIOMTc2GWLfSign_A2,GWCT_RIOMTc2GWVer_A2,DICT_RIOMTc2DIMVer_A2,DOCT_RIOMTc2DOMVer_A2,
    AICT_RIOMTc2AXMVer_A2,DICT_RIOMTc2LfSignDI1_A2,DICT_RIOMTc2LfSignDI2_A2,DICT_RIOMTc2LfSignDI3_A2,
    DICT_RIOMTc2LfSignDI4_A2,DOCT_RIOMTc2LfSignDO1_A2,AICT_RIOMTc2LfSignAX1_A2;

    bool DICT_RIOMTc2Flt1500DIM1_A2,
    DICT_RIOMTc2Flt1500DIM2_A2,DICT_RIOMTc2Flt1500DIM3_A2,DICT_RIOMTc2Flt1500DIM4_A2,DOCT_RIOMTc2Flt1500DOM1_A2,
    AICT_RIOMTc2Flt1500AXM1_A2,DICT_RIOMTc2Flt3000DIM1_A2,DICT_RIOMTc2Flt3000DIM2_A2,DICT_RIOMTc2Flt3000DIM3_A2,
    DICT_RIOMTc2Flt3000DIM4_A2,DOCT_RIOMTc2Flt3000DOM1_A2,AICT_RIOMTc2Flt3000AXM1_A2,GWCT_RIOMTc2LAT_A2,
    GWCT_RIOMTc2RLD_A2;

    //0x111
    unsigned short int AICT_Tc1AI1ATCLevelA_A1,AICT_Tc1AI2ATCLevelB_A1,AICT_Tc1AI5DCLevelADup_A1,AICT_Tc1AI6DCLevelBDup_A1,
    AICT_Tc1AI7DriverControllerLevelA_A1,AICT_Tc1AI8DriverControllerLevelB_A1;
    bool DICT_Tc1DI1I20DrLCloseCmd_A1,DICT_Tc1DI1I19DrRCloseCmd_A1,
    DICT_Tc1DI1I18EmgyDoorStatus_A1,DICT_Tc1DI1I17CabDrRightStatus_A1,DICT_Tc1DI1I16CabDrLeftStatus_A1,DICT_Tc1DI1I15AllDoorClosed_A1,
    DICT_Tc1DI1I14DrLOpenCmd_A1,DICT_Tc1DI1I13DrROpenCmd_A1,DICT_Tc1DI1I12DrLeftEnable_A1,DICT_Tc1DI1I11DrRightEnable_A1,
    DICT_Tc1DI1I8Brake_A1,DICT_Tc1DI1I7Traction_A1,DICT_Tc1DI1I6FastBrk_A1,DICT_Tc1DI1I5Brake_A1,
    DICT_Tc1DI1I4Traction_A1,DICT_Tc1DI1I3DriverRoomAct_A1,DICT_Tc1DI1I2Backward_A1,DICT_Tc1DI1I1Forward_A1,
    DICT_Tc1DI2I23LuminairePower4_A1,DICT_Tc1DI2I22LuminairePower3_A1,DICT_Tc1DI2I21LuminairePower2_A1,DICT_Tc1DI2I20LuminairePower1_A1,
    DICT_Tc1DI2I19ParkingBrkCutOut_A1,DICT_Tc1DI2I18Bogie2Cut_A1,DICT_Tc1DI2I17Bogie1Cut_A1,DICT_Tc1DI2I16BCUCut_A1,
    DICT_Tc1DI2I15VVVFCut_A1,DICT_Tc1DI2I14VVVFReset_A1,DICT_Tc1DI2I13WindPressBtn_A1,DICT_Tc1DI2I12BCUMainFlt_A1,
    DICT_Tc1DI2I11EBCutBtn_A1,DICT_Tc1DI2I8Brake_A1,DICT_Tc1DI2I7Traction_A1,DICT_Tc1DI2I6FastBrk_A1,
    DICT_Tc1DI2I5Brake_A1,DICT_Tc1DI2I4Traction_A1,DICT_Tc1DI2I3DriverRoomAct_A1,DICT_Tc1DI2I2Backward_A1,
    DICT_Tc1DI2I1Forward_A1,DICT_Tc1DI3I19BatCtrlBreakerSta_A1,DICT_Tc1DI3I18BatBreakerSta_A1,DICT_Tc1DI3I16EmgySta_A1,
    DICT_Tc1DI3I15ForceRelBtn_A1,DICT_Tc1DI3I14ParkingBrk_A1,DICT_Tc1DI3I13HSCBConBtn_A1,DICT_Tc1DI3I12ADDByPass_A1,
    DICT_Tc1DI3I11EmgyBrkButton_A1,DICT_Tc1DI3I9WindWhistleBtn_A1,DICT_Tc1DI3I8EleWhistleBtn_A1,DICT_Tc1DI3I7StopBrkRelBtn_A1,
    DICT_Tc1DI3I6StopBrkInBtn_A1,DICT_Tc1DI3I5BrkNotRelByPass_A1,DICT_Tc1DI3I4ParkingBrkByPass_A1,DICT_Tc1DI3I3EmcByPass_A1,
    DICT_Tc1DI3I2DoorSafeByPass_A1,DICT_Tc1DI3I1NotZeroSpeed_A1;

    //0x161
    unsigned short int AICT_Tc2AI1ATCLevelA_A2,AICT_Tc2AI2ATCLevelB_A2,AICT_Tc2AI5DCLevelADup_A2,AICT_Tc2AI6DCLevelBDup_A2,
    AICT_Tc2AI7DriverControllerLevelA_A2,AICT_Tc2AI8DriverControllerLevelB_A2;
    bool DICT_Tc2DI1I20DrLCloseCmd_A2,DICT_Tc2DI1I19DrRCloseCmd_A2,
    DICT_Tc2DI1I18EmgyDoorStatus_A2,DICT_Tc2DI1I17CabDrRightStatus_A2,DICT_Tc2DI1I16CabDrLeftStatus_A2,DICT_Tc2DI1I15AllDoorClosed_A2,
    DICT_Tc2DI1I14DrLOpenCmd_A2,DICT_Tc2DI1I13DrROpenCmd_A2,DICT_Tc2DI1I12DrLeftEnable_A2,DICT_Tc2DI1I11DrRightEnable_A2,
    DICT_Tc2DI1I8Brake_A2,DICT_Tc2DI1I7Traction_A2,DICT_Tc2DI1I6FastBrk_A2,DICT_Tc2DI1I5Brake_A2,
    DICT_Tc2DI1I4Traction_A2,DICT_Tc2DI1I3DriverRoomAct_A2,DICT_Tc2DI1I2Backward_A2,DICT_Tc2DI1I1Forward_A2,
    DICT_Tc2DI2I23LuminairePower4_A2,DICT_Tc2DI2I22LuminairePower3_A2,DICT_Tc2DI2I21LuminairePower2_A2,DICT_Tc2DI2I20LuminairePower1_A2,
    DICT_Tc2DI2I19ParkingBrkCutOut_A2,DICT_Tc2DI2I18Bogie2Cut_A2,DICT_Tc2DI2I17Bogie1Cut_A2,DICT_Tc2DI2I16BCUCut_A2,
    DICT_Tc2DI2I15VVVFCut_A2,DICT_Tc2DI2I14VVVFReset_A2,DICT_Tc2DI2I13WindPressBtn_A2,DICT_Tc2DI2I12BCUMainFlt_A2,
    DICT_Tc2DI2I11EBCutBtn_A2,DICT_Tc2DI2I8Brake_A2,DICT_Tc2DI2I7Traction_A2,DICT_Tc2DI2I6FastBrk_A2,
    DICT_Tc2DI2I5Brake_A2,DICT_Tc2DI2I4Traction_A2,DICT_Tc2DI2I3DriverRoomAct_A2,DICT_Tc2DI2I2Backward_A2,
    DICT_Tc2DI2I1Forward_A2,DICT_Tc2DI3I19BatCtrlBreakerSta_A2,DICT_Tc2DI3I18BatBreakerSta_A2,DICT_Tc2DI3I16EmgySta_A2,
    DICT_Tc2DI3I15ForceRelBtn_A2,DICT_Tc2DI3I14ParkingBrk_A2,DICT_Tc2DI3I13HSCBConBtn_A2,DICT_Tc2DI3I12ADDByPass_A2,
    DICT_Tc2DI3I11EmgyBrkButton_A2,DICT_Tc2DI3I9WindWhistleBtn_A2,DICT_Tc2DI3I8EleWhistleBtn_A2,DICT_Tc2DI3I7StopBrkRelBtn_A2,
    DICT_Tc2DI3I6StopBrkInBtn_A2,DICT_Tc2DI3I5BrkNotRelByPass_A2,DICT_Tc2DI3I4ParkingBrkByPass_A2,DICT_Tc2DI3I3EmcByPass_A2,
    DICT_Tc2DI3I2DoorSafeByPass_A2,DICT_Tc2DI3I1NotZeroSpeed_A2;

    //0x112
    bool DICT_Tc1DI4I23DC24V, DICT_Tc1DI4I22SivRun_A1,DICT_Tc1DI4I21SivFlt_A1,DICT_Tc1DI4I20SendBackSta_A1,DICT_Tc1DI4I19EMCMode_A1,
    DICT_Tc1DI4I18HeaterNetCtrl_A1,DICT_Tc1DI4I17HeaterCh2_A1,DICT_Tc1DI4I16HeaterCh1_A1,DICT_Tc1DI4I15HighAcceMode_A1,
    DICT_Tc1DI4I14DeadmanPress_A1,DICT_Tc1DI4I13DeadmanLoosen_A1,DICT_Tc1DI4I12AirCmpPowerFlt_A1,DICT_Tc1DI4I11AirCmpPreStart_A1,
    DICT_Tc1DI4I10AirCmpHotOverload_A1,DICT_Tc1DI4I9AirCmpRun_A1,DICT_Tc1DI4I8ATOSwitch_A1,DICT_Tc1DI4I7ATBMode_A1,
    DICT_Tc1DI4I6ATPMode_A1,DICT_Tc1DI4I5IATPMode_A1,DICT_Tc1DI4I4RMMode_A1,DICT_Tc1DI4I3ATCCut_A1,
    Tc1DI4I2,DICT_Tc1DI4I1WorkShopPower_A1;

    //0x162

    bool DICT_TC2DI4I23DC24V,DICT_Tc2DI4I22SivRun_A2,DICT_Tc2DI4I21SivFlt_A2,DICT_Tc2DI4I20SendBackSta_A2,DICT_Tc2DI4I19EMCMode_A2,
    DICT_Tc2DI4I18HeaterNetCtrl_A2,DICT_Tc2DI4I17HeaterCh2_A2,DICT_Tc2DI4I16HeaterCh1_A2,DICT_Tc2DI4I15HighAcceMode_A2,
    DICT_Tc2DI4I14DeadmanPress_A2,DICT_Tc2DI4I13DeadmanLoosen_A2,DICT_Tc2DI4I12AirCmpPowerFlt_A2,DICT_Tc2DI4I11AirCmpPreStart_A2,
    DICT_Tc2DI4I10AirCmpHotOverload_A2,DICT_Tc2DI4I9AirCmpRun_A2,DICT_Tc2DI4I8ATOSwitch_A2,DICT_Tc2DI4I7ATBMode_A2,
    DICT_Tc2DI4I6ATPMode_A2,DICT_Tc2DI4I5ATPMode_A2,DICT_Tc2DI4I4RMMode_A2,DICT_Tc2DI4I3ATCCut_A2,
    Tc2DI4I2,DICT_Tc2DI4I1WorkShopPower_A2;


    //0x120
    unsigned char GWCT_RIOMM1GWLfSign_A1,GWCT_RIOMM1GWVer_A1,DICT_RIOMM1DIMVer_A1,DOCT_RIOMM1DOMVer_A1,
    DICT_RIOMM1LfSignDI1_A1,DOCT_RIOMM1LfSignDO1_A1;
    bool DICT_RIOMM1Flt1500DIM1_A1,DOCT_RIOMM1Flt1500DOM1_A1,
    DICT_RIOMM1Flt3000DIM1_A1,DOCT_RIOMM1Flt3000DOM1_A1,GWCT_RIOMM1LAT_A1,GWCT_RIOMM1RLD_A1;

    //0x150
    unsigned char GWCT_RIOMM2GWLfSign_A2,GWCT_RIOMM2GWVer_A2,DICT_RIOMM2DIMVer_A2,DOCT_RIOMM2DOMVer_A2,
    DICT_RIOMM2LfSignDI1_A2,DOCT_RIOMM2LfSignDO1_A2;
    bool DICT_RIOMM2Flt1500DIM1_A2,DOCT_RIOMM2Flt1500DOM1_A2,
    DICT_RIOMM2Flt3000DIM1_A2,DOCT_RIOMM2Flt3000DOM1_A2,GWCT_RIOMM2LAT_A2,GWCT_RIOMM2RLD_A2;

    //0x130
    unsigned char GWCT_RIOMMp1GWLfSign_A1,GWCT_RIOMMp1GWVer_A1,DICT_RIOMMp1DIMVer_A1,DOCT_RIOMMp1DOMVer_A1,
    DICT_RIOMMp1LfSignDI1_A1,DOCT_RIOMMp1LfSignDO1_A1;

    bool DICT_RIOMMp1Flt1500DIM1_A1,DOCT_RIOMMp1Flt1500DOM1_A1,
    DICT_RIOMMp1Flt3000DIM1_A1,DOCT_RIOMMp1Flt3000DOM1_A1,GWCT_RIOMMp1LAT_A1,GWCT_RIOMMp1RLD_A1;

    //0x140
    unsigned char GWCT_RIOMMp2GWLfSign_A2,GWCT_RIOMMp2GWVer_A2,DICT_RIOMMp2DIMVer_A2,DOCT_RIOMMp2DOMVer_A2,
    DICT_RIOMMp2LfSignDI1_A2,DOCT_RIOMMp2LfSignDO1_A2;

    bool DICT_RIOMMp2Flt1500DIM1_A2,DOCT_RIOMMp2Flt1500DOM1_A2,
    DICT_RIOMMp2Flt3000DIM1_A2,DOCT_RIOMMp2Flt3000DOM1_A2,GWCT_RIOMMp2LAT_A2,GWCT_RIOMMp2RLD_A2;

    //0x131
    bool DICT_Mp1DI1I21FirstRisePanPump_A1,DICT_Mp1DI1I20ADDDropPan_A1,DICT_Mp1DI1I19PanDropped_A1,DICT_Mp1DI1I18PanRised_A1,
    DICT_Mp1DI1I17ExPowerSta_A1,DICT_M1DI1I16ExpandPower_A1,DICT_M1DI1I15ExpandPowerFB_A1,DICT_M1DI1I14BHBStaFB_A1,
    DICT_M1DI1I13MainFuseOn_A1,DICT_M1DI1I11BCUMainFlt_A1,DICT_M1DI1I10BCUCut_A1,DICT_Mp1DI1I9HeaterCh2_A1,
    DICT_Mp1DI1I8HeaterCh1_A1,DICT_Mp1DI1I7LuminairePower4_A1,DICT_Mp1DI1I6LuminairePower3_A1,DICT_Mp1DI1I5LuminairePower2_A1,
    DICT_Mp1DI1I4LuminairePower1_A1,DICT_Mp1DI1I3ParkingBrkCutOut_A1,DICT_Mp1DI1I2Bogie2Cut_A1,DICT_Mp1DI1I1Bogie1Cut_A1;

    //0x141
    bool DICT_Mp2DI1I21FirstRisePanPump_A2,DICT_Mp2DI1I20ADDDropPan_A2,DICT_Mp2DI1I19PanDropped_A2,DICT_Mp2DI1I18PanRised_A2,
    DICT_Mp2DI1I17ExPowerSta_A2,DICT_M2DI1I16ExpandPower_A2,DICT_M2DI1I15ExpandPowerFB_A2,DICT_M2DI1I14BHBStaFB_A2,
    DICT_M2DI1I13MainFuseOn_A2,DICT_M2DI1I11BCUMainFlt_A2,DICT_M2DI1I10BCUCut_A2,DICT_Mp2DI1I9HeaterCh2_A2,
    DICT_Mp2DI1I8HeaterCh1_A2,DICT_Mp2DI1I7LuminairePower4_A2,DICT_Mp2DI1I6LuminairePower3_A2,DICT_Mp2DI1I5LuminairePower2_A2,
    DICT_Mp2DI1I4LuminairePower1_A2,DICT_Mp2DI1I3ParkingBrkCutOut_A2,DICT_Mp2DI1I2Bogie2Cut_A2,DICT_Mp2DI1I1Bogie1Cut_A2;


    //0x310
    unsigned short int HM1CT_LifeSignal_A1;
     unsigned char HM1CT_HMISWVerH_A1,HM1CT_HMISWVerL_A1,HM1CT_SetFlagChecker_A1;

    //0x311
    unsigned char HM1CT_Year_A1,HM1CT_Month_A1,HM1CT_Day_A1,HM1CT_Hour_A1,HM1CT_Minute_A1,HM1CT_Second_A1,
                  HM1CT_TrainNum_A1,HM1CT_LineNum_A1,HM1CT_StationIDFirst_A1,HM1CT_StationIDLast_A1;
    bool HM1CT_SAVETime_A1,HM1CT_SAVETrainNum_A1,HM1CT_SAVELineNum_A1,HM1CT_SAVEFirstStation_A1,HM1CT_SAVELastStation_A1;
    unsigned char HM1CT_HVACModeTc1_A1,HM1CT_HVACModeM1_A1,HM1CT_HVACModeMp1_A1,HM1CT_HVACModeMp2_A1,HM1CT_HVACModeM2_A1,HM1CT_HVACModeTc2_A1,
                  HM1CT_SetTempTc1_A1,HM1CT_SetTempM1_A1,HM1CT_SetTempMp1_A1,HM1CT_SetTempMp2_A1,HM1CT_SetTempM2_A1,HM1CT_SetTempTc2_A1;
    bool HM1CT_SAVEHVACModeTc1_A1,HM1CT_SAVEHVACModeM1_A1,HM1CT_SAVEHVACModeMp1_A1,HM1CT_SAVEHVACModeMp2_A1,HM1CT_SAVEHVACModeM2_A1,HM1CT_SAVEHVACModeTc2_A1,
         HM1CT_SAVEHVACTempTc1_A1,HM1CT_SAVEHVACTempM1_A1,HM1CT_SAVEHVACTempMp1_A1,HM1CT_SAVEHVACTempMp2_A1,HM1CT_SAVEHVACTempM2_A1,HM1CT_SAVEHVACTempTc2_A1;

    //0x312
    unsigned char HM1CT_WheelDiaTc1_A1,HM1CT_WheelDiaM1_A1,HM1CT_WheelDiaMp1_A1,HM1CT_WheelDiaMp2_A1,HM1CT_WheelDiaM2_A1,HM1CT_WheelDiaTc2_A1,HM1CT_BCUTestCode_A1;
    bool HM1CT_SAVEWheelDigTc1_A1,HM1CT_SAVEWheelDigM1_A1,HM1CT_SAVEWheelDigMp1_A1,HM1CT_SAVEWheelDigMp2_A1,HM1CT_SAVEWheelDigM2_A1,HM1CT_SAVEWheelDigTc2_A1;
    unsigned char HM1CT_StationIDCurrent_A1,HM1CT_StationIDNext_A1,HM1CT_EmgyBroadcastID_A1;
    bool HM1CT_BackMode_A1,HM1CT_WashMode_A1,HM1CT_CutBCG1_A1,HM1CT_CutBCG2_A1,HM1CT_ResetBCG1_A1,HM1CT_ResetBCG2_A1,HM1CT_ResetSIV1Fult_A1,HM1CT_ResetSIV2Fult_A1,
         HM1CT_CutSIV1Fult_A1,HM1CT_CutSIV2Fult_A1,HM1CT_MuteFAU_A1,HM1CT_ResetFAU_A1,HM1CT_ResetSIV1Energy_A1,HM1CT_ResetSIV2Energy_A1,
         HM1CT_ResetDCUEnergy1_A1,HM1CT_ResetDCUEnergy2_A1,HM1CT_ResetDCUEnergy3_A1,HM1CT_ResetDCUEnergy4_A1,HM1CT_AdjustStation_A1,HM1CT_EmgyBroadcastCommd_A1,HM1CT_EmgyBroadcastStop_A1;
    //0x313
    bool HM1CT_ClearERMAP1Time_A1,HM1CT_ClearERMAP2Time_A1,HM1CT_ClearTractionCost_A1,HM1CT_ClearServiceDistance_A1,HM1CT_ClearAuxCost_A1;
    unsigned char HM1CT_StationCancelByte1_A1,HM1CT_StationCancelByte2_A1,HM1CT_StationCancelByte3_A1,HM1CT_StationCancelByte4_A1,HM1CT_StationCancelSet_A1,
         HM1CT_TCMSStationCtrl_A1;
    unsigned long HM1CT_SetServiceKilometers_A1;
    unsigned char HM1CT_SetTagServiceKilometers_A1;
    unsigned long HM1CT_SetRunningKilometers_A1;
    unsigned char HM1CT_SetTagRunningKilometers_A1;


    //0x320
    unsigned short int HM2CT_LifeSignal_A2;
    unsigned char HM2CT_HMISWVerH_A2,HM2CT_HMISWVerL_A2,HM2CT_SetFlagChecker_A2;

    //0x321
    unsigned char HM2CT_Year_A2,HM2CT_Month_A2,HM2CT_Day_A2,HM2CT_Hour_A2,HM2CT_Minute_A2,HM2CT_Second_A2,
                  HM2CT_TrainNum_A2,HM2CT_LineNum_A2,HM2CT_StationIDFirst_A2,HM2CT_StationIDLast_A2;
    bool HM2CT_SAVETime_A2,HM2CT_SAVETrainNum_A2,HM2CT_SAVELineNum_A2,HM2CT_SAVEFirstStation_A2,HM2CT_SAVELastStation_A2;
    unsigned char HM2CT_HVACModeTc1_A2,HM2CT_HVACModeM1_A2,HM2CT_HVACModeMp1_A2,HM2CT_HVACModeMp2_A2,HM2CT_HVACModeM2_A2,HM2CT_HVACModeTc2_A2,
                  HM2CT_SetTempTc1_A2,HM2CT_SetTempM1_A2,HM2CT_SetTempMp1_A2,HM2CT_SetTempMp2_A2,HM2CT_SetTempM2_A2,HM2CT_SetTempTc2_A2;
    bool HM2CT_SAVEHVACModeTc1_A2,HM2CT_SAVEHVACModeM1_A2,HM2CT_SAVEHVACModeMp1_A2,HM2CT_SAVEHVACModeMp2_A2,HM2CT_SAVEHVACModeM2_A2,HM2CT_SAVEHVACModeTc2_A2,
         HM2CT_SAVEHVACTempTc1_A2,HM2CT_SAVEHVACTempM1_A2,HM2CT_SAVEHVACTempMp1_A2,HM2CT_SAVEHVACTempMp2_A2,HM2CT_SAVEHVACTempM2_A2,HM2CT_SAVEHVACTempTc2_A2;

    //0x322
    unsigned char HM2CT_WheelDiaTc1_A2,HM2CT_WheelDiaM1_A2,HM2CT_WheelDiaMp1_A2,HM2CT_WheelDiaMp2_A2,HM2CT_WheelDiaM2_A2,HM2CT_WheelDiaTc2_A2,HM2CT_BCUTestCode_A2;
    bool HM2CT_SAVEWheelDigTc1_A2,HM2CT_SAVEWheelDigM1_A2,HM2CT_SAVEWheelDigMp1_A2,HM2CT_SAVEWheelDigMp2_A2,HM2CT_SAVEWheelDigM2_A2,HM2CT_SAVEWheelDigTc2_A2;
    unsigned char HM2CT_StationIDCurrent_A2,HM2CT_StationIDNext_A2,HM2CT_EmgyBroadcastID_A2;
    bool HM2CT_BackMode_A2,HM2CT_WashMode_A2,HM2CT_CutBCG1_A2,HM2CT_CutBCG2_A2,HM2CT_ResetBCG1_A2,HM2CT_ResetBCG2_A2,HM2CT_ResetSIV1Fult_A2,HM2CT_ResetSIV2Fult_A2,
         HM2CT_CutSIV1Fult_A2,HM2CT_CutSIV2Fult_A2,HM2CT_MuteFAU_A2,HM2CT_ResetFAU_A2,HM2CT_ResetSIV1Energy_A2,HM2CT_ResetSIV2Energy_A2,
         HM2CT_ResetDCUEnergy1_A2,HM2CT_ResetDCUEnergy2_A2,HM2CT_ResetDCUEnergy3_A2,HM2CT_ResetDCUEnergy4_A2,HM2CT_AdjustStation_A2,HM2CT_EmgyBroadcastCommd_A2,HM2CT_EmgyBroadcastStop_A2;
    //0x323
    bool HM2CT_ClearERMAP1Time_A2,HM2CT_ClearERMAP2Time_A2,HM2CT_ClearTractionCost_A2,HM2CT_ClearServiceDistance_A2,HM2CT_ClearAuxCost_A2;
    unsigned char HM2CT_StationCancelByte1_A2,HM2CT_StationCancelByte2_A2,HM2CT_StationCancelByte3_A2,HM2CT_StationCancelByte4_A2,HM2CT_StationCancelSet_A2,
         HM2CT_TCMSStationCtrl_A2;
    unsigned long HM2CT_SetServiceKilometers_A2;
    unsigned char HM2CT_SetTagServiceKilometers_A2;
    unsigned long HM2CT_SetRunningKilometers_A2;
    unsigned char HM2CT_SetTagRunningKilometers_A2;

    // value in hmi
    bool hmiCcuOnlineState;

    //0x00F
    unsigned short int PUBPORT_TMSLifeSignal;
    unsigned char PUBPORT_SysTimeMonth,PUBPORT_SysTimeYear,PUBPORT_SysTimeHour,PUBPORT_SysTimeDay,PUBPORT_SysTimeSecond,PUBPORT_SysTimeMinute;
    unsigned short int PUBPORT_TrainNumber;
    bool PUBPORT_SettingTimeEnable;

    //0x210
    unsigned short int DT1CT_ERMLfSginal_A1;
    unsigned char DT1CT_ERMTimeYear_A1,DT1CT_ERMTimeMonth_A1,DT1CT_ERMTimeDay_A1,DT1CT_ERMTimeHour_A1,DT1CT_ERMTimeMinute_A1,
    DT1CT_ERMTimeSecond_A1,DT1CT_ERMVxWorksVer_A1,DT1CT_ERMMVBSWVer_A1,DT1CT_ERMSDBVer_A1;
    unsigned short int DT1CT_TCMSRunTime_A1;

    //0x211
    quint32 DT1CT_RunningKilometers_A1,DT1CT_VVVFEngyConsumption_A1,DT1CT_SIVEngyConsumption_A1,DT1CT_ReEngy_A1,
    DT1CT_ServiceDistance_A1,DT1CT_AP1RunningTime_A1,DT1CT_AP2RunningTime_A1,DT1CT_TCMSTotalTime_A1;

    //0x212
    unsigned char DT1CT_TotalDistanceYear_A1,DT1CT_TotalDistanceMonth_A1,DT1CT_TotalDistanceDay_A1,DT1CT_VVVFECYear_A1,
    DT1CT_VVVFECMonth_A1,DT1CT_VVVFECDay_A1,DT1CT_SIVECYear_A1,DT1CT_SIVECMonth_A1,
    DT1CT_SIVECDay_A1,DT1CT_ReEngyYear_A1,DT1CT_ReEngyMonth_A1,DT1CT_ReEngyDay_A1,
    DT1CT_ServiceDistanceYear_A1,DT1CT_ServiceDistanceMonth_A1,DT1CT_ServiceDistanceDay_A1,DT1CT_AP1ECYear_A1,
    DT1CT_AP1ECMonth_A1,DT1CT_AP1ECDay_A1,DT1CT_AP2ECYear_A1,DT1CT_AP2ECMonth_A1,
    DT1CT_AP2ECDay_A1,DT1CT_TCMSTotalTimeYear_A1,DT1CT_TCMSTotalTimeMonth_A1,DT1CT_TCMSTotalTimeDay_A1;

    //0x220
    unsigned short int DT6CT_ERMLfSginal_A2;
    unsigned char DT6CT_ERMTimeYear_A2,DT6CT_ERMTimeMonth_A2,DT6CT_ERMTimeDay_A2,DT6CT_ERMTimeHour_A2,DT6CT_ERMTimeMinute_A2,
    DT6CT_ERMTimeSecond_A2,DT6CT_ERMVxWorksVer_A2,DT6CT_ERMMVBSWVer_A2,DT6CT_ERMSDBVer_A2;
    unsigned short int DT6CT_TCMSRunTime_A2;

    //0x221
    quint32 DT6CT_RunningKilometers_A2,DT6CT_VVVFEngyConsumption_A2,DT6CT_SIVEngyConsumption_A2,DT6CT_ReEngy_A2,
    DT6CT_ServiceDistance_A2,DT6CT_AP1RunningTime_A2,DT6CT_AP2RunningTime_A2,DT6CT_TCMSTotalTime_A2;

    //0x222
    unsigned char DT6CT_TotalDistanceYear_A2,DT6CT_TotalDistanceMonth_A2,DT6CT_TotalDistanceDay_A2,DT6CT_VVVFECYear_A2,
    DT6CT_VVVFECMonth_A2,DT6CT_VVVFECDay_A2,DT6CT_SIVECYear_A2,DT6CT_SIVECMonth_A2,
    DT6CT_SIVECDay_A2,DT6CT_ReEngyYear_A2,DT6CT_ReEngyMonth_A2,DT6CT_ReEngyDay_A2,
    DT6CT_ServiceDistanceYear_A2,DT6CT_ServiceDistanceMonth_A2,DT6CT_ServiceDistanceDay_A2,DT6CT_AP1ECYear_A2,
    DT6CT_AP1ECMonth_A2,DT6CT_AP1ECDay_A2,DT6CT_AP2ECYear_A2,DT6CT_AP2ECMonth_A2,
    DT6CT_AP2ECDay_A2,DT6CT_TCMSTotalTimeYear_A2,DT6CT_TCMSTotalTimeMonth_A2,DT6CT_TCMSTotalTimeDay_A2;

    //0x218
    unsigned char CTDT1_RidingRateTc1_A1,CTDT1_RidingRateM1_A1,CTDT1_RidingRateMp1_A1,CTDT1_RidingRateMp2_A1,
    CTDT1_RidingRateM2_A1,CTDT1_RidingRateTc2_A1,CTDT1_RidingRate_A1;
    unsigned short int CTDT1_Accerate_A1,CTDT1_BrakeDistance_A1;
    unsigned char CTDT1_RunClass_A1,CTDT1_Level_A1;
    bool CTDT1_BrakeStartSpeed_A1,CTDT1_Regeneration_A1, CTDT1_TestDataValid, CTDT1_DrivingTL_A1,CTDT1_BkeTL_A1,
    CTDT1_EmBkeCircleTL_A1,CTDT1_TCDI1Off_A1,CTDT1_TCDO1Off_A1,CTDT1_KeyTowardError1_A1,
    CTDT1_ForwardReverseError1_A1,CTDT1_PBError1_A1,CTDT1_DirPBError1_A1,CTDT1_KeyActiveError_A1,
    CTDT1_KeyTowardError2_A1,CTDT1_ForwardReverseError2_A1,CTDT1_PBError2_A1,CTDT1_DirPBError2_A1,
    CTDT1_QuickBrkTL_A1,CTDT1_ForwardRedu1_A1,CTDT1_ForwardRedu2_A1,CTDT1_BackwardRedu1_A1,
    CTDT1_BackwardRedu2_A1,CTDT1_TrcRedu1_A1,CTDT1_TrcRedu2_A1,CTDT1_BrkRedu1_A1,
    CTDT1_BrkRedu2_A1,CTDT1_QBrkRedu1_A1,CTDT1_QBrkRedu2_A1,CTDT1_EMCRedu1_A1,CTDT1_EMCRedu2_A1;

    //0x228
    unsigned char CTDT6_RidingRateTc1_A2,CTDT6_RidingRateM1_A2,CTDT6_RidingRateMp1_A2,CTDT6_RidingRateMp2_A2,
    CTDT6_RidingRateM2_A2,CTDT6_RidingRateTc2_A2,CTDT6_RidingRate_A2;
    unsigned short int CTDT6_Accerate_A2,CTDT6_BrakeDistance_A2;
    unsigned char CTDT6_RunClass_A2,CTDT6_Level_A2;
    bool CTDT6_BrakeStartSpeed_A2,CTDT6_Regeneration_A2, CTDT6_TestDataValid, CTDT6_DrivingTL_A2,CTDT6_BkeTL_A2,
    CTDT6_EmBkeCircleTL_A2,CTDT6_TCDI1Off_A2,CTDT6_TCDO1Off_A2,CTDT6_KeyTowardError1_A2,
    CTDT6_ForwardReverseError1_A2,CTDT6_PBError1_A2,CTDT6_DirPBError1_A2,CTDT6_KeyActiveError_A2,
    CTDT6_KeyTowardError2_A2,CTDT6_ForwardReverseError2_A2,CTDT6_PBError2_A2,CTDT6_DirPBError2_A2,
    CTDT6_QuickBrkTL_A2,CTDT6_ForwardRedu1_A2,CTDT6_ForwardRedu2_A2,CTDT6_BackwardRedu1_A2,
    CTDT6_BackwardRedu2_A2,CTDT6_TrcRedu1_A2,CTDT6_TrcRedu2_A2,CTDT6_BrkRedu1_A2,
    CTDT6_BrkRedu2_A2,CTDT6_QBrkRedu1_A2,CTDT6_QBrkRedu2_A2,CTDT6_EMCRedu1_A2,CTDT6_EMCRedu2_A2;

    //0x320/0x321/0x322
    unsigned short int HM6CT_LifeSignal_A2;
    unsigned char HM6CT_HMISWVerH_A2,HM6CT_HMISWVerL_A2,HM6CT_SetFlagChecker_A2,HM6CT_Year_A2,HM6CT_Month_A2,HM6CT_Day_A2,
    HM6CT_Hour_A2,HM6CT_Minute_A2,HM6CT_Second_A2,HM6CT_TrainNum_A2,HM6CT_LineNum_A2,HM6CT_StationIDFirst_A2,
    HM6CT_StationIDLast_A2;
    bool HM6CT_SAVETime_A2,HM6CT_SAVETrainNum_A2,HM6CT_SAVELineNum_A2,HM6CT_SAVEFirstStation_A2,HM6CT_SAVELastStation_A2;
    unsigned char HM6CT_HVACModeTc1_A2,HM6CT_HVACModeM1_A2,HM6CT_HVACModeMp1_A2,HM6CT_HVACModeMp2_A2,HM6CT_HVACModeM2_A2,HM6CT_HVACModeTc2_A2,
    HM6CT_SetTempTc1_A2,HM6CT_SetTempM1_A2,HM6CT_SetTempMp1_A2,HM6CT_SetTempMp2_A2,HM6CT_SetTempM2_A2,HM6CT_SetTempTc2_A2;
    bool HM6CT_SAVEHVACModeTc1_A2,HM6CT_SAVEHVACModeM1_A2,HM6CT_SAVEHVACModeMp1_A2,HM6CT_SAVEHVACModeMp2_A2,HM6CT_SAVEHVACModeM2_A2,HM6CT_SAVEHVACModeTc2_A2,
    HM6CT_SAVEHVACTempTc1_A2,HM6CT_SAVEHVACTempM1_A2,HM6CT_SAVEHVACTempMp1_A2,HM6CT_SAVEHVACTempMp2_A2,HM6CT_SAVEHVACTempM2_A2,HM6CT_SAVEHVACTempTc2_A2,
    HM6CT_WheelDiaTc1_A2,HM6CT_WheelDiaM1_A2,HM6CT_WheelDiaMp1_A2,HM6CT_WheelDiaMp2_A2,HM6CT_WheelDiaM2_A2,HM6CT_WheelDiaTc2_A2,
    HM6CT_BCUTestCode_A2;

    bool HM6CT_SAVEWheelDigTc1_A2,HM6CT_SAVEWheelDigM1_A2,HM6CT_SAVEWheelDigMp1_A2,HM6CT_SAVEWheelDigMp2_A2,HM6CT_SAVEWheelDigM2_A2,HM6CT_SAVEWheelDigTc2_A2;
    unsigned char HM6CT_StationIDCurrent_A2,HM6CT_StationIDNext_A2,HM6CT_EmgyBroadcastID_A2;
    bool HM6CT_BackMode_A2,HM6CT_WashMode_A2,HM6CT_CutBCG1_A2,HM6CT_CutBCG2_A2,HM6CT_ResetBCG1_A2,HM6CT_ResetBCG2_A2,
    HM6CT_ResetSIV1Fult_A2,HM6CT_ResetSIV2Fult_A2,HM6CT_CutSIV1Fult_A2,HM6CT_CutSIV2Fult_A2,HM6CT_MuteFAU_A2,HM6CT_ResetFAU_A2,
    HM6CT_ResetSIV1Energy_A2,HM6CT_ResetSIV2Energy_A2,HM6CT_ResetDCUEnergy1_A2,HM6CT_ResetDCUEnergy2_A2,HM6CT_ResetDCUEnergy3_A2,HM6CT_ResetDCUEnergy4_A2,
    HM6CT_AdjustStation_A2,HM6CT_EmgyBroadcastCommd_A2,HM6CT_EmgyBroadcastStop_A2,HM6CT_BCUSelfTestReq_A2,HM6CT_AcTestStartReq_A2,HM6CT_AcTestStopReq_A2,
    HM6CT_ClearERMAP1Time_A2,HM6CT_ClearERMAP2Time_A2,HM6CT_ClearTractionCost_A2,HM6CT_ClearServiceDistance_A2,HM6CT_ClearAuxCost_A2;
    unsigned char HM6CT_StationCancelByte1_A2,HM6CT_StationCancelByte2_A2,HM6CT_StationCancelByte3_A2,HM6CT_StationCancelByte4_A2,HM6CT_StationCancelSet_A2,HM6CT_TCMSStationCtrl_A2;
    quint32 HM6CT_SetServiceKilometers_A2;
    unsigned char HM6CT_SetTagServiceKilometers_A2;
    quint32 HM6CT_SetRunningKilometers_A2;
    unsigned char HM6CT_SetTagRunningKilometers_A2;

    //0x308,0x309
    bool CTHM_CCU1On,CTHM_CCU2On,CTHM_ERM1On,CTHM_ERM2On,CTHM_HMI1On,CTHM_HMI2On,
    CTHM_TC1RIOMGWOn,CTHM_M1RIOMGWOn,CTHM_Mp1RIOMGWOn,CTHM_Mp2RIOMGWOn,CTHM_M2RIOMGWOn,CTHM_TC2RIOMGWOn,
    CTHM_TC1DI1On,CTHM_TC1DI2On,CTHM_TC1DI3On,CTHM_TC1DI4On,CTHM_TC1DO1On,CTHM_TC1AX1On,
    CTHM_MP1DI1On,CTHM_MP1DO1On,CTHM_M1DI1On,CTHM_M1DO1On,CTHM_M2DI1On,CTHM_M2DO1On,
    CTHM_MP2DI1On,CTHM_MP2DO1On,CTHM_TC2DI1On,CTHM_TC2DI2On,CTHM_TC2DI3On,CTHM_TC2DI4On,
    CTHM_TC2DO1On,CTHM_TC2AX1On,CTHM_Tc1BCUOn,CTHM_M1BCUOn,CTHM_Mp1BCUOn,CTHM_Mp2BCUOn,
    CTHM_M2BCUOn,CTHM_Tc2BCUOn,CTHM_M1DCUOn,CTHM_Mp1DCUOn,CTHM_Mp2DCUOn,CTHM_M2DCUOn,
    CTHM_SIV1On,CTHM_SIV2On,CTHM_EDCU1On,CTHM_EDCU2On,CTHM_EDCU3On,CTHM_EDCU4On,
    CTHM_EDCU5On,CTHM_EDCU6On,CTHM_EDCU7On,CTHM_EDCU8On,CTHM_EDCU9On,CTHM_EDCU10On,
    CTHM_EDCU11On,CTHM_EDCU12On,CTHM_BCG1On,CTHM_BCG2On,CTHM_PIS1On,CTHM_PIS2On,
    CTHM_Tc1HVACOn,CTHM_M1HVACOn,CTHM_Mp1HVACOn,CTHM_Mp2HVACOn,CTHM_M2HVACOn,CTHM_Tc2HVACOn,
    CTHM_ATC1On,CTHM_ATC2On,CTHM_FAU1On,CTHM_FAU2On,CTHM_BMS1On,CTHM_BMS2On,CTHM_PDS1On,CTHM_PDS2On;
    unsigned char CTHM_StationCancelByte1,CTHM_StationCancelByte2,CTHM_StationCancelByte3,CTHM_StationCancelByte4;

    bool CTHM_ATC1Active,CTHM_ATC2Active,CTHM_PIS1Active,CTHM_PIS2Active,CTHM_CCU1Active,CTHM_CCU2Active,
    CTHM_TC1Active,CTHM_TC2Active,CTHM_Traction,CTHM_Brake,CTHM_FastBrake,CTHM_EmgyBrake,
    CTHM_Backward,CTHM_Forward,CTHM_Testing,CTHM_TestFinish,CTHM_CCU1VerOK,CTHM_CCU2VerOK,
    CTHM_ClaarVVVFECEnable,CTHM_ClearSIVECEnable;

    unsigned short int CTHM_TestDistance,CTHM_TestTime;
    unsigned char CTHM_Grade,CTHM_CurrentStation;

    unsigned short int CTHM_TrainSpeed,CTHM_CatenaryVoltage,CTHM_CatenaryCurrent,CTHM_WheelDigTc1FedBk,CTHM_WheelDigM1FedBk,
    CTHM_WheelDigMp1FedBk,CTHM_WheelDigMp2FedBk,CTHM_WheelDigM2FedBk,CTHM_WheelDigTc2FedBk;
    //unsigned char CTHM_CCU1SWVer,CTHM_CCU1MVBVer,CTHM_CCU1SDBVer,CTHM_CCU1VxWorksVer;

    bool CTHM_PBReleaseTc1,CTHM_PBReleaseM1,CTHM_PBReleaseMp1,CTHM_PBReleaseMp2,CTHM_PBReleaseM2,CTHM_PBReleaseTc2,CTHM_BCUSTOverTime;

    unsigned char CTHM_LineNum,CTHM_TrainNum,CTHM_FirstStationID,CTHM_LastStationID;
    //CTHM_CCU2SWVer,CTHM_CCU2MVBVer,CTHM_CCU2SDBVer,CTHM_CCU2VxWorksVer;
    bool CTHM_Tc1HVACColdHibt,CTHM_M1HVACColdHibt,CTHM_Mp1HVACColdHibt,CTHM_Mp2HVACColdHibt,CTHM_M2HVACColdHibt,CTHM_Tc2HVACColdHibt,
    CTHM_AutoWarmHibt,CTHM_ColdHibt,CTHM_SAVEWheelDigTc1FedBk,CTHM_SAVEWheelDigM1FedBk,CTHM_SAVEWheelDigMp1FedBk,CTHM_SAVEWheelDigMp2FedBk,
    CTHM_SAVEWheelDigM2FedBk,CTHM_SAVEWheelDigTc2FedBk,CTHM_SAVEHVACModeTc1FedBk,CTHM_SAVEHVACModeM1FedBk,CTHM_SAVEHVACModeMp1FedBk,CTHM_SAVEHVACModeMp2FedBk,
    CTHM_SAVEHVACModeM2FedBk,CTHM_SAVEHVACModeTc2FedBk,CTHM_SAVEHVACTempTc1FedBk,CTHM_SAVEHVACTempM1FedBk,CTHM_SAVEHVACTempMp1FedBk,CTHM_SAVEHVACTempMp2FedBk,
    CTHM_SAVEHVACTempM2FedBk,CTHM_SAVEHVACTempTc2FedBk,CTHM_SAVETimeFedBk,CTHM_SAVETrainNumFedBk,CTHM_SAVELineNumFedBk,CTHM_SAVEFirstStationFedBk,
    CTHM_SAVELastStationFedBk,CTHM_SAVEStationCancelFedBk;

    //0x410,0x411,0x412,0x413
    signed short int BR1CT_LfSgn_A1, BR3CT_LfSgn_Mp1, BR4CT_LfSgn_Mp2, BR6CT_LfSgn_A2;
//    signed short int BR1CT_LfSgn_A1,BR1CT_MssTCjBg1_A1,BR1CT_MssTCjBg2_A1,BR1CT_MssMPjBg1_A1,BR1CT_MssMPjBg2_A1,BR1CT_SpdTrain_A1;
//    bool BR1CT_MssVldTCjBg1_A1,BR1CT_MssVldTCjBg2,BR1CT_MssVldMPjBg1,BR1CT_MssVldMPjBg2,BR1CT_SpdTrainVld,BR1CT_SttsDgnssVldTCjBg1,
//    BR1CT_SttsDgnssVldTCjBg2,BR1CT_SttsDgnssVldMPjBg1,BR1CT_SttsDgnssVldMPjBg2,BR1CT_EPOKTCjBg1,BR1CT_EPOKTCjBg2,BR1CT_EPOKMPjBg1,
//    BR1CT_EPOKMPjBg2,BR1CT_EDCtOffMPj,BR1CT_HWBrSt,BR1CT_HWFstBrSt,BR1CT_HWTrctnSt,BR1CT_ZrSpd,
//    BR1CT_EBActv,BR1CT_MstrBCU,BR1CT_SeBrAc50,BR1CT_TwngMd,BR1CT_EmOprnMd,BR1CT_TwngIstrct3,
//    BR1CT_STRdy,BR1CT_STActv;

//    signed short int BR1CT_ASP1TCjBg1_A1,BR1CT_EPPssblTCjBg1_A1,BR1CT_SpdTCjAxl1_A1,BR1CT_SpdTCjAxl2_A1,BR1CT_BCP1TCjBg1_A1,BR1CT_BCP2TCjBg1_A1;
//    bool BR1CT_ASP1VldTCjBg1,BR1CT_SpdVldTCjAxl1,BR1CT_SpdVldTCjAxl2,BR1CT_EPRlsdTCjBg1,BR1CT_EPAppldTCjBg1,BR1CT_WSPActvTCjAxl1,
//    BR1CT_STOKTCjBg1,BR1CT_EBActvTCjBg1,BR1CT_EBAvlblTCjBg1,BR1CT_HBAppldTCjBg1,BR1CT_BC1PVldTCjBg1,BR1CT_EPPssblVldTCjBg1,
//    BR1CT_STFAILTCjBg1,BR1CT_ASP2VldTCjBg1,BR1CT_ASP2VldTCjBg2,BR1CT_BCP2VldTCjBg1;

//    signed short int BR1CT_ASP2TCjBg1_A1,BR1CT_ASP1TCjBg2_A1,BR1CT_EPPssblTCjBg2_A1,BR1CT_SpdTCjAxl3_A1,BR1CT_SpdTCjAxl4_A1,BR1CT_BCP1TCjBg2_A1,
//    BR1CT_BCP2TCjBg2_A1;
//    bool BR1CT_ASP1VldTCjBg2,BR1CT_SpdVldTCjAxl3,BR1CT_SpdVldTCjAxl4,BR1CT_EPRlsdTCjBg2,BR1CT_EPAppldTCjBg2,BR1CT_WSPActvTCjAxle3,
//    BR1CT_STOKTCjBg2,BR1CT_EBActvTCjBg2,BR1CT_EBAvlblTCjBg2,BR1CT_HBAppldTCjBg2,BR1CT_BC1PVldTCjBg2,BR1CT_EPPssblVldTCj2Bg2,
//    BR1CT_STFAILTCjBg2,BR1CT_WSPActvTCjAxle2,BR1CT_WSPActvTCjAxle4,BR1CT_BC2PVldTCjBg2;

//    signed short int BR1CT_ASP2TCjBg2_A1,BR1CT_ASP1MPjBg1_A1,BR1CT_EPPssblMPjBg1_A1,BR1CT_SpdMPjAxl1_A1,BR1CT_SpdMPjAxl2_A1,BR1CT_BCP1MPjBg1_A1,
//    BR1CT_BCP2MPjBg1_A1;
//    bool BR1CT_ASP1VldMPjBg1,BR1CT_SpdVldMPjAxl1,BR1CT_SpdVldMPjAxl2,BR1CT_EPRlsdMPjBg1,BR1CT_EPAppldMPjBg1,BR1CT_WSPActvMPjAxle1,
//    BR1CT_STOKMPjBg1,BR1CT_EBActvMPjBg1,BR1CT_EBAvlblMPjBg1,BR1CT_HBAppldMPjBg1,BR1CT_BC1PVldMPjBg1,BR1CT_EPPssblVldMPjBg1,
//    BR1CT_STFAILMPjBg1,BR1CT_ASP2VldMPjBg1,BR1CT_ASP2VldMPjBg2,BR1CT_BC2PVldMPjBg1;

//    signed short int BR1CT_ASP2MPjBg1_A1,BR1CT_ASP1MPjBg2_A1,BR1CT_EPPssblMPjBg2_A1,BR1CT_SpdMPjAxl3_A1,BR1CT_SpdMPjAxl4_A1,BR1CT_BCP1MPjBg2_A1,
//    BR1CT_BCP2MPjBg2_A1;
//    bool BR1CT_ASP1VldMPjBg2,BR1CT_SpdVldMPjAxl3,BR1CT_SpdVldMPjAxl4,BR1CT_EPRlsdMPjBg2,BR1CT_EPAppldMPjBg2,BR1CT_WSPActvMPjAxle3,
//    BR1CT_STOKMPjBg2,BR1CT_EBActvMPjBg2,BR1CT_EBAvlblMPjBg2,BR1CT_HBAppldMPjBg2,BR1CT_BC1PVldMPjBg2,BR1CT_EPPssblVldMPjBg2,
//    BR1CT_STFAILMPjBg2,BR1CT_WSPActvMPjAxle2,BR1CT_WSPActvMPjAxle4,BR1CT_BC2PVldMPjBg2;

//    signed short int BR1CT_ASP2MPjBg2_A1;
//    bool BR1CT_LwBSRTCjBg1,BR1CT_LwBSRTCjBg2,BR1CT_LwBSRMPjBg1,BR1CT_LwBSRMPjBg2,BR1CT_FtlErrTCjBg1,BR1CT_FtlErrTCjBg2,
//    BR1CT_FtlErrMPjBg1,BR1CT_FtlErrMPjBg2,BR1CT_MntnncWrnngTCjBg1,BR1CT_MntnncWrnngTCjBg2,BR1CT_MntnncWrnngMPjBg1,BR1CT_MntnncWrnngMPjBg2,
//    BR1CT_ASPOtOfRngTCjBg1,BR1CT_ASPOtOfRngTCjBg2,BR1CT_ASPOtOfRngMPjBg1,BR1CT_ASPOtOfRngMPjBg2,BR1CT_CANBsFlt,BR1CT_BrRqstIncnsstnt,
//    BR1CT_STExcd26H,BR1CT_EdBrFdHghSpd,BR1CT_EdBrFdLwSpd,BR1CT_ASPRdy,BR1CT_MjrEvnt,BR1CT_MdmEvnt,
//    BR1CT_MnrEvnt,BR1CT_STExcd00H,BR1CT_BrNtRlsdTCjBg1,BR1CT_BrNtRlsdTCjBg2,BR1CT_BrNtRlsdMPjBg1,BR1CT_BrNtRlsdMPjBg2,
//    BR1CT_SpdSnsrFltTCjAxle1,BR1CT_SpdSnsrFltTCjAxle2,BR1CT_SpdSnsrFltTCjAxle3,BR1CT_SpdSnsrFltTCjAxle4,BR1CT_SpdSnsrFltMPjAxle1,BR1CT_SpdSnsrFltMPjAxle2,
//    BR1CT_SpdSnsrFltMPjAxle3,BR1CT_SpdSnsrFltMPjAxle4,BR1CT_2ndErrTCjBg1,BR1CT_2ndErrTCjBg2,BR1CT_2ndErrMPjBg1,BR1CT_2ndErrMPjBg2,
//    BR1CT_FBrIncnsstnt,BR1CT_MRPVld,BR1CT_CB01SWVrsnVld,BR1CT_MVBSWVrsnVld,BR1CT_EB01SWVrsnVld;

//    signed char BR1CT_CB01SWVrsn_A1,BR1CT_MVBSWVrsn_A1,BR1CT_EB01SWVrsn_A1;
//    signed short int BR1CT_MRP_A1;


//    //0x430,0x431,0x432,0x433
//    signed short int BR3CT_LfSgn_Mp1,BR3CT_MssTCjBg1_Mp1,BR3CT_MssTCjBg2_Mp1,BR3CT_MssMPjBg1_Mp1,BR3CT_MssMPjBg2_Mp1,BR3CT_SpdTrain_Mp1;
//    bool BR3CT_MssVldTCjBg1_Mp1,BR3CT_MssVldTCjBg2_Mp1,BR3CT_MssVldMPjBg1_Mp1,BR3CT_MssVldMPjBg2_Mp1,BR3CT_SpdTrainVld_Mp1,BR3CT_SttsDgnssVldTCjBg1_Mp1,
//    BR3CT_SttsDgnssVldTCjBg2_Mp1,BR3CT_SttsDgnssVldMPjBg1_Mp1,BR3CT_SttsDgnssVldMPjBg2_Mp1,BR3CT_EPOKTCjBg1_Mp1,BR3CT_EPOKTCjBg2_Mp1,BR3CT_EPOKMPjBg1_Mp1,
//    BR3CT_EPOKMPjBg2_Mp1,BR3CT_EDCtOffMPj_Mp1,BR3CT_HWBrSt_Mp1,BR3CT_HWFstBrSt_Mp1,BR3CT_HWTrctnSt_Mp1,BR3CT_ZrSpd_Mp1,
//    BR3CT_EBActv_Mp1,BR3CT_MstrBCU_Mp1,BR3CT_SeBrAc50_Mp1,BR3CT_TwngMd_Mp1,BR3CT_EmOprnMd_Mp1,BR3CT_TwngIstrct3_Mp1,
//    BR3CT_STRdy_Mp1,BR3CT_STActv_Mp1;

//    signed short int BR3CT_ASP1TCjBg1_Mp1,BR3CT_EPPssblTCjBg1_Mp1,BR3CT_SpdTCjAxl1_Mp1,BR3CT_SpdTCjAxl2_Mp1,BR3CT_BCP1TCjBg1_Mp1,BR3CT_BCP2TCjBg1_Mp1;
//    bool BR3CT_ASP1VldTCjBg1_Mp1,BR3CT_SpdVldTCjAxl1_Mp1,BR3CT_SpdVldTCjAxl2_Mp1,BR3CT_EPRlsdTCjBg1_Mp1,BR3CT_EPAppldTCjBg1_Mp1,BR3CT_WSPActvTCjAxl1_Mp1,
//    BR3CT_STOKTCjBg1_Mp1,BR3CT_EBActvTCjBg1_Mp1,BR3CT_EBAvlblTCjBg1_Mp1,BR3CT_HBAppldTCjBg1_Mp1,BR3CT_BC1PVldTCjBg1_Mp1,BR3CT_EPPssblVldTCjBg1_Mp1,
//    BR3CT_STFAILTCjBg1_Mp1,BR3CT_ASP2VldTCjBg1_Mp1,BR3CT_ASP2VldTCjBg2_Mp1,BR3CT_BCP2VldTCjBg1_Mp1;

//    signed short int BR3CT_ASP2TCjBg1_Mp1,BR3CT_ASP1TCjBg2_Mp1,BR3CT_EPPssblTCjBg2_Mp1,BR3CT_SpdTCjAxl3_Mp1,BR3CT_SpdTCjAxl4_Mp1,BR3CT_BCP1TCjBg2_Mp1,
//    BR3CT_BCP2TCjBg2_Mp1;
//    bool BR3CT_ASP1VldTCjBg2_Mp1,BR3CT_SpdVldTCjAxl3_Mp1,BR3CT_SpdVldTCjAxl4_Mp1,BR3CT_EPRlsdTCjBg2_Mp1,BR3CT_EPAppldTCjBg2_Mp1,BR3CT_WSPActvTCjAxle3_Mp1,
//    BR3CT_STOKTCjBg2_Mp1,BR3CT_EBActvTCjBg2_Mp1,BR3CT_EBAvlblTCjBg2_Mp1,BR3CT_HBAppldTCjBg2_Mp1,BR3CT_BC1PVldTCjBg2_Mp1,BR3CT_EPPssblVldTCj2Bg2_Mp1,
//    BR3CT_STFAILTCjBg2_Mp1,BR3CT_WSPActvTCjAxle2_Mp1,BR3CT_WSPActvTCjAxle4_Mp1,BR3CT_BC2PVldTCjBg2_Mp1;

//    signed short int BR3CT_ASP2TCjBg2_Mp1,BR3CT_ASP1MPjBg1_Mp1,BR3CT_EPPssblMPjBg1_Mp1,BR3CT_SpdMPjAxl1_Mp1,BR3CT_SpdMPjAxl2_Mp1,BR3CT_BCP1MPjBg1_Mp1,
//    BR3CT_BCP2MPjBg1_Mp1;
//    bool BR3CT_ASP1VldMPjBg1_Mp1,BR3CT_SpdVldMPjAxl1_Mp1,BR3CT_SpdVldMPjAxl2_Mp1,BR3CT_EPRlsdMPjBg1_Mp1,BR3CT_EPAppldMPjBg1_Mp1,BR3CT_WSPActvMPjAxle1_Mp1,
//    BR3CT_STOKMPjBg1_Mp1,BR3CT_EBActvMPjBg1_Mp1,BR3CT_EBAvlblMPjBg1_Mp1,BR3CT_HBAppldMPjBg1_Mp1,BR3CT_BC1PVldMPjBg1_Mp1,BR3CT_EPPssblVldMPjBg1_Mp1,
//    BR3CT_STFAILMPjBg1_Mp1,BR3CT_ASP2VldMPjBg1_Mp1,BR3CT_ASP2VldMPjBg2_Mp1,BR3CT_BC2PVldMPjBg1_Mp1;

//    signed short int BR3CT_ASP2MPjBg1_Mp1,BR3CT_ASP1MPjBg2_Mp1,BR3CT_EPPssblMPjBg2_Mp1,BR3CT_SpdMPjAxl3_Mp1,BR3CT_SpdMPjAxl4_Mp1,BR3CT_BCP1MPjBg2_Mp1,
//    BR3CT_BCP2MPjBg2_Mp1;
//    bool BR3CT_ASP1VldMPjBg2_Mp1,BR3CT_SpdVldMPjAxl3_Mp1,BR3CT_SpdVldMPjAxl4_Mp1,BR3CT_EPRlsdMPjBg2_Mp1,BR3CT_EPAppldMPjBg2_Mp1,BR3CT_WSPActvMPjAxle3_Mp1,
//    BR3CT_STOKMPjBg2_Mp1,BR3CT_EBActvMPjBg2_Mp1,BR3CT_EBAvlblMPjBg2_Mp1,BR3CT_HBAppldMPjBg2_Mp1,BR3CT_BC1PVldMPjBg2_Mp1,BR3CT_EPPssblVldMPjBg2_Mp1,
//    BR3CT_STFAILMPjBg2_Mp1,BR3CT_WSPActvMPjAxle2_Mp1,BR3CT_WSPActvMPjAxle4_Mp1,BR3CT_BC2PVldMPjBg2_Mp1;
//    signed short int BR3CT_ASP2MPjBg2_Mp1;
//    bool BR3CT_LwBSRTCjBg1_Mp1,BR3CT_LwBSRTCjBg2_Mp1,BR3CT_LwBSRMPjBg1_Mp1,BR3CT_LwBSRMPjBg2_Mp1,BR3CT_FtlErrTCjBg1_Mp1,BR3CT_FtlErrTCjBg2_Mp1,
//    BR3CT_FtlErrMPjBg1_Mp1,BR3CT_FtlErrMPjBg2_Mp1,BR3CT_MntnncWrnngTCjBg1_Mp1,BR3CT_MntnncWrnngTCjBg2_Mp1,BR3CT_MntnncWrnngMPjBg1_Mp1,BR3CT_MntnncWrnngMPjBg2_Mp1,
//    BR3CT_ASPOtOfRngTCjBg1_Mp1,BR3CT_ASPOtOfRngTCjBg2_Mp1,BR3CT_ASPOtOfRngMPjBg1_Mp1,BR3CT_ASPOtOfRngMPjBg2_Mp1,BR3CT_CANBsFlt_Mp1,BR3CT_BrRqstIncnsstnt_Mp1,
//    BR3CT_STExcd26H_Mp1,BR3CT_EdBrFdHghSpd_Mp1,BR3CT_EdBrFdLwSpd_Mp1,BR3CT_ASPRdy_Mp1,BR3CT_MjrEvnt_Mp1,BR3CT_MdmEvnt_Mp1,
//    BR3CT_MnrEvnt_Mp1,BR3CT_STExcd00H_Mp1,BR3CT_BrNtRlsdTCjBg1_Mp1,BR3CT_BrNtRlsdTCjBg2_Mp1,BR3CT_BrNtRlsdMPjBg1_Mp1,BR3CT_BrNtRlsdMPjBg2_Mp1,
//    BR3CT_SpdSnsrFltTCjAxle1_Mp1,BR3CT_SpdSnsrFltTCjAxle2_Mp1,BR3CT_SpdSnsrFltTCjAxle3_Mp1,BR3CT_SpdSnsrFltTCjAxle4_Mp1,BR3CT_SpdSnsrFltMPjAxle1_Mp1,BR3CT_SpdSnsrFltMPjAxle2_Mp1,
//    BR3CT_SpdSnsrFltMPjAxle3_Mp1,BR3CT_SpdSnsrFltMPjAxle4_Mp1,BR3CT_2ndErrTCjBg1_Mp1,BR3CT_2ndErrTCjBg2_Mp1,BR3CT_2ndErrMPjBg1_Mp1,BR3CT_2ndErrMPjBg2_Mp1,
//    BR3CT_FBrIncnsstnt_Mp1,BR3CT_MRPVld_Mp1,BR3CT_CB01SWVrsnVld_Mp1,BR3CT_MVBSWVrsnVld_Mp1,BR3CT_EB01SWVrsnVld_Mp1;

//    signed char BR3CT_CB01SWVrsn_Mp1,BR3CT_MVBSWVrsn_Mp1,BR3CT_EB01SWVrsn_Mp1;
//    signed short int BR3CT_MRP_Mp1;
    //0x440,0x441,0x442,0x443

    //bcu master
    bool BR1CT_MstrBCU, BR3CT_MstrBCU_Mp1, BR4CT_MstrBCU_Mp2, BR6CT_MstrBCU_A2;
//    signed short int BR4CT_LfSgn_Mp2,BR4CT_MssTCjBg1_Mp2,BR4CT_MssTCjBg2_Mp2,BR4CT_MssMPjBg1_Mp2,BR4CT_MssMPjBg2_Mp2,BR4CT_SpdTrain_Mp2;
//    bool BR4CT_MssVldTCjBg1_Mp2,BR4CT_MssVldTCjBg2_Mp2,BR4CT_MssVldMPjBg1_Mp2,BR4CT_MssVldMPjBg2_Mp2,BR4CT_SpdTrainVld_Mp2,BR4CT_SttsDgnssVldTCjBg1_Mp2,
//    BR4CT_SttsDgnssVldTCjBg2_Mp2,BR4CT_SttsDgnssVldMPjBg1_Mp2,BR4CT_SttsDgnssVldMPjBg2_Mp2,BR4CT_EPOKTCjBg1_Mp2,BR4CT_EPOKTCjBg2_Mp2,BR4CT_EPOKMPjBg1_Mp2,
//    BR4CT_EPOKMPjBg2_Mp2,BR4CT_EDCtOffMPj_Mp2,BR4CT_HWBrSt_Mp2,BR4CT_HWFstBrSt_Mp2,BR4CT_HWTrctnSt_Mp2,BR4CT_ZrSpd_Mp2,
//    BR4CT_EBActv_Mp2,BR4CT_MstrBCU_Mp2,BR4CT_SeBrAc50_Mp2,BR4CT_TwngMd_Mp2,BR4CT_EmOprnMd_Mp2,BR4CT_TwngIstrct3_Mp2,
//    BR4CT_STRdy_Mp2,BR4CT_STActv_Mp2;

//    signed short int BR4CT_ASPTCjBg1_Mp2,BR4CT_EPPssblTCjBg1_Mp2,BR4CT_SpdTCjAxl1_Mp2,BR4CT_SpdTCjAxl2_Mp2,BR4CT_BCP1TCjBg1_Mp2,BR4CT_BCP2TCjBg1_Mp2;
//    bool BR4CT_ASP1VldTCjBg1_Mp2,BR4CT_SpdVldTCjAxl1_Mp2,BR4CT_SpdVldTCjAxl2_Mp2,BR4CT_EPRlsdTCjBg1_Mp2,BR4CT_EPAppldTCjBg1_Mp2,BR4CT_WSPActvTCjAxl1_Mp2,
//    BR4CT_STOKTCjBg1_Mp2,BR4CT_EBActvTCjBg1_Mp2,BR4CT_EBAvlblTCjBg1_Mp2,BR4CT_HBAppldTCjBg1_Mp2,BR4CT_BC1PVldTCjBg1_Mp2,BR4CT_EPPssblVldTCjBg1_Mp2,
//    BR4CT_STFAILTCjBg1_Mp2,BR4CT_ASP2VldTCjBg1_Mp2,BR4CT_ASP2VldTCjBg2_Mp2,BR4CT_BCP2VldTCjBg1_Mp2;

//    signed short int BR4CT_ASP2TCjBg1_Mp2,BR4CT_ASP1TCjBg2_Mp2,BR4CT_EPPssblTCjBg2_Mp2,BR4CT_SpdTCjAxl3_Mp2,BR4CT_SpdTCjAxl4_Mp2,BR4CT_BCP1TCjBg2_Mp2,
//    BR4CT_BCP2TCjBg2_Mp2;
//    bool BR4CT_ASP1VldTCjBg2_Mp2,BR4CT_SpdVldTCjAxl3_Mp2,BR4CT_SpdVldTCjAxl4_Mp2,BR4CT_EPRlsdTCjBg2_Mp2,BR4CT_EPAppldTCjBg2_Mp2,BR4CT_WSPActvTCjAxle3_Mp2,
//    BR4CT_STOKTCjBg2_Mp2,BR4CT_EBActvTCjBg2_Mp2,BR4CT_EBAvlblTCjBg2_Mp2,BR4CT_HBAppldTCjBg2_Mp2,BR4CT_BC1PVldTCjBg2_Mp2,BR4CT_EPPssblVldTCj2Bg2_Mp2,
//    BR4CT_STFAILTCjBg2_Mp2,BR4CT_WSPActvTCjAxle2_Mp2,BR4CT_WSPActvTCjAxle4_Mp2,BR4CT_BC2PVldTCjBg2_Mp2;

//    signed short int BR4CT_ASP2TCjBg2_Mp2,BR4CT_ASP1MPjBg1_Mp2,BR4CT_EPPssblMPjBg1_Mp2,BR4CT_SpdMPjAxl1_Mp2,BR4CT_SpdMPjAxl2_Mp2,BR4CT_BCP1MPjBg1_Mp2,
//    BR4CT_BCP2MPjBg1_Mp2;
//    bool BR4CT_ASP1VldMPjBg1_Mp2,BR4CT_SpdVldMPjAxl1_Mp2,BR4CT_SpdVldMPjAxl2_Mp2,BR4CT_EPRlsdMPjBg1_Mp2,BR4CT_EPAppldMPjBg1_Mp2,BR4CT_WSPActvMPjAxle1_Mp2,
//    BR4CT_STOKMPjBg1_Mp2,BR4CT_EBActvMPjBg1_Mp2,BR4CT_EBAvlblMPjBg1_Mp2,BR4CT_HBAppldMPjBg1_Mp2,BR4CT_BC1PVldMPjBg1_Mp2,BR4CT_EPPssblVldMPjBg1_Mp2,
//    BR4CT_STFAILMPjBg1_Mp2,BR4CT_ASP2VldMPjBg1_Mp2,BR4CT_ASP2VldMPjBg2_Mp2,BR4CT_BC2PVldMPjBg1_Mp2;

//    signed short int BR4CT_ASP2MPjBg1_Mp2,BR4CT_ASP1MPjBg2_Mp2,BR4CT_EPPssblMPjBg2_Mp2,BR4CT_SpdMPjAxl3_Mp2,BR4CT_SpdMPjAxl4_Mp2,BR4CT_BCP1MPjBg2_Mp2,
//    BR4CT_BCP2MPjBg2_Mp2;
//    bool BR4CT_ASP1VldMPjBg2_Mp2,BR4CT_SpdVldMPjAxl3_Mp2,BR4CT_SpdVldMPjAxl4_Mp2,BR4CT_EPRlsdMPjBg2_Mp2,BR4CT_EPAppldMPjBg2_Mp2,BR4CT_WSPActvMPjAxle3_Mp2,
//    BR4CT_STOKMPjBg2_Mp2,BR4CT_EBActvMPjBg2_Mp2,BR4CT_EBAvlblMPjBg2_Mp2,BR4CT_HBAppldMPjBg2_Mp2,BR4CT_BC1PVldMPjBg2_Mp2,BR4CT_EPPssblVldMPjBg2_Mp2,
//    BR4CT_STFAILMPjBg2_Mp2,BR4CT_WSPActvMPjAxle2_Mp2,BR4CT_WSPActvMPjAxle4_Mp2,BR4CT_BC2PVldMPjBg2_Mp2;

//    signed short int BR4CT_ASP2MPjBg2_Mp2;
//    bool BR4CT_LwBSRTCjBg1_Mp2,BR4CT_LwBSRTCjBg2_Mp2,BR4CT_LwBSRMPjBg1_Mp2,BR4CT_LwBSRMPjBg2_Mp2,BR4CT_FtlErrTCjBg1_Mp2,BR4CT_FtlErrTCjBg2_Mp2,
//    BR4CT_FtlErrMPjBg1_Mp2,BR4CT_FtlErrMPjBg2_Mp2,BR4CT_MntnncWrnngTCjBg1_Mp2,BR4CT_MntnncWrnngTCjBg2_Mp2,BR4CT_MntnncWrnngMPjBg1_Mp2,BR4CT_MntnncWrnngMPjBg2_Mp2,
//    BR4CT_ASPOtOfRngTCjBg1_Mp2,BR4CT_ASPOtOfRngTCjBg2_Mp2,BR4CT_ASPOtOfRngMPjBg1_Mp2,BR4CT_ASPOtOfRngMPjBg2_Mp2,BR4CT_CANBsFlt_Mp2,BR4CT_BrRqstIncnsstnt_Mp2,
//    BR4CT_STExcd26H_Mp2,BR4CT_EdBrFdHghSpd_Mp2,BR4CT_EdBrFdLwSpd_Mp2,BR4CT_ASPRdy_Mp2,BR4CT_MjrEvnt_Mp2,BR4CT_MdmEvnt_Mp2,
//    BR4CT_MnrEvnt_Mp2,BR4CT_STExcd00H_Mp2,BR4CT_BrNtRlsdTCjBg1_Mp2,BR4CT_BrNtRlsdTCjBg2_Mp2,BR4CT_BrNtRlsdMPjBg1_Mp2,BR4CT_BrNtRlsdMPjBg2_Mp2,
//    BR4CT_SpdSnsrFltTCjAxle1_Mp2,BR4CT_SpdSnsrFltTCjAxle2_Mp2,BR4CT_SpdSnsrFltTCjAxle3_Mp2,BR4CT_SpdSnsrFltTCjAxle4_Mp2,BR4CT_SpdSnsrFltMPjAxle1_Mp2,BR4CT_SpdSnsrFltMPjAxle2_Mp2,
//    BR4CT_SpdSnsrFltMPjAxle3_Mp2,BR4CT_SpdSnsrFltMPjAxle4_Mp2,BR4CT_2ndErrTCjBg1_Mp2,BR4CT_2ndErrTCjBg2_Mp2,BR4CT_2ndErrMPjBg1_Mp2,BR4CT_2ndErrMPjBg2_Mp2,
//    BR4CT_FBrIncnsstnt_Mp2,BR4CT_MRPVld_Mp2,BR4CT_CB01SWVrsnVld_Mp2,BR4CT_MVBSWVrsnVld_Mp2,BR4CT_EB01SWVrsnVld_Mp2;

//    signed char BR4CT_CB01SWVrsn_Mp2,BR4CT_MVBSWVrsn_Mp2,BR4CT_EB01SWVrsn_Mp2;
//    signed short int BR4CT_MRP_Mp2;

//    //0x460,0x461,0x462,0x463
//    signed short int BR6CT_LfSgn_A2,BR6CT_MssTCjBg1_A2,BR6CT_MssTCjBg2_A2,BR6CT_MssMPjBg1_A2,BR6CT_MssMPjBg2_A2,BR6CT_SpdTrain_A2;
//    bool BR6CT_MssVldTCjBg1_A2,BR6CT_MssVldTCjBg2_A2,BR6CT_MssVldMPjBg1_A2,BR6CT_MssVldMPjBg2_A2,BR6CT_SpdTrainVld_A2,BR6CT_SttsDgnssVldTCjBg1_A2,
//    BR6CT_SttsDgnssVldTCjBg2_A2,BR6CT_SttsDgnssVldMPjBg1_A2,BR6CT_SttsDgnssVldMPjBg2_A2,BR6CT_EPOKTCjBg1_A2,BR6CT_EPOKTCjBg2_A2,BR6CT_EPOKMPjBg1_A2,
//    BR6CT_EPOKMPjBg2_A2,BR6CT_EDCtOffMPj_A2,BR6CT_HWBrSt_A2,BR6CT_HWFstBrSt_A2,BR6CT_HWTrctnSt_A2,BR6CT_ZrSpd_A2,
//    BR6CT_EBActv_A2,BR6CT_MstrBCU_A2,BR6CT_SeBrAc50_A2,BR6CT_TwngMd_A2,BR6CT_EmOprnMd_A2,BR6CT_TwngIstrct3_A2,
//    BR6CT_STRdy_A2,BR6CT_STActv_A2;

//    signed short int BR6CT_ASP1TCjBg1_A2,BR6CT_EPPssblTCjBg1_A2,BR6CT_SpdTCjAxl1_A2,BR6CT_SpdTCjAxl2_A2,BR6CT_BCP1TCjBg1_A2,BR6CT_BCP2TCjBg1_A2;
//    bool BR6CT_ASP1VldTCjBg1_A2,BR6CT_SpdVldTCjAxl1_A2,BR6CT_SpdVldTCjAxl2_A2,BR6CT_EPRlsdTCjBg1_A2,BR6CT_EPAppldTCjBg1_A2,BR6CT_WSPActvTCjAxl1_A2,
//    BR6CT_STOKTCjBg1_A2,BR6CT_EBActvTCjBg1_A2,BR6CT_EBAvlblTCjBg1_A2,BR6CT_HBAppldTCjBg1_A2,BR6CT_BC1PVldTCjBg1_A2,BR6CT_EPPssblVldTCjBg1_A2,
//    BR6CT_STFAILTCjBg1_A2,BR6CT_ASP2VldTCjBg1_A2,BR6CT_ASP2VldTCjBg2_A2,BR6CT_BCP2VldTCjBg1_A2;

//    signed short int BR6CT_ASP2TCjBg1_A2,BR6CT_ASP1TCjBg2_A2,BR6CT_EPPssblTCjBg2_A2,BR6CT_SpdTCjAxl3_A2,BR6CT_SpdTCjAxl4_A2,BR6CT_BCP1TCjBg2_A2,
//    BR6CT_BCP2TCjBg2_A2;
//    bool BR6CT_ASP1VldTCjBg2_A2,BR6CT_SpdVldTCjAxl3_A2,BR6CT_SpdVldTCjAxl4_A2,BR6CT_EPRlsdTCjBg2_A2,BR6CT_EPAppldTCjBg2_A2,BR6CT_WSPActvTCjAxle3_A2,
//    BR6CT_STOKTCjBg2_A2,BR6CT_EBActvTCjBg2_A2,BR6CT_EBAvlblTCjBg2_A2,BR6CT_HBAppldTCjBg2_A2,BR6CT_BC1PVldTCjBg2_A2,BR6CT_EPPssblVldTCj2Bg2_A2,
//    BR6CT_STFAILTCjBg2_A2,BR6CT_WSPActvTCjAxle2_A2,BR6CT_WSPActvTCjAxle4_A2,BR6CT_BC2PVldTCjBg2_A2;

//    signed short int BR6CT_ASP2TCjBg2_A2,BR6CT_ASP1MPjBg1_A2,BR6CT_EPPssblMPjBg1_A2,BR6CT_SpdMPjAxl1_A2,BR6CT_SpdMPjAxl2_A2,BR6CT_BCP1MPjBg1_A2,
//    BR6CT_BCP2MPjBg1_A2;
//    bool BR6CT_ASP1VldMPjBg1_A2,BR6CT_SpdVldMPjAxl1_A2,BR6CT_SpdVldMPjAxl2_A2,BR6CT_EPRlsdMPjBg1_A2,BR6CT_EPAppldMPjBg1_A2,BR6CT_WSPActvMPjAxle1_A2,
//    BR6CT_STOKMPjBg1_A2,BR6CT_EBActvMPjBg1_A2,BR6CT_EBAvlblMPjBg1_A2,BR6CT_HBAppldMPjBg1_A2,BR6CT_BC1PVldMPjBg1_A2,BR6CT_EPPssblVldMPjBg1_A2,
//    BR6CT_STFAILMPjBg1_A2,BR6CT_ASP2VldMPjBg1_A2,BR6CT_ASP2VldMPjBg2_A2,BR6CT_BC2PVldMPjBg1_A2;

//    signed short int BR6CT_ASP2MPjBg1_A2,BR6CT_ASP1MPjBg2_A2,BR6CT_EPPssblMPjBg2_A2,BR6CT_SpdMPjAxl3_A2,BR6CT_SpdMPjAxl4_A2,BR6CT_BCP1MPjBg2_A2,
//    BR6CT_BCP2MPjBg2_A2;
//    bool BR6CT_ASP1VldMPjBg2_A2,BR6CT_SpdVldMPjAxl3_A2,BR6CT_SpdVldMPjAxl4_A2,BR6CT_EPRlsdMPjBg2_A2,BR6CT_EPAppldMPjBg2_A2,BR6CT_WSPActvMPjAxle3_A2,
//    BR6CT_STOKMPjBg2_A2,BR6CT_EBActvMPjBg2_A2,BR6CT_EBAvlblMPjBg2_A2,BR6CT_HBAppldMPjBg2_A2,BR6CT_BC1PVldMPjBg2_A2,BR6CT_EPPssblVldMPjBg2_A2,
//    BR6CT_STFAILMPjBg2_A2,BR6CT_WSPActvMPjAxle2_A2,BR6CT_WSPActvMPjAxle4_A2,BR6CT_BC2PVldMPjBg2_A2;

//    signed short int BR6CT_ASP2MPjBg2_A2;
//    bool BR6CT_LwBSRTCjBg1_A2,BR6CT_LwBSRTCjBg2_A2,BR6CT_LwBSRMPjBg1_A2,BR6CT_LwBSRMPjBg2_A2,BR6CT_FtlErrTCjBg1_A2,BR6CT_FtlErrTCjBg2_A2,
//    BR6CT_FtlErrMPjBg1_A2,BR6CT_FtlErrMPjBg2_A2,BR6CT_MntnncWrnngTCjBg1_A2,BR6CT_MntnncWrnngTCjBg2_A2,BR6CT_MntnncWrnngMPjBg1_A2,BR6CT_MntnncWrnngMPjBg2_A2,
//    BR6CT_ASPOtOfRngTCjBg1_A2,BR6CT_ASPOtOfRngTCjBg2_A2,BR6CT_ASPOtOfRngMPjBg1_A2,BR6CT_ASPOtOfRngMPjBg2_A2,BR6CT_CANBsFlt_A2,BR6CT_BrRqstIncnsstnt_A2,
//    BR6CT_STExcd26H_A2,BR6CT_EdBrFdHghSpd_A2,BR6CT_EdBrFdLwSpd_A2,BR6CT_ASPRdy_A2,BR6CT_MjrEvnt_A2,BR6CT_MdmEvnt_A2,
//    BR6CT_MnrEvnt_A2,BR6CT_STExcd00H_A2,BR6CT_BrNtRlsdTCjBg1_A2,BR6CT_BrNtRlsdTCjBg2_A2,BR6CT_BrNtRlsdMPjBg1_A2,BR6CT_BrNtRlsdMPjBg2_A2,
//    BR6CT_SpdSnsrFltTCjAxle1_A2,BR6CT_SpdSnsrFltTCjAxle2_A2,BR6CT_SpdSnsrFltTCjAxle3_A2,BR6CT_SpdSnsrFltTCjAxle4_A2,BR6CT_SpdSnsrFltMPjAxle1_A2,BR6CT_SpdSnsrFltMPjAxle2_A2,
//    BR6CT_SpdSnsrFltMPjAxle3_A2,BR6CT_SpdSnsrFltMPjAxle4_A2,BR6CT_2ndErrTCjBg1_A2,BR6CT_2ndErrTCjBg2_A2,BR6CT_2ndErrMPjBg1_A2,BR6CT_2ndErrMPjBg2_A2,
//    BR6CT_FBrIncnsstnt_A2,BR6CT_MRPVld_A2,BR6CT_CB01SWVrsnVld_A2,BR6CT_MVBSWVrsnVld_A2,BR6CT_EB01SWVrsnVld_A2;

//    signed char BR6CT_CB01SWVrsn_A2,BR6CT_MVBSWVrsn_A2,BR6CT_EB01SWVrsn_A2;
//    signed short int BR6CT_MRP_A2;

    // bcu signals in hmi
    //TC1/MP1
//    signed short int hmiBrake1_LfSgn_A1,hmiBrake1_MssTCjBg1_A1,hmiBrake1_MssTCjBg2_A1,hmiBrake1_MssMPjBg1_A1,hmiBrake1_MssMPjBg2_A1,hmiBrake1_SpdTrain_A1;
//    bool hmiBrake1_MssVldTCjBg1_A1,hmiBrake1_MssVldTCjBg2,hmiBrake1_MssVldMPjBg1,hmiBrake1_MssVldMPjBg2,hmiBrake1_SpdTrainVld,hmiBrake1_SttsDgnssVldTCjBg1,
//    hmiBrake1_SttsDgnssVldTCjBg2,hmiBrake1_SttsDgnssVldMPjBg1,hmiBrake1_SttsDgnssVldMPjBg2,hmiBrake1_EPOKTCjBg1,hmiBrake1_EPOKTCjBg2,hmiBrake1_EPOKMPjBg1,
//    hmiBrake1_EPOKMPjBg2,hmiBrake1_EDCtOffMPj,hmiBrake1_HWBrSt,hmiBrake1_HWFstBrSt,hmiBrake1_HWTrctnSt,hmiBrake1_ZrSpd,
//    hmiBrake1_EBActv,hmiBrake1_MstrBCU,hmiBrake1_SeBrAc50,hmiBrake1_TwngMd,hmiBrake1_EmOprnMd,hmiBrake1_TwngIstrct3,
//    hmiBrake1_STRdy,hmiBrake1_STActv,hmiAcTeststart,hmiAcTestStop;
      bool hmiAcTeststart,hmiAcTestStop;
//    signed short int hmiBrake1_ASP1TCjBg1_A1,hmiBrake1_EPPssblTCjBg1_A1,hmiBrake1_SpdTCjAxl1_A1,hmiBrake1_SpdTCjAxl2_A1,hmiBrake1_BCP1TCjBg1_A1,hmiBrake1_BCP2TCjBg1_A1;
//    bool hmiBrake1_ASP1VldTCjBg1,hmiBrake1_SpdVldTCjAxl1,hmiBrake1_SpdVldTCjAxl2,hmiBrake1_EPRlsdTCjBg1,hmiBrake1_EPAppldTCjBg1,hmiBrake1_WSPActvTCjAxle1,
//    hmiBrake1_STOKTCjBg1,hmiBrake1_EBActvTCjBg1,hmiBrake1_EBAvlblTCjBg1,hmiBrake1_HBAppldTCjBg1,hmiBrake1_BC1PVldTCjBg1,hmiBrake1_EPPssblVldTCjBg1,
//    hmiBrake1_STFAILTCjBg1,hmiBrake1_ASP2VldTCjBg1,hmiBrake1_ASP2VldTCjBg2,hmiBrake1_BCP2VldTCjBg1;

//    signed short int hmiBrake1_ASP2TCjBg1_A1,hmiBrake1_ASP1TCjBg2_A1,hmiBrake1_EPPssblTCjBg2_A1,hmiBrake1_SpdTCjAxl3_A1,hmiBrake1_SpdTCjAxl4_A1,hmiBrake1_BCP1TCjBg2_A1,
//    hmiBrake1_BCP2TCjBg2_A1;
//    bool hmiBrake1_ASP1VldTCjBg2,hmiBrake1_SpdVldTCjAxl3,hmiBrake1_SpdVldTCjAxl4,hmiBrake1_EPRlsdTCjBg2,hmiBrake1_EPAppldTCjBg2,hmiBrake1_WSPActvTCjAxle3,
//    hmiBrake1_STOKTCjBg2,hmiBrake1_EBActvTCjBg2,hmiBrake1_EBAvlblTCjBg2,hmiBrake1_HBAppldTCjBg2,hmiBrake1_BC1PVldTCjBg2,hmiBrake1_EPPssblVldTCj2Bg2,
//    hmiBrake1_STFAILTCjBg2,hmiBrake1_WSPActvTCjAxle2,hmiBrake1_WSPActvTCjAxle4,hmiBrake1_BC2PVldTCjBg2;

//    signed short int hmiBrake1_ASP2TCjBg2_A1,hmiBrake1_ASP1MPjBg1_A1,hmiBrake1_EPPssblMPjBg1_A1,hmiBrake1_SpdMPjAxl1_A1,hmiBrake1_SpdMPjAxl2_A1,hmiBrake1_BCP1MPjBg1_A1,
//    hmiBrake1_BCP2MPjBg1_A1;
//    bool hmiBrake1_ASP1VldMPjBg1,hmiBrake1_SpdVldMPjAxl1,hmiBrake1_SpdVldMPjAxl2,hmiBrake1_EPRlsdMPjBg1,hmiBrake1_EPAppldMPjBg1,hmiBrake1_WSPActvMPjAxle1,
//    hmiBrake1_STOKMPjBg1,hmiBrake1_EBActvMPjBg1,hmiBrake1_EBAvlblMPjBg1,hmiBrake1_HBAppldMPjBg1,hmiBrake1_BC1PVldMPjBg1,hmiBrake1_EPPssblVldMPjBg1,
//    hmiBrake1_STFAILMPjBg1,hmiBrake1_ASP2VldMPjBg1,hmiBrake1_ASP2VldMPjBg2,hmiBrake1_BC2PVldMPjBg1;

//    signed short int hmiBrake1_ASP2MPjBg1_A1,hmiBrake1_ASP1MPjBg2_A1,hmiBrake1_EPPssblMPjBg2_A1,hmiBrake1_SpdMPjAxl3_A1,hmiBrake1_SpdMPjAxl4_A1,hmiBrake1_BCP1MPjBg2_A1,
//    hmiBrake1_BCP2MPjBg2_A1;
//    bool hmiBrake1_ASP1VldMPjBg2,hmiBrake1_SpdVldMPjAxl3,hmiBrake1_SpdVldMPjAxl4,hmiBrake1_EPRlsdMPjBg2,hmiBrake1_EPAppldMPjBg2,hmiBrake1_WSPActvMPjAxle3,
//    hmiBrake1_STOKMPjBg2,hmiBrake1_EBActvMPjBg2,hmiBrake1_EBAvlblMPjBg2,hmiBrake1_HBAppldMPjBg2,hmiBrake1_BC1PVldMPjBg2,hmiBrake1_EPPssblVldMPjBg2,
//    hmiBrake1_STFAILMPjBg2,hmiBrake1_WSPActvMPjAxle2,hmiBrake1_WSPActvMPjAxle4,hmiBrake1_BC2PVldMPjBg2;

//    signed short int hmiBrake1_ASP2MPjBg2_A1;
//    bool hmiBrake1_LwBSRTCjBg1,hmiBrake1_LwBSRTCjBg2,hmiBrake1_LwBSRMPjBg1,hmiBrake1_LwBSRMPjBg2,hmiBrake1_FtlErrTCjBg1,hmiBrake1_FtlErrTCjBg2,
//    hmiBrake1_FtlErrMPjBg1,hmiBrake1_FtlErrMPjBg2,hmiBrake1_MntnncWrnngTCjBg1,hmiBrake1_MntnncWrnngTCjBg2,hmiBrake1_MntnncWrnngMPjBg1,hmiBrake1_MntnncWrnngMPjBg2,
//    hmiBrake1_ASPOtOfRngTCjBg1,hmiBrake1_ASPOtOfRngTCjBg2,hmiBrake1_ASPOtOfRngMPjBg1,hmiBrake1_ASPOtOfRngMPjBg2,hmiBrake1_CANBsFlt,hmiBrake1_BrRqstIncnsstnt,
//    hmiBrake1_STExcd26H,hmiBrake1_EdBrFdHghSpd,hmiBrake1_EdBrFdLwSpd,hmiBrake1_ASPRdy,hmiBrake1_MjrEvnt,hmiBrake1_MdmEvnt,
//    hmiBrake1_MnrEvnt,hmiBrake1_STExcd00H,hmiBrake1_BrNtRlsdTCjBg1,hmiBrake1_BrNtRlsdTCjBg2,hmiBrake1_BrNtRlsdMPjBg1,hmiBrake1_BrNtRlsdMPjBg2,
//    hmiBrake1_SpdSnsrFltTCjAxle1,hmiBrake1_SpdSnsrFltTCjAxle2,hmiBrake1_SpdSnsrFltTCjAxle3,hmiBrake1_SpdSnsrFltTCjAxle4,hmiBrake1_SpdSnsrFltMPjAxle1,hmiBrake1_SpdSnsrFltMPjAxle2,
//    hmiBrake1_SpdSnsrFltMPjAxle3,hmiBrake1_SpdSnsrFltMPjAxle4,hmiBrake1_2ndErrTCjBg1,hmiBrake1_2ndErrTCjBg2,hmiBrake1_2ndErrMPjBg1,hmiBrake1_2ndErrMPjBg2,
//    hmiBrake1_FBrIncnsstnt,hmiBrake1_MRPVld,hmiBrake1_CB01SWVrsnVld,hmiBrake1_MVBSWVrsnVld,hmiBrake1_EB01SWVrsnVld;

//    signed char hmiBrake1_CB01SWVrsn_A1,hmiBrake1_MVBSWVrsn_A1,hmiBrake1_EB01SWVrsn_A1;
//    signed short int hmiBrake1_MRP_A1;

//    //TC2/MP2
//    signed short int hmiBrake2_LfSgn_A2,hmiBrake2_MssTCjBg1_A2,hmiBrake2_MssTCjBg2_A2,hmiBrake2_MssMPjBg1_A2,hmiBrake2_MssMPjBg2_A2,hmiBrake2_SpdTrain_A2;
//    bool hmiBrake2_MssVldTCjBg1_A2,hmiBrake2_MssVldTCjBg2_A2,hmiBrake2_MssVldMPjBg1_A2,hmiBrake2_MssVldMPjBg2_A2,hmiBrake2_SpdTrainVld_A2,hmiBrake2_SttsDgnssVldTCjBg1_A2,
//    hmiBrake2_SttsDgnssVldTCjBg2_A2,hmiBrake2_SttsDgnssVldMPjBg1_A2,hmiBrake2_SttsDgnssVldMPjBg2_A2,hmiBrake2_EPOKTCjBg1_A2,hmiBrake2_EPOKTCjBg2_A2,hmiBrake2_EPOKMPjBg1_A2,
//    hmiBrake2_EPOKMPjBg2_A2,hmiBrake2_EDCtOffMPj_A2,hmiBrake2_HWBrSt_A2,hmiBrake2_HWFstBrSt_A2,hmiBrake2_HWTrctnSt_A2,hmiBrake2_ZrSpd_A2,
//    hmiBrake2_EBActv_A2,hmiBrake2_MstrBCU_A2,hmiBrake2_SeBrAc50_A2,hmiBrake2_TwngMd_A2,hmiBrake2_EmOprnMd_A2,hmiBrake2_TwngIstrct3_A2,
//    hmiBrake2_STRdy_A2,hmiBrake2_STActv_A2;

//    signed short int hmiBrake2_ASP1TC1jBg1_A2,hmiBrake2_EPPssblTCjBg1_A2,hmiBrake2_SpdTCjAxl1_A2,hmiBrake2_SpdTCjAxl2_A2,hmiBrake2_BCP1TCjBg1_A2,hmiBrake2_BCP2TCjBg1_A2;
//    bool hmiBrake2_ASP1VldTCjBg1_A2,hmiBrake2_SpdVldTCjAxl1_A2,hmiBrake2_SpdVldTCjAxl2_A2,hmiBrake2_EPRlsdTCjBg1_A2,hmiBrake2_EPAppldTCjBg1_A2,hmiBrake2_WSPActvTCjAxle1_A2,
//    hmiBrake2_STOKTCjBg1_A2,hmiBrake2_EBActvTCjBg1_A2,hmiBrake2_EBAvlblTCjBg1_A2,hmiBrake2_HBAppldTCjBg1_A2,hmiBrake2_BC1PVldTCjBg1_A2,hmiBrake2_EPPssblVldTCjBg1_A2,
//    hmiBrake2_STFAILTCjBg1_A2,hmiBrake2_ASP2VldTCjBg1_A2,hmiBrake2_ASP2VldTCjBg2_A2,hmiBrake2_BCP2VldTCjBg1_A2;

//    signed short int hmiBrake2_ASP2TCjBg1_A2,hmiBrake2_ASP1TCjBg2_A2,hmiBrake2_EPPssblTCjBg2_A2,hmiBrake2_SpdTCjAxl3_A2,hmiBrake2_SpdTCjAxl4_A2,hmiBrake2_BCP1TCjBg2_A2,
//    hmiBrake2_BCP2TCjBg2_A2;
//    bool hmiBrake2_ASP1VldTCjBg2_A2,hmiBrake2_SpdVldTCjAxl3_A2,hmiBrake2_SpdVldTCjAxl4_A2,hmiBrake2_EPRlsdTCjBg2_A2,hmiBrake2_EPAppldTCjBg2_A2,hmiBrake2_WSPActvTCjAxle3_A2,
//    hmiBrake2_STOKTCjBg2_A2,hmiBrake2_EBActvTCjBg2_A2,hmiBrake2_EBAvlblTCjBg2_A2,hmiBrake2_HBAppldTCjBg2_A2,hmiBrake2_BC1PVldTCjBg2_A2,hmiBrake2_EPPssblVldTCj2Bg2_A2,
//    hmiBrake2_STFAILTCjBg2_A2,hmiBrake2_WSPActvTCjAxle2_A2,hmiBrake2_WSPActvTCjAxle4_A2,hmiBrake2_BC2PVldTCjBg2_A2;

//    signed short int hmiBrake2_ASP2TCjBg2_A2,hmiBrake2_ASP1MPjBg1_A2,hmiBrake2_EPPssblMPjBg1_A2,hmiBrake2_SpdMPjAxl1_A2,hmiBrake2_SpdMPjAxl2_A2,hmiBrake2_BCP1MPjBg1_A2,
//    hmiBrake2_BCP2MPjBg1_A2;
//    bool hmiBrake2_ASP1VldMPjBg1_A2,hmiBrake2_SpdVldMPjAxl1_A2,hmiBrake2_SpdVldMPjAxl2_A2,hmiBrake2_EPRlsdMPjBg1_A2,hmiBrake2_EPAppldMPjBg1_A2,hmiBrake2_WSPActvMPjAxle1_A2,
//    hmiBrake2_STOKMPjBg1_A2,hmiBrake2_EBActvMPjBg1_A2,hmiBrake2_EBAvlblMPjBg1_A2,hmiBrake2_HBAppldMPjBg1_A2,hmiBrake2_BC1PVldMPjBg1_A2,hmiBrake2_EPPssblVldMPjBg1_A2,
//    hmiBrake2_STFAILMPjBg1_A2,hmiBrake2_ASP2VldMPjBg1_A2,hmiBrake2_ASP2VldMPjBg2_A2,hmiBrake2_BC2PVldMPjBg1_A2;

//    signed short int hmiBrake2_ASP2MPjBg1_A2,hmiBrake2_ASP1MPjBg2_A2,hmiBrake2_EPPssblMPjBg2_A2,hmiBrake2_SpdMPjAxl3_A2,hmiBrake2_SpdMPjAxl4_A2,hmiBrake2_BCP1MPjBg2_A2,
//    hmiBrake2_BCP2MPjBg2_A2;
//    bool hmiBrake2_ASP1VldMPjBg2_A2,hmiBrake2_SpdVldMPjAxl3_A2,hmiBrake2_SpdVldMPjAxl4_A2,hmiBrake2_EPRlsdMPjBg2_A2,hmiBrake2_EPAppldMPjBg2_A2,hmiBrake2_WSPActvMPjAxle3_A2,
//    hmiBrake2_STOKMPjBg2_A2,hmiBrake2_EBActvMPjBg2_A2,hmiBrake2_EBAvlblMPjBg2_A2,hmiBrake2_HBAppldMPjBg2_A2,hmiBrake2_BC1PVldMPjBg2_A2,hmiBrake2_EPPssblVldMPjBg2_A2,
//    hmiBrake2_STFAILMPjBg2_A2,hmiBrake2_WSPActvMPjAxle2_A2,hmiBrake2_WSPActvMPjAxle4_A2,hmiBrake2_BC2PVldMPjBg2_A2;

//    signed short int hmiBrake2_ASP2MPjBg2_A2;
//    bool hmiBrake2_LwBSRTCjBg1_A2,hmiBrake2_LwBSRTCjBg2_A2,hmiBrake2_LwBSRMPjBg1_A2,hmiBrake2_LwBSRMPjBg2_A2,hmiBrake2_FtlErrTCjBg1_A2,hmiBrake2_FtlErrTCjBg2_A2,
//    hmiBrake2_FtlErrMPjBg1_A2,hmiBrake2_FtlErrMPjBg2_A2,hmiBrake2_MntnncWrnngTCjBg1_A2,hmiBrake2_MntnncWrnngTCjBg2_A2,hmiBrake2_MntnncWrnngMPjBg1_A2,hmiBrake2_MntnncWrnngMPjBg2_A2,
//    hmiBrake2_ASPOtOfRngTCjBg1_A2,hmiBrake2_ASPOtOfRngTCjBg2_A2,hmiBrake2_ASPOtOfRngMPjBg1_A2,hmiBrake2_ASPOtOfRngMPjBg2_A2,hmiBrake2_CANBsFlt_A2,hmiBrake2_BrRqstIncnsstnt_A2,
//    hmiBrake2_STExcd26H_A2,hmiBrake2_EdBrFdHghSpd_A2,hmiBrake2_EdBrFdLwSpd_A2,hmiBrake2_ASPRdy_A2,hmiBrake2_MjrEvnt_A2,hmiBrake2_MdmEvnt_A2,
//    hmiBrake2_MnrEvnt_A2,hmiBrake2_STExcd00H_A2,hmiBrake2_BrNtRlsdTCjBg1_A2,hmiBrake2_BrNtRlsdTCjBg2_A2,hmiBrake2_BrNtRlsdMPjBg1_A2,hmiBrake2_BrNtRlsdMPjBg2_A2,
//    hmiBrake2_SpdSnsrFltTCjAxle1_A2,hmiBrake2_SpdSnsrFltTCjAxle2_A2,hmiBrake2_SpdSnsrFltTCjAxle3_A2,hmiBrake2_SpdSnsrFltTCjAxle4_A2,hmiBrake2_SpdSnsrFltMPjAxle1_A2,hmiBrake2_SpdSnsrFltMPjAxle2_A2,
//    hmiBrake2_SpdSnsrFltMPjAxle3_A2,hmiBrake2_SpdSnsrFltMPjAxle4_A2,hmiBrake2_2ndErrTCjBg1_A2,hmiBrake2_2ndErrTCjBg2_A2,hmiBrake2_2ndErrMPjBg1_A2,hmiBrake2_2ndErrMPjBg2_A2,
//    hmiBrake2_FBrIncnsstnt_A2,hmiBrake2_MRPVld_A2,hmiBrake2_CB01SWVrsnVld_A2,hmiBrake2_MVBSWVrsnVld_A2,hmiBrake2_EB01SWVrsnVld_A2;

//    signed char hmiBrake2_CB01SWVrsn_A2,hmiBrake2_MVBSWVrsn_A2,hmiBrake2_EB01SWVrsn_A2;
//    signed short int hmiBrake2_MRP_A2;

    //ERM signals in hmi
    unsigned short int hmiAccerate, hmiBrakeDistance;
    unsigned char hmiLevel, hmiBrakeStartSpeed;
    bool hmiTestDataValid;
    QString hmiRunClass, hmiRegeneration;
    quint32 runningKilometers, VVVFEngyConsumption, SIVEngyConsumption, ReEngy, ServiceDistance, AP1RunningTime, AP2RunningTime, TCMSTotalTime;
    unsigned char totalDistanceYear, totalDistanceMonth, totalDistanceDay, VVVFECYear, VVVFECMonth, VVVFECDay, SIVECYear, SIVECMonth, SIVECDay;
    unsigned char reEngyYear, reEngyMonth, reEngyDay, serviceDistanceYear, serviceDistanceMonth, serviceDistanceDay, AP1ECYear, AP1ECMonth, AP1ECDay;
    unsigned char AP2ECYear, AP2ECMonth, AP2ECDay, TCMSTotalTimeYear, TCMSTotalTimeMonth, TCMSTotalDay;
    unsigned char ridingRateTc1, ridingRateMp1, ridingRateMp2, ridingRateTc2;
    QString serviceDistanceDisplay, TCMSTotalTimeDisplay;
    //0x418
    signed char CTBR_AchEDFrcMP1,CTBR_AchEDFrcMP2;
    bool CTBR_CutHoldBrk;
    signed short int CTBR_PerBrFrc;
    bool CTBR_Driving,CTBR_Braking,CTBR_EBLpOpen,CTBR_ATOMode,CTBR_ATOHBApply,CTBR_HBRls,
    CTBR_EDFdOt,CTBR_EDOKMP1,CTBR_EDSldMP1,CTBR_AchEDFrcVldMP1,CTBR_EDFrcAblyVldMP1,CTBR_EDOKMP2,
    CTBR_EDSldMP2,CTBR_AchEDFrcVldMP2,CTBR_EDFrcAblyVldMP2,CTBR_AllDrsClsd,CTBR_PerBrFrcVld,CTBR_StartST,
    CTBR_RunST,CTBR_DiamReqTC1,CTBR_DiamReqMP1,CTBR_DiamReqMP2,CTBR_DiamReqTC2;
    signed char CTBR_WhDiamTC1,CTBR_WhDiamMP1,CTBR_WhDiamMP2,CTBR_WhDiamTC2,CTBR_CodeST;
    signed short int CTBR_EDFrcAblyMP1,CTBR_EDFrcAblyMP2;

    //0x520/0x521/0x522/0x523
    unsigned short int TR2CT_T1LifeSignalVCU;
    bool TR2CT_M1MainConState,TR2CT_M1CharConState,TR2CT_HSCBState,TR2CT_HSCBDemand,TR2CT_T1CutOff,TR2CT_A1Slide,
    TR2CT_A1EBAvailable,TR2CT_A1EBSlide,TR2CT_A1EBDecrease,TR2CT_A1EBCutOff,TR2CT_A1EBOK,TR2CT_BrkReleaseReq1,
    TR2CT_AllBrkReleased1,TR2CT_T1SafetyBrk,TR2CT_T1PM1ReBrkPulse,TR2CT_T1PM1TrtPulse,TR2CT_T1RadOverTemp,TR2CT_T1HSCBNotClosed,
    TR2CT_T1LB1NotClosed,TR2CT_T1LB2NotClosed,TR2CT_T1OverCurrent,TR2CT_T1OverSpeed,TR2CT_T1TMCSFault,TR2CT_T1LineOverVolt,
    TR2CT_T1InverterOverCur,TR2CT_T1NetOverCur,TR2CT_T1NetOverVolt,TR2CT_T1OverTime,TR2CT_T1ChargeFault,TR2CT_T1DriverFlt,
    TR2CT_T1MotorOverTem,TR2CT_T1DirectionFlt,TR2CT_T1InstructionFlt,TR2CT_T1OverCurU,TR2CT_T1OverCurV,TR2CT_T1SpeedSensorFlt,
    TR2CT_T1BrkNotRealesed,TR2CT_T1LineOverVoltSet,TR2CT_T1LineOverCur,TR2CT_T1DriverFltU,TR2CT_T1DriverFltV,TR2CT_T1DriverFltW,
    TR2CT_T1PhaseLess,TR2CT_T1NetUnderVolt;

    unsigned short int  TR2CT_T1TractionEffort,TR2CT_T1ActualEBEffort,TR2CT_M1LineCur,TR2CT_NetVoltage,TR2CT_T1InverterCurrent,TR2CT_A1MotorSpeed,
    TR2CT_A1MotorTemp,TR2CT_T1SwVersion,TR2CT_T1LifeSignal,TR2CT_T2LifeSignalVCU;

    bool TR2CT_T2CutOff,TR2CT_A2Slide,TR2CT_A2EBAvailable,TR2CT_A2EBSlide,TR2CT_A2EBDecrease,TR2CT_A2EBCutOff,
    TR2CT_A2EBOK,TR2CT_BrkReleaseReq2,TR2CT_AllBrkReleased2,TR2CT_T2SafetyBrk,TR2CT_T2RadOverTemp,TR2CT_T2HSCBNotClosed,
    TR2CT_T2LB1NotClosed,TR2CT_T2LB2NotClosed,TR2CT_T2OverCurrent,TR2CT_T2OverSpeed,TR2CT_T2TMCSFault,TR2CT_T2LineOverVolt,
    TR2CT_T2InverterOverCur,TR2CT_T2NetOverCur,TR2CT_T2NetOverVolt,TR2CT_T2OverTime,TR2CT_T2ChargeFault,TR2CT_T2DriverFlt,
    TR2CT_T2MotorOverTem,TR2CT_T2DirectionFlt,TR2CT_T2InstructionFlt,TR2CT_T2OverCurU,TR2CT_T2OverCurV,TR2CT_T2SpeedSensorFlt,
    TR2CT_T2BrkNotRealesed,TR2CT_T2LineOverVoltSet,TR2CT_T2LineOverCur,TR2CT_T2DriverFltU,TR2CT_T2DriverFltV,TR2CT_T2DriverFltW,
    TR2CT_T2PhaseLess,TR2CT_T2NetUnderVolt;

    unsigned short int TR2CT_T2TractionEffort,TR2CT_T2ActualEBEffort,TR2CT_T2InverterCurrent,TR2CT_A2MotorSpeed,TR2CT_A2MotorTemp,TR2CT_T2SwVersion,
    TR2CT_T2LifeSignal,TR2CT_M1LineVol,TR2CT_T3LifeSignalVCU;

    bool TR2CT_M2MainConState,TR2CT_M2CharConState,TR2CT_T3CutOff,TR2CT_A3Slide,TR2CT_A3EBAvailable,TR2CT_A3EBSlide,
    TR2CT_A3EBDecrease,TR2CT_A3EBCutOff,TR2CT_A3EBOK,TR2CT_BrkReleaseReq3,TR2CT_AllBrkReleased3,TR2CT_T3SafetyBrk,
    TR2CT_PM2ReBrkPulse,TR2CT_PM2TrtPulse,TR2CT_T3RadOverTemp,TR2CT_T3HSCBNotClosed,TR2CT_T3LB1NotClosed,TR2CT_T3LB2NotClosed,
    TR2CT_T3OverCurrent,TR2CT_T3OverSpeed,TR2CT_T3TMCSFault,TR2CT_T3LineOverVolt,TR2CT_T3InverterOverCur,TR2CT_T3NetOverCur,
    TR2CT_T3NetOverVolt,TR2CT_T3OverTime,TR2CT_T3ChargeFault,TR2CT_T3DriverFlt,TR2CT_T3MotorOverTem,TR2CT_T3DirectionFlt,
    TR2CT_T3InstructionFlt,TR2CT_T3OverCurU,TR2CT_T3OverCurV,TR2CT_T3SpeedSensorFlt,TR2CT_T3BrkNotRealesed,TR2CT_T3LineOverVoltSet,
    TR2CT_T3LineOverCur,TR2CT_T3DriverFltU,TR2CT_T3DriverFltV,TR2CT_T3DriverFltW,TR2CT_T3PhaseLess,TR2CT_T3NetUnderVolt;

    unsigned short int TR2CT_T3TractionEffort,TR2CT_T3ActualEBEffort,TR2CT_M2LineCur,TR2CT_T3InverterCurrent,TR2CT_A3MotorSpeed,TR2CT_A3MotorTemp,
    TR2CT_T3SwVersion,TR2CT_T3LifeSignal;

    unsigned char TR2CT_GWLifeSignal;
    unsigned short int TR2CT_T4LifeSignalVCU;
    bool TR2CT_T4CutOff,TR2CT_A4Slide,TR2CT_A4EBAvailable,TR2CT_A4EBSlide,TR2CT_A4EBDecrease,TR2CT_A4EBCutOff,
    TR2CT_A4EBOK,TR2CT_BrkReleaseReq4,TR2CT_AllBrkReleased4,TR2CT_T4SafetyBrk,TR2CT_T4RadOverTemp,TR2CT_T4HSCBNotClosed,
    TR2CT_T4LB1NotClosed,TR2CT_T4LB2NotClosed,TR2CT_T4OverCurrent,TR2CT_T4OverSpeed,TR2CT_T4TMCSFault,TR2CT_T4LineOverVolt,
    TR2CT_T4InverterOverCur,TR2CT_T4NetOverCur,TR2CT_T4NetOverVolt,TR2CT_T4OverTime,TR2CT_T4ChargeFault,TR2CT_T4DriverFlt,
    TR2CT_T4MotorOverTem,TR2CT_T4DirectionFlt,TR2CT_T4InstructionFlt,TR2CT_T4OverCurU,TR2CT_T4OverCurV,TR2CT_T4SpeedSensorFlt,
    TR2CT_T4BrkNotRealesed,TR2CT_T4LineOverVoltSet,TR2CT_T4LineOverCur,TR2CT_T4DriverFltU,TR2CT_T4DriverFltV,TR2CT_T4DriverFltW,
    TR2CT_T4PhaseLess,TR2CT_T4NetUnderVolt;

    unsigned short int TR2CT_T4TractionEffort,TR2CT_T4ActualEBEffort,TR2CT_T4InverterCurrent,TR2CT_A4MotorSpeed,TR2CT_A4MotorTemp,TR2CT_T4SwVersion,
    TR2CT_T4LifeSignal,TR2CT_M2LineVol;

    unsigned char TR2CT_GWVersion;

    //0x530/0x531/0x532/0x533
    unsigned short int TR3CT_T1LifeSignalVCU;
    bool TR3CT_M1MainConState,TR3CT_M1CharConState,TR3CT_HSCBState,TR3CT_HSCBDemand,TR3CT_T1CutOff,TR3CT_A1Slide,
    TR3CT_A1EBAvailable,TR3CT_A1EBSlide,TR3CT_A1EBDecrease,TR3CT_A1EBCutOff,TR3CT_A1EBOK,TR3CT_BrkReleaseReq1,
    TR3CT_AllBrkReleased1,TR3CT_T1SafetyBrk,TR3CT_T1PM1ReBrkPulse,TR3CT_T1PM1TrtPulse,TR3CT_T1RadOverTemp,TR3CT_T1HSCBNotClosed,
    TR3CT_T1LB1NotClosed,TR3CT_T1LB2NotClosed,TR3CT_T1OverCurrent,TR3CT_T1OverSpeed,TR3CT_T1TMCSFault,TR3CT_T1LineOverVolt,
    TR3CT_T1InverterOverCur,TR3CT_T1NetOverCur,TR3CT_T1NetOverVolt,TR3CT_T1OverTime,TR3CT_T1ChargeFault,TR3CT_T1DriverFlt,
    TR3CT_T1MotorOverTem,TR3CT_T1DirectionFlt,TR3CT_T1InstructionFlt,TR3CT_T1OverCurU,TR3CT_T1OverCurV,TR3CT_T1SpeedSensorFlt,
    TR3CT_T1BrkNotRealesed,TR3CT_T1LineOverVoltSet,TR3CT_T1LineOverCur,TR3CT_T1DriverFltU,TR3CT_T1DriverFltV,TR3CT_T1DriverFltW,
    TR3CT_T1PhaseLess,TR3CT_T1NetUnderVolt;

    unsigned short int TR3CT_T1TractionEffort,TR3CT_T1ActualEBEffort,TR3CT_M1LineCur,TR3CT_NetVoltage,TR3CT_T1InverterCurrent,TR3CT_A1MotorSpeed,
    TR3CT_A1MotorTemp,TR3CT_T1SwVersion,TR3CT_T1LifeSignal,TR3CT_T2LifeSignalVCU;

    bool TR3CT_T2CutOff,TR3CT_A2Slide,TR3CT_A2EBAvailable,TR3CT_A2EBSlide,TR3CT_A2EBDecrease,TR3CT_A2EBCutOff,
    TR3CT_A2EBOK,TR3CT_BrkReleaseReq2,TR3CT_AllBrkReleased2,TR3CT_T2SafetyBrk,TR3CT_T2RadOverTemp,TR3CT_T2HSCBNotClosed,
    TR3CT_T2LB1NotClosed,TR3CT_T2LB2NotClosed,TR3CT_T2OverCurrent,TR3CT_T2OverSpeed,TR3CT_T2TMCSFault,TR3CT_T2LineOverVolt,
    TR3CT_T2InverterOverCur,TR3CT_T2NetOverCur,TR3CT_T2NetOverVolt,TR3CT_T2OverTime,TR3CT_T2ChargeFault,TR3CT_T2DriverFlt,
    TR3CT_T2MotorOverTem,TR3CT_T2DirectionFlt,TR3CT_T2InstructionFlt,TR3CT_T2OverCurU,TR3CT_T2OverCurV,TR3CT_T2SpeedSensorFlt,
    TR3CT_T2BrkNotRealesed,TR3CT_T2LineOverVoltSet,TR3CT_T2LineOverCur,TR3CT_T2DriverFltU,TR3CT_T2DriverFltV,TR3CT_T2DriverFltW,
    TR3CT_T2PhaseLess,TR3CT_T2NetUnderVolt;

    unsigned short int TR3CT_T2TractionEffort,TR3CT_T2ActualEBEffort,TR3CT_T2InverterCurrent,TR3CT_A2MotorSpeed,TR3CT_A2MotorTemp,TR3CT_T2SwVersion,
    TR3CT_T2LifeSignal,TR3CT_M1LineVol,TR3CT_T3LifeSignalVCU;

    bool TR3CT_M2MainConState,TR3CT_M2CharConState,TR3CT_T3CutOff,TR3CT_A3Slide,TR3CT_A3EBAvailable,TR3CT_A3EBSlide,
    TR3CT_A3EBDecrease,TR3CT_A3EBCutOff,TR3CT_A3EBOK,TR3CT_BrkReleaseReq3,TR3CT_AllBrkReleased3,TR3CT_T3SafetyBrk,
    TR3CT_PM2ReBrkPulse,TR3CT_PM2TrtPulse,TR3CT_T3RadOverTemp,TR3CT_T3HSCBNotClosed,TR3CT_T3LB1NotClosed,TR3CT_T3LB2NotClosed,
    TR3CT_T3OverCurrent,TR3CT_T3OverSpeed,TR3CT_T3TMCSFault,TR3CT_T3LineOverVolt,TR3CT_T3InverterOverCur,TR3CT_T3NetOverCur,
    TR3CT_T3NetOverVolt,TR3CT_T3OverTime,TR3CT_T3ChargeFault,TR3CT_T3DriverFlt,TR3CT_T3MotorOverTem,TR3CT_T3DirectionFlt,
    TR3CT_T3InstructionFlt,TR3CT_T3OverCurU,TR3CT_T3OverCurV,TR3CT_T3SpeedSensorFlt,TR3CT_T3BrkNotRealesed,TR3CT_T3LineOverVoltSet,
    TR3CT_T3LineOverCur,TR3CT_T3DriverFltU,TR3CT_T3DriverFltV,TR3CT_T3DriverFltW,TR3CT_T3PhaseLess,TR3CT_T3NetUnderVolt;

    unsigned short int TR3CT_T3TractionEffort,TR3CT_T3ActualEBEffort,TR3CT_M2LineCur,TR3CT_T3InverterCurrent,TR3CT_A3MotorSpeed,TR3CT_A3MotorTemp,
    TR3CT_T3SwVersion,TR3CT_T3LifeSignal;

    unsigned char TR3CT_GWLifeSignal;
    unsigned short int TR3CT_T4LifeSignalVCU;
    bool TR3CT_T4CutOff,TR3CT_A4Slide,TR3CT_A4EBAvailable,TR3CT_A4EBSlide,TR3CT_A4EBDecrease,TR3CT_A4EBCutOff,
    TR3CT_A4EBOK,TR3CT_BrkReleaseReq4,TR3CT_AllBrkReleased4,TR3CT_T4SafetyBrk,TR3CT_T4RadOverTemp,TR3CT_T4HSCBNotClosed,
    TR3CT_T4LB1NotClosed,TR3CT_T4LB2NotClosed,TR3CT_T4OverCurrent,TR3CT_T4OverSpeed,TR3CT_T4TMCSFault,TR3CT_T4LineOverVolt,
    TR3CT_T4InverterOverCur,TR3CT_T4NetOverCur,TR3CT_T4NetOverVolt,TR3CT_T4OverTime,TR3CT_T4ChargeFault,TR3CT_T4DriverFlt,
    TR3CT_T4MotorOverTem,TR3CT_T4DirectionFlt,TR3CT_T4InstructionFlt,TR3CT_T4OverCurU,TR3CT_T4OverCurV,TR3CT_T4SpeedSensorFlt,
    TR3CT_T4BrkNotRealesed,TR3CT_T4LineOverVoltSet,TR3CT_T4LineOverCur,TR3CT_T4DriverFltU,TR3CT_T4DriverFltV,TR3CT_T4DriverFltW,
    TR3CT_T4PhaseLess,TR3CT_T4NetUnderVolt;

    unsigned short int TR3CT_T4TractionEffort,TR3CT_T4ActualEBEffort,TR3CT_T4InverterCurrent,TR3CT_A4MotorSpeed,TR3CT_A4MotorTemp,TR3CT_T4SwVersion,
    TR3CT_T4LifeSignal,TR3CT_M2LineVol;
    unsigned char TR3CT_GWVersion;

    //0x540/0x541/0x542/0x543
    unsigned short int TR4CT_T1LifeSignalVCU;
    bool TR4CT_M1MainConState,TR4CT_M1CharConState,TR4CT_HSCBState,TR4CT_HSCBDemand,TR4CT_T1CutOff,TR4CT_A1Slide,
    TR4CT_A1EBAvailable,TR4CT_A1EBSlide,TR4CT_A1EBDecrease,TR4CT_A1EBCutOff,TR4CT_A1EBOK,TR4CT_BrkReleaseReq1,
    TR4CT_AllBrkReleased1,TR4CT_T1SafetyBrk,TR4CT_T1PM1ReBrkPulse,TR4CT_T1PM1TrtPulse,TR4CT_T1RadOverTemp,TR4CT_T1HSCBNotClosed,
    TR4CT_T1LB1NotClosed,TR4CT_T1LB2NotClosed,TR4CT_T1OverCurrent,TR4CT_T1OverSpeed,TR4CT_T1TMCSFault,TR4CT_T1LineOverVolt,
    TR4CT_T1InverterOverCur,TR4CT_T1NetOverCur,TR4CT_T1NetOverVolt,TR4CT_T1OverTime,TR4CT_T1ChargeFault,TR4CT_T1DriverFlt,
    TR4CT_T1MotorOverTem,TR4CT_T1DirectionFlt,TR4CT_T1InstructionFlt,TR4CT_T1OverCurU,TR4CT_T1OverCurV,TR4CT_T1SpeedSensorFlt,
    TR4CT_T1BrkNotRealesed,TR4CT_T1LineOverVoltSet,TR4CT_T1LineOverCur,TR4CT_T1DriverFltU,TR4CT_T1DriverFltV,TR4CT_T1DriverFltW,
    TR4CT_T1PhaseLess,TR4CT_T1NetUnderVolt;

    unsigned short int TR4CT_T1TractionEffort,TR4CT_T1ActualEBEffort,TR4CT_M1LineCur,TR4CT_NetVoltage,TR4CT_T1InverterCurrent,TR4CT_A1MotorSpeed,
    TR4CT_A1MotorTemp,TR4CT_T1SwVersion,TR4CT_T1LifeSignal,TR4CT_T2LifeSignalVCU;

    bool TR4CT_T2CutOff,TR4CT_A2Slide,TR4CT_A2EBAvailable,TR4CT_A2EBSlide,TR4CT_A2EBDecrease,TR4CT_A2EBCutOff,
    TR4CT_A2EBOK,TR4CT_BrkReleaseReq2,TR4CT_AllBrkReleased2,TR4CT_T2SafetyBrk,TR4CT_T2RadOverTemp,TR4CT_T2HSCBNotClosed,
    TR4CT_T2LB1NotClosed,TR4CT_T2LB2NotClosed,TR4CT_T2OverCurrent,TR4CT_T2OverSpeed,TR4CT_T2TMCSFault,TR4CT_T2LineOverVolt,
    TR4CT_T2InverterOverCur,TR4CT_T2NetOverCur,TR4CT_T2NetOverVolt,TR4CT_T2OverTime,TR4CT_T2ChargeFault,TR4CT_T2DriverFlt,
    TR4CT_T2MotorOverTem,TR4CT_T2DirectionFlt,TR4CT_T2InstructionFlt,TR4CT_T2OverCurU,TR4CT_T2OverCurV,TR4CT_T2SpeedSensorFlt,
    TR4CT_T2BrkNotRealesed,TR4CT_T2LineOverVoltSet,TR4CT_T2LineOverCur,TR4CT_T2DriverFltU,TR4CT_T2DriverFltV,TR4CT_T2DriverFltW,
    TR4CT_T2PhaseLess,TR4CT_T2NetUnderVolt;

    unsigned short int TR4CT_T2TractionEffort,TR4CT_T2ActualEBEffort,TR4CT_T2InverterCurrent,TR4CT_A2MotorSpeed,TR4CT_A2MotorTemp,TR4CT_T2SwVersion,
    TR4CT_T2LifeSignal,TR4CT_M1LineVol,TR4CT_T3LifeSignalVCU;

    bool TR4CT_M2MainConState,TR4CT_M2CharConState,TR4CT_T3CutOff,TR4CT_A3Slide,TR4CT_A3EBAvailable,TR4CT_A3EBSlide,
    TR4CT_A3EBDecrease,TR4CT_A3EBCutOff,TR4CT_A3EBOK,TR4CT_BrkReleaseReq3,TR4CT_AllBrkReleased3,TR4CT_T3SafetyBrk,
    TR4CT_PM2ReBrkPulse,TR4CT_PM2TrtPulse,TR4CT_T3RadOverTemp,TR4CT_T3HSCBNotClosed,TR4CT_T3LB1NotClosed,TR4CT_T3LB2NotClosed,
    TR4CT_T3OverCurrent,TR4CT_T3OverSpeed,TR4CT_T3TMCSFault,TR4CT_T3LineOverVolt,TR4CT_T3InverterOverCur,TR4CT_T3NetOverCur,
    TR4CT_T3NetOverVolt,TR4CT_T3OverTime,TR4CT_T3ChargeFault,TR4CT_T3DriverFlt,TR4CT_T3MotorOverTem,TR4CT_T3DirectionFlt,
    TR4CT_T3InstructionFlt,TR4CT_T3OverCurU,TR4CT_T3OverCurV,TR4CT_T3SpeedSensorFlt,TR4CT_T3BrkNotRealesed,TR4CT_T3LineOverVoltSet,
    TR4CT_T3LineOverCur,TR4CT_T3DriverFltU,TR4CT_T3DriverFltV,TR4CT_T3DriverFltW,TR4CT_T3PhaseLess,TR4CT_T3NetUnderVolt;

    unsigned short int TR4CT_T3TractionEffort,TR4CT_T3ActualEBEffort,TR4CT_M2LineCur,TR4CT_T3InverterCurrent,TR4CT_A3MotorSpeed,TR4CT_A3MotorTemp,
    TR4CT_T3SwVersion,TR4CT_T3LifeSignal;

    unsigned char TR4CT_GWLifeSignal;
    unsigned short int TR4CT_T4LifeSignalVCU;
    bool TR4CT_T4CutOff,TR4CT_A4Slide,TR4CT_A4EBAvailable,TR4CT_A4EBSlide,TR4CT_A4EBDecrease,TR4CT_A4EBCutOff,
    TR4CT_A4EBOK,TR4CT_BrkReleaseReq4,TR4CT_AllBrkReleased4,TR4CT_T4SafetyBrk,TR4CT_T4RadOverTemp,TR4CT_T4HSCBNotClosed,
    TR4CT_T4LB1NotClosed,TR4CT_T4LB2NotClosed,TR4CT_T4OverCurrent,TR4CT_T4OverSpeed,TR4CT_T4TMCSFault,TR4CT_T4LineOverVolt,
    TR4CT_T4InverterOverCur,TR4CT_T4NetOverCur,TR4CT_T4NetOverVolt,TR4CT_T4OverTime,TR4CT_T4ChargeFault,TR4CT_T4DriverFlt,
    TR4CT_T4MotorOverTem,TR4CT_T4DirectionFlt,TR4CT_T4InstructionFlt,TR4CT_T4OverCurU,TR4CT_T4OverCurV,TR4CT_T4SpeedSensorFlt,
    TR4CT_T4BrkNotRealesed,TR4CT_T4LineOverVoltSet,TR4CT_T4LineOverCur,TR4CT_T4DriverFltU,TR4CT_T4DriverFltV,TR4CT_T4DriverFltW,
    TR4CT_T4PhaseLess,TR4CT_T4NetUnderVolt;

    unsigned short int TR4CT_T4TractionEffort,TR4CT_T4ActualEBEffort,TR4CT_T4InverterCurrent,TR4CT_A4MotorSpeed,TR4CT_A4MotorTemp,TR4CT_T4SwVersion,
    TR4CT_T4LifeSignal,TR4CT_M2LineVol;
    unsigned char TR4CT_GWVersion;

    //0x550/0x551/0x552/0x553
    unsigned short int TR5CT_T1LifeSignalVCU;
    bool TR5CT_M1MainConState,TR5CT_M1CharConState,TR5CT_HSCBState,TR5CT_HSCBDemand,TR5CT_T1CutOff,TR5CT_A1Slide,
    TR5CT_A1EBAvailable,TR5CT_A1EBSlide,TR5CT_A1EBDecrease,TR5CT_A1EBCutOff,TR5CT_A1EBOK,TR5CT_BrkReleaseReq1,
    TR5CT_AllBrkReleased1,TR5CT_T1SafetyBrk,TR5CT_T1PM1ReBrkPulse,TR5CT_T1PM1TrtPulse,TR5CT_T1RadOverTemp,TR5CT_T1HSCBNotClosed,
    TR5CT_T1LB1NotClosed,TR5CT_T1LB2NotClosed,TR5CT_T1OverCurrent,TR5CT_T1OverSpeed,TR5CT_T1TMCSFault,TR5CT_T1LineOverVolt,
    TR5CT_T1InverterOverCur,TR5CT_T1NetOverCur,TR5CT_T1NetOverVolt,TR5CT_T1OverTime,TR5CT_T1ChargeFault,TR5CT_T1DriverFlt,
    TR5CT_T1MotorOverTem,TR5CT_T1DirectionFlt,TR5CT_T1InstructionFlt,TR5CT_T1OverCurU,TR5CT_T1OverCurV,TR5CT_T1SpeedSensorFlt,
    TR5CT_T1BrkNotRealesed,TR5CT_T1LineOverVoltSet,TR5CT_T1LineOverCur,TR5CT_T1DriverFltU,TR5CT_T1DriverFltV,TR5CT_T1DriverFltW,
    TR5CT_T1PhaseLess,TR5CT_T1NetUnderVolt;

    unsigned short int TR5CT_T1TractionEffort,TR5CT_T1ActualEBEffort,TR5CT_M1LineCur,TR5CT_NetVoltage,TR5CT_T1InverterCurrent,TR5CT_A1MotorSpeed,
    TR5CT_A1MotorTemp,TR5CT_T1SwVersion,TR5CT_T1LifeSignal,TR5CT_T2LifeSignalVCU;

    bool TR5CT_T2CutOff,TR5CT_A2Slide,TR5CT_A2EBAvailable,TR5CT_A2EBSlide,TR5CT_A2EBDecrease,TR5CT_A2EBCutOff,
    TR5CT_A2EBOK,TR5CT_BrkReleaseReq2,TR5CT_AllBrkReleased2,TR5CT_T2SafetyBrk,TR5CT_T2RadOverTemp,TR5CT_T2HSCBNotClosed,
    TR5CT_T2LB1NotClosed,TR5CT_T2LB2NotClosed,TR5CT_T2OverCurrent,TR5CT_T2OverSpeed,TR5CT_T2TMCSFault,TR5CT_T2LineOverVolt,
    TR5CT_T2InverterOverCur,TR5CT_T2NetOverCur,TR5CT_T2NetOverVolt,TR5CT_T2OverTime,TR5CT_T2ChargeFault,TR5CT_T2DriverFlt,
    TR5CT_T2MotorOverTem,TR5CT_T2DirectionFlt,TR5CT_T2InstructionFlt,TR5CT_T2OverCurU,TR5CT_T2OverCurV,TR5CT_T2SpeedSensorFlt,
    TR5CT_T2BrkNotRealesed,TR5CT_T2LineOverVoltSet,TR5CT_T2LineOverCur,TR5CT_T2DriverFltU,TR5CT_T2DriverFltV,TR5CT_T2DriverFltW,
    TR5CT_T2PhaseLess,TR5CT_T2NetUnderVolt;

    unsigned short int TR5CT_T2TractionEffort,TR5CT_T2ActualEBEffort,TR5CT_T2InverterCurrent,TR5CT_A2MotorSpeed,TR5CT_A2MotorTemp,TR5CT_T2SwVersion,
    TR5CT_T2LifeSignal,TR5CT_M1LineVol,TR5CT_T3LifeSignalVCU;

    bool TR5CT_M2MainConState,TR5CT_M2CharConState,TR5CT_T3CutOff,TR5CT_A3Slide,TR5CT_A3EBAvailable,TR5CT_A3EBSlide,
    TR5CT_A3EBDecrease,TR5CT_A3EBCutOff,TR5CT_A3EBOK,TR5CT_BrkReleaseReq3,TR5CT_AllBrkReleased3,TR5CT_T3SafetyBrk,
    TR5CT_PM2ReBrkPulse,TR5CT_PM2TrtPulse,TR5CT_T3RadOverTemp,TR5CT_T3HSCBNotClosed,TR5CT_T3LB1NotClosed,TR5CT_T3LB2NotClosed,
    TR5CT_T3OverCurrent,TR5CT_T3OverSpeed,TR5CT_T3TMCSFault,TR5CT_T3LineOverVolt,TR5CT_T3InverterOverCur,TR5CT_T3NetOverCur,
    TR5CT_T3NetOverVolt,TR5CT_T3OverTime,TR5CT_T3ChargeFault,TR5CT_T3DriverFlt,TR5CT_T3MotorOverTem,TR5CT_T3DirectionFlt,
    TR5CT_T3InstructionFlt,TR5CT_T3OverCurU,TR5CT_T3OverCurV,TR5CT_T3SpeedSensorFlt,TR5CT_T3BrkNotRealesed,TR5CT_T3LineOverVoltSet,
    TR5CT_T3LineOverCur,TR5CT_T3DriverFltU,TR5CT_T3DriverFltV,TR5CT_T3DriverFltW,TR5CT_T3PhaseLess,TR5CT_T3NetUnderVolt;

    unsigned short int TR5CT_T3TractionEffort,TR5CT_T3ActualEBEffort,TR5CT_M2LineCur,TR5CT_T3InverterCurrent,TR5CT_A3MotorSpeed,TR5CT_A3MotorTemp,
    TR5CT_T3SwVersion,TR5CT_T3LifeSignal;

    unsigned char TR5CT_GWLifeSignal;
    unsigned short int TR5CT_T4LifeSignalVCU;
    bool TR5CT_T4CutOff,TR5CT_A4Slide,TR5CT_A4EBAvailable,TR5CT_A4EBSlide,TR5CT_A4EBDecrease,TR5CT_A4EBCutOff,
    TR5CT_A4EBOK,TR5CT_BrkReleaseReq4,TR5CT_AllBrkReleased4,TR5CT_T4SafetyBrk,TR5CT_T4RadOverTemp,TR5CT_T4HSCBNotClosed,
    TR5CT_T4LB1NotClosed,TR5CT_T4LB2NotClosed,TR5CT_T4OverCurrent,TR5CT_T4OverSpeed,TR5CT_T4TMCSFault,TR5CT_T4LineOverVolt,
    TR5CT_T4InverterOverCur,TR5CT_T4NetOverCur,TR5CT_T4NetOverVolt,TR5CT_T4OverTime,TR5CT_T4ChargeFault,TR5CT_T4DriverFlt,
    TR5CT_T4MotorOverTem,TR5CT_T4DirectionFlt,TR5CT_T4InstructionFlt,TR5CT_T4OverCurU,TR5CT_T4OverCurV,TR5CT_T4SpeedSensorFlt,
    TR5CT_T4BrkNotRealesed,TR5CT_T4LineOverVoltSet,TR5CT_T4LineOverCur,TR5CT_T4DriverFltU,TR5CT_T4DriverFltV,TR5CT_T4DriverFltW,
    TR5CT_T4PhaseLess,TR5CT_T4NetUnderVolt;


    unsigned short int TR5CT_T4TractionEffort,TR5CT_T4ActualEBEffort,TR5CT_T4InverterCurrent,TR5CT_A4MotorSpeed,TR5CT_A4MotorTemp,TR5CT_T4SwVersion,
    TR5CT_T4LifeSignal,TR5CT_M2LineVol;
    unsigned char TR5CT_GWVersion;

    //0x528/0x538/0x548/0x558
    bool CTTR2_EBRelease,CTTR2_EBFade,CTTR2_EmBrake,CTTR2_Brake,CTTR2_Traction,CTTR2_Backward,
    CTTR2_Forward,CTTR2_PantUp,CTTR2_EBCutOff,CTTR2_WashingMode,CTTR2_Reverse,CTTR2_TractionAllowed,
    CTTR2_SpdLimitValid,CTTR2_TCU1CutOff,CTTR2_TCU2CutOff,CTTR2_TCU3CutOff,CTTR2_TCU4CutOff;

    unsigned char CTTRi_SpdLimit;
    unsigned short int CTTR2_MasterControler,CTTR2_EBReqValue,CTTR2_TrailerSpeed,CTTR2_Diameter,CTTR2_Load,CTTR2_TrailerLoad,
    CTTR2_VechileNumber;

    bool CTTR3_EBRelease,CTTR3_EBFade,CTTR3_EmBrake,CTTR3_Brake,CTTR3_Traction,CTTR3_Backward,
    CTTR3_Forward,CTTR3_PantUp,CTTR3_EBCutOff,CTTR3_WashingMode,CTTR3_Reverse,CTTR3_TractionAllowed,
    CTTR3_SpdLimitValid,CTTR3_TCU1CutOff,CTTR3_TCU2CutOff,CTTR3_TCU3CutOff,CTTR3_TCU4CutOff;

    unsigned char CTTR3_SpdLimit;
    unsigned short int CTTR3_MasterControler,CTTR3_EBReqValue,CTTR3_TrailerSpeed,CTTR3_Diameter,CTTR3_Load,CTTR3_TrailerLoad,
    CTTR3_VechileNumber;

    bool CTTR4_EBRelease,CTTR4_EBFade,CTTR4_EmBrake,CTTR4_Brake,CTTR4_Traction,CTTR4_Backward,
    CTTR4_Forward,CTTR4_PantUp,CTTR4_EBCutOff,CTTR4_WashingMode,CTTR4_Reverse,CTTR4_TractionAllowed,
    CTTR4_SpdLimitValid,CTTR4_TCU1CutOff,CTTR4_TCU2CutOff,CTTR4_TCU3CutOff,CTTR4_TCU4CutOff;

    unsigned char CTTR4_SpdLimit;
    unsigned short int CTTR4_MasterControler,CTTR4_EBReqValue,CTTR4_TrailerSpeed,CTTR4_Diameter,CTTR4_Load,CTTR4_TrailerLoad,
    CTTR4_VechileNumber;

    bool CTTR5_EBRelease,CTTR5_EBFade,CTTR5_EmBrake,CTTR5_Brake,CTTR5_Traction,CTTR5_Backward,
    CTTR5_Forward,CTTR5_PantUp,CTTR5_EBCutOff,CTTR5_WashingMode,CTTR5_Reverse,CTTR5_TractionAllowed,
    CTTR5_SpdLimitValid,CTTR5_TCU1CutOff,CTTR5_TCU2CutOff,CTTR5_TCU3CutOff,CTTR5_TCU4CutOff;

    unsigned char CTTR5_SpdLimit;
    unsigned short int CTTR5_MasterControler,CTTR5_EBReqValue,CTTR5_TrailerSpeed,CTTR5_Diameter,CTTR5_Load,CTTR5_TrailerLoad,
    CTTR5_VechileNumber;

    //0x610/0x611
    unsigned char AX1CT_SIVSwVersion;
    bool AX1CT_Fault,AX1CT_Running,AX1CT_Stop,AX1CT_ExtendEnable,AX1CT_DropPantStop,AX1CT_PowerValid,
    AX1CT_UVOverVol,AX1CT_VWOverVol,AX1CT_WUOverVol,AX1CT_UOverCur,AX1CT_VOverCur,AX1CT_WOverCur,
    AX1CT_LineHWOverVol,AX1CT_NetHWOverVol,AX1CT_PDPProtection,AX1CT_CtrlLowVoltage,AX1CT_UIGBTOverCur,AX1CT_VIGBTOverCur,
    AX1CT_WIGBTOverCur,AX1CT_UIGBTFlt,AX1CT_VIGBTFlt,AX1CT_WIGBTFlt,AX1CT_NetOverVol,AX1CT_LineOverVol,
    AX1CT_LineLowVol,AX1CT_UOutEffOverVol,AX1CT_VOutEffOverVol,AX1CT_WOutEffOverVol,AX1CT_UOutEffLowVol,AX1CT_VOutEffLowVol,
    AX1CT_WOutEffLowVol,AX1CT_UOutIEffOverCur,AX1CT_VOutIEffOverCur,AX1CT_WOutIEffOverCur,AX1CT_UOutIInsOverCur,AX1CT_VOutIInsOverCur,
    AX1CT_WOutIInsOverCur,AX1CT_NetLowerVol,AX1CT_UIGBTIEffOverCur,AX1CT_VIGBTIEffOverCur,AX1CT_WIGBTIEffOverCur,AX1CT_UIGBTIInsOverCur,
    AX1CT_VIGBTIInsOverCur,AX1CT_WIGBTIInsOverCur,AX1CT_UOutUIInsOverCur,AX1CT_VOutUIInsOverCur,AX1CT_WOutUIInsOverCur,AX1CT_OutputFreFlt,
    AX1CT_LackPhase,AX1CT_IGBTOverRHeat,AX1CT_Con15OverLoad,AX1CT_Ins2OverLoad,AX1CT_LineCShortFlt,AX1CT_IGBTOverSHeat,
    AX1CT_PreChargerLose,AX1CT_SoftStartLose,AX1CT_FastDischargerFlt,AX1CT_PreChargerKMFlt,AX1CT_MainKMFlt,AX1CT_OutputKMFlt,
    AX1CT_SelfcheckErr,AX1CT_FlashErr,AX1CT_AdcCheckErr,AX1CT_FuseFlt,AX1CT_CANFlt,AX1CT_THDOverHigh,
    AX1CT_ConSoftOverVol,AX1CT_ConSoftLowerVol,AX1CT_NetVolChangeBigger;

    unsigned char AX1CT_LifeSignal,AX1CT_InputCurrent;
    unsigned short int AX1CT_Power,AX1CT_InputVoltage,AX1CT_OutputACFrenq,AX1CT_LineVoltageDC,AX1CT_OutputVoltAC,AX1CT_OutputCurAC;
    unsigned char AX1CT_GWLifeSig,AX1CT_GWVersion;

    //0x620/0x621
    unsigned char AX2CT_SIVSwVersion;
    bool AX2CT_Fault,AX2CT_Running,AX2CT_Stop,AX2CT_ExtendEnable,AX2CT_DropPantStop,AX2CT_PowerValid,
    AX2CT_UVOverVol,AX2CT_VWOverVol,AX2CT_WUOverVol,AX2CT_UOverCur,AX2CT_VOverCur,AX2CT_WOverCur,
    AX2CT_LineHWOverVol,AX2CT_NetHWOverVol,AX2CT_PDPProtection,AX2CT_CtrlLowVoltage,AX2CT_UIGBTOverCur,AX2CT_VIGBTOverCur,
    AX2CT_WIGBTOverCur,AX2CT_UIGBTFlt,AX2CT_VIGBTFlt,AX2CT_WIGBTFlt,AX2CT_NetOverVol,AX2CT_LineOverVol,
    AX2CT_LineLowVol,AX2CT_UOutEffOverVol,AX2CT_VOutEffOverVol,AX2CT_WOutEffOverVol,AX2CT_UOutEffLowVol,AX2CT_VOutEffLowVol,
    AX2CT_WOutEffLowVol,AX2CT_UOutIEffOverCur,AX2CT_VOutIEffOverCur,AX2CT_WOutIEffOverCur,AX2CT_UOutIInsOverCur,AX2CT_VOutIInsOverCur,
    AX2CT_WOutIInsOverCur,AX2CT_NetLowerVol,AX2CT_UIGBTIEffOverCur,AX2CT_VIGBTIEffOverCur,AX2CT_WIGBTIEffOverCur,AX2CT_UIGBTIInsOverCur,
    AX2CT_VIGBTIInsOverCur,AX2CT_WIGBTIInsOverCur,AX2CT_UOutUIInsOverCur,AX2CT_VOutUIInsOverCur,AX2CT_WOutUIInsOverCur,AX2CT_OutputFreFlt,
    AX2CT_LackPhase,AX2CT_IGBTOverRHeat,AX2CT_Con15OverLoad,AX2CT_Ins2OverLoad,AX2CT_LineCShortFlt,AX2CT_IGBTOverSHeat,
    AX2CT_PreChargerLose,AX2CT_SoftStartLose,AX2CT_FastDischargerFlt,AX2CT_PreChargerKMFlt,AX2CT_MainKMFlt,AX2CT_OutputKMFlt,
    AX2CT_SelfcheckErr,AX2CT_FlashErr,AX2CT_AdcCheckErr,AX2CT_FuseFlt,AX2CT_CANFlt,AX2CT_THDOverHigh,
    AX2CT_ConSoftOverVol,AX2CT_ConSoftLowerVol,AX2CT_NetVolChangeBigger;

    unsigned char AX2CT_LifeSignal,AX2CT_InputCurrent;
    unsigned short int AX2CT_Power,AX2CT_InputVoltage,AX2CT_OutputACFrenq,AX2CT_LineVoltageDC,AX2CT_OutputVoltAC,AX2CT_OutputCurAC;
    unsigned char AX2CT_GWLifeSig,AX2CT_GWVersion;

    //0x618
    unsigned short int CTAX1_TrainSpeed;
    bool CTAX1_TestValid,CTAX1_ExtendPowerValid,CTAX1_Reset,CTAX1_Cutoff,CTAX1_PowerRec;
    unsigned char CTAX1_GWCode;

    //0x628
    unsigned short int CTAX2_TrainSpeed;
    bool CTAX2_TestValid,CTAX2_ExtendPowerValid,CTAX2_Reset,CTAX2_Cutoff,CTAX2_PowerRec;
    unsigned char CTAX2_GWCode;

    //0x810/0x811
    bool pisAutoMode;
    unsigned short int PA1CT_LifeSignal;
    unsigned char PA1CT_PASwVersion;
    bool PA1CT_StreamDirection,PA1CT_SkipStation,PA1CT_SkipNextStation,PA1CT_RightDoorOpen,PA1CT_LeftDoorOpen;
    unsigned short int PA1CT_StartStationID,PA1CT_DestinationID,PA1CT_NextStation;
    unsigned char PA1CT_EmBroadcastID;
    bool PA1CT_MasterActive,PA1CT_AutoMode,PA1CT_CabTalk,PA1CT_BroadcastingSta,PA1CT_OCCBroadcast;
    unsigned char PA1CT_BCStationFB;
    bool PA1CT_Tc1EMC1Alarm,PA1CT_Tc1EMC1On,PA1CT_Tc1EMC2Alarm,PA1CT_Tc1EMC2On,PA1CT_Mp1EMC1Alarm,PA1CT_Mp1EMC1On,
    PA1CT_Mp1EMC2Alarm,PA1CT_Mp1EMC2On;
    bool PA1CT_Mp2EMC1Alarm,PA1CT_Mp2EMC1On,PA1CT_Mp2EMC2Alarm,PA1CT_Mp2EMC2On,PA1CT_Tc2EMC1Alarm,PA1CT_Tc2EMC1On,
    PA1CT_Tc2EMC2Alarm,PA1CT_Tc2EMC2On,PA1CT_Tc1EMC3Alarm,PA1CT_Tc1EMC3On,PA1CT_Tc1EMC4Alarm,PA1CT_Tc1EMC4On,
    PA1CT_Mp1EMC3Alarm,PA1CT_Mp1EMC3On,PA1CT_Mp1EMC4Alarm,PA1CT_Mp1EMC4On,PA1CT_Mp2EMC3Alarm,PA1CT_Mp2EMC3On,
    PA1CT_Mp2EMC4Alarm,PA1CT_Mp2EMC4On,PA1CT_Tc2EMC3Alarm,PA1CT_Tc2EMC3On,PA1CT_Tc2EMC4Alarm,PA1CT_Tc2EMC4On,
    PA1CT_Tc1CabConFlt,PA1CT_Tc1BrdConFlt,PA1CT_Tc1endLEDFlt,PA1CT_Tc1RoomConFlt,PA1CT_Tc1LED1Flt,PA1CT_Tc1LED2Flt,
    PA1CT_Tc1Map1Flt,PA1CT_Tc1Map2Flt,PA1CT_Tc1Map3Flt,PA1CT_Tc1Map4Flt,PA1CT_Tc1Map5Flt,PA1CT_Tc1Map6Flt,
    PA1CT_Tc1Map7Flt,PA1CT_Tc1Map8Flt,PA1CT_Mp1RoomConFlt,PA1CT_Mp1LED1Flt,PA1CT_Mp1LED2Flt,PA1CT_Mp1Map1Flt,
    PA1CT_Mp1Map2Flt,PA1CT_Mp1Map3Flt,PA1CT_Mp1Map4Flt,PA1CT_Mp1Map5Flt,PA1CT_Mp1Map6Flt,PA1CT_Mp1Map7Flt,
    PA1CT_Mp1Map8Flt,PA1CT_Mp2RoomConFlt,PA1CT_Mp2LED1Flt,PA1CT_Mp2LED2Flt,PA1CT_Mp2Map1Flt,PA1CT_Mp2Map2Flt,
    PA1CT_Mp2Map3Flt,PA1CT_Mp2Map4Flt,PA1CT_Mp2Map5Flt,PA1CT_Mp2Map6Flt,PA1CT_Mp2Map7Flt,PA1CT_Mp2Map8Flt,
    PA1CT_Tc2CabConFlt,PA1CT_Tc2BrdConFlt,PA1CT_Tc2endLEDFlt,PA1CT_Tc2RoomConFlt,PA1CT_Tc2LED1Flt,PA1CT_Tc2LED2Flt,
    PA1CT_Tc2Map1Flt,PA1CT_Tc2Map2Flt,PA1CT_Tc2Map3Flt,PA1CT_Tc2Map4Flt,PA1CT_Tc2Map5Flt,PA1CT_Tc2Map6Flt,
    PA1CT_Tc2Map7Flt,PA1CT_Tc2Map8Flt,PA1CT_Tc1Video1NetFlt,PA1CT_Tc1Video2NetFlt,PA1CT_Tc1Video3NetFlt,PA1CT_Mp1Video1NetFlt,
    PA1CT_Mp1Video2NetFlt,PA1CT_Mp2Video1NetFlt,PA1CT_Mp2Video2NetFlt,PA1CT_Tc2Video1NetFlt,PA1CT_Tc2Video2NetFlt,PA1CT_Tc2Video3NetFlt;

    //0x820/0x821
    unsigned short int PA2CT_LifeSignal;
    unsigned char PA2CT_PASwVersion;
    bool PA2CT_StreamDirection,PA2CT_SkipStation,PA2CT_SkipNextStation,PA2CT_RightDoorOpen,PA2CT_LeftDoorOpen;
    unsigned short int PA2CT_StartStationID,PA2CT_DestinationID,PA2CT_NextStation;
    unsigned char PA2CT_EmBroadcastID;
    bool PA2CT_MasterActive,PA2CT_AutoMode,PA2CT_CabTalk,PA2CT_BroadcastingSta,PA2CT_OCCBroadcast;
    unsigned char PA2CT_BCStationFB;
    bool PA2CT_Tc1EMC1Alarm,PA2CT_Tc1EMC1On,PA2CT_Tc1EMC2Alarm,PA2CT_Tc1EMC2On,PA2CT_Mp1EMC1Alarm,PA2CT_Mp1EMC1On,
    PA2CT_Mp1EMC2Alarm,PA2CT_Mp1EMC2On;
    bool PA2CT_Mp2EMC1Alarm,PA2CT_Mp2EMC1On,PA2CT_Mp2EMC2Alarm,PA2CT_Mp2EMC2On,PA2CT_Tc2EMC1Alarm,PA2CT_Tc2EMC1On,
    PA2CT_Tc2EMC2Alarm,PA2CT_Tc2EMC2On,PA2CT_Tc1EMC3Alarm,PA2CT_Tc1EMC3On,PA2CT_Tc1EMC4Alarm,PA2CT_Tc1EMC4On,
    PA2CT_Mp1EMC3Alarm,PA2CT_Mp1EMC3On,PA2CT_Mp1EMC4Alarm,PA2CT_Mp1EMC4On,PA2CT_Mp2EMC3Alarm,PA2CT_Mp2EMC3On,
    PA2CT_Mp2EMC4Alarm,PA2CT_Mp2EMC4On,PA2CT_Tc2EMC3Alarm,PA2CT_Tc2EMC3On,PA2CT_Tc2EMC4Alarm,PA2CT_Tc2EMC4On,
    PA2CT_Tc1CabConFlt,PA2CT_Tc1BrdConFlt,PA2CT_Tc1endLEDFlt,PA2CT_Tc1RoomConFlt,PA2CT_Tc1LED1Flt,PA2CT_Tc1LED2Flt,
    PA2CT_Tc1Map1Flt,PA2CT_Tc1Map2Flt,PA2CT_Tc1Map3Flt,PA2CT_Tc1Map4Flt,PA2CT_Tc1Map5Flt,PA2CT_Tc1Map6Flt,
    PA2CT_Tc1Map7Flt,PA2CT_Tc1Map8Flt,PA2CT_Mp1RoomConFlt,PA2CT_Mp1LED1Flt,PA2CT_Mp1LED2Flt,PA2CT_Mp1Map1Flt,
    PA2CT_Mp1Map2Flt,PA2CT_Mp1Map3Flt,PA2CT_Mp1Map4Flt,PA2CT_Mp1Map5Flt,PA2CT_Mp1Map6Flt,PA2CT_Mp1Map7Flt,
    PA2CT_Mp1Map8Flt,PA2CT_Mp2RoomConFlt,PA2CT_Mp2LED1Flt,PA2CT_Mp2LED2Flt,PA2CT_Mp2Map1Flt,PA2CT_Mp2Map2Flt,
    PA2CT_Mp2Map3Flt,PA2CT_Mp2Map4Flt,PA2CT_Mp2Map5Flt,PA2CT_Mp2Map6Flt,PA2CT_Mp2Map7Flt,PA2CT_Mp2Map8Flt,
    PA2CT_Tc2CabConFlt,PA2CT_Tc2BrdConFlt,PA2CT_Tc2endLEDFlt,PA2CT_Tc2RoomConFlt,PA2CT_Tc2LED1Flt,PA2CT_Tc2LED2Flt,
    PA2CT_Tc2Map1Flt,PA2CT_Tc2Map2Flt,PA2CT_Tc2Map3Flt,PA2CT_Tc2Map4Flt,PA2CT_Tc2Map5Flt,PA2CT_Tc2Map6Flt,
    PA2CT_Tc2Map7Flt,PA2CT_Tc2Map8Flt,PA2CT_Tc1Video1NetFlt,PA2CT_Tc1Video2NetFlt,PA2CT_Tc1Video3NetFlt,PA2CT_Mp1Video1NetFlt,
    PA2CT_Mp1Video2NetFlt,PA2CT_Mp2Video1NetFlt,PA2CT_Mp2Video2NetFlt,PA2CT_Tc2Video1NetFlt,PA2CT_Tc2Video2NetFlt,PA2CT_Tc2Video3NetFlt;

    //0x808
    unsigned short int CTPA_TrainSpeed;
    unsigned char CTPA_EmBroadcastID,CTPA_ATCLifeSignal;
    bool CTPA_StreamDirection,CTPA_SkipStation,CTPA_SkipNextStation,CTPA_RightDoorOpen,CTPA_LeftDoorOpen;
    unsigned short int CTPA_StartStationID,CTPA_DestinationID,CTPA_NextStationID,CTPA_TrainID,CTPA_DisToNextStation;
    bool CTPA_TC1Master,CTPA_TC2Master,CTPA_CloseRightDoor,CTPA_OpenRightDoor,CTPA_CloseLeftDoor,CTPA_OpenLeftDoor,
    CTPA_AllDoorClosed,CTPA_ATOMode,CTPA_Cab1VideoShow,CTPA_Tc1Video1Show,CTPA_Tc1Video2Show,CTPA_Mp1Video1Show,
    CTPA_Mp1Video2Show,CTPA_Mp2Video1Show,CTPA_Mp2Video2Show,CTPA_Tc2Video1Show,CTPA_Tc2Video2Show,CTPA_Cab2VideoShow,
    CTPA_TracClash,CTPA_BrkClash,CTPA_EBClash,CTPA_SBClash,CTPA_ForwardClash,CTPA_BackwardClash,
    CTPA_CabActiveClash,CTPA_ForBackClash,CTPA_TrBrkClash,CTPA_LROpenClash;

    //0x910
    unsigned short int AC1CT_Lifesignal;
    unsigned char AC1CT_SWVersion1,AC1CT_SWVersion2,AC1CT_Mode,AC1CT_TempInside,AC1CT_TempOutside,AC1CT_TargetTemp;
    bool AC1CT_WorkingStste,AC1CT_LoadDecState,AC1CT_HeaterCenCon,AC1CT_Vent11State,AC1CT_Vent12State,AC1CT_Vent21State,
    AC1CT_Vent22State,AC1CT_Compressor11State,AC1CT_Compressor12State,AC1CT_Compressor21State,AC1CT_Compressor22State,AC1CT_Conden11State,
    AC1CT_Conden12State,AC1CT_Conden21State,AC1CT_Conden22State,AC1CT_PreHeater11State,AC1CT_PreHeater12State,AC1CT_PreHeater21State,
    AC1CT_PreHeater22State,AC1CT_Vent11Fault,AC1CT_Vent12Fault,AC1CT_Vent21Fault,AC1CT_Vent22Fault,AC1CT_Compressor11Fault,
    AC1CT_Compressor12Fault,AC1CT_Compressor21Fault,AC1CT_Compressor22Fault,AC1CT_Conden11Fault,AC1CT_Conden12Fault,AC1CT_Conden21Fault,
    AC1CT_Conden22Fault,AC1CT_PreHeater11Fault,AC1CT_PreHeater12Fault,AC1CT_PreHeater21Fault,AC1CT_PreHeater22Fault,AC1CT_FreshAir11Fault,
    AC1CT_FreshAir12Fault,AC1CT_ReAir11Fault,AC1CT_FreshAir21Fault,AC1CT_FreshAir22Fault,AC1CT_ReAir21Fault,AC1CT_Cleaner11Fault,
    AC1CT_Cleaner21Fault,AC1CT_EleHeating11Fault,AC1CT_EleHeating12Fault,AC1CT_EmcVent1Sta,AC1CT_EmcVent2Sta,AC1CT_EmcVentInvFault,
    AC1CT_EmcVent1Fault,AC1CT_EmcVent2Fault;

    //0x920
    unsigned short int AC2CT_Lifesignal;
    unsigned char AC2CT_SWVersion1,AC2CT_SWVersion2,AC2CT_Mode,AC2CT_TempInside,AC2CT_TempOutside,AC2CT_TargetTemp;
    bool AC2CT_WorkingStste,AC2CT_LoadDecState,AC2CT_HeaterCenCon,AC2CT_Vent11State,AC2CT_Vent12State,AC2CT_Vent21State,
    AC2CT_Vent22State,AC2CT_Compressor11State,AC2CT_Compressor12State,AC2CT_Compressor21State,AC2CT_Compressor22State,AC2CT_Conden11State,
    AC2CT_Conden12State,AC2CT_Conden21State,AC2CT_Conden22State,AC2CT_PreHeater11State,AC2CT_PreHeater12State,AC2CT_PreHeater21State,
    AC2CT_PreHeater22State,AC2CT_Vent11Fault,AC2CT_Vent12Fault,AC2CT_Vent21Fault,AC2CT_Vent22Fault,AC2CT_Compressor11Fault,
    AC2CT_Compressor12Fault,AC2CT_Compressor21Fault,AC2CT_Compressor22Fault,AC2CT_Conden11Fault,AC2CT_Conden12Fault,AC2CT_Conden21Fault,
    AC2CT_Conden22Fault,AC2CT_PreHeater11Fault,AC2CT_PreHeater12Fault,AC2CT_PreHeater21Fault,AC2CT_PreHeater22Fault,AC2CT_FreshAir11Fault,
    AC2CT_FreshAir12Fault,AC2CT_ReAir11Fault,AC2CT_FreshAir21Fault,AC2CT_FreshAir22Fault,AC2CT_ReAir21Fault,AC2CT_Cleaner11Fault,
    AC2CT_Cleaner21Fault,AC2CT_EleHeating11Fault,AC2CT_EleHeating12Fault,AC2CT_EmcVent1Sta,AC2CT_EmcVent2Sta,AC2CT_EmcVentInvFault,
    AC2CT_EmcVent1Fault,AC2CT_EmcVent2Fault;

    //0x930
    unsigned short int AC3CT_Lifesignal;
    unsigned char AC3CT_SWVersion1,AC3CT_SWVersion2,AC3CT_Mode,AC3CT_TempInside,AC3CT_TempOutside,AC3CT_TargetTemp;
    bool AC3CT_WorkingStste,AC3CT_LoadDecState,AC3CT_HeaterCenCon,AC3CT_Vent11State,AC3CT_Vent12State,AC3CT_Vent21State,
    AC3CT_Vent22State,AC3CT_Compressor11State,AC3CT_Compressor12State,AC3CT_Compressor21State,AC3CT_Compressor22State,AC3CT_Conden11State,
    AC3CT_Conden12State,AC3CT_Conden21State,AC3CT_Conden22State,AC3CT_PreHeater11State,AC3CT_PreHeater12State,AC3CT_PreHeater21State,
    AC3CT_PreHeater22State,AC3CT_Vent11Fault,AC3CT_Vent12Fault,AC3CT_Vent21Fault,AC3CT_Vent22Fault,AC3CT_Compressor11Fault,
    AC3CT_Compressor12Fault,AC3CT_Compressor21Fault,AC3CT_Compressor22Fault,AC3CT_Conden11Fault,AC3CT_Conden12Fault,AC3CT_Conden21Fault,
    AC3CT_Conden22Fault,AC3CT_PreHeater11Fault,AC3CT_PreHeater12Fault,AC3CT_PreHeater21Fault,AC3CT_PreHeater22Fault,AC3CT_FreshAir11Fault,
    AC3CT_FreshAir12Fault,AC3CT_ReAir11Fault,AC3CT_FreshAir21Fault,AC3CT_FreshAir22Fault,AC3CT_ReAir21Fault,AC3CT_Cleaner11Fault,
    AC3CT_Cleaner21Fault,AC3CT_EleHeating11Fault,AC3CT_EleHeating12Fault,AC3CT_EmcVent1Sta,AC3CT_EmcVent2Sta,AC3CT_EmcVentInvFault,
    AC3CT_EmcVent1Fault,AC3CT_EmcVent2Fault;

    //0x940
    unsigned short int AC4CT_Lifesignal;
    unsigned char AC4CT_SWVersion1,AC4CT_SWVersion2,AC4CT_Mode,AC4CT_TempInside,AC4CT_TempOutside,AC4CT_TargetTemp;
    bool AC4CT_WorkingStste,AC4CT_LoadDecState,AC4CT_HeaterCenCon,AC4CT_Vent11State,AC4CT_Vent12State,AC4CT_Vent21State,
    AC4CT_Vent22State,AC4CT_Compressor11State,AC4CT_Compressor12State,AC4CT_Compressor21State,AC4CT_Compressor22State,AC4CT_Conden11State,
    AC4CT_Conden12State,AC4CT_Conden21State,AC4CT_Conden22State,AC4CT_PreHeater11State,AC4CT_PreHeater12State,AC4CT_PreHeater21State,
    AC4CT_PreHeater22State,AC4CT_Vent11Fault,AC4CT_Vent12Fault,AC4CT_Vent21Fault,AC4CT_Vent22Fault,AC4CT_Compressor11Fault,
    AC4CT_Compressor12Fault,AC4CT_Compressor21Fault,AC4CT_Compressor22Fault,AC4CT_Conden11Fault,AC4CT_Conden12Fault,AC4CT_Conden21Fault,
    AC4CT_Conden22Fault,AC4CT_PreHeater11Fault,AC4CT_PreHeater12Fault,AC4CT_PreHeater21Fault,AC4CT_PreHeater22Fault,AC4CT_FreshAir11Fault,
    AC4CT_FreshAir12Fault,AC4CT_ReAir11Fault,AC4CT_FreshAir21Fault,AC4CT_FreshAir22Fault,AC4CT_ReAir21Fault,AC4CT_Cleaner11Fault,
    AC4CT_Cleaner21Fault,AC4CT_EleHeating11Fault,AC4CT_EleHeating12Fault,AC4CT_EmcVent1Sta,AC4CT_EmcVent2Sta,AC4CT_EmcVentInvFault,
    AC4CT_EmcVent1Fault,AC4CT_EmcVent2Fault;

    //0x950
    unsigned short int AC5CT_Lifesignal;
    unsigned char AC5CT_SWVersion1,AC5CT_SWVersion2,AC5CT_Mode,AC5CT_TempInside,AC5CT_TempOutside,AC5CT_TargetTemp;
    bool AC5CT_WorkingStste,AC5CT_LoadDecState,AC5CT_HeaterCenCon,AC5CT_Vent11State,AC5CT_Vent12State,AC5CT_Vent21State,
    AC5CT_Vent22State,AC5CT_Compressor11State,AC5CT_Compressor12State,AC5CT_Compressor21State,AC5CT_Compressor22State,AC5CT_Conden11State,
    AC5CT_Conden12State,AC5CT_Conden21State,AC5CT_Conden22State,AC5CT_PreHeater11State,AC5CT_PreHeater12State,AC5CT_PreHeater21State,
    AC5CT_PreHeater22State,AC5CT_Vent11Fault,AC5CT_Vent12Fault,AC5CT_Vent21Fault,AC5CT_Vent22Fault,AC5CT_Compressor11Fault,
    AC5CT_Compressor12Fault,AC5CT_Compressor21Fault,AC5CT_Compressor22Fault,AC5CT_Conden11Fault,AC5CT_Conden12Fault,AC5CT_Conden21Fault,
    AC5CT_Conden22Fault,AC5CT_PreHeater11Fault,AC5CT_PreHeater12Fault,AC5CT_PreHeater21Fault,AC5CT_PreHeater22Fault,AC5CT_FreshAir11Fault,
    AC5CT_FreshAir12Fault,AC5CT_ReAir11Fault,AC5CT_FreshAir21Fault,AC5CT_FreshAir22Fault,AC5CT_ReAir21Fault,AC5CT_Cleaner11Fault,
    AC5CT_Cleaner21Fault,AC5CT_EleHeating11Fault,AC5CT_EleHeating12Fault,AC5CT_EmcVent1Sta,AC5CT_EmcVent2Sta,AC5CT_EmcVentInvFault,
    AC5CT_EmcVent1Fault,AC5CT_EmcVent2Fault;

    //0x960
    unsigned short int AC6CT_Lifesignal;
    unsigned char AC6CT_SWVersion1,AC6CT_SWVersion2,AC6CT_Mode,AC6CT_TempInside,AC6CT_TempOutside,AC6CT_TargetTemp;
    bool AC6CT_WorkingStste,AC6CT_LoadDecState,AC6CT_HeaterCenCon,AC6CT_Vent11State,AC6CT_Vent12State,AC6CT_Vent21State,
    AC6CT_Vent22State,AC6CT_Compressor11State,AC6CT_Compressor12State,AC6CT_Compressor21State,AC6CT_Compressor22State,AC6CT_Conden11State,
    AC6CT_Conden12State,AC6CT_Conden21State,AC6CT_Conden22State,AC6CT_PreHeater11State,AC6CT_PreHeater12State,AC6CT_PreHeater21State,
    AC6CT_PreHeater22State,AC6CT_Vent11Fault,AC6CT_Vent12Fault,AC6CT_Vent21Fault,AC6CT_Vent22Fault,AC6CT_Compressor11Fault,
    AC6CT_Compressor12Fault,AC6CT_Compressor21Fault,AC6CT_Compressor22Fault,AC6CT_Conden11Fault,AC6CT_Conden12Fault,AC6CT_Conden21Fault,
    AC6CT_Conden22Fault,AC6CT_PreHeater11Fault,AC6CT_PreHeater12Fault,AC6CT_PreHeater21Fault,AC6CT_PreHeater22Fault,AC6CT_FreshAir11Fault,
    AC6CT_FreshAir12Fault,AC6CT_ReAir11Fault,AC6CT_FreshAir21Fault,AC6CT_FreshAir22Fault,AC6CT_ReAir21Fault,AC6CT_Cleaner11Fault,
    AC6CT_Cleaner21Fault,AC6CT_EleHeating11Fault,AC6CT_EleHeating12Fault,AC6CT_EmcVent1Sta,AC6CT_EmcVent2Sta,AC6CT_EmcVentInvFault,
    AC6CT_EmcVent1Fault,AC6CT_EmcVent2Fault;

    //0xA10,0xA20,0xA08,0xC10,0xC20,0xC08,0xD18,0xD28
    unsigned short int AT1CT_LfSign,AT2CT_LfSign;
    unsigned char AT1CT_Test;
    unsigned short int PDS1CT_LfSign,PDS2CT_LfSign;
    unsigned char CTPDS_Function;
    bool CTBC1_TrainRunning,CTBC1_FaultReset,CTBC1_BCGCut;

    //0xD10
    unsigned char BC1CT_SwVersion,BC1CT_BatteryTemp;
    bool BC1CT_BatteryTempFlt,BC1CT_DC24VOutputFlt,BC1CT_DC110VOutputOverFlt,BC1CT_DC110VOutputShortFlt,BC1CT_RecOverLoadFlt,BC1CT_InputOverCurFlt,
    BC1CT_InputOverVolFlt,BC1CT_InputLowVolFlt,BC1CT_RadOverTempFlt,BC1CT_DC24VInputFuseFlt,BC1CT_DC24VModuleFlt,BC1CT_DC24VOutputRunSig,
    BC1CT_DC110VOutputFuseFlt,BC1CT_WholeInputFuseFlt;
    unsigned short int BC1CT_BatteryVoltage,BC1CT_BatteryCurrent,BC1CT_NetVoltage,BC1CT_CapacityVoltage,BC1CT_NetCurrent,BC1CT_LifeSignal;


    //0xD20
    unsigned char BC2CT_SwVersion,BC2CT_BatteryTemp;
    bool BC2CT_BatteryTempFlt,BC2CT_DC24VOutputFlt,BC2CT_DC110VOutputOverFlt,BC2CT_DC110VOutputShortFlt,BC2CT_RecOverLoadFlt,BC2CT_InputOverCurFlt,
    BC2CT_InputOverVolFlt,BC2CT_InputLowVolFlt,BC2CT_RadOverTempFlt,BC2CT_DC24VInputFuseFlt,BC2CT_DC24VModuleFlt,BC2CT_DC24VOutputRunSig,
    BC2CT_DC110VOutputFuseFlt,BC2CT_WholeInputFuseFlt;
    unsigned short int BC2CT_BatteryVoltage,BC2CT_BatteryCurrent,BC2CT_NetVoltage,BC2CT_CapacityVoltage,BC2CT_NetCurrent,BC2CT_LifeSignal;

    //0xE10
    unsigned char BM1CT_OverVolBattNum,BM1CT_LowVolBattNum,BM1CT_OverTempBattNum,BM1CT_OverResBattNum,BM1CT_OverVolAlarmBatt1,BM1CT_OverVolAlarmBatt2;
    unsigned short int BM1CT_OverVolAlarmBatt1Val,BM1CT_OverVolAlarmBatt2Val;
    unsigned char BM1CT_LowVolAlarmBatt1,BM1CT_LowVolAlarmBatt2;
    unsigned short int BM1CT_LowVolAlarmBatt1Val,BM1CT_LowVolAlarmBatt2Val;
    unsigned char BM1CT_OverTempAlarmBatt1,BM1CT_OverTempAlarmBatt2;
    unsigned short int BM1CT_OverTempAlarmBatt1Val,BM1CT_OverTempAlarmBatt2Val;
    unsigned char BM1CT_OverResAlarmBatt1,BM1CT_OverResAlarmBatt2;
    unsigned short int BM1CT_OverResAlarmBatt1Val,BM1CT_OverResAlarmBatt2Val;
    bool BM1CT_OnlyOverVolAlarm,BM1CT_OnlyLowVolAlarm,BM1CT_TempAlarm,BM1CT_ResAlarm,BM1CT_WholeLowVolAlarm,BM1CT_InsetOverTempAlarm,
    BM1CT_OverChargeCurAlarm;
    unsigned short int BM1CT_SoftVersion;

    //0xE11
    unsigned char BM1CT_LifeSignal,BM1CT_AlarmLampSta;
    unsigned short int BM1CT_ChargeVolVal,BM1CT_DischargeVolVal,BM1CT_InsetTempVal,BM1CT_ChargeCurVal,BM1CT_DischargeCurVal;

    //0xE20
    unsigned char BM2CT_OverVolBattNum,BM2CT_LowVolBattNum,BM2CT_OverTempBattNum,BM2CT_OverResBattNum,BM2CT_OverVolAlarmBatt1,BM2CT_OverVolAlarmBatt2;
    unsigned short int BM2CT_OverVolAlarmBatt1Val,BM2CT_OverVolAlarmBatt2Val;
    unsigned char BM2CT_LowVolAlarmBatt1,BM2CT_LowVolAlarmBatt2;
    unsigned short int BM2CT_LowVolAlarmBatt1Val,BM2CT_LowVolAlarmBatt2Val;
    unsigned char BM2CT_OverTempAlarmBatt1,BM2CT_OverTempAlarmBatt2;
    unsigned short int BM2CT_OverTempAlarmBatt1Val,BM2CT_OverTempAlarmBatt2Val;
    unsigned char BM2CT_OverResAlarmBatt1,BM2CT_OverResAlarmBatt2;
    unsigned short int BM2CT_OverResAlarmBatt1Val,BM2CT_OverResAlarmBatt2Val;
    bool BM2CT_OnlyOverVolAlarm,BM2CT_OnlyLowVolAlarm,BM2CT_TempAlarm,BM2CT_ResAlarm,BM2CT_WholeLowVolAlarm,BM2CT_InsetOverTempAlarm,
    BM2CT_OverChargeCurAlarm;
    unsigned short int BM2CT_SoftVersion;

    //0xE21
    unsigned char BM2CT_LifeSignal,BM2CT_AlarmLampSta;
    unsigned short int BM2CT_ChargeVolVal,BM2CT_DischargeVolVal,BM2CT_InsetTempVal,BM2CT_ChargeCurVal,BM2CT_DischargeCurVal;

    //0xF10
    unsigned char FA1CT_Lifesignal;
    bool FA1CT_FAComFault,FA1CT_TrainExtended;
    unsigned char FA1CT_SWHighByte,FA1CT_SWLowByte;
    bool FA1CT_Det11FireAlert,FA1CT_Det11ComFault,FA1CT_Det11FanFault,FA1CT_Det11Polluted,FA1CT_Det12FireAlert,FA1CT_Det12ComFault,
    FA1CT_Det12FanFault,FA1CT_Det12Polluted,FA1CT_Det13FireAlert,FA1CT_Det13ComFault,FA1CT_Det13FanFault,FA1CT_Det13Polluted,
    FA1CT_Det14FireAlert,FA1CT_Det14ComFault,FA1CT_Det14FanFault,FA1CT_Det14Polluted,FA1CT_Det15FireAlert,FA1CT_Det15ComFault,
    FA1CT_Det15FanFault,FA1CT_Det15Polluted,FA1CT_Det16FireAlert,FA1CT_Det16ComFault,FA1CT_Det16FanFault,FA1CT_Det16Polluted,
    FA1CT_Det17FireAlert,FA1CT_Det17ComFault,FA1CT_Det17FanFault,FA1CT_Det17Polluted,FA1CT_Det21FireAlert,FA1CT_Det21ComFault,
    FA1CT_Det21FanFault,FA1CT_Det21Polluted,FA1CT_Det22FireAlert,FA1CT_Det22ComFault,FA1CT_Det22FanFault,FA1CT_Det22Polluted,
    FA1CT_Det23FireAlert,FA1CT_Det23ComFault,FA1CT_Det23FanFault,FA1CT_Det23Polluted,FA1CT_Det24FireAlert,FA1CT_Det24ComFault,
    FA1CT_Det24FanFault,FA1CT_Det24Polluted,FA1CT_Det31FireAlert,FA1CT_Det31ComFault,FA1CT_Det31FanFault,FA1CT_Det31Polluted,
    FA1CT_Det32FireAlert,FA1CT_Det32ComFault,FA1CT_Det32FanFault,FA1CT_Det32Polluted,FA1CT_Det33FireAlert,FA1CT_Det33ComFault,
    FA1CT_Det33FanFault,FA1CT_Det33Polluted,FA1CT_Det34FireAlert,FA1CT_Det34ComFault,FA1CT_Det34FanFault,FA1CT_Det34Polluted,
    FA1CT_Det41FireAlert,FA1CT_Det41ComFault,FA1CT_Det41FanFault,FA1CT_Det41Polluted,FA1CT_Det42FireAlert,FA1CT_Det42ComFault,
    FA1CT_Det42FanFault,FA1CT_Det42Polluted,FA1CT_Det43FireAlert,FA1CT_Det43ComFault,FA1CT_Det43FanFault,FA1CT_Det43Polluted,
    FA1CT_Det44FireAlert,FA1CT_Det44ComFault,FA1CT_Det44FanFault,FA1CT_Det44Polluted,FA1CT_Det51FireAlert,FA1CT_Det51ComFault,
    FA1CT_Det51FanFault,FA1CT_Det51Polluted,FA1CT_Det52FireAlert,FA1CT_Det52ComFault,FA1CT_Det52FanFault,FA1CT_Det52Polluted,
    FA1CT_Det53FireAlert,FA1CT_Det53ComFault,FA1CT_Det53FanFault,FA1CT_Det53Polluted,FA1CT_Det54FireAlert,FA1CT_Det54ComFault,
    FA1CT_Det54FanFault,FA1CT_Det54Polluted,FA1CT_Det61FireAlert,FA1CT_Det61ComFault,FA1CT_Det61FanFault,FA1CT_Det61Polluted,
    FA1CT_Det62FireAlert,FA1CT_Det62ComFault,FA1CT_Det62FanFault,FA1CT_Det62Polluted,FA1CT_Det63FireAlert,FA1CT_Det63ComFault,
    FA1CT_Det63FanFault,FA1CT_Det63Polluted,FA1CT_Det64FireAlert,FA1CT_Det64ComFault,FA1CT_Det64FanFault,FA1CT_Det64Polluted,
    FA1CT_Det65FireAlert,FA1CT_Det65ComFault,FA1CT_Det65FanFault,FA1CT_Det65Polluted,FA1CT_Det66FireAlert,FA1CT_Det66ComFault,
    FA1CT_Det66FanFault,FA1CT_Det66Polluted,FA1CT_Det67FireAlert,FA1CT_Det67ComFault,FA1CT_Det67FanFault,FA1CT_Det67Polluted;

    //0xF20
    unsigned char FA2CT_Lifesignal;
    bool FA2CT_FAComFault,FA2CT_TrainExtended;
    unsigned char FA2CT_SWHighByte,FA2CT_SWLowByte;
    bool FA2CT_Det11FireAlert,FA2CT_Det11ComFault,FA2CT_Det11FanFault,FA2CT_Det11Polluted,FA2CT_Det12FireAlert,FA2CT_Det12ComFault,
    FA2CT_Det12FanFault,FA2CT_Det12Polluted,FA2CT_Det13FireAlert,FA2CT_Det13ComFault,FA2CT_Det13FanFault,FA2CT_Det13Polluted,
    FA2CT_Det14FireAlert,FA2CT_Det14ComFault,FA2CT_Det14FanFault,FA2CT_Det14Polluted,FA2CT_Det15FireAlert,FA2CT_Det15ComFault,
    FA2CT_Det15FanFault,FA2CT_Det15Polluted,FA2CT_Det16FireAlert,FA2CT_Det16ComFault,FA2CT_Det16FanFault,FA2CT_Det16Polluted,
    FA2CT_Det17FireAlert,FA2CT_Det17ComFault,FA2CT_Det17FanFault,FA2CT_Det17Polluted,FA2CT_Det21FireAlert,FA2CT_Det21ComFault,
    FA2CT_Det21FanFault,FA2CT_Det21Polluted,FA2CT_Det22FireAlert,FA2CT_Det22ComFault,FA2CT_Det22FanFault,FA2CT_Det22Polluted,
    FA2CT_Det23FireAlert,FA2CT_Det23ComFault,FA2CT_Det23FanFault,FA2CT_Det23Polluted,FA2CT_Det24FireAlert,FA2CT_Det24ComFault,
    FA2CT_Det24FanFault,FA2CT_Det24Polluted,FA2CT_Det31FireAlert,FA2CT_Det31ComFault,FA2CT_Det31FanFault,FA2CT_Det31Polluted,
    FA2CT_Det32FireAlert,FA2CT_Det32ComFault,FA2CT_Det32FanFault,FA2CT_Det32Polluted,FA2CT_Det33FireAlert,FA2CT_Det33ComFault,
    FA2CT_Det33FanFault,FA2CT_Det33Polluted,FA2CT_Det34FireAlert,FA2CT_Det34ComFault,FA2CT_Det34FanFault,FA2CT_Det34Polluted,
    FA2CT_Det41FireAlert,FA2CT_Det41ComFault,FA2CT_Det41FanFault,FA2CT_Det41Polluted,FA2CT_Det42FireAlert,FA2CT_Det42ComFault,
    FA2CT_Det42FanFault,FA2CT_Det42Polluted,FA2CT_Det43FireAlert,FA2CT_Det43ComFault,FA2CT_Det43FanFault,FA2CT_Det43Polluted,
    FA2CT_Det44FireAlert,FA2CT_Det44ComFault,FA2CT_Det44FanFault,FA2CT_Det44Polluted,FA2CT_Det51FireAlert,FA2CT_Det51ComFault,
    FA2CT_Det51FanFault,FA2CT_Det51Polluted,FA2CT_Det52FireAlert,FA2CT_Det52ComFault,FA2CT_Det52FanFault,FA2CT_Det52Polluted,
    FA2CT_Det53FireAlert,FA2CT_Det53ComFault,FA2CT_Det53FanFault,FA2CT_Det53Polluted,FA2CT_Det54FireAlert,FA2CT_Det54ComFault,
    FA2CT_Det54FanFault,FA2CT_Det54Polluted,FA2CT_Det61FireAlert,FA2CT_Det61ComFault,FA2CT_Det61FanFault,FA2CT_Det61Polluted,
    FA2CT_Det62FireAlert,FA2CT_Det62ComFault,FA2CT_Det62FanFault,FA2CT_Det62Polluted,FA2CT_Det63FireAlert,FA2CT_Det63ComFault,
    FA2CT_Det63FanFault,FA2CT_Det63Polluted,FA2CT_Det64FireAlert,FA2CT_Det64ComFault,FA2CT_Det64FanFault,FA2CT_Det64Polluted,
    FA2CT_Det65FireAlert,FA2CT_Det65ComFault,FA2CT_Det65FanFault,FA2CT_Det65Polluted,FA2CT_Det66FireAlert,FA2CT_Det66ComFault,
    FA2CT_Det66FanFault,FA2CT_Det66Polluted,FA2CT_Det67FireAlert,FA2CT_Det67ComFault,FA2CT_Det67FanFault,FA2CT_Det67Polluted;

    //0xF08
    bool CTFA_Silence,CTFA_Reset;
    //0x918
    unsigned short int CTAC1_Mode,CTAC1_TargetTemp;
    bool CTAC1_StartAllowance,CTAC1_LoadDec,CTAC1_HeaterCenCont,CTAC1_SpdMode;
    unsigned short int CTAC1_PassengerLoad,CTAC1_NewWindMode;
    //0x928
    unsigned short int CTAC2_Mode,CTAC2_TargetTemp;
    bool CTAC2_StartAllowance,CTAC2_LoadDec,CTAC2_HeaterCenCont,CTAC2_SpdMode;
    unsigned short int CTAC2_PassengerLoad,CTAC2_NewWindMode;

    //0x938
    unsigned short int CTAC3_Mode,CTAC3_TargetTemp;
    bool CTAC3_StartAllowance,CTAC3_LoadDec,CTAC3_HeaterCenCont,CTAC3_SpdMode;
    unsigned short int CTAC3_PassengerLoad,CTAC3_NewWindMode;

    //0x948
    unsigned short int CTAC4_Mode,CTAC4_TargetTemp;
    bool CTAC4_StartAllowance,CTAC4_LoadDec,CTAC4_HeaterCenCont,CTAC4_SpdMode;
    unsigned short int CTAC4_PassengerLoad,CTAC4_NewWindMode;

    //0x958
    unsigned short int CTAC5_Mode,CTAC5_TargetTemp;
    bool CTAC5_StartAllowance,CTAC5_LoadDec,CTAC5_HeaterCenCont,CTAC5_SpdMode;
    unsigned short int CTAC5_PassengerLoad,CTAC5_NewWindMode;

    //0x968
    unsigned short int CTAC6_Mode,CTAC6_TargetTemp;
    bool CTAC6_StartAllowance,CTAC6_LoadDec,CTAC6_HeaterCenCont,CTAC6_SpdMode;
    unsigned short int CTAC6_PassengerLoad,CTAC6_NewWindMode;


    //0x710

    //reservation
    //DI
    bool RIOM1_DIM1Ch9,RIOM1_DIM1Ch10,RIOM1_DIM1Ch21,RIOM1_DIM1Ch22,RIOM1_DIM1Ch23,RIOM1_DIM1Ch24,
         RIOM6_DIM1Ch9,RIOM6_DIM1Ch10,RIOM6_DIM1Ch21,RIOM6_DIM1Ch22,RIOM6_DIM1Ch23,RIOM6_DIM1Ch24,
         RIOM1_DIM2Ch9,RIOM1_DIM2Ch10,RIOM1_DIM2Ch24,
         RIOM6_DIM2Ch9,RIOM6_DIM2Ch10,RIOM6_DIM2Ch24,
         RIOM1_DIM3Ch10,RIOM1_DIM3Ch17,RIOM1_DIM3Ch20,RIOM1_DIM3Ch21,RIOM1_DIM3Ch22,RIOM1_DIM3Ch23,RIOM1_DIM3Ch24,
         RIOM6_DIM3Ch10,RIOM6_DIM3Ch17,RIOM6_DIM3Ch20,RIOM6_DIM3Ch21,RIOM6_DIM3Ch22,RIOM6_DIM3Ch23,RIOM6_DIM3Ch24,
         RIOM1_DIM4Ch24,
         RIOM6_DIM4Ch24,
         RIOM2_DIM1Ch10,RIOM2_DIM1Ch11,RIOM2_DIM1Ch12,RIOM2_DIM1Ch19,RIOM2_DIM1Ch22,RIOM2_DIM1Ch23,RIOM2_DIM1Ch24,
         RIOM5_DIM1Ch10,RIOM5_DIM1Ch11,RIOM5_DIM1Ch12,RIOM5_DIM1Ch19,RIOM5_DIM1Ch22,RIOM5_DIM1Ch23,RIOM5_DIM1Ch24,
         RIOM3_DIM1Ch10,RIOM3_DIM1Ch11,RIOM3_DIM1Ch12,RIOM3_DIM1Ch18,RIOM3_DIM1Ch19,RIOM3_DIM1Ch22,RIOM3_DIM1Ch23,RIOM3_DIM1Ch24,
         RIOM4_DIM1Ch10,RIOM4_DIM1Ch11,RIOM4_DIM1Ch12,RIOM4_DIM1Ch18,RIOM4_DIM1Ch19,RIOM4_DIM1Ch22,RIOM4_DIM1Ch23,RIOM4_DIM1Ch24;

    //DO
   bool RIOM1_DOMIC4, RIOM1_DOMIC5, RIOM1_DOMIC6, RIOM1_DOMIC7, RIOM1_DOMIC8, RIOM1_DOMIC9,
        RIOM1_DOMIC10, RIOM1_DOMIC11, RIOM1_DOMIC12, RIOM1_DOMIC13, RIOM1_DOMIC14, RIOM1_DOMIC15, RIOM1_DOMIC16,
        RIOM6_DOMIC4, RIOM6_DOMIC5, RIOM6_DOMIC6, RIOM6_DOMIC7, RIOM6_DOMIC8, RIOM6_DOMIC9,
        RIOM6_DOMIC10, RIOM6_DOMIC11, RIOM6_DOMIC12, RIOM6_DOMIC13, RIOM6_DOMIC14, RIOM6_DOMIC15, RIOM6_DOMIC16,
        RIOM2_DOMIC1,RIOM2_DOMIC2, RIOM2_DOMIC3, RIOM2_DOMIC4, RIOM2_DOMIC5, RIOM2_DOMIC6, RIOM2_DOMIC7, RIOM2_DOMIC8, RIOM2_DOMIC9,
        RIOM2_DOMIC10, RIOM2_DOMIC11, RIOM2_DOMIC12, RIOM2_DOMIC13, RIOM2_DOMIC14, RIOM2_DOMIC15, RIOM2_DOMIC16,
        RIOM5_DOMIC1,RIOM5_DOMIC2, RIOM5_DOMIC3, RIOM5_DOMIC4, RIOM5_DOMIC5, RIOM5_DOMIC6, RIOM5_DOMIC7, RIOM5_DOMIC8, RIOM5_DOMIC9,
        RIOM5_DOMIC10, RIOM5_DOMIC11, RIOM5_DOMIC12, RIOM5_DOMIC13, RIOM5_DOMIC14, RIOM5_DOMIC15, RIOM5_DOMIC16,
        RIOM3_DOMIC2, RIOM3_DOMIC3, RIOM3_DOMIC4, RIOM3_DOMIC5, RIOM3_DOMIC6, RIOM3_DOMIC7, RIOM3_DOMIC8, RIOM3_DOMIC9,
        RIOM3_DOMIC10, RIOM3_DOMIC11, RIOM3_DOMIC12, RIOM3_DOMIC13, RIOM3_DOMIC14, RIOM3_DOMIC15, RIOM3_DOMIC16,
        RIOM4_DOMIC2, RIOM4_DOMIC3, RIOM4_DOMIC4, RIOM4_DOMIC5, RIOM4_DOMIC6, RIOM4_DOMIC7, RIOM4_DOMIC8, RIOM4_DOMIC9,
        RIOM4_DOMIC10, RIOM4_DOMIC11, RIOM4_DOMIC12, RIOM4_DOMIC13, RIOM4_DOMIC14, RIOM4_DOMIC15, RIOM4_DOMIC16;


    //EDCU
    //0x710, 0x711, 0x712
   bool DR1CT_Dr1MotoLineBrk,DR1CT_Dr1ClockedInvalid,DR1CT_Dr1ClosedInvalid,DR1CT_Dr1NotUnlockIn3s,
   DR1CT_Dr1PSensorInvalid,DR1CT_Dr1OutClockedPnotAllowed,DR1CT_Dr1SafeRelayFlt,DR1CT_Dr1InterlockFlt,
   DR1CT_Dr1ClockFlt,DR1CT_Dr1CHinderNum,DR1CT_Dr1OHinderNum,DR1CT_Dr1O0OutShort,
   DR1CT_Dr1O1OutShort,DR1CT_Dr1O2OutShort,DR1CT_Dr1O3OutShort,DR1CT_Dr1RomFlt,
   DR1CT_Dr1ComFlt,DR1CT_Dr1AddCodeFlt,DR1CT_Dr1MaintainBtnFlt;

   bool DR1CT_Dr2MotoLineBrk,DR1CT_Dr2ClockedInvalid,DR1CT_Dr2ClosedInvalid,DR1CT_Dr2NotUnlockIn3s,
   DR1CT_Dr2PSensorInvalid,DR1CT_Dr2OutClockedPnotAllowed,DR1CT_Dr2SafeRelayFlt,DR1CT_Dr2InterlockFlt,
   DR1CT_Dr2ClockFlt,DR1CT_Dr2CHinderNum,DR1CT_Dr2OHinderNum,DR1CT_Dr2O0OutShort,
   DR1CT_Dr2O1OutShort,DR1CT_Dr2O2OutShort,DR1CT_Dr2O3OutShort,DR1CT_Dr2RomFlt,
   DR1CT_Dr2ComFlt,DR1CT_Dr2AddCodeFlt,DR1CT_Dr2MaintainBtnFlt;

   bool DR1CT_Dr3MotoLineBrk,DR1CT_Dr3ClockedInvalid,DR1CT_Dr3ClosedInvalid,DR1CT_Dr3NotUnlockIn3s,
   DR1CT_Dr3PSensorInvalid,DR1CT_Dr3OutClockedPnotAllowed,DR1CT_Dr3SafeRelayFlt,DR1CT_Dr3InterlockFlt,
   DR1CT_Dr3ClockFlt,DR1CT_Dr3CHinderNum,DR1CT_Dr3OHinderNum,DR1CT_Dr3O0OutShort,
   DR1CT_Dr3O1OutShort,DR1CT_Dr3O2OutShort,DR1CT_Dr3O3OutShort,DR1CT_Dr3RomFlt,
   DR1CT_Dr3ComFlt,DR1CT_Dr3AddCodeFlt,DR1CT_Dr3MaintainBtnFlt;

   bool DR1CT_Dr4MotoLineBrk,DR1CT_Dr4ClockedInvalid,DR1CT_Dr4ClosedInvalid,DR1CT_Dr4NotUnlockIn3s,
   DR1CT_Dr4PSensorInvalid,DR1CT_Dr4OutClockedPnotAllowed,DR1CT_Dr4SafeRelayFlt,DR1CT_Dr4InterlockFlt,
   DR1CT_Dr4ClockFlt,DR1CT_Dr4CHinderNum,DR1CT_Dr4OHinderNum,DR1CT_Dr4O0OutShort,
   DR1CT_Dr4O1OutShort,DR1CT_Dr4O2OutShort,DR1CT_Dr4O3OutShort,DR1CT_Dr4RomFlt,
   DR1CT_Dr4ComFlt,DR1CT_Dr4AddCodeFlt,DR1CT_Dr4MaintainBtnFlt;

   bool DR1CT_Dr5MotoLineBrk,DR1CT_Dr5ClockedInvalid,DR1CT_Dr5ClosedInvalid,DR1CT_Dr5NotUnlockIn3s,
   DR1CT_Dr5PSensorInvalid,DR1CT_Dr5OutClockedPnotAllowed,DR1CT_Dr5SafeRelayFlt,DR1CT_Dr5InterlockFlt,
   DR1CT_Dr5ClockFlt,DR1CT_Dr5CHinderNum,DR1CT_Dr5OHinderNum,DR1CT_Dr5O0OutShort,
   DR1CT_Dr5O1OutShort,DR1CT_Dr5O2OutShort,DR1CT_Dr5O3OutShort,DR1CT_Dr5RomFlt,
   DR1CT_Dr5ComFlt,DR1CT_Dr5AddCodeFlt,DR1CT_Dr5MaintainBtnFlt;

   bool DR1CT_Dr6MotoLineBrk,DR1CT_Dr6ClockedInvalid,DR1CT_Dr6ClosedInvalid,DR1CT_Dr6NotUnlockIn3s,
   DR1CT_Dr6PSensorInvalid,DR1CT_Dr6OutClockedPnotAllowed,DR1CT_Dr6SafeRelayFlt,DR1CT_Dr6InterlockFlt,
   DR1CT_Dr6ClockFlt,DR1CT_Dr6CHinderNum,DR1CT_Dr6OHinderNum,DR1CT_Dr6O0OutShort,
   DR1CT_Dr6O1OutShort,DR1CT_Dr6O2OutShort,DR1CT_Dr6O3OutShort,DR1CT_Dr6RomFlt,
   DR1CT_Dr6ComFlt,DR1CT_Dr6AddCodeFlt,DR1CT_Dr6MaintainBtnFlt;

   bool DR1CT_Dr7MotoLineBrk,DR1CT_Dr7ClockedInvalid,DR1CT_Dr7ClosedInvalid,DR1CT_Dr7NotUnlockIn3s,
   DR1CT_Dr7PSensorInvalid,DR1CT_Dr7OutClockedPnotAllowed,DR1CT_Dr7SafeRelayFlt,DR1CT_Dr7InterlockFlt,
   DR1CT_Dr7ClockFlt,DR1CT_Dr7CHinderNum,DR1CT_Dr7OHinderNum,DR1CT_Dr7O0OutShort,
   DR1CT_Dr7O1OutShort,DR1CT_Dr7O2OutShort,DR1CT_Dr7O3OutShort,DR1CT_Dr7RomFlt,
   DR1CT_Dr7ComFlt,DR1CT_Dr7AddCodeFlt,DR1CT_Dr7MaintainBtnFlt;

   bool DR1CT_Dr8MotoLineBrk,DR1CT_Dr8ClockedInvalid,DR1CT_Dr8ClosedInvalid,DR1CT_Dr8NotUnlockIn3s,
   DR1CT_Dr8PSensorInvalid,DR1CT_Dr8OutClockedPnotAllowed,DR1CT_Dr8SafeRelayFlt,DR1CT_Dr8InterlockFlt,
   DR1CT_Dr8ClockFlt,DR1CT_Dr8CHinderNum,DR1CT_Dr8OHinderNum,DR1CT_Dr8O0OutShort,
   DR1CT_Dr8O1OutShort,DR1CT_Dr8O2OutShort,DR1CT_Dr8O3OutShort,DR1CT_Dr8RomFlt,
   DR1CT_Dr8ComFlt,DR1CT_Dr8AddCodeFlt,DR1CT_Dr8MaintainBtnFlt;

   bool DR1CT_Dr1EnableFB,DR1CT_Dr1ZeroSpFB,DR1CT_Dr1OpenFB,DR1CT_Dr1NotOandCFB,
   DR1CT_Dr1CloseFB,DR1CT_Dr1OpenHinder,DR1CT_Dr1Safe1FB,DR1CT_Dr1Safe2FB,
   DR1CT_Dr1Closed,DR1CT_Dr1Opened,DR1CT_Dr1EMCunclock,DR1CT_Dr1Cut,
   DR1CT_Dr1CloseHinder,DR1CT_Dr1ReSwitchLineFB,DR1CT_Dr1SeriousFlt,DR1CT_Dr1SlightFlt;

   bool DR1CT_Dr2EnableFB,DR1CT_Dr2ZeroSpFB,DR1CT_Dr2OpenFB,DR1CT_Dr2NotOandCFB,
   DR1CT_Dr2CloseFB,DR1CT_Dr2OpenHinder,DR1CT_Dr2Safe1FB,DR1CT_Dr2Safe2FB,
   DR1CT_Dr2Closed,DR1CT_Dr2Opened,DR1CT_Dr2EMCunclock,DR1CT_Dr2Cut,
   DR1CT_Dr2CloseHinder,DR1CT_Dr2ReSwitchLineFB,DR1CT_Dr2SeriousFlt,DR1CT_Dr2SlightFlt;

   bool DR1CT_Dr3EnableFB,DR1CT_Dr3ZeroSpFB,DR1CT_Dr3OpenFB,DR1CT_Dr3NotOandCFB,
   DR1CT_Dr3CloseFB,DR1CT_Dr3OpenHinder,DR1CT_Dr3Safe1FB,DR1CT_Dr3Safe2FB,
   DR1CT_Dr3Closed,DR1CT_Dr3Opened,DR1CT_Dr3EMCunclock,DR1CT_Dr3Cut,
   DR1CT_Dr3CloseHinder,DR1CT_Dr3ReSwitchLineFB,DR1CT_Dr3SeriousFlt,DR1CT_Dr3SlightFlt;

   bool DR1CT_Dr4EnableFB,DR1CT_Dr4ZeroSpFB,DR1CT_Dr4OpenFB,DR1CT_Dr4NotOandCFB,
   DR1CT_Dr4CloseFB,DR1CT_Dr4OpenHinder,DR1CT_Dr4Safe1FB,DR1CT_Dr4Safe2FB,
   DR1CT_Dr4Closed,DR1CT_Dr4Opened,DR1CT_Dr4EMCunclock,DR1CT_Dr4Cut,
   DR1CT_Dr4CloseHinder,DR1CT_Dr4ReSwitchLineFB,DR1CT_Dr4SeriousFlt,DR1CT_Dr4SlightFlt;

   bool DR1CT_Dr5EnableFB,DR1CT_Dr5ZeroSpFB,DR1CT_Dr5OpenFB,DR1CT_Dr5NotOandCFB,
   DR1CT_Dr5CloseFB,DR1CT_Dr5OpenHinder,DR1CT_Dr5Safe1FB,DR1CT_Dr5Safe2FB,
   DR1CT_Dr5Closed,DR1CT_Dr5Opened,DR1CT_Dr5EMCunclock,DR1CT_Dr5Cut,
   DR1CT_Dr5CloseHinder,DR1CT_Dr5ReSwitchLineFB,DR1CT_Dr5SeriousFlt,DR1CT_Dr5SlightFlt;

   bool DR1CT_Dr6EnableFB,DR1CT_Dr6ZeroSpFB,DR1CT_Dr6OpenFB,DR1CT_Dr6NotOandCFB,
   DR1CT_Dr6CloseFB,DR1CT_Dr6OpenHinder,DR1CT_Dr6Safe1FB,DR1CT_Dr6Safe2FB,
   DR1CT_Dr6Closed,DR1CT_Dr6Opened,DR1CT_Dr6EMCunclock,DR1CT_Dr6Cut,
   DR1CT_Dr6CloseHinder,DR1CT_Dr6ReSwitchLineFB,DR1CT_Dr6SeriousFlt,DR1CT_Dr6SlightFlt;

   bool DR1CT_Dr7EnableFB,DR1CT_Dr7ZeroSpFB,DR1CT_Dr7OpenFB,DR1CT_Dr7NotOandCFB,
   DR1CT_Dr7CloseFB,DR1CT_Dr7OpenHinder,DR1CT_Dr7Safe1FB,DR1CT_Dr7Safe2FB,
   DR1CT_Dr7Closed,DR1CT_Dr7Opened,DR1CT_Dr7EMCunclock,DR1CT_Dr7Cut,
   DR1CT_Dr7CloseHinder,DR1CT_Dr7ReSwitchLineFB,DR1CT_Dr7SeriousFlt,DR1CT_Dr7SlightFlt;

   bool DR1CT_Dr8EnableFB,DR1CT_Dr8ZeroSpFB,DR1CT_Dr8OpenFB,DR1CT_Dr8NotOandCFB,
   DR1CT_Dr8CloseFB,DR1CT_Dr8OpenHinder,DR1CT_Dr8Safe1FB,DR1CT_Dr8Safe2FB,
   DR1CT_Dr8Closed,DR1CT_Dr8Opened,DR1CT_Dr8EMCunclock,DR1CT_Dr8Cut,
   DR1CT_Dr8CloseHinder,DR1CT_Dr8ReSwitchLineFB,DR1CT_Dr8SeriousFlt,DR1CT_Dr8SlightFlt;

   unsigned short int DR1CT_OperationSt;
   bool DR1CT_MDCU1DataValid,DR1CT_MDCU2DataValid,DR1CT_MDCU3DataValid,DR1CT_MDCU4DataValid,
   DR1CT_MDCU5DataValid,DR1CT_MDCU6DataValid,DR1CT_MDCU7DataValid,DR1CT_MDCU8DataValid;

   unsigned short int DR1CT_BusToken,DR1CT_LifeSign;
   bool DR1CT_CANBreak;
   unsigned short int DR1CT_D1Version,DR1CT_D2Version,DR1CT_D3Version,DR1CT_D4Version,
   DR1CT_D5Version,DR1CT_D6Version,DR1CT_D7Version,DR1CT_D8Version;

   //0x720, 0x721, 0x722
   bool DR2CT_Dr1MotoLineBrk,DR2CT_Dr1ClockedInvalid,DR2CT_Dr1ClosedInvalid,DR2CT_Dr1NotUnlockIn3s,
   DR2CT_Dr1PSensorInvalid,DR2CT_Dr1OutClockedPnotAllowed,DR2CT_Dr1SafeRelayFlt,DR2CT_Dr1InterlockFlt,
   DR2CT_Dr1ClockFlt,DR2CT_Dr1CHinderNum,DR2CT_Dr1OHinderNum,DR2CT_Dr1O0OutShort,
   DR2CT_Dr1O1OutShort,DR2CT_Dr1O2OutShort,DR2CT_Dr1O3OutShort,DR2CT_Dr1RomFlt,
   DR2CT_Dr1ComFlt,DR2CT_Dr1AddCodeFlt,DR2CT_Dr1MaintainBtnFlt;

   bool DR2CT_Dr2MotoLineBrk,DR2CT_Dr2ClockedInvalid,DR2CT_Dr2ClosedInvalid,DR2CT_Dr2NotUnlockIn3s,
   DR2CT_Dr2PSensorInvalid,DR2CT_Dr2OutClockedPnotAllowed,DR2CT_Dr2SafeRelayFlt,DR2CT_Dr2InterlockFlt,
   DR2CT_Dr2ClockFlt,DR2CT_Dr2CHinderNum,DR2CT_Dr2OHinderNum,DR2CT_Dr2O0OutShort,
   DR2CT_Dr2O1OutShort,DR2CT_Dr2O2OutShort,DR2CT_Dr2O3OutShort,DR2CT_Dr2RomFlt,
   DR2CT_Dr2ComFlt,DR2CT_Dr2AddCodeFlt,DR2CT_Dr2MaintainBtnFlt;

   bool DR2CT_Dr3MotoLineBrk,DR2CT_Dr3ClockedInvalid,DR2CT_Dr3ClosedInvalid,DR2CT_Dr3NotUnlockIn3s,
   DR2CT_Dr3PSensorInvalid,DR2CT_Dr3OutClockedPnotAllowed,DR2CT_Dr3SafeRelayFlt,DR2CT_Dr3InterlockFlt,
   DR2CT_Dr3ClockFlt,DR2CT_Dr3CHinderNum,DR2CT_Dr3OHinderNum,DR2CT_Dr3O0OutShort,
   DR2CT_Dr3O1OutShort,DR2CT_Dr3O2OutShort,DR2CT_Dr3O3OutShort,DR2CT_Dr3RomFlt,
   DR2CT_Dr3ComFlt,DR2CT_Dr3AddCodeFlt,DR2CT_Dr3MaintainBtnFlt;

   bool DR2CT_Dr4MotoLineBrk,DR2CT_Dr4ClockedInvalid,DR2CT_Dr4ClosedInvalid,DR2CT_Dr4NotUnlockIn3s,
   DR2CT_Dr4PSensorInvalid,DR2CT_Dr4OutClockedPnotAllowed,DR2CT_Dr4SafeRelayFlt,DR2CT_Dr4InterlockFlt,
   DR2CT_Dr4ClockFlt,DR2CT_Dr4CHinderNum,DR2CT_Dr4OHinderNum,DR2CT_Dr4O0OutShort,
   DR2CT_Dr4O1OutShort,DR2CT_Dr4O2OutShort,DR2CT_Dr4O3OutShort,DR2CT_Dr4RomFlt,
   DR2CT_Dr4ComFlt,DR2CT_Dr4AddCodeFlt,DR2CT_Dr4MaintainBtnFlt;

   bool DR2CT_Dr5MotoLineBrk,DR2CT_Dr5ClockedInvalid,DR2CT_Dr5ClosedInvalid,DR2CT_Dr5NotUnlockIn3s,
   DR2CT_Dr5PSensorInvalid,DR2CT_Dr5OutClockedPnotAllowed,DR2CT_Dr5SafeRelayFlt,DR2CT_Dr5InterlockFlt,
   DR2CT_Dr5ClockFlt,DR2CT_Dr5CHinderNum,DR2CT_Dr5OHinderNum,DR2CT_Dr5O0OutShort,
   DR2CT_Dr5O1OutShort,DR2CT_Dr5O2OutShort,DR2CT_Dr5O3OutShort,DR2CT_Dr5RomFlt,
   DR2CT_Dr5ComFlt,DR2CT_Dr5AddCodeFlt,DR2CT_Dr5MaintainBtnFlt;

   bool DR2CT_Dr6MotoLineBrk,DR2CT_Dr6ClockedInvalid,DR2CT_Dr6ClosedInvalid,DR2CT_Dr6NotUnlockIn3s,
   DR2CT_Dr6PSensorInvalid,DR2CT_Dr6OutClockedPnotAllowed,DR2CT_Dr6SafeRelayFlt,DR2CT_Dr6InterlockFlt,
   DR2CT_Dr6ClockFlt,DR2CT_Dr6CHinderNum,DR2CT_Dr6OHinderNum,DR2CT_Dr6O0OutShort,
   DR2CT_Dr6O1OutShort,DR2CT_Dr6O2OutShort,DR2CT_Dr6O3OutShort,DR2CT_Dr6RomFlt,
   DR2CT_Dr6ComFlt,DR2CT_Dr6AddCodeFlt,DR2CT_Dr6MaintainBtnFlt;

   bool DR2CT_Dr7MotoLineBrk,DR2CT_Dr7ClockedInvalid,DR2CT_Dr7ClosedInvalid,DR2CT_Dr7NotUnlockIn3s,
   DR2CT_Dr7PSensorInvalid,DR2CT_Dr7OutClockedPnotAllowed,DR2CT_Dr7SafeRelayFlt,DR2CT_Dr7InterlockFlt,
   DR2CT_Dr7ClockFlt,DR2CT_Dr7CHinderNum,DR2CT_Dr7OHinderNum,DR2CT_Dr7O0OutShort,
   DR2CT_Dr7O1OutShort,DR2CT_Dr7O2OutShort,DR2CT_Dr7O3OutShort,DR2CT_Dr7RomFlt,
   DR2CT_Dr7ComFlt,DR2CT_Dr7AddCodeFlt,DR2CT_Dr7MaintainBtnFlt;

   bool DR2CT_Dr8MotoLineBrk,DR2CT_Dr8ClockedInvalid,DR2CT_Dr8ClosedInvalid,DR2CT_Dr8NotUnlockIn3s,
   DR2CT_Dr8PSensorInvalid,DR2CT_Dr8OutClockedPnotAllowed,DR2CT_Dr8SafeRelayFlt,DR2CT_Dr8InterlockFlt,
   DR2CT_Dr8ClockFlt,DR2CT_Dr8CHinderNum,DR2CT_Dr8OHinderNum,DR2CT_Dr8O0OutShort,
   DR2CT_Dr8O1OutShort,DR2CT_Dr8O2OutShort,DR2CT_Dr8O3OutShort,DR2CT_Dr8RomFlt,
   DR2CT_Dr8ComFlt,DR2CT_Dr8AddCodeFlt,DR2CT_Dr8MaintainBtnFlt;

   bool DR2CT_Dr1EnableFB,DR2CT_Dr1ZeroSpFB,DR2CT_Dr1OpenFB,DR2CT_Dr1NotOandCFB,
   DR2CT_Dr1CloseFB,DR2CT_Dr1OpenHinder,DR2CT_Dr1Safe1FB,DR2CT_Dr1Safe2FB,
   DR2CT_Dr1Closed,DR2CT_Dr1Opened,DR2CT_Dr1EMCunclock,DR2CT_Dr1Cut,
   DR2CT_Dr1CloseHinder,DR2CT_Dr1ReSwitchLineFB,DR2CT_Dr1SeriousFlt,DR2CT_Dr1SlightFlt;

   bool DR2CT_Dr2EnableFB,DR2CT_Dr2ZeroSpFB,DR2CT_Dr2OpenFB,DR2CT_Dr2NotOandCFB,
   DR2CT_Dr2CloseFB,DR2CT_Dr2OpenHinder,DR2CT_Dr2Safe1FB,DR2CT_Dr2Safe2FB,
   DR2CT_Dr2Closed,DR2CT_Dr2Opened,DR2CT_Dr2EMCunclock,DR2CT_Dr2Cut,
   DR2CT_Dr2CloseHinder,DR2CT_Dr2ReSwitchLineFB,DR2CT_Dr2SeriousFlt,DR2CT_Dr2SlightFlt;

   bool DR2CT_Dr3EnableFB,DR2CT_Dr3ZeroSpFB,DR2CT_Dr3OpenFB,DR2CT_Dr3NotOandCFB,
   DR2CT_Dr3CloseFB,DR2CT_Dr3OpenHinder,DR2CT_Dr3Safe1FB,DR2CT_Dr3Safe2FB,
   DR2CT_Dr3Closed,DR2CT_Dr3Opened,DR2CT_Dr3EMCunclock,DR2CT_Dr3Cut,
   DR2CT_Dr3CloseHinder,DR2CT_Dr3ReSwitchLineFB,DR2CT_Dr3SeriousFlt,DR2CT_Dr3SlightFlt;

   bool DR2CT_Dr4EnableFB,DR2CT_Dr4ZeroSpFB,DR2CT_Dr4OpenFB,DR2CT_Dr4NotOandCFB,
   DR2CT_Dr4CloseFB,DR2CT_Dr4OpenHinder,DR2CT_Dr4Safe1FB,DR2CT_Dr4Safe2FB,
   DR2CT_Dr4Closed,DR2CT_Dr4Opened,DR2CT_Dr4EMCunclock,DR2CT_Dr4Cut,
   DR2CT_Dr4CloseHinder,DR2CT_Dr4ReSwitchLineFB,DR2CT_Dr4SeriousFlt,DR2CT_Dr4SlightFlt;

   bool DR2CT_Dr5EnableFB,DR2CT_Dr5ZeroSpFB,DR2CT_Dr5OpenFB,DR2CT_Dr5NotOandCFB,
   DR2CT_Dr5CloseFB,DR2CT_Dr5OpenHinder,DR2CT_Dr5Safe1FB,DR2CT_Dr5Safe2FB,
   DR2CT_Dr5Closed,DR2CT_Dr5Opened,DR2CT_Dr5EMCunclock,DR2CT_Dr5Cut,
   DR2CT_Dr5CloseHinder,DR2CT_Dr5ReSwitchLineFB,DR2CT_Dr5SeriousFlt,DR2CT_Dr5SlightFlt;

   bool DR2CT_Dr6EnableFB,DR2CT_Dr6ZeroSpFB,DR2CT_Dr6OpenFB,DR2CT_Dr6NotOandCFB,
   DR2CT_Dr6CloseFB,DR2CT_Dr6OpenHinder,DR2CT_Dr6Safe1FB,DR2CT_Dr6Safe2FB,
   DR2CT_Dr6Closed,DR2CT_Dr6Opened,DR2CT_Dr6EMCunclock,DR2CT_Dr6Cut,
   DR2CT_Dr6CloseHinder,DR2CT_Dr6ReSwitchLineFB,DR2CT_Dr6SeriousFlt,DR2CT_Dr6SlightFlt;

   bool DR2CT_Dr7EnableFB,DR2CT_Dr7ZeroSpFB,DR2CT_Dr7OpenFB,DR2CT_Dr7NotOandCFB,
   DR2CT_Dr7CloseFB,DR2CT_Dr7OpenHinder,DR2CT_Dr7Safe1FB,DR2CT_Dr7Safe2FB,
   DR2CT_Dr7Closed,DR2CT_Dr7Opened,DR2CT_Dr7EMCunclock,DR2CT_Dr7Cut,
   DR2CT_Dr7CloseHinder,DR2CT_Dr7ReSwitchLineFB,DR2CT_Dr7SeriousFlt,DR2CT_Dr7SlightFlt;

   bool DR2CT_Dr8EnableFB,DR2CT_Dr8ZeroSpFB,DR2CT_Dr8OpenFB,DR2CT_Dr8NotOandCFB,
   DR2CT_Dr8CloseFB,DR2CT_Dr8OpenHinder,DR2CT_Dr8Safe1FB,DR2CT_Dr8Safe2FB,
   DR2CT_Dr8Closed,DR2CT_Dr8Opened,DR2CT_Dr8EMCunclock,DR2CT_Dr8Cut,
   DR2CT_Dr8CloseHinder,DR2CT_Dr8ReSwitchLineFB,DR2CT_Dr8SeriousFlt,DR2CT_Dr8SlightFlt;

   unsigned short int DR2CT_OperationSt;
   bool DR2CT_MDCU1DataValid,DR2CT_MDCU2DataValid,DR2CT_MDCU3DataValid,DR2CT_MDCU4DataValid,
   DR2CT_MDCU5DataValid,DR2CT_MDCU6DataValid,DR2CT_MDCU7DataValid,DR2CT_MDCU8DataValid;

   unsigned short int DR2CT_BusToken,DR2CT_LifeSign;
   bool DR2CT_CANBreak;

   unsigned short int DR2CT_D1Version,DR2CT_D2Version,DR2CT_D3Version,DR2CT_D4Version,
   DR2CT_D5Version,DR2CT_D6Version,DR2CT_D7Version,DR2CT_D8Version;

    //0x730, 0x731, 0x732
   bool DR3CT_Dr1MotoLineBrk,DR3CT_Dr1ClockedInvalid,DR3CT_Dr1ClosedInvalid,DR3CT_Dr1NotUnlockIn3s,
   DR3CT_Dr1PSensorInvalid,DR3CT_Dr1OutClockedPnotAllowed,DR3CT_Dr1SafeRelayFlt,DR3CT_Dr1InterlockFlt,
   DR3CT_Dr1ClockFlt,DR3CT_Dr1CHinderNum,DR3CT_Dr1OHinderNum,DR3CT_Dr1O0OutShort,
   DR3CT_Dr1O1OutShort,DR3CT_Dr1O2OutShort,DR3CT_Dr1O3OutShort,DR3CT_Dr1RomFlt,
   DR3CT_Dr1ComFlt,DR3CT_Dr1AddCodeFlt,DR3CT_Dr1MaintainBtnFlt;

   bool DR3CT_Dr2MotoLineBrk,DR3CT_Dr2ClockedInvalid,DR3CT_Dr2ClosedInvalid,DR3CT_Dr2NotUnlockIn3s,
   DR3CT_Dr2PSensorInvalid,DR3CT_Dr2OutClockedPnotAllowed,DR3CT_Dr2SafeRelayFlt,DR3CT_Dr2InterlockFlt,
   DR3CT_Dr2ClockFlt,DR3CT_Dr2CHinderNum,DR3CT_Dr2OHinderNum,DR3CT_Dr2O0OutShort,
   DR3CT_Dr2O1OutShort,DR3CT_Dr2O2OutShort,DR3CT_Dr2O3OutShort,DR3CT_Dr2RomFlt,
   DR3CT_Dr2ComFlt,DR3CT_Dr2AddCodeFlt,DR3CT_Dr2MaintainBtnFlt;

   bool DR3CT_Dr3MotoLineBrk,DR3CT_Dr3ClockedInvalid,DR3CT_Dr3ClosedInvalid,DR3CT_Dr3NotUnlockIn3s,
   DR3CT_Dr3PSensorInvalid,DR3CT_Dr3OutClockedPnotAllowed,DR3CT_Dr3SafeRelayFlt,DR3CT_Dr3InterlockFlt,
   DR3CT_Dr3ClockFlt,DR3CT_Dr3CHinderNum,DR3CT_Dr3OHinderNum,DR3CT_Dr3O0OutShort,
   DR3CT_Dr3O1OutShort,DR3CT_Dr3O2OutShort,DR3CT_Dr3O3OutShort,DR3CT_Dr3RomFlt,
   DR3CT_Dr3ComFlt,DR3CT_Dr3AddCodeFlt,DR3CT_Dr3MaintainBtnFlt;

   bool DR3CT_Dr4MotoLineBrk,DR3CT_Dr4ClockedInvalid,DR3CT_Dr4ClosedInvalid,DR3CT_Dr4NotUnlockIn3s,
   DR3CT_Dr4PSensorInvalid,DR3CT_Dr4OutClockedPnotAllowed,DR3CT_Dr4SafeRelayFlt,DR3CT_Dr4InterlockFlt,
   DR3CT_Dr4ClockFlt,DR3CT_Dr4CHinderNum,DR3CT_Dr4OHinderNum,DR3CT_Dr4O0OutShort,
   DR3CT_Dr4O1OutShort,DR3CT_Dr4O2OutShort,DR3CT_Dr4O3OutShort,DR3CT_Dr4RomFlt,
   DR3CT_Dr4ComFlt,DR3CT_Dr4AddCodeFlt,DR3CT_Dr4MaintainBtnFlt;

   bool DR3CT_Dr5MotoLineBrk,DR3CT_Dr5ClockedInvalid,DR3CT_Dr5ClosedInvalid,DR3CT_Dr5NotUnlockIn3s,
   DR3CT_Dr5PSensorInvalid,DR3CT_Dr5OutClockedPnotAllowed,DR3CT_Dr5SafeRelayFlt,DR3CT_Dr5InterlockFlt,
   DR3CT_Dr5ClockFlt,DR3CT_Dr5CHinderNum,DR3CT_Dr5OHinderNum,DR3CT_Dr5O0OutShort,
   DR3CT_Dr5O1OutShort,DR3CT_Dr5O2OutShort,DR3CT_Dr5O3OutShort,DR3CT_Dr5RomFlt,
   DR3CT_Dr5ComFlt,DR3CT_Dr5AddCodeFlt,DR3CT_Dr5MaintainBtnFlt;

   bool DR3CT_Dr6MotoLineBrk,DR3CT_Dr6ClockedInvalid,DR3CT_Dr6ClosedInvalid,DR3CT_Dr6NotUnlockIn3s,
   DR3CT_Dr6PSensorInvalid,DR3CT_Dr6OutClockedPnotAllowed,DR3CT_Dr6SafeRelayFlt,DR3CT_Dr6InterlockFlt,
   DR3CT_Dr6ClockFlt,DR3CT_Dr6CHinderNum,DR3CT_Dr6OHinderNum,DR3CT_Dr6O0OutShort,
   DR3CT_Dr6O1OutShort,DR3CT_Dr6O2OutShort,DR3CT_Dr6O3OutShort,DR3CT_Dr6RomFlt,
   DR3CT_Dr6ComFlt,DR3CT_Dr6AddCodeFlt,DR3CT_Dr6MaintainBtnFlt;

   bool DR3CT_Dr7MotoLineBrk,DR3CT_Dr7ClockedInvalid,DR3CT_Dr7ClosedInvalid,DR3CT_Dr7NotUnlockIn3s,
   DR3CT_Dr7PSensorInvalid,DR3CT_Dr7OutClockedPnotAllowed,DR3CT_Dr7SafeRelayFlt,DR3CT_Dr7InterlockFlt,
   DR3CT_Dr7ClockFlt,DR3CT_Dr7CHinderNum,DR3CT_Dr7OHinderNum,DR3CT_Dr7O0OutShort,
   DR3CT_Dr7O1OutShort,DR3CT_Dr7O2OutShort,DR3CT_Dr7O3OutShort,DR3CT_Dr7RomFlt,
   DR3CT_Dr7ComFlt,DR3CT_Dr7AddCodeFlt,DR3CT_Dr7MaintainBtnFlt;

   bool DR3CT_Dr8MotoLineBrk,DR3CT_Dr8ClockedInvalid,DR3CT_Dr8ClosedInvalid,DR3CT_Dr8NotUnlockIn3s,
   DR3CT_Dr8PSensorInvalid,DR3CT_Dr8OutClockedPnotAllowed,DR3CT_Dr8SafeRelayFlt,DR3CT_Dr8InterlockFlt,
   DR3CT_Dr8ClockFlt,DR3CT_Dr8CHinderNum,DR3CT_Dr8OHinderNum,DR3CT_Dr8O0OutShort,
   DR3CT_Dr8O1OutShort,DR3CT_Dr8O2OutShort,DR3CT_Dr8O3OutShort,DR3CT_Dr8RomFlt,
   DR3CT_Dr8ComFlt,DR3CT_Dr8AddCodeFlt,DR3CT_Dr8MaintainBtnFlt;

   bool DR3CT_Dr1EnableFB,DR3CT_Dr1ZeroSpFB,DR3CT_Dr1OpenFB,DR3CT_Dr1NotOandCFB,
   DR3CT_Dr1CloseFB,DR3CT_Dr1OpenHinder,DR3CT_Dr1Safe1FB,DR3CT_Dr1Safe2FB,
   DR3CT_Dr1Closed,DR3CT_Dr1Opened,DR3CT_Dr1EMCunclock,DR3CT_Dr1Cut,
   DR3CT_Dr1CloseHinder,DR3CT_Dr1ReSwitchLineFB,DR3CT_Dr1SeriousFlt,DR3CT_Dr1SlightFlt;

   bool DR3CT_Dr2EnableFB,DR3CT_Dr2ZeroSpFB,DR3CT_Dr2OpenFB,DR3CT_Dr2NotOandCFB,
   DR3CT_Dr2CloseFB,DR3CT_Dr2OpenHinder,DR3CT_Dr2Safe1FB,DR3CT_Dr2Safe2FB,
   DR3CT_Dr2Closed,DR3CT_Dr2Opened,DR3CT_Dr2EMCunclock,DR3CT_Dr2Cut,
   DR3CT_Dr2CloseHinder,DR3CT_Dr2ReSwitchLineFB,DR3CT_Dr2SeriousFlt,DR3CT_Dr2SlightFlt;

   bool DR3CT_Dr3EnableFB,DR3CT_Dr3ZeroSpFB,DR3CT_Dr3OpenFB,DR3CT_Dr3NotOandCFB,
   DR3CT_Dr3CloseFB,DR3CT_Dr3OpenHinder,DR3CT_Dr3Safe1FB,DR3CT_Dr3Safe2FB,
   DR3CT_Dr3Closed,DR3CT_Dr3Opened,DR3CT_Dr3EMCunclock,DR3CT_Dr3Cut,
   DR3CT_Dr3CloseHinder,DR3CT_Dr3ReSwitchLineFB,DR3CT_Dr3SeriousFlt,DR3CT_Dr3SlightFlt;

   bool DR3CT_Dr4EnableFB,DR3CT_Dr4ZeroSpFB,DR3CT_Dr4OpenFB,DR3CT_Dr4NotOandCFB,
   DR3CT_Dr4CloseFB,DR3CT_Dr4OpenHinder,DR3CT_Dr4Safe1FB,DR3CT_Dr4Safe2FB,
   DR3CT_Dr4Closed,DR3CT_Dr4Opened,DR3CT_Dr4EMCunclock,DR3CT_Dr4Cut,
   DR3CT_Dr4CloseHinder,DR3CT_Dr4ReSwitchLineFB,DR3CT_Dr4SeriousFlt,DR3CT_Dr4SlightFlt;

   bool DR3CT_Dr5EnableFB,DR3CT_Dr5ZeroSpFB,DR3CT_Dr5OpenFB,DR3CT_Dr5NotOandCFB,
   DR3CT_Dr5CloseFB,DR3CT_Dr5OpenHinder,DR3CT_Dr5Safe1FB,DR3CT_Dr5Safe2FB,
   DR3CT_Dr5Closed,DR3CT_Dr5Opened,DR3CT_Dr5EMCunclock,DR3CT_Dr5Cut,
   DR3CT_Dr5CloseHinder,DR3CT_Dr5ReSwitchLineFB,DR3CT_Dr5SeriousFlt,DR3CT_Dr5SlightFlt;

   bool DR3CT_Dr6EnableFB,DR3CT_Dr6ZeroSpFB,DR3CT_Dr6OpenFB,DR3CT_Dr6NotOandCFB,
   DR3CT_Dr6CloseFB,DR3CT_Dr6OpenHinder,DR3CT_Dr6Safe1FB,DR3CT_Dr6Safe2FB,
   DR3CT_Dr6Closed,DR3CT_Dr6Opened,DR3CT_Dr6EMCunclock,DR3CT_Dr6Cut,
   DR3CT_Dr6CloseHinder,DR3CT_Dr6ReSwitchLineFB,DR3CT_Dr6SeriousFlt,DR3CT_Dr6SlightFlt;

   bool DR3CT_Dr7EnableFB,DR3CT_Dr7ZeroSpFB,DR3CT_Dr7OpenFB,DR3CT_Dr7NotOandCFB,
   DR3CT_Dr7CloseFB,DR3CT_Dr7OpenHinder,DR3CT_Dr7Safe1FB,DR3CT_Dr7Safe2FB,
   DR3CT_Dr7Closed,DR3CT_Dr7Opened,DR3CT_Dr7EMCunclock,DR3CT_Dr7Cut,
   DR3CT_Dr7CloseHinder,DR3CT_Dr7ReSwitchLineFB,DR3CT_Dr7SeriousFlt,DR3CT_Dr7SlightFlt;

   bool DR3CT_Dr8EnableFB,DR3CT_Dr8ZeroSpFB,DR3CT_Dr8OpenFB,DR3CT_Dr8NotOandCFB,
   DR3CT_Dr8CloseFB,DR3CT_Dr8OpenHinder,DR3CT_Dr8Safe1FB,DR3CT_Dr8Safe2FB,
   DR3CT_Dr8Closed,DR3CT_Dr8Opened,DR3CT_Dr8EMCunclock,DR3CT_Dr8Cut,
   DR3CT_Dr8CloseHinder,DR3CT_Dr8ReSwitchLineFB,DR3CT_Dr8SeriousFlt,DR3CT_Dr8SlightFlt;

   unsigned short int DR3CT_OperationSt;
   bool DR3CT_MDCU1DataValid,DR3CT_MDCU2DataValid,DR3CT_MDCU3DataValid,DR3CT_MDCU4DataValid,
   DR3CT_MDCU5DataValid,DR3CT_MDCU6DataValid,DR3CT_MDCU7DataValid,DR3CT_MDCU8DataValid;

   unsigned short int DR3CT_BusToken,DR3CT_LifeSign;
   bool DR3CT_CANBreak;
   unsigned short int DR3CT_D1Version,DR3CT_D2Version,DR3CT_D3Version,DR3CT_D4Version,
   DR3CT_D5Version,DR3CT_D6Version,DR3CT_D7Version,DR3CT_D8Version;

   //0x740, 0x741, 0x742
   bool DR4CT_Dr1MotoLineBrk,DR4CT_Dr1ClockedInvalid,DR4CT_Dr1ClosedInvalid,DR4CT_Dr1NotUnlockIn3s,
   DR4CT_Dr1PSensorInvalid,DR4CT_Dr1OutClockedPnotAllowed,DR4CT_Dr1SafeRelayFlt,DR4CT_Dr1InterlockFlt,
   DR4CT_Dr1ClockFlt,DR4CT_Dr1CHinderNum,DR4CT_Dr1OHinderNum,DR4CT_Dr1O0OutShort,
   DR4CT_Dr1O1OutShort,DR4CT_Dr1O2OutShort,DR4CT_Dr1O3OutShort,DR4CT_Dr1RomFlt,
   DR4CT_Dr1ComFlt,DR4CT_Dr1AddCodeFlt,DR4CT_Dr1MaintainBtnFlt;

   bool DR4CT_Dr2MotoLineBrk,DR4CT_Dr2ClockedInvalid,DR4CT_Dr2ClosedInvalid,DR4CT_Dr2NotUnlockIn3s,
   DR4CT_Dr2PSensorInvalid,DR4CT_Dr2OutClockedPnotAllowed,DR4CT_Dr2SafeRelayFlt,DR4CT_Dr2InterlockFlt,
   DR4CT_Dr2ClockFlt,DR4CT_Dr2CHinderNum,DR4CT_Dr2OHinderNum,DR4CT_Dr2O0OutShort,
   DR4CT_Dr2O1OutShort,DR4CT_Dr2O2OutShort,DR4CT_Dr2O3OutShort,DR4CT_Dr2RomFlt,
   DR4CT_Dr2ComFlt,DR4CT_Dr2AddCodeFlt,DR4CT_Dr2MaintainBtnFlt;

   bool DR4CT_Dr3MotoLineBrk,DR4CT_Dr3ClockedInvalid,DR4CT_Dr3ClosedInvalid,DR4CT_Dr3NotUnlockIn3s,
   DR4CT_Dr3PSensorInvalid,DR4CT_Dr3OutClockedPnotAllowed,DR4CT_Dr3SafeRelayFlt,DR4CT_Dr3InterlockFlt,
   DR4CT_Dr3ClockFlt,DR4CT_Dr3CHinderNum,DR4CT_Dr3OHinderNum,DR4CT_Dr3O0OutShort,
   DR4CT_Dr3O1OutShort,DR4CT_Dr3O2OutShort,DR4CT_Dr3O3OutShort,DR4CT_Dr3RomFlt,
   DR4CT_Dr3ComFlt,DR4CT_Dr3AddCodeFlt,DR4CT_Dr3MaintainBtnFlt;

   bool DR4CT_Dr4MotoLineBrk,DR4CT_Dr4ClockedInvalid,DR4CT_Dr4ClosedInvalid,DR4CT_Dr4NotUnlockIn3s,
   DR4CT_Dr4PSensorInvalid,DR4CT_Dr4OutClockedPnotAllowed,DR4CT_Dr4SafeRelayFlt,DR4CT_Dr4InterlockFlt,
   DR4CT_Dr4ClockFlt,DR4CT_Dr4CHinderNum,DR4CT_Dr4OHinderNum,DR4CT_Dr4O0OutShort,
   DR4CT_Dr4O1OutShort,DR4CT_Dr4O2OutShort,DR4CT_Dr4O3OutShort,DR4CT_Dr4RomFlt,
   DR4CT_Dr4ComFlt,DR4CT_Dr4AddCodeFlt,DR4CT_Dr4MaintainBtnFlt;

   bool DR4CT_Dr5MotoLineBrk,DR4CT_Dr5ClockedInvalid,DR4CT_Dr5ClosedInvalid,DR4CT_Dr5NotUnlockIn3s,
   DR4CT_Dr5PSensorInvalid,DR4CT_Dr5OutClockedPnotAllowed,DR4CT_Dr5SafeRelayFlt,DR4CT_Dr5InterlockFlt,
   DR4CT_Dr5ClockFlt,DR4CT_Dr5CHinderNum,DR4CT_Dr5OHinderNum,DR4CT_Dr5O0OutShort,
   DR4CT_Dr5O1OutShort,DR4CT_Dr5O2OutShort,DR4CT_Dr5O3OutShort,DR4CT_Dr5RomFlt,
   DR4CT_Dr5ComFlt,DR4CT_Dr5AddCodeFlt,DR4CT_Dr5MaintainBtnFlt;

   bool DR4CT_Dr6MotoLineBrk,DR4CT_Dr6ClockedInvalid,DR4CT_Dr6ClosedInvalid,DR4CT_Dr6NotUnlockIn3s,
   DR4CT_Dr6PSensorInvalid,DR4CT_Dr6OutClockedPnotAllowed,DR4CT_Dr6SafeRelayFlt,DR4CT_Dr6InterlockFlt,
   DR4CT_Dr6ClockFlt,DR4CT_Dr6CHinderNum,DR4CT_Dr6OHinderNum,DR4CT_Dr6O0OutShort,
   DR4CT_Dr6O1OutShort,DR4CT_Dr6O2OutShort,DR4CT_Dr6O3OutShort,DR4CT_Dr6RomFlt,
   DR4CT_Dr6ComFlt,DR4CT_Dr6AddCodeFlt,DR4CT_Dr6MaintainBtnFlt;

   bool DR4CT_Dr7MotoLineBrk,DR4CT_Dr7ClockedInvalid,DR4CT_Dr7ClosedInvalid,DR4CT_Dr7NotUnlockIn3s,
   DR4CT_Dr7PSensorInvalid,DR4CT_Dr7OutClockedPnotAllowed,DR4CT_Dr7SafeRelayFlt,DR4CT_Dr7InterlockFlt,
   DR4CT_Dr7ClockFlt,DR4CT_Dr7CHinderNum,DR4CT_Dr7OHinderNum,DR4CT_Dr7O0OutShort,
   DR4CT_Dr7O1OutShort,DR4CT_Dr7O2OutShort,DR4CT_Dr7O3OutShort,DR4CT_Dr7RomFlt,
   DR4CT_Dr7ComFlt,DR4CT_Dr7AddCodeFlt,DR4CT_Dr7MaintainBtnFlt;

   bool DR4CT_Dr8MotoLineBrk,DR4CT_Dr8ClockedInvalid,DR4CT_Dr8ClosedInvalid,DR4CT_Dr8NotUnlockIn3s,
   DR4CT_Dr8PSensorInvalid,DR4CT_Dr8OutClockedPnotAllowed,DR4CT_Dr8SafeRelayFlt,DR4CT_Dr8InterlockFlt,
   DR4CT_Dr8ClockFlt,DR4CT_Dr8CHinderNum,DR4CT_Dr8OHinderNum,DR4CT_Dr8O0OutShort,
   DR4CT_Dr8O1OutShort,DR4CT_Dr8O2OutShort,DR4CT_Dr8O3OutShort,DR4CT_Dr8RomFlt,
   DR4CT_Dr8ComFlt,DR4CT_Dr8AddCodeFlt,DR4CT_Dr8MaintainBtnFlt;

   bool DR4CT_Dr1EnableFB,DR4CT_Dr1ZeroSpFB,DR4CT_Dr1OpenFB,DR4CT_Dr1NotOandCFB,
   DR4CT_Dr1CloseFB,DR4CT_Dr1OpenHinder,DR4CT_Dr1Safe1FB,DR4CT_Dr1Safe2FB,
   DR4CT_Dr1Closed,DR4CT_Dr1Opened,DR4CT_Dr1EMCunclock,DR4CT_Dr1Cut,
   DR4CT_Dr1CloseHinder,DR4CT_Dr1ReSwitchLineFB,DR4CT_Dr1SeriousFlt,DR4CT_Dr1SlightFlt;

   bool DR4CT_Dr2EnableFB,DR4CT_Dr2ZeroSpFB,DR4CT_Dr2OpenFB,DR4CT_Dr2NotOandCFB,
   DR4CT_Dr2CloseFB,DR4CT_Dr2OpenHinder,DR4CT_Dr2Safe1FB,DR4CT_Dr2Safe2FB,
   DR4CT_Dr2Closed,DR4CT_Dr2Opened,DR4CT_Dr2EMCunclock,DR4CT_Dr2Cut,
   DR4CT_Dr2CloseHinder,DR4CT_Dr2ReSwitchLineFB,DR4CT_Dr2SeriousFlt,DR4CT_Dr2SlightFlt;

   bool DR4CT_Dr3EnableFB,DR4CT_Dr3ZeroSpFB,DR4CT_Dr3OpenFB,DR4CT_Dr3NotOandCFB,
   DR4CT_Dr3CloseFB,DR4CT_Dr3OpenHinder,DR4CT_Dr3Safe1FB,DR4CT_Dr3Safe2FB,
   DR4CT_Dr3Closed,DR4CT_Dr3Opened,DR4CT_Dr3EMCunclock,DR4CT_Dr3Cut,
   DR4CT_Dr3CloseHinder,DR4CT_Dr3ReSwitchLineFB,DR4CT_Dr3SeriousFlt,DR4CT_Dr3SlightFlt;

   bool DR4CT_Dr4EnableFB,DR4CT_Dr4ZeroSpFB,DR4CT_Dr4OpenFB,DR4CT_Dr4NotOandCFB,
   DR4CT_Dr4CloseFB,DR4CT_Dr4OpenHinder,DR4CT_Dr4Safe1FB,DR4CT_Dr4Safe2FB,
   DR4CT_Dr4Closed,DR4CT_Dr4Opened,DR4CT_Dr4EMCunclock,DR4CT_Dr4Cut,
   DR4CT_Dr4CloseHinder,DR4CT_Dr4ReSwitchLineFB,DR4CT_Dr4SeriousFlt,DR4CT_Dr4SlightFlt;

   bool DR4CT_Dr5EnableFB,DR4CT_Dr5ZeroSpFB,DR4CT_Dr5OpenFB,DR4CT_Dr5NotOandCFB,
   DR4CT_Dr5CloseFB,DR4CT_Dr5OpenHinder,DR4CT_Dr5Safe1FB,DR4CT_Dr5Safe2FB,
   DR4CT_Dr5Closed,DR4CT_Dr5Opened,DR4CT_Dr5EMCunclock,DR4CT_Dr5Cut,
   DR4CT_Dr5CloseHinder,DR4CT_Dr5ReSwitchLineFB,DR4CT_Dr5SeriousFlt,DR4CT_Dr5SlightFlt;

   bool DR4CT_Dr6EnableFB,DR4CT_Dr6ZeroSpFB,DR4CT_Dr6OpenFB,DR4CT_Dr6NotOandCFB,
   DR4CT_Dr6CloseFB,DR4CT_Dr6OpenHinder,DR4CT_Dr6Safe1FB,DR4CT_Dr6Safe2FB,
   DR4CT_Dr6Closed,DR4CT_Dr6Opened,DR4CT_Dr6EMCunclock,DR4CT_Dr6Cut,
   DR4CT_Dr6CloseHinder,DR4CT_Dr6ReSwitchLineFB,DR4CT_Dr6SeriousFlt,DR4CT_Dr6SlightFlt;

   bool DR4CT_Dr7EnableFB,DR4CT_Dr7ZeroSpFB,DR4CT_Dr7OpenFB,DR4CT_Dr7NotOandCFB,
   DR4CT_Dr7CloseFB,DR4CT_Dr7OpenHinder,DR4CT_Dr7Safe1FB,DR4CT_Dr7Safe2FB,
   DR4CT_Dr7Closed,DR4CT_Dr7Opened,DR4CT_Dr7EMCunclock,DR4CT_Dr7Cut,
   DR4CT_Dr7CloseHinder,DR4CT_Dr7ReSwitchLineFB,DR4CT_Dr7SeriousFlt,DR4CT_Dr7SlightFlt;

   bool DR4CT_Dr8EnableFB,DR4CT_Dr8ZeroSpFB,DR4CT_Dr8OpenFB,DR4CT_Dr8NotOandCFB,
   DR4CT_Dr8CloseFB,DR4CT_Dr8OpenHinder,DR4CT_Dr8Safe1FB,DR4CT_Dr8Safe2FB,
   DR4CT_Dr8Closed,DR4CT_Dr8Opened,DR4CT_Dr8EMCunclock,DR4CT_Dr8Cut,
   DR4CT_Dr8CloseHinder,DR4CT_Dr8ReSwitchLineFB,DR4CT_Dr8SeriousFlt,DR4CT_Dr8SlightFlt;

   unsigned short int DR4CT_OperationSt;

   bool DR4CT_MDCU1DataValid,DR4CT_MDCU2DataValid,DR4CT_MDCU3DataValid,DR4CT_MDCU4DataValid,
   DR4CT_MDCU5DataValid,DR4CT_MDCU6DataValid,DR4CT_MDCU7DataValid,DR4CT_MDCU8DataValid;

   unsigned short int DR4CT_BusToken,DR4CT_LifeSign;
   bool DR4CT_CANBreak;
   unsigned short int DR4CT_D1Version,DR4CT_D2Version,DR4CT_D3Version,DR4CT_D4Version,
   DR4CT_D5Version,DR4CT_D6Version,DR4CT_D7Version,DR4CT_D8Version;

   //0x750, 0x751, 0x752
   bool DR5CT_Dr1MotoLineBrk,DR5CT_Dr1ClockedInvalid,DR5CT_Dr1ClosedInvalid,DR5CT_Dr1NotUnlockIn3s,
   DR5CT_Dr1PSensorInvalid,DR5CT_Dr1OutClockedPnotAllowed,DR5CT_Dr1SafeRelayFlt,DR5CT_Dr1InterlockFlt,
   DR5CT_Dr1ClockFlt,DR5CT_Dr1CHinderNum,DR5CT_Dr1OHinderNum,DR5CT_Dr1O0OutShort,
   DR5CT_Dr1O1OutShort,DR5CT_Dr1O2OutShort,DR5CT_Dr1O3OutShort,DR5CT_Dr1RomFlt,
   DR5CT_Dr1ComFlt,DR5CT_Dr1AddCodeFlt,DR5CT_Dr1MaintainBtnFlt;

   bool DR5CT_Dr2MotoLineBrk,DR5CT_Dr2ClockedInvalid,DR5CT_Dr2ClosedInvalid,DR5CT_Dr2NotUnlockIn3s,
   DR5CT_Dr2PSensorInvalid,DR5CT_Dr2OutClockedPnotAllowed,DR5CT_Dr2SafeRelayFlt,DR5CT_Dr2InterlockFlt,
   DR5CT_Dr2ClockFlt,DR5CT_Dr2CHinderNum,DR5CT_Dr2OHinderNum,DR5CT_Dr2O0OutShort,
   DR5CT_Dr2O1OutShort,DR5CT_Dr2O2OutShort,DR5CT_Dr2O3OutShort,DR5CT_Dr2RomFlt,
   DR5CT_Dr2ComFlt,DR5CT_Dr2AddCodeFlt,DR5CT_Dr2MaintainBtnFlt;

   bool DR5CT_Dr3MotoLineBrk,DR5CT_Dr3ClockedInvalid,DR5CT_Dr3ClosedInvalid,DR5CT_Dr3NotUnlockIn3s,
   DR5CT_Dr3PSensorInvalid,DR5CT_Dr3OutClockedPnotAllowed,DR5CT_Dr3SafeRelayFlt,DR5CT_Dr3InterlockFlt,
   DR5CT_Dr3ClockFlt,DR5CT_Dr3CHinderNum,DR5CT_Dr3OHinderNum,DR5CT_Dr3O0OutShort,
   DR5CT_Dr3O1OutShort,DR5CT_Dr3O2OutShort,DR5CT_Dr3O3OutShort,DR5CT_Dr3RomFlt,
   DR5CT_Dr3ComFlt,DR5CT_Dr3AddCodeFlt,DR5CT_Dr3MaintainBtnFlt;

   bool DR5CT_Dr4MotoLineBrk,DR5CT_Dr4ClockedInvalid,DR5CT_Dr4ClosedInvalid,DR5CT_Dr4NotUnlockIn3s,
   DR5CT_Dr4PSensorInvalid,DR5CT_Dr4OutClockedPnotAllowed,DR5CT_Dr4SafeRelayFlt,DR5CT_Dr4InterlockFlt,
   DR5CT_Dr4ClockFlt,DR5CT_Dr4CHinderNum,DR5CT_Dr4OHinderNum,DR5CT_Dr4O0OutShort,
   DR5CT_Dr4O1OutShort,DR5CT_Dr4O2OutShort,DR5CT_Dr4O3OutShort,DR5CT_Dr4RomFlt,
   DR5CT_Dr4ComFlt,DR5CT_Dr4AddCodeFlt,DR5CT_Dr4MaintainBtnFlt;

   bool DR5CT_Dr5MotoLineBrk,DR5CT_Dr5ClockedInvalid,DR5CT_Dr5ClosedInvalid,DR5CT_Dr5NotUnlockIn3s,
   DR5CT_Dr5PSensorInvalid,DR5CT_Dr5OutClockedPnotAllowed,DR5CT_Dr5SafeRelayFlt,DR5CT_Dr5InterlockFlt,
   DR5CT_Dr5ClockFlt,DR5CT_Dr5CHinderNum,DR5CT_Dr5OHinderNum,DR5CT_Dr5O0OutShort,
   DR5CT_Dr5O1OutShort,DR5CT_Dr5O2OutShort,DR5CT_Dr5O3OutShort,DR5CT_Dr5RomFlt,
   DR5CT_Dr5ComFlt,DR5CT_Dr5AddCodeFlt,DR5CT_Dr5MaintainBtnFlt;

   bool DR5CT_Dr6MotoLineBrk,DR5CT_Dr6ClockedInvalid,DR5CT_Dr6ClosedInvalid,DR5CT_Dr6NotUnlockIn3s,
   DR5CT_Dr6PSensorInvalid,DR5CT_Dr6OutClockedPnotAllowed,DR5CT_Dr6SafeRelayFlt,DR5CT_Dr6InterlockFlt,
   DR5CT_Dr6ClockFlt,DR5CT_Dr6CHinderNum,DR5CT_Dr6OHinderNum,DR5CT_Dr6O0OutShort,
   DR5CT_Dr6O1OutShort,DR5CT_Dr6O2OutShort,DR5CT_Dr6O3OutShort,DR5CT_Dr6RomFlt,
   DR5CT_Dr6ComFlt,DR5CT_Dr6AddCodeFlt,DR5CT_Dr6MaintainBtnFlt;

   bool DR5CT_Dr7MotoLineBrk,DR5CT_Dr7ClockedInvalid,DR5CT_Dr7ClosedInvalid,DR5CT_Dr7NotUnlockIn3s,
   DR5CT_Dr7PSensorInvalid,DR5CT_Dr7OutClockedPnotAllowed,DR5CT_Dr7SafeRelayFlt,DR5CT_Dr7InterlockFlt,
   DR5CT_Dr7ClockFlt,DR5CT_Dr7CHinderNum,DR5CT_Dr7OHinderNum,DR5CT_Dr7O0OutShort,
   DR5CT_Dr7O1OutShort,DR5CT_Dr7O2OutShort,DR5CT_Dr7O3OutShort,DR5CT_Dr7RomFlt,
   DR5CT_Dr7ComFlt,DR5CT_Dr7AddCodeFlt,DR5CT_Dr7MaintainBtnFlt;

   bool DR5CT_Dr8MotoLineBrk,DR5CT_Dr8ClockedInvalid,DR5CT_Dr8ClosedInvalid,DR5CT_Dr8NotUnlockIn3s,
   DR5CT_Dr8PSensorInvalid,DR5CT_Dr8OutClockedPnotAllowed,DR5CT_Dr8SafeRelayFlt,DR5CT_Dr8InterlockFlt,
   DR5CT_Dr8ClockFlt,DR5CT_Dr8CHinderNum,DR5CT_Dr8OHinderNum,DR5CT_Dr8O0OutShort,
   DR5CT_Dr8O1OutShort,DR5CT_Dr8O2OutShort,DR5CT_Dr8O3OutShort,DR5CT_Dr8RomFlt,
   DR5CT_Dr8ComFlt,DR5CT_Dr8AddCodeFlt,DR5CT_Dr8MaintainBtnFlt;

   bool DR5CT_Dr1EnableFB,DR5CT_Dr1ZeroSpFB,DR5CT_Dr1OpenFB,DR5CT_Dr1NotOandCFB,
   DR5CT_Dr1CloseFB,DR5CT_Dr1OpenHinder,DR5CT_Dr1Safe1FB,DR5CT_Dr1Safe2FB,
   DR5CT_Dr1Closed,DR5CT_Dr1Opened,DR5CT_Dr1EMCunclock,DR5CT_Dr1Cut,
   DR5CT_Dr1CloseHinder,DR5CT_Dr1ReSwitchLineFB,DR5CT_Dr1SeriousFlt,DR5CT_Dr1SlightFlt;

   bool DR5CT_Dr2EnableFB,DR5CT_Dr2ZeroSpFB,DR5CT_Dr2OpenFB,DR5CT_Dr2NotOandCFB,
   DR5CT_Dr2CloseFB,DR5CT_Dr2OpenHinder,DR5CT_Dr2Safe1FB,DR5CT_Dr2Safe2FB,
   DR5CT_Dr2Closed,DR5CT_Dr2Opened,DR5CT_Dr2EMCunclock,DR5CT_Dr2Cut,
   DR5CT_Dr2CloseHinder,DR5CT_Dr2ReSwitchLineFB,DR5CT_Dr2SeriousFlt,DR5CT_Dr2SlightFlt;

   bool DR5CT_Dr3EnableFB,DR5CT_Dr3ZeroSpFB,DR5CT_Dr3OpenFB,DR5CT_Dr3NotOandCFB,
   DR5CT_Dr3CloseFB,DR5CT_Dr3OpenHinder,DR5CT_Dr3Safe1FB,DR5CT_Dr3Safe2FB,
   DR5CT_Dr3Closed,DR5CT_Dr3Opened,DR5CT_Dr3EMCunclock,DR5CT_Dr3Cut,
   DR5CT_Dr3CloseHinder,DR5CT_Dr3ReSwitchLineFB,DR5CT_Dr3SeriousFlt,DR5CT_Dr3SlightFlt;

   bool DR5CT_Dr4EnableFB,DR5CT_Dr4ZeroSpFB,DR5CT_Dr4OpenFB,DR5CT_Dr4NotOandCFB,
   DR5CT_Dr4CloseFB,DR5CT_Dr4OpenHinder,DR5CT_Dr4Safe1FB,DR5CT_Dr4Safe2FB,
   DR5CT_Dr4Closed,DR5CT_Dr4Opened,DR5CT_Dr4EMCunclock,DR5CT_Dr4Cut,
   DR5CT_Dr4CloseHinder,DR5CT_Dr4ReSwitchLineFB,DR5CT_Dr4SeriousFlt,DR5CT_Dr4SlightFlt;

   bool DR5CT_Dr5EnableFB,DR5CT_Dr5ZeroSpFB,DR5CT_Dr5OpenFB,DR5CT_Dr5NotOandCFB,
   DR5CT_Dr5CloseFB,DR5CT_Dr5OpenHinder,DR5CT_Dr5Safe1FB,DR5CT_Dr5Safe2FB,
   DR5CT_Dr5Closed,DR5CT_Dr5Opened,DR5CT_Dr5EMCunclock,DR5CT_Dr5Cut,
   DR5CT_Dr5CloseHinder,DR5CT_Dr5ReSwitchLineFB,DR5CT_Dr5SeriousFlt,DR5CT_Dr5SlightFlt;

   bool DR5CT_Dr6EnableFB,DR5CT_Dr6ZeroSpFB,DR5CT_Dr6OpenFB,DR5CT_Dr6NotOandCFB,
   DR5CT_Dr6CloseFB,DR5CT_Dr6OpenHinder,DR5CT_Dr6Safe1FB,DR5CT_Dr6Safe2FB,
   DR5CT_Dr6Closed,DR5CT_Dr6Opened,DR5CT_Dr6EMCunclock,DR5CT_Dr6Cut,
   DR5CT_Dr6CloseHinder,DR5CT_Dr6ReSwitchLineFB,DR5CT_Dr6SeriousFlt,DR5CT_Dr6SlightFlt;

   bool DR5CT_Dr7EnableFB,DR5CT_Dr7ZeroSpFB,DR5CT_Dr7OpenFB,DR5CT_Dr7NotOandCFB,
   DR5CT_Dr7CloseFB,DR5CT_Dr7OpenHinder,DR5CT_Dr7Safe1FB,DR5CT_Dr7Safe2FB,
   DR5CT_Dr7Closed,DR5CT_Dr7Opened,DR5CT_Dr7EMCunclock,DR5CT_Dr7Cut,
   DR5CT_Dr7CloseHinder,DR5CT_Dr7ReSwitchLineFB,DR5CT_Dr7SeriousFlt,DR5CT_Dr7SlightFlt;

   bool DR5CT_Dr8EnableFB,DR5CT_Dr8ZeroSpFB,DR5CT_Dr8OpenFB,DR5CT_Dr8NotOandCFB,
   DR5CT_Dr8CloseFB,DR5CT_Dr8OpenHinder,DR5CT_Dr8Safe1FB,DR5CT_Dr8Safe2FB,
   DR5CT_Dr8Closed,DR5CT_Dr8Opened,DR5CT_Dr8EMCunclock,DR5CT_Dr8Cut,
   DR5CT_Dr8CloseHinder,DR5CT_Dr8ReSwitchLineFB,DR5CT_Dr8SeriousFlt,DR5CT_Dr8SlightFlt;

   unsigned short int DR5CT_OperationSt;

   bool DR5CT_MDCU1DataValid,DR5CT_MDCU2DataValid,DR5CT_MDCU3DataValid,DR5CT_MDCU4DataValid,
   DR5CT_MDCU5DataValid,DR5CT_MDCU6DataValid,DR5CT_MDCU7DataValid,DR5CT_MDCU8DataValid;
   unsigned short int DR5CT_BusToken,DR5CT_LifeSign;

   bool DR5CT_CANBreak;
   unsigned short int DR5CT_D1Version,DR5CT_D2Version,DR5CT_D3Version,DR5CT_D4Version,
   DR5CT_D5Version,DR5CT_D6Version,DR5CT_D7Version,DR5CT_D8Version;

    //0x760, 0x761, 0x762
   bool DR6CT_Dr1MotoLineBrk,DR6CT_Dr1ClockedInvalid,DR6CT_Dr1ClosedInvalid,DR6CT_Dr1NotUnlockIn3s,
   DR6CT_Dr1PSensorInvalid,DR6CT_Dr1OutClockedPnotAllowed,DR6CT_Dr1SafeRelayFlt,DR6CT_Dr1InterlockFlt,
   DR6CT_Dr1ClockFlt,DR6CT_Dr1CHinderNum,DR6CT_Dr1OHinderNum,DR6CT_Dr1O0OutShort,
   DR6CT_Dr1O1OutShort,DR6CT_Dr1O2OutShort,DR6CT_Dr1O3OutShort,DR6CT_Dr1RomFlt,
   DR6CT_Dr1ComFlt,DR6CT_Dr1AddCodeFlt,DR6CT_Dr1MaintainBtnFlt;

   bool DR6CT_Dr2MotoLineBrk,DR6CT_Dr2ClockedInvalid,DR6CT_Dr2ClosedInvalid,DR6CT_Dr2NotUnlockIn3s,
   DR6CT_Dr2PSensorInvalid,DR6CT_Dr2OutClockedPnotAllowed,DR6CT_Dr2SafeRelayFlt,DR6CT_Dr2InterlockFlt,
   DR6CT_Dr2ClockFlt,DR6CT_Dr2CHinderNum,DR6CT_Dr2OHinderNum,DR6CT_Dr2O0OutShort,
   DR6CT_Dr2O1OutShort,DR6CT_Dr2O2OutShort,DR6CT_Dr2O3OutShort,DR6CT_Dr2RomFlt,
   DR6CT_Dr2ComFlt,DR6CT_Dr2AddCodeFlt,DR6CT_Dr2MaintainBtnFlt;

   bool DR6CT_Dr3MotoLineBrk,DR6CT_Dr3ClockedInvalid,DR6CT_Dr3ClosedInvalid,DR6CT_Dr3NotUnlockIn3s,
   DR6CT_Dr3PSensorInvalid,DR6CT_Dr3OutClockedPnotAllowed,DR6CT_Dr3SafeRelayFlt,DR6CT_Dr3InterlockFlt,
   DR6CT_Dr3ClockFlt,DR6CT_Dr3CHinderNum,DR6CT_Dr3OHinderNum,DR6CT_Dr3O0OutShort,
   DR6CT_Dr3O1OutShort,DR6CT_Dr3O2OutShort,DR6CT_Dr3O3OutShort,DR6CT_Dr3RomFlt,
   DR6CT_Dr3ComFlt,DR6CT_Dr3AddCodeFlt,DR6CT_Dr3MaintainBtnFlt;

   bool DR6CT_Dr4MotoLineBrk,DR6CT_Dr4ClockedInvalid,DR6CT_Dr4ClosedInvalid,DR6CT_Dr4NotUnlockIn3s,
   DR6CT_Dr4PSensorInvalid,DR6CT_Dr4OutClockedPnotAllowed,DR6CT_Dr4SafeRelayFlt,DR6CT_Dr4InterlockFlt,
   DR6CT_Dr4ClockFlt,DR6CT_Dr4CHinderNum,DR6CT_Dr4OHinderNum,DR6CT_Dr4O0OutShort,
   DR6CT_Dr4O1OutShort,DR6CT_Dr4O2OutShort,DR6CT_Dr4O3OutShort,DR6CT_Dr4RomFlt,
   DR6CT_Dr4ComFlt,DR6CT_Dr4AddCodeFlt,DR6CT_Dr4MaintainBtnFlt;

   bool DR6CT_Dr5MotoLineBrk,DR6CT_Dr5ClockedInvalid,DR6CT_Dr5ClosedInvalid,DR6CT_Dr5NotUnlockIn3s,
   DR6CT_Dr5PSensorInvalid,DR6CT_Dr5OutClockedPnotAllowed,DR6CT_Dr5SafeRelayFlt,DR6CT_Dr5InterlockFlt,
   DR6CT_Dr5ClockFlt,DR6CT_Dr5CHinderNum,DR6CT_Dr5OHinderNum,DR6CT_Dr5O0OutShort,
   DR6CT_Dr5O1OutShort,DR6CT_Dr5O2OutShort,DR6CT_Dr5O3OutShort,DR6CT_Dr5RomFlt,
   DR6CT_Dr5ComFlt,DR6CT_Dr5AddCodeFlt,DR6CT_Dr5MaintainBtnFlt;

   bool DR6CT_Dr6MotoLineBrk,DR6CT_Dr6ClockedInvalid,DR6CT_Dr6ClosedInvalid,DR6CT_Dr6NotUnlockIn3s,
   DR6CT_Dr6PSensorInvalid,DR6CT_Dr6OutClockedPnotAllowed,DR6CT_Dr6SafeRelayFlt,DR6CT_Dr6InterlockFlt,
   DR6CT_Dr6ClockFlt,DR6CT_Dr6CHinderNum,DR6CT_Dr6OHinderNum,DR6CT_Dr6O0OutShort,
   DR6CT_Dr6O1OutShort,DR6CT_Dr6O2OutShort,DR6CT_Dr6O3OutShort,DR6CT_Dr6RomFlt,
   DR6CT_Dr6ComFlt,DR6CT_Dr6AddCodeFlt,DR6CT_Dr6MaintainBtnFlt;

   bool DR6CT_Dr7MotoLineBrk,DR6CT_Dr7ClockedInvalid,DR6CT_Dr7ClosedInvalid,DR6CT_Dr7NotUnlockIn3s,
   DR6CT_Dr7PSensorInvalid,DR6CT_Dr7OutClockedPnotAllowed,DR6CT_Dr7SafeRelayFlt,DR6CT_Dr7InterlockFlt,
   DR6CT_Dr7ClockFlt,DR6CT_Dr7CHinderNum,DR6CT_Dr7OHinderNum,DR6CT_Dr7O0OutShort,
   DR6CT_Dr7O1OutShort,DR6CT_Dr7O2OutShort,DR6CT_Dr7O3OutShort,DR6CT_Dr7RomFlt,
   DR6CT_Dr7ComFlt,DR6CT_Dr7AddCodeFlt,DR6CT_Dr7MaintainBtnFlt;

   bool DR6CT_Dr8MotoLineBrk,DR6CT_Dr8ClockedInvalid,DR6CT_Dr8ClosedInvalid,DR6CT_Dr8NotUnlockIn3s,
   DR6CT_Dr8PSensorInvalid,DR6CT_Dr8OutClockedPnotAllowed,DR6CT_Dr8SafeRelayFlt,DR6CT_Dr8InterlockFlt,
   DR6CT_Dr8ClockFlt,DR6CT_Dr8CHinderNum,DR6CT_Dr8OHinderNum,DR6CT_Dr8O0OutShort,
   DR6CT_Dr8O1OutShort,DR6CT_Dr8O2OutShort,DR6CT_Dr8O3OutShort,DR6CT_Dr8RomFlt,
   DR6CT_Dr8ComFlt,DR6CT_Dr8AddCodeFlt,DR6CT_Dr8MaintainBtnFlt;

   bool DR6CT_Dr1EnableFB,DR6CT_Dr1ZeroSpFB,DR6CT_Dr1OpenFB,DR6CT_Dr1NotOandCFB,
   DR6CT_Dr1CloseFB,DR6CT_Dr1OpenHinder,DR6CT_Dr1Safe1FB,DR6CT_Dr1Safe2FB,
   DR6CT_Dr1Closed,DR6CT_Dr1Opened,DR6CT_Dr1EMCunclock,DR6CT_Dr1Cut,
   DR6CT_Dr1CloseHinder,DR6CT_Dr1ReSwitchLineFB,DR6CT_Dr1SeriousFlt,DR6CT_Dr1SlightFlt;

   bool DR6CT_Dr2EnableFB,DR6CT_Dr2ZeroSpFB,DR6CT_Dr2OpenFB,DR6CT_Dr2NotOandCFB,
   DR6CT_Dr2CloseFB,DR6CT_Dr2OpenHinder,DR6CT_Dr2Safe1FB,DR6CT_Dr2Safe2FB,
   DR6CT_Dr2Closed,DR6CT_Dr2Opened,DR6CT_Dr2EMCunclock,DR6CT_Dr2Cut,
   DR6CT_Dr2CloseHinder,DR6CT_Dr2ReSwitchLineFB,DR6CT_Dr2SeriousFlt,DR6CT_Dr2SlightFlt;

   bool DR6CT_Dr3EnableFB,DR6CT_Dr3ZeroSpFB,DR6CT_Dr3OpenFB,DR6CT_Dr3NotOandCFB,
   DR6CT_Dr3CloseFB,DR6CT_Dr3OpenHinder,DR6CT_Dr3Safe1FB,DR6CT_Dr3Safe2FB,
   DR6CT_Dr3Closed,DR6CT_Dr3Opened,DR6CT_Dr3EMCunclock,DR6CT_Dr3Cut,
   DR6CT_Dr3CloseHinder,DR6CT_Dr3ReSwitchLineFB,DR6CT_Dr3SeriousFlt,DR6CT_Dr3SlightFlt;

   bool DR6CT_Dr4EnableFB,DR6CT_Dr4ZeroSpFB,DR6CT_Dr4OpenFB,DR6CT_Dr4NotOandCFB,
   DR6CT_Dr4CloseFB,DR6CT_Dr4OpenHinder,DR6CT_Dr4Safe1FB,DR6CT_Dr4Safe2FB,
   DR6CT_Dr4Closed,DR6CT_Dr4Opened,DR6CT_Dr4EMCunclock,DR6CT_Dr4Cut,
   DR6CT_Dr4CloseHinder,DR6CT_Dr4ReSwitchLineFB,DR6CT_Dr4SeriousFlt,DR6CT_Dr4SlightFlt;

   bool DR6CT_Dr5EnableFB,DR6CT_Dr5ZeroSpFB,DR6CT_Dr5OpenFB,DR6CT_Dr5NotOandCFB,
   DR6CT_Dr5CloseFB,DR6CT_Dr5OpenHinder,DR6CT_Dr5Safe1FB,DR6CT_Dr5Safe2FB,
   DR6CT_Dr5Closed,DR6CT_Dr5Opened,DR6CT_Dr5EMCunclock,DR6CT_Dr5Cut,
   DR6CT_Dr5CloseHinder,DR6CT_Dr5ReSwitchLineFB,DR6CT_Dr5SeriousFlt,DR6CT_Dr5SlightFlt;

   bool DR6CT_Dr6EnableFB,DR6CT_Dr6ZeroSpFB,DR6CT_Dr6OpenFB,DR6CT_Dr6NotOandCFB,
   DR6CT_Dr6CloseFB,DR6CT_Dr6OpenHinder,DR6CT_Dr6Safe1FB,DR6CT_Dr6Safe2FB,
   DR6CT_Dr6Closed,DR6CT_Dr6Opened,DR6CT_Dr6EMCunclock,DR6CT_Dr6Cut,
   DR6CT_Dr6CloseHinder,DR6CT_Dr6ReSwitchLineFB,DR6CT_Dr6SeriousFlt,DR6CT_Dr6SlightFlt;

   bool DR6CT_Dr7EnableFB,DR6CT_Dr7ZeroSpFB,DR6CT_Dr7OpenFB,DR6CT_Dr7NotOandCFB,
   DR6CT_Dr7CloseFB,DR6CT_Dr7OpenHinder,DR6CT_Dr7Safe1FB,DR6CT_Dr7Safe2FB,
   DR6CT_Dr7Closed,DR6CT_Dr7Opened,DR6CT_Dr7EMCunclock,DR6CT_Dr7Cut,
   DR6CT_Dr7CloseHinder,DR6CT_Dr7ReSwitchLineFB,DR6CT_Dr7SeriousFlt,DR6CT_Dr7SlightFlt;

   bool DR6CT_Dr8EnableFB,DR6CT_Dr8ZeroSpFB,DR6CT_Dr8OpenFB,DR6CT_Dr8NotOandCFB,
   DR6CT_Dr8CloseFB,DR6CT_Dr8OpenHinder,DR6CT_Dr8Safe1FB,DR6CT_Dr8Safe2FB,
   DR6CT_Dr8Closed,DR6CT_Dr8Opened,DR6CT_Dr8EMCunclock,DR6CT_Dr8Cut,
   DR6CT_Dr8CloseHinder,DR6CT_Dr8ReSwitchLineFB,DR6CT_Dr8SeriousFlt,DR6CT_Dr8SlightFlt;

   unsigned short int  DR6CT_OperationSt;
   bool DR6CT_MDCU1DataValid,DR6CT_MDCU2DataValid,DR6CT_MDCU3DataValid,DR6CT_MDCU4DataValid,
   DR6CT_MDCU5DataValid,DR6CT_MDCU6DataValid,DR6CT_MDCU7DataValid,DR6CT_MDCU8DataValid;
   unsigned short int  DR6CT_BusToken,DR6CT_LifeSign;
   bool DR6CT_CANBreak;
   unsigned short int DR6CT_D1Version,DR6CT_D2Version,DR6CT_D3Version,DR6CT_D4Version,
   DR6CT_D5Version,DR6CT_D6Version,DR6CT_D7Version,DR6CT_D8Version;

   //0x770, 0x771, 0x772
   bool DR7CT_Dr1MotoLineBrk,DR7CT_Dr1ClockedInvalid,DR7CT_Dr1ClosedInvalid,DR7CT_Dr1NotUnlockIn3s,
   DR7CT_Dr1PSensorInvalid,DR7CT_Dr1OutClockedPnotAllowed,DR7CT_Dr1SafeRelayFlt,DR7CT_Dr1InterlockFlt,
   DR7CT_Dr1ClockFlt,DR7CT_Dr1CHinderNum,DR7CT_Dr1OHinderNum,DR7CT_Dr1O0OutShort,
   DR7CT_Dr1O1OutShort,DR7CT_Dr1O2OutShort,DR7CT_Dr1O3OutShort,DR7CT_Dr1RomFlt,
   DR7CT_Dr1ComFlt,DR7CT_Dr1AddCodeFlt,DR7CT_Dr1MaintainBtnFlt;

   bool DR7CT_Dr2MotoLineBrk,DR7CT_Dr2ClockedInvalid,DR7CT_Dr2ClosedInvalid,DR7CT_Dr2NotUnlockIn3s,
   DR7CT_Dr2PSensorInvalid,DR7CT_Dr2OutClockedPnotAllowed,DR7CT_Dr2SafeRelayFlt,DR7CT_Dr2InterlockFlt,
   DR7CT_Dr2ClockFlt,DR7CT_Dr2CHinderNum,DR7CT_Dr2OHinderNum,DR7CT_Dr2O0OutShort,
   DR7CT_Dr2O1OutShort,DR7CT_Dr2O2OutShort,DR7CT_Dr2O3OutShort,DR7CT_Dr2RomFlt,
   DR7CT_Dr2ComFlt,DR7CT_Dr2AddCodeFlt,DR7CT_Dr2MaintainBtnFlt;

   bool DR7CT_Dr3MotoLineBrk,DR7CT_Dr3ClockedInvalid,DR7CT_Dr3ClosedInvalid,DR7CT_Dr3NotUnlockIn3s,
   DR7CT_Dr3PSensorInvalid,DR7CT_Dr3OutClockedPnotAllowed,DR7CT_Dr3SafeRelayFlt,DR7CT_Dr3InterlockFlt,
   DR7CT_Dr3ClockFlt,DR7CT_Dr3CHinderNum,DR7CT_Dr3OHinderNum,DR7CT_Dr3O0OutShort,
   DR7CT_Dr3O1OutShort,DR7CT_Dr3O2OutShort,DR7CT_Dr3O3OutShort,DR7CT_Dr3RomFlt,
   DR7CT_Dr3ComFlt,DR7CT_Dr3AddCodeFlt,DR7CT_Dr3MaintainBtnFlt;

   bool DR7CT_Dr4MotoLineBrk,DR7CT_Dr4ClockedInvalid,DR7CT_Dr4ClosedInvalid,DR7CT_Dr4NotUnlockIn3s,
   DR7CT_Dr4PSensorInvalid,DR7CT_Dr4OutClockedPnotAllowed,DR7CT_Dr4SafeRelayFlt,DR7CT_Dr4InterlockFlt,
   DR7CT_Dr4ClockFlt,DR7CT_Dr4CHinderNum,DR7CT_Dr4OHinderNum,DR7CT_Dr4O0OutShort,
   DR7CT_Dr4O1OutShort,DR7CT_Dr4O2OutShort,DR7CT_Dr4O3OutShort,DR7CT_Dr4RomFlt,
   DR7CT_Dr4ComFlt,DR7CT_Dr4AddCodeFlt,DR7CT_Dr4MaintainBtnFlt;

   bool DR7CT_Dr5MotoLineBrk,DR7CT_Dr5ClockedInvalid,DR7CT_Dr5ClosedInvalid,DR7CT_Dr5NotUnlockIn3s,
   DR7CT_Dr5PSensorInvalid,DR7CT_Dr5OutClockedPnotAllowed,DR7CT_Dr5SafeRelayFlt,DR7CT_Dr5InterlockFlt,
   DR7CT_Dr5ClockFlt,DR7CT_Dr5CHinderNum,DR7CT_Dr5OHinderNum,DR7CT_Dr5O0OutShort,
   DR7CT_Dr5O1OutShort,DR7CT_Dr5O2OutShort,DR7CT_Dr5O3OutShort,DR7CT_Dr5RomFlt,
   DR7CT_Dr5ComFlt,DR7CT_Dr5AddCodeFlt,DR7CT_Dr5MaintainBtnFlt;

   bool DR7CT_Dr6MotoLineBrk,DR7CT_Dr6ClockedInvalid,DR7CT_Dr6ClosedInvalid,DR7CT_Dr6NotUnlockIn3s,
   DR7CT_Dr6PSensorInvalid,DR7CT_Dr6OutClockedPnotAllowed,DR7CT_Dr6SafeRelayFlt,DR7CT_Dr6InterlockFlt,
   DR7CT_Dr6ClockFlt,DR7CT_Dr6CHinderNum,DR7CT_Dr6OHinderNum,DR7CT_Dr6O0OutShort,
   DR7CT_Dr6O1OutShort,DR7CT_Dr6O2OutShort,DR7CT_Dr6O3OutShort,DR7CT_Dr6RomFlt,
   DR7CT_Dr6ComFlt,DR7CT_Dr6AddCodeFlt,DR7CT_Dr6MaintainBtnFlt;

   bool DR7CT_Dr7MotoLineBrk,DR7CT_Dr7ClockedInvalid,DR7CT_Dr7ClosedInvalid,DR7CT_Dr7NotUnlockIn3s,
   DR7CT_Dr7PSensorInvalid,DR7CT_Dr7OutClockedPnotAllowed,DR7CT_Dr7SafeRelayFlt,DR7CT_Dr7InterlockFlt,
   DR7CT_Dr7ClockFlt,DR7CT_Dr7CHinderNum,DR7CT_Dr7OHinderNum,DR7CT_Dr7O0OutShort,
   DR7CT_Dr7O1OutShort,DR7CT_Dr7O2OutShort,DR7CT_Dr7O3OutShort,DR7CT_Dr7RomFlt,
   DR7CT_Dr7ComFlt,DR7CT_Dr7AddCodeFlt,DR7CT_Dr7MaintainBtnFlt;

   bool DR7CT_Dr8MotoLineBrk,DR7CT_Dr8ClockedInvalid,DR7CT_Dr8ClosedInvalid,DR7CT_Dr8NotUnlockIn3s,
   DR7CT_Dr8PSensorInvalid,DR7CT_Dr8OutClockedPnotAllowed,DR7CT_Dr8SafeRelayFlt,DR7CT_Dr8InterlockFlt,
   DR7CT_Dr8ClockFlt,DR7CT_Dr8CHinderNum,DR7CT_Dr8OHinderNum,DR7CT_Dr8O0OutShort,
   DR7CT_Dr8O1OutShort,DR7CT_Dr8O2OutShort,DR7CT_Dr8O3OutShort,DR7CT_Dr8RomFlt,
   DR7CT_Dr8ComFlt,DR7CT_Dr8AddCodeFlt,DR7CT_Dr8MaintainBtnFlt;

   bool DR7CT_Dr1EnableFB,DR7CT_Dr1ZeroSpFB,DR7CT_Dr1OpenFB,DR7CT_Dr1NotOandCFB,
   DR7CT_Dr1CloseFB,DR7CT_Dr1OpenHinder,DR7CT_Dr1Safe1FB,DR7CT_Dr1Safe2FB,
   DR7CT_Dr1Closed,DR7CT_Dr1Opened,DR7CT_Dr1EMCunclock,DR7CT_Dr1Cut,
   DR7CT_Dr1CloseHinder,DR7CT_Dr1ReSwitchLineFB,DR7CT_Dr1SeriousFlt,DR7CT_Dr1SlightFlt;

   bool DR7CT_Dr2EnableFB,DR7CT_Dr2ZeroSpFB,DR7CT_Dr2OpenFB,DR7CT_Dr2NotOandCFB,
   DR7CT_Dr2CloseFB,DR7CT_Dr2OpenHinder,DR7CT_Dr2Safe1FB,DR7CT_Dr2Safe2FB,
   DR7CT_Dr2Closed,DR7CT_Dr2Opened,DR7CT_Dr2EMCunclock,DR7CT_Dr2Cut,
   DR7CT_Dr2CloseHinder,DR7CT_Dr2ReSwitchLineFB,DR7CT_Dr2SeriousFlt,DR7CT_Dr2SlightFlt;

   bool DR7CT_Dr3EnableFB,DR7CT_Dr3ZeroSpFB,DR7CT_Dr3OpenFB,DR7CT_Dr3NotOandCFB,
   DR7CT_Dr3CloseFB,DR7CT_Dr3OpenHinder,DR7CT_Dr3Safe1FB,DR7CT_Dr3Safe2FB,
   DR7CT_Dr3Closed,DR7CT_Dr3Opened,DR7CT_Dr3EMCunclock,DR7CT_Dr3Cut,
   DR7CT_Dr3CloseHinder,DR7CT_Dr3ReSwitchLineFB,DR7CT_Dr3SeriousFlt,DR7CT_Dr3SlightFlt;

   bool DR7CT_Dr4EnableFB,DR7CT_Dr4ZeroSpFB,DR7CT_Dr4OpenFB,DR7CT_Dr4NotOandCFB,
   DR7CT_Dr4CloseFB,DR7CT_Dr4OpenHinder,DR7CT_Dr4Safe1FB,DR7CT_Dr4Safe2FB,
   DR7CT_Dr4Closed,DR7CT_Dr4Opened,DR7CT_Dr4EMCunclock,DR7CT_Dr4Cut,
   DR7CT_Dr4CloseHinder,DR7CT_Dr4ReSwitchLineFB,DR7CT_Dr4SeriousFlt,DR7CT_Dr4SlightFlt;

   bool DR7CT_Dr5EnableFB,DR7CT_Dr5ZeroSpFB,DR7CT_Dr5OpenFB,DR7CT_Dr5NotOandCFB,
   DR7CT_Dr5CloseFB,DR7CT_Dr5OpenHinder,DR7CT_Dr5Safe1FB,DR7CT_Dr5Safe2FB,
   DR7CT_Dr5Closed,DR7CT_Dr5Opened,DR7CT_Dr5EMCunclock,DR7CT_Dr5Cut,
   DR7CT_Dr5CloseHinder,DR7CT_Dr5ReSwitchLineFB,DR7CT_Dr5SeriousFlt,DR7CT_Dr5SlightFlt;

   bool DR7CT_Dr6EnableFB,DR7CT_Dr6ZeroSpFB,DR7CT_Dr6OpenFB,DR7CT_Dr6NotOandCFB,
   DR7CT_Dr6CloseFB,DR7CT_Dr6OpenHinder,DR7CT_Dr6Safe1FB,DR7CT_Dr6Safe2FB,
   DR7CT_Dr6Closed,DR7CT_Dr6Opened,DR7CT_Dr6EMCunclock,DR7CT_Dr6Cut,
   DR7CT_Dr6CloseHinder,DR7CT_Dr6ReSwitchLineFB,DR7CT_Dr6SeriousFlt,DR7CT_Dr6SlightFlt;

   bool DR7CT_Dr7EnableFB,DR7CT_Dr7ZeroSpFB,DR7CT_Dr7OpenFB,DR7CT_Dr7NotOandCFB,
   DR7CT_Dr7CloseFB,DR7CT_Dr7OpenHinder,DR7CT_Dr7Safe1FB,DR7CT_Dr7Safe2FB,
   DR7CT_Dr7Closed,DR7CT_Dr7Opened,DR7CT_Dr7EMCunclock,DR7CT_Dr7Cut,
   DR7CT_Dr7CloseHinder,DR7CT_Dr7ReSwitchLineFB,DR7CT_Dr7SeriousFlt,DR7CT_Dr7SlightFlt;

   bool DR7CT_Dr8EnableFB,DR7CT_Dr8ZeroSpFB,DR7CT_Dr8OpenFB,DR7CT_Dr8NotOandCFB,
   DR7CT_Dr8CloseFB,DR7CT_Dr8OpenHinder,DR7CT_Dr8Safe1FB,DR7CT_Dr8Safe2FB,
   DR7CT_Dr8Closed,DR7CT_Dr8Opened,DR7CT_Dr8EMCunclock,DR7CT_Dr8Cut,
   DR7CT_Dr8CloseHinder,DR7CT_Dr8ReSwitchLineFB,DR7CT_Dr8SeriousFlt,DR7CT_Dr8SlightFlt;

   unsigned short int DR7CT_OperationSt;
   bool DR7CT_MDCU1DataValid,DR7CT_MDCU2DataValid,DR7CT_MDCU3DataValid,DR7CT_MDCU4DataValid,
   DR7CT_MDCU5DataValid,DR7CT_MDCU6DataValid,DR7CT_MDCU7DataValid,DR7CT_MDCU8DataValid;

   unsigned short int DR7CT_BusToken,DR7CT_LifeSign;

   bool DR7CT_CANBreak;
   unsigned short int DR7CT_D1Version,DR7CT_D2Version,DR7CT_D3Version,DR7CT_D4Version,
   DR7CT_D5Version,DR7CT_D6Version,DR7CT_D7Version,DR7CT_D8Version;

   //0x780, 0x781, 0x782
   bool DR8CT_Dr1MotoLineBrk,DR8CT_Dr1ClockedInvalid,DR8CT_Dr1ClosedInvalid,DR8CT_Dr1NotUnlockIn3s,
   DR8CT_Dr1PSensorInvalid,DR8CT_Dr1OutClockedPnotAllowed,DR8CT_Dr1SafeRelayFlt,DR8CT_Dr1InterlockFlt,
   DR8CT_Dr1ClockFlt,DR8CT_Dr1CHinderNum,DR8CT_Dr1OHinderNum,DR8CT_Dr1O0OutShort,
   DR8CT_Dr1O1OutShort,DR8CT_Dr1O2OutShort,DR8CT_Dr1O3OutShort,DR8CT_Dr1RomFlt,
   DR8CT_Dr1ComFlt,DR8CT_Dr1AddCodeFlt,DR8CT_Dr1MaintainBtnFlt;

   bool DR8CT_Dr2MotoLineBrk,DR8CT_Dr2ClockedInvalid,DR8CT_Dr2ClosedInvalid,DR8CT_Dr2NotUnlockIn3s,
   DR8CT_Dr2PSensorInvalid,DR8CT_Dr2OutClockedPnotAllowed,DR8CT_Dr2SafeRelayFlt,DR8CT_Dr2InterlockFlt,
   DR8CT_Dr2ClockFlt,DR8CT_Dr2CHinderNum,DR8CT_Dr2OHinderNum,DR8CT_Dr2O0OutShort,
   DR8CT_Dr2O1OutShort,DR8CT_Dr2O2OutShort,DR8CT_Dr2O3OutShort,DR8CT_Dr2RomFlt,
   DR8CT_Dr2ComFlt,DR8CT_Dr2AddCodeFlt,DR8CT_Dr2MaintainBtnFlt;

   bool DR8CT_Dr3MotoLineBrk,DR8CT_Dr3ClockedInvalid,DR8CT_Dr3ClosedInvalid,DR8CT_Dr3NotUnlockIn3s,
   DR8CT_Dr3PSensorInvalid,DR8CT_Dr3OutClockedPnotAllowed,DR8CT_Dr3SafeRelayFlt,DR8CT_Dr3InterlockFlt,
   DR8CT_Dr3ClockFlt,DR8CT_Dr3CHinderNum,DR8CT_Dr3OHinderNum,DR8CT_Dr3O0OutShort,
   DR8CT_Dr3O1OutShort,DR8CT_Dr3O2OutShort,DR8CT_Dr3O3OutShort,DR8CT_Dr3RomFlt,
   DR8CT_Dr3ComFlt,DR8CT_Dr3AddCodeFlt,DR8CT_Dr3MaintainBtnFlt;

   bool DR8CT_Dr4MotoLineBrk,DR8CT_Dr4ClockedInvalid,DR8CT_Dr4ClosedInvalid,DR8CT_Dr4NotUnlockIn3s,
   DR8CT_Dr4PSensorInvalid,DR8CT_Dr4OutClockedPnotAllowed,DR8CT_Dr4SafeRelayFlt,DR8CT_Dr4InterlockFlt,
   DR8CT_Dr4ClockFlt,DR8CT_Dr4CHinderNum,DR8CT_Dr4OHinderNum,DR8CT_Dr4O0OutShort,
   DR8CT_Dr4O1OutShort,DR8CT_Dr4O2OutShort,DR8CT_Dr4O3OutShort,DR8CT_Dr4RomFlt,
   DR8CT_Dr4ComFlt,DR8CT_Dr4AddCodeFlt,DR8CT_Dr4MaintainBtnFlt;

   bool DR8CT_Dr5MotoLineBrk,DR8CT_Dr5ClockedInvalid,DR8CT_Dr5ClosedInvalid,DR8CT_Dr5NotUnlockIn3s,
   DR8CT_Dr5PSensorInvalid,DR8CT_Dr5OutClockedPnotAllowed,DR8CT_Dr5SafeRelayFlt,DR8CT_Dr5InterlockFlt,
   DR8CT_Dr5ClockFlt,DR8CT_Dr5CHinderNum,DR8CT_Dr5OHinderNum,DR8CT_Dr5O0OutShort,
   DR8CT_Dr5O1OutShort,DR8CT_Dr5O2OutShort,DR8CT_Dr5O3OutShort,DR8CT_Dr5RomFlt,
   DR8CT_Dr5ComFlt,DR8CT_Dr5AddCodeFlt,DR8CT_Dr5MaintainBtnFlt;

   bool DR8CT_Dr6MotoLineBrk,DR8CT_Dr6ClockedInvalid,DR8CT_Dr6ClosedInvalid,DR8CT_Dr6NotUnlockIn3s,
   DR8CT_Dr6PSensorInvalid,DR8CT_Dr6OutClockedPnotAllowed,DR8CT_Dr6SafeRelayFlt,DR8CT_Dr6InterlockFlt,
   DR8CT_Dr6ClockFlt,DR8CT_Dr6CHinderNum,DR8CT_Dr6OHinderNum,DR8CT_Dr6O0OutShort,
   DR8CT_Dr6O1OutShort,DR8CT_Dr6O2OutShort,DR8CT_Dr6O3OutShort,DR8CT_Dr6RomFlt,
   DR8CT_Dr6ComFlt,DR8CT_Dr6AddCodeFlt,DR8CT_Dr6MaintainBtnFlt;

   bool DR8CT_Dr7MotoLineBrk,DR8CT_Dr7ClockedInvalid,DR8CT_Dr7ClosedInvalid,DR8CT_Dr7NotUnlockIn3s,
   DR8CT_Dr7PSensorInvalid,DR8CT_Dr7OutClockedPnotAllowed,DR8CT_Dr7SafeRelayFlt,DR8CT_Dr7InterlockFlt,
   DR8CT_Dr7ClockFlt,DR8CT_Dr7CHinderNum,DR8CT_Dr7OHinderNum,DR8CT_Dr7O0OutShort,
   DR8CT_Dr7O1OutShort,DR8CT_Dr7O2OutShort,DR8CT_Dr7O3OutShort,DR8CT_Dr7RomFlt,
   DR8CT_Dr7ComFlt,DR8CT_Dr7AddCodeFlt,DR8CT_Dr7MaintainBtnFlt;

   bool DR8CT_Dr8MotoLineBrk,DR8CT_Dr8ClockedInvalid,DR8CT_Dr8ClosedInvalid,DR8CT_Dr8NotUnlockIn3s,
   DR8CT_Dr8PSensorInvalid,DR8CT_Dr8OutClockedPnotAllowed,DR8CT_Dr8SafeRelayFlt,DR8CT_Dr8InterlockFlt,
   DR8CT_Dr8ClockFlt,DR8CT_Dr8CHinderNum,DR8CT_Dr8OHinderNum,DR8CT_Dr8O0OutShort,
   DR8CT_Dr8O1OutShort,DR8CT_Dr8O2OutShort,DR8CT_Dr8O3OutShort,DR8CT_Dr8RomFlt,
   DR8CT_Dr8ComFlt,DR8CT_Dr8AddCodeFlt,DR8CT_Dr8MaintainBtnFlt;

   bool DR8CT_Dr1EnableFB,DR8CT_Dr1ZeroSpFB,DR8CT_Dr1OpenFB,DR8CT_Dr1NotOandCFB,
   DR8CT_Dr1CloseFB,DR8CT_Dr1OpenHinder,DR8CT_Dr1Safe1FB,DR8CT_Dr1Safe2FB,
   DR8CT_Dr1Closed,DR8CT_Dr1Opened,DR8CT_Dr1EMCunclock,DR8CT_Dr1Cut,
   DR8CT_Dr1CloseHinder,DR8CT_Dr1ReSwitchLineFB,DR8CT_Dr1SeriousFlt,DR8CT_Dr1SlightFlt;

   bool DR8CT_Dr2EnableFB,DR8CT_Dr2ZeroSpFB,DR8CT_Dr2OpenFB,DR8CT_Dr2NotOandCFB,
   DR8CT_Dr2CloseFB,DR8CT_Dr2OpenHinder,DR8CT_Dr2Safe1FB,DR8CT_Dr2Safe2FB,
   DR8CT_Dr2Closed,DR8CT_Dr2Opened,DR8CT_Dr2EMCunclock,DR8CT_Dr2Cut,
   DR8CT_Dr2CloseHinder,DR8CT_Dr2ReSwitchLineFB,DR8CT_Dr2SeriousFlt,DR8CT_Dr2SlightFlt;

   bool DR8CT_Dr3EnableFB,DR8CT_Dr3ZeroSpFB,DR8CT_Dr3OpenFB,DR8CT_Dr3NotOandCFB,
   DR8CT_Dr3CloseFB,DR8CT_Dr3OpenHinder,DR8CT_Dr3Safe1FB,DR8CT_Dr3Safe2FB,
   DR8CT_Dr3Closed,DR8CT_Dr3Opened,DR8CT_Dr3EMCunclock,DR8CT_Dr3Cut,
   DR8CT_Dr3CloseHinder,DR8CT_Dr3ReSwitchLineFB,DR8CT_Dr3SeriousFlt,DR8CT_Dr3SlightFlt;

   bool DR8CT_Dr4EnableFB,DR8CT_Dr4ZeroSpFB,DR8CT_Dr4OpenFB,DR8CT_Dr4NotOandCFB,
   DR8CT_Dr4CloseFB,DR8CT_Dr4OpenHinder,DR8CT_Dr4Safe1FB,DR8CT_Dr4Safe2FB,
   DR8CT_Dr4Closed,DR8CT_Dr4Opened,DR8CT_Dr4EMCunclock,DR8CT_Dr4Cut,
   DR8CT_Dr4CloseHinder,DR8CT_Dr4ReSwitchLineFB,DR8CT_Dr4SeriousFlt,DR8CT_Dr4SlightFlt;

   bool DR8CT_Dr5EnableFB,DR8CT_Dr5ZeroSpFB,DR8CT_Dr5OpenFB,DR8CT_Dr5NotOandCFB,
   DR8CT_Dr5CloseFB,DR8CT_Dr5OpenHinder,DR8CT_Dr5Safe1FB,DR8CT_Dr5Safe2FB,
   DR8CT_Dr5Closed,DR8CT_Dr5Opened,DR8CT_Dr5EMCunclock,DR8CT_Dr5Cut,
   DR8CT_Dr5CloseHinder,DR8CT_Dr5ReSwitchLineFB,DR8CT_Dr5SeriousFlt,DR8CT_Dr5SlightFlt;

   bool DR8CT_Dr6EnableFB,DR8CT_Dr6ZeroSpFB,DR8CT_Dr6OpenFB,DR8CT_Dr6NotOandCFB,
   DR8CT_Dr6CloseFB,DR8CT_Dr6OpenHinder,DR8CT_Dr6Safe1FB,DR8CT_Dr6Safe2FB,
   DR8CT_Dr6Closed,DR8CT_Dr6Opened,DR8CT_Dr6EMCunclock,DR8CT_Dr6Cut,
   DR8CT_Dr6CloseHinder,DR8CT_Dr6ReSwitchLineFB,DR8CT_Dr6SeriousFlt,DR8CT_Dr6SlightFlt;

   bool DR8CT_Dr7EnableFB,DR8CT_Dr7ZeroSpFB,DR8CT_Dr7OpenFB,DR8CT_Dr7NotOandCFB,
   DR8CT_Dr7CloseFB,DR8CT_Dr7OpenHinder,DR8CT_Dr7Safe1FB,DR8CT_Dr7Safe2FB,
   DR8CT_Dr7Closed,DR8CT_Dr7Opened,DR8CT_Dr7EMCunclock,DR8CT_Dr7Cut,
   DR8CT_Dr7CloseHinder,DR8CT_Dr7ReSwitchLineFB,DR8CT_Dr7SeriousFlt,DR8CT_Dr7SlightFlt;

   bool DR8CT_Dr8EnableFB,DR8CT_Dr8ZeroSpFB,DR8CT_Dr8OpenFB,DR8CT_Dr8NotOandCFB,
   DR8CT_Dr8CloseFB,DR8CT_Dr8OpenHinder,DR8CT_Dr8Safe1FB,DR8CT_Dr8Safe2FB,
   DR8CT_Dr8Closed,DR8CT_Dr8Opened,DR8CT_Dr8EMCunclock,DR8CT_Dr8Cut,
   DR8CT_Dr8CloseHinder,DR8CT_Dr8ReSwitchLineFB,DR8CT_Dr8SeriousFlt,DR8CT_Dr8SlightFlt;

   unsigned short int DR8CT_OperationSt;

   bool DR8CT_MDCU1DataValid,DR8CT_MDCU2DataValid,DR8CT_MDCU3DataValid,DR8CT_MDCU4DataValid,
   DR8CT_MDCU5DataValid,DR8CT_MDCU6DataValid,DR8CT_MDCU7DataValid,DR8CT_MDCU8DataValid;

   unsigned short int DR8CT_BusToken,DR8CT_LifeSign;
   bool DR8CT_CANBreak;
   unsigned short int DR8CT_D1Version,DR8CT_D2Version,DR8CT_D3Version,
   DR8CT_D4Version,DR8CT_D5Version,DR8CT_D6Version,DR8CT_D7Version,DR8CT_D8Version;

   //0x790, 0x791, 0x792
   bool DR9CT_Dr1MotoLineBrk,DR9CT_Dr1ClockedInvalid,DR9CT_Dr1ClosedInvalid,DR9CT_Dr1NotUnlockIn3s,
   DR9CT_Dr1PSensorInvalid,DR9CT_Dr1OutClockedPnotAllowed,DR9CT_Dr1SafeRelayFlt,DR9CT_Dr1InterlockFlt,
   DR9CT_Dr1ClockFlt,DR9CT_Dr1CHinderNum,DR9CT_Dr1OHinderNum,DR9CT_Dr1O0OutShort,
   DR9CT_Dr1O1OutShort,DR9CT_Dr1O2OutShort,DR9CT_Dr1O3OutShort,DR9CT_Dr1RomFlt,
   DR9CT_Dr1ComFlt,DR9CT_Dr1AddCodeFlt,DR9CT_Dr1MaintainBtnFlt;
   bool DR9CT_Dr2MotoLineBrk,DR9CT_Dr2ClockedInvalid,DR9CT_Dr2ClosedInvalid,DR9CT_Dr2NotUnlockIn3s,
   DR9CT_Dr2PSensorInvalid,DR9CT_Dr2OutClockedPnotAllowed,DR9CT_Dr2SafeRelayFlt,DR9CT_Dr2InterlockFlt,
   DR9CT_Dr2ClockFlt,DR9CT_Dr2CHinderNum,DR9CT_Dr2OHinderNum,DR9CT_Dr2O0OutShort,
   DR9CT_Dr2O1OutShort,DR9CT_Dr2O2OutShort,DR9CT_Dr2O3OutShort,DR9CT_Dr2RomFlt,
   DR9CT_Dr2ComFlt,DR9CT_Dr2AddCodeFlt,DR9CT_Dr2MaintainBtnFlt;

   bool DR9CT_Dr3MotoLineBrk,DR9CT_Dr3ClockedInvalid,DR9CT_Dr3ClosedInvalid,DR9CT_Dr3NotUnlockIn3s,
   DR9CT_Dr3PSensorInvalid,DR9CT_Dr3OutClockedPnotAllowed,DR9CT_Dr3SafeRelayFlt,DR9CT_Dr3InterlockFlt,
   DR9CT_Dr3ClockFlt,DR9CT_Dr3CHinderNum,DR9CT_Dr3OHinderNum,DR9CT_Dr3O0OutShort,
   DR9CT_Dr3O1OutShort,DR9CT_Dr3O2OutShort,DR9CT_Dr3O3OutShort,DR9CT_Dr3RomFlt,
   DR9CT_Dr3ComFlt,DR9CT_Dr3AddCodeFlt,DR9CT_Dr3MaintainBtnFlt;

   bool DR9CT_Dr4MotoLineBrk,DR9CT_Dr4ClockedInvalid,DR9CT_Dr4ClosedInvalid,DR9CT_Dr4NotUnlockIn3s,
   DR9CT_Dr4PSensorInvalid,DR9CT_Dr4OutClockedPnotAllowed,DR9CT_Dr4SafeRelayFlt,DR9CT_Dr4InterlockFlt,
   DR9CT_Dr4ClockFlt,DR9CT_Dr4CHinderNum,DR9CT_Dr4OHinderNum,DR9CT_Dr4O0OutShort,
   DR9CT_Dr4O1OutShort,DR9CT_Dr4O2OutShort,DR9CT_Dr4O3OutShort,DR9CT_Dr4RomFlt,
   DR9CT_Dr4ComFlt,DR9CT_Dr4AddCodeFlt,DR9CT_Dr4MaintainBtnFlt;
   bool DR9CT_Dr5MotoLineBrk,DR9CT_Dr5ClockedInvalid,DR9CT_Dr5ClosedInvalid,DR9CT_Dr5NotUnlockIn3s,
   DR9CT_Dr5PSensorInvalid,DR9CT_Dr5OutClockedPnotAllowed,DR9CT_Dr5SafeRelayFlt,DR9CT_Dr5InterlockFlt,
   DR9CT_Dr5ClockFlt,DR9CT_Dr5CHinderNum,DR9CT_Dr5OHinderNum,DR9CT_Dr5O0OutShort,
   DR9CT_Dr5O1OutShort,DR9CT_Dr5O2OutShort,DR9CT_Dr5O3OutShort,DR9CT_Dr5RomFlt,
   DR9CT_Dr5ComFlt,DR9CT_Dr5AddCodeFlt,DR9CT_Dr5MaintainBtnFlt;

   bool DR9CT_Dr6MotoLineBrk,DR9CT_Dr6ClockedInvalid,DR9CT_Dr6ClosedInvalid,DR9CT_Dr6NotUnlockIn3s,
   DR9CT_Dr6PSensorInvalid,DR9CT_Dr6OutClockedPnotAllowed,DR9CT_Dr6SafeRelayFlt,DR9CT_Dr6InterlockFlt,
   DR9CT_Dr6ClockFlt,DR9CT_Dr6CHinderNum,DR9CT_Dr6OHinderNum,DR9CT_Dr6O0OutShort,
   DR9CT_Dr6O1OutShort,DR9CT_Dr6O2OutShort,DR9CT_Dr6O3OutShort,DR9CT_Dr6RomFlt,
   DR9CT_Dr6ComFlt,DR9CT_Dr6AddCodeFlt,DR9CT_Dr6MaintainBtnFlt;

   bool DR9CT_Dr7MotoLineBrk,DR9CT_Dr7ClockedInvalid,DR9CT_Dr7ClosedInvalid,DR9CT_Dr7NotUnlockIn3s,
   DR9CT_Dr7PSensorInvalid,DR9CT_Dr7OutClockedPnotAllowed,DR9CT_Dr7SafeRelayFlt,DR9CT_Dr7InterlockFlt,
   DR9CT_Dr7ClockFlt,DR9CT_Dr7CHinderNum,DR9CT_Dr7OHinderNum,DR9CT_Dr7O0OutShort,
   DR9CT_Dr7O1OutShort,DR9CT_Dr7O2OutShort,DR9CT_Dr7O3OutShort,DR9CT_Dr7RomFlt,
   DR9CT_Dr7ComFlt,DR9CT_Dr7AddCodeFlt,DR9CT_Dr7MaintainBtnFlt;

   bool DR9CT_Dr8MotoLineBrk,DR9CT_Dr8ClockedInvalid,DR9CT_Dr8ClosedInvalid,DR9CT_Dr8NotUnlockIn3s,
   DR9CT_Dr8PSensorInvalid,DR9CT_Dr8OutClockedPnotAllowed,DR9CT_Dr8SafeRelayFlt,DR9CT_Dr8InterlockFlt,
   DR9CT_Dr8ClockFlt,DR9CT_Dr8CHinderNum,DR9CT_Dr8OHinderNum,DR9CT_Dr8O0OutShort,
   DR9CT_Dr8O1OutShort,DR9CT_Dr8O2OutShort,DR9CT_Dr8O3OutShort,DR9CT_Dr8RomFlt,
   DR9CT_Dr8ComFlt,DR9CT_Dr8AddCodeFlt,DR9CT_Dr8MaintainBtnFlt;

   bool DR9CT_Dr1EnableFB,DR9CT_Dr1ZeroSpFB,DR9CT_Dr1OpenFB,DR9CT_Dr1NotOandCFB,
   DR9CT_Dr1CloseFB,DR9CT_Dr1OpenHinder,DR9CT_Dr1Safe1FB,DR9CT_Dr1Safe2FB,
   DR9CT_Dr1Closed,DR9CT_Dr1Opened,DR9CT_Dr1EMCunclock,DR9CT_Dr1Cut,
   DR9CT_Dr1CloseHinder,DR9CT_Dr1ReSwitchLineFB,DR9CT_Dr1SeriousFlt,DR9CT_Dr1SlightFlt;

   bool DR9CT_Dr2EnableFB,DR9CT_Dr2ZeroSpFB,DR9CT_Dr2OpenFB,DR9CT_Dr2NotOandCFB,
   DR9CT_Dr2CloseFB,DR9CT_Dr2OpenHinder,DR9CT_Dr2Safe1FB,DR9CT_Dr2Safe2FB,
   DR9CT_Dr2Closed,DR9CT_Dr2Opened,DR9CT_Dr2EMCunclock,DR9CT_Dr2Cut,
   DR9CT_Dr2CloseHinder,DR9CT_Dr2ReSwitchLineFB,DR9CT_Dr2SeriousFlt,DR9CT_Dr2SlightFlt;

   bool DR9CT_Dr3EnableFB,DR9CT_Dr3ZeroSpFB,DR9CT_Dr3OpenFB,DR9CT_Dr3NotOandCFB,
   DR9CT_Dr3CloseFB,DR9CT_Dr3OpenHinder,DR9CT_Dr3Safe1FB,DR9CT_Dr3Safe2FB,
   DR9CT_Dr3Closed,DR9CT_Dr3Opened,DR9CT_Dr3EMCunclock,DR9CT_Dr3Cut,
   DR9CT_Dr3CloseHinder,DR9CT_Dr3ReSwitchLineFB,DR9CT_Dr3SeriousFlt,DR9CT_Dr3SlightFlt;

   bool DR9CT_Dr4EnableFB,DR9CT_Dr4ZeroSpFB,DR9CT_Dr4OpenFB,DR9CT_Dr4NotOandCFB,
   DR9CT_Dr4CloseFB,DR9CT_Dr4OpenHinder,DR9CT_Dr4Safe1FB,DR9CT_Dr4Safe2FB,
   DR9CT_Dr4Closed,DR9CT_Dr4Opened,DR9CT_Dr4EMCunclock,DR9CT_Dr4Cut,
   DR9CT_Dr4CloseHinder,DR9CT_Dr4ReSwitchLineFB,DR9CT_Dr4SeriousFlt,DR9CT_Dr4SlightFlt;

   bool DR9CT_Dr5EnableFB,DR9CT_Dr5ZeroSpFB,DR9CT_Dr5OpenFB,DR9CT_Dr5NotOandCFB,
   DR9CT_Dr5CloseFB,DR9CT_Dr5OpenHinder,DR9CT_Dr5Safe1FB,DR9CT_Dr5Safe2FB,
   DR9CT_Dr5Closed,DR9CT_Dr5Opened,DR9CT_Dr5EMCunclock,DR9CT_Dr5Cut,
   DR9CT_Dr5CloseHinder,DR9CT_Dr5ReSwitchLineFB,DR9CT_Dr5SeriousFlt,DR9CT_Dr5SlightFlt;

   bool DR9CT_Dr6EnableFB,DR9CT_Dr6ZeroSpFB,DR9CT_Dr6OpenFB,DR9CT_Dr6NotOandCFB,
   DR9CT_Dr6CloseFB,DR9CT_Dr6OpenHinder,DR9CT_Dr6Safe1FB,DR9CT_Dr6Safe2FB,
   DR9CT_Dr6Closed,DR9CT_Dr6Opened,DR9CT_Dr6EMCunclock,DR9CT_Dr6Cut,
   DR9CT_Dr6CloseHinder,DR9CT_Dr6ReSwitchLineFB,DR9CT_Dr6SeriousFlt,DR9CT_Dr6SlightFlt;

   bool DR9CT_Dr7EnableFB,DR9CT_Dr7ZeroSpFB,DR9CT_Dr7OpenFB,DR9CT_Dr7NotOandCFB,
   DR9CT_Dr7CloseFB,DR9CT_Dr7OpenHinder,DR9CT_Dr7Safe1FB,DR9CT_Dr7Safe2FB,
   DR9CT_Dr7Closed,DR9CT_Dr7Opened,DR9CT_Dr7EMCunclock,DR9CT_Dr7Cut,
   DR9CT_Dr7CloseHinder,DR9CT_Dr7ReSwitchLineFB,DR9CT_Dr7SeriousFlt,DR9CT_Dr7SlightFlt;

   bool DR9CT_Dr8EnableFB,DR9CT_Dr8ZeroSpFB,DR9CT_Dr8OpenFB,DR9CT_Dr8NotOandCFB,
   DR9CT_Dr8CloseFB,DR9CT_Dr8OpenHinder,DR9CT_Dr8Safe1FB,DR9CT_Dr8Safe2FB,
   DR9CT_Dr8Closed,DR9CT_Dr8Opened,DR9CT_Dr8EMCunclock,DR9CT_Dr8Cut,
   DR9CT_Dr8CloseHinder,DR9CT_Dr8ReSwitchLineFB,DR9CT_Dr8SeriousFlt,DR9CT_Dr8SlightFlt;

   unsigned short int DR9CT_OperationSt;
   bool DR9CT_MDCU1DataValid,DR9CT_MDCU2DataValid,DR9CT_MDCU3DataValid,DR9CT_MDCU4DataValid,
   DR9CT_MDCU5DataValid,DR9CT_MDCU6DataValid,DR9CT_MDCU7DataValid,DR9CT_MDCU8DataValid;

   unsigned short int DR9CT_BusToken,DR9CT_LifeSign;
   bool DR9CT_CANBreak;
   unsigned short int DR9CT_D1Version,DR9CT_D2Version,DR9CT_D3Version,DR9CT_D4Version,
   DR9CT_D5Version,DR9CT_D6Version,DR9CT_D7Version,DR9CT_D8Version;

   //0x7A0, 0x7A1, 0X7A2
   bool DRACT_Dr1MotoLineBrk,DRACT_Dr1ClockedInvalid,DRACT_Dr1ClosedInvalid,DRACT_Dr1NotUnlockIn3s,
   DRACT_Dr1PSensorInvalid,DRACT_Dr1OutClockedPnotAllowed,DRACT_Dr1SafeRelayFlt,DRACT_Dr1InterlockFlt,
   DRACT_Dr1ClockFlt,DRACT_Dr1CHinderNum,DRACT_Dr1OHinderNum,DRACT_Dr1O0OutShort,
   DRACT_Dr1O1OutShort,DRACT_Dr1O2OutShort,DRACT_Dr1O3OutShort,DRACT_Dr1RomFlt,
   DRACT_Dr1ComFlt,DRACT_Dr1AddCodeFlt,DRACT_Dr1MaintainBtnFlt;

   bool DRACT_Dr2MotoLineBrk,DRACT_Dr2ClockedInvalid,DRACT_Dr2ClosedInvalid,DRACT_Dr2NotUnlockIn3s,
   DRACT_Dr2PSensorInvalid,DRACT_Dr2OutClockedPnotAllowed,DRACT_Dr2SafeRelayFlt,DRACT_Dr2InterlockFlt,
   DRACT_Dr2ClockFlt,DRACT_Dr2CHinderNum,DRACT_Dr2OHinderNum,DRACT_Dr2O0OutShort,
   DRACT_Dr2O1OutShort,DRACT_Dr2O2OutShort,DRACT_Dr2O3OutShort,DRACT_Dr2RomFlt,
   DRACT_Dr2ComFlt,DRACT_Dr2AddCodeFlt,DRACT_Dr2MaintainBtnFlt;

   bool DRACT_Dr3MotoLineBrk,DRACT_Dr3ClockedInvalid,DRACT_Dr3ClosedInvalid,DRACT_Dr3NotUnlockIn3s,
   DRACT_Dr3PSensorInvalid,DRACT_Dr3OutClockedPnotAllowed,DRACT_Dr3SafeRelayFlt,DRACT_Dr3InterlockFlt,
   DRACT_Dr3ClockFlt,DRACT_Dr3CHinderNum,DRACT_Dr3OHinderNum,DRACT_Dr3O0OutShort,
   DRACT_Dr3O1OutShort,DRACT_Dr3O2OutShort,DRACT_Dr3O3OutShort,DRACT_Dr3RomFlt,
   DRACT_Dr3ComFlt,DRACT_Dr3AddCodeFlt,DRACT_Dr3MaintainBtnFlt;

   bool DRACT_Dr4MotoLineBrk,DRACT_Dr4ClockedInvalid,DRACT_Dr4ClosedInvalid,DRACT_Dr4NotUnlockIn3s,
   DRACT_Dr4PSensorInvalid,DRACT_Dr4OutClockedPnotAllowed,DRACT_Dr4SafeRelayFlt,DRACT_Dr4InterlockFlt,
   DRACT_Dr4ClockFlt,DRACT_Dr4CHinderNum,DRACT_Dr4OHinderNum,DRACT_Dr4O0OutShort,
   DRACT_Dr4O1OutShort,DRACT_Dr4O2OutShort,DRACT_Dr4O3OutShort,DRACT_Dr4RomFlt,
   DRACT_Dr4ComFlt,DRACT_Dr4AddCodeFlt,DRACT_Dr4MaintainBtnFlt;

   bool DRACT_Dr5MotoLineBrk,DRACT_Dr5ClockedInvalid,DRACT_Dr5ClosedInvalid,DRACT_Dr5NotUnlockIn3s,
   DRACT_Dr5PSensorInvalid,DRACT_Dr5OutClockedPnotAllowed,DRACT_Dr5SafeRelayFlt,DRACT_Dr5InterlockFlt,
   DRACT_Dr5ClockFlt,DRACT_Dr5CHinderNum,DRACT_Dr5OHinderNum,DRACT_Dr5O0OutShort,
   DRACT_Dr5O1OutShort,DRACT_Dr5O2OutShort,DRACT_Dr5O3OutShort,DRACT_Dr5RomFlt,
   DRACT_Dr5ComFlt,DRACT_Dr5AddCodeFlt,DRACT_Dr5MaintainBtnFlt;

   bool DRACT_Dr6MotoLineBrk,DRACT_Dr6ClockedInvalid,DRACT_Dr6ClosedInvalid,DRACT_Dr6NotUnlockIn3s,
   DRACT_Dr6PSensorInvalid,DRACT_Dr6OutClockedPnotAllowed,DRACT_Dr6SafeRelayFlt,DRACT_Dr6InterlockFlt,
   DRACT_Dr6ClockFlt,DRACT_Dr6CHinderNum,DRACT_Dr6OHinderNum,DRACT_Dr6O0OutShort,
   DRACT_Dr6O1OutShort,DRACT_Dr6O2OutShort,DRACT_Dr6O3OutShort,DRACT_Dr6RomFlt,
   DRACT_Dr6ComFlt,DRACT_Dr6AddCodeFlt,DRACT_Dr6MaintainBtnFlt;

   bool DRACT_Dr7MotoLineBrk,DRACT_Dr7ClockedInvalid,DRACT_Dr7ClosedInvalid,DRACT_Dr7NotUnlockIn3s,
   DRACT_Dr7PSensorInvalid,DRACT_Dr7OutClockedPnotAllowed,DRACT_Dr7SafeRelayFlt,DRACT_Dr7InterlockFlt,
   DRACT_Dr7ClockFlt,DRACT_Dr7CHinderNum,DRACT_Dr7OHinderNum,DRACT_Dr7O0OutShort,
   DRACT_Dr7O1OutShort,DRACT_Dr7O2OutShort,DRACT_Dr7O3OutShort,DRACT_Dr7RomFlt,
   DRACT_Dr7ComFlt,DRACT_Dr7AddCodeFlt,DRACT_Dr7MaintainBtnFlt;

   bool DRACT_Dr8MotoLineBrk,DRACT_Dr8ClockedInvalid,DRACT_Dr8ClosedInvalid,DRACT_Dr8NotUnlockIn3s,
   DRACT_Dr8PSensorInvalid,DRACT_Dr8OutClockedPnotAllowed,DRACT_Dr8SafeRelayFlt,DRACT_Dr8InterlockFlt,
   DRACT_Dr8ClockFlt,DRACT_Dr8CHinderNum,DRACT_Dr8OHinderNum,DRACT_Dr8O0OutShort,
   DRACT_Dr8O1OutShort,DRACT_Dr8O2OutShort,DRACT_Dr8O3OutShort,DRACT_Dr8RomFlt,
   DRACT_Dr8ComFlt,DRACT_Dr8AddCodeFlt,DRACT_Dr8MaintainBtnFlt;

   bool DRACT_Dr1EnableFB,DRACT_Dr1ZeroSpFB,DRACT_Dr1OpenFB,DRACT_Dr1NotOandCFB,
   DRACT_Dr1CloseFB,DRACT_Dr1OpenHinder,DRACT_Dr1Safe1FB,DRACT_Dr1Safe2FB,
   DRACT_Dr1Closed,DRACT_Dr1Opened,DRACT_Dr1EMCunclock,DRACT_Dr1Cut,
   DRACT_Dr1CloseHinder,DRACT_Dr1ReSwitchLineFB,DRACT_Dr1SeriousFlt,DRACT_Dr1SlightFlt;

   bool DRACT_Dr2EnableFB,DRACT_Dr2ZeroSpFB,DRACT_Dr2OpenFB,DRACT_Dr2NotOandCFB,
   DRACT_Dr2CloseFB,DRACT_Dr2OpenHinder,DRACT_Dr2Safe1FB,DRACT_Dr2Safe2FB,
   DRACT_Dr2Closed,DRACT_Dr2Opened,DRACT_Dr2EMCunclock,DRACT_Dr2Cut,
   DRACT_Dr2CloseHinder,DRACT_Dr2ReSwitchLineFB,DRACT_Dr2SeriousFlt,DRACT_Dr2SlightFlt;

   bool DRACT_Dr3EnableFB,DRACT_Dr3ZeroSpFB,DRACT_Dr3OpenFB,DRACT_Dr3NotOandCFB,
   DRACT_Dr3CloseFB,DRACT_Dr3OpenHinder,DRACT_Dr3Safe1FB,DRACT_Dr3Safe2FB,
   DRACT_Dr3Closed,DRACT_Dr3Opened,DRACT_Dr3EMCunclock,DRACT_Dr3Cut,
   DRACT_Dr3CloseHinder,DRACT_Dr3ReSwitchLineFB,DRACT_Dr3SeriousFlt,DRACT_Dr3SlightFlt;

   bool DRACT_Dr4EnableFB,DRACT_Dr4ZeroSpFB,DRACT_Dr4OpenFB,DRACT_Dr4NotOandCFB,
   DRACT_Dr4CloseFB,DRACT_Dr4OpenHinder,DRACT_Dr4Safe1FB,DRACT_Dr4Safe2FB,
   DRACT_Dr4Closed,DRACT_Dr4Opened,DRACT_Dr4EMCunclock,DRACT_Dr4Cut,
   DRACT_Dr4CloseHinder,DRACT_Dr4ReSwitchLineFB,DRACT_Dr4SeriousFlt,DRACT_Dr4SlightFlt;

   bool DRACT_Dr5EnableFB,DRACT_Dr5ZeroSpFB,DRACT_Dr5OpenFB,DRACT_Dr5NotOandCFB,
   DRACT_Dr5CloseFB,DRACT_Dr5OpenHinder,DRACT_Dr5Safe1FB,DRACT_Dr5Safe2FB,
   DRACT_Dr5Closed,DRACT_Dr5Opened,DRACT_Dr5EMCunclock,DRACT_Dr5Cut,
   DRACT_Dr5CloseHinder,DRACT_Dr5ReSwitchLineFB,DRACT_Dr5SeriousFlt,DRACT_Dr5SlightFlt;

   bool DRACT_Dr6EnableFB,DRACT_Dr6ZeroSpFB,DRACT_Dr6OpenFB,DRACT_Dr6NotOandCFB,
   DRACT_Dr6CloseFB,DRACT_Dr6OpenHinder,DRACT_Dr6Safe1FB,DRACT_Dr6Safe2FB,
   DRACT_Dr6Closed,DRACT_Dr6Opened,DRACT_Dr6EMCunclock,DRACT_Dr6Cut,
   DRACT_Dr6CloseHinder,DRACT_Dr6ReSwitchLineFB,DRACT_Dr6SeriousFlt,DRACT_Dr6SlightFlt;

   bool DRACT_Dr7EnableFB,DRACT_Dr7ZeroSpFB,DRACT_Dr7OpenFB,DRACT_Dr7NotOandCFB,
   DRACT_Dr7CloseFB,DRACT_Dr7OpenHinder,DRACT_Dr7Safe1FB,DRACT_Dr7Safe2FB,
   DRACT_Dr7Closed,DRACT_Dr7Opened,DRACT_Dr7EMCunclock,DRACT_Dr7Cut,
   DRACT_Dr7CloseHinder,DRACT_Dr7ReSwitchLineFB,DRACT_Dr7SeriousFlt,DRACT_Dr7SlightFlt;

   bool DRACT_Dr8EnableFB,DRACT_Dr8ZeroSpFB,DRACT_Dr8OpenFB,DRACT_Dr8NotOandCFB,
   DRACT_Dr8CloseFB,DRACT_Dr8OpenHinder,DRACT_Dr8Safe1FB,DRACT_Dr8Safe2FB,
   DRACT_Dr8Closed,DRACT_Dr8Opened,DRACT_Dr8EMCunclock,DRACT_Dr8Cut,
   DRACT_Dr8CloseHinder,DRACT_Dr8ReSwitchLineFB,DRACT_Dr8SeriousFlt,DRACT_Dr8SlightFlt;

   unsigned short int DRACT_OperationSt;
   bool DRACT_MDCU1DataValid,DRACT_MDCU2DataValid,DRACT_MDCU3DataValid,DRACT_MDCU4DataValid,
   DRACT_MDCU5DataValid,DRACT_MDCU6DataValid,DRACT_MDCU7DataValid,DRACT_MDCU8DataValid;

   unsigned short int DRACT_BusToken,DRACT_LifeSign;
   bool DRACT_CANBreak;
   unsigned short int DRACT_D1Version,DRACT_D2Version,DRACT_D3Version,DRACT_D4Version,
   DRACT_D5Version,DRACT_D6Version,DRACT_D7Version,DRACT_D8Version;

   //0x7B0, 0x7B1, 0x7B2
   bool DRBCT_Dr1MotoLineBrk,DRBCT_Dr1ClockedInvalid,DRBCT_Dr1ClosedInvalid,DRBCT_Dr1NotUnlockIn3s,
   DRBCT_Dr1PSensorInvalid,DRBCT_Dr1OutClockedPnotAllowed,DRBCT_Dr1SafeRelayFlt,DRBCT_Dr1InterlockFlt,
   DRBCT_Dr1ClockFlt,DRBCT_Dr1CHinderNum,DRBCT_Dr1OHinderNum,DRBCT_Dr1O0OutShort,
   DRBCT_Dr1O1OutShort,DRBCT_Dr1O2OutShort,DRBCT_Dr1O3OutShort,DRBCT_Dr1RomFlt,
   DRBCT_Dr1ComFlt,DRBCT_Dr1AddCodeFlt,DRBCT_Dr1MaintainBtnFlt;

   bool DRBCT_Dr2MotoLineBrk,DRBCT_Dr2ClockedInvalid,DRBCT_Dr2ClosedInvalid,DRBCT_Dr2NotUnlockIn3s,
   DRBCT_Dr2PSensorInvalid,DRBCT_Dr2OutClockedPnotAllowed,DRBCT_Dr2SafeRelayFlt,DRBCT_Dr2InterlockFlt,
   DRBCT_Dr2ClockFlt,DRBCT_Dr2CHinderNum,DRBCT_Dr2OHinderNum,DRBCT_Dr2O0OutShort,
   DRBCT_Dr2O1OutShort,DRBCT_Dr2O2OutShort,DRBCT_Dr2O3OutShort,DRBCT_Dr2RomFlt,
   DRBCT_Dr2ComFlt,DRBCT_Dr2AddCodeFlt,DRBCT_Dr2MaintainBtnFlt;

   bool DRBCT_Dr3MotoLineBrk,DRBCT_Dr3ClockedInvalid,DRBCT_Dr3ClosedInvalid,DRBCT_Dr3NotUnlockIn3s,
   DRBCT_Dr3PSensorInvalid,DRBCT_Dr3OutClockedPnotAllowed,DRBCT_Dr3SafeRelayFlt,DRBCT_Dr3InterlockFlt,
   DRBCT_Dr3ClockFlt,DRBCT_Dr3CHinderNum,DRBCT_Dr3OHinderNum,DRBCT_Dr3O0OutShort,
   DRBCT_Dr3O1OutShort,DRBCT_Dr3O2OutShort,DRBCT_Dr3O3OutShort,DRBCT_Dr3RomFlt,
   DRBCT_Dr3ComFlt,DRBCT_Dr3AddCodeFlt,DRBCT_Dr3MaintainBtnFlt;

   bool DRBCT_Dr4MotoLineBrk,DRBCT_Dr4ClockedInvalid,DRBCT_Dr4ClosedInvalid,DRBCT_Dr4NotUnlockIn3s,
   DRBCT_Dr4PSensorInvalid,DRBCT_Dr4OutClockedPnotAllowed,DRBCT_Dr4SafeRelayFlt,DRBCT_Dr4InterlockFlt,
   DRBCT_Dr4ClockFlt,DRBCT_Dr4CHinderNum,DRBCT_Dr4OHinderNum,DRBCT_Dr4O0OutShort,
   DRBCT_Dr4O1OutShort,DRBCT_Dr4O2OutShort,DRBCT_Dr4O3OutShort,DRBCT_Dr4RomFlt,
   DRBCT_Dr4ComFlt,DRBCT_Dr4AddCodeFlt,DRBCT_Dr4MaintainBtnFlt;

   bool DRBCT_Dr5MotoLineBrk,DRBCT_Dr5ClockedInvalid,DRBCT_Dr5ClosedInvalid,DRBCT_Dr5NotUnlockIn3s,
   DRBCT_Dr5PSensorInvalid,DRBCT_Dr5OutClockedPnotAllowed,DRBCT_Dr5SafeRelayFlt,DRBCT_Dr5InterlockFlt,
   DRBCT_Dr5ClockFlt,DRBCT_Dr5CHinderNum,DRBCT_Dr5OHinderNum,DRBCT_Dr5O0OutShort,
   DRBCT_Dr5O1OutShort,DRBCT_Dr5O2OutShort,DRBCT_Dr5O3OutShort,DRBCT_Dr5RomFlt,
   DRBCT_Dr5ComFlt,DRBCT_Dr5AddCodeFlt,DRBCT_Dr5MaintainBtnFlt;

   bool DRBCT_Dr6MotoLineBrk,DRBCT_Dr6ClockedInvalid,DRBCT_Dr6ClosedInvalid,DRBCT_Dr6NotUnlockIn3s,
   DRBCT_Dr6PSensorInvalid,DRBCT_Dr6OutClockedPnotAllowed,DRBCT_Dr6SafeRelayFlt,DRBCT_Dr6InterlockFlt,
   DRBCT_Dr6ClockFlt,DRBCT_Dr6CHinderNum,DRBCT_Dr6OHinderNum,DRBCT_Dr6O0OutShort,
   DRBCT_Dr6O1OutShort,DRBCT_Dr6O2OutShort,DRBCT_Dr6O3OutShort,DRBCT_Dr6RomFlt,
   DRBCT_Dr6ComFlt,DRBCT_Dr6AddCodeFlt,DRBCT_Dr6MaintainBtnFlt;

   bool DRBCT_Dr7MotoLineBrk,DRBCT_Dr7ClockedInvalid,DRBCT_Dr7ClosedInvalid,DRBCT_Dr7NotUnlockIn3s,
   DRBCT_Dr7PSensorInvalid,DRBCT_Dr7OutClockedPnotAllowed,DRBCT_Dr7SafeRelayFlt,DRBCT_Dr7InterlockFlt,
   DRBCT_Dr7ClockFlt,DRBCT_Dr7CHinderNum,DRBCT_Dr7OHinderNum,DRBCT_Dr7O0OutShort,
   DRBCT_Dr7O1OutShort,DRBCT_Dr7O2OutShort,DRBCT_Dr7O3OutShort,DRBCT_Dr7RomFlt,
   DRBCT_Dr7ComFlt,DRBCT_Dr7AddCodeFlt,DRBCT_Dr7MaintainBtnFlt;

   bool DRBCT_Dr8MotoLineBrk,DRBCT_Dr8ClockedInvalid,DRBCT_Dr8ClosedInvalid,DRBCT_Dr8NotUnlockIn3s,
   DRBCT_Dr8PSensorInvalid,DRBCT_Dr8OutClockedPnotAllowed,DRBCT_Dr8SafeRelayFlt,DRBCT_Dr8InterlockFlt,
   DRBCT_Dr8ClockFlt,DRBCT_Dr8CHinderNum,DRBCT_Dr8OHinderNum,DRBCT_Dr8O0OutShort,
   DRBCT_Dr8O1OutShort,DRBCT_Dr8O2OutShort,DRBCT_Dr8O3OutShort,DRBCT_Dr8RomFlt,
   DRBCT_Dr8ComFlt,DRBCT_Dr8AddCodeFlt,DRBCT_Dr8MaintainBtnFlt;

   bool DRBCT_Dr1EnableFB,DRBCT_Dr1ZeroSpFB,DRBCT_Dr1OpenFB,DRBCT_Dr1NotOandCFB,
   DRBCT_Dr1CloseFB,DRBCT_Dr1OpenHinder,DRBCT_Dr1Safe1FB,DRBCT_Dr1Safe2FB,
   DRBCT_Dr1Closed,DRBCT_Dr1Opened,DRBCT_Dr1EMCunclock,DRBCT_Dr1Cut,
   DRBCT_Dr1CloseHinder,DRBCT_Dr1ReSwitchLineFB,DRBCT_Dr1SeriousFlt,DRBCT_Dr1SlightFlt;

   bool DRBCT_Dr2EnableFB,DRBCT_Dr2ZeroSpFB,DRBCT_Dr2OpenFB,DRBCT_Dr2NotOandCFB,
   DRBCT_Dr2CloseFB,DRBCT_Dr2OpenHinder,DRBCT_Dr2Safe1FB,DRBCT_Dr2Safe2FB,
   DRBCT_Dr2Closed,DRBCT_Dr2Opened,DRBCT_Dr2EMCunclock,DRBCT_Dr2Cut,
   DRBCT_Dr2CloseHinder,DRBCT_Dr2ReSwitchLineFB,DRBCT_Dr2SeriousFlt,DRBCT_Dr2SlightFlt;

   bool DRBCT_Dr3EnableFB,DRBCT_Dr3ZeroSpFB,DRBCT_Dr3OpenFB,DRBCT_Dr3NotOandCFB,
   DRBCT_Dr3CloseFB,DRBCT_Dr3OpenHinder,DRBCT_Dr3Safe1FB,DRBCT_Dr3Safe2FB,
   DRBCT_Dr3Closed,DRBCT_Dr3Opened,DRBCT_Dr3EMCunclock,DRBCT_Dr3Cut,
   DRBCT_Dr3CloseHinder,DRBCT_Dr3ReSwitchLineFB,DRBCT_Dr3SeriousFlt,DRBCT_Dr3SlightFlt;

   bool DRBCT_Dr4EnableFB,DRBCT_Dr4ZeroSpFB,DRBCT_Dr4OpenFB,DRBCT_Dr4NotOandCFB,
   DRBCT_Dr4CloseFB,DRBCT_Dr4OpenHinder,DRBCT_Dr4Safe1FB,DRBCT_Dr4Safe2FB,
   DRBCT_Dr4Closed,DRBCT_Dr4Opened,DRBCT_Dr4EMCunclock,DRBCT_Dr4Cut,
   DRBCT_Dr4CloseHinder,DRBCT_Dr4ReSwitchLineFB,DRBCT_Dr4SeriousFlt,DRBCT_Dr4SlightFlt;

   bool DRBCT_Dr5EnableFB,DRBCT_Dr5ZeroSpFB,DRBCT_Dr5OpenFB,DRBCT_Dr5NotOandCFB,
   DRBCT_Dr5CloseFB,DRBCT_Dr5OpenHinder,DRBCT_Dr5Safe1FB,DRBCT_Dr5Safe2FB,
   DRBCT_Dr5Closed,DRBCT_Dr5Opened,DRBCT_Dr5EMCunclock,DRBCT_Dr5Cut,
   DRBCT_Dr5CloseHinder,DRBCT_Dr5ReSwitchLineFB,DRBCT_Dr5SeriousFlt,DRBCT_Dr5SlightFlt;

   bool DRBCT_Dr6EnableFB,DRBCT_Dr6ZeroSpFB,DRBCT_Dr6OpenFB,DRBCT_Dr6NotOandCFB,
   DRBCT_Dr6CloseFB,DRBCT_Dr6OpenHinder,DRBCT_Dr6Safe1FB,DRBCT_Dr6Safe2FB,
   DRBCT_Dr6Closed,DRBCT_Dr6Opened,DRBCT_Dr6EMCunclock,DRBCT_Dr6Cut,
   DRBCT_Dr6CloseHinder,DRBCT_Dr6ReSwitchLineFB,DRBCT_Dr6SeriousFlt,DRBCT_Dr6SlightFlt;

   bool DRBCT_Dr7EnableFB,DRBCT_Dr7ZeroSpFB,DRBCT_Dr7OpenFB,DRBCT_Dr7NotOandCFB,
   DRBCT_Dr7CloseFB,DRBCT_Dr7OpenHinder,DRBCT_Dr7Safe1FB,DRBCT_Dr7Safe2FB,
   DRBCT_Dr7Closed,DRBCT_Dr7Opened,DRBCT_Dr7EMCunclock,DRBCT_Dr7Cut,
   DRBCT_Dr7CloseHinder,DRBCT_Dr7ReSwitchLineFB,DRBCT_Dr7SeriousFlt,DRBCT_Dr7SlightFlt;

   bool DRBCT_Dr8EnableFB,DRBCT_Dr8ZeroSpFB,DRBCT_Dr8OpenFB,DRBCT_Dr8NotOandCFB,
   DRBCT_Dr8CloseFB,DRBCT_Dr8OpenHinder,DRBCT_Dr8Safe1FB,DRBCT_Dr8Safe2FB,
   DRBCT_Dr8Closed,DRBCT_Dr8Opened,DRBCT_Dr8EMCunclock,DRBCT_Dr8Cut,
   DRBCT_Dr8CloseHinder,DRBCT_Dr8ReSwitchLineFB,DRBCT_Dr8SeriousFlt,DRBCT_Dr8SlightFlt;

   unsigned short int DRBCT_OperationSt;
   bool DRBCT_MDCU1DataValid,DRBCT_MDCU2DataValid,DRBCT_MDCU3DataValid,DRBCT_MDCU4DataValid,
   DRBCT_MDCU5DataValid,DRBCT_MDCU6DataValid,DRBCT_MDCU7DataValid,DRBCT_MDCU8DataValid;

   unsigned short int DRBCT_BusToken,DRBCT_LifeSign;
   bool DRBCT_CANBreak;
   unsigned short int DRBCT_D1Version,DRBCT_D2Version,DRBCT_D3Version,DRBCT_D4Version,
   DRBCT_D5Version,DRBCT_D6Version,DRBCT_D7Version,DRBCT_D8Version;


   //0x7C0, 0x7C1, 0x7C2
   bool DRCCT_Dr1MotoLineBrk,DRCCT_Dr1ClockedInvalid,DRCCT_Dr1ClosedInvalid,DRCCT_Dr1NotUnlockIn3s,
   DRCCT_Dr1PSensorInvalid,DRCCT_Dr1OutClockedPnotAllowed,DRCCT_Dr1SafeRelayFlt,DRCCT_Dr1InterlockFlt,
   DRCCT_Dr1ClockFlt,DRCCT_Dr1CHinderNum,DRCCT_Dr1OHinderNum,DRCCT_Dr1O0OutShort,
   DRCCT_Dr1O1OutShort,DRCCT_Dr1O2OutShort,DRCCT_Dr1O3OutShort,DRCCT_Dr1RomFlt,
   DRCCT_Dr1ComFlt,DRCCT_Dr1AddCodeFlt,DRCCT_Dr1MaintainBtnFlt;

   bool DRCCT_Dr2MotoLineBrk,DRCCT_Dr2ClockedInvalid,DRCCT_Dr2ClosedInvalid,DRCCT_Dr2NotUnlockIn3s,
   DRCCT_Dr2PSensorInvalid,DRCCT_Dr2OutClockedPnotAllowed,DRCCT_Dr2SafeRelayFlt,DRCCT_Dr2InterlockFlt,
   DRCCT_Dr2ClockFlt,DRCCT_Dr2CHinderNum,DRCCT_Dr2OHinderNum,DRCCT_Dr2O0OutShort,
   DRCCT_Dr2O1OutShort,DRCCT_Dr2O2OutShort,DRCCT_Dr2O3OutShort,DRCCT_Dr2RomFlt,
   DRCCT_Dr2ComFlt,DRCCT_Dr2AddCodeFlt,DRCCT_Dr2MaintainBtnFlt;

   bool DRCCT_Dr3MotoLineBrk,DRCCT_Dr3ClockedInvalid,DRCCT_Dr3ClosedInvalid,DRCCT_Dr3NotUnlockIn3s,
   DRCCT_Dr3PSensorInvalid,DRCCT_Dr3OutClockedPnotAllowed,DRCCT_Dr3SafeRelayFlt,DRCCT_Dr3InterlockFlt,
   DRCCT_Dr3ClockFlt,DRCCT_Dr3CHinderNum,DRCCT_Dr3OHinderNum,DRCCT_Dr3O0OutShort,
   DRCCT_Dr3O1OutShort,DRCCT_Dr3O2OutShort,DRCCT_Dr3O3OutShort,DRCCT_Dr3RomFlt,
   DRCCT_Dr3ComFlt,DRCCT_Dr3AddCodeFlt,DRCCT_Dr3MaintainBtnFlt;

   bool DRCCT_Dr4MotoLineBrk,DRCCT_Dr4ClockedInvalid,DRCCT_Dr4ClosedInvalid,DRCCT_Dr4NotUnlockIn3s,
   DRCCT_Dr4PSensorInvalid,DRCCT_Dr4OutClockedPnotAllowed,DRCCT_Dr4SafeRelayFlt,DRCCT_Dr4InterlockFlt,
   DRCCT_Dr4ClockFlt,DRCCT_Dr4CHinderNum,DRCCT_Dr4OHinderNum,DRCCT_Dr4O0OutShort,
   DRCCT_Dr4O1OutShort,DRCCT_Dr4O2OutShort,DRCCT_Dr4O3OutShort,DRCCT_Dr4RomFlt,
   DRCCT_Dr4ComFlt,DRCCT_Dr4AddCodeFlt,DRCCT_Dr4MaintainBtnFlt;

   bool DRCCT_Dr5MotoLineBrk,DRCCT_Dr5ClockedInvalid,DRCCT_Dr5ClosedInvalid,DRCCT_Dr5NotUnlockIn3s,
   DRCCT_Dr5PSensorInvalid,DRCCT_Dr5OutClockedPnotAllowed,DRCCT_Dr5SafeRelayFlt,DRCCT_Dr5InterlockFlt,
   DRCCT_Dr5ClockFlt,DRCCT_Dr5CHinderNum,DRCCT_Dr5OHinderNum,DRCCT_Dr5O0OutShort,
   DRCCT_Dr5O1OutShort,DRCCT_Dr5O2OutShort,DRCCT_Dr5O3OutShort,DRCCT_Dr5RomFlt,
   DRCCT_Dr5ComFlt,DRCCT_Dr5AddCodeFlt,DRCCT_Dr5MaintainBtnFlt;

   bool DRCCT_Dr6MotoLineBrk,DRCCT_Dr6ClockedInvalid,DRCCT_Dr6ClosedInvalid,DRCCT_Dr6NotUnlockIn3s,
   DRCCT_Dr6PSensorInvalid,DRCCT_Dr6OutClockedPnotAllowed,DRCCT_Dr6SafeRelayFlt,DRCCT_Dr6InterlockFlt,
   DRCCT_Dr6ClockFlt,DRCCT_Dr6CHinderNum,DRCCT_Dr6OHinderNum,DRCCT_Dr6O0OutShort,
   DRCCT_Dr6O1OutShort,DRCCT_Dr6O2OutShort,DRCCT_Dr6O3OutShort,DRCCT_Dr6RomFlt,
   DRCCT_Dr6ComFlt,DRCCT_Dr6AddCodeFlt,DRCCT_Dr6MaintainBtnFlt;

   bool DRCCT_Dr7MotoLineBrk,DRCCT_Dr7ClockedInvalid,DRCCT_Dr7ClosedInvalid,DRCCT_Dr7NotUnlockIn3s,
   DRCCT_Dr7PSensorInvalid,DRCCT_Dr7OutClockedPnotAllowed,DRCCT_Dr7SafeRelayFlt,DRCCT_Dr7InterlockFlt,
   DRCCT_Dr7ClockFlt,DRCCT_Dr7CHinderNum,DRCCT_Dr7OHinderNum,DRCCT_Dr7O0OutShort,
   DRCCT_Dr7O1OutShort,DRCCT_Dr7O2OutShort,DRCCT_Dr7O3OutShort,DRCCT_Dr7RomFlt,
   DRCCT_Dr7ComFlt,DRCCT_Dr7AddCodeFlt,DRCCT_Dr7MaintainBtnFlt;

   bool DRCCT_Dr8MotoLineBrk,DRCCT_Dr8ClockedInvalid,DRCCT_Dr8ClosedInvalid,DRCCT_Dr8NotUnlockIn3s,
   DRCCT_Dr8PSensorInvalid,DRCCT_Dr8OutClockedPnotAllowed,DRCCT_Dr8SafeRelayFlt,DRCCT_Dr8InterlockFlt,
   DRCCT_Dr8ClockFlt,DRCCT_Dr8CHinderNum,DRCCT_Dr8OHinderNum,DRCCT_Dr8O0OutShort,
   DRCCT_Dr8O1OutShort,DRCCT_Dr8O2OutShort,DRCCT_Dr8O3OutShort,DRCCT_Dr8RomFlt,
   DRCCT_Dr8ComFlt,DRCCT_Dr8AddCodeFlt,DRCCT_Dr8MaintainBtnFlt;

   bool DRCCT_Dr1EnableFB,DRCCT_Dr1ZeroSpFB,DRCCT_Dr1OpenFB,DRCCT_Dr1NotOandCFB,
   DRCCT_Dr1CloseFB,DRCCT_Dr1OpenHinder,DRCCT_Dr1Safe1FB,DRCCT_Dr1Safe2FB,
   DRCCT_Dr1Closed,DRCCT_Dr1Opened,DRCCT_Dr1EMCunclock,DRCCT_Dr1Cut,
   DRCCT_Dr1CloseHinder,DRCCT_Dr1ReSwitchLineFB,DRCCT_Dr1SeriousFlt,DRCCT_Dr1SlightFlt;

   bool DRCCT_Dr2EnableFB,DRCCT_Dr2ZeroSpFB,DRCCT_Dr2OpenFB,DRCCT_Dr2NotOandCFB,
   DRCCT_Dr2CloseFB,DRCCT_Dr2OpenHinder,DRCCT_Dr2Safe1FB,DRCCT_Dr2Safe2FB,
   DRCCT_Dr2Closed,DRCCT_Dr2Opened,DRCCT_Dr2EMCunclock,DRCCT_Dr2Cut,
   DRCCT_Dr2CloseHinder,DRCCT_Dr2ReSwitchLineFB,DRCCT_Dr2SeriousFlt,DRCCT_Dr2SlightFlt;

   bool DRCCT_Dr3EnableFB,DRCCT_Dr3ZeroSpFB,DRCCT_Dr3OpenFB,DRCCT_Dr3NotOandCFB,
   DRCCT_Dr3CloseFB,DRCCT_Dr3OpenHinder,DRCCT_Dr3Safe1FB,DRCCT_Dr3Safe2FB,
   DRCCT_Dr3Closed,DRCCT_Dr3Opened,DRCCT_Dr3EMCunclock,DRCCT_Dr3Cut,
   DRCCT_Dr3CloseHinder,DRCCT_Dr3ReSwitchLineFB,DRCCT_Dr3SeriousFlt,DRCCT_Dr3SlightFlt;

   bool DRCCT_Dr4EnableFB,DRCCT_Dr4ZeroSpFB,DRCCT_Dr4OpenFB,DRCCT_Dr4NotOandCFB,
   DRCCT_Dr4CloseFB,DRCCT_Dr4OpenHinder,DRCCT_Dr4Safe1FB,DRCCT_Dr4Safe2FB,
   DRCCT_Dr4Closed,DRCCT_Dr4Opened,DRCCT_Dr4EMCunclock,DRCCT_Dr4Cut,
   DRCCT_Dr4CloseHinder,DRCCT_Dr4ReSwitchLineFB,DRCCT_Dr4SeriousFlt,DRCCT_Dr4SlightFlt;

   bool DRCCT_Dr5EnableFB,DRCCT_Dr5ZeroSpFB,DRCCT_Dr5OpenFB,DRCCT_Dr5NotOandCFB,
   DRCCT_Dr5CloseFB,DRCCT_Dr5OpenHinder,DRCCT_Dr5Safe1FB,DRCCT_Dr5Safe2FB,
   DRCCT_Dr5Closed,DRCCT_Dr5Opened,DRCCT_Dr5EMCunclock,DRCCT_Dr5Cut,
   DRCCT_Dr5CloseHinder,DRCCT_Dr5ReSwitchLineFB,DRCCT_Dr5SeriousFlt,DRCCT_Dr5SlightFlt;

   bool DRCCT_Dr6EnableFB,DRCCT_Dr6ZeroSpFB,DRCCT_Dr6OpenFB,DRCCT_Dr6NotOandCFB,
   DRCCT_Dr6CloseFB,DRCCT_Dr6OpenHinder,DRCCT_Dr6Safe1FB,DRCCT_Dr6Safe2FB,
   DRCCT_Dr6Closed,DRCCT_Dr6Opened,DRCCT_Dr6EMCunclock,DRCCT_Dr6Cut,
   DRCCT_Dr6CloseHinder,DRCCT_Dr6ReSwitchLineFB,DRCCT_Dr6SeriousFlt,DRCCT_Dr6SlightFlt;

   bool DRCCT_Dr7EnableFB,DRCCT_Dr7ZeroSpFB,DRCCT_Dr7OpenFB,DRCCT_Dr7NotOandCFB,
   DRCCT_Dr7CloseFB,DRCCT_Dr7OpenHinder,DRCCT_Dr7Safe1FB,DRCCT_Dr7Safe2FB,
   DRCCT_Dr7Closed,DRCCT_Dr7Opened,DRCCT_Dr7EMCunclock,DRCCT_Dr7Cut,
   DRCCT_Dr7CloseHinder,DRCCT_Dr7ReSwitchLineFB,DRCCT_Dr7SeriousFlt,DRCCT_Dr7SlightFlt;

   bool DRCCT_Dr8EnableFB,DRCCT_Dr8ZeroSpFB,DRCCT_Dr8OpenFB,DRCCT_Dr8NotOandCFB,
   DRCCT_Dr8CloseFB,DRCCT_Dr8OpenHinder,DRCCT_Dr8Safe1FB,DRCCT_Dr8Safe2FB,
   DRCCT_Dr8Closed,DRCCT_Dr8Opened,DRCCT_Dr8EMCunclock,DRCCT_Dr8Cut,
   DRCCT_Dr8CloseHinder,DRCCT_Dr8ReSwitchLineFB,DRCCT_Dr8SeriousFlt,DRCCT_Dr8SlightFlt;

   unsigned short int DRCCT_OperationSt;
   bool DRCCT_MDCU1DataValid,DRCCT_MDCU2DataValid,DRCCT_MDCU3DataValid,DRCCT_MDCU4DataValid,
   DRCCT_MDCU5DataValid,DRCCT_MDCU6DataValid,DRCCT_MDCU7DataValid,DRCCT_MDCU8DataValid;

   unsigned short int DRCCT_BusToken,DRCCT_LifeSign;

   bool DRCCT_CANBreak;
   unsigned short int DRCCT_D1Version,DRCCT_D2Version,DRCCT_D3Version,DRCCT_D4Version,
   DRCCT_D5Version,DRCCT_D6Version,DRCCT_D7Version,DRCCT_D8Version;

   //EDCU virtual ports
   //0xF710, 0xF711, 0xF712
   bool hmiEDCU1_Door1MotoLineBrk,hmiEDCU1_Door1ClockedInvalid,hmiEDCU1_Door1ClosedInvalid,hmiEDCU1_Door1NotUnlockIn3s,
   hmiEDCU1_Door1PSensorInvalid,hmiEDCU1_Door1OutClockedPnotAllowed,hmiEDCU1_Door1SafeRelayFlt,hmiEDCU1_Door1InterlockFlt,
   hmiEDCU1_Door1ClockFlt,hmiEDCU1_Door1CHinderNum,hmiEDCU1_Door1OHinderNum,hmiEDCU1_Door1O0OutShort,
   hmiEDCU1_Door1O1OutShort,hmiEDCU1_Door1O2OutShort,hmiEDCU1_Door1O3OutShort,hmiEDCU1_Door1RomFlt,
   hmiEDCU1_Door1ComFlt,hmiEDCU1_Door1AddCodeFlt,hmiEDCU1_Door1MaintainBtnFlt;

   bool hmiEDCU1_Door2MotoLineBrk,hmiEDCU1_Door2ClockedInvalid,hmiEDCU1_Door2ClosedInvalid,hmiEDCU1_Door2NotUnlockIn3s,
   hmiEDCU1_Door2PSensorInvalid,hmiEDCU1_Door2OutClockedPnotAllowed,hmiEDCU1_Door2SafeRelayFlt,hmiEDCU1_Door2InterlockFlt,
   hmiEDCU1_Door2ClockFlt,hmiEDCU1_Door2CHinderNum,hmiEDCU1_Door2OHinderNum,hmiEDCU1_Door2O0OutShort,
   hmiEDCU1_Door2O1OutShort,hmiEDCU1_Door2O2OutShort,hmiEDCU1_Door2O3OutShort,hmiEDCU1_Door2RomFlt,
   hmiEDCU1_Door2ComFlt,hmiEDCU1_Door2AddCodeFlt,hmiEDCU1_Door2MaintainBtnFlt;

   bool hmiEDCU1_Door3MotoLineBrk,hmiEDCU1_Door3ClockedInvalid,hmiEDCU1_Door3ClosedInvalid,hmiEDCU1_Door3NotUnlockIn3s,
   hmiEDCU1_Door3PSensorInvalid,hmiEDCU1_Door3OutClockedPnotAllowed,hmiEDCU1_Door3SafeRelayFlt,hmiEDCU1_Door3InterlockFlt,
   hmiEDCU1_Door3ClockFlt,hmiEDCU1_Door3CHinderNum,hmiEDCU1_Door3OHinderNum,hmiEDCU1_Door3O0OutShort,
   hmiEDCU1_Door3O1OutShort,hmiEDCU1_Door3O2OutShort,hmiEDCU1_Door3O3OutShort,hmiEDCU1_Door3RomFlt,
   hmiEDCU1_Door3ComFlt,hmiEDCU1_Door3AddCodeFlt,hmiEDCU1_Door3MaintainBtnFlt;

   bool hmiEDCU1_Door4MotoLineBrk,hmiEDCU1_Door4ClockedInvalid,hmiEDCU1_Door4ClosedInvalid,hmiEDCU1_Door4NotUnlockIn3s,
   hmiEDCU1_Door4PSensorInvalid,hmiEDCU1_Door4OutClockedPnotAllowed,hmiEDCU1_Door4SafeRelayFlt,hmiEDCU1_Door4InterlockFlt,
   hmiEDCU1_Door4ClockFlt,hmiEDCU1_Door4CHinderNum,hmiEDCU1_Door4OHinderNum,hmiEDCU1_Door4O0OutShort,
   hmiEDCU1_Door4O1OutShort,hmiEDCU1_Door4O2OutShort,hmiEDCU1_Door4O3OutShort,hmiEDCU1_Door4RomFlt,
   hmiEDCU1_Door4ComFlt,hmiEDCU1_Door4AddCodeFlt,hmiEDCU1_Door4MaintainBtnFlt;

   bool hmiEDCU1_Door5MotoLineBrk,hmiEDCU1_Door5ClockedInvalid,hmiEDCU1_Door5ClosedInvalid,hmiEDCU1_Door5NotUnlockIn3s,
   hmiEDCU1_Door5PSensorInvalid,hmiEDCU1_Door5OutClockedPnotAllowed,hmiEDCU1_Door5SafeRelayFlt,hmiEDCU1_Door5InterlockFlt,
   hmiEDCU1_Door5ClockFlt,hmiEDCU1_Door5CHinderNum,hmiEDCU1_Door5OHinderNum,hmiEDCU1_Door5O0OutShort,
   hmiEDCU1_Door5O1OutShort,hmiEDCU1_Door5O2OutShort,hmiEDCU1_Door5O3OutShort,hmiEDCU1_Door5RomFlt,
   hmiEDCU1_Door5ComFlt,hmiEDCU1_Door5AddCodeFlt,hmiEDCU1_Door5MaintainBtnFlt;

   bool hmiEDCU1_Door6MotoLineBrk,hmiEDCU1_Door6ClockedInvalid,hmiEDCU1_Door6ClosedInvalid,hmiEDCU1_Door6NotUnlockIn3s,
   hmiEDCU1_Door6PSensorInvalid,hmiEDCU1_Door6OutClockedPnotAllowed,hmiEDCU1_Door6SafeRelayFlt,hmiEDCU1_Door6InterlockFlt,
   hmiEDCU1_Door6ClockFlt,hmiEDCU1_Door6CHinderNum,hmiEDCU1_Door6OHinderNum,hmiEDCU1_Door6O0OutShort,
   hmiEDCU1_Door6O1OutShort,hmiEDCU1_Door6O2OutShort,hmiEDCU1_Door6O3OutShort,hmiEDCU1_Door6RomFlt,
   hmiEDCU1_Door6ComFlt,hmiEDCU1_Door6AddCodeFlt,hmiEDCU1_Door6MaintainBtnFlt;

   bool hmiEDCU1_Door7MotoLineBrk,hmiEDCU1_Door7ClockedInvalid,hmiEDCU1_Door7ClosedInvalid,hmiEDCU1_Door7NotUnlockIn3s,
   hmiEDCU1_Door7PSensorInvalid,hmiEDCU1_Door7OutClockedPnotAllowed,hmiEDCU1_Door7SafeRelayFlt,hmiEDCU1_Door7InterlockFlt,
   hmiEDCU1_Door7ClockFlt,hmiEDCU1_Door7CHinderNum,hmiEDCU1_Door7OHinderNum,hmiEDCU1_Door7O0OutShort,
   hmiEDCU1_Door7O1OutShort,hmiEDCU1_Door7O2OutShort,hmiEDCU1_Door7O3OutShort,hmiEDCU1_Door7RomFlt,
   hmiEDCU1_Door7ComFlt,hmiEDCU1_Door7AddCodeFlt,hmiEDCU1_Door7MaintainBtnFlt;

   bool hmiEDCU1_Door8MotoLineBrk,hmiEDCU1_Door8ClockedInvalid,hmiEDCU1_Door8ClosedInvalid,hmiEDCU1_Door8NotUnlockIn3s,
   hmiEDCU1_Door8PSensorInvalid,hmiEDCU1_Door8OutClockedPnotAllowed,hmiEDCU1_Door8SafeRelayFlt,hmiEDCU1_Door8InterlockFlt,
   hmiEDCU1_Door8ClockFlt,hmiEDCU1_Door8CHinderNum,hmiEDCU1_Door8OHinderNum,hmiEDCU1_Door8O0OutShort,
   hmiEDCU1_Door8O1OutShort,hmiEDCU1_Door8O2OutShort,hmiEDCU1_Door8O3OutShort,hmiEDCU1_Door8RomFlt,
   hmiEDCU1_Door8ComFlt,hmiEDCU1_Door8AddCodeFlt,hmiEDCU1_Door8MaintainBtnFlt;

   bool hmiEDCU1_Door1EnableFB,hmiEDCU1_Door1ZeroSpFB,hmiEDCU1_Door1OpenFB,hmiEDCU1_Door1NotOandCFB,
   hmiEDCU1_Door1CloseFB,hmiEDCU1_Door1OpenHinder,hmiEDCU1_Door1Safe1FB,hmiEDCU1_Door1Safe2FB,
   hmiEDCU1_Door1Closed,hmiEDCU1_Door1Opened,hmiEDCU1_Door1EMCunclock,hmiEDCU1_Door1Cut,
   hmiEDCU1_Door1CloseHinder,hmiEDCU1_Door1ReSwitchLineFB,hmiEDCU1_Door1SeriousFlt,hmiEDCU1_Door1SlightFlt;

   bool hmiEDCU1_Door2EnableFB,hmiEDCU1_Door2ZeroSpFB,hmiEDCU1_Door2OpenFB,hmiEDCU1_Door2NotOandCFB,
   hmiEDCU1_Door2CloseFB,hmiEDCU1_Door2OpenHinder,hmiEDCU1_Door2Safe1FB,hmiEDCU1_Door2Safe2FB,
   hmiEDCU1_Door2Closed,hmiEDCU1_Door2Opened,hmiEDCU1_Door2EMCunclock,hmiEDCU1_Door2Cut,
   hmiEDCU1_Door2CloseHinder,hmiEDCU1_Door2ReSwitchLineFB,hmiEDCU1_Door2SeriousFlt,hmiEDCU1_Door2SlightFlt;

   bool hmiEDCU1_Door3EnableFB,hmiEDCU1_Door3ZeroSpFB,hmiEDCU1_Door3OpenFB,hmiEDCU1_Door3NotOandCFB,
   hmiEDCU1_Door3CloseFB,hmiEDCU1_Door3OpenHinder,hmiEDCU1_Door3Safe1FB,hmiEDCU1_Door3Safe2FB,
   hmiEDCU1_Door3Closed,hmiEDCU1_Door3Opened,hmiEDCU1_Door3EMCunclock,hmiEDCU1_Door3Cut,
   hmiEDCU1_Door3CloseHinder,hmiEDCU1_Door3ReSwitchLineFB,hmiEDCU1_Door3SeriousFlt,hmiEDCU1_Door3SlightFlt;

   bool hmiEDCU1_Door4EnableFB,hmiEDCU1_Door4ZeroSpFB,hmiEDCU1_Door4OpenFB,hmiEDCU1_Door4NotOandCFB,
   hmiEDCU1_Door4CloseFB,hmiEDCU1_Door4OpenHinder,hmiEDCU1_Door4Safe1FB,hmiEDCU1_Door4Safe2FB,
   hmiEDCU1_Door4Closed,hmiEDCU1_Door4Opened,hmiEDCU1_Door4EMCunclock,hmiEDCU1_Door4Cut,
   hmiEDCU1_Door4CloseHinder,hmiEDCU1_Door4ReSwitchLineFB,hmiEDCU1_Door4SeriousFlt,hmiEDCU1_Door4SlightFlt;

   bool hmiEDCU1_Door5EnableFB,hmiEDCU1_Door5ZeroSpFB,hmiEDCU1_Door5OpenFB,hmiEDCU1_Door5NotOandCFB,
   hmiEDCU1_Door5CloseFB,hmiEDCU1_Door5OpenHinder,hmiEDCU1_Door5Safe1FB,hmiEDCU1_Door5Safe2FB,
   hmiEDCU1_Door5Closed,hmiEDCU1_Door5Opened,hmiEDCU1_Door5EMCunclock,hmiEDCU1_Door5Cut,
   hmiEDCU1_Door5CloseHinder,hmiEDCU1_Door5ReSwitchLineFB,hmiEDCU1_Door5SeriousFlt,hmiEDCU1_Door5SlightFlt;

   bool hmiEDCU1_Door6EnableFB,hmiEDCU1_Door6ZeroSpFB,hmiEDCU1_Door6OpenFB,hmiEDCU1_Door6NotOandCFB,
   hmiEDCU1_Door6CloseFB,hmiEDCU1_Door6OpenHinder,hmiEDCU1_Door6Safe1FB,hmiEDCU1_Door6Safe2FB,
   hmiEDCU1_Door6Closed,hmiEDCU1_Door6Opened,hmiEDCU1_Door6EMCunclock,hmiEDCU1_Door6Cut,
   hmiEDCU1_Door6CloseHinder,hmiEDCU1_Door6ReSwitchLineFB,hmiEDCU1_Door6SeriousFlt,hmiEDCU1_Door6SlightFlt;

   bool hmiEDCU1_Door7EnableFB,hmiEDCU1_Door7ZeroSpFB,hmiEDCU1_Door7OpenFB,hmiEDCU1_Door7NotOandCFB,
   hmiEDCU1_Door7CloseFB,hmiEDCU1_Door7OpenHinder,hmiEDCU1_Door7Safe1FB,hmiEDCU1_Door7Safe2FB,
   hmiEDCU1_Door7Closed,hmiEDCU1_Door7Opened,hmiEDCU1_Door7EMCunclock,hmiEDCU1_Door7Cut,
   hmiEDCU1_Door7CloseHinder,hmiEDCU1_Door7ReSwitchLineFB,hmiEDCU1_Door7SeriousFlt,hmiEDCU1_Door7SlightFlt;

   bool hmiEDCU1_Door8EnableFB,hmiEDCU1_Door8ZeroSpFB,hmiEDCU1_Door8OpenFB,hmiEDCU1_Door8NotOandCFB,
   hmiEDCU1_Door8CloseFB,hmiEDCU1_Door8OpenHinder,hmiEDCU1_Door8Safe1FB,hmiEDCU1_Door8Safe2FB,
   hmiEDCU1_Door8Closed,hmiEDCU1_Door8Opened,hmiEDCU1_Door8EMCunclock,hmiEDCU1_Door8Cut,
   hmiEDCU1_Door8CloseHinder,hmiEDCU1_Door8ReSwitchLineFB,hmiEDCU1_Door8SeriousFlt,hmiEDCU1_Door8SlightFlt;

   unsigned short int hmiEDCU1_OperationSt;
   bool hmiEDCU1_MDCU1DataValid,hmiEDCU1_MDCU2DataValid,hmiEDCU1_MDCU3DataValid,hmiEDCU1_MDCU4DataValid,
   hmiEDCU1_MDCU5DataValid,hmiEDCU1_MDCU6DataValid,hmiEDCU1_MDCU7DataValid,hmiEDCU1_MDCU8DataValid;

   unsigned short int hmiEDCU1_BusToken,hmiEDCU1_LifeSign;
   bool hmiEDCU1_CANBreak;
   unsigned short int hmiEDCU1_D1Version,hmiEDCU1_D2Version,hmiEDCU1_D3Version,hmiEDCU1_D4Version,
   hmiEDCU1_D5Version,hmiEDCU1_D6Version,hmiEDCU1_D7Version,hmiEDCU1_D8Version;

   //0xF730, 0xF731, 0xF732
   bool hmiEDCU2_Door1MotoLineBrk,hmiEDCU2_Door1ClockedInvalid,hmiEDCU2_Door1ClosedInvalid,hmiEDCU2_Door1NotUnlockIn3s,
   hmiEDCU2_Door1PSensorInvalid,hmiEDCU2_Door1OutClockedPnotAllowed,hmiEDCU2_Door1SafeRelayFlt,hmiEDCU2_Door1InterlockFlt,
   hmiEDCU2_Door1ClockFlt,hmiEDCU2_Door1CHinderNum,hmiEDCU2_Door1OHinderNum,hmiEDCU2_Door1O0OutShort,
   hmiEDCU2_Door1O1OutShort,hmiEDCU2_Door1O2OutShort,hmiEDCU2_Door1O3OutShort,hmiEDCU2_Door1RomFlt,
   hmiEDCU2_Door1ComFlt,hmiEDCU2_Door1AddCodeFlt,hmiEDCU2_Door1MaintainBtnFlt;

   bool hmiEDCU2_Door2MotoLineBrk,hmiEDCU2_Door2ClockedInvalid,hmiEDCU2_Door2ClosedInvalid,hmiEDCU2_Door2NotUnlockIn3s,
   hmiEDCU2_Door2PSensorInvalid,hmiEDCU2_Door2OutClockedPnotAllowed,hmiEDCU2_Door2SafeRelayFlt,hmiEDCU2_Door2InterlockFlt,
   hmiEDCU2_Door2ClockFlt,hmiEDCU2_Door2CHinderNum,hmiEDCU2_Door2OHinderNum,hmiEDCU2_Door2O0OutShort,
   hmiEDCU2_Door2O1OutShort,hmiEDCU2_Door2O2OutShort,hmiEDCU2_Door2O3OutShort,hmiEDCU2_Door2RomFlt,
   hmiEDCU2_Door2ComFlt,hmiEDCU2_Door2AddCodeFlt,hmiEDCU2_Door2MaintainBtnFlt;

   bool hmiEDCU2_Door3MotoLineBrk,hmiEDCU2_Door3ClockedInvalid,hmiEDCU2_Door3ClosedInvalid,hmiEDCU2_Door3NotUnlockIn3s,
   hmiEDCU2_Door3PSensorInvalid,hmiEDCU2_Door3OutClockedPnotAllowed,hmiEDCU2_Door3SafeRelayFlt,hmiEDCU2_Door3InterlockFlt,
   hmiEDCU2_Door3ClockFlt,hmiEDCU2_Door3CHinderNum,hmiEDCU2_Door3OHinderNum,hmiEDCU2_Door3O0OutShort,
   hmiEDCU2_Door3O1OutShort,hmiEDCU2_Door3O2OutShort,hmiEDCU2_Door3O3OutShort,hmiEDCU2_Door3RomFlt,
   hmiEDCU2_Door3ComFlt,hmiEDCU2_Door3AddCodeFlt,hmiEDCU2_Door3MaintainBtnFlt;

   bool hmiEDCU2_Door4MotoLineBrk,hmiEDCU2_Door4ClockedInvalid,hmiEDCU2_Door4ClosedInvalid,hmiEDCU2_Door4NotUnlockIn3s,
   hmiEDCU2_Door4PSensorInvalid,hmiEDCU2_Door4OutClockedPnotAllowed,hmiEDCU2_Door4SafeRelayFlt,hmiEDCU2_Door4InterlockFlt,
   hmiEDCU2_Door4ClockFlt,hmiEDCU2_Door4CHinderNum,hmiEDCU2_Door4OHinderNum,hmiEDCU2_Door4O0OutShort,
   hmiEDCU2_Door4O1OutShort,hmiEDCU2_Door4O2OutShort,hmiEDCU2_Door4O3OutShort,hmiEDCU2_Door4RomFlt,
   hmiEDCU2_Door4ComFlt,hmiEDCU2_Door4AddCodeFlt,hmiEDCU2_Door4MaintainBtnFlt;

   bool hmiEDCU2_Door5MotoLineBrk,hmiEDCU2_Door5ClockedInvalid,hmiEDCU2_Door5ClosedInvalid,hmiEDCU2_Door5NotUnlockIn3s,
   hmiEDCU2_Door5PSensorInvalid,hmiEDCU2_Door5OutClockedPnotAllowed,hmiEDCU2_Door5SafeRelayFlt,hmiEDCU2_Door5InterlockFlt,
   hmiEDCU2_Door5ClockFlt,hmiEDCU2_Door5CHinderNum,hmiEDCU2_Door5OHinderNum,hmiEDCU2_Door5O0OutShort,
   hmiEDCU2_Door5O1OutShort,hmiEDCU2_Door5O2OutShort,hmiEDCU2_Door5O3OutShort,hmiEDCU2_Door5RomFlt,
   hmiEDCU2_Door5ComFlt,hmiEDCU2_Door5AddCodeFlt,hmiEDCU2_Door5MaintainBtnFlt;

   bool hmiEDCU2_Door6MotoLineBrk,hmiEDCU2_Door6ClockedInvalid,hmiEDCU2_Door6ClosedInvalid,hmiEDCU2_Door6NotUnlockIn3s,
   hmiEDCU2_Door6PSensorInvalid,hmiEDCU2_Door6OutClockedPnotAllowed,hmiEDCU2_Door6SafeRelayFlt,hmiEDCU2_Door6InterlockFlt,
   hmiEDCU2_Door6ClockFlt,hmiEDCU2_Door6CHinderNum,hmiEDCU2_Door6OHinderNum,hmiEDCU2_Door6O0OutShort,
   hmiEDCU2_Door6O1OutShort,hmiEDCU2_Door6O2OutShort,hmiEDCU2_Door6O3OutShort,hmiEDCU2_Door6RomFlt,
   hmiEDCU2_Door6ComFlt,hmiEDCU2_Door6AddCodeFlt,hmiEDCU2_Door6MaintainBtnFlt;

   bool hmiEDCU2_Door7MotoLineBrk,hmiEDCU2_Door7ClockedInvalid,hmiEDCU2_Door7ClosedInvalid,hmiEDCU2_Door7NotUnlockIn3s,
   hmiEDCU2_Door7PSensorInvalid,hmiEDCU2_Door7OutClockedPnotAllowed,hmiEDCU2_Door7SafeRelayFlt,hmiEDCU2_Door7InterlockFlt,
   hmiEDCU2_Door7ClockFlt,hmiEDCU2_Door7CHinderNum,hmiEDCU2_Door7OHinderNum,hmiEDCU2_Door7O0OutShort,
   hmiEDCU2_Door7O1OutShort,hmiEDCU2_Door7O2OutShort,hmiEDCU2_Door7O3OutShort,hmiEDCU2_Door7RomFlt,
   hmiEDCU2_Door7ComFlt,hmiEDCU2_Door7AddCodeFlt,hmiEDCU2_Door7MaintainBtnFlt;

   bool hmiEDCU2_Door8MotoLineBrk,hmiEDCU2_Door8ClockedInvalid,hmiEDCU2_Door8ClosedInvalid,hmiEDCU2_Door8NotUnlockIn3s,
   hmiEDCU2_Door8PSensorInvalid,hmiEDCU2_Door8OutClockedPnotAllowed,hmiEDCU2_Door8SafeRelayFlt,hmiEDCU2_Door8InterlockFlt,
   hmiEDCU2_Door8ClockFlt,hmiEDCU2_Door8CHinderNum,hmiEDCU2_Door8OHinderNum,hmiEDCU2_Door8O0OutShort,
   hmiEDCU2_Door8O1OutShort,hmiEDCU2_Door8O2OutShort,hmiEDCU2_Door8O3OutShort,hmiEDCU2_Door8RomFlt,
   hmiEDCU2_Door8ComFlt,hmiEDCU2_Door8AddCodeFlt,hmiEDCU2_Door8MaintainBtnFlt;

   bool hmiEDCU2_Door1EnableFB,hmiEDCU2_Door1ZeroSpFB,hmiEDCU2_Door1OpenFB,hmiEDCU2_Door1NotOandCFB,
   hmiEDCU2_Door1CloseFB,hmiEDCU2_Door1OpenHinder,hmiEDCU2_Door1Safe1FB,hmiEDCU2_Door1Safe2FB,
   hmiEDCU2_Door1Closed,hmiEDCU2_Door1Opened,hmiEDCU2_Door1EMCunclock,hmiEDCU2_Door1Cut,
   hmiEDCU2_Door1CloseHinder,hmiEDCU2_Door1ReSwitchLineFB,hmiEDCU2_Door1SeriousFlt,hmiEDCU2_Door1SlightFlt;

   bool hmiEDCU2_Door2EnableFB,hmiEDCU2_Door2ZeroSpFB,hmiEDCU2_Door2OpenFB,hmiEDCU2_Door2NotOandCFB,
   hmiEDCU2_Door2CloseFB,hmiEDCU2_Door2OpenHinder,hmiEDCU2_Door2Safe1FB,hmiEDCU2_Door2Safe2FB,
   hmiEDCU2_Door2Closed,hmiEDCU2_Door2Opened,hmiEDCU2_Door2EMCunclock,hmiEDCU2_Door2Cut,
   hmiEDCU2_Door2CloseHinder,hmiEDCU2_Door2ReSwitchLineFB,hmiEDCU2_Door2SeriousFlt,hmiEDCU2_Door2SlightFlt;

   bool hmiEDCU2_Door3EnableFB,hmiEDCU2_Door3ZeroSpFB,hmiEDCU2_Door3OpenFB,hmiEDCU2_Door3NotOandCFB,
   hmiEDCU2_Door3CloseFB,hmiEDCU2_Door3OpenHinder,hmiEDCU2_Door3Safe1FB,hmiEDCU2_Door3Safe2FB,
   hmiEDCU2_Door3Closed,hmiEDCU2_Door3Opened,hmiEDCU2_Door3EMCunclock,hmiEDCU2_Door3Cut,
   hmiEDCU2_Door3CloseHinder,hmiEDCU2_Door3ReSwitchLineFB,hmiEDCU2_Door3SeriousFlt,hmiEDCU2_Door3SlightFlt;

   bool hmiEDCU2_Door4EnableFB,hmiEDCU2_Door4ZeroSpFB,hmiEDCU2_Door4OpenFB,hmiEDCU2_Door4NotOandCFB,
   hmiEDCU2_Door4CloseFB,hmiEDCU2_Door4OpenHinder,hmiEDCU2_Door4Safe1FB,hmiEDCU2_Door4Safe2FB,
   hmiEDCU2_Door4Closed,hmiEDCU2_Door4Opened,hmiEDCU2_Door4EMCunclock,hmiEDCU2_Door4Cut,
   hmiEDCU2_Door4CloseHinder,hmiEDCU2_Door4ReSwitchLineFB,hmiEDCU2_Door4SeriousFlt,hmiEDCU2_Door4SlightFlt;

   bool hmiEDCU2_Door5EnableFB,hmiEDCU2_Door5ZeroSpFB,hmiEDCU2_Door5OpenFB,hmiEDCU2_Door5NotOandCFB,
   hmiEDCU2_Door5CloseFB,hmiEDCU2_Door5OpenHinder,hmiEDCU2_Door5Safe1FB,hmiEDCU2_Door5Safe2FB,
   hmiEDCU2_Door5Closed,hmiEDCU2_Door5Opened,hmiEDCU2_Door5EMCunclock,hmiEDCU2_Door5Cut,
   hmiEDCU2_Door5CloseHinder,hmiEDCU2_Door5ReSwitchLineFB,hmiEDCU2_Door5SeriousFlt,hmiEDCU2_Door5SlightFlt;

   bool hmiEDCU2_Door6EnableFB,hmiEDCU2_Door6ZeroSpFB,hmiEDCU2_Door6OpenFB,hmiEDCU2_Door6NotOandCFB,
   hmiEDCU2_Door6CloseFB,hmiEDCU2_Door6OpenHinder,hmiEDCU2_Door6Safe1FB,hmiEDCU2_Door6Safe2FB,
   hmiEDCU2_Door6Closed,hmiEDCU2_Door6Opened,hmiEDCU2_Door6EMCunclock,hmiEDCU2_Door6Cut,
   hmiEDCU2_Door6CloseHinder,hmiEDCU2_Door6ReSwitchLineFB,hmiEDCU2_Door6SeriousFlt,hmiEDCU2_Door6SlightFlt;

   bool hmiEDCU2_Door7EnableFB,hmiEDCU2_Door7ZeroSpFB,hmiEDCU2_Door7OpenFB,hmiEDCU2_Door7NotOandCFB,
   hmiEDCU2_Door7CloseFB,hmiEDCU2_Door7OpenHinder,hmiEDCU2_Door7Safe1FB,hmiEDCU2_Door7Safe2FB,
   hmiEDCU2_Door7Closed,hmiEDCU2_Door7Opened,hmiEDCU2_Door7EMCunclock,hmiEDCU2_Door7Cut,
   hmiEDCU2_Door7CloseHinder,hmiEDCU2_Door7ReSwitchLineFB,hmiEDCU2_Door7SeriousFlt,hmiEDCU2_Door7SlightFlt;

   bool hmiEDCU2_Door8EnableFB,hmiEDCU2_Door8ZeroSpFB,hmiEDCU2_Door8OpenFB,hmiEDCU2_Door8NotOandCFB,
   hmiEDCU2_Door8CloseFB,hmiEDCU2_Door8OpenHinder,hmiEDCU2_Door8Safe1FB,hmiEDCU2_Door8Safe2FB,
   hmiEDCU2_Door8Closed,hmiEDCU2_Door8Opened,hmiEDCU2_Door8EMCunclock,hmiEDCU2_Door8Cut,
   hmiEDCU2_Door8CloseHinder,hmiEDCU2_Door8ReSwitchLineFB,hmiEDCU2_Door8SeriousFlt,hmiEDCU2_Door8SlightFlt;

   unsigned short int hmiEDCU2_OperationSt;

   bool hmiEDCU2_MDCU1DataValid,hmiEDCU2_MDCU2DataValid,hmiEDCU2_MDCU3DataValid,hmiEDCU2_MDCU4DataValid,
   hmiEDCU2_MDCU5DataValid,hmiEDCU2_MDCU6DataValid,hmiEDCU2_MDCU7DataValid,hmiEDCU2_MDCU8DataValid;
   unsigned short int hmiEDCU2_BusToken,hmiEDCU2_LifeSign;

   bool hmiEDCU2_CANBreak;
   unsigned short int hmiEDCU2_D1Version,hmiEDCU2_D2Version,hmiEDCU2_D3Version,hmiEDCU2_D4Version,
   hmiEDCU2_D5Version,hmiEDCU2_D6Version,hmiEDCU2_D7Version,hmiEDCU2_D8Version;

   bool hmiEDCU3_Door1MotoLineBrk,hmiEDCU3_Door1ClockedInvalid,hmiEDCU3_Door1ClosedInvalid,hmiEDCU3_Door1NotUnlockIn3s,
   hmiEDCU3_Door1PSensorInvalid,hmiEDCU3_Door1OutClockedPnotAllowed,hmiEDCU3_Door1SafeRelayFlt,hmiEDCU3_Door1InterlockFlt,
   hmiEDCU3_Door1ClockFlt,hmiEDCU3_Door1CHinderNum,hmiEDCU3_Door1OHinderNum,hmiEDCU3_Door1O0OutShort,
   hmiEDCU3_Door1O1OutShort,hmiEDCU3_Door1O2OutShort,hmiEDCU3_Door1O3OutShort,hmiEDCU3_Door1RomFlt,
   hmiEDCU3_Door1ComFlt,hmiEDCU3_Door1AddCodeFlt,hmiEDCU3_Door1MaintainBtnFlt;

   bool hmiEDCU3_Door2MotoLineBrk,hmiEDCU3_Door2ClockedInvalid,hmiEDCU3_Door2ClosedInvalid,hmiEDCU3_Door2NotUnlockIn3s,
   hmiEDCU3_Door2PSensorInvalid,hmiEDCU3_Door2OutClockedPnotAllowed,hmiEDCU3_Door2SafeRelayFlt,hmiEDCU3_Door2InterlockFlt,
   hmiEDCU3_Door2ClockFlt,hmiEDCU3_Door2CHinderNum,hmiEDCU3_Door2OHinderNum,hmiEDCU3_Door2O0OutShort,
   hmiEDCU3_Door2O1OutShort,hmiEDCU3_Door2O2OutShort,hmiEDCU3_Door2O3OutShort,hmiEDCU3_Door2RomFlt,
   hmiEDCU3_Door2ComFlt,hmiEDCU3_Door2AddCodeFlt,hmiEDCU3_Door2MaintainBtnFlt;

   bool hmiEDCU3_Door3MotoLineBrk,hmiEDCU3_Door3ClockedInvalid,hmiEDCU3_Door3ClosedInvalid,hmiEDCU3_Door3NotUnlockIn3s,
   hmiEDCU3_Door3PSensorInvalid,hmiEDCU3_Door3OutClockedPnotAllowed,hmiEDCU3_Door3SafeRelayFlt,hmiEDCU3_Door3InterlockFlt,
   hmiEDCU3_Door3ClockFlt,hmiEDCU3_Door3CHinderNum,hmiEDCU3_Door3OHinderNum,hmiEDCU3_Door3O0OutShort,
   hmiEDCU3_Door3O1OutShort,hmiEDCU3_Door3O2OutShort,hmiEDCU3_Door3O3OutShort,hmiEDCU3_Door3RomFlt,
   hmiEDCU3_Door3ComFlt,hmiEDCU3_Door3AddCodeFlt,hmiEDCU3_Door3MaintainBtnFlt;

   bool hmiEDCU3_Door4MotoLineBrk,hmiEDCU3_Door4ClockedInvalid,hmiEDCU3_Door4ClosedInvalid,hmiEDCU3_Door4NotUnlockIn3s,
   hmiEDCU3_Door4PSensorInvalid,hmiEDCU3_Door4OutClockedPnotAllowed,hmiEDCU3_Door4SafeRelayFlt,hmiEDCU3_Door4InterlockFlt,
   hmiEDCU3_Door4ClockFlt,hmiEDCU3_Door4CHinderNum,hmiEDCU3_Door4OHinderNum,hmiEDCU3_Door4O0OutShort,
   hmiEDCU3_Door4O1OutShort,hmiEDCU3_Door4O2OutShort,hmiEDCU3_Door4O3OutShort,hmiEDCU3_Door4RomFlt,
   hmiEDCU3_Door4ComFlt,hmiEDCU3_Door4AddCodeFlt,hmiEDCU3_Door4MaintainBtnFlt;

   bool hmiEDCU3_Door5MotoLineBrk,hmiEDCU3_Door5ClockedInvalid,hmiEDCU3_Door5ClosedInvalid,hmiEDCU3_Door5NotUnlockIn3s,
   hmiEDCU3_Door5PSensorInvalid,hmiEDCU3_Door5OutClockedPnotAllowed,hmiEDCU3_Door5SafeRelayFlt,hmiEDCU3_Door5InterlockFlt,
   hmiEDCU3_Door5ClockFlt,hmiEDCU3_Door5CHinderNum,hmiEDCU3_Door5OHinderNum,hmiEDCU3_Door5O0OutShort,
   hmiEDCU3_Door5O1OutShort,hmiEDCU3_Door5O2OutShort,hmiEDCU3_Door5O3OutShort,hmiEDCU3_Door5RomFlt,
   hmiEDCU3_Door5ComFlt,hmiEDCU3_Door5AddCodeFlt,hmiEDCU3_Door5MaintainBtnFlt;

   bool hmiEDCU3_Door6MotoLineBrk,hmiEDCU3_Door6ClockedInvalid,hmiEDCU3_Door6ClosedInvalid,hmiEDCU3_Door6NotUnlockIn3s,
   hmiEDCU3_Door6PSensorInvalid,hmiEDCU3_Door6OutClockedPnotAllowed,hmiEDCU3_Door6SafeRelayFlt,hmiEDCU3_Door6InterlockFlt,
   hmiEDCU3_Door6ClockFlt,hmiEDCU3_Door6CHinderNum,hmiEDCU3_Door6OHinderNum,hmiEDCU3_Door6O0OutShort,
   hmiEDCU3_Door6O1OutShort,hmiEDCU3_Door6O2OutShort,hmiEDCU3_Door6O3OutShort,hmiEDCU3_Door6RomFlt,
   hmiEDCU3_Door6ComFlt,hmiEDCU3_Door6AddCodeFlt,hmiEDCU3_Door6MaintainBtnFlt;

   bool hmiEDCU3_Door7MotoLineBrk,hmiEDCU3_Door7ClockedInvalid,hmiEDCU3_Door7ClosedInvalid,hmiEDCU3_Door7NotUnlockIn3s,
   hmiEDCU3_Door7PSensorInvalid,hmiEDCU3_Door7OutClockedPnotAllowed,hmiEDCU3_Door7SafeRelayFlt,hmiEDCU3_Door7InterlockFlt,
   hmiEDCU3_Door7ClockFlt,hmiEDCU3_Door7CHinderNum,hmiEDCU3_Door7OHinderNum,hmiEDCU3_Door7O0OutShort,
   hmiEDCU3_Door7O1OutShort,hmiEDCU3_Door7O2OutShort,hmiEDCU3_Door7O3OutShort,hmiEDCU3_Door7RomFlt,
   hmiEDCU3_Door7ComFlt,hmiEDCU3_Door7AddCodeFlt,hmiEDCU3_Door7MaintainBtnFlt;

   bool hmiEDCU3_Door8MotoLineBrk,hmiEDCU3_Door8ClockedInvalid,hmiEDCU3_Door8ClosedInvalid,hmiEDCU3_Door8NotUnlockIn3s,
   hmiEDCU3_Door8PSensorInvalid,hmiEDCU3_Door8OutClockedPnotAllowed,hmiEDCU3_Door8SafeRelayFlt,hmiEDCU3_Door8InterlockFlt,
   hmiEDCU3_Door8ClockFlt,hmiEDCU3_Door8CHinderNum,hmiEDCU3_Door8OHinderNum,hmiEDCU3_Door8O0OutShort,
   hmiEDCU3_Door8O1OutShort,hmiEDCU3_Door8O2OutShort,hmiEDCU3_Door8O3OutShort,hmiEDCU3_Door8RomFlt,
   hmiEDCU3_Door8ComFlt,hmiEDCU3_Door8AddCodeFlt,hmiEDCU3_Door8MaintainBtnFlt;

   bool hmiEDCU3_Door1EnableFB,hmiEDCU3_Door1ZeroSpFB,hmiEDCU3_Door1OpenFB,hmiEDCU3_Door1NotOandCFB,
   hmiEDCU3_Door1CloseFB,hmiEDCU3_Door1OpenHinder,hmiEDCU3_Door1Safe1FB,hmiEDCU3_Door1Safe2FB,
   hmiEDCU3_Door1Closed,hmiEDCU3_Door1Opened,hmiEDCU3_Door1EMCunclock,hmiEDCU3_Door1Cut,
   hmiEDCU3_Door1CloseHinder,hmiEDCU3_Door1ReSwitchLineFB,hmiEDCU3_Door1SeriousFlt,hmiEDCU3_Door1SlightFlt;

   bool hmiEDCU3_Door2EnableFB,hmiEDCU3_Door2ZeroSpFB,hmiEDCU3_Door2OpenFB,hmiEDCU3_Door2NotOandCFB,
   hmiEDCU3_Door2CloseFB,hmiEDCU3_Door2OpenHinder,hmiEDCU3_Door2Safe1FB,hmiEDCU3_Door2Safe2FB,
   hmiEDCU3_Door2Closed,hmiEDCU3_Door2Opened,hmiEDCU3_Door2EMCunclock,hmiEDCU3_Door2Cut,
   hmiEDCU3_Door2CloseHinder,hmiEDCU3_Door2ReSwitchLineFB,hmiEDCU3_Door2SeriousFlt,hmiEDCU3_Door2SlightFlt;

   bool hmiEDCU3_Door3EnableFB,hmiEDCU3_Door3ZeroSpFB,hmiEDCU3_Door3OpenFB,hmiEDCU3_Door3NotOandCFB,
   hmiEDCU3_Door3CloseFB,hmiEDCU3_Door3OpenHinder,hmiEDCU3_Door3Safe1FB,hmiEDCU3_Door3Safe2FB,
   hmiEDCU3_Door3Closed,hmiEDCU3_Door3Opened,hmiEDCU3_Door3EMCunclock,hmiEDCU3_Door3Cut,
   hmiEDCU3_Door3CloseHinder,hmiEDCU3_Door3ReSwitchLineFB,hmiEDCU3_Door3SeriousFlt,hmiEDCU3_Door3SlightFlt;

   bool hmiEDCU3_Door4EnableFB,hmiEDCU3_Door4ZeroSpFB,hmiEDCU3_Door4OpenFB,hmiEDCU3_Door4NotOandCFB,
   hmiEDCU3_Door4CloseFB,hmiEDCU3_Door4OpenHinder,hmiEDCU3_Door4Safe1FB,hmiEDCU3_Door4Safe2FB,
   hmiEDCU3_Door4Closed,hmiEDCU3_Door4Opened,hmiEDCU3_Door4EMCunclock,hmiEDCU3_Door4Cut,
   hmiEDCU3_Door4CloseHinder,hmiEDCU3_Door4ReSwitchLineFB,hmiEDCU3_Door4SeriousFlt,hmiEDCU3_Door4SlightFlt;

   bool hmiEDCU3_Door5EnableFB,hmiEDCU3_Door5ZeroSpFB,hmiEDCU3_Door5OpenFB,hmiEDCU3_Door5NotOandCFB,
   hmiEDCU3_Door5CloseFB,hmiEDCU3_Door5OpenHinder,hmiEDCU3_Door5Safe1FB,hmiEDCU3_Door5Safe2FB,
   hmiEDCU3_Door5Closed,hmiEDCU3_Door5Opened,hmiEDCU3_Door5EMCunclock,hmiEDCU3_Door5Cut,
   hmiEDCU3_Door5CloseHinder,hmiEDCU3_Door5ReSwitchLineFB,hmiEDCU3_Door5SeriousFlt,hmiEDCU3_Door5SlightFlt;

   bool hmiEDCU3_Door6EnableFB,hmiEDCU3_Door6ZeroSpFB,hmiEDCU3_Door6OpenFB,hmiEDCU3_Door6NotOandCFB,
   hmiEDCU3_Door6CloseFB,hmiEDCU3_Door6OpenHinder,hmiEDCU3_Door6Safe1FB,hmiEDCU3_Door6Safe2FB,
   hmiEDCU3_Door6Closed,hmiEDCU3_Door6Opened,hmiEDCU3_Door6EMCunclock,hmiEDCU3_Door6Cut,
   hmiEDCU3_Door6CloseHinder,hmiEDCU3_Door6ReSwitchLineFB,hmiEDCU3_Door6SeriousFlt,hmiEDCU3_Door6SlightFlt;

   bool hmiEDCU3_Door7EnableFB,hmiEDCU3_Door7ZeroSpFB,hmiEDCU3_Door7OpenFB,hmiEDCU3_Door7NotOandCFB,
   hmiEDCU3_Door7CloseFB,hmiEDCU3_Door7OpenHinder,hmiEDCU3_Door7Safe1FB,hmiEDCU3_Door7Safe2FB,
   hmiEDCU3_Door7Closed,hmiEDCU3_Door7Opened,hmiEDCU3_Door7EMCunclock,hmiEDCU3_Door7Cut,
   hmiEDCU3_Door7CloseHinder,hmiEDCU3_Door7ReSwitchLineFB,hmiEDCU3_Door7SeriousFlt,hmiEDCU3_Door7SlightFlt;

   bool hmiEDCU3_Door8EnableFB,hmiEDCU3_Door8ZeroSpFB,hmiEDCU3_Door8OpenFB,hmiEDCU3_Door8NotOandCFB,
   hmiEDCU3_Door8CloseFB,hmiEDCU3_Door8OpenHinder,hmiEDCU3_Door8Safe1FB,hmiEDCU3_Door8Safe2FB,
   hmiEDCU3_Door8Closed,hmiEDCU3_Door8Opened,hmiEDCU3_Door8EMCunclock,hmiEDCU3_Door8Cut,
   hmiEDCU3_Door8CloseHinder,hmiEDCU3_Door8ReSwitchLineFB,hmiEDCU3_Door8SeriousFlt,hmiEDCU3_Door8SlightFlt;

   unsigned short int hmiEDCU3_OperationSt;
   bool hmiEDCU3_MDCU1DataValid,hmiEDCU3_MDCU2DataValid,hmiEDCU3_MDCU3DataValid,hmiEDCU3_MDCU4DataValid,
   hmiEDCU3_MDCU5DataValid,hmiEDCU3_MDCU6DataValid,hmiEDCU3_MDCU7DataValid,hmiEDCU3_MDCU8DataValid;

   unsigned short int hmiEDCU3_BusToken,hmiEDCU3_LifeSign;
   bool hmiEDCU3_CANBreak;
   unsigned short int hmiEDCU3_D1Version,hmiEDCU3_D2Version,hmiEDCU3_D3Version,hmiEDCU3_D4Version,
   hmiEDCU3_D5Version,hmiEDCU3_D6Version,hmiEDCU3_D7Version,hmiEDCU3_D8Version;

   ////0xF730, 0xF731, 0xF732
   bool hmiEDCU4_Door1MotoLineBrk,hmiEDCU4_Door1ClockedInvalid,hmiEDCU4_Door1ClosedInvalid,hmiEDCU4_Door1NotUnlockIn3s,
   hmiEDCU4_Door1PSensorInvalid,hmiEDCU4_Door1OutClockedPnotAllowed,hmiEDCU4_Door1SafeRelayFlt,hmiEDCU4_Door1InterlockFlt,
   hmiEDCU4_Door1ClockFlt,hmiEDCU4_Door1CHinderNum,hmiEDCU4_Door1OHinderNum,hmiEDCU4_Door1O0OutShort,
   hmiEDCU4_Door1O1OutShort,hmiEDCU4_Door1O2OutShort,hmiEDCU4_Door1O3OutShort,hmiEDCU4_Door1RomFlt,
   hmiEDCU4_Door1ComFlt,hmiEDCU4_Door1AddCodeFlt,hmiEDCU4_Door1MaintainBtnFlt;

   bool hmiEDCU4_Door2MotoLineBrk,hmiEDCU4_Door2ClockedInvalid,hmiEDCU4_Door2ClosedInvalid,hmiEDCU4_Door2NotUnlockIn3s,
   hmiEDCU4_Door2PSensorInvalid,hmiEDCU4_Door2OutClockedPnotAllowed,hmiEDCU4_Door2SafeRelayFlt,hmiEDCU4_Door2InterlockFlt,
   hmiEDCU4_Door2ClockFlt,hmiEDCU4_Door2CHinderNum,hmiEDCU4_Door2OHinderNum,hmiEDCU4_Door2O0OutShort,
   hmiEDCU4_Door2O1OutShort,hmiEDCU4_Door2O2OutShort,hmiEDCU4_Door2O3OutShort,hmiEDCU4_Door2RomFlt,
   hmiEDCU4_Door2ComFlt,hmiEDCU4_Door2AddCodeFlt,hmiEDCU4_Door2MaintainBtnFlt;

   bool hmiEDCU4_Door3MotoLineBrk,hmiEDCU4_Door3ClockedInvalid,hmiEDCU4_Door3ClosedInvalid,hmiEDCU4_Door3NotUnlockIn3s,
   hmiEDCU4_Door3PSensorInvalid,hmiEDCU4_Door3OutClockedPnotAllowed,hmiEDCU4_Door3SafeRelayFlt,hmiEDCU4_Door3InterlockFlt,
   hmiEDCU4_Door3ClockFlt,hmiEDCU4_Door3CHinderNum,hmiEDCU4_Door3OHinderNum,hmiEDCU4_Door3O0OutShort,
   hmiEDCU4_Door3O1OutShort,hmiEDCU4_Door3O2OutShort,hmiEDCU4_Door3O3OutShort,hmiEDCU4_Door3RomFlt,
   hmiEDCU4_Door3ComFlt,hmiEDCU4_Door3AddCodeFlt,hmiEDCU4_Door3MaintainBtnFlt;

   bool hmiEDCU4_Door4MotoLineBrk,hmiEDCU4_Door4ClockedInvalid,hmiEDCU4_Door4ClosedInvalid,hmiEDCU4_Door4NotUnlockIn3s,
   hmiEDCU4_Door4PSensorInvalid,hmiEDCU4_Door4OutClockedPnotAllowed,hmiEDCU4_Door4SafeRelayFlt,hmiEDCU4_Door4InterlockFlt,
   hmiEDCU4_Door4ClockFlt,hmiEDCU4_Door4CHinderNum,hmiEDCU4_Door4OHinderNum,hmiEDCU4_Door4O0OutShort,
   hmiEDCU4_Door4O1OutShort,hmiEDCU4_Door4O2OutShort,hmiEDCU4_Door4O3OutShort,hmiEDCU4_Door4RomFlt,
   hmiEDCU4_Door4ComFlt,hmiEDCU4_Door4AddCodeFlt,hmiEDCU4_Door4MaintainBtnFlt;

   bool hmiEDCU4_Door5MotoLineBrk,hmiEDCU4_Door5ClockedInvalid,hmiEDCU4_Door5ClosedInvalid,hmiEDCU4_Door5NotUnlockIn3s,
   hmiEDCU4_Door5PSensorInvalid,hmiEDCU4_Door5OutClockedPnotAllowed,hmiEDCU4_Door5SafeRelayFlt,hmiEDCU4_Door5InterlockFlt,
   hmiEDCU4_Door5ClockFlt,hmiEDCU4_Door5CHinderNum,hmiEDCU4_Door5OHinderNum,hmiEDCU4_Door5O0OutShort,
   hmiEDCU4_Door5O1OutShort,hmiEDCU4_Door5O2OutShort,hmiEDCU4_Door5O3OutShort,hmiEDCU4_Door5RomFlt,
   hmiEDCU4_Door5ComFlt,hmiEDCU4_Door5AddCodeFlt,hmiEDCU4_Door5MaintainBtnFlt;

   bool hmiEDCU4_Door6MotoLineBrk,hmiEDCU4_Door6ClockedInvalid,hmiEDCU4_Door6ClosedInvalid,hmiEDCU4_Door6NotUnlockIn3s,
   hmiEDCU4_Door6PSensorInvalid,hmiEDCU4_Door6OutClockedPnotAllowed,hmiEDCU4_Door6SafeRelayFlt,hmiEDCU4_Door6InterlockFlt,
   hmiEDCU4_Door6ClockFlt,hmiEDCU4_Door6CHinderNum,hmiEDCU4_Door6OHinderNum,hmiEDCU4_Door6O0OutShort,
   hmiEDCU4_Door6O1OutShort,hmiEDCU4_Door6O2OutShort,hmiEDCU4_Door6O3OutShort,hmiEDCU4_Door6RomFlt,
   hmiEDCU4_Door6ComFlt,hmiEDCU4_Door6AddCodeFlt,hmiEDCU4_Door6MaintainBtnFlt;

   bool hmiEDCU4_Door7MotoLineBrk,hmiEDCU4_Door7ClockedInvalid,hmiEDCU4_Door7ClosedInvalid,hmiEDCU4_Door7NotUnlockIn3s,
   hmiEDCU4_Door7PSensorInvalid,hmiEDCU4_Door7OutClockedPnotAllowed,hmiEDCU4_Door7SafeRelayFlt,hmiEDCU4_Door7InterlockFlt,
   hmiEDCU4_Door7ClockFlt,hmiEDCU4_Door7CHinderNum,hmiEDCU4_Door7OHinderNum,hmiEDCU4_Door7O0OutShort,
   hmiEDCU4_Door7O1OutShort,hmiEDCU4_Door7O2OutShort,hmiEDCU4_Door7O3OutShort,hmiEDCU4_Door7RomFlt,
   hmiEDCU4_Door7ComFlt,hmiEDCU4_Door7AddCodeFlt,hmiEDCU4_Door7MaintainBtnFlt;

   bool hmiEDCU4_Door8MotoLineBrk,hmiEDCU4_Door8ClockedInvalid,hmiEDCU4_Door8ClosedInvalid,hmiEDCU4_Door8NotUnlockIn3s,
   hmiEDCU4_Door8PSensorInvalid,hmiEDCU4_Door8OutClockedPnotAllowed,hmiEDCU4_Door8SafeRelayFlt,hmiEDCU4_Door8InterlockFlt,
   hmiEDCU4_Door8ClockFlt,hmiEDCU4_Door8CHinderNum,hmiEDCU4_Door8OHinderNum,hmiEDCU4_Door8O0OutShort,
   hmiEDCU4_Door8O1OutShort,hmiEDCU4_Door8O2OutShort,hmiEDCU4_Door8O3OutShort,hmiEDCU4_Door8RomFlt,
   hmiEDCU4_Door8ComFlt,hmiEDCU4_Door8AddCodeFlt,hmiEDCU4_Door8MaintainBtnFlt;

   bool hmiEDCU4_Door1EnableFB,hmiEDCU4_Door1ZeroSpFB,hmiEDCU4_Door1OpenFB,hmiEDCU4_Door1NotOandCFB,
   hmiEDCU4_Door1CloseFB,hmiEDCU4_Door1OpenHinder,hmiEDCU4_Door1Safe1FB,hmiEDCU4_Door1Safe2FB,
   hmiEDCU4_Door1Closed,hmiEDCU4_Door1Opened,hmiEDCU4_Door1EMCunclock,hmiEDCU4_Door1Cut,
   hmiEDCU4_Door1CloseHinder,hmiEDCU4_Door1ReSwitchLineFB,hmiEDCU4_Door1SeriousFlt,hmiEDCU4_Door1SlightFlt;

   bool hmiEDCU4_Door2EnableFB,hmiEDCU4_Door2ZeroSpFB,hmiEDCU4_Door2OpenFB,hmiEDCU4_Door2NotOandCFB,
   hmiEDCU4_Door2CloseFB,hmiEDCU4_Door2OpenHinder,hmiEDCU4_Door2Safe1FB,hmiEDCU4_Door2Safe2FB,
   hmiEDCU4_Door2Closed,hmiEDCU4_Door2Opened,hmiEDCU4_Door2EMCunclock,hmiEDCU4_Door2Cut,
   hmiEDCU4_Door2CloseHinder,hmiEDCU4_Door2ReSwitchLineFB,hmiEDCU4_Door2SeriousFlt,hmiEDCU4_Door2SlightFlt;

   bool hmiEDCU4_Door3EnableFB,hmiEDCU4_Door3ZeroSpFB,hmiEDCU4_Door3OpenFB,hmiEDCU4_Door3NotOandCFB,
   hmiEDCU4_Door3CloseFB,hmiEDCU4_Door3OpenHinder,hmiEDCU4_Door3Safe1FB,hmiEDCU4_Door3Safe2FB,
   hmiEDCU4_Door3Closed,hmiEDCU4_Door3Opened,hmiEDCU4_Door3EMCunclock,hmiEDCU4_Door3Cut,
   hmiEDCU4_Door3CloseHinder,hmiEDCU4_Door3ReSwitchLineFB,hmiEDCU4_Door3SeriousFlt,hmiEDCU4_Door3SlightFlt;

   bool hmiEDCU4_Door4EnableFB,hmiEDCU4_Door4ZeroSpFB,hmiEDCU4_Door4OpenFB,hmiEDCU4_Door4NotOandCFB,
   hmiEDCU4_Door4CloseFB,hmiEDCU4_Door4OpenHinder,hmiEDCU4_Door4Safe1FB,hmiEDCU4_Door4Safe2FB,
   hmiEDCU4_Door4Closed,hmiEDCU4_Door4Opened,hmiEDCU4_Door4EMCunclock,hmiEDCU4_Door4Cut,
   hmiEDCU4_Door4CloseHinder,hmiEDCU4_Door4ReSwitchLineFB,hmiEDCU4_Door4SeriousFlt,hmiEDCU4_Door4SlightFlt;

   bool hmiEDCU4_Door5EnableFB,hmiEDCU4_Door5ZeroSpFB,hmiEDCU4_Door5OpenFB,hmiEDCU4_Door5NotOandCFB,
   hmiEDCU4_Door5CloseFB,hmiEDCU4_Door5OpenHinder,hmiEDCU4_Door5Safe1FB,hmiEDCU4_Door5Safe2FB,
   hmiEDCU4_Door5Closed,hmiEDCU4_Door5Opened,hmiEDCU4_Door5EMCunclock,hmiEDCU4_Door5Cut,
   hmiEDCU4_Door5CloseHinder,hmiEDCU4_Door5ReSwitchLineFB,hmiEDCU4_Door5SeriousFlt,hmiEDCU4_Door5SlightFlt;

   bool hmiEDCU4_Door6EnableFB,hmiEDCU4_Door6ZeroSpFB,hmiEDCU4_Door6OpenFB,hmiEDCU4_Door6NotOandCFB,
   hmiEDCU4_Door6CloseFB,hmiEDCU4_Door6OpenHinder,hmiEDCU4_Door6Safe1FB,hmiEDCU4_Door6Safe2FB,
   hmiEDCU4_Door6Closed,hmiEDCU4_Door6Opened,hmiEDCU4_Door6EMCunclock,hmiEDCU4_Door6Cut,
   hmiEDCU4_Door6CloseHinder,hmiEDCU4_Door6ReSwitchLineFB,hmiEDCU4_Door6SeriousFlt,hmiEDCU4_Door6SlightFlt;

   bool hmiEDCU4_Door7EnableFB,hmiEDCU4_Door7ZeroSpFB,hmiEDCU4_Door7OpenFB,hmiEDCU4_Door7NotOandCFB,
   hmiEDCU4_Door7CloseFB,hmiEDCU4_Door7OpenHinder,hmiEDCU4_Door7Safe1FB,hmiEDCU4_Door7Safe2FB,
   hmiEDCU4_Door7Closed,hmiEDCU4_Door7Opened,hmiEDCU4_Door7EMCunclock,hmiEDCU4_Door7Cut,
   hmiEDCU4_Door7CloseHinder,hmiEDCU4_Door7ReSwitchLineFB,hmiEDCU4_Door7SeriousFlt,hmiEDCU4_Door7SlightFlt;

   bool hmiEDCU4_Door8EnableFB,hmiEDCU4_Door8ZeroSpFB,hmiEDCU4_Door8OpenFB,hmiEDCU4_Door8NotOandCFB,
   hmiEDCU4_Door8CloseFB,hmiEDCU4_Door8OpenHinder,hmiEDCU4_Door8Safe1FB,hmiEDCU4_Door8Safe2FB,
   hmiEDCU4_Door8Closed,hmiEDCU4_Door8Opened,hmiEDCU4_Door8EMCunclock,hmiEDCU4_Door8Cut,
   hmiEDCU4_Door8CloseHinder,hmiEDCU4_Door8ReSwitchLineFB,hmiEDCU4_Door8SeriousFlt,hmiEDCU4_Door8SlightFlt;

   unsigned short int hmiEDCU4_OperationSt;
   bool hmiEDCU4_MDCU1DataValid,hmiEDCU4_MDCU2DataValid,hmiEDCU4_MDCU3DataValid,hmiEDCU4_MDCU4DataValid,
   hmiEDCU4_MDCU5DataValid,hmiEDCU4_MDCU6DataValid,hmiEDCU4_MDCU7DataValid,hmiEDCU4_MDCU8DataValid;

   unsigned short int hmiEDCU4_BusToken,hmiEDCU4_LifeSign;
   bool hmiEDCU4_CANBreak;
   unsigned short int hmiEDCU4_D1Version,hmiEDCU4_D2Version,hmiEDCU4_D3Version,hmiEDCU4_D4Version,
   hmiEDCU4_D5Version,hmiEDCU4_D6Version,hmiEDCU4_D7Version,hmiEDCU4_D8Version;

   // 0xF790, 0xF791, 0xF792
   bool hmiEDCU5_Door1MotoLineBrk,hmiEDCU5_Door1ClockedInvalid,hmiEDCU5_Door1ClosedInvalid,hmiEDCU5_Door1NotUnlockIn3s,
   hmiEDCU5_Door1PSensorInvalid,hmiEDCU5_Door1OutClockedPnotAllowed,hmiEDCU5_Door1SafeRelayFlt,hmiEDCU5_Door1InterlockFlt,
   hmiEDCU5_Door1ClockFlt,hmiEDCU5_Door1CHinderNum,hmiEDCU5_Door1OHinderNum,hmiEDCU5_Door1O0OutShort,
   hmiEDCU5_Door1O1OutShort,hmiEDCU5_Door1O2OutShort,hmiEDCU5_Door1O3OutShort,hmiEDCU5_Door1RomFlt,
   hmiEDCU5_Door1ComFlt,hmiEDCU5_Door1AddCodeFlt,hmiEDCU5_Door1MaintainBtnFlt;

   bool hmiEDCU5_Door2MotoLineBrk,hmiEDCU5_Door2ClockedInvalid,hmiEDCU5_Door2ClosedInvalid,hmiEDCU5_Door2NotUnlockIn3s,
   hmiEDCU5_Door2PSensorInvalid,hmiEDCU5_Door2OutClockedPnotAllowed,hmiEDCU5_Door2SafeRelayFlt,hmiEDCU5_Door2InterlockFlt,
   hmiEDCU5_Door2ClockFlt,hmiEDCU5_Door2CHinderNum,hmiEDCU5_Door2OHinderNum,hmiEDCU5_Door2O0OutShort,
   hmiEDCU5_Door2O1OutShort,hmiEDCU5_Door2O2OutShort,hmiEDCU5_Door2O3OutShort,hmiEDCU5_Door2RomFlt,
   hmiEDCU5_Door2ComFlt,hmiEDCU5_Door2AddCodeFlt,hmiEDCU5_Door2MaintainBtnFlt;

   bool hmiEDCU5_Door3MotoLineBrk,hmiEDCU5_Door3ClockedInvalid,hmiEDCU5_Door3ClosedInvalid,hmiEDCU5_Door3NotUnlockIn3s,
   hmiEDCU5_Door3PSensorInvalid,hmiEDCU5_Door3OutClockedPnotAllowed,hmiEDCU5_Door3SafeRelayFlt,hmiEDCU5_Door3InterlockFlt,
   hmiEDCU5_Door3ClockFlt,hmiEDCU5_Door3CHinderNum,hmiEDCU5_Door3OHinderNum,hmiEDCU5_Door3O0OutShort,
   hmiEDCU5_Door3O1OutShort,hmiEDCU5_Door3O2OutShort,hmiEDCU5_Door3O3OutShort,hmiEDCU5_Door3RomFlt,
   hmiEDCU5_Door3ComFlt,hmiEDCU5_Door3AddCodeFlt,hmiEDCU5_Door3MaintainBtnFlt;

   bool hmiEDCU5_Door4MotoLineBrk,hmiEDCU5_Door4ClockedInvalid,hmiEDCU5_Door4ClosedInvalid,hmiEDCU5_Door4NotUnlockIn3s,
   hmiEDCU5_Door4PSensorInvalid,hmiEDCU5_Door4OutClockedPnotAllowed,hmiEDCU5_Door4SafeRelayFlt,hmiEDCU5_Door4InterlockFlt,
   hmiEDCU5_Door4ClockFlt,hmiEDCU5_Door4CHinderNum,hmiEDCU5_Door4OHinderNum,hmiEDCU5_Door4O0OutShort,
   hmiEDCU5_Door4O1OutShort,hmiEDCU5_Door4O2OutShort,hmiEDCU5_Door4O3OutShort,hmiEDCU5_Door4RomFlt,
   hmiEDCU5_Door4ComFlt,hmiEDCU5_Door4AddCodeFlt,hmiEDCU5_Door4MaintainBtnFlt;

   bool hmiEDCU5_Door5MotoLineBrk,hmiEDCU5_Door5ClockedInvalid,hmiEDCU5_Door5ClosedInvalid,hmiEDCU5_Door5NotUnlockIn3s,
   hmiEDCU5_Door5PSensorInvalid,hmiEDCU5_Door5OutClockedPnotAllowed,hmiEDCU5_Door5SafeRelayFlt,hmiEDCU5_Door5InterlockFlt,
   hmiEDCU5_Door5ClockFlt,hmiEDCU5_Door5CHinderNum,hmiEDCU5_Door5OHinderNum,hmiEDCU5_Door5O0OutShort,
   hmiEDCU5_Door5O1OutShort,hmiEDCU5_Door5O2OutShort,hmiEDCU5_Door5O3OutShort,hmiEDCU5_Door5RomFlt,
   hmiEDCU5_Door5ComFlt,hmiEDCU5_Door5AddCodeFlt,hmiEDCU5_Door5MaintainBtnFlt;

   bool hmiEDCU5_Door6MotoLineBrk,hmiEDCU5_Door6ClockedInvalid,hmiEDCU5_Door6ClosedInvalid,hmiEDCU5_Door6NotUnlockIn3s,
   hmiEDCU5_Door6PSensorInvalid,hmiEDCU5_Door6OutClockedPnotAllowed,hmiEDCU5_Door6SafeRelayFlt,hmiEDCU5_Door6InterlockFlt,
   hmiEDCU5_Door6ClockFlt,hmiEDCU5_Door6CHinderNum,hmiEDCU5_Door6OHinderNum,hmiEDCU5_Door6O0OutShort,
   hmiEDCU5_Door6O1OutShort,hmiEDCU5_Door6O2OutShort,hmiEDCU5_Door6O3OutShort,hmiEDCU5_Door6RomFlt,
   hmiEDCU5_Door6ComFlt,hmiEDCU5_Door6AddCodeFlt,hmiEDCU5_Door6MaintainBtnFlt;

   bool hmiEDCU5_Door7MotoLineBrk,hmiEDCU5_Door7ClockedInvalid,hmiEDCU5_Door7ClosedInvalid,hmiEDCU5_Door7NotUnlockIn3s,
   hmiEDCU5_Door7PSensorInvalid,hmiEDCU5_Door7OutClockedPnotAllowed,hmiEDCU5_Door7SafeRelayFlt,hmiEDCU5_Door7InterlockFlt,
   hmiEDCU5_Door7ClockFlt,hmiEDCU5_Door7CHinderNum,hmiEDCU5_Door7OHinderNum,hmiEDCU5_Door7O0OutShort,
   hmiEDCU5_Door7O1OutShort,hmiEDCU5_Door7O2OutShort,hmiEDCU5_Door7O3OutShort,hmiEDCU5_Door7RomFlt,
   hmiEDCU5_Door7ComFlt,hmiEDCU5_Door7AddCodeFlt,hmiEDCU5_Door7MaintainBtnFlt;

   bool hmiEDCU5_Door8MotoLineBrk,hmiEDCU5_Door8ClockedInvalid,hmiEDCU5_Door8ClosedInvalid,hmiEDCU5_Door8NotUnlockIn3s,
   hmiEDCU5_Door8PSensorInvalid,hmiEDCU5_Door8OutClockedPnotAllowed,hmiEDCU5_Door8SafeRelayFlt,hmiEDCU5_Door8InterlockFlt,
   hmiEDCU5_Door8ClockFlt,hmiEDCU5_Door8CHinderNum,hmiEDCU5_Door8OHinderNum,hmiEDCU5_Door8O0OutShort,
   hmiEDCU5_Door8O1OutShort,hmiEDCU5_Door8O2OutShort,hmiEDCU5_Door8O3OutShort,hmiEDCU5_Door8RomFlt,
   hmiEDCU5_Door8ComFlt,hmiEDCU5_Door8AddCodeFlt,hmiEDCU5_Door8MaintainBtnFlt;

   bool hmiEDCU5_Door1EnableFB,hmiEDCU5_Door1ZeroSpFB,hmiEDCU5_Door1OpenFB,hmiEDCU5_Door1NotOandCFB,
   hmiEDCU5_Door1CloseFB,hmiEDCU5_Door1OpenHinder,hmiEDCU5_Door1Safe1FB,hmiEDCU5_Door1Safe2FB,
   hmiEDCU5_Door1Closed,hmiEDCU5_Door1Opened,hmiEDCU5_Door1EMCunclock,hmiEDCU5_Door1Cut,
   hmiEDCU5_Door1CloseHinder,hmiEDCU5_Door1ReSwitchLineFB,hmiEDCU5_Door1SeriousFlt,hmiEDCU5_Door1SlightFlt;

   bool hmiEDCU5_Door2EnableFB,hmiEDCU5_Door2ZeroSpFB,hmiEDCU5_Door2OpenFB,hmiEDCU5_Door2NotOandCFB,
   hmiEDCU5_Door2CloseFB,hmiEDCU5_Door2OpenHinder,hmiEDCU5_Door2Safe1FB,hmiEDCU5_Door2Safe2FB,
   hmiEDCU5_Door2Closed,hmiEDCU5_Door2Opened,hmiEDCU5_Door2EMCunclock,hmiEDCU5_Door2Cut,
   hmiEDCU5_Door2CloseHinder,hmiEDCU5_Door2ReSwitchLineFB,hmiEDCU5_Door2SeriousFlt,hmiEDCU5_Door2SlightFlt;

   bool hmiEDCU5_Door3EnableFB,hmiEDCU5_Door3ZeroSpFB,hmiEDCU5_Door3OpenFB,hmiEDCU5_Door3NotOandCFB,
   hmiEDCU5_Door3CloseFB,hmiEDCU5_Door3OpenHinder,hmiEDCU5_Door3Safe1FB,hmiEDCU5_Door3Safe2FB,
   hmiEDCU5_Door3Closed,hmiEDCU5_Door3Opened,hmiEDCU5_Door3EMCunclock,hmiEDCU5_Door3Cut,
   hmiEDCU5_Door3CloseHinder,hmiEDCU5_Door3ReSwitchLineFB,hmiEDCU5_Door3SeriousFlt,hmiEDCU5_Door3SlightFlt;

   bool hmiEDCU5_Door4EnableFB,hmiEDCU5_Door4ZeroSpFB,hmiEDCU5_Door4OpenFB,hmiEDCU5_Door4NotOandCFB,
   hmiEDCU5_Door4CloseFB,hmiEDCU5_Door4OpenHinder,hmiEDCU5_Door4Safe1FB,hmiEDCU5_Door4Safe2FB,
   hmiEDCU5_Door4Closed,hmiEDCU5_Door4Opened,hmiEDCU5_Door4EMCunclock,hmiEDCU5_Door4Cut,
   hmiEDCU5_Door4CloseHinder,hmiEDCU5_Door4ReSwitchLineFB,hmiEDCU5_Door4SeriousFlt,hmiEDCU5_Door4SlightFlt;

   bool hmiEDCU5_Door5EnableFB,hmiEDCU5_Door5ZeroSpFB,hmiEDCU5_Door5OpenFB,hmiEDCU5_Door5NotOandCFB,
   hmiEDCU5_Door5CloseFB,hmiEDCU5_Door5OpenHinder,hmiEDCU5_Door5Safe1FB,hmiEDCU5_Door5Safe2FB,
   hmiEDCU5_Door5Closed,hmiEDCU5_Door5Opened,hmiEDCU5_Door5EMCunclock,hmiEDCU5_Door5Cut,
   hmiEDCU5_Door5CloseHinder,hmiEDCU5_Door5ReSwitchLineFB,hmiEDCU5_Door5SeriousFlt,hmiEDCU5_Door5SlightFlt;

   bool hmiEDCU5_Door6EnableFB,hmiEDCU5_Door6ZeroSpFB,hmiEDCU5_Door6OpenFB,hmiEDCU5_Door6NotOandCFB,
   hmiEDCU5_Door6CloseFB,hmiEDCU5_Door6OpenHinder,hmiEDCU5_Door6Safe1FB,hmiEDCU5_Door6Safe2FB,
   hmiEDCU5_Door6Closed,hmiEDCU5_Door6Opened,hmiEDCU5_Door6EMCunclock,hmiEDCU5_Door6Cut,
   hmiEDCU5_Door6CloseHinder,hmiEDCU5_Door6ReSwitchLineFB,hmiEDCU5_Door6SeriousFlt,hmiEDCU5_Door6SlightFlt;

   bool hmiEDCU5_Door7EnableFB,hmiEDCU5_Door7ZeroSpFB,hmiEDCU5_Door7OpenFB,hmiEDCU5_Door7NotOandCFB,
   hmiEDCU5_Door7CloseFB,hmiEDCU5_Door7OpenHinder,hmiEDCU5_Door7Safe1FB,hmiEDCU5_Door7Safe2FB,
   hmiEDCU5_Door7Closed,hmiEDCU5_Door7Opened,hmiEDCU5_Door7EMCunclock,hmiEDCU5_Door7Cut,
   hmiEDCU5_Door7CloseHinder,hmiEDCU5_Door7ReSwitchLineFB,hmiEDCU5_Door7SeriousFlt,hmiEDCU5_Door7SlightFlt;

   bool hmiEDCU5_Door8EnableFB,hmiEDCU5_Door8ZeroSpFB,hmiEDCU5_Door8OpenFB,hmiEDCU5_Door8NotOandCFB,
   hmiEDCU5_Door8CloseFB,hmiEDCU5_Door8OpenHinder,hmiEDCU5_Door8Safe1FB,hmiEDCU5_Door8Safe2FB,
   hmiEDCU5_Door8Closed,hmiEDCU5_Door8Opened,hmiEDCU5_Door8EMCunclock,hmiEDCU5_Door8Cut,
   hmiEDCU5_Door8CloseHinder,hmiEDCU5_Door8ReSwitchLineFB,hmiEDCU5_Door8SeriousFlt,hmiEDCU5_Door8SlightFlt;

   unsigned short int hmiEDCU5_OperationSt;
   bool hmiEDCU5_MDCU1DataValid,hmiEDCU5_MDCU2DataValid,hmiEDCU5_MDCU3DataValid,hmiEDCU5_MDCU4DataValid,
   hmiEDCU5_MDCU5DataValid,hmiEDCU5_MDCU6DataValid,hmiEDCU5_MDCU7DataValid,hmiEDCU5_MDCU8DataValid;

   unsigned short int hmiEDCU5_BusToken,hmiEDCU5_LifeSign;
   bool hmiEDCU5_CANBreak;

   unsigned short int hmiEDCU5_D1Version,hmiEDCU5_D2Version,hmiEDCU5_D3Version,hmiEDCU5_D4Version,
   hmiEDCU5_D5Version,hmiEDCU5_D6Version,hmiEDCU5_D7Version,hmiEDCU5_D8Version;

   // 0x7B0, 0x7B1, 0x7B2
   bool hmiEDCU6_Door1MotoLineBrk,hmiEDCU6_Door1ClockedInvalid,hmiEDCU6_Door1ClosedInvalid,hmiEDCU6_Door1NotUnlockIn3s,
   hmiEDCU6_Door1PSensorInvalid,hmiEDCU6_Door1OutClockedPnotAllowed,hmiEDCU6_Door1SafeRelayFlt,hmiEDCU6_Door1InterlockFlt,
   hmiEDCU6_Door1ClockFlt,hmiEDCU6_Door1CHinderNum,hmiEDCU6_Door1OHinderNum,hmiEDCU6_Door1O0OutShort,
   hmiEDCU6_Door1O1OutShort,hmiEDCU6_Door1O2OutShort,hmiEDCU6_Door1O3OutShort,hmiEDCU6_Door1RomFlt,
   hmiEDCU6_Door1ComFlt,hmiEDCU6_Door1AddCodeFlt,hmiEDCU6_Door1MaintainBtnFlt;

   bool hmiEDCU6_Door2MotoLineBrk,hmiEDCU6_Door2ClockedInvalid,hmiEDCU6_Door2ClosedInvalid,hmiEDCU6_Door2NotUnlockIn3s,
   hmiEDCU6_Door2PSensorInvalid,hmiEDCU6_Door2OutClockedPnotAllowed,hmiEDCU6_Door2SafeRelayFlt,hmiEDCU6_Door2InterlockFlt,
   hmiEDCU6_Door2ClockFlt,hmiEDCU6_Door2CHinderNum,hmiEDCU6_Door2OHinderNum,hmiEDCU6_Door2O0OutShort,
   hmiEDCU6_Door2O1OutShort,hmiEDCU6_Door2O2OutShort,hmiEDCU6_Door2O3OutShort,hmiEDCU6_Door2RomFlt,
   hmiEDCU6_Door2ComFlt,hmiEDCU6_Door2AddCodeFlt,hmiEDCU6_Door2MaintainBtnFlt;

   bool hmiEDCU6_Door3MotoLineBrk,hmiEDCU6_Door3ClockedInvalid,hmiEDCU6_Door3ClosedInvalid,hmiEDCU6_Door3NotUnlockIn3s,
   hmiEDCU6_Door3PSensorInvalid,hmiEDCU6_Door3OutClockedPnotAllowed,hmiEDCU6_Door3SafeRelayFlt,hmiEDCU6_Door3InterlockFlt,
   hmiEDCU6_Door3ClockFlt,hmiEDCU6_Door3CHinderNum,hmiEDCU6_Door3OHinderNum,hmiEDCU6_Door3O0OutShort,
   hmiEDCU6_Door3O1OutShort,hmiEDCU6_Door3O2OutShort,hmiEDCU6_Door3O3OutShort,hmiEDCU6_Door3RomFlt,
   hmiEDCU6_Door3ComFlt,hmiEDCU6_Door3AddCodeFlt,hmiEDCU6_Door3MaintainBtnFlt;

   bool hmiEDCU6_Door4MotoLineBrk,hmiEDCU6_Door4ClockedInvalid,hmiEDCU6_Door4ClosedInvalid,hmiEDCU6_Door4NotUnlockIn3s,
   hmiEDCU6_Door4PSensorInvalid,hmiEDCU6_Door4OutClockedPnotAllowed,hmiEDCU6_Door4SafeRelayFlt,hmiEDCU6_Door4InterlockFlt,
   hmiEDCU6_Door4ClockFlt,hmiEDCU6_Door4CHinderNum,hmiEDCU6_Door4OHinderNum,hmiEDCU6_Door4O0OutShort,
   hmiEDCU6_Door4O1OutShort,hmiEDCU6_Door4O2OutShort,hmiEDCU6_Door4O3OutShort,hmiEDCU6_Door4RomFlt,
   hmiEDCU6_Door4ComFlt,hmiEDCU6_Door4AddCodeFlt,hmiEDCU6_Door4MaintainBtnFlt;

   bool hmiEDCU6_Door5MotoLineBrk,hmiEDCU6_Door5ClockedInvalid,hmiEDCU6_Door5ClosedInvalid,hmiEDCU6_Door5NotUnlockIn3s,
   hmiEDCU6_Door5PSensorInvalid,hmiEDCU6_Door5OutClockedPnotAllowed,hmiEDCU6_Door5SafeRelayFlt,hmiEDCU6_Door5InterlockFlt,
   hmiEDCU6_Door5ClockFlt,hmiEDCU6_Door5CHinderNum,hmiEDCU6_Door5OHinderNum,hmiEDCU6_Door5O0OutShort,
   hmiEDCU6_Door5O1OutShort,hmiEDCU6_Door5O2OutShort,hmiEDCU6_Door5O3OutShort,hmiEDCU6_Door5RomFlt,
   hmiEDCU6_Door5ComFlt,hmiEDCU6_Door5AddCodeFlt,hmiEDCU6_Door5MaintainBtnFlt;

   bool hmiEDCU6_Door6MotoLineBrk,hmiEDCU6_Door6ClockedInvalid,hmiEDCU6_Door6ClosedInvalid,hmiEDCU6_Door6NotUnlockIn3s,
   hmiEDCU6_Door6PSensorInvalid,hmiEDCU6_Door6OutClockedPnotAllowed,hmiEDCU6_Door6SafeRelayFlt,hmiEDCU6_Door6InterlockFlt,
   hmiEDCU6_Door6ClockFlt,hmiEDCU6_Door6CHinderNum,hmiEDCU6_Door6OHinderNum,hmiEDCU6_Door6O0OutShort,
   hmiEDCU6_Door6O1OutShort,hmiEDCU6_Door6O2OutShort,hmiEDCU6_Door6O3OutShort,hmiEDCU6_Door6RomFlt,
   hmiEDCU6_Door6ComFlt,hmiEDCU6_Door6AddCodeFlt,hmiEDCU6_Door6MaintainBtnFlt;

   bool hmiEDCU6_Door7MotoLineBrk,hmiEDCU6_Door7ClockedInvalid,hmiEDCU6_Door7ClosedInvalid,hmiEDCU6_Door7NotUnlockIn3s,
   hmiEDCU6_Door7PSensorInvalid,hmiEDCU6_Door7OutClockedPnotAllowed,hmiEDCU6_Door7SafeRelayFlt,hmiEDCU6_Door7InterlockFlt,
   hmiEDCU6_Door7ClockFlt,hmiEDCU6_Door7CHinderNum,hmiEDCU6_Door7OHinderNum,hmiEDCU6_Door7O0OutShort,
   hmiEDCU6_Door7O1OutShort,hmiEDCU6_Door7O2OutShort,hmiEDCU6_Door7O3OutShort,hmiEDCU6_Door7RomFlt,
   hmiEDCU6_Door7ComFlt,hmiEDCU6_Door7AddCodeFlt,hmiEDCU6_Door7MaintainBtnFlt;

   bool hmiEDCU6_Door8MotoLineBrk,hmiEDCU6_Door8ClockedInvalid,hmiEDCU6_Door8ClosedInvalid,hmiEDCU6_Door8NotUnlockIn3s,
   hmiEDCU6_Door8PSensorInvalid,hmiEDCU6_Door8OutClockedPnotAllowed,hmiEDCU6_Door8SafeRelayFlt,hmiEDCU6_Door8InterlockFlt,
   hmiEDCU6_Door8ClockFlt,hmiEDCU6_Door8CHinderNum,hmiEDCU6_Door8OHinderNum,hmiEDCU6_Door8O0OutShort,
   hmiEDCU6_Door8O1OutShort,hmiEDCU6_Door8O2OutShort,hmiEDCU6_Door8O3OutShort,hmiEDCU6_Door8RomFlt,
   hmiEDCU6_Door8ComFlt,hmiEDCU6_Door8AddCodeFlt,hmiEDCU6_Door8MaintainBtnFlt;

   bool hmiEDCU6_Door1EnableFB,hmiEDCU6_Door1ZeroSpFB,hmiEDCU6_Door1OpenFB,hmiEDCU6_Door1NotOandCFB,
   hmiEDCU6_Door1CloseFB,hmiEDCU6_Door1OpenHinder,hmiEDCU6_Door1Safe1FB,hmiEDCU6_Door1Safe2FB,
   hmiEDCU6_Door1Closed,hmiEDCU6_Door1Opened,hmiEDCU6_Door1EMCunclock,hmiEDCU6_Door1Cut,
   hmiEDCU6_Door1CloseHinder,hmiEDCU6_Door1ReSwitchLineFB,hmiEDCU6_Door1SeriousFlt,hmiEDCU6_Door1SlightFlt;

   bool hmiEDCU6_Door2EnableFB,hmiEDCU6_Door2ZeroSpFB,hmiEDCU6_Door2OpenFB,hmiEDCU6_Door2NotOandCFB,
   hmiEDCU6_Door2CloseFB,hmiEDCU6_Door2OpenHinder,hmiEDCU6_Door2Safe1FB,hmiEDCU6_Door2Safe2FB,
   hmiEDCU6_Door2Closed,hmiEDCU6_Door2Opened,hmiEDCU6_Door2EMCunclock,hmiEDCU6_Door2Cut,
   hmiEDCU6_Door2CloseHinder,hmiEDCU6_Door2ReSwitchLineFB,hmiEDCU6_Door2SeriousFlt,hmiEDCU6_Door2SlightFlt;

   bool hmiEDCU6_Door3EnableFB,hmiEDCU6_Door3ZeroSpFB,hmiEDCU6_Door3OpenFB,hmiEDCU6_Door3NotOandCFB,
   hmiEDCU6_Door3CloseFB,hmiEDCU6_Door3OpenHinder,hmiEDCU6_Door3Safe1FB,hmiEDCU6_Door3Safe2FB,
   hmiEDCU6_Door3Closed,hmiEDCU6_Door3Opened,hmiEDCU6_Door3EMCunclock,hmiEDCU6_Door3Cut,
   hmiEDCU6_Door3CloseHinder,hmiEDCU6_Door3ReSwitchLineFB,hmiEDCU6_Door3SeriousFlt,hmiEDCU6_Door3SlightFlt;

   bool hmiEDCU6_Door4EnableFB,hmiEDCU6_Door4ZeroSpFB,hmiEDCU6_Door4OpenFB,hmiEDCU6_Door4NotOandCFB,
   hmiEDCU6_Door4CloseFB,hmiEDCU6_Door4OpenHinder,hmiEDCU6_Door4Safe1FB,hmiEDCU6_Door4Safe2FB,
   hmiEDCU6_Door4Closed,hmiEDCU6_Door4Opened,hmiEDCU6_Door4EMCunclock,hmiEDCU6_Door4Cut,
   hmiEDCU6_Door4CloseHinder,hmiEDCU6_Door4ReSwitchLineFB,hmiEDCU6_Door4SeriousFlt,hmiEDCU6_Door4SlightFlt;

   bool hmiEDCU6_Door5EnableFB,hmiEDCU6_Door5ZeroSpFB,hmiEDCU6_Door5OpenFB,hmiEDCU6_Door5NotOandCFB,
   hmiEDCU6_Door5CloseFB,hmiEDCU6_Door5OpenHinder,hmiEDCU6_Door5Safe1FB,hmiEDCU6_Door5Safe2FB,
   hmiEDCU6_Door5Closed,hmiEDCU6_Door5Opened,hmiEDCU6_Door5EMCunclock,hmiEDCU6_Door5Cut,
   hmiEDCU6_Door5CloseHinder,hmiEDCU6_Door5ReSwitchLineFB,hmiEDCU6_Door5SeriousFlt,hmiEDCU6_Door5SlightFlt;

   bool hmiEDCU6_Door6EnableFB,hmiEDCU6_Door6ZeroSpFB,hmiEDCU6_Door6OpenFB,hmiEDCU6_Door6NotOandCFB,
   hmiEDCU6_Door6CloseFB,hmiEDCU6_Door6OpenHinder,hmiEDCU6_Door6Safe1FB,hmiEDCU6_Door6Safe2FB,
   hmiEDCU6_Door6Closed,hmiEDCU6_Door6Opened,hmiEDCU6_Door6EMCunclock,hmiEDCU6_Door6Cut,
   hmiEDCU6_Door6CloseHinder,hmiEDCU6_Door6ReSwitchLineFB,hmiEDCU6_Door6SeriousFlt,hmiEDCU6_Door6SlightFlt;

   bool hmiEDCU6_Door7EnableFB,hmiEDCU6_Door7ZeroSpFB,hmiEDCU6_Door7OpenFB,hmiEDCU6_Door7NotOandCFB,
   hmiEDCU6_Door7CloseFB,hmiEDCU6_Door7OpenHinder,hmiEDCU6_Door7Safe1FB,hmiEDCU6_Door7Safe2FB,
   hmiEDCU6_Door7Closed,hmiEDCU6_Door7Opened,hmiEDCU6_Door7EMCunclock,hmiEDCU6_Door7Cut,
   hmiEDCU6_Door7CloseHinder,hmiEDCU6_Door7ReSwitchLineFB,hmiEDCU6_Door7SeriousFlt,hmiEDCU6_Door7SlightFlt;

   bool hmiEDCU6_Door8EnableFB,hmiEDCU6_Door8ZeroSpFB,hmiEDCU6_Door8OpenFB,hmiEDCU6_Door8NotOandCFB,
   hmiEDCU6_Door8CloseFB,hmiEDCU6_Door8OpenHinder,hmiEDCU6_Door8Safe1FB,hmiEDCU6_Door8Safe2FB,
   hmiEDCU6_Door8Closed,hmiEDCU6_Door8Opened,hmiEDCU6_Door8EMCunclock,hmiEDCU6_Door8Cut,
   hmiEDCU6_Door8CloseHinder,hmiEDCU6_Door8ReSwitchLineFB,hmiEDCU6_Door8SeriousFlt,hmiEDCU6_Door8SlightFlt;

   unsigned short int hmiEDCU6_OperationSt;
   bool hmiEDCU6_MDCU1DataValid,hmiEDCU6_MDCU2DataValid,hmiEDCU6_MDCU3DataValid,hmiEDCU6_MDCU4DataValid,
   hmiEDCU6_MDCU5DataValid,hmiEDCU6_MDCU6DataValid,hmiEDCU6_MDCU7DataValid,hmiEDCU6_MDCU8DataValid;
   unsigned short int hmiEDCU6_BusToken,hmiEDCU6_LifeSign;

   bool hmiEDCU6_CANBreak;
   unsigned short int hmiEDCU6_D1Version,hmiEDCU6_D2Version,hmiEDCU6_D3Version,hmiEDCU6_D4Version,
   hmiEDCU6_D5Version,hmiEDCU6_D6Version,hmiEDCU6_D7Version,hmiEDCU6_D8Version;

   //PIS 0xF810, 0xF811
   unsigned short int hmiPIS_LifeSignal;
   unsigned char hmiPIS_PASwVersion;
   bool hmiPIS_StreamDirection,hmiPIS_SkipStation,hmiPIS_SkipNextStation,hmiPIS_RightDoorOpen,hmiPIS_LeftDoorOpen;
   unsigned short int hmiPIS_StartStationID,hmiPIS_DestinationID,hmiPIS_NextStation;
   unsigned char hmiPIS_EmBroadcastID;
   bool hmiPIS_MasterActive,hmiPIS_AutoMode,hmiPIS_CabTalk,hmiPIS_BroadcastingSta,hmiPIS_OCCBroadcast;
   unsigned char hmiPIS_BCStationFB;
   bool hmiPIS_Tc1EMC1Alarm,hmiPIS_Tc1EMC1On,hmiPIS_Tc1EMC2Alarm,hmiPIS_Tc1EMC2On,hmiPIS_M1EMC1Alarm,
   hmiPIS_M1EMC1On,hmiPIS_M1EMC2Alarm,hmiPIS_M1EMC2On,hmiPIS_Mp1EMC1Alarm,hmiPIS_Mp1EMC1On,
   hmiPIS_Mp1EMC2Alarm,hmiPIS_Mp1EMC2On,hmiPIS_Mp2EMC1Alarm,hmiPIS_Mp2EMC1On,hmiPIS_Mp2EMC2Alarm,
   hmiPIS_Mp2EMC2On,hmiPIS_M2EMC1Alarm,hmiPIS_M2EMC1On,hmiPIS_M2EMC2Alarm,hmiPIS_M2EMC2On,
   hmiPIS_Tc2EMC1Alarm,hmiPIS_Tc2EMC1On,hmiPIS_Tc2EMC2Alarm,hmiPIS_Tc2EMC2On,hmiPIS_Tc1CabOutVideoNetFlt,
   hmiPIS_Tc1CabInVideoNetFlt,hmiPIS_Tc1RoomVideo1NetFlt,hmiPIS_Tc1RoomVideo2NetFlt,hmiPIS_Tc1RoomVideo3NetFlt,
   hmiPIS_Tc1RoomVideo4NetFlt,hmiPIS_Tc1MaintainServerFlt,hmiPIS_M1RoomVideo1NetFlt,hmiPIS_M1RoomVideo2NetFlt,
   hmiPIS_M1RoomVideo3NetFlt,hmiPIS_M1RoomVideo4NetFlt,hmiPIS_Mp1RoomVideo1NetFlt,hmiPIS_Mp1RoomVideo2NetFlt,
   hmiPIS_Mp1RoomVideo3NetFlt,hmiPIS_Mp1RoomVideo4NetFlt,hmiPIS_Mp2RoomVideo1NetFlt,hmiPIS_Mp2RoomVideo2NetFlt,
   hmiPIS_Mp2RoomVideo3NetFlt,hmiPIS_Mp2RoomVideo4NetFlt,hmiPIS_M2RoomVideo1NetFlt,hmiPIS_M2RoomVideo2NetFlt,
   hmiPIS_M2RoomVideo3NetFlt,hmiPIS_M2RoomVideo4NetFlt,hmiPIS_Tc2CabOutVideoNetFlt,hmiPIS_Tc2CabInVideoNetFlt,
   hmiPIS_Tc2RoomVideo1NetFlt,hmiPIS_Tc2RoomVideo2NetFlt,hmiPIS_Tc2RoomVideo3NetFlt,hmiPIS_Tc2RoomVideo4NetFlt,
   hmiPIS_Tc2MaintainServerFlt,hmiPIS_Tc1MediaInterfaceFlt,hmiPIS_M1MediaInterfaceFlt,hmiPIS_Mp1MediaInterfaceFlt,
   hmiPIS_Mp2MediaInterfaceFlt,hmiPIS_M2MediaInterfaceFlt,hmiPIS_Tc2MediaInterfaceFlt,hmiPIS_Tc1MediaServerFlt,
   hmiPIS_Tc2MediaServerFlt,hmiPIS_Tc1NVR1Flt,hmiPIS_Tc1NVR2Flt,hmiPIS_Tc2NVR1Flt,hmiPIS_Tc2NVR2Flt,
   hmiPIS_Tc1RadioMainUnitFlt,hmiPIS_Tc1RadioControlBoxFlt,hmiPIS_Tc1RoomMinorUnitFlt,hmiPIS_M1RoomMinorUnitFlt,
   hmiPIS_Mp1RoomMinorUnitFlt,hmiPIS_Mp2RoomMinorUnitFlt,hmiPIS_M2RoomMinorUnitFlt,hmiPIS_Tc2RoomMinorUnitFlt,
   hmiPIS_Tc2RadioMainUnitFlt,hmiPIS_Tc2RadioControlBoxFlt,hmiPIS_Tc1EMCTalkback1Flt,hmiPIS_Tc1EMCTalkback2Flt,
   hmiPIS_M1EMCTalkback1Flt,hmiPIS_M1EMCTalkback2Flt,hmiPIS_Mp1EMCTalkback1Flt,hmiPIS_Mp1EMCTalkback2Flt,
   hmiPIS_Mp2EMCTalkback1Flt,hmiPIS_Mp2EMCTalkback2Flt,hmiPIS_M2EMCTalkback1Flt,hmiPIS_M2EMCTalkback2Flt,
   hmiPIS_Tc2EMCTalkback1Flt,hmiPIS_Tc2EMCTalkback2Flt,hmiPIS_Tc1InsetDisplay1Flt,hmiPIS_Tc1InsetDisplay2Flt,
   hmiPIS_Tc1OutsetDisplay1Flt,hmiPIS_Tc1OutsetDisplay2Flt,hmiPIS_M1InsetDisplay1Flt,hmiPIS_M1InsetDisplay2Flt,
   hmiPIS_M1OutsetDisplay1Flt,hmiPIS_M1OutsetDisplay2Flt,hmiPIS_Mp1InsetDisplay1Flt,hmiPIS_Mp1InsetDisplay2Flt,
   hmiPIS_Mp1OutsetDisplay1Flt,hmiPIS_Mp1OutsetDisplay2Flt,hmiPIS_Mp2InsetDisplay1Flt,hmiPIS_Mp2InsetDisplay2Flt,
   hmiPIS_Mp2OutsetDisplay1Flt,hmiPIS_Mp2OutsetDisplay2Flt,hmiPIS_M2InsetDisplay1Flt,hmiPIS_M2InsetDisplay2Flt,
   hmiPIS_M2OutsetDisplay1Flt,hmiPIS_M2OutsetDisplay2Flt,hmiPIS_Tc2InsetDisplay1Flt,hmiPIS_Tc2InsetDisplay2Flt,
   hmiPIS_Tc2OutsetDisplay1Flt,hmiPIS_Tc2OutsetDisplay2Flt,hmiPIS_Tc1MapDisplay1Flt,hmiPIS_Tc1MapDisplay2Flt,
   hmiPIS_Tc1MapDisplay3Flt,hmiPIS_Tc1MapDisplay4Flt,hmiPIS_Tc1MapDisplay5Flt,hmiPIS_Tc1MapDisplay6Flt,
   hmiPIS_Tc1MapDisplay7Flt,hmiPIS_Tc1MapDisplay8Flt,hmiPIS_M1MapDisplay1Flt,hmiPIS_M1MapDisplay2Flt,
   hmiPIS_M1MapDisplay3Flt,hmiPIS_M1MapDisplay4Flt,hmiPIS_M1MapDisplay5Flt,hmiPIS_M1MapDisplay6Flt,hmiPIS_M1MapDisplay7Flt,
   hmiPIS_M1MapDisplay8Flt,hmiPIS_Mp1MapDisplay1Flt,hmiPIS_Mp1MapDisplay2Flt,hmiPIS_Mp1MapDisplay3Flt,hmiPIS_Mp1MapDisplay4Flt,
   hmiPIS_Mp1MapDisplay5Flt,hmiPIS_Mp1MapDisplay6Flt,hmiPIS_Mp1MapDisplay7Flt,hmiPIS_Mp1MapDisplay8Flt,hmiPIS_Mp2MapDisplay1Flt,
   hmiPIS_Mp2MapDisplay2Flt,hmiPIS_Mp2MapDisplay3Flt,hmiPIS_Mp2MapDisplay4Flt,hmiPIS_Mp2MapDisplay5Flt,hmiPIS_Mp2MapDisplay6Flt,
   hmiPIS_Mp2MapDisplay7Flt,hmiPIS_Mp2MapDisplay8Flt,hmiPIS_M2MapDisplay1Flt,hmiPIS_M2MapDisplay2Flt,hmiPIS_M2MapDisplay3Flt,
   hmiPIS_M2MapDisplay4Flt,hmiPIS_M2MapDisplay5Flt,hmiPIS_M2MapDisplay6Flt,hmiPIS_M2MapDisplay7Flt,hmiPIS_M2MapDisplay8Flt,
   hmiPIS_Tc2MapDisplay1Flt,hmiPIS_Tc2MapDisplay2Flt,hmiPIS_Tc2MapDisplay3Flt,hmiPIS_Tc2MapDisplay4Flt,hmiPIS_Tc2MapDisplay5Flt,
   hmiPIS_Tc2MapDisplay6Flt,hmiPIS_Tc2MapDisplay7Flt,hmiPIS_Tc2MapDisplay8Flt;


   QString car1Door1Version, car1Door2Version, car1Door3Version, car1Door4Version,
   car1Door5Version, car1Door6Version, car1Door7Version, car1Door8Version,
   car2Door1Version, car2Door2Version, car2Door3Version, car2Door4Version,
   car2Door5Version, car2Door6Version, car2Door7Version, car2Door8Version,
   car3Door1Version, car3Door2Version, car3Door3Version, car3Door4Version,
   car3Door5Version, car3Door6Version, car3Door7Version, car3Door8Version,
   car4Door1Version, car4Door2Version, car4Door3Version, car4Door4Version,
   car4Door5Version, car4Door6Version, car4Door7Version, car4Door8Version,
   car5Door1Version, car5Door2Version, car5Door3Version, car5Door4Version,
   car5Door5Version, car5Door6Version, car5Door7Version, car5Door8Version,
   car6Door1Version, car6Door2Version, car6Door3Version, car6Door4Version,
   car6Door5Version, car6Door6Version, car6Door7Version, car6Door8Version;
   //AX
   unsigned short int RIOM1_AXC3, RIOM1_AXC4, RIOM6_AXC3, RIOM6_AXC4;
   //parameter set fireButton's state(if has fire alert button turn red)
   bool ifFire;
   QList <int> doorsOnLine1, doorsOnLine2, doorsOnLine3, doorsOnLine4, doorsOnLine5, doorsOnLine6;
private:
   EdcuDefaultList edcuDefaultList1, edcuDefaultList2, edcuDefaultList3, edcuDefaultList4, edcuDefaultList5, edcuDefaultList6;
   PISDefaultList pisDefaultList;
   BCUDefaultList bcuDefaultList1, bcuDefaultList2;
   ErmDefaultList ermDefaultList;

};



#endif // DATABASE_H
