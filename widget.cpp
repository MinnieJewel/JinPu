#include "widget.h"
#include "ui_widget.h"
#include "header.h"
#include "navigator.h"
#include "network.h"
#include "database.h"
#include "mvbdriver.h"
#include "myfunction.h"
#include "allports.h"
#include "debugpage.h"
#include "headerinner.h"
#include "simulation.h"
#include "lifesignals.h"
#include "riomdebug.h"
#include "publishsetpage.h"
#include "mainpage.h"
#include "networkhelppage.h"
#include "emergencybroadcast.h"
#include "airconditionerpage.h"
#include "airconditionerhelppage.h"
#include "runstatepage.h"
#include "brakestatepage.h"
#include "tractionpage.h"
#include "assistantpage.h"
#include "otherchannelspage.h"
#include "otherchannelshelppage.h"
#include "airconditionerpage.h"
#include "firealertpage.h"
#include "runstatehelppage1.h"
#include "runstatehelppage2.h"
#include "runstatehelppage3.h"
#include "runstatehelppage4.h"
#include "setpasswordpage.h"
#include "maintainloginpage.h"
#include "maintainancepage.h"
#include "brakestatehelppage.h"
#include "tractionhelppage.h"
#include "tractionhelppage2.h"
#include "assistanthelppage.h"
#include "chargerpage.h"
#include "batterypage.h"
#include "chargerhelppage.h"
#include "batteryhelppage.h"
#include "versioninfopage.h"
#include "timesetpage.h"
#include "wheeldiaset.h"
#include "setparameterpage.h"
#include "datamoniter.h"
#include "brakeselfcheckpage.h"
#include "tractiontestpage.h"
#include "testpage.h"
#include "drivertestpage.h"
#include "setvehicleno.h"
#include "speedtestpage.h"
#include "runningrecordpage.h"
#include "runningrecordclearpage.h"
#include "runningrecordset.h"
#include "crrcfault.h"
#include "historyfault.h"
#include "currentfaultlist.h"
#include "widget.h"
#include "tractionisolate.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    _LOG << "Widget constructor";
    QDesktopWidget *desktop = QApplication::desktop();
    this->move((desktop->width() - this->width()) / 2, (desktop->height() - this->height()) / 2);

    //initialize the mvb bus and the database at first
    this->database = new Database();
    this->mvbDriver = new MvbDriver();

    MyBase::database = this->database;
    this->crrcFault = new CrrcFault(QString("./ErrorList.txt"), QString("./HistoryFaultList.txt"));
    this->timer = new QTimer;
    connect(timer, SIGNAL(timeout()), this, SLOT(updatePage()));

    this->header = new Header(this);
    this->header->setMyBase(uTop, QString("标题栏"));
    this->header->installCrrcFault(this->crrcFault);
    this->header->show();

    this->headerInner = new HeaderInner(this);
    this->headerInner->setMyBase(uTopInner,QString("子标题栏"));

    this->network = new NetWork(this);
    QList <QString> networkList;
    networkList << "主菜单" << "调试" << "帮助";
    QList <int> numberList ;
    numberList << uMainPage << uDebugPage << uNetWorkHelpPage;
    this->network->setMyBase(QString("网络"), networkList, numberList);
    this->network->installCrrcFault(this->crrcFault);

    this->debugPage = new DebugPage(this);
    this->debugPage->setMyBase(uHuge, "调试界面");
    this->debugPage->setFullScreen();

    this->allPorts = new AllPorts(this);
    this->allPorts->setMyBase(uHuge, QString("riom详细信息"));
    this->allPorts->setInnerHeader();
    this->allPorts->setNoneNavigator();

    this->lifeSignals = new LifeSignals(this);
    this->lifeSignals->setMyBase(uMiddleInner, QString("生命信号"));
    this->lifeSignals->setInnerHeader();

    this->riomDebug = new RIOMDebug(this);
    this->riomDebug->setMyBase(uMiddleInner, QString("RIOM调试"));
    this->riomDebug->setInnerHeader();

    this->versionInfoPage = new VersionInfoPage(this);
    this->versionInfoPage->setMyBase(uMiddleInner, QString("版本信息"));
    this->versionInfoPage->setInnerHeader();

    this->navigator = new Navigator(this);
    this->navigator->setMyBase(uBottom, QString("导航栏"));

    this->publishSetPage = new PublishSetPage(this);
    this->publishSetPage->setMyBase(uHuge, QString("出厂设置"));
    this->publishSetPage->setFullScreen();

    this->timeSetPage = new TimeSetPage(this);
    this->timeSetPage->setMyBase(uMiddle, QString("时间设定"));
    this->timeSetPage->setNoneNavigator();

    this->wheelDiaSet = new WheelDiaSet(this);
    this->wheelDiaSet->setMyBase(uMiddle, QString("轮径值设定"));
    this->wheelDiaSet->setNoneNavigator();

    this->setParameterPage = new SetParameterPage(this);
    this->setParameterPage->setMyBase(uMiddle, QString("参数设置"));
    this->setParameterPage->setNoneNavigator();

    this->mainPage = new MainPage(this);
    QList <QString> netMainPageList;
    QList <int> netMainPageNumberList;
    netMainPageList << "网络" << "运行" << "制动状态" << "牵引状态" << "辅助状态" << "旁路状态" << "空调设置" << "烟火报警" << "充电机" << "蓄电池" << "维修菜单" ;
    netMainPageNumberList << uNetWorkPage << uRunStatePage << uBrakeStatePage << uTractionPage << uAssistantPage << uOtherChannelsPage << uAirConditionerPage << uFireAlertPage << uChargerPage << uBatteryPage << uMaintainLoginPage ;
    this->mainPage->setMyBase(QString("主菜单"), netMainPageList, netMainPageNumberList);

    this->networkHelpPage = new NetworkHelpPage(this);
    this->networkHelpPage->setMyBase(uMiddleInner, QString("通信状态帮助"));
    this->networkHelpPage->setInnerHeader();
    this->networkHelpPage->setNoneNavigator();

    this->emergencyBroadcast = new EmergencyBroadcast(this);
    this->emergencyBroadcast->setMyBase(uMiddleInner, QString("紧急广播"));
    this->emergencyBroadcast->setInnerHeader();
    this->emergencyBroadcast->setNoneNavigator();

    this->runStatePage = new RunStatePage(this);
    QList <QString> runStatePageList;
    QList <int> runStatePageNumberList;
    runStatePageList << "主菜单" << "运行" << "制动状态" << "牵引状态" << "辅助状态" << "旁路状态" << "空调设置" << "烟火报警" << "充电机" << "蓄电池" << "帮助";
    runStatePageNumberList << uMainPage << uRunStatePage << uBrakeStatePage << uTractionPage << uAssistantPage << uOtherChannelsPage << uAirConditionerPage << uFireAlertPage << uChargerPage << uBatteryPage << uRunStateHelpPage1;
    this->runStatePage->setMyBase(QString("运行"), runStatePageList, runStatePageNumberList);

    this->runStateHelpPage1 = new RunstateHelpPage1(this);
    this->runStateHelpPage1->setMyBase(uMiddleInner, QString("运行帮助"));
    this->runStateHelpPage1->setInnerHeader();
    this->runStateHelpPage1->setNoneNavigator();

    this->runStateHelpPage2 = new RunstateHelpPage2(this);
    this->runStateHelpPage2->setMyBase(uMiddleInner, QString("运行帮助"));
    this->runStateHelpPage2->setInnerHeader();
    this->runStateHelpPage2->setNoneNavigator();

    this->runStateHelpPage3 = new RunstateHelpPage3(this);
    this->runStateHelpPage3->setMyBase(uMiddleInner, QString("运行帮助"));
    this->runStateHelpPage3->setInnerHeader();
    this->runStateHelpPage3->setNoneNavigator();

    this->runStateHelpPage4 = new RunstateHelpPage4(this);
    this->runStateHelpPage4->setMyBase(uMiddleInner, QString("运行帮助"));
    this->runStateHelpPage4->setInnerHeader();
    this->runStateHelpPage4->setNoneNavigator();

    this->brakeStatePage = new BrakeStatePage(this);
    QList <QString> brakeStatePageList;
    QList <int> brakeStatePageNumberList;
    brakeStatePageList << "主菜单" << "运行" << "制动状态" << "牵引状态" << "辅助状态" << "旁路状态" << "空调设置" << "烟火报警" << "充电机" << "蓄电池" << "帮助";
    brakeStatePageNumberList << uMainPage << uRunStatePage << uBrakeStatePage << uTractionPage << uAssistantPage << uOtherChannelsPage << uAirConditionerPage << uFireAlertPage << uChargerPage << uBatteryPage << uBrakestateHelpPage;
    this->brakeStatePage->setMyBase(QString("制动状态"), brakeStatePageList, brakeStatePageNumberList);

    this->tractionPage = new TractionPage(this);
    QList <QString> tractionPageList;
    QList <int> tractionPageNumberList;
    tractionPageList << "主菜单" << "运行" << "制动状态" << "牵引状态" << "辅助状态" << "旁路状态" << "空调设置" << "烟火报警" << "充电机" << "蓄电池" << "帮助";
    tractionPageNumberList << uMainPage << uRunStatePage << uBrakeStatePage << uTractionPage << uAssistantPage << uOtherChannelsPage << uAirConditionerPage << uFireAlertPage << uChargerPage << uBatteryPage << uTractionHelpPage;
    this->tractionPage->setMyBase(QString("牵引状态"), tractionPageList, tractionPageNumberList);

    this->tractionHelpPage = new TractionHelpPage(this);
    this->tractionHelpPage->setMyBase(uMiddleInner, QString("牵引帮助"));
    this->tractionHelpPage->setInnerHeader();
    this->tractionHelpPage->setNoneNavigator();

    this->tractionHelpPage2 = new TractionHelpPage2(this);
    this->tractionHelpPage2->setMyBase(uMiddleInner, QString("牵引帮助"));
    this->tractionHelpPage2->setInnerHeader();
    this->tractionHelpPage2->setNoneNavigator();

    this->assistantPage = new AssistantPage(this);
    QList <QString> assistantPageList;
    QList <int> assistantPageNumberList;
    assistantPageList << "主菜单" << "运行" << "制动状态" << "牵引状态" << "辅助状态" << "旁路状态" << "空调设置" << "烟火报警" << "充电机" << "蓄电池" << "帮助";
    assistantPageNumberList << uMainPage << uRunStatePage << uBrakeStatePage << uTractionPage << uAssistantPage << uOtherChannelsPage << uAirConditionerPage << uFireAlertPage << uChargerPage << uBatteryPage << uAssistantHelpPage;
    this->assistantPage->setMyBase(QString("辅助状态"), assistantPageList, assistantPageNumberList);

    this->assistantHelpPage = new AssistantHelpPage(this);
    this->assistantHelpPage->setMyBase(uMiddleInner, QString("辅助帮助"));
    this->assistantHelpPage->setInnerHeader();
    this->assistantHelpPage->setNoneNavigator();

    this->otherChannelsPage = new OtherChannelsPage(this);
    QList <QString> otherChannelsPageList;
    QList <int> otherChannelsPageNumberList;
    otherChannelsPageList << "主菜单" << "运行" << "制动状态" << "牵引状态" << "辅助状态" << "旁路状态" << "空调设置" << "烟火报警" << "充电机" << "蓄电池" << "帮助";
    otherChannelsPageNumberList << uMainPage << uRunStatePage << uBrakeStatePage << uTractionPage << uAssistantPage << uOtherChannelsPage << uAirConditionerPage << uFireAlertPage << uChargerPage << uBatteryPage << uOtherChannelsHelpPage;
    this->otherChannelsPage->setMyBase(QString("旁路状态"), otherChannelsPageList, otherChannelsPageNumberList);

    this->otherChannelsHelpPage = new OtherChannelsHelpPage(this);
    this->otherChannelsHelpPage->setMyBase(uMiddleInner, QString("旁路帮助"));
    this->otherChannelsHelpPage->setInnerHeader();
    this->otherChannelsHelpPage->setNoneNavigator();

    this->airConditionerPage = new AirConditionerPage(this);
    QList <QString> airConditionerPageList;
    QList <int> airConditionerPageNumberList;
    airConditionerPageList << "主菜单" << "运行" << "制动状态" << "牵引状态" << "辅助状态" << "旁路状态" << "空调设置" << "烟火报警" << "充电机" << "蓄电池" << "帮助";
    airConditionerPageNumberList << uMainPage << uRunStatePage << uBrakeStatePage << uTractionPage << uAssistantPage << uOtherChannelsPage << uAirConditionerPage << uFireAlertPage << uChargerPage << uBatteryPage << uAirConditionerHelpPage;
    this->airConditionerPage->setMyBase(QString("空调设置"), airConditionerPageList, airConditionerPageNumberList);

    this->airConditionerHelpPage = new AirConditionerHelpPage(this);
    this->airConditionerHelpPage->setMyBase(uMiddleInner, QString("空调帮助"));
    this->airConditionerHelpPage->setInnerHeader();
    this->airConditionerHelpPage->setNoneNavigator();

    this->fireAlertPage = new FireAlertPage(this);
    QList <QString> fireAlertPageList;
    QList <int> fireAlertPageNumberList;
    fireAlertPageList << "主菜单" << "运行" << "制动状态" << "牵引状态" << "辅助状态" << "旁路状态" << "空调设置" << "烟火报警" << "充电机" << "蓄电池";
    fireAlertPageNumberList << uMainPage << uRunStatePage << uBrakeStatePage << uTractionPage << uAssistantPage << uOtherChannelsPage << uAirConditionerPage << uFireAlertPage << uChargerPage << uBatteryPage ;
    this->fireAlertPage->setMyBase(QString("烟火报警"), fireAlertPageList, fireAlertPageNumberList);

    this->chargerPage = new ChargerPage(this);
    QList <QString> chargerPageList;
    QList <int> chargerPageNumberList;
    chargerPageList << "主菜单" << "运行" << "制动状态" << "牵引状态" << "辅助状态" << "旁路状态" << "空调设置" << "烟火报警" << "充电机" << "蓄电池" << "帮助";
    chargerPageNumberList << uMainPage << uRunStatePage << uBrakeStatePage << uTractionPage << uAssistantPage << uOtherChannelsPage << uAirConditionerPage << uFireAlertPage << uChargerPage << uBatteryPage << uChargerHelpPage;
    this->chargerPage->setMyBase(QString("充电机"), chargerPageList, chargerPageNumberList);

    this->batteryPage = new BatteryPage(this);
    QList <QString> batteryPageList;
    QList <int> batteryPageNumberList;
    batteryPageList << "主菜单" << "运行" << "制动状态" << "牵引状态" << "辅助状态" << "旁路状态" << "空调设置" << "烟火报警" << "充电机" << "蓄电池" << "帮助";
    batteryPageNumberList << uMainPage << uRunStatePage << uBrakeStatePage << uTractionPage << uAssistantPage << uOtherChannelsPage << uAirConditionerPage << uFireAlertPage << uChargerPage << uBatteryPage << uBatteryHelpPage;
    this->batteryPage->setMyBase(QString("蓄电池"), batteryPageList, batteryPageNumberList);

    this->chargerHelpPage = new ChargerHelpPage(this);
    this->chargerHelpPage->setMyBase(uMiddleInner, QString("充电机帮助"));
    this->chargerHelpPage->setInnerHeader();
    this->chargerHelpPage->setNoneNavigator();

    this->batteryHelpPage = new BatteryHelpPage(this);
    this->batteryHelpPage->setMyBase(uMiddleInner, QString("蓄电池帮助"));
    this->batteryHelpPage->setInnerHeader();
    this->batteryHelpPage->setNoneNavigator();

    this->setPasswordPage = new SetPasswordPage(this);
    this->setPasswordPage->setMyBase(uMiddle, QString("密码设置"));
    this->setPasswordPage->setNoneNavigator();

    this->maintainLoginPage = new MaintainLoginPage(this);
    this->maintainLoginPage->setMyBase(uMiddle, QString("登录"));
    this->maintainLoginPage->setNoneNavigator();

    this->maintainancePage = new MaintainancePage(this);
    this->maintainancePage->setMyBase(uMiddle, QString("维修菜单"));
    this->maintainancePage->setNoneNavigator();

    this->brakestateHelpPage = new BrakestateHelpPage(this);
    this->brakestateHelpPage->setMyBase(uMiddleInner, QString("制动帮助"));
    this->brakestateHelpPage->setNoneNavigator();
    this->brakestateHelpPage->setInnerHeader();

    this->dataMoniter = new DataMoniter(this);
    this->dataMoniter->setMyBase(uHuge, QString("数据监控"));
    this->dataMoniter->setFullScreen();

    this->brakeSelfCheckPage = new BrakeSelfCheckPage(this);
    this->brakeSelfCheckPage->setMyBase(uMiddle, QString("制动自检"));
    this->brakeSelfCheckPage->setNoneNavigator();

    this->tractionTestPage = new TractionTestPage(this);
    this->tractionTestPage->setMyBase(uMiddle, QString("牵引测试"));
    this->tractionTestPage->setNoneNavigator();

    this->testPage = new TestPage(this);
    this->testPage->setMyBase(uMiddle, QString("测试"));
    this->testPage->setNoneNavigator();

    this->driverTestPage = new DriverTestPage(this);
    this->driverTestPage->setMyBase(uMiddle, QString("司控器测试"));
    this->driverTestPage->setNoneNavigator();

    this->setVehicleNo = new SetVehicleNo(this);
    this->setVehicleNo->setMyBase(uMiddle, QString("列车号/\n线路号设置"));
    this->setVehicleNo->setNoneNavigator();

    this->speedTestPage = new SpeedTestPage(this);
    this->speedTestPage->setMyBase(uMiddle, QString("加减速度\n测试"));
    this->speedTestPage->setNoneNavigator();

    this->runningRecordPage = new RunningRecordPage(this);
    this->runningRecordPage->setMyBase(uMiddle, QString("运行记录"));
    this->runningRecordPage->setNoneNavigator();

    this->runningRecordClearPage = new RunningRecordClearPage(this);
    this->runningRecordClearPage->setMyBase(uMiddle, QString("运行记录\n清零"));
    this->runningRecordClearPage->setNoneNavigator();

    this->runningRecordSet = new RunningRecordSet(this);
    this->runningRecordSet->setMyBase(uMiddle, QString("运行记录\n设置"));
    this->runningRecordSet->setNoneNavigator();

    this->historyFault = new HistoryFault(this);
    this->historyFault->setMyBase(uMiddleInner, QString("历史故障"));
    this->historyFault->setInnerHeader();
    this->historyFault->setNoneNavigator();
    this->historyFault->installCrrcFault(this->crrcFault);

    this->currentFaultList = new CurrentFaultList(this);
    this->currentFaultList->setMyBase(uMiddleInner, QString("运行故障"));
    this->currentFaultList->setInnerHeader();
    this->currentFaultList->setNoneNavigator();
    this->currentFaultList->installCrrcFault(this->crrcFault);

    this->tractionIsolate = new TractionIsolate(this);
    this->tractionIsolate->setMyBase(uMiddleInner, QString("牵引隔离"));
    this->tractionIsolate->setInnerHeader();
    this->tractionIsolate->setNoneNavigator();


    //connect windows with the enum
    this->widgets.insert(uNetWorkPage, this->network);
    this->widgets.insert(uDebugPage, this->debugPage);
    this->widgets.insert(uAllportsPage,this->allPorts);
    this->widgets.insert(uLifeSignalsPage, this->lifeSignals);
    this->widgets.insert(uRIOMDebugPage, this->riomDebug);
    this->widgets.insert(uPublishSetPage, this->publishSetPage);
    this->widgets.insert(uMainPage, this->mainPage);
    this->widgets.insert(uNetWorkHelpPage, this->networkHelpPage);
    this->widgets.insert(uEmergencyBroadcast, this->emergencyBroadcast);
    this->widgets.insert(uRunStatePage, this->runStatePage);
    this->widgets.insert(uBrakeStatePage, this->brakeStatePage);
    this->widgets.insert(uTractionPage, this->tractionPage);
    this->widgets.insert(uAssistantPage, this->assistantPage);
    this->widgets.insert(uOtherChannelsPage, this->otherChannelsPage);
    this->widgets.insert(uAirConditionerPage, this->airConditionerPage);
    this->widgets.insert(uFireAlertPage, this->fireAlertPage);
    this->widgets.insert(uRunStateHelpPage1, this->runStateHelpPage1);
    this->widgets.insert(uRunStateHelpPage2, this->runStateHelpPage2);
    this->widgets.insert(uRunStateHelpPage3, this->runStateHelpPage3);
    this->widgets.insert(uRunStateHelpPage4, this->runStateHelpPage4);
    this->widgets.insert(uSetpasswordPage, this->setPasswordPage);
    this->widgets.insert(uMaintainLoginPage, this->maintainLoginPage);
    this->widgets.insert(uMaintainancePage, this->maintainancePage);
    this->widgets.insert(uBrakestateHelpPage, this->brakestateHelpPage);
    this->widgets.insert(uTractionHelpPage, this->tractionHelpPage);
    this->widgets.insert(uTractionHelpPage2, this->tractionHelpPage2);
    this->widgets.insert(uAssistantHelpPage, this->assistantHelpPage);
    this->widgets.insert(uOtherChannelsHelpPage, this->otherChannelsHelpPage);
    this->widgets.insert(uAirConditionerHelpPage, this->airConditionerHelpPage);
    this->widgets.insert(uChargerPage, this->chargerPage);
    this->widgets.insert(uBatteryPage, this->batteryPage);
    this->widgets.insert(uBatteryHelpPage, this->batteryHelpPage);
    this->widgets.insert(uChargerHelpPage, this->chargerHelpPage);
    this->widgets.insert(uVersionInfoPage, this->versionInfoPage);
    this->widgets.insert(uTimeSetPage, this->timeSetPage);
    this->widgets.insert(uWheelDiaSet, this->wheelDiaSet);
    this->widgets.insert(uSetParameterPage, this->setParameterPage);
    this->widgets.insert(uDataMoniter, this->dataMoniter);
    this->widgets.insert(uBrakeSelfCheckPage, this->brakeSelfCheckPage);
    this->widgets.insert(uTractionTestPage, this->tractionTestPage);
    this->widgets.insert(uTestPage, this->testPage);
    this->widgets.insert(uDriverTestPage, this->driverTestPage);
    this->widgets.insert(uSetVehicleNo, this->setVehicleNo);
    this->widgets.insert(uSpeedTestPage, this->speedTestPage);
    this->widgets.insert(uRunningRecordPage, this->runningRecordPage);
    this->widgets.insert(uRunningRecordClearPage, this->runningRecordClearPage);
    this->widgets.insert(uRunningRecordSet, this->runningRecordSet);
    this->widgets.insert(uHistoryFault, this->historyFault);
    this->widgets.insert(uCurrentFaultList, this->currentFaultList);
    this->widgets.insert(uTractionIsolate, this->tractionIsolate);
    _LOG << "widget finished";
}

Widget::~Widget()
{
    delete ui;
}

void Widget::updatePage()
{
    // a counter used to count time, each represent 0.33 second
    static int counter = 1, delay = 0;

    //20s once
    if (0 == counter % 60)
    {
        this->synchronizeTimeWithCcu();
    }

    //update the header and navigator every 0.33 second
    this->header->updatePage();
    this->headerInner->updatePage();
    this->navigator->updatePage();
    //this->recordCCU();
    //update the middle area every 0.33 second
    this->widgets[MyBase::currentPage]->updatePage();

    //refresh the mvb port every 1 second, the code which occupies cpu time a lot should not execute at the same cycle

    if (counter % 3 == 0)
    {
        this->mvbDriver->synchronizeMvbData(this->database->allPorts, this->database->ports);
        this->database->synchronize();
//        #ifndef USER_DEBUG_MODE
//            pixymvb_ForceSwitch();
//        #endif
    }

    if (0 == counter % 4 && delay >= 90)
    {
        this->crrcFault->synchronize(this->database);
    }

    if (delay <= 100)
    //if (delay <= 100 && this->database->hmiCcuOnlineState)
    {
        delay ++;
    }
    //reset the counter, its longest counter time is 10 second

    counter >= 100 ? (counter = 1) : (counter = 0);
}
/*
@author:zhumm
function:record ccu lifesignals and time to files
name: recordCCU
*/
//void Widget::recordCCU()
//{
//    int switchTimes = this->database->checkCcuSwitch(this->database->PUBPORT_TMSLifeSignal);
//    QFile ccuFile("./ccuSignals.txt");
//    if (!ccuFile.open(QIODevice::WriteOnly | QIODevice::Append))
//    {
//        _LOG << "open ccuSignals failed!" << endl;
//        return;
//    }
//    QTextStream ccuInfo(&ccuFile);

//    ccuInfo.setCodec("UTF-8");
//    QString info = "lifeSignal :" + QString::number(this->database->PUBPORT_TMSLifeSignal)+ "\t"
//                   + "time :" + QDateTime::currentDateTime().toString("hh:mm:ss.zzz ") +"\t"+
//                   QDateTime::currentDateTime().toString("yyyy-MM-dd") + "\t"
//                   + "switch " + QString::number(switchTimes) + " times" + "\t"
//                   + "ccu1 active: " + QString::number(this->database->CTHM_CCU1Active) + "\t"
//                   + "ccu2 active: " + QString::number(this->database->CTHM_CCU2Active);
//    ccuInfo << info << endl;
//    ccuFile.close();
//}

//void Widget::checkCCUFileSize()
//{
//    QFileInfo *ccuFileInfo = new QFileInfo("./ccuSignals.txt");

//    if (ccuFileInfo->size() > _LOG_MAX_SIZE)
//    {
//        QFile::remove("./ccuSignals.txt");
//    }

//    delete ccuFileInfo;
//    _LOG << "ccuSignals file has been deleted for its size";
//}


void Widget::changePage(int page)
{
    foreach (int key ,this->widgets.keys())
    {
        if (key == page)
        {
            MyBase::currentPage = page;
            this->widgets[page]->show();

            this->header->setPageName(this->widgets[page]->name);

            //implement dynamic navigator
            if(!(this->widgets[page]->navigatorList.isEmpty() || this->widgets[page]->navigatorPageNo.isEmpty()))
            {
                this->navigator->setButtonsDisplay(this->widgets[page]->navigatorList, this->widgets[page]->navigatorPageNo);
                this->navigator->show();
            }
            //judge if its full screen
            if (this->widgets[page]->getFullScreen())
            {
                this->header->hide();
                this->headerInner->hide();
                this->navigator->hide();
            }
            else
            {
                //judge if its innerHeader
                if(this->widgets[page]->getInnerHeader())
                {
                    this->header->hide();
                    this->headerInner->show();
                    this->headerInner->setPageName(this->widgets[page]->name);
                }
                else
                {
                    this->headerInner->hide();
                    this->header->show();
                    this->header->setPageName(this->widgets[page]->name);
                }
                //judge if its has navigator
                if(this->widgets[page]->getNoneNavigator())
                {
                    this->navigator->hide();
                }
            }
            _LOG << "change page to" << this->widgets[page]->name;
        }
        else
        {
            this->widgets[key]->hide();
        }
    }
}



void Widget::showEvent(QShowEvent *)
{
    this->checkLogFileSize();
    //this->checkCCUFileSize();
    _LOG << "system powers on";

    if (MyFunction::configureValid())
    {
        //read password from file
        this->database->troubleShootingPassword = MyFunction::getString(QString("/Password/troubleShooting"));
        this->database->dataRecordSetPassword = MyFunction::getString(QString("/Password/dataRecordSet"));

        //read vehicle number from file
        this->database->vehicleNumberA1 = MyFunction::getString(QString("/VehicleNumber/A1"));
        this->database->vehicleNumberB1 = MyFunction::getString(QString("/VehicleNumber/B1"));
        this->database->vehicleNumberB2 = MyFunction::getString(QString("/VehicleNumber/B2"));
        this->database->vehicleNumberA2 = MyFunction::getString(QString("/VehicleNumber/A2"));
        //read him position from file
        this->database->hmiPosition = MyFunction::getInt(QString("/Position/position"));

        //mvb initial, add ports to mvb board and run mvb board
        this->database->installPorts();
        this->mvbDriver->setMvbConfigure();
        this->mvbDriver->initialMvb(this->database->hmiPosition);
        this->mvbDriver->addPorts(this->database->allPorts);
        this->mvbDriver->setMvbOperation();

        //set ip if hmi1 and hmi2
        if (1 == this->database->hmiPosition)
        {
            system("ifconfig eth0 192.168.2.3");
            qDebug() << "the ip of hmi has been set to 192.168.2.3";
        }

        else if (2 == this->database->hmiPosition)
        {
            system("ifconfig eth0 192.168.2.4");
            qDebug() << "the ip of hmi has been set to 192.168.2.4";
        }
        //show the allPorts page and start the timer to update
        //the timer's time out is 333ms which means 3 times each second
        //this->allPorts = new AllPorts(this);
        this->timer->start(333);
        this->network->show();
       // this->allPorts->show();
        this->navigator->setButtonsDisplay(this->network->navigatorList, this->network->navigatorPageNo);
        this->navigator->show();
    }
    else
    {
        //show a warning message box
        _LOG << "fail to read configure file.";
    }
}


void Widget::checkLogFileSize()
{
    QFileInfo *fileInfo = new QFileInfo("./log.txt");

    if (fileInfo->size() > _LOG_MAX_SIZE)
    {
        QFile::remove("./log.txt");
    }

    delete fileInfo;
    _LOG << "log file has been deleted for its size";
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Escape)
    {
        // stop the mvb board and close the window
        this->mvbDriver->setMvbStop();
        this->close();
    }
    else if (event->key() == Qt::Key_S)
    {
        QDesktopWidget *desktop = QApplication::desktop();
        //show a window used th manipuliate the mvb ports and change page
        Simulation *simulation = new Simulation();
        simulation->move((desktop->width() - simulation->width()) / 2, (desktop->height() - simulation->height()) / 2);
        simulation->show();
    }
}

void Widget::synchronizeTimeWithCcu()
{
    if (!this->database->hmiCcuOnlineState)
    {
        return;
    }
    else if (!this->database->PUBPORT_SettingTimeEnable)
    {
        return;
    }
    else if (!QDate::isValid(2000 + this->database->PUBPORT_SysTimeYear, this->database->PUBPORT_SysTimeMonth, this->database->PUBPORT_SysTimeDay))
    {
        return;
    }
    else if (!QTime::isValid(this->database->PUBPORT_SysTimeHour, this->database->PUBPORT_SysTimeMinute, this->database->PUBPORT_SysTimeSecond))
    {
        return;
    }
    QDateTime ccuTime(QDate(2000 + this->database->PUBPORT_SysTimeYear, this->database->PUBPORT_SysTimeMonth, this->database->PUBPORT_SysTimeDay),
                      QTime(this->database->PUBPORT_SysTimeHour, this->database->PUBPORT_SysTimeMinute, this->database->PUBPORT_SysTimeSecond));

    if (abs(ccuTime.toTime_t() - QDateTime::currentDateTime().toTime_t()) > 5)
    {
        QDate date(2000 + this->database->PUBPORT_SysTimeYear, this->database->PUBPORT_SysTimeMonth, this->database->PUBPORT_SysTimeDay);
        QTime time(this->database->PUBPORT_SysTimeHour, this->database->PUBPORT_SysTimeMinute, this->database->PUBPORT_SysTimeSecond);
        QString dateString = date.toString("yyyy-MM-dd");
        QString timeString = time.toString("hh:mm:ss");
        QString command = "date -s \"";

        dateString.replace(QRegExp("-"), "");
        timeString.replace(QRegExp("-"), ",");
        command = command + dateString + " " + timeString + "\"";

        const char *c = command.toAscii().data();

        system(c);
        // write bios
        system("hwclock -w");
        _LOG << "synchronize the time  of" << dateString << timeString << "with ccu";
    }
}
