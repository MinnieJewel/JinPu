/********************************************************************************
** Form generated from reading UI file 'runstatepage.ui'
**
** Created: Mon Jan 15 08:18:36 2018
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RUNSTATEPAGE_H
#define UI_RUNSTATEPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RunStatePage
{
public:
    QLabel *label_vehicleNo;
    QLabel *label_assistantState;
    QLabel *label_tractionState;
    QLabel *label_brakeState;
    QLabel *label_valve1;
    QLabel *label_innerTemperature;
    QLabel *label_AirPressor;
    QLabel *label_car1No;
    QLabel *label_car1AssistantState;
    QLabel *label_car1TractionState;
    QLabel *label_car1Brake1;
    QLabel *label_car1Valve1;
    QLabel *label_car1Valve2;
    QLabel *label_car1Valve5;
    QLabel *label_car1Valve6;
    QLabel *label_car1InnerTemperature;
    QLabel *label_APAbnormal1;
    QLabel *label_car2No;
    QLabel *label_car2AssistantState;
    QLabel *label_car2Brake1;
    QLabel *label_car2InnerTemperature;
    QLabel *label_car3No;
    QLabel *label_car3AssistantState;
    QLabel *label_car3Brake2;
    QLabel *label_car3InnerTemperature;
    QLabel *label_car4No;
    QLabel *label_car4AssistantState;
    QLabel *label_car4TractionState;
    QLabel *label_car4Brake1;
    QLabel *label_car4InnerTemperature;
    QLabel *label_APAbnormal4;
    QLabel *label_car2Brake2;
    QLabel *label_car3Brake1;
    QLabel *label_car4Brake2;
    QLabel *label_car1Brake2;
    QLabel *label_car4outerTemperature;
    QLabel *label_car3outerTemperature;
    QLabel *label_car1outerTemperature;
    QLabel *label_car2outerTemperature;
    QLabel *label_outerTemperature;
    QLabel *label_car1Valve8;
    QLabel *label_car1Valve3;
    QLabel *label_car1Valve7;
    QLabel *label_car1Valve4;
    QLabel *label_car2Valve4;
    QLabel *label_car2Valve7;
    QLabel *label_car2Valve8;
    QLabel *label_car2Valve1;
    QLabel *label_car2Valve5;
    QLabel *label_car2Valve6;
    QLabel *label_car2Valve3;
    QLabel *label_car2Valve2;
    QLabel *label_car3Valve4;
    QLabel *label_car3Valve7;
    QLabel *label_car3Valve5;
    QLabel *label_car3Valve2;
    QLabel *label_car3Valve6;
    QLabel *label_car3Valve8;
    QLabel *label_car3Valve3;
    QLabel *label_car3Valve1;
    QLabel *label_car4Valve1;
    QLabel *label_car4Valve3;
    QLabel *label_car4Valve8;
    QLabel *label_car4Valve4;
    QLabel *label_car4Valve5;
    QLabel *label_car4Valve2;
    QLabel *label_car4Valve6;
    QLabel *label_car4Valve7;
    QLabel *label_car3TractionSystem1;
    QLabel *label_car3TractionSystem3;
    QLabel *label_car2TractionSystem2;
    QLabel *label_car2TractionSystem4;
    QLabel *label_car2TractionSystem3;
    QLabel *label_car3TractionSystem2;
    QLabel *label_car3TractionSystem4;
    QLabel *label_car2TractionSystem1;
    QPushButton *btn_EmergencyBroadcast;
    QLabel *label_car3RidingRate;
    QLabel *label_ridingRate;
    QLabel *label_car1RidingRate;
    QLabel *label_car4RidingRate;
    QLabel *label_car2RidingRate;
    QLabel *label_APOverLoad1;
    QLabel *label_APOverLoad4;
    QLabel *label_APRun1;
    QLabel *label_APPreStart1;
    QLabel *label_APPreStart4;
    QLabel *label_APRun4;
    QLabel *label_car2RidingRate_2;
    QLabel *label_car3RidingRate_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label_22;
    QLabel *label_23;
    QLabel *label_24;
    QLabel *label_25;
    QLabel *label_26;
    QLabel *label_27;
    QLabel *label_28;
    QLabel *label_29;
    QLabel *label_30;
    QLabel *label_31;
    QLabel *label_32;
    QLabel *label_car2Brake2_2;
    QLabel *label_car3Brake1_2;
    QLabel *label_car1Brake2_2;
    QLabel *label_car1Brake1_2;
    QLabel *label_car4Brake2_2;
    QLabel *label_car3Brake2_2;
    QLabel *label_car2Brake1_2;
    QLabel *label_car4Brake1_2;

    void setupUi(QWidget *RunStatePage)
    {
        if (RunStatePage->objectName().isEmpty())
            RunStatePage->setObjectName(QString::fromUtf8("RunStatePage"));
        RunStatePage->resize(1024, 618);
        RunStatePage->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	color: white;\n"
"	border: 2px groove, gray;\n"
"    border-color: gray;\n"
"	font: 20px, \"SimHei\";	\n"
"}\n"
"\n"
"QWidget\n"
"{\n"
"	background-color: black;\n"
"}\n"
"\n"
"QPushButton\n"
"{\n"
"	font: 20px, \"SimHei\";\n"
"    color: black;\n"
"	background-color: rgb(250, 250, 250);\n"
"	border-radius: 5px;\n"
"}"));
        label_vehicleNo = new QLabel(RunStatePage);
        label_vehicleNo->setObjectName(QString::fromUtf8("label_vehicleNo"));
        label_vehicleNo->setGeometry(QRect(20, 102, 157, 40));
        label_assistantState = new QLabel(RunStatePage);
        label_assistantState->setObjectName(QString::fromUtf8("label_assistantState"));
        label_assistantState->setGeometry(QRect(20, 141, 157, 40));
        label_tractionState = new QLabel(RunStatePage);
        label_tractionState->setObjectName(QString::fromUtf8("label_tractionState"));
        label_tractionState->setGeometry(QRect(20, 180, 157, 40));
        label_brakeState = new QLabel(RunStatePage);
        label_brakeState->setObjectName(QString::fromUtf8("label_brakeState"));
        label_brakeState->setGeometry(QRect(20, 219, 157, 60));
        label_valve1 = new QLabel(RunStatePage);
        label_valve1->setObjectName(QString::fromUtf8("label_valve1"));
        label_valve1->setGeometry(QRect(20, 278, 157, 104));
        label_innerTemperature = new QLabel(RunStatePage);
        label_innerTemperature->setObjectName(QString::fromUtf8("label_innerTemperature"));
        label_innerTemperature->setGeometry(QRect(20, 382, 157, 35));
        label_AirPressor = new QLabel(RunStatePage);
        label_AirPressor->setObjectName(QString::fromUtf8("label_AirPressor"));
        label_AirPressor->setGeometry(QRect(20, 450, 157, 70));
        label_car1No = new QLabel(RunStatePage);
        label_car1No->setObjectName(QString::fromUtf8("label_car1No"));
        label_car1No->setGeometry(QRect(176, 102, 190, 40));
        label_car1No->setScaledContents(false);
        label_car1No->setAlignment(Qt::AlignCenter);
        label_car1AssistantState = new QLabel(RunStatePage);
        label_car1AssistantState->setObjectName(QString::fromUtf8("label_car1AssistantState"));
        label_car1AssistantState->setGeometry(QRect(176, 141, 190, 40));
        label_car1AssistantState->setAlignment(Qt::AlignCenter);
        label_car1TractionState = new QLabel(RunStatePage);
        label_car1TractionState->setObjectName(QString::fromUtf8("label_car1TractionState"));
        label_car1TractionState->setGeometry(QRect(176, 180, 190, 40));
        label_car1TractionState->setAlignment(Qt::AlignCenter);
        label_car1Brake1 = new QLabel(RunStatePage);
        label_car1Brake1->setObjectName(QString::fromUtf8("label_car1Brake1"));
        label_car1Brake1->setGeometry(QRect(176, 244, 95, 35));
        label_car1Brake1->setStyleSheet(QString::fromUtf8("	color: white;\n"
"	border: 2px groove, gray;\n"
"    border-color: gray;\n"
"	font: 15px, \"SimHei\";	"));
        label_car1Brake1->setAlignment(Qt::AlignCenter);
        label_car1Valve1 = new QLabel(RunStatePage);
        label_car1Valve1->setObjectName(QString::fromUtf8("label_car1Valve1"));
        label_car1Valve1->setGeometry(QRect(176, 279, 47, 52));
        label_car1Valve1->setStyleSheet(QString::fromUtf8("font: 75 25px, \"SimHei\";	"));
        label_car1Valve1->setAlignment(Qt::AlignCenter);
        label_car1Valve2 = new QLabel(RunStatePage);
        label_car1Valve2->setObjectName(QString::fromUtf8("label_car1Valve2"));
        label_car1Valve2->setGeometry(QRect(176, 330, 47, 52));
        label_car1Valve2->setStyleSheet(QString::fromUtf8("font: 75 25px, \"SimHei\";	"));
        label_car1Valve2->setAlignment(Qt::AlignCenter);
        label_car1Valve5 = new QLabel(RunStatePage);
        label_car1Valve5->setObjectName(QString::fromUtf8("label_car1Valve5"));
        label_car1Valve5->setGeometry(QRect(270, 279, 47, 52));
        label_car1Valve5->setStyleSheet(QString::fromUtf8("font: 75 25px, \"SimHei\";	"));
        label_car1Valve5->setAlignment(Qt::AlignCenter);
        label_car1Valve6 = new QLabel(RunStatePage);
        label_car1Valve6->setObjectName(QString::fromUtf8("label_car1Valve6"));
        label_car1Valve6->setGeometry(QRect(270, 330, 47, 52));
        label_car1Valve6->setStyleSheet(QString::fromUtf8("font: 75 25px, \"SimHei\";	"));
        label_car1Valve6->setAlignment(Qt::AlignCenter);
        label_car1InnerTemperature = new QLabel(RunStatePage);
        label_car1InnerTemperature->setObjectName(QString::fromUtf8("label_car1InnerTemperature"));
        label_car1InnerTemperature->setGeometry(QRect(176, 382, 190, 35));
        label_car1InnerTemperature->setAlignment(Qt::AlignCenter);
        label_APAbnormal1 = new QLabel(RunStatePage);
        label_APAbnormal1->setObjectName(QString::fromUtf8("label_APAbnormal1"));
        label_APAbnormal1->setGeometry(QRect(176, 450, 95, 35));
        label_car2No = new QLabel(RunStatePage);
        label_car2No->setObjectName(QString::fromUtf8("label_car2No"));
        label_car2No->setGeometry(QRect(364, 102, 210, 40));
        label_car2No->setAlignment(Qt::AlignCenter);
        label_car2AssistantState = new QLabel(RunStatePage);
        label_car2AssistantState->setObjectName(QString::fromUtf8("label_car2AssistantState"));
        label_car2AssistantState->setGeometry(QRect(364, 141, 210, 40));
        label_car2AssistantState->setAlignment(Qt::AlignCenter);
        label_car2Brake1 = new QLabel(RunStatePage);
        label_car2Brake1->setObjectName(QString::fromUtf8("label_car2Brake1"));
        label_car2Brake1->setGeometry(QRect(364, 244, 105, 35));
        label_car2Brake1->setStyleSheet(QString::fromUtf8("	color: white;\n"
"	border: 2px groove, gray;\n"
"    border-color: gray;\n"
"	font: 12px, \"SimHei\";	"));
        label_car2Brake1->setAlignment(Qt::AlignCenter);
        label_car2InnerTemperature = new QLabel(RunStatePage);
        label_car2InnerTemperature->setObjectName(QString::fromUtf8("label_car2InnerTemperature"));
        label_car2InnerTemperature->setGeometry(QRect(364, 382, 210, 35));
        label_car2InnerTemperature->setAlignment(Qt::AlignCenter);
        label_car3No = new QLabel(RunStatePage);
        label_car3No->setObjectName(QString::fromUtf8("label_car3No"));
        label_car3No->setGeometry(QRect(573, 102, 210, 40));
        label_car3No->setAlignment(Qt::AlignCenter);
        label_car3AssistantState = new QLabel(RunStatePage);
        label_car3AssistantState->setObjectName(QString::fromUtf8("label_car3AssistantState"));
        label_car3AssistantState->setGeometry(QRect(573, 141, 210, 40));
        label_car3AssistantState->setAlignment(Qt::AlignCenter);
        label_car3Brake2 = new QLabel(RunStatePage);
        label_car3Brake2->setObjectName(QString::fromUtf8("label_car3Brake2"));
        label_car3Brake2->setGeometry(QRect(573, 244, 105, 35));
        label_car3Brake2->setStyleSheet(QString::fromUtf8("	color: white;\n"
"	border: 2px groove, gray;\n"
"    border-color: gray;\n"
"	font: 12px, \"SimHei\";	"));
        label_car3Brake2->setAlignment(Qt::AlignCenter);
        label_car3InnerTemperature = new QLabel(RunStatePage);
        label_car3InnerTemperature->setObjectName(QString::fromUtf8("label_car3InnerTemperature"));
        label_car3InnerTemperature->setGeometry(QRect(573, 382, 210, 35));
        label_car3InnerTemperature->setStyleSheet(QString::fromUtf8(""));
        label_car3InnerTemperature->setAlignment(Qt::AlignCenter);
        label_car4No = new QLabel(RunStatePage);
        label_car4No->setObjectName(QString::fromUtf8("label_car4No"));
        label_car4No->setGeometry(QRect(781, 102, 180, 40));
        label_car4No->setAlignment(Qt::AlignCenter);
        label_car4AssistantState = new QLabel(RunStatePage);
        label_car4AssistantState->setObjectName(QString::fromUtf8("label_car4AssistantState"));
        label_car4AssistantState->setGeometry(QRect(781, 141, 180, 40));
        label_car4AssistantState->setAlignment(Qt::AlignCenter);
        label_car4TractionState = new QLabel(RunStatePage);
        label_car4TractionState->setObjectName(QString::fromUtf8("label_car4TractionState"));
        label_car4TractionState->setGeometry(QRect(781, 180, 180, 40));
        label_car4TractionState->setAlignment(Qt::AlignCenter);
        label_car4Brake1 = new QLabel(RunStatePage);
        label_car4Brake1->setObjectName(QString::fromUtf8("label_car4Brake1"));
        label_car4Brake1->setGeometry(QRect(871, 244, 90, 35));
        label_car4Brake1->setStyleSheet(QString::fromUtf8("	color: white;\n"
"	border: 2px groove, gray;\n"
"    border-color: gray;\n"
"	font: 12px, \"SimHei\";	"));
        label_car4Brake1->setAlignment(Qt::AlignCenter);
        label_car4InnerTemperature = new QLabel(RunStatePage);
        label_car4InnerTemperature->setObjectName(QString::fromUtf8("label_car4InnerTemperature"));
        label_car4InnerTemperature->setGeometry(QRect(781, 382, 180, 35));
        label_car4InnerTemperature->setStyleSheet(QString::fromUtf8(""));
        label_car4InnerTemperature->setAlignment(Qt::AlignCenter);
        label_APAbnormal4 = new QLabel(RunStatePage);
        label_APAbnormal4->setObjectName(QString::fromUtf8("label_APAbnormal4"));
        label_APAbnormal4->setGeometry(QRect(781, 450, 90, 35));
        label_car2Brake2 = new QLabel(RunStatePage);
        label_car2Brake2->setObjectName(QString::fromUtf8("label_car2Brake2"));
        label_car2Brake2->setGeometry(QRect(469, 244, 105, 35));
        label_car2Brake2->setStyleSheet(QString::fromUtf8("	color: white;\n"
"	border: 2px groove, gray;\n"
"    border-color: gray;\n"
"	font: 12px, \"SimHei\";	"));
        label_car2Brake2->setAlignment(Qt::AlignCenter);
        label_car3Brake1 = new QLabel(RunStatePage);
        label_car3Brake1->setObjectName(QString::fromUtf8("label_car3Brake1"));
        label_car3Brake1->setGeometry(QRect(677, 244, 105, 35));
        label_car3Brake1->setStyleSheet(QString::fromUtf8("	color: white;\n"
"	border: 2px groove, gray;\n"
"    border-color: gray;\n"
"	font: 12px, \"SimHei\";	"));
        label_car3Brake1->setAlignment(Qt::AlignCenter);
        label_car4Brake2 = new QLabel(RunStatePage);
        label_car4Brake2->setObjectName(QString::fromUtf8("label_car4Brake2"));
        label_car4Brake2->setGeometry(QRect(781, 244, 90, 35));
        label_car4Brake2->setStyleSheet(QString::fromUtf8("	color: white;\n"
"	border: 2px groove, gray;\n"
"    border-color: gray;\n"
"	font: 12px, \"SimHei\";	"));
        label_car4Brake2->setAlignment(Qt::AlignCenter);
        label_car1Brake2 = new QLabel(RunStatePage);
        label_car1Brake2->setObjectName(QString::fromUtf8("label_car1Brake2"));
        label_car1Brake2->setGeometry(QRect(270, 244, 96, 35));
        label_car1Brake2->setStyleSheet(QString::fromUtf8("	color: white;\n"
"	border: 2px groove, gray;\n"
"    border-color: gray;\n"
"	font: 12px, \"SimHei\";	"));
        label_car1Brake2->setAlignment(Qt::AlignCenter);
        label_car4outerTemperature = new QLabel(RunStatePage);
        label_car4outerTemperature->setObjectName(QString::fromUtf8("label_car4outerTemperature"));
        label_car4outerTemperature->setGeometry(QRect(781, 416, 180, 35));
        label_car4outerTemperature->setStyleSheet(QString::fromUtf8(""));
        label_car4outerTemperature->setAlignment(Qt::AlignCenter);
        label_car3outerTemperature = new QLabel(RunStatePage);
        label_car3outerTemperature->setObjectName(QString::fromUtf8("label_car3outerTemperature"));
        label_car3outerTemperature->setGeometry(QRect(573, 416, 210, 35));
        label_car3outerTemperature->setStyleSheet(QString::fromUtf8(""));
        label_car3outerTemperature->setAlignment(Qt::AlignCenter);
        label_car1outerTemperature = new QLabel(RunStatePage);
        label_car1outerTemperature->setObjectName(QString::fromUtf8("label_car1outerTemperature"));
        label_car1outerTemperature->setGeometry(QRect(176, 416, 190, 35));
        label_car1outerTemperature->setAlignment(Qt::AlignCenter);
        label_car2outerTemperature = new QLabel(RunStatePage);
        label_car2outerTemperature->setObjectName(QString::fromUtf8("label_car2outerTemperature"));
        label_car2outerTemperature->setGeometry(QRect(364, 416, 210, 35));
        label_car2outerTemperature->setAlignment(Qt::AlignCenter);
        label_outerTemperature = new QLabel(RunStatePage);
        label_outerTemperature->setObjectName(QString::fromUtf8("label_outerTemperature"));
        label_outerTemperature->setGeometry(QRect(20, 416, 157, 35));
        label_car1Valve8 = new QLabel(RunStatePage);
        label_car1Valve8->setObjectName(QString::fromUtf8("label_car1Valve8"));
        label_car1Valve8->setGeometry(QRect(317, 330, 48, 52));
        label_car1Valve8->setStyleSheet(QString::fromUtf8("font: 75 25px, \"SimHei\";	"));
        label_car1Valve8->setAlignment(Qt::AlignCenter);
        label_car1Valve3 = new QLabel(RunStatePage);
        label_car1Valve3->setObjectName(QString::fromUtf8("label_car1Valve3"));
        label_car1Valve3->setGeometry(QRect(222, 279, 48, 52));
        label_car1Valve3->setStyleSheet(QString::fromUtf8("font: 75 25px, \"SimHei\";	"));
        label_car1Valve3->setAlignment(Qt::AlignCenter);
        label_car1Valve7 = new QLabel(RunStatePage);
        label_car1Valve7->setObjectName(QString::fromUtf8("label_car1Valve7"));
        label_car1Valve7->setGeometry(QRect(317, 279, 48, 52));
        label_car1Valve7->setStyleSheet(QString::fromUtf8("font: 75 25px, \"SimHei\";	"));
        label_car1Valve7->setAlignment(Qt::AlignCenter);
        label_car1Valve4 = new QLabel(RunStatePage);
        label_car1Valve4->setObjectName(QString::fromUtf8("label_car1Valve4"));
        label_car1Valve4->setGeometry(QRect(222, 330, 48, 52));
        label_car1Valve4->setStyleSheet(QString::fromUtf8("font: 75 25px, \"SimHei\";	"));
        label_car1Valve4->setAlignment(Qt::AlignCenter);
        label_car2Valve4 = new QLabel(RunStatePage);
        label_car2Valve4->setObjectName(QString::fromUtf8("label_car2Valve4"));
        label_car2Valve4->setGeometry(QRect(417, 330, 52, 52));
        label_car2Valve4->setStyleSheet(QString::fromUtf8("font: 75 25px, \"SimHei\";	"));
        label_car2Valve4->setAlignment(Qt::AlignCenter);
        label_car2Valve7 = new QLabel(RunStatePage);
        label_car2Valve7->setObjectName(QString::fromUtf8("label_car2Valve7"));
        label_car2Valve7->setGeometry(QRect(522, 279, 52, 52));
        label_car2Valve7->setStyleSheet(QString::fromUtf8("font: 75 25px, \"SimHei\";	"));
        label_car2Valve7->setAlignment(Qt::AlignCenter);
        label_car2Valve8 = new QLabel(RunStatePage);
        label_car2Valve8->setObjectName(QString::fromUtf8("label_car2Valve8"));
        label_car2Valve8->setGeometry(QRect(522, 330, 52, 52));
        label_car2Valve8->setStyleSheet(QString::fromUtf8("font: 75 25px, \"SimHei\";	"));
        label_car2Valve8->setAlignment(Qt::AlignCenter);
        label_car2Valve1 = new QLabel(RunStatePage);
        label_car2Valve1->setObjectName(QString::fromUtf8("label_car2Valve1"));
        label_car2Valve1->setGeometry(QRect(364, 279, 53, 52));
        label_car2Valve1->setStyleSheet(QString::fromUtf8("font: 75 25px, \"SimHei\";	"));
        label_car2Valve1->setAlignment(Qt::AlignCenter);
        label_car2Valve5 = new QLabel(RunStatePage);
        label_car2Valve5->setObjectName(QString::fromUtf8("label_car2Valve5"));
        label_car2Valve5->setGeometry(QRect(469, 279, 53, 52));
        label_car2Valve5->setStyleSheet(QString::fromUtf8("font: 75 25px, \"SimHei\";	"));
        label_car2Valve5->setAlignment(Qt::AlignCenter);
        label_car2Valve6 = new QLabel(RunStatePage);
        label_car2Valve6->setObjectName(QString::fromUtf8("label_car2Valve6"));
        label_car2Valve6->setGeometry(QRect(469, 330, 53, 52));
        label_car2Valve6->setStyleSheet(QString::fromUtf8("font: 75 25px, \"SimHei\";	"));
        label_car2Valve6->setAlignment(Qt::AlignCenter);
        label_car2Valve3 = new QLabel(RunStatePage);
        label_car2Valve3->setObjectName(QString::fromUtf8("label_car2Valve3"));
        label_car2Valve3->setGeometry(QRect(417, 279, 52, 52));
        label_car2Valve3->setStyleSheet(QString::fromUtf8("font: 75 25px, \"SimHei\";	"));
        label_car2Valve3->setAlignment(Qt::AlignCenter);
        label_car2Valve2 = new QLabel(RunStatePage);
        label_car2Valve2->setObjectName(QString::fromUtf8("label_car2Valve2"));
        label_car2Valve2->setGeometry(QRect(364, 330, 53, 52));
        label_car2Valve2->setStyleSheet(QString::fromUtf8("font: 75 25px, \"SimHei\";	"));
        label_car2Valve2->setAlignment(Qt::AlignCenter);
        label_car3Valve4 = new QLabel(RunStatePage);
        label_car3Valve4->setObjectName(QString::fromUtf8("label_car3Valve4"));
        label_car3Valve4->setGeometry(QRect(677, 279, 53, 52));
        label_car3Valve4->setStyleSheet(QString::fromUtf8("font: 75 25px, \"SimHei\";	"));
        label_car3Valve4->setAlignment(Qt::AlignCenter);
        label_car3Valve7 = new QLabel(RunStatePage);
        label_car3Valve7->setObjectName(QString::fromUtf8("label_car3Valve7"));
        label_car3Valve7->setGeometry(QRect(573, 330, 53, 52));
        label_car3Valve7->setStyleSheet(QString::fromUtf8("font: 75 25px, \"SimHei\";	"));
        label_car3Valve7->setAlignment(Qt::AlignCenter);
        label_car3Valve5 = new QLabel(RunStatePage);
        label_car3Valve5->setObjectName(QString::fromUtf8("label_car3Valve5"));
        label_car3Valve5->setGeometry(QRect(626, 330, 52, 52));
        label_car3Valve5->setStyleSheet(QString::fromUtf8("font: 75 25px, \"SimHei\";	"));
        label_car3Valve5->setAlignment(Qt::AlignCenter);
        label_car3Valve2 = new QLabel(RunStatePage);
        label_car3Valve2->setObjectName(QString::fromUtf8("label_car3Valve2"));
        label_car3Valve2->setGeometry(QRect(730, 279, 52, 52));
        label_car3Valve2->setStyleSheet(QString::fromUtf8("font: 75 25px, \"SimHei\";	"));
        label_car3Valve2->setAlignment(Qt::AlignCenter);
        label_car3Valve6 = new QLabel(RunStatePage);
        label_car3Valve6->setObjectName(QString::fromUtf8("label_car3Valve6"));
        label_car3Valve6->setGeometry(QRect(626, 279, 52, 52));
        label_car3Valve6->setStyleSheet(QString::fromUtf8("font: 75 25px, \"SimHei\";	"));
        label_car3Valve6->setAlignment(Qt::AlignCenter);
        label_car3Valve8 = new QLabel(RunStatePage);
        label_car3Valve8->setObjectName(QString::fromUtf8("label_car3Valve8"));
        label_car3Valve8->setGeometry(QRect(573, 279, 53, 52));
        label_car3Valve8->setStyleSheet(QString::fromUtf8("font: 75 25px, \"SimHei\";	"));
        label_car3Valve8->setAlignment(Qt::AlignCenter);
        label_car3Valve3 = new QLabel(RunStatePage);
        label_car3Valve3->setObjectName(QString::fromUtf8("label_car3Valve3"));
        label_car3Valve3->setGeometry(QRect(677, 330, 53, 52));
        label_car3Valve3->setStyleSheet(QString::fromUtf8("font: 75 25px, \"SimHei\";	"));
        label_car3Valve3->setAlignment(Qt::AlignCenter);
        label_car3Valve1 = new QLabel(RunStatePage);
        label_car3Valve1->setObjectName(QString::fromUtf8("label_car3Valve1"));
        label_car3Valve1->setGeometry(QRect(730, 330, 52, 52));
        label_car3Valve1->setStyleSheet(QString::fromUtf8("font: 75 25px, \"SimHei\";	"));
        label_car3Valve1->setAlignment(Qt::AlignCenter);
        label_car4Valve1 = new QLabel(RunStatePage);
        label_car4Valve1->setObjectName(QString::fromUtf8("label_car4Valve1"));
        label_car4Valve1->setGeometry(QRect(916, 330, 45, 52));
        label_car4Valve1->setStyleSheet(QString::fromUtf8("font: 75 25px, \"SimHei\";	"));
        label_car4Valve1->setAlignment(Qt::AlignCenter);
        label_car4Valve3 = new QLabel(RunStatePage);
        label_car4Valve3->setObjectName(QString::fromUtf8("label_car4Valve3"));
        label_car4Valve3->setGeometry(QRect(871, 330, 45, 52));
        label_car4Valve3->setStyleSheet(QString::fromUtf8("font: 75 25px, \"SimHei\";	"));
        label_car4Valve3->setAlignment(Qt::AlignCenter);
        label_car4Valve8 = new QLabel(RunStatePage);
        label_car4Valve8->setObjectName(QString::fromUtf8("label_car4Valve8"));
        label_car4Valve8->setGeometry(QRect(781, 279, 45, 52));
        label_car4Valve8->setStyleSheet(QString::fromUtf8("font: 75 25px, \"SimHei\";	"));
        label_car4Valve8->setAlignment(Qt::AlignCenter);
        label_car4Valve4 = new QLabel(RunStatePage);
        label_car4Valve4->setObjectName(QString::fromUtf8("label_car4Valve4"));
        label_car4Valve4->setGeometry(QRect(871, 279, 45, 52));
        label_car4Valve4->setStyleSheet(QString::fromUtf8("font: 75 25px, \"SimHei\";	"));
        label_car4Valve4->setAlignment(Qt::AlignCenter);
        label_car4Valve5 = new QLabel(RunStatePage);
        label_car4Valve5->setObjectName(QString::fromUtf8("label_car4Valve5"));
        label_car4Valve5->setGeometry(QRect(826, 330, 45, 52));
        label_car4Valve5->setStyleSheet(QString::fromUtf8("font: 75 25px, \"SimHei\";	"));
        label_car4Valve5->setAlignment(Qt::AlignCenter);
        label_car4Valve2 = new QLabel(RunStatePage);
        label_car4Valve2->setObjectName(QString::fromUtf8("label_car4Valve2"));
        label_car4Valve2->setGeometry(QRect(916, 279, 45, 52));
        label_car4Valve2->setStyleSheet(QString::fromUtf8("font: 75 25px, \"SimHei\";	"));
        label_car4Valve2->setAlignment(Qt::AlignCenter);
        label_car4Valve6 = new QLabel(RunStatePage);
        label_car4Valve6->setObjectName(QString::fromUtf8("label_car4Valve6"));
        label_car4Valve6->setGeometry(QRect(826, 279, 45, 52));
        label_car4Valve6->setStyleSheet(QString::fromUtf8("font: 75 25px, \"SimHei\";	"));
        label_car4Valve6->setAlignment(Qt::AlignCenter);
        label_car4Valve7 = new QLabel(RunStatePage);
        label_car4Valve7->setObjectName(QString::fromUtf8("label_car4Valve7"));
        label_car4Valve7->setGeometry(QRect(781, 330, 45, 52));
        label_car4Valve7->setStyleSheet(QString::fromUtf8("font: 75 25px, \"SimHei\";	"));
        label_car4Valve7->setAlignment(Qt::AlignCenter);
        label_car3TractionSystem1 = new QLabel(RunStatePage);
        label_car3TractionSystem1->setObjectName(QString::fromUtf8("label_car3TractionSystem1"));
        label_car3TractionSystem1->setGeometry(QRect(729, 180, 53, 40));
        label_car3TractionSystem1->setAlignment(Qt::AlignCenter);
        label_car3TractionSystem3 = new QLabel(RunStatePage);
        label_car3TractionSystem3->setObjectName(QString::fromUtf8("label_car3TractionSystem3"));
        label_car3TractionSystem3->setGeometry(QRect(625, 180, 52, 40));
        label_car3TractionSystem3->setAlignment(Qt::AlignCenter);
        label_car2TractionSystem2 = new QLabel(RunStatePage);
        label_car2TractionSystem2->setObjectName(QString::fromUtf8("label_car2TractionSystem2"));
        label_car2TractionSystem2->setGeometry(QRect(416, 180, 53, 40));
        label_car2TractionSystem2->setAlignment(Qt::AlignCenter);
        label_car2TractionSystem4 = new QLabel(RunStatePage);
        label_car2TractionSystem4->setObjectName(QString::fromUtf8("label_car2TractionSystem4"));
        label_car2TractionSystem4->setGeometry(QRect(520, 180, 53, 40));
        label_car2TractionSystem4->setAlignment(Qt::AlignCenter);
        label_car2TractionSystem3 = new QLabel(RunStatePage);
        label_car2TractionSystem3->setObjectName(QString::fromUtf8("label_car2TractionSystem3"));
        label_car2TractionSystem3->setGeometry(QRect(469, 180, 51, 40));
        label_car2TractionSystem3->setAlignment(Qt::AlignCenter);
        label_car3TractionSystem2 = new QLabel(RunStatePage);
        label_car3TractionSystem2->setObjectName(QString::fromUtf8("label_car3TractionSystem2"));
        label_car3TractionSystem2->setGeometry(QRect(677, 180, 52, 40));
        label_car3TractionSystem2->setAlignment(Qt::AlignCenter);
        label_car3TractionSystem4 = new QLabel(RunStatePage);
        label_car3TractionSystem4->setObjectName(QString::fromUtf8("label_car3TractionSystem4"));
        label_car3TractionSystem4->setGeometry(QRect(573, 180, 52, 40));
        label_car3TractionSystem4->setAlignment(Qt::AlignCenter);
        label_car2TractionSystem1 = new QLabel(RunStatePage);
        label_car2TractionSystem1->setObjectName(QString::fromUtf8("label_car2TractionSystem1"));
        label_car2TractionSystem1->setGeometry(QRect(364, 180, 52, 40));
        label_car2TractionSystem1->setAlignment(Qt::AlignCenter);
        btn_EmergencyBroadcast = new QPushButton(RunStatePage);
        btn_EmergencyBroadcast->setObjectName(QString::fromUtf8("btn_EmergencyBroadcast"));
        btn_EmergencyBroadcast->setGeometry(QRect(860, 570, 130, 40));
        label_car3RidingRate = new QLabel(RunStatePage);
        label_car3RidingRate->setObjectName(QString::fromUtf8("label_car3RidingRate"));
        label_car3RidingRate->setGeometry(QRect(573, 520, 210, 35));
        label_ridingRate = new QLabel(RunStatePage);
        label_ridingRate->setObjectName(QString::fromUtf8("label_ridingRate"));
        label_ridingRate->setGeometry(QRect(20, 520, 157, 35));
        label_car1RidingRate = new QLabel(RunStatePage);
        label_car1RidingRate->setObjectName(QString::fromUtf8("label_car1RidingRate"));
        label_car1RidingRate->setGeometry(QRect(176, 520, 190, 35));
        label_car4RidingRate = new QLabel(RunStatePage);
        label_car4RidingRate->setObjectName(QString::fromUtf8("label_car4RidingRate"));
        label_car4RidingRate->setGeometry(QRect(781, 520, 180, 35));
        label_car2RidingRate = new QLabel(RunStatePage);
        label_car2RidingRate->setObjectName(QString::fromUtf8("label_car2RidingRate"));
        label_car2RidingRate->setGeometry(QRect(364, 520, 210, 35));
        label_APOverLoad1 = new QLabel(RunStatePage);
        label_APOverLoad1->setObjectName(QString::fromUtf8("label_APOverLoad1"));
        label_APOverLoad1->setGeometry(QRect(176, 485, 95, 35));
        label_APOverLoad4 = new QLabel(RunStatePage);
        label_APOverLoad4->setObjectName(QString::fromUtf8("label_APOverLoad4"));
        label_APOverLoad4->setGeometry(QRect(781, 485, 90, 35));
        label_APRun1 = new QLabel(RunStatePage);
        label_APRun1->setObjectName(QString::fromUtf8("label_APRun1"));
        label_APRun1->setGeometry(QRect(270, 485, 95, 35));
        label_APPreStart1 = new QLabel(RunStatePage);
        label_APPreStart1->setObjectName(QString::fromUtf8("label_APPreStart1"));
        label_APPreStart1->setGeometry(QRect(270, 450, 95, 35));
        label_APPreStart4 = new QLabel(RunStatePage);
        label_APPreStart4->setObjectName(QString::fromUtf8("label_APPreStart4"));
        label_APPreStart4->setGeometry(QRect(871, 450, 90, 35));
        label_APRun4 = new QLabel(RunStatePage);
        label_APRun4->setObjectName(QString::fromUtf8("label_APRun4"));
        label_APRun4->setGeometry(QRect(871, 485, 90, 35));
        label_car2RidingRate_2 = new QLabel(RunStatePage);
        label_car2RidingRate_2->setObjectName(QString::fromUtf8("label_car2RidingRate_2"));
        label_car2RidingRate_2->setGeometry(QRect(364, 450, 210, 70));
        label_car2RidingRate_2->setAlignment(Qt::AlignCenter);
        label_car3RidingRate_2 = new QLabel(RunStatePage);
        label_car3RidingRate_2->setObjectName(QString::fromUtf8("label_car3RidingRate_2"));
        label_car3RidingRate_2->setGeometry(QRect(573, 450, 210, 70));
        label_car3RidingRate_2->setAlignment(Qt::AlignCenter);
        label = new QLabel(RunStatePage);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(190, 295, 20, 20));
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(RunStatePage);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(190, 345, 20, 20));
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(RunStatePage);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(235, 295, 20, 20));
        label_3->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(RunStatePage);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(235, 345, 20, 20));
        label_4->setAlignment(Qt::AlignCenter);
        label_5 = new QLabel(RunStatePage);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(284, 295, 20, 20));
        label_5->setAlignment(Qt::AlignCenter);
        label_6 = new QLabel(RunStatePage);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(284, 345, 20, 20));
        label_6->setAlignment(Qt::AlignCenter);
        label_7 = new QLabel(RunStatePage);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(331, 295, 20, 20));
        label_7->setAlignment(Qt::AlignCenter);
        label_8 = new QLabel(RunStatePage);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(331, 345, 20, 20));
        label_8->setAlignment(Qt::AlignCenter);
        label_9 = new QLabel(RunStatePage);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(538, 345, 20, 20));
        label_9->setAlignment(Qt::AlignCenter);
        label_10 = new QLabel(RunStatePage);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(380, 345, 20, 20));
        label_10->setAlignment(Qt::AlignCenter);
        label_11 = new QLabel(RunStatePage);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(538, 295, 20, 20));
        label_11->setAlignment(Qt::AlignCenter);
        label_12 = new QLabel(RunStatePage);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(485, 345, 20, 20));
        label_12->setAlignment(Qt::AlignCenter);
        label_13 = new QLabel(RunStatePage);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(433, 345, 20, 20));
        label_13->setAlignment(Qt::AlignCenter);
        label_14 = new QLabel(RunStatePage);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(433, 295, 20, 20));
        label_14->setAlignment(Qt::AlignCenter);
        label_15 = new QLabel(RunStatePage);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(485, 295, 20, 20));
        label_15->setAlignment(Qt::AlignCenter);
        label_16 = new QLabel(RunStatePage);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(590, 295, 20, 20));
        label_16->setAlignment(Qt::AlignCenter);
        label_17 = new QLabel(RunStatePage);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(746, 295, 20, 20));
        label_17->setAlignment(Qt::AlignCenter);
        label_18 = new QLabel(RunStatePage);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(590, 345, 20, 20));
        label_18->setAlignment(Qt::AlignCenter);
        label_19 = new QLabel(RunStatePage);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(643, 295, 20, 20));
        label_19->setAlignment(Qt::AlignCenter);
        label_20 = new QLabel(RunStatePage);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(693, 295, 20, 20));
        label_20->setAlignment(Qt::AlignCenter);
        label_21 = new QLabel(RunStatePage);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(693, 345, 20, 20));
        label_21->setAlignment(Qt::AlignCenter);
        label_22 = new QLabel(RunStatePage);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(643, 345, 20, 20));
        label_22->setAlignment(Qt::AlignCenter);
        label_23 = new QLabel(RunStatePage);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(793, 295, 20, 20));
        label_23->setAlignment(Qt::AlignCenter);
        label_24 = new QLabel(RunStatePage);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(928, 295, 20, 20));
        label_24->setAlignment(Qt::AlignCenter);
        label_25 = new QLabel(RunStatePage);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(793, 345, 20, 20));
        label_25->setAlignment(Qt::AlignCenter);
        label_26 = new QLabel(RunStatePage);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(838, 295, 20, 20));
        label_26->setAlignment(Qt::AlignCenter);
        label_27 = new QLabel(RunStatePage);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setGeometry(QRect(883, 295, 20, 20));
        label_27->setAlignment(Qt::AlignCenter);
        label_28 = new QLabel(RunStatePage);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setGeometry(QRect(883, 345, 20, 20));
        label_28->setAlignment(Qt::AlignCenter);
        label_29 = new QLabel(RunStatePage);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setGeometry(QRect(838, 345, 20, 20));
        label_29->setAlignment(Qt::AlignCenter);
        label_30 = new QLabel(RunStatePage);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setGeometry(QRect(380, 295, 20, 20));
        label_30->setAlignment(Qt::AlignCenter);
        label_31 = new QLabel(RunStatePage);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setGeometry(QRect(746, 345, 20, 20));
        label_31->setAlignment(Qt::AlignCenter);
        label_32 = new QLabel(RunStatePage);
        label_32->setObjectName(QString::fromUtf8("label_32"));
        label_32->setGeometry(QRect(928, 345, 20, 20));
        label_32->setAlignment(Qt::AlignCenter);
        label_car2Brake2_2 = new QLabel(RunStatePage);
        label_car2Brake2_2->setObjectName(QString::fromUtf8("label_car2Brake2_2"));
        label_car2Brake2_2->setGeometry(QRect(469, 219, 105, 25));
        label_car2Brake2_2->setStyleSheet(QString::fromUtf8("	color: white;\n"
"	border: 2px groove, gray;\n"
"    border-color: gray;\n"
"	font: 12px, \"SimHei\";	"));
        label_car2Brake2_2->setAlignment(Qt::AlignCenter);
        label_car3Brake1_2 = new QLabel(RunStatePage);
        label_car3Brake1_2->setObjectName(QString::fromUtf8("label_car3Brake1_2"));
        label_car3Brake1_2->setGeometry(QRect(677, 219, 105, 25));
        label_car3Brake1_2->setStyleSheet(QString::fromUtf8("	color: white;\n"
"	border: 2px groove, gray;\n"
"    border-color: gray;\n"
"	font: 12px, \"SimHei\";	"));
        label_car3Brake1_2->setAlignment(Qt::AlignCenter);
        label_car1Brake2_2 = new QLabel(RunStatePage);
        label_car1Brake2_2->setObjectName(QString::fromUtf8("label_car1Brake2_2"));
        label_car1Brake2_2->setGeometry(QRect(270, 219, 96, 25));
        label_car1Brake2_2->setStyleSheet(QString::fromUtf8("	color: white;\n"
"	border: 2px groove, gray;\n"
"    border-color: gray;\n"
"	font: 12px, \"SimHei\";	"));
        label_car1Brake2_2->setAlignment(Qt::AlignCenter);
        label_car1Brake1_2 = new QLabel(RunStatePage);
        label_car1Brake1_2->setObjectName(QString::fromUtf8("label_car1Brake1_2"));
        label_car1Brake1_2->setGeometry(QRect(176, 219, 95, 25));
        label_car1Brake1_2->setStyleSheet(QString::fromUtf8("	color: white;\n"
"	border: 2px groove, gray;\n"
"    border-color: gray;\n"
"	font: 15px, \"SimHei\";	"));
        label_car1Brake1_2->setAlignment(Qt::AlignCenter);
        label_car4Brake2_2 = new QLabel(RunStatePage);
        label_car4Brake2_2->setObjectName(QString::fromUtf8("label_car4Brake2_2"));
        label_car4Brake2_2->setGeometry(QRect(781, 219, 90, 25));
        label_car4Brake2_2->setStyleSheet(QString::fromUtf8("	color: white;\n"
"	border: 2px groove, gray;\n"
"    border-color: gray;\n"
"	font: 12px, \"SimHei\";	"));
        label_car4Brake2_2->setAlignment(Qt::AlignCenter);
        label_car3Brake2_2 = new QLabel(RunStatePage);
        label_car3Brake2_2->setObjectName(QString::fromUtf8("label_car3Brake2_2"));
        label_car3Brake2_2->setGeometry(QRect(573, 219, 105, 25));
        label_car3Brake2_2->setStyleSheet(QString::fromUtf8("	color: white;\n"
"	border: 2px groove, gray;\n"
"    border-color: gray;\n"
"	font: 12px, \"SimHei\";	"));
        label_car3Brake2_2->setAlignment(Qt::AlignCenter);
        label_car2Brake1_2 = new QLabel(RunStatePage);
        label_car2Brake1_2->setObjectName(QString::fromUtf8("label_car2Brake1_2"));
        label_car2Brake1_2->setGeometry(QRect(364, 219, 105, 25));
        label_car2Brake1_2->setStyleSheet(QString::fromUtf8("	color: white;\n"
"	border: 2px groove, gray;\n"
"    border-color: gray;\n"
"	font: 12px, \"SimHei\";	"));
        label_car2Brake1_2->setAlignment(Qt::AlignCenter);
        label_car4Brake1_2 = new QLabel(RunStatePage);
        label_car4Brake1_2->setObjectName(QString::fromUtf8("label_car4Brake1_2"));
        label_car4Brake1_2->setGeometry(QRect(871, 219, 90, 25));
        label_car4Brake1_2->setStyleSheet(QString::fromUtf8("	color: white;\n"
"	border: 2px groove, gray;\n"
"    border-color: gray;\n"
"	font: 12px, \"SimHei\";	"));
        label_car4Brake1_2->setAlignment(Qt::AlignCenter);

        retranslateUi(RunStatePage);

        QMetaObject::connectSlotsByName(RunStatePage);
    } // setupUi

    void retranslateUi(QWidget *RunStatePage)
    {
        RunStatePage->setWindowTitle(QApplication::translate("RunStatePage", "Form", 0, QApplication::UnicodeUTF8));
        label_vehicleNo->setText(QApplication::translate("RunStatePage", "\350\275\246\345\217\267", 0, QApplication::UnicodeUTF8));
        label_assistantState->setText(QApplication::translate("RunStatePage", "\350\276\205\345\212\251\347\263\273\347\273\237\347\212\266\346\200\201", 0, QApplication::UnicodeUTF8));
        label_tractionState->setText(QApplication::translate("RunStatePage", "\347\211\265\345\274\225\347\263\273\347\273\237\347\212\266\346\200\201", 0, QApplication::UnicodeUTF8));
        label_brakeState->setText(QApplication::translate("RunStatePage", "\345\210\266\345\212\250\347\212\266\346\200\201", 0, QApplication::UnicodeUTF8));
        label_valve1->setText(QApplication::translate("RunStatePage", "\351\227\250\347\212\266\346\200\201", 0, QApplication::UnicodeUTF8));
        label_innerTemperature->setText(QApplication::translate("RunStatePage", "\350\275\246\345\206\205\346\270\251\345\272\246(\342\204\203)", 0, QApplication::UnicodeUTF8));
        label_AirPressor->setText(QApplication::translate("RunStatePage", "\347\251\272\345\216\213\346\234\272\347\212\266\346\200\201", 0, QApplication::UnicodeUTF8));
        label_car1No->setText(QApplication::translate("RunStatePage", "1", 0, QApplication::UnicodeUTF8));
        label_car1AssistantState->setText(QString());
        label_car1TractionState->setText(QApplication::translate("RunStatePage", "-- --", 0, QApplication::UnicodeUTF8));
        label_car1Brake1->setText(QString());
        label_car1Valve1->setText(QString());
        label_car1Valve2->setText(QString());
        label_car1Valve5->setText(QString());
        label_car1Valve6->setText(QString());
        label_car1InnerTemperature->setText(QString());
        label_APAbnormal1->setText(QApplication::translate("RunStatePage", "\344\276\233\347\224\265\345\274\202\345\270\270", 0, QApplication::UnicodeUTF8));
        label_car2No->setText(QApplication::translate("RunStatePage", "2", 0, QApplication::UnicodeUTF8));
        label_car2AssistantState->setText(QApplication::translate("RunStatePage", "-- --", 0, QApplication::UnicodeUTF8));
        label_car2Brake1->setText(QString());
        label_car2InnerTemperature->setText(QString());
        label_car3No->setText(QApplication::translate("RunStatePage", "3", 0, QApplication::UnicodeUTF8));
        label_car3AssistantState->setText(QApplication::translate("RunStatePage", "-- --", 0, QApplication::UnicodeUTF8));
        label_car3Brake2->setText(QString());
        label_car3InnerTemperature->setText(QString());
        label_car4No->setText(QApplication::translate("RunStatePage", "4", 0, QApplication::UnicodeUTF8));
        label_car4AssistantState->setText(QString());
        label_car4TractionState->setText(QApplication::translate("RunStatePage", "-- --", 0, QApplication::UnicodeUTF8));
        label_car4Brake1->setText(QString());
        label_car4InnerTemperature->setText(QString());
        label_APAbnormal4->setText(QApplication::translate("RunStatePage", "\344\276\233\347\224\265\345\274\202\345\270\270", 0, QApplication::UnicodeUTF8));
        label_car2Brake2->setText(QString());
        label_car3Brake1->setText(QString());
        label_car4Brake2->setText(QString());
        label_car1Brake2->setText(QString());
        label_car4outerTemperature->setText(QString());
        label_car3outerTemperature->setText(QString());
        label_car1outerTemperature->setText(QString());
        label_car2outerTemperature->setText(QString());
        label_outerTemperature->setText(QApplication::translate("RunStatePage", "\350\275\246\345\244\226\346\270\251\345\272\246(\342\204\203)", 0, QApplication::UnicodeUTF8));
        label_car1Valve8->setText(QString());
        label_car1Valve3->setText(QString());
        label_car1Valve7->setText(QString());
        label_car1Valve4->setText(QString());
        label_car2Valve4->setText(QString());
        label_car2Valve7->setText(QString());
        label_car2Valve8->setText(QString());
        label_car2Valve1->setText(QString());
        label_car2Valve5->setText(QString());
        label_car2Valve6->setText(QString());
        label_car2Valve3->setText(QString());
        label_car2Valve2->setText(QString());
        label_car3Valve4->setText(QString());
        label_car3Valve7->setText(QString());
        label_car3Valve5->setText(QString());
        label_car3Valve2->setText(QString());
        label_car3Valve6->setText(QString());
        label_car3Valve8->setText(QString());
        label_car3Valve3->setText(QString());
        label_car3Valve1->setText(QString());
        label_car4Valve1->setText(QString());
        label_car4Valve3->setText(QString());
        label_car4Valve8->setText(QString());
        label_car4Valve4->setText(QString());
        label_car4Valve5->setText(QString());
        label_car4Valve2->setText(QString());
        label_car4Valve6->setText(QString());
        label_car4Valve7->setText(QString());
        label_car3TractionSystem1->setText(QString());
        label_car3TractionSystem3->setText(QString());
        label_car2TractionSystem2->setText(QString());
        label_car2TractionSystem4->setText(QString());
        label_car2TractionSystem3->setText(QString());
        label_car3TractionSystem2->setText(QString());
        label_car3TractionSystem4->setText(QString());
        label_car2TractionSystem1->setText(QString());
        btn_EmergencyBroadcast->setText(QApplication::translate("RunStatePage", "\347\264\247\346\200\245\345\271\277\346\222\255", 0, QApplication::UnicodeUTF8));
        label_car3RidingRate->setText(QString());
        label_ridingRate->setText(QApplication::translate("RunStatePage", "\344\271\230\350\275\246\347\216\207", 0, QApplication::UnicodeUTF8));
        label_car1RidingRate->setText(QString());
        label_car4RidingRate->setText(QString());
        label_car2RidingRate->setText(QString());
        label_APOverLoad1->setText(QApplication::translate("RunStatePage", "\347\203\255\350\277\207\350\275\275", 0, QApplication::UnicodeUTF8));
        label_APOverLoad4->setText(QApplication::translate("RunStatePage", "\347\203\255\350\277\207\350\275\275", 0, QApplication::UnicodeUTF8));
        label_APRun1->setText(QApplication::translate("RunStatePage", "\350\277\220\350\241\214", 0, QApplication::UnicodeUTF8));
        label_APPreStart1->setText(QApplication::translate("RunStatePage", "\351\242\204\345\220\257\345\212\250", 0, QApplication::UnicodeUTF8));
        label_APPreStart4->setText(QApplication::translate("RunStatePage", "\351\242\204\345\220\257\345\212\250", 0, QApplication::UnicodeUTF8));
        label_APRun4->setText(QApplication::translate("RunStatePage", "\350\277\220\350\241\214", 0, QApplication::UnicodeUTF8));
        label_car2RidingRate_2->setText(QApplication::translate("RunStatePage", "-- --", 0, QApplication::UnicodeUTF8));
        label_car3RidingRate_2->setText(QApplication::translate("RunStatePage", "-- --", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("RunStatePage", "1", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("RunStatePage", "2", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("RunStatePage", "3", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("RunStatePage", "4", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("RunStatePage", "5", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("RunStatePage", "6", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("RunStatePage", "7", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("RunStatePage", "8", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("RunStatePage", "8", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("RunStatePage", "2", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("RunStatePage", "7", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("RunStatePage", "6", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("RunStatePage", "4", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("RunStatePage", "3", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("RunStatePage", "5", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("RunStatePage", "8", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("RunStatePage", "2", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("RunStatePage", "7", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("RunStatePage", "6", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("RunStatePage", "4", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("RunStatePage", "3", 0, QApplication::UnicodeUTF8));
        label_22->setText(QApplication::translate("RunStatePage", "5", 0, QApplication::UnicodeUTF8));
        label_23->setText(QApplication::translate("RunStatePage", "8", 0, QApplication::UnicodeUTF8));
        label_24->setText(QApplication::translate("RunStatePage", "2", 0, QApplication::UnicodeUTF8));
        label_25->setText(QApplication::translate("RunStatePage", "7", 0, QApplication::UnicodeUTF8));
        label_26->setText(QApplication::translate("RunStatePage", "6", 0, QApplication::UnicodeUTF8));
        label_27->setText(QApplication::translate("RunStatePage", "4", 0, QApplication::UnicodeUTF8));
        label_28->setText(QApplication::translate("RunStatePage", "3", 0, QApplication::UnicodeUTF8));
        label_29->setText(QApplication::translate("RunStatePage", "5", 0, QApplication::UnicodeUTF8));
        label_30->setText(QApplication::translate("RunStatePage", "1", 0, QApplication::UnicodeUTF8));
        label_31->setText(QApplication::translate("RunStatePage", "1", 0, QApplication::UnicodeUTF8));
        label_32->setText(QApplication::translate("RunStatePage", "1", 0, QApplication::UnicodeUTF8));
        label_car2Brake2_2->setText(QApplication::translate("RunStatePage", "2", 0, QApplication::UnicodeUTF8));
        label_car3Brake1_2->setText(QApplication::translate("RunStatePage", "1", 0, QApplication::UnicodeUTF8));
        label_car1Brake2_2->setText(QApplication::translate("RunStatePage", "2", 0, QApplication::UnicodeUTF8));
        label_car1Brake1_2->setText(QApplication::translate("RunStatePage", "1", 0, QApplication::UnicodeUTF8));
        label_car4Brake2_2->setText(QApplication::translate("RunStatePage", "2", 0, QApplication::UnicodeUTF8));
        label_car3Brake2_2->setText(QApplication::translate("RunStatePage", "2", 0, QApplication::UnicodeUTF8));
        label_car2Brake1_2->setText(QApplication::translate("RunStatePage", "1", 0, QApplication::UnicodeUTF8));
        label_car4Brake1_2->setText(QApplication::translate("RunStatePage", "1", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class RunStatePage: public Ui_RunStatePage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RUNSTATEPAGE_H
