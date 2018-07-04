#ifndef GLOBAL_H
#define GLOBAL_H

#include <stdlib.h>
#include <PixyMvbLib.h>
#include <PixyTypes.h>
#include <QString>
#include <QDateTime>

#define _HMI_VERSION_MAIN 2
#define _HMI_VERSION_MINOR 34

#define USER_DEBUG_MODE
#define _LOG_MAX_SIZE (3 * 1024 * 1024)

#define BUTTON_DOWN ("font: 20px, SimHei; color: white; background-color: rgb(0, 0, 255);")
#define BUTTON_UP ("background-color: rgb(250, 250, 250);")

#define _WHITECOLOR QColor(255, 255, 255)
#define _BLUECOLOR  QColor(0, 255, 255)

enum pageIndex
{    
    uNetWorkPage = 0,
    uNetWorkHelpPage,
    uRunStatePage,
    uRunStateHelpPage1,
    uRunStateHelpPage2,
    uRunStateHelpPage3,
    uRunStateHelpPage4,
    uBrakeStatePage,
    uTractionPage,
    uAssistantPage,
    uOtherChannelsPage,
    uOtherChannelsHelpPage,
    uAirConditionerPage,
    uAirConditionerHelpPage,
    uFireAlertPage,
    uRepairPage,
    uMainPage,
    uDebugPage,
    uAllportsPage,
    uLifeSignalsPage,
    uRIOMDebugPage,
    uPublishSetPage,
    uEmergencyBroadcast,
    uRunstateHelpPage1,
    uBrakeStateHelpPage1,
    uSetpasswordPage,
    uMaintainLoginPage,
    uMaintainancePage,
    uBrakestateHelpPage,
    uTractionHelpPage,
    uTractionHelpPage2,
    uAssistantHelpPage,
    uChargerPage,
    uBatteryPage,
    uChargerHelpPage,
    uBatteryHelpPage,
    uVersionInfoPage,
    uTimeSetPage,
    uWheelDiaSet,
    uSetParameterPage,
    uDataMoniter,
    uBrakeSelfCheckPage,
    uTractionTestPage,
    uTestPage,
    uDriverTestPage,
    uSetVehicleNo,
    uSpeedTestPage,
    uRunningRecordPage,
    uRunningRecordClearPage,
    uRunningRecordSet,
    uHistoryFault,
    uCurrentFaultList,
    uTractionIsolate
};

enum pagePosition
{
    uTop = 0,
    uMiddle,
    uBottom,
    uHuge,
    uTopInner,
    uMiddleInner
};

enum port_size
{
    uFCode1 = 1,
    uFCode2,
    uFCode3,
    uFCode4
};

enum port_type
{
    uSinkPort = 0,
    uSourcePort,
    uUserDefinePort
};

struct port
{
    unsigned short int address;
    enum port_size size;
    enum port_type type;
    unsigned short int cycle;

    port(unsigned short int a, enum port_size s, enum port_type t, unsigned short int c)
    {
        this->address = a;
        this->size = s;
        this->type = t;
        this->cycle = c;
    }
};


struct port_data
{
    PIXYMVB_Data data;
    unsigned short int time;

    port_data()
    {
        memset(data, 0, sizeof data);
        time = 65535;
    }
};



#define _LOG qDebug() << __DATE__ << __TIME__ << __FILE__ << __LINE__
#define _NO_DATABASE_WARNING    \
                                if (this->database == NULL) \
                                { \
                                    _LOG << "no database"; \
                                \
                                    return; \
                                }
#endif // GLOBAL_H
