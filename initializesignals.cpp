#include "database.h"
#include <QDebug>
#include "global.h"
#include <QDateTime>
void Database::initializeSignals()
{
    this->TimeSetMode = false;
    this->hmisetDateTime.setDate(QDate::currentDate());
    this->hmisetDateTime.setTime(QTime::currentTime());
    this->flagChecker = 0x55;

    this->hmiSaveAirConditionerTempTc1 = false;
    this->hmiSaveAirConditionerTempMp1 = false;
    this->hmiSaveAirConditionerTempMp2 = false;
    this->hmiSaveAirConditionerTempTc2 = false;

    this->hmiSaveAirConditionerTc1 = false;
    this->hmiSaveAirConditionerMp1 = false;
    this->hmiSaveAirConditionerMp2 = false;
    this->hmiSaveAirConditionerTc2 = false;

    this->saveWheelDigflag_Tc1 = false;
    this->saveWheelDigflag_Mp1 = false;
    this->saveWheelDigflag_Mp2 = false;
    this->saveWheelDigflag_Tc2 = false;

    this->hmiCutBCG1 = false;
    this->hmiCutBCG2 = false;
    this->hmiResetBCG1 = false;
    this->hmiResetBCG2 = false;

    this->hmiSaveTrainNum = false;
    this->hmiSaveLineNum = false;

    this->hmiMuteFau = false;
    this->hmiResetFau = false;

    this->hmiResetSIV1 = false;
    this->hmiResetSIV2 = false;
    this->hmiCutSIV1 = false;
    this->hmiCutSIV2 = false;
    this->keepBrakeState = false;

    this->hmiClearERMAP1Time = false;
    this->hmiClearERMAP2Time = false;
    this->hmiClearServiceDistance = false;
    this->hmiClearTractionCost = false;
    this->hmiClearAuxCost = false;

    this->hmiTrainNumber = 0;
    this->hmiLineNumber = 0;
    this->hmiAirconditionerModeTc1 = 0;
    this->hmiAirconditionerModeTc2 = 0;
    this->hmiAirconditionerModeMp1 = 0;
    this->hmiAirconditionerModeMp2 = 0;
    this->hmiTc1Temperature = 0;
    this->hmiTc2Temperature = 0;
    this->hmiMp1Temperature = 0;
    this->hmiMp2Temperature = 0;

    this->wheelDiameterTc1 = 0;
    this->wheelDiameterTc2 = 0;
    this->wheelDiameterMp1 = 0;
    this->wheelDiameterMp2 = 0;

    this->hmiEmergencyCode = 0;
    this->hmiEmergencyCommand = false;
    this->hmiEmergencyStop = false;
    this->hmiBcuTestCode = 0;
    this->hmiAcTeststart = false;
    this->hmiAcTestStop = true;

    this->hmiSetServiceKilometer = 0;
    this->hmiSetRunningKilometer = 0;
    this->hmiSetTagRunningKilometer = 0;
    this->hmiSetTagServiceKilometer = 0;

    this->hmiTc1WindSpd = false;
    this->hmiTc2WindSpd = false;
    this->hmiMp1WindSpd = false;
    this->hmiMp2WindSpd = false;

    this->hmiTc1WindMode = 0;
    this->hmiTc2WindMode = 0;
    this->hmiMp1WindMode = 0;
    this->hmiMp2WindMode = 0;

    this->hmiNewWindSave = false;

    this->hmiTc1WindSpd = false;
    this->hmiMp1WindSpd = false;
    this->hmiMp2WindSpd = false;
    this->hmiTc2WindSpd = false;

    this->hmiResetSIV1Egy = false;
    this->hmiResetSIV2Egy = false;
    this->hmiResetDCU1Egy = false;
    this->hmiResetDCU2Egy = false;
    this->hmiResetDCU3Egy = false;
    this->hmiResetDCU4Egy = false;

    this->bcuSelfTest = false;

    this->mp1Tcu1Isolate = false;
    this->mp1Tcu2Isolate = false;
    this->mp1Tcu3Isolate = false;
    this->mp1Tcu4Isolate = false;
    this->mp2Tcu1Isolate = false;
    this->mp2Tcu2Isolate = false;
    this->mp2Tcu3Isolate = false;
    this->mp2Tcu4Isolate = false;
 }

void Database::synchronizeCcuSignals()
{
    // transmit message
    this->hmiLifeSignal++;
    if (1 == this->hmiPosition)
    {
        this->hmiVersionA1.sprintf("%02d.%02d", _HMI_VERSION_MAIN, _HMI_VERSION_MINOR);
        this->hmiVersionA2.sprintf("%02d.%02d", this->getUnsignedChar(0x320, 2), this->getUnsignedChar(0x320, 3));
        this->setUnsignedInt(0x310, 0, this->hmiLifeSignal);
        this->setUnsignedChar(0x310, 2, _HMI_VERSION_MAIN);
        this->setUnsignedChar(0x310, 3, _HMI_VERSION_MINOR);
        this->setUnsignedChar(0x311, 0, this->hmisetDateTime.toString("yy").toInt());
        this->setUnsignedChar(0x311, 1, this->hmisetDateTime.toString("MM").toInt());
        this->setUnsignedChar(0x311, 2, this->hmisetDateTime.toString("dd").toInt());
        this->setUnsignedChar(0x311, 3, this->hmisetDateTime.toString("hh").toInt());
        this->setUnsignedChar(0x311, 4, this->hmisetDateTime.toString("mm").toInt());
        this->setUnsignedChar(0x311, 5, this->hmisetDateTime.toString("ss").toInt());

        this->setUnsignedChar(0x310, 31, this->flagChecker);
        this->setBool(0x311, 10, 0, this->TimeSetMode);
        this->setBool(0x312, 8, 0, this->saveWheelDigflag_Tc1);
        this->setBool(0x312, 8, 2, this->saveWheelDigflag_Mp1);
        this->setBool(0x312, 8, 3, this->saveWheelDigflag_Mp2);
        this->setBool(0x312, 8, 5, this->saveWheelDigflag_Tc2);
        this->setUnsignedChar(0x312, 0, this->wheelDiameterTc1);
        this->setUnsignedChar(0x312, 2, this->wheelDiameterMp1);
        this->setUnsignedChar(0x312, 3, this->wheelDiameterMp2);
        this->setUnsignedChar(0x312, 5, this->wheelDiameterTc2);
        this->setBool(0x312, 17, 3, this->bcuSelfTest);
        this->setUnsignedChar(0x312, 7, this->hmiBcuTestCode);

        this->setUnsignedChar(0x311, 11, this->hmiAirconditionerModeTc1);
        this->setUnsignedChar(0x311, 13, this->hmiAirconditionerModeMp1);
        this->setUnsignedChar(0x311, 14, this->hmiAirconditionerModeMp2);
        this->setUnsignedChar(0x311, 16, this->hmiAirconditionerModeTc2);

        this->setUnsignedChar(0x311, 19, this->hmiTc1Temperature);
        this->setUnsignedChar(0x311, 21, this->hmiMp1Temperature);
        this->setUnsignedChar(0x311, 22, this->hmiMp2Temperature);
        this->setUnsignedChar(0x311, 24, this->hmiTc2Temperature);

        this->setBool(0x311, 27, 0, this->hmiSaveAirConditionerTc1);
        this->setBool(0x311, 27, 2, this->hmiSaveAirConditionerMp1);
        this->setBool(0x311, 27, 3, this->hmiSaveAirConditionerMp2);
        this->setBool(0x311, 27, 5, this->hmiSaveAirConditionerTc2);

        this->setBool(0x311, 28, 0, this->hmiSaveAirConditionerTempTc1);
        this->setBool(0x311, 28, 2, this->hmiSaveAirConditionerTempMp1);
        this->setBool(0x311, 28, 3, this->hmiSaveAirConditionerTempMp2);
        this->setBool(0x311, 28, 5, this->hmiSaveAirConditionerTempTc2);

        //emergencyBroadcast
        this->setUnsignedChar(0x312, 11, this->hmiEmergencyCode);
        this->setBool(0x312, 17, 1, this->hmiEmergencyCommand);
        this->setBool(0x312, 17, 2, this->hmiEmergencyStop);

        //BCG
        this->setBool(0x312, 15, 0, this->hmiCutBCG1);
        this->setBool(0x312, 15, 1, this->hmiCutBCG2);

        this->setBool(0x312, 15, 2, this->hmiResetBCG1);
        this->setBool(0x312, 15, 3, this->hmiResetBCG2);

        // TrainNum and LineNum
        this->setUnsignedChar(0x311, 6, this->hmiTrainNumber);
        this->setUnsignedChar(0x311, 7, this->hmiLineNumber);
        this->setBool(0x311, 10, 1, this->hmiSaveTrainNum);
        this->setBool(0x311, 10, 2, this->hmiSaveLineNum);

        //fau
        this->setBool(0x312, 16, 0, this->hmiMuteFau);
        this->setBool(0x312, 16, 1, this->hmiResetFau);

        //siv
        this->setBool(0x312, 15, 4, this->hmiResetSIV1);
        this->setBool(0x312, 15, 5, this->hmiResetSIV2);
        this->setBool(0x312, 15, 6, this->hmiCutSIV1);
        this->setBool(0x312, 15, 7, this->hmiCutSIV2);

        //service kilometers
        this->setUnsignedInt32(0x313, 22, this->hmiSetServiceKilometer);
        //running kilometers
        this->setUnsignedInt32(0x313, 27, this->hmiSetRunningKilometer);

        //running record clear page
        this->setBool(0x313, 0, 0, this->hmiClearERMAP1Time);
        this->setBool(0x313, 0, 1, this->hmiClearERMAP2Time);
        this->setBool(0x313, 0, 2, this->hmiClearTractionCost);
        this->setBool(0x313, 0, 3, this->hmiClearServiceDistance);
        this->setBool(0x313, 0, 4, this->hmiClearAuxCost);

        //speed test
        this->setBool(0x312, 17, 4, this->hmiAcTeststart);
        this->setBool(0x312, 17, 5, this->hmiAcTestStop);

        //HVAC new wind
        this->setBool(0x311, 10, 5, this->hmiTc1WindSpd);
        this->setBool(0x311, 10, 6, this->hmiTc2WindSpd);
        this->setBool(0x311, 10, 7, this->hmiMp1WindSpd);
        this->setBool(0x311, 27, 6, this->hmiMp2WindSpd);

        this->setBool(0x311, 27, 7, this->hmiNewWindSave);
        this->setUnsignedChar(0x311, 17, this->hmiTc1WindMode);
        this->setUnsignedChar(0x311, 18, this->hmiTc2WindMode);
        this->setUnsignedChar(0x311, 25, this->hmiMp1WindMode);
        this->setUnsignedChar(0x311, 26, this->hmiMp2WindMode);

        this->setBool(0x312, 16, 2, this->hmiResetSIV1Egy);
        this->setBool(0x312, 16, 3, this->hmiResetSIV2Egy);
        this->setBool(0x312, 16, 4, this->hmiResetDCU1Egy);
        this->setBool(0x312, 16, 5, this->hmiResetDCU2Egy);
        this->setBool(0x312, 16, 6, this->hmiResetDCU3Egy);
        this->setBool(0x312, 16, 7, this->hmiResetDCU4Egy);

        //traction isolate
        this->setBool(0x312, 12, 0, this->mp1Tcu1Isolate);
        this->setBool(0x312, 12, 1, this->mp1Tcu2Isolate);
        this->setBool(0x312, 12, 2, this->mp1Tcu3Isolate);
        this->setBool(0x312, 12, 3, this->mp1Tcu4Isolate);
        this->setBool(0x312, 12, 4, this->mp2Tcu1Isolate);
        this->setBool(0x312, 12, 5, this->mp2Tcu2Isolate);
        this->setBool(0x312, 12, 6, this->mp2Tcu3Isolate);
        this->setBool(0x312, 12, 7, this->mp2Tcu4Isolate);

        this->setBool(0x312, 13, 0, this->keepBrakeState);
    }
    else if(2 == this->hmiPosition)
    {
        this->hmiVersionA2.sprintf("%02d.%02d", _HMI_VERSION_MAIN, _HMI_VERSION_MINOR);
        this->hmiVersionA1.sprintf("%02d.%02d", this->getUnsignedChar(0x310, 2), this->getUnsignedChar(0x310, 3));
        this->setUnsignedInt(0x320, 0, this->hmiLifeSignal);
        this->setUnsignedChar(0x320, 2, _HMI_VERSION_MAIN);
        this->setUnsignedChar(0x320, 3, _HMI_VERSION_MINOR);
        this->setUnsignedChar(0x321, 0, this->hmisetDateTime.toString("yy").toInt());
        this->setUnsignedChar(0x321, 1, this->hmisetDateTime.toString("MM").toInt());
        this->setUnsignedChar(0x321, 2, this->hmisetDateTime.toString("dd").toInt());
        this->setUnsignedChar(0x321, 3, this->hmisetDateTime.toString("hh").toInt());
        this->setUnsignedChar(0x321, 4, this->hmisetDateTime.toString("mm").toInt());
        this->setUnsignedChar(0x321, 5, this->hmisetDateTime.toString("ss").toInt());

        this->setUnsignedChar(0x320, 31, this->flagChecker);
        this->setBool(0x321, 10, 0, this->TimeSetMode);
        this->setBool(0x322, 8, 0, this->saveWheelDigflag_Tc1);
        this->setBool(0x322, 8, 2, this->saveWheelDigflag_Mp1);
        this->setBool(0x322, 8, 3, this->saveWheelDigflag_Mp2);
        this->setBool(0x322, 8, 5, this->saveWheelDigflag_Tc2);
        this->setUnsignedChar(0x322, 0, this->wheelDiameterTc1);
        this->setUnsignedChar(0x322, 2, this->wheelDiameterMp1);
        this->setUnsignedChar(0x322, 3, this->wheelDiameterMp2);
        this->setUnsignedChar(0x322, 5, this->wheelDiameterTc2);
        this->setBool(0x322, 17, 3, this->bcuSelfTest);
        this->setUnsignedChar(0x322, 7, this->hmiBcuTestCode);

        this->setUnsignedChar(0x321, 11, this->hmiAirconditionerModeTc1);
        this->setUnsignedChar(0x321, 13, this->hmiAirconditionerModeMp1);
        this->setUnsignedChar(0x321, 14, this->hmiAirconditionerModeMp2);
        this->setUnsignedChar(0x321, 16, this->hmiAirconditionerModeTc2);

        this->setUnsignedChar(0x321, 19, this->hmiTc1Temperature);
        this->setUnsignedChar(0x321, 21, this->hmiMp1Temperature);
        this->setUnsignedChar(0x321, 22, this->hmiMp2Temperature);
        this->setUnsignedChar(0x321, 24, this->hmiTc2Temperature);

        this->setBool(0x321, 27, 0, this->hmiSaveAirConditionerTc1);
        this->setBool(0x321, 27, 2, this->hmiSaveAirConditionerMp1);
        this->setBool(0x321, 27, 3, this->hmiSaveAirConditionerMp2);
        this->setBool(0x321, 27, 5, this->hmiSaveAirConditionerTc2);

        this->setBool(0x321, 28, 0, this->hmiSaveAirConditionerTempTc1);
        this->setBool(0x321, 28, 2, this->hmiSaveAirConditionerTempMp1);
        this->setBool(0x321, 28, 3, this->hmiSaveAirConditionerTempMp2);
        this->setBool(0x321, 28, 5, this->hmiSaveAirConditionerTempTc2);

        //emergencyBroadcast
        this->setUnsignedChar(0x322, 11, this->hmiEmergencyCode);
        this->setBool(0x322, 17, 1, this->hmiEmergencyCommand);
        this->setBool(0x322, 17, 2, this->hmiEmergencyStop);

        //BCG
        this->setBool(0x322, 15, 0, this->hmiCutBCG1);
        this->setBool(0x322, 15, 1, this->hmiCutBCG2);
        this->setBool(0x322, 15, 2, this->hmiResetBCG1);
        this->setBool(0x322, 15, 3, this->hmiResetBCG2);

        // TrainNum and LineNum
        this->setUnsignedChar(0x321, 6, this->hmiTrainNumber);
        this->setUnsignedChar(0x321, 7, this->hmiLineNumber);
        this->setBool(0x321, 10, 1, this->hmiSaveTrainNum);
        this->setBool(0x321, 10, 2, this->hmiSaveLineNum);

        //fau
        this->setBool(0x322, 16, 0, this->hmiMuteFau);
        this->setBool(0x322, 16, 1, this->hmiResetFau);

        //siv
        this->setBool(0x322, 15, 4, this->hmiResetSIV1);
        this->setBool(0x322, 15, 5, this->hmiResetSIV2);
        this->setBool(0x322, 15, 6, this->hmiCutSIV1);
        this->setBool(0x322, 15, 7, this->hmiCutSIV2);

        //service kilometers
        this->setUnsignedInt32(0x323, 22, this->hmiSetServiceKilometer);
        //running kilometers
        this->setUnsignedInt32(0x323, 27, this->hmiSetRunningKilometer);

        //running record clear page
        this->setBool(0x323, 0, 0, this->hmiClearERMAP1Time);
        this->setBool(0x323, 0, 1, this->hmiClearERMAP2Time);
        this->setBool(0x323, 0, 2, this->hmiClearTractionCost);
        this->setBool(0x323, 0, 3, this->hmiClearServiceDistance);
        this->setBool(0x323, 0, 4, this->hmiClearAuxCost);

        //speed test
        this->setBool(0x322, 17, 4, this->hmiAcTeststart);
        this->setBool(0x322, 17, 5, this->hmiAcTestStop);

        //HVAC new wind
        this->setBool(0x321, 10, 5, this->hmiTc1WindSpd);
        this->setBool(0x321, 10, 6, this->hmiTc2WindSpd);
        this->setBool(0x321, 10, 7, this->hmiMp1WindSpd);
        this->setBool(0x321, 27, 6, this->hmiMp2WindSpd);

        this->setBool(0x321, 27, 7, this->hmiNewWindSave);
        this->setUnsignedChar(0x321, 17, this->hmiTc1WindMode);
        this->setUnsignedChar(0x321, 18, this->hmiTc2WindMode);
        this->setUnsignedChar(0x321, 25, this->hmiMp1WindMode);
        this->setUnsignedChar(0x321, 26, this->hmiMp2WindMode);

        this->setBool(0x322, 16, 2, this->hmiResetSIV1Egy);
        this->setBool(0x322, 16, 3, this->hmiResetSIV2Egy);
        this->setBool(0x322, 16, 4, this->hmiResetDCU1Egy);
        this->setBool(0x322, 16, 5, this->hmiResetDCU2Egy);
        this->setBool(0x322, 16, 6, this->hmiResetDCU3Egy);
        this->setBool(0x322, 16, 7, this->hmiResetDCU4Egy);

        //traction isolate
        this->setBool(0x322, 12, 0, this->mp1Tcu1Isolate);
        this->setBool(0x322, 12, 1, this->mp1Tcu2Isolate);
        this->setBool(0x322, 12, 2, this->mp1Tcu3Isolate);
        this->setBool(0x322, 12, 3, this->mp1Tcu4Isolate);
        this->setBool(0x322, 12, 4, this->mp2Tcu1Isolate);
        this->setBool(0x322, 12, 5, this->mp2Tcu2Isolate);
        this->setBool(0x322, 12, 6, this->mp2Tcu3Isolate);
        this->setBool(0x322, 12, 7, this->mp2Tcu4Isolate);

        this->setBool(0x322, 13, 0, this->keepBrakeState);
    }
}
