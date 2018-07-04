#-------------------------------------------------
#
# Project created by QtCreator 2016-07-08T12:58:43
#
#-------------------------------------------------

QT += core gui
QT += network
LIBS += -lPixyMvb

TARGET = JinpuLine
TEMPLATE = app

DEPENDPATH += .
INCLUDEPATH += .

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
SOURCES += main.cpp\
        widget.cpp \
    mybase.cpp \
    database.cpp \
    mvbdriver.cpp \
    network.cpp \
    myfunction.cpp \
    allports.cpp \
    header.cpp \
    navigator.cpp \
    vehiclelogo.cpp \
    debugpage.cpp \
    headerinner.cpp \
    navigatorinner.cpp \
    simulation.cpp \
    mainpage.cpp \
    runstatepage.cpp \
    setpasswordpage.cpp \
    lifesignals.cpp \
    riomdebug.cpp \
    runstatehelppage1.cpp \
    runstatehelppage2.cpp \
    runstatehelppage3.cpp \
    runstatehelppage4.cpp \
    brakestatehelppage.cpp \
    brakestatehelppage2.cpp \
    tractionhelppage.cpp \
    assistanthelppage.cpp \
    otherchannelshelppage.cpp \
    airconditionerhelppage.cpp \
    firealertpage.cpp \
    brakeselfcheckpage.cpp \
    setparameterpage.cpp \
    setdoorparameterpage.cpp \
    runningrecordpage.cpp \
    runningrecordclearpage.cpp \
    versioninfopage.cpp \
    publishsetpage.cpp \
    brakestatepage.cpp \
    tractionpage.cpp \
    assistantpage.cpp \
    otherchannelspage.cpp \
    repairpage.cpp \
    networkhelppage.cpp \
    emergencybroadcast.cpp \
    airconditionerpage.cpp \
    initializesignals.cpp \
    maintainancepage.cpp \
    wheeldiaset.cpp \
    timesetpage.cpp \
    commandpage.cpp \
    testpage.cpp \
    maintainloginpage.cpp \
    tractionhelppage2.cpp \
    batterypage.cpp \
    chargerpage.cpp \
    chargerhelppage.cpp \
    batteryhelppage.cpp \
    datamoniter.cpp \
    tractiontestpage.cpp \
    drivertestpage.cpp \
    sivtestpage.cpp \
    setvehicleno.cpp \
    initializeBCUSignals.cpp \
    speedtestpage.cpp \
    edcudefaultlist.cpp \
    initializeEDCUsignals.cpp \
    initializeERMSignals.cpp \
    runningrecordset.cpp \
    panel.cpp \
    initializePISSignals.cpp \
    initializeRIOMSignals.cpp \
    crrcfault.cpp \
    historyfault.cpp \
    currentfaultlist.cpp \
    pisdefaultlist.cpp \
    bcudefaultlist.cpp \
    tractionisolate.cpp \
    ermdefaultlist.cpp

HEADERS  += widget.h \
    global.h \
    mybase.h \
    PixyMvbLib.h \
    PixyTypes.h \
    database.h \
    mvbdriver.h \
    network.h \
    myfunction.h \
    allports.h \
    header.h \
    navigator.h \
    vehiclelogo.h \
    debugpage.h \
    headerinner.h \
    navigatorinner.h \
    simulation.h \
    mainpage.h \
    runstatepage.h \
    setpasswordpage.h \
    lifesignals.h \
    riomdebug.h \
    runstatehelppage1.h \
    runstatehelppage2.h \
    runstatehelppage3.h \
    runstatehelppage4.h \
    brakestatehelppage.h \
    brakestatehelppage2.h \
    tractionhelppage.h \
    assistanthelppage.h \
    otherchannelshelppage.h \
    airconditionerhelppage.h \
    firealertpage.h \
    brakeselfcheckpage.h \
    tractiontestpage.h \
    setparameterpage.h \
    setdoorparameterpage.h \
    runningrecordpage.h \
    runningrecordclearpage.h \
    versioninfopage.h \
    publishsetpage.h \
    brakestatepage.h \
    tractionpage.h \
    assistantpage.h \
    otherchannelspage.h \
    repairpage.h \
    networkhelppage.h \
    emergencybroadcast.h \
    airconditionerpage.h \
    maintainancepage.h \
    wheeldiaset.h \
    timesetpage.h \
    commandpage.h \
    testpage.h \
    maintainloginpage.h \
    tractionhelppage2.h \
    batterypage.h \
    chargerpage.h \
    chargerhelppage.h \
    batteryhelppage.h \
    ccusignals.h \
    datamoniter.h \
    drivertestpage.h \
    sivtestpage.h \
    setvehicleno.h \
    speedtestpage.h \
    edcudefaultlist.h \
    runningrecordset.h \
    panel.h \
    crrcfault.h \
    historyfault.h \
    currentfaultlist.h \
    pisdefaultlist.h \
    bcudefaultlist.h \
    tractionisolate.h \
    ermdefaultlist.h

FORMS    += widget.ui \
    network.ui \
    allports.ui \
    header.ui \
    navigator.ui \
    vehiclelogo.ui \
    debugpage.ui \
    headerinner.ui \
    navigatorinner.ui \
    simulation.ui \
    mainpage.ui \
    runstatepage.ui \
    setpasswordpage.ui \
    lifesignals.ui \
    riomdebug.ui \
    runstatehelppage1.ui \
    runstatehelppage2.ui \
    runstatehelppage3.ui \
    runstatehelppage4.ui \
    brakestatehelppage.ui \
    brakestatehelppage2.ui \
    tractionhelppage.ui \
    assistanthelppage.ui \
    otherchannelshelppage.ui \
    airconditionerhelppage.ui \
    firealertpage.ui \
    brakeselfcheckpage.ui \
    tractiontestpage.ui \
    setparameterpage.ui \
    setdoorparameterpage.ui \
    runningrecordpage.ui \
    runningrecordclearpage.ui \
    versioninfopage.ui \
    publishsetpage.ui \
    brakestatepage.ui \
    tractionpage.ui \
    assistantpage.ui \
    otherchannelspage.ui \
    repairpage.ui \
    networkhelppage.ui \
    emergencybroadcast.ui \
    airconditionerpage.ui \
    maintainancepage.ui \
    wheeldiaset.ui \
    commandpage.ui \
    testpage.ui \
    maintainloginpage.ui \
    tractionhelppage2.ui \
    batterypage.ui \
    chargerpage.ui \
    chargerhelppage.ui \
    batteryhelppage.ui \
    timesetpage.ui \
    datamoniter.ui \
    drivertestpage.ui \
    sivtestpage.ui \
    setvehicleno.ui \
    speedtestpage.ui \
    runningrecordset.ui \
    panel.ui \
    historyfault.ui \
    currentfaultlist.ui \
    tractionisolate.ui

RESOURCES += \
    Resources.qrc

OTHER_FILES +=
