#include "database.h"
#include "global.h"
#include <QDebug>

void Database::initializeERMSignals()
{
    this->hmiTestDataValid = false;
    this->hmiRunClass = "无";
    this->hmiRegeneration = "无";
    this->TCMSTotalDay = 0;
    this->TCMSTotalTime = 0;
    this->TCMSTotalTimeDisplay = "";
    this->TCMSTotalTimeYear = 0;
    this->TCMSTotalTimeMonth = 0;
    this->ServiceDistance = 0;
}

void Database::synchronizeERMSignals()
{
    if (this->CTHM_ERM1On)
    {
        this->hmiAccerate = this->CTDT1_Accerate_A1;
        this->hmiBrakeDistance = this->CTDT1_BrakeDistance_A1;
        if(1 == this->CTDT1_RunClass_A1)
            this->hmiRunClass = "加速度1";
        else if (2 == this->CTDT1_RunClass_A1)
            this->hmiRunClass = "加速度2";
        else if (4 == this->CTDT1_RunClass_A1)
            this->hmiRunClass = "减速度";
        else
            this->hmiRunClass = "无";
        this->hmiLevel = this->CTDT1_Level_A1;
        this->hmiBrakeStartSpeed = this->CTDT1_BrakeStartSpeed_A1;
        if(this->CTDT1_Regeneration_A1)
            this->hmiRegeneration = "再生制动";
        else
            this->hmiRegeneration = "无";
        this->hmiTestDataValid = this->CTDT1_TestDataValid;

        this->runningKilometers = this->DT1CT_RunningKilometers_A1;
        this->VVVFEngyConsumption = this->DT1CT_VVVFEngyConsumption_A1;
        this->SIVEngyConsumption = this->DT1CT_SIVEngyConsumption_A1;
        this->ReEngy = this->DT1CT_ReEngy_A1;
        this->ServiceDistance = this->DT1CT_ServiceDistance_A1;
        this->AP1RunningTime = this->DT1CT_AP1RunningTime_A1;
        this->AP2RunningTime = this->DT1CT_AP2RunningTime_A1;
        this->TCMSTotalTime = this->DT1CT_TCMSTotalTime_A1;

        this->totalDistanceYear = this->DT1CT_TotalDistanceYear_A1;
        this->totalDistanceMonth = this->DT1CT_TotalDistanceMonth_A1;
        this->totalDistanceDay = this->DT1CT_TotalDistanceDay_A1;

        this->ridingRateTc1 = this->CTDT1_RidingRateTc1_A1;
        this->ridingRateTc2 = this->CTDT1_RidingRateTc2_A1;
        this->ridingRateMp1 = this->CTDT1_RidingRateMp1_A1;
        this->ridingRateMp2 = this->CTDT1_RidingRateMp2_A1;

        this->VVVFECYear = this->DT1CT_VVVFECYear_A1;
        this->VVVFECMonth = this->DT1CT_VVVFECMonth_A1;
        this->VVVFECDay = this->DT1CT_VVVFECDay_A1;
        this->SIVECYear = this->DT1CT_SIVECYear_A1;
        this->SIVECMonth = this->DT1CT_SIVECMonth_A1;
        this->SIVECDay = this->DT1CT_SIVECDay_A1;

        this->reEngyYear = this->DT1CT_ReEngyYear_A1;
        this->reEngyMonth = this->DT1CT_ReEngyMonth_A1;
        this->reEngyDay = this->DT1CT_ReEngyDay_A1;

        this->serviceDistanceYear = this->DT1CT_ServiceDistanceYear_A1;
        this->serviceDistanceMonth = this->DT1CT_ServiceDistanceMonth_A1;
        this->AP1ECYear = this->DT1CT_AP1ECYear_A1;
        this->AP1ECMonth = this->DT1CT_AP1ECMonth_A1;
        this->AP1ECDay = this->DT1CT_AP1ECDay_A1;
        this->AP2ECYear = this->DT1CT_AP2ECYear_A1;
        this->AP2ECMonth = this->DT1CT_AP2ECMonth_A1;
        this->AP2ECDay = this->DT1CT_AP2ECDay_A1;
        this->TCMSTotalTimeYear = this->DT1CT_TCMSTotalTimeYear_A1;
        this->TCMSTotalTimeMonth = this->DT1CT_TCMSTotalTimeMonth_A1;
        this->TCMSTotalDay = this->DT1CT_TCMSTotalTimeDay_A1;
    }
    else if(this->CTHM_ERM2On)
    {
        this->hmiAccerate = this->CTDT6_Accerate_A2;
        this->hmiBrakeDistance = this->CTDT6_BrakeDistance_A2;
        if(1 == this->CTDT6_RunClass_A2)
            this->hmiRunClass = "加速度1";
        else if (2 == this->CTDT6_RunClass_A2)
            this->hmiRunClass = "加速度2";
        else if (4 == this->CTDT6_RunClass_A2)
            this->hmiRunClass = "减速度";
        else
            this->hmiRunClass = "无";
        this->hmiLevel = this->CTDT6_Level_A2;
        this->hmiBrakeStartSpeed = this->CTDT6_BrakeStartSpeed_A2;
        if(this->CTDT6_Regeneration_A2)
            this->hmiRegeneration = "再生制动";
        else
            this->hmiRegeneration = "无";
        this->hmiTestDataValid = this->CTDT6_TestDataValid;

        this->runningKilometers = this->DT6CT_RunningKilometers_A2;
        this->VVVFEngyConsumption = this->DT6CT_VVVFEngyConsumption_A2;
        this->SIVEngyConsumption = this->DT6CT_SIVEngyConsumption_A2;
        this->ReEngy = this->DT6CT_ReEngy_A2;
        this->ServiceDistance = this->DT6CT_ServiceDistance_A2;
        this->AP1RunningTime = this->DT6CT_AP1RunningTime_A2;
        this->AP2RunningTime = this->DT6CT_AP2RunningTime_A2;
        this->TCMSTotalTime = this->DT6CT_TCMSTotalTime_A2;

        this->totalDistanceYear = this->DT6CT_TotalDistanceYear_A2;
        this->totalDistanceMonth = this->DT6CT_TotalDistanceMonth_A2;
        this->totalDistanceDay = this->DT6CT_TotalDistanceDay_A2;

        this->ridingRateTc1 = this->CTDT6_RidingRateTc1_A2;
        this->ridingRateTc2 = this->CTDT6_RidingRateTc2_A2;
        this->ridingRateMp1 = this->CTDT6_RidingRateMp1_A2;
        this->ridingRateMp2 = this->CTDT6_RidingRateMp2_A2;

        this->VVVFECYear = this->DT6CT_VVVFECYear_A2;
        this->VVVFECMonth = this->DT6CT_VVVFECMonth_A2;
        this->VVVFECDay = this->DT6CT_VVVFECDay_A2;
        this->SIVECYear = this->DT6CT_SIVECYear_A2;
        this->SIVECMonth = this->DT6CT_SIVECMonth_A2;
        this->SIVECDay = this->DT6CT_SIVECDay_A2;

        this->reEngyYear = this->DT6CT_ReEngyYear_A2;
        this->reEngyMonth = this->DT6CT_ReEngyMonth_A2;
        this->reEngyDay = this->DT6CT_ReEngyDay_A2;

        this->serviceDistanceYear = this->DT6CT_ServiceDistanceYear_A2;
        this->serviceDistanceMonth = this->DT6CT_ServiceDistanceMonth_A2;
        this->AP1ECYear = this->DT6CT_AP1ECYear_A2;
        this->AP1ECMonth = this->DT6CT_AP1ECMonth_A2;
        this->AP1ECDay = this->DT6CT_AP1ECDay_A2;
        this->AP2ECYear = this->DT6CT_AP2ECYear_A2;
        this->AP2ECMonth = this->DT6CT_AP2ECMonth_A2;
        this->AP2ECDay = this->DT6CT_AP2ECDay_A2;
        this->TCMSTotalTimeYear = this->DT6CT_TCMSTotalTimeYear_A2;
        this->TCMSTotalTimeMonth = this->DT6CT_TCMSTotalTimeMonth_A2;
        this->TCMSTotalDay = this->DT6CT_TCMSTotalTimeDay_A2;
    }
    //this->serviceDistanceDisplay.sprintf("%d.%d", this->ServiceDistance / 1000, this->ServiceDistance % 1000);
    //this->TCMSTotalTimeDisplay.sprintf("%d.%d", this->TCMSTotalTime / 3600, this->TCMSTotalTime % 3600);
}
