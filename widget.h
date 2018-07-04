#ifndef WIDGET_H
#define WIDGET_H

#include <QtGui>
#include <QWidget>
#include <QMap>

namespace Ui {
    class Widget;
}

class QTimer;
class MyBase;
class MvbDriver;
class Database;
class Header;
class Navigator;
class NetWork;
class DebugPage;
class AllPorts;
class LifeSignals;
class RIOMDebug;
class HeaderInner;
class PublishSetPage;
class MainPage;
class NetworkHelpPage;
class EmergencyBroadcast;
class AirCondtionerPage;
class RunStatePage;
class RunstateHelpPage1;
class RunstateHelpPage2;
class RunstateHelpPage3;
class RunstateHelpPage4;
class BrakeStatePage;
class TractionPage;
class AssistantPage;
class OtherChannelsPage;
class OtherChannelsHelpPage;
class AirConditionerPage;
class FireAlertPage;
class SetPasswordPage;
class MaintainLoginPage;
class MaintainancePage;
class VehicleLogo;
class BrakestateHelpPage;
class TractionHelpPage;
class TractionHelpPage2;
class AssistantHelpPage;
class AirConditionerHelpPage;
class ChargerPage;
class BatteryPage;
class ChargerHelpPage;
class BatteryHelpPage;
class VersionInfoPage;
class TimeSetPage;
class WheelDiaSet;
class SetParameterPage;
class DataMoniter;
class BrakeSelfCheckPage;
class TractionTestPage;
class TestPage;
class DriverTestPage;
class SetVehicleNo;
class SpeedTestPage;
class RunningRecordPage;
class RunningRecordClearPage;
class RunningRecordSet;
class HistoryFault;
class CrrcFault;
class CurrentFaultList;
class TractionIsolate;

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void showEvent(QShowEvent *event);
    void keyPressEvent(QKeyEvent *event);
    QMap<int, MyBase *> widgets;
    //void recordCCU();

public slots:
    void changePage(int page);
    void updatePage();
signals:

private:
    Ui::Widget *ui;
    QTimer *timer;
    void checkLogFileSize();
    //void checkCCUFileSize();
    void synchronizeTimeWithCcu();
public:
    Header *header;
    HeaderInner *headerInner;
    Navigator *navigator;
    MvbDriver *mvbDriver;
    Database *database;

//pages
public:
    NetWork *network;
    MainPage *mainPage;
    AllPorts *allPorts;
    DebugPage *debugPage;
    LifeSignals *lifeSignals;
    RIOMDebug *riomDebug;
    PublishSetPage *publishSetPage;
    NetworkHelpPage *networkHelpPage;
    EmergencyBroadcast *emergencyBroadcast;
    RunStatePage *runStatePage;
    RunstateHelpPage1 *runStateHelpPage1;
    RunstateHelpPage2 *runStateHelpPage2;
    RunstateHelpPage3 *runStateHelpPage3;
    RunstateHelpPage4 *runStateHelpPage4;
    BrakeStatePage *brakeStatePage;
    TractionPage *tractionPage;
    AssistantPage *assistantPage;
    OtherChannelsPage *otherChannelsPage;
    OtherChannelsHelpPage *otherChannelsHelpPage;
    AirConditionerPage *airConditionerPage;
    FireAlertPage *fireAlertPage;
    SetPasswordPage *setPasswordPage;
    MaintainLoginPage *maintainLoginPage;
    MaintainancePage *maintainancePage;
    BrakestateHelpPage *brakestateHelpPage;
    TractionHelpPage *tractionHelpPage;
    TractionHelpPage2 *tractionHelpPage2;
    AssistantHelpPage *assistantHelpPage;
    AirConditionerHelpPage *airConditionerHelpPage;
    ChargerPage *chargerPage;
    ChargerHelpPage *chargerHelpPage;
    BatteryPage *batteryPage;
    BatteryHelpPage *batteryHelpPage;
    VersionInfoPage *versionInfoPage;
    TimeSetPage *timeSetPage;
    WheelDiaSet *wheelDiaSet;
    SetParameterPage *setParameterPage;
    DataMoniter *dataMoniter;
    BrakeSelfCheckPage *brakeSelfCheckPage;
    TractionTestPage *tractionTestPage;
    TestPage *testPage;
    DriverTestPage *driverTestPage;
    SetVehicleNo *setVehicleNo;
    SpeedTestPage *speedTestPage;
    RunningRecordPage *runningRecordPage;
    RunningRecordClearPage *runningRecordClearPage;
    RunningRecordSet *runningRecordSet;
    HistoryFault *historyFault;
    CrrcFault *crrcFault;
    CurrentFaultList *currentFaultList;
    TractionIsolate *tractionIsolate;
 };

#endif // WIDGET_H
