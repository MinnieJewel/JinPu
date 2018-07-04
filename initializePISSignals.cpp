#include "database.h"
#include "global.h"
#include <QDebug>

void Database::initializePisSignals()
{
    this->pisAutoMode = false;
    this->PA1CT_MasterActive = false;
    this->PA2CT_MasterActive = false;
}
void Database::synchronizePISSignals()
{
    //0x810
    this->PA1CT_LifeSignal = getUnsignedInt(0x810,0);
    this->PA1CT_PASwVersion = getUnsignedChar(0x810,2);
    if(this->CTHM_PIS1On)
    {
        this->pisVersion1.sprintf("%2d.%-1d", getUnsignedChar(0x810, 2) / 10, getUnsignedChar(0x810, 2) % 10);
    }
    else
    {
        this->pisVersion1 = QString("0");
    }
    this->PA1CT_StreamDirection = getBool(0x810,3,0);
    this->PA1CT_SkipStation = getBool(0x810,3,1);
    this->PA1CT_SkipNextStation = getBool(0x810,3,2);
    this->PA1CT_RightDoorOpen = getBool(0x810,3,4);
    this->PA1CT_LeftDoorOpen = getBool(0x810,3,5);
    this->PA1CT_StartStationID = getUnsignedInt(0x810,4);
    this->PA1CT_DestinationID = getUnsignedInt(0x810,6);
    this->PA1CT_NextStation = getUnsignedInt(0x810,8);
    this->PA1CT_EmBroadcastID = getUnsignedChar(0x810,10);
    this->PA1CT_MasterActive = getBool(0x810,11,0);
    this->PA1CT_AutoMode = getBool(0x810,11,1);
    this->PA1CT_CabTalk = getBool(0x810,11,2);
    this->PA1CT_BroadcastingSta = getBool(0x810,11,3);
    this->PA1CT_OCCBroadcast = getBool(0x810,11,4);
    this->PA1CT_BCStationFB = getUnsignedChar(0x810,12);
    this->PA1CT_Tc1EMC1Alarm = getBool(0x810,13,0);
    this->PA1CT_Tc1EMC1On = getBool(0x810,13,1);
    this->PA1CT_Tc1EMC2Alarm = getBool(0x810,13,2);
    this->PA1CT_Tc1EMC2On = getBool(0x810,13,3);
    this->PA1CT_Mp1EMC1Alarm = getBool(0x810,13,4);
    this->PA1CT_Mp1EMC1On = getBool(0x810,13,5);
    this->PA1CT_Mp1EMC2Alarm = getBool(0x810,13,6);
    this->PA1CT_Mp1EMC2On = getBool(0x810,13,7);
    this->PA1CT_Mp2EMC1Alarm = getBool(0x810,15,0);
    this->PA1CT_Mp2EMC1On = getBool(0x810,15,1);
    this->PA1CT_Mp2EMC2Alarm = getBool(0x810,15,2);
    this->PA1CT_Mp2EMC2On = getBool(0x810,15,3);
    this->PA1CT_Tc2EMC1Alarm = getBool(0x810,15,4);
    this->PA1CT_Tc2EMC1On = getBool(0x810,15,5);
    this->PA1CT_Tc2EMC2Alarm = getBool(0x810,15,6);
    this->PA1CT_Tc2EMC2On = getBool(0x810,15,7);
    this->PA1CT_Tc1EMC3Alarm = getBool(0x810,16,0);
    this->PA1CT_Tc1EMC3On = getBool(0x810,16,1);
    this->PA1CT_Tc1EMC4Alarm = getBool(0x810,16,2);
    this->PA1CT_Tc1EMC4On = getBool(0x810,16,3);
    this->PA1CT_Mp1EMC3Alarm = getBool(0x810,16,4);
    this->PA1CT_Mp1EMC3On = getBool(0x810,16,5);
    this->PA1CT_Mp1EMC4Alarm = getBool(0x810,16,6);
    this->PA1CT_Mp1EMC4On = getBool(0x810,16,7);
    this->PA1CT_Mp2EMC3Alarm = getBool(0x810,18,0);
    this->PA1CT_Mp2EMC3On = getBool(0x810,18,1);
    this->PA1CT_Mp2EMC4Alarm = getBool(0x810,18,2);
    this->PA1CT_Mp2EMC4On = getBool(0x810,18,3);
    this->PA1CT_Tc2EMC3Alarm = getBool(0x810,18,4);
    this->PA1CT_Tc2EMC3On = getBool(0x810,18,5);
    this->PA1CT_Tc2EMC4Alarm = getBool(0x810,18,6);
    this->PA1CT_Tc2EMC4On = getBool(0x810,18,7);

    //0x811
    this->PA1CT_Tc1CabConFlt = getBool(0x811,0,0);
    this->PA1CT_Tc1BrdConFlt = getBool(0x811,0,1);
    this->PA1CT_Tc1endLEDFlt = getBool(0x811,0,2);
    this->PA1CT_Tc1RoomConFlt = getBool(0x811,0,3);
    this->PA1CT_Tc1LED1Flt = getBool(0x811,0,4);
    this->PA1CT_Tc1LED2Flt = getBool(0x811,0,5);
    this->PA1CT_Tc1Map1Flt = getBool(0x811,0,6);
    this->PA1CT_Tc1Map2Flt = getBool(0x811,0,7);
    this->PA1CT_Tc1Map3Flt = getBool(0x811,1,0);
    this->PA1CT_Tc1Map4Flt = getBool(0x811,1,1);
    this->PA1CT_Tc1Map5Flt = getBool(0x811,1,2);
    this->PA1CT_Tc1Map6Flt = getBool(0x811,1,3);
    this->PA1CT_Tc1Map7Flt = getBool(0x811,1,4);
    this->PA1CT_Tc1Map8Flt = getBool(0x811,1,5);
    this->PA1CT_Mp1RoomConFlt = getBool(0x811,1,6);
    this->PA1CT_Mp1LED1Flt = getBool(0x811,1,7);
    this->PA1CT_Mp1LED2Flt = getBool(0x811,2,0);
    this->PA1CT_Mp1Map1Flt = getBool(0x811,2,1);
    this->PA1CT_Mp1Map2Flt = getBool(0x811,2,2);
    this->PA1CT_Mp1Map3Flt = getBool(0x811,2,3);
    this->PA1CT_Mp1Map4Flt = getBool(0x811,2,4);
    this->PA1CT_Mp1Map5Flt = getBool(0x811,2,5);
    this->PA1CT_Mp1Map6Flt = getBool(0x811,2,6);
    this->PA1CT_Mp1Map7Flt = getBool(0x811,2,7);
    this->PA1CT_Mp1Map8Flt = getBool(0x811,3,0);
    this->PA1CT_Mp2RoomConFlt = getBool(0x811,5,7);
    this->PA1CT_Mp2LED1Flt = getBool(0x811,6,0);
    this->PA1CT_Mp2LED2Flt = getBool(0x811,6,1);
    this->PA1CT_Mp2Map1Flt = getBool(0x811,6,2);
    this->PA1CT_Mp2Map2Flt = getBool(0x811,6,3);
    this->PA1CT_Mp2Map3Flt = getBool(0x811,6,4);
    this->PA1CT_Mp2Map4Flt = getBool(0x811,6,5);
    this->PA1CT_Mp2Map5Flt = getBool(0x811,6,6);
    this->PA1CT_Mp2Map6Flt = getBool(0x811,6,7);
    this->PA1CT_Mp2Map7Flt = getBool(0x811,7,0);
    this->PA1CT_Mp2Map8Flt = getBool(0x811,7,1);
    this->PA1CT_Tc2CabConFlt = getBool(0x811,7,2);
    this->PA1CT_Tc2BrdConFlt = getBool(0x811,7,3);
    this->PA1CT_Tc2endLEDFlt = getBool(0x811,7,4);
    this->PA1CT_Tc2RoomConFlt = getBool(0x811,7,5);
    this->PA1CT_Tc2LED1Flt = getBool(0x811,7,6);
    this->PA1CT_Tc2LED2Flt = getBool(0x811,7,7);
    this->PA1CT_Tc2Map1Flt = getBool(0x811,8,0);
    this->PA1CT_Tc2Map2Flt = getBool(0x811,8,1);
    this->PA1CT_Tc2Map3Flt = getBool(0x811,8,2);
    this->PA1CT_Tc2Map4Flt = getBool(0x811,8,3);
    this->PA1CT_Tc2Map5Flt = getBool(0x811,8,4);
    this->PA1CT_Tc2Map6Flt = getBool(0x811,8,5);
    this->PA1CT_Tc2Map7Flt = getBool(0x811,8,6);
    this->PA1CT_Tc2Map8Flt = getBool(0x811,8,7);
    this->PA1CT_Tc1Video1NetFlt = getBool(0x811,9,0);
    this->PA1CT_Tc1Video2NetFlt = getBool(0x811,9,1);
    this->PA1CT_Tc1Video3NetFlt = getBool(0x811,9,2);
    this->PA1CT_Mp1Video1NetFlt = getBool(0x811,9,3);
    this->PA1CT_Mp1Video2NetFlt = getBool(0x811,9,4);
    this->PA1CT_Mp2Video1NetFlt = getBool(0x811,10,1);
    this->PA1CT_Mp2Video2NetFlt = getBool(0x811,10,2);
    this->PA1CT_Tc2Video1NetFlt = getBool(0x811,10,3);
    this->PA1CT_Tc2Video2NetFlt = getBool(0x811,10,4);
    this->PA1CT_Tc2Video3NetFlt = getBool(0x811,10,5);

    //0x820
    this->PA2CT_LifeSignal = getUnsignedInt(0x820,0);
    this->PA2CT_PASwVersion = getUnsignedChar(0x820,2);
    if(this->CTHM_PIS2On)
    {
        this->pisVersion2.sprintf("%2d.%-1d", getUnsignedChar(0x820, 2) / 10, getUnsignedChar(0x820, 2) % 10);
    }
    else
    {
        this->pisVersion2 = QString("0");
    }
    this->PA2CT_StreamDirection = getBool(0x820,3,0);
    this->PA2CT_SkipStation = getBool(0x820,3,1);
    this->PA2CT_SkipNextStation = getBool(0x820,3,2);
    this->PA2CT_RightDoorOpen = getBool(0x820,3,4);
    this->PA2CT_LeftDoorOpen = getBool(0x820,3,5);
    this->PA2CT_StartStationID = getUnsignedInt(0x820,4);
    this->PA2CT_DestinationID = getUnsignedInt(0x820,6);
    this->PA2CT_NextStation = getUnsignedInt(0x820,8);
    this->PA2CT_EmBroadcastID = getUnsignedChar(0x820,10);
    this->PA2CT_MasterActive = getBool(0x820,11,0);
    this->PA2CT_AutoMode = getBool(0x820,11,1);
    this->PA2CT_CabTalk = getBool(0x820,11,2);
    this->PA2CT_BroadcastingSta = getBool(0x820,11,3);
    this->PA2CT_OCCBroadcast = getBool(0x820,11,4);
    this->PA2CT_BCStationFB = getUnsignedChar(0x820,12);
    this->PA2CT_Tc1EMC1Alarm = getBool(0x820,13,0);
    this->PA2CT_Tc1EMC1On = getBool(0x820,13,1);
    this->PA2CT_Tc1EMC2Alarm = getBool(0x820,13,2);
    this->PA2CT_Tc1EMC2On = getBool(0x820,13,3);
    this->PA2CT_Mp1EMC1Alarm = getBool(0x820,13,4);
    this->PA2CT_Mp1EMC1On = getBool(0x820,13,5);
    this->PA2CT_Mp1EMC2Alarm = getBool(0x820,13,6);
    this->PA2CT_Mp1EMC2On = getBool(0x820,13,7);
    this->PA2CT_Mp2EMC1Alarm = getBool(0x820,15,0);
    this->PA2CT_Mp2EMC1On = getBool(0x820,15,1);
    this->PA2CT_Mp2EMC2Alarm = getBool(0x820,15,2);
    this->PA2CT_Mp2EMC2On = getBool(0x820,15,3);
    this->PA2CT_Tc2EMC1Alarm = getBool(0x820,15,4);
    this->PA2CT_Tc2EMC1On = getBool(0x820,15,5);
    this->PA2CT_Tc2EMC2Alarm = getBool(0x820,15,6);
    this->PA2CT_Tc2EMC2On = getBool(0x820,15,7);
    this->PA2CT_Tc1EMC3Alarm = getBool(0x820,16,0);
    this->PA2CT_Tc1EMC3On = getBool(0x820,16,1);
    this->PA2CT_Tc1EMC4Alarm = getBool(0x820,16,2);
    this->PA2CT_Tc1EMC4On = getBool(0x820,16,3);
    this->PA2CT_Mp1EMC3Alarm = getBool(0x820,16,4);
    this->PA2CT_Mp1EMC3On = getBool(0x820,16,5);
    this->PA2CT_Mp1EMC4Alarm = getBool(0x820,16,6);
    this->PA2CT_Mp1EMC4On = getBool(0x820,16,7);
    this->PA2CT_Mp2EMC3Alarm = getBool(0x820,18,0);
    this->PA2CT_Mp2EMC3On = getBool(0x820,18,1);
    this->PA2CT_Mp2EMC4Alarm = getBool(0x820,18,2);
    this->PA2CT_Mp2EMC4On = getBool(0x820,18,3);
    this->PA2CT_Tc2EMC3Alarm = getBool(0x820,18,4);
    this->PA2CT_Tc2EMC3On = getBool(0x820,18,5);
    this->PA2CT_Tc2EMC4Alarm = getBool(0x820,18,6);
    this->PA2CT_Tc2EMC4On = getBool(0x820,18,7);

    //0x821
    this->PA2CT_Tc1CabConFlt = getBool(0x821,0,0);
    this->PA2CT_Tc1BrdConFlt = getBool(0x821,0,1);
    this->PA2CT_Tc1endLEDFlt = getBool(0x821,0,2);
    this->PA2CT_Tc1RoomConFlt = getBool(0x821,0,3);
    this->PA2CT_Tc1LED1Flt = getBool(0x821,0,4);
    this->PA2CT_Tc1LED2Flt = getBool(0x821,0,5);
    this->PA2CT_Tc1Map1Flt = getBool(0x821,0,6);
    this->PA2CT_Tc1Map2Flt = getBool(0x821,0,7);
    this->PA2CT_Tc1Map3Flt = getBool(0x821,1,0);
    this->PA2CT_Tc1Map4Flt = getBool(0x821,1,1);
    this->PA2CT_Tc1Map5Flt = getBool(0x821,1,2);
    this->PA2CT_Tc1Map6Flt = getBool(0x821,1,3);
    this->PA2CT_Tc1Map7Flt = getBool(0x821,1,4);
    this->PA2CT_Tc1Map8Flt = getBool(0x821,1,5);
    this->PA2CT_Mp1RoomConFlt = getBool(0x821,1,6);
    this->PA2CT_Mp1LED1Flt = getBool(0x821,1,7);
    this->PA2CT_Mp1LED2Flt = getBool(0x821,2,0);
    this->PA2CT_Mp1Map1Flt = getBool(0x821,2,1);
    this->PA2CT_Mp1Map2Flt = getBool(0x821,2,2);
    this->PA2CT_Mp1Map3Flt = getBool(0x821,2,3);
    this->PA2CT_Mp1Map4Flt = getBool(0x821,2,4);
    this->PA2CT_Mp1Map5Flt = getBool(0x821,2,5);
    this->PA2CT_Mp1Map6Flt = getBool(0x821,2,6);
    this->PA2CT_Mp1Map7Flt = getBool(0x821,2,7);
    this->PA2CT_Mp1Map8Flt = getBool(0x821,3,0);
    this->PA2CT_Mp2RoomConFlt = getBool(0x821,5,7);
    this->PA2CT_Mp2LED1Flt = getBool(0x821,6,0);
    this->PA2CT_Mp2LED2Flt = getBool(0x821,6,1);
    this->PA2CT_Mp2Map1Flt = getBool(0x821,6,2);
    this->PA2CT_Mp2Map2Flt = getBool(0x821,6,3);
    this->PA2CT_Mp2Map3Flt = getBool(0x821,6,4);
    this->PA2CT_Mp2Map4Flt = getBool(0x821,6,5);
    this->PA2CT_Mp2Map5Flt = getBool(0x821,6,6);
    this->PA2CT_Mp2Map6Flt = getBool(0x821,6,7);
    this->PA2CT_Mp2Map7Flt = getBool(0x821,7,0);
    this->PA2CT_Mp2Map8Flt = getBool(0x821,7,1);
    this->PA2CT_Tc2CabConFlt = getBool(0x821,7,2);
    this->PA2CT_Tc2BrdConFlt = getBool(0x821,7,3);
    this->PA2CT_Tc2endLEDFlt = getBool(0x821,7,4);
    this->PA2CT_Tc2RoomConFlt = getBool(0x821,7,5);
    this->PA2CT_Tc2LED1Flt = getBool(0x821,7,6);
    this->PA2CT_Tc2LED2Flt = getBool(0x821,7,7);
    this->PA2CT_Tc2Map1Flt = getBool(0x821,8,0);
    this->PA2CT_Tc2Map2Flt = getBool(0x821,8,1);
    this->PA2CT_Tc2Map3Flt = getBool(0x821,8,2);
    this->PA2CT_Tc2Map4Flt = getBool(0x821,8,3);
    this->PA2CT_Tc2Map5Flt = getBool(0x821,8,4);
    this->PA2CT_Tc2Map6Flt = getBool(0x821,8,5);
    this->PA2CT_Tc2Map7Flt = getBool(0x821,8,6);
    this->PA2CT_Tc2Map8Flt = getBool(0x821,8,7);
    this->PA2CT_Tc1Video1NetFlt = getBool(0x821,9,0);
    this->PA2CT_Tc1Video2NetFlt = getBool(0x821,9,1);
    this->PA2CT_Tc1Video3NetFlt = getBool(0x821,9,2);
    this->PA2CT_Mp1Video1NetFlt = getBool(0x821,9,3);
    this->PA2CT_Mp1Video2NetFlt = getBool(0x821,9,4);
    this->PA2CT_Mp2Video1NetFlt = getBool(0x821,10,1);
    this->PA2CT_Mp2Video2NetFlt = getBool(0x821,10,2);
    this->PA2CT_Tc2Video1NetFlt = getBool(0x821,10,3);
    this->PA2CT_Tc2Video2NetFlt = getBool(0x821,10,4);
    this->PA2CT_Tc2Video3NetFlt = getBool(0x821,10,5);
    if (this->CTHM_PIS1On && this->CTHM_PIS1Active)
    {
        this->pisAutoMode = this->PA1CT_AutoMode;
    }
    else if (this->CTHM_PIS2On && this->CTHM_PIS2Active)
    {
        this->pisAutoMode = this->PA2CT_AutoMode;
    }
}
