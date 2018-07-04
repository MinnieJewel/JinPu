/********************************************************************************
** Form generated from reading UI file 'airconditionerpage.ui'
**
** Created: Fri Jan 12 13:03:46 2018
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AIRCONDITIONERPAGE_H
#define UI_AIRCONDITIONERPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AirConditionerPage
{
public:
    QLabel *label_controlState4;
    QLabel *label_controlState2;
    QLabel *label_controlState;
    QLabel *label_controlState3;
    QLabel *label_controlState1;
    QLabel *label_setTemperature4;
    QLabel *label_setTemperature3;
    QLabel *label_setTemperature1;
    QLabel *label_setTemperature2;
    QLabel *label_setTemperature;
    QLabel *label_control4;
    QLabel *label_control3;
    QLabel *label_control1;
    QLabel *label_innerTemperature;
    QLabel *label_control2;
    QLabel *label_pressure;
    QLabel *label_conden;
    QLabel *label_vent;
    QLabel *label_preHeater;
    QLabel *label_inputTemperature;
    QLabel *label_4;
    QPushButton *btn_reduse;
    QPushButton *btn_add;
    QPushButton *btn_confirm;
    QPushButton *btn_halfHeat;
    QPushButton *btn_halfCold;
    QPushButton *btn_wholeCold;
    QPushButton *btn_wholeHeat;
    QPushButton *btn_autoCold;
    QPushButton *btn_autoHeat;
    QPushButton *btn_Cease;
    QPushButton *btn_mergencyVent;
    QPushButton *btn_Vent;
    QLabel *label_pressure1_1;
    QLabel *label_pressure1_2;
    QLabel *label_pressure1_3;
    QLabel *label_pressure1_4;
    QLabel *label_pressure2_4;
    QLabel *label_pressure2_3;
    QLabel *label_pressure2_1;
    QLabel *label_pressure2_2;
    QLabel *label_pressure3_4;
    QLabel *label_pressure3_2;
    QLabel *label_pressure3_1;
    QLabel *label_pressure3_3;
    QLabel *label_pressure4_4;
    QLabel *label_pressure4_1;
    QLabel *label_pressure4_3;
    QLabel *label_pressure4_2;
    QLabel *label_conden4_4;
    QLabel *label_conden3_1;
    QLabel *label_conden3_4;
    QLabel *label_conden4_1;
    QLabel *label_conden3_3;
    QLabel *label_conden4_2;
    QLabel *label_conden2_2;
    QLabel *label_conden4_3;
    QLabel *label_conden1_4;
    QLabel *label_conden2_4;
    QLabel *label_conden1_3;
    QLabel *label_conden2_1;
    QLabel *label_conden3_2;
    QLabel *label_conden1_1;
    QLabel *label_conden1_2;
    QLabel *label_conden2_3;
    QLabel *label_vent4_4;
    QLabel *label_vent4_3;
    QLabel *label_vent2_1;
    QLabel *label_vent4_1;
    QLabel *label_vent2_3;
    QLabel *label_vent1_3;
    QLabel *label_vent3_1;
    QLabel *label_vent3_4;
    QLabel *label_vent1_4;
    QLabel *label_vent2_4;
    QLabel *label_vent3_2;
    QLabel *label_vent1_2;
    QLabel *label_vent4_2;
    QLabel *label_vent2_2;
    QLabel *label_vent3_3;
    QLabel *label_vent1_1;
    QLabel *label_preHeater4_4;
    QLabel *label_preHeater4_1;
    QLabel *label_preHeater2_1;
    QLabel *label_preHeater3_2;
    QLabel *label_preHeater1_2;
    QLabel *label_preHeater2_2;
    QLabel *label_preHeater2_3;
    QLabel *label_preHeater1_1;
    QLabel *label_preHeater4_2;
    QLabel *label_preHeater1_4;
    QLabel *label_preHeater3_3;
    QLabel *label_preHeater4_3;
    QLabel *label_preHeater3_4;
    QLabel *label_preHeater3_1;
    QLabel *label_preHeater1_3;
    QLabel *label_preHeater2_4;
    QPushButton *btn_wholeCar;
    QPushButton *btn_car1;
    QPushButton *btn_car2;
    QPushButton *btn_car3;
    QPushButton *btn_car4;
    QLabel *label;
    QLabel *label_remindInfo;
    QLabel *label_remindInfo1;
    QPushButton *btn_EmergencyBroadcast;
    QPushButton *btn_AllOpen;
    QPushButton *btn_23NewWind;
    QPushButton *btn_13NewWind;
    QPushButton *btn_ALLClose;
    QPushButton *btn_Speed_low;
    QPushButton *btn_autowind;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *btn_Speed_high;
    QLabel *label_5;

    void setupUi(QWidget *AirConditionerPage)
    {
        if (AirConditionerPage->objectName().isEmpty())
            AirConditionerPage->setObjectName(QString::fromUtf8("AirConditionerPage"));
        AirConditionerPage->resize(1024, 618);
        AirConditionerPage->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	color: white;\n"
"	border: 2px groove, gray;\n"
"    border-color: gray;\n"
"	font: 18px, \"SimHei\";	\n"
"}\n"
"\n"
"QWidget\n"
"{\n"
"	background-color: black;\n"
"}\n"
"QPushButton\n"
"{\n"
"   font: 20px, \"SimHei\";\n"
"   color: black;\n"
"   background-color: rgb(250, 250, 250);\n"
"   border-radius: 5px;\n"
"   border: 2px solid rgb(150, 150, 150);\n"
"}\n"
"QPushButton:disabled\n"
"{\n"
"		border-radius:5px;\n"
"	font: 20px, \"SimHei\";\n"
"    color: grey;\n"
"	background-color: rgb(221,221,221);\n"
"}"));
        label_controlState4 = new QLabel(AirConditionerPage);
        label_controlState4->setObjectName(QString::fromUtf8("label_controlState4"));
        label_controlState4->setGeometry(QRect(700, 140, 180, 40));
        label_controlState4->setStyleSheet(QString::fromUtf8(""));
        label_controlState4->setAlignment(Qt::AlignCenter);
        label_controlState2 = new QLabel(AirConditionerPage);
        label_controlState2->setObjectName(QString::fromUtf8("label_controlState2"));
        label_controlState2->setGeometry(QRect(305, 140, 195, 40));
        label_controlState2->setStyleSheet(QString::fromUtf8(""));
        label_controlState2->setAlignment(Qt::AlignCenter);
        label_controlState = new QLabel(AirConditionerPage);
        label_controlState->setObjectName(QString::fromUtf8("label_controlState"));
        label_controlState->setGeometry(QRect(0, 140, 125, 40));
        label_controlState->setStyleSheet(QString::fromUtf8(""));
        label_controlState3 = new QLabel(AirConditionerPage);
        label_controlState3->setObjectName(QString::fromUtf8("label_controlState3"));
        label_controlState3->setGeometry(QRect(500, 140, 200, 40));
        label_controlState3->setStyleSheet(QString::fromUtf8(""));
        label_controlState3->setAlignment(Qt::AlignCenter);
        label_controlState1 = new QLabel(AirConditionerPage);
        label_controlState1->setObjectName(QString::fromUtf8("label_controlState1"));
        label_controlState1->setGeometry(QRect(125, 140, 180, 40));
        label_controlState1->setStyleSheet(QString::fromUtf8(""));
        label_controlState1->setAlignment(Qt::AlignCenter);
        label_setTemperature4 = new QLabel(AirConditionerPage);
        label_setTemperature4->setObjectName(QString::fromUtf8("label_setTemperature4"));
        label_setTemperature4->setGeometry(QRect(700, 180, 180, 40));
        label_setTemperature4->setStyleSheet(QString::fromUtf8(""));
        label_setTemperature4->setAlignment(Qt::AlignCenter);
        label_setTemperature3 = new QLabel(AirConditionerPage);
        label_setTemperature3->setObjectName(QString::fromUtf8("label_setTemperature3"));
        label_setTemperature3->setGeometry(QRect(500, 180, 200, 40));
        label_setTemperature3->setStyleSheet(QString::fromUtf8(""));
        label_setTemperature3->setAlignment(Qt::AlignCenter);
        label_setTemperature1 = new QLabel(AirConditionerPage);
        label_setTemperature1->setObjectName(QString::fromUtf8("label_setTemperature1"));
        label_setTemperature1->setGeometry(QRect(125, 180, 180, 40));
        label_setTemperature1->setStyleSheet(QString::fromUtf8(""));
        label_setTemperature1->setAlignment(Qt::AlignCenter);
        label_setTemperature2 = new QLabel(AirConditionerPage);
        label_setTemperature2->setObjectName(QString::fromUtf8("label_setTemperature2"));
        label_setTemperature2->setGeometry(QRect(305, 180, 195, 40));
        label_setTemperature2->setStyleSheet(QString::fromUtf8(""));
        label_setTemperature2->setAlignment(Qt::AlignCenter);
        label_setTemperature = new QLabel(AirConditionerPage);
        label_setTemperature->setObjectName(QString::fromUtf8("label_setTemperature"));
        label_setTemperature->setGeometry(QRect(0, 180, 125, 40));
        label_setTemperature->setStyleSheet(QString::fromUtf8("	font: 16px, \"SimHei\";	"));
        label_control4 = new QLabel(AirConditionerPage);
        label_control4->setObjectName(QString::fromUtf8("label_control4"));
        label_control4->setGeometry(QRect(700, 220, 180, 40));
        label_control4->setStyleSheet(QString::fromUtf8(""));
        label_control4->setAlignment(Qt::AlignCenter);
        label_control3 = new QLabel(AirConditionerPage);
        label_control3->setObjectName(QString::fromUtf8("label_control3"));
        label_control3->setGeometry(QRect(500, 220, 200, 40));
        label_control3->setStyleSheet(QString::fromUtf8(""));
        label_control3->setAlignment(Qt::AlignCenter);
        label_control1 = new QLabel(AirConditionerPage);
        label_control1->setObjectName(QString::fromUtf8("label_control1"));
        label_control1->setGeometry(QRect(125, 220, 180, 40));
        label_control1->setStyleSheet(QString::fromUtf8(""));
        label_control1->setAlignment(Qt::AlignCenter);
        label_innerTemperature = new QLabel(AirConditionerPage);
        label_innerTemperature->setObjectName(QString::fromUtf8("label_innerTemperature"));
        label_innerTemperature->setGeometry(QRect(0, 220, 125, 40));
        label_innerTemperature->setStyleSheet(QString::fromUtf8("	font: 16px, \"SimHei\";	"));
        label_control2 = new QLabel(AirConditionerPage);
        label_control2->setObjectName(QString::fromUtf8("label_control2"));
        label_control2->setGeometry(QRect(305, 220, 195, 40));
        label_control2->setStyleSheet(QString::fromUtf8(""));
        label_control2->setAlignment(Qt::AlignCenter);
        label_pressure = new QLabel(AirConditionerPage);
        label_pressure->setObjectName(QString::fromUtf8("label_pressure"));
        label_pressure->setGeometry(QRect(0, 260, 125, 40));
        label_pressure->setStyleSheet(QString::fromUtf8(""));
        label_conden = new QLabel(AirConditionerPage);
        label_conden->setObjectName(QString::fromUtf8("label_conden"));
        label_conden->setGeometry(QRect(0, 300, 125, 40));
        label_conden->setStyleSheet(QString::fromUtf8(""));
        label_vent = new QLabel(AirConditionerPage);
        label_vent->setObjectName(QString::fromUtf8("label_vent"));
        label_vent->setGeometry(QRect(0, 340, 125, 40));
        label_vent->setStyleSheet(QString::fromUtf8(""));
        label_preHeater = new QLabel(AirConditionerPage);
        label_preHeater->setObjectName(QString::fromUtf8("label_preHeater"));
        label_preHeater->setGeometry(QRect(0, 380, 125, 40));
        label_preHeater->setStyleSheet(QString::fromUtf8(""));
        label_inputTemperature = new QLabel(AirConditionerPage);
        label_inputTemperature->setObjectName(QString::fromUtf8("label_inputTemperature"));
        label_inputTemperature->setGeometry(QRect(600, 500, 181, 31));
        label_4 = new QLabel(AirConditionerPage);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(510, 500, 81, 31));
        label_4->setStyleSheet(QString::fromUtf8("border-color:black;"));
        btn_reduse = new QPushButton(AirConditionerPage);
        btn_reduse->setObjectName(QString::fromUtf8("btn_reduse"));
        btn_reduse->setGeometry(QRect(790, 500, 61, 40));
        btn_add = new QPushButton(AirConditionerPage);
        btn_add->setObjectName(QString::fromUtf8("btn_add"));
        btn_add->setGeometry(QRect(860, 500, 61, 40));
        btn_confirm = new QPushButton(AirConditionerPage);
        btn_confirm->setObjectName(QString::fromUtf8("btn_confirm"));
        btn_confirm->setGeometry(QRect(930, 500, 80, 40));
        btn_halfHeat = new QPushButton(AirConditionerPage);
        btn_halfHeat->setObjectName(QString::fromUtf8("btn_halfHeat"));
        btn_halfHeat->setGeometry(QRect(10, 560, 85, 40));
        btn_halfCold = new QPushButton(AirConditionerPage);
        btn_halfCold->setObjectName(QString::fromUtf8("btn_halfCold"));
        btn_halfCold->setGeometry(QRect(10, 500, 85, 40));
        btn_wholeCold = new QPushButton(AirConditionerPage);
        btn_wholeCold->setObjectName(QString::fromUtf8("btn_wholeCold"));
        btn_wholeCold->setGeometry(QRect(105, 500, 85, 40));
        btn_wholeHeat = new QPushButton(AirConditionerPage);
        btn_wholeHeat->setObjectName(QString::fromUtf8("btn_wholeHeat"));
        btn_wholeHeat->setGeometry(QRect(105, 560, 85, 40));
        btn_autoCold = new QPushButton(AirConditionerPage);
        btn_autoCold->setObjectName(QString::fromUtf8("btn_autoCold"));
        btn_autoCold->setGeometry(QRect(200, 500, 85, 40));
        btn_autoHeat = new QPushButton(AirConditionerPage);
        btn_autoHeat->setObjectName(QString::fromUtf8("btn_autoHeat"));
        btn_autoHeat->setGeometry(QRect(295, 500, 85, 40));
        btn_Cease = new QPushButton(AirConditionerPage);
        btn_Cease->setObjectName(QString::fromUtf8("btn_Cease"));
        btn_Cease->setGeometry(QRect(390, 500, 85, 40));
        btn_mergencyVent = new QPushButton(AirConditionerPage);
        btn_mergencyVent->setObjectName(QString::fromUtf8("btn_mergencyVent"));
        btn_mergencyVent->setGeometry(QRect(200, 560, 85, 40));
        btn_Vent = new QPushButton(AirConditionerPage);
        btn_Vent->setObjectName(QString::fromUtf8("btn_Vent"));
        btn_Vent->setGeometry(QRect(295, 560, 85, 40));
        label_pressure1_1 = new QLabel(AirConditionerPage);
        label_pressure1_1->setObjectName(QString::fromUtf8("label_pressure1_1"));
        label_pressure1_1->setGeometry(QRect(125, 260, 45, 40));
        label_pressure1_1->setAlignment(Qt::AlignCenter);
        label_pressure1_2 = new QLabel(AirConditionerPage);
        label_pressure1_2->setObjectName(QString::fromUtf8("label_pressure1_2"));
        label_pressure1_2->setGeometry(QRect(170, 260, 45, 40));
        label_pressure1_2->setAlignment(Qt::AlignCenter);
        label_pressure1_3 = new QLabel(AirConditionerPage);
        label_pressure1_3->setObjectName(QString::fromUtf8("label_pressure1_3"));
        label_pressure1_3->setGeometry(QRect(215, 260, 45, 40));
        label_pressure1_3->setAlignment(Qt::AlignCenter);
        label_pressure1_4 = new QLabel(AirConditionerPage);
        label_pressure1_4->setObjectName(QString::fromUtf8("label_pressure1_4"));
        label_pressure1_4->setGeometry(QRect(260, 260, 45, 40));
        label_pressure1_4->setAlignment(Qt::AlignCenter);
        label_pressure2_4 = new QLabel(AirConditionerPage);
        label_pressure2_4->setObjectName(QString::fromUtf8("label_pressure2_4"));
        label_pressure2_4->setGeometry(QRect(451, 260, 49, 40));
        label_pressure2_4->setAlignment(Qt::AlignCenter);
        label_pressure2_3 = new QLabel(AirConditionerPage);
        label_pressure2_3->setObjectName(QString::fromUtf8("label_pressure2_3"));
        label_pressure2_3->setGeometry(QRect(403, 260, 48, 40));
        label_pressure2_3->setAlignment(Qt::AlignCenter);
        label_pressure2_1 = new QLabel(AirConditionerPage);
        label_pressure2_1->setObjectName(QString::fromUtf8("label_pressure2_1"));
        label_pressure2_1->setGeometry(QRect(305, 260, 49, 40));
        label_pressure2_1->setAlignment(Qt::AlignCenter);
        label_pressure2_2 = new QLabel(AirConditionerPage);
        label_pressure2_2->setObjectName(QString::fromUtf8("label_pressure2_2"));
        label_pressure2_2->setGeometry(QRect(354, 260, 49, 40));
        label_pressure2_2->setAlignment(Qt::AlignCenter);
        label_pressure3_4 = new QLabel(AirConditionerPage);
        label_pressure3_4->setObjectName(QString::fromUtf8("label_pressure3_4"));
        label_pressure3_4->setGeometry(QRect(650, 260, 50, 40));
        label_pressure3_4->setAlignment(Qt::AlignCenter);
        label_pressure3_2 = new QLabel(AirConditionerPage);
        label_pressure3_2->setObjectName(QString::fromUtf8("label_pressure3_2"));
        label_pressure3_2->setGeometry(QRect(550, 260, 50, 40));
        label_pressure3_2->setAlignment(Qt::AlignCenter);
        label_pressure3_1 = new QLabel(AirConditionerPage);
        label_pressure3_1->setObjectName(QString::fromUtf8("label_pressure3_1"));
        label_pressure3_1->setGeometry(QRect(500, 260, 50, 40));
        label_pressure3_1->setAlignment(Qt::AlignCenter);
        label_pressure3_3 = new QLabel(AirConditionerPage);
        label_pressure3_3->setObjectName(QString::fromUtf8("label_pressure3_3"));
        label_pressure3_3->setGeometry(QRect(600, 260, 50, 40));
        label_pressure3_3->setAlignment(Qt::AlignCenter);
        label_pressure4_4 = new QLabel(AirConditionerPage);
        label_pressure4_4->setObjectName(QString::fromUtf8("label_pressure4_4"));
        label_pressure4_4->setGeometry(QRect(835, 260, 45, 40));
        label_pressure4_4->setAlignment(Qt::AlignCenter);
        label_pressure4_1 = new QLabel(AirConditionerPage);
        label_pressure4_1->setObjectName(QString::fromUtf8("label_pressure4_1"));
        label_pressure4_1->setGeometry(QRect(700, 260, 45, 40));
        label_pressure4_1->setAlignment(Qt::AlignCenter);
        label_pressure4_3 = new QLabel(AirConditionerPage);
        label_pressure4_3->setObjectName(QString::fromUtf8("label_pressure4_3"));
        label_pressure4_3->setGeometry(QRect(790, 260, 45, 40));
        label_pressure4_3->setAlignment(Qt::AlignCenter);
        label_pressure4_2 = new QLabel(AirConditionerPage);
        label_pressure4_2->setObjectName(QString::fromUtf8("label_pressure4_2"));
        label_pressure4_2->setGeometry(QRect(745, 260, 45, 40));
        label_pressure4_2->setAlignment(Qt::AlignCenter);
        label_conden4_4 = new QLabel(AirConditionerPage);
        label_conden4_4->setObjectName(QString::fromUtf8("label_conden4_4"));
        label_conden4_4->setGeometry(QRect(835, 300, 45, 40));
        label_conden4_4->setAlignment(Qt::AlignCenter);
        label_conden3_1 = new QLabel(AirConditionerPage);
        label_conden3_1->setObjectName(QString::fromUtf8("label_conden3_1"));
        label_conden3_1->setGeometry(QRect(500, 300, 50, 40));
        label_conden3_1->setAlignment(Qt::AlignCenter);
        label_conden3_4 = new QLabel(AirConditionerPage);
        label_conden3_4->setObjectName(QString::fromUtf8("label_conden3_4"));
        label_conden3_4->setGeometry(QRect(650, 300, 50, 40));
        label_conden3_4->setAlignment(Qt::AlignCenter);
        label_conden4_1 = new QLabel(AirConditionerPage);
        label_conden4_1->setObjectName(QString::fromUtf8("label_conden4_1"));
        label_conden4_1->setGeometry(QRect(700, 300, 45, 40));
        label_conden4_1->setAlignment(Qt::AlignCenter);
        label_conden3_3 = new QLabel(AirConditionerPage);
        label_conden3_3->setObjectName(QString::fromUtf8("label_conden3_3"));
        label_conden3_3->setGeometry(QRect(600, 300, 50, 40));
        label_conden3_3->setAlignment(Qt::AlignCenter);
        label_conden4_2 = new QLabel(AirConditionerPage);
        label_conden4_2->setObjectName(QString::fromUtf8("label_conden4_2"));
        label_conden4_2->setGeometry(QRect(745, 300, 45, 40));
        label_conden4_2->setAlignment(Qt::AlignCenter);
        label_conden2_2 = new QLabel(AirConditionerPage);
        label_conden2_2->setObjectName(QString::fromUtf8("label_conden2_2"));
        label_conden2_2->setGeometry(QRect(354, 300, 49, 40));
        label_conden2_2->setAlignment(Qt::AlignCenter);
        label_conden4_3 = new QLabel(AirConditionerPage);
        label_conden4_3->setObjectName(QString::fromUtf8("label_conden4_3"));
        label_conden4_3->setGeometry(QRect(790, 300, 45, 40));
        label_conden4_3->setAlignment(Qt::AlignCenter);
        label_conden1_4 = new QLabel(AirConditionerPage);
        label_conden1_4->setObjectName(QString::fromUtf8("label_conden1_4"));
        label_conden1_4->setGeometry(QRect(260, 300, 45, 40));
        label_conden1_4->setAlignment(Qt::AlignCenter);
        label_conden2_4 = new QLabel(AirConditionerPage);
        label_conden2_4->setObjectName(QString::fromUtf8("label_conden2_4"));
        label_conden2_4->setGeometry(QRect(451, 300, 49, 40));
        label_conden2_4->setAlignment(Qt::AlignCenter);
        label_conden1_3 = new QLabel(AirConditionerPage);
        label_conden1_3->setObjectName(QString::fromUtf8("label_conden1_3"));
        label_conden1_3->setGeometry(QRect(215, 300, 45, 40));
        label_conden1_3->setAlignment(Qt::AlignCenter);
        label_conden2_1 = new QLabel(AirConditionerPage);
        label_conden2_1->setObjectName(QString::fromUtf8("label_conden2_1"));
        label_conden2_1->setGeometry(QRect(305, 300, 49, 40));
        label_conden2_1->setAlignment(Qt::AlignCenter);
        label_conden3_2 = new QLabel(AirConditionerPage);
        label_conden3_2->setObjectName(QString::fromUtf8("label_conden3_2"));
        label_conden3_2->setGeometry(QRect(550, 300, 50, 40));
        label_conden3_2->setAlignment(Qt::AlignCenter);
        label_conden1_1 = new QLabel(AirConditionerPage);
        label_conden1_1->setObjectName(QString::fromUtf8("label_conden1_1"));
        label_conden1_1->setGeometry(QRect(125, 300, 45, 40));
        label_conden1_1->setAlignment(Qt::AlignCenter);
        label_conden1_2 = new QLabel(AirConditionerPage);
        label_conden1_2->setObjectName(QString::fromUtf8("label_conden1_2"));
        label_conden1_2->setGeometry(QRect(170, 300, 45, 40));
        label_conden1_2->setAlignment(Qt::AlignCenter);
        label_conden2_3 = new QLabel(AirConditionerPage);
        label_conden2_3->setObjectName(QString::fromUtf8("label_conden2_3"));
        label_conden2_3->setGeometry(QRect(403, 300, 48, 40));
        label_conden2_3->setAlignment(Qt::AlignCenter);
        label_vent4_4 = new QLabel(AirConditionerPage);
        label_vent4_4->setObjectName(QString::fromUtf8("label_vent4_4"));
        label_vent4_4->setGeometry(QRect(835, 340, 45, 40));
        label_vent4_4->setAlignment(Qt::AlignCenter);
        label_vent4_3 = new QLabel(AirConditionerPage);
        label_vent4_3->setObjectName(QString::fromUtf8("label_vent4_3"));
        label_vent4_3->setGeometry(QRect(790, 340, 45, 40));
        label_vent4_3->setAlignment(Qt::AlignCenter);
        label_vent2_1 = new QLabel(AirConditionerPage);
        label_vent2_1->setObjectName(QString::fromUtf8("label_vent2_1"));
        label_vent2_1->setGeometry(QRect(305, 340, 49, 40));
        label_vent2_1->setAlignment(Qt::AlignCenter);
        label_vent4_1 = new QLabel(AirConditionerPage);
        label_vent4_1->setObjectName(QString::fromUtf8("label_vent4_1"));
        label_vent4_1->setGeometry(QRect(700, 340, 45, 40));
        label_vent4_1->setAlignment(Qt::AlignCenter);
        label_vent2_3 = new QLabel(AirConditionerPage);
        label_vent2_3->setObjectName(QString::fromUtf8("label_vent2_3"));
        label_vent2_3->setGeometry(QRect(403, 340, 48, 40));
        label_vent2_3->setAlignment(Qt::AlignCenter);
        label_vent1_3 = new QLabel(AirConditionerPage);
        label_vent1_3->setObjectName(QString::fromUtf8("label_vent1_3"));
        label_vent1_3->setGeometry(QRect(215, 340, 45, 40));
        label_vent1_3->setAlignment(Qt::AlignCenter);
        label_vent3_1 = new QLabel(AirConditionerPage);
        label_vent3_1->setObjectName(QString::fromUtf8("label_vent3_1"));
        label_vent3_1->setGeometry(QRect(500, 340, 50, 40));
        label_vent3_1->setAlignment(Qt::AlignCenter);
        label_vent3_4 = new QLabel(AirConditionerPage);
        label_vent3_4->setObjectName(QString::fromUtf8("label_vent3_4"));
        label_vent3_4->setGeometry(QRect(650, 340, 50, 40));
        label_vent3_4->setAlignment(Qt::AlignCenter);
        label_vent1_4 = new QLabel(AirConditionerPage);
        label_vent1_4->setObjectName(QString::fromUtf8("label_vent1_4"));
        label_vent1_4->setGeometry(QRect(260, 340, 45, 40));
        label_vent1_4->setAlignment(Qt::AlignCenter);
        label_vent2_4 = new QLabel(AirConditionerPage);
        label_vent2_4->setObjectName(QString::fromUtf8("label_vent2_4"));
        label_vent2_4->setGeometry(QRect(451, 340, 49, 40));
        label_vent2_4->setAlignment(Qt::AlignCenter);
        label_vent3_2 = new QLabel(AirConditionerPage);
        label_vent3_2->setObjectName(QString::fromUtf8("label_vent3_2"));
        label_vent3_2->setGeometry(QRect(550, 340, 50, 40));
        label_vent3_2->setAlignment(Qt::AlignCenter);
        label_vent1_2 = new QLabel(AirConditionerPage);
        label_vent1_2->setObjectName(QString::fromUtf8("label_vent1_2"));
        label_vent1_2->setGeometry(QRect(170, 340, 45, 40));
        label_vent1_2->setAlignment(Qt::AlignCenter);
        label_vent4_2 = new QLabel(AirConditionerPage);
        label_vent4_2->setObjectName(QString::fromUtf8("label_vent4_2"));
        label_vent4_2->setGeometry(QRect(745, 340, 45, 40));
        label_vent4_2->setAlignment(Qt::AlignCenter);
        label_vent2_2 = new QLabel(AirConditionerPage);
        label_vent2_2->setObjectName(QString::fromUtf8("label_vent2_2"));
        label_vent2_2->setGeometry(QRect(354, 340, 49, 40));
        label_vent2_2->setAlignment(Qt::AlignCenter);
        label_vent3_3 = new QLabel(AirConditionerPage);
        label_vent3_3->setObjectName(QString::fromUtf8("label_vent3_3"));
        label_vent3_3->setGeometry(QRect(600, 340, 50, 40));
        label_vent3_3->setAlignment(Qt::AlignCenter);
        label_vent1_1 = new QLabel(AirConditionerPage);
        label_vent1_1->setObjectName(QString::fromUtf8("label_vent1_1"));
        label_vent1_1->setGeometry(QRect(125, 340, 45, 40));
        label_vent1_1->setAlignment(Qt::AlignCenter);
        label_preHeater4_4 = new QLabel(AirConditionerPage);
        label_preHeater4_4->setObjectName(QString::fromUtf8("label_preHeater4_4"));
        label_preHeater4_4->setGeometry(QRect(835, 380, 45, 40));
        label_preHeater4_4->setAlignment(Qt::AlignCenter);
        label_preHeater4_1 = new QLabel(AirConditionerPage);
        label_preHeater4_1->setObjectName(QString::fromUtf8("label_preHeater4_1"));
        label_preHeater4_1->setGeometry(QRect(700, 380, 45, 40));
        label_preHeater4_1->setAlignment(Qt::AlignCenter);
        label_preHeater2_1 = new QLabel(AirConditionerPage);
        label_preHeater2_1->setObjectName(QString::fromUtf8("label_preHeater2_1"));
        label_preHeater2_1->setGeometry(QRect(305, 380, 49, 40));
        label_preHeater2_1->setAlignment(Qt::AlignCenter);
        label_preHeater3_2 = new QLabel(AirConditionerPage);
        label_preHeater3_2->setObjectName(QString::fromUtf8("label_preHeater3_2"));
        label_preHeater3_2->setGeometry(QRect(550, 380, 50, 40));
        label_preHeater3_2->setAlignment(Qt::AlignCenter);
        label_preHeater1_2 = new QLabel(AirConditionerPage);
        label_preHeater1_2->setObjectName(QString::fromUtf8("label_preHeater1_2"));
        label_preHeater1_2->setGeometry(QRect(170, 380, 45, 40));
        label_preHeater1_2->setAlignment(Qt::AlignCenter);
        label_preHeater2_2 = new QLabel(AirConditionerPage);
        label_preHeater2_2->setObjectName(QString::fromUtf8("label_preHeater2_2"));
        label_preHeater2_2->setGeometry(QRect(354, 380, 49, 40));
        label_preHeater2_2->setAlignment(Qt::AlignCenter);
        label_preHeater2_3 = new QLabel(AirConditionerPage);
        label_preHeater2_3->setObjectName(QString::fromUtf8("label_preHeater2_3"));
        label_preHeater2_3->setGeometry(QRect(403, 380, 48, 40));
        label_preHeater2_3->setAlignment(Qt::AlignCenter);
        label_preHeater1_1 = new QLabel(AirConditionerPage);
        label_preHeater1_1->setObjectName(QString::fromUtf8("label_preHeater1_1"));
        label_preHeater1_1->setGeometry(QRect(125, 380, 45, 40));
        label_preHeater1_1->setAlignment(Qt::AlignCenter);
        label_preHeater4_2 = new QLabel(AirConditionerPage);
        label_preHeater4_2->setObjectName(QString::fromUtf8("label_preHeater4_2"));
        label_preHeater4_2->setGeometry(QRect(745, 380, 45, 40));
        label_preHeater4_2->setAlignment(Qt::AlignCenter);
        label_preHeater1_4 = new QLabel(AirConditionerPage);
        label_preHeater1_4->setObjectName(QString::fromUtf8("label_preHeater1_4"));
        label_preHeater1_4->setGeometry(QRect(260, 380, 45, 40));
        label_preHeater1_4->setAlignment(Qt::AlignCenter);
        label_preHeater3_3 = new QLabel(AirConditionerPage);
        label_preHeater3_3->setObjectName(QString::fromUtf8("label_preHeater3_3"));
        label_preHeater3_3->setGeometry(QRect(600, 380, 50, 40));
        label_preHeater3_3->setAlignment(Qt::AlignCenter);
        label_preHeater4_3 = new QLabel(AirConditionerPage);
        label_preHeater4_3->setObjectName(QString::fromUtf8("label_preHeater4_3"));
        label_preHeater4_3->setGeometry(QRect(790, 380, 45, 40));
        label_preHeater4_3->setAlignment(Qt::AlignCenter);
        label_preHeater3_4 = new QLabel(AirConditionerPage);
        label_preHeater3_4->setObjectName(QString::fromUtf8("label_preHeater3_4"));
        label_preHeater3_4->setGeometry(QRect(650, 380, 50, 40));
        label_preHeater3_4->setAlignment(Qt::AlignCenter);
        label_preHeater3_1 = new QLabel(AirConditionerPage);
        label_preHeater3_1->setObjectName(QString::fromUtf8("label_preHeater3_1"));
        label_preHeater3_1->setGeometry(QRect(500, 380, 50, 40));
        label_preHeater3_1->setAlignment(Qt::AlignCenter);
        label_preHeater1_3 = new QLabel(AirConditionerPage);
        label_preHeater1_3->setObjectName(QString::fromUtf8("label_preHeater1_3"));
        label_preHeater1_3->setGeometry(QRect(215, 380, 45, 40));
        label_preHeater1_3->setAlignment(Qt::AlignCenter);
        label_preHeater2_4 = new QLabel(AirConditionerPage);
        label_preHeater2_4->setObjectName(QString::fromUtf8("label_preHeater2_4"));
        label_preHeater2_4->setGeometry(QRect(451, 380, 49, 40));
        label_preHeater2_4->setAlignment(Qt::AlignCenter);
        btn_wholeCar = new QPushButton(AirConditionerPage);
        btn_wholeCar->setObjectName(QString::fromUtf8("btn_wholeCar"));
        btn_wholeCar->setGeometry(QRect(0, 100, 125, 40));
        btn_wholeCar->setStyleSheet(QString::fromUtf8("font: 20px, \"SimHei\";\n"
"color: black;\n"
"background-color: rgb(250, 250, 250);\n"
"border-radius: 0px;\n"
"border: 2px solid rgb(150, 150, 150);"));
        btn_car1 = new QPushButton(AirConditionerPage);
        btn_car1->setObjectName(QString::fromUtf8("btn_car1"));
        btn_car1->setGeometry(QRect(125, 100, 180, 40));
        btn_car1->setStyleSheet(QString::fromUtf8("font: 20px, \"SimHei\";\n"
"color: black;\n"
"background-color: rgb(250, 250, 250);\n"
"border-radius: 0px;\n"
"border: 2px solid rgb(150, 150, 150);"));
        btn_car2 = new QPushButton(AirConditionerPage);
        btn_car2->setObjectName(QString::fromUtf8("btn_car2"));
        btn_car2->setGeometry(QRect(305, 100, 195, 40));
        btn_car2->setStyleSheet(QString::fromUtf8("font: 20px, \"SimHei\";\n"
"color: black;\n"
"background-color: rgb(250, 250, 250);\n"
"border-radius: 0px;\n"
"border: 2px solid rgb(150, 150, 150);"));
        btn_car3 = new QPushButton(AirConditionerPage);
        btn_car3->setObjectName(QString::fromUtf8("btn_car3"));
        btn_car3->setGeometry(QRect(500, 100, 200, 40));
        btn_car3->setStyleSheet(QString::fromUtf8("font: 20px, \"SimHei\";\n"
"color: black;\n"
"background-color: rgb(250, 250, 250);\n"
"border-radius: 0px;\n"
"border: 2px solid rgb(150, 150, 150);"));
        btn_car4 = new QPushButton(AirConditionerPage);
        btn_car4->setObjectName(QString::fromUtf8("btn_car4"));
        btn_car4->setGeometry(QRect(700, 100, 180, 40));
        btn_car4->setStyleSheet(QString::fromUtf8("font: 20px, \"SimHei\";\n"
"color: black;\n"
"background-color: rgb(250, 250, 250);\n"
"border-radius: 0px;\n"
"border: 2px solid rgb(150, 150, 150);"));
        label = new QLabel(AirConditionerPage);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(600, 460, 281, 31));
        label->setStyleSheet(QString::fromUtf8("font: 15px, \"SimHei\";\n"
"border:0px;\n"
"color:red;"));
        label_remindInfo = new QLabel(AirConditionerPage);
        label_remindInfo->setObjectName(QString::fromUtf8("label_remindInfo"));
        label_remindInfo->setGeometry(QRect(10, 460, 281, 31));
        label_remindInfo->setStyleSheet(QString::fromUtf8("font: 15px, \"SimHei\";\n"
"border:0px;\n"
"color:red;"));
        label_remindInfo1 = new QLabel(AirConditionerPage);
        label_remindInfo1->setObjectName(QString::fromUtf8("label_remindInfo1"));
        label_remindInfo1->setGeometry(QRect(310, 460, 281, 31));
        label_remindInfo1->setStyleSheet(QString::fromUtf8("font: 15px, \"SimHei\";\n"
"border:0px;\n"
"color:red;"));
        btn_EmergencyBroadcast = new QPushButton(AirConditionerPage);
        btn_EmergencyBroadcast->setObjectName(QString::fromUtf8("btn_EmergencyBroadcast"));
        btn_EmergencyBroadcast->setGeometry(QRect(890, 560, 120, 40));
        btn_AllOpen = new QPushButton(AirConditionerPage);
        btn_AllOpen->setObjectName(QString::fromUtf8("btn_AllOpen"));
        btn_AllOpen->setGeometry(QRect(900, 340, 95, 40));
        btn_23NewWind = new QPushButton(AirConditionerPage);
        btn_23NewWind->setObjectName(QString::fromUtf8("btn_23NewWind"));
        btn_23NewWind->setGeometry(QRect(900, 220, 95, 40));
        btn_13NewWind = new QPushButton(AirConditionerPage);
        btn_13NewWind->setObjectName(QString::fromUtf8("btn_13NewWind"));
        btn_13NewWind->setGeometry(QRect(900, 160, 95, 40));
        btn_ALLClose = new QPushButton(AirConditionerPage);
        btn_ALLClose->setObjectName(QString::fromUtf8("btn_ALLClose"));
        btn_ALLClose->setGeometry(QRect(900, 280, 95, 40));
        btn_Speed_low = new QPushButton(AirConditionerPage);
        btn_Speed_low->setObjectName(QString::fromUtf8("btn_Speed_low"));
        btn_Speed_low->setGeometry(QRect(390, 560, 85, 40));
        btn_autowind = new QPushButton(AirConditionerPage);
        btn_autowind->setObjectName(QString::fromUtf8("btn_autowind"));
        btn_autowind->setGeometry(QRect(900, 400, 95, 40));
        label_2 = new QLabel(AirConditionerPage);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(890, 100, 120, 360));
        label_3 = new QLabel(AirConditionerPage);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(905, 115, 85, 31));
        label_3->setStyleSheet(QString::fromUtf8("	color: white;\n"
"	border: 2px groove, gray;\n"
"    border-color: black;\n"
"	font: 18px, \"SimHei\";	"));
        btn_Speed_high = new QPushButton(AirConditionerPage);
        btn_Speed_high->setObjectName(QString::fromUtf8("btn_Speed_high"));
        btn_Speed_high->setGeometry(QRect(485, 560, 85, 40));
        label_5 = new QLabel(AirConditionerPage);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(385, 550, 191, 61));
        label_2->raise();
        label_5->raise();
        label_controlState4->raise();
        label_controlState2->raise();
        label_controlState->raise();
        label_controlState3->raise();
        label_controlState1->raise();
        label_setTemperature4->raise();
        label_setTemperature3->raise();
        label_setTemperature1->raise();
        label_setTemperature2->raise();
        label_setTemperature->raise();
        label_control4->raise();
        label_control3->raise();
        label_control1->raise();
        label_innerTemperature->raise();
        label_control2->raise();
        label_pressure->raise();
        label_conden->raise();
        label_vent->raise();
        label_preHeater->raise();
        label_inputTemperature->raise();
        label_4->raise();
        btn_reduse->raise();
        btn_add->raise();
        btn_confirm->raise();
        btn_halfHeat->raise();
        btn_halfCold->raise();
        btn_wholeCold->raise();
        btn_wholeHeat->raise();
        btn_autoCold->raise();
        btn_autoHeat->raise();
        btn_Cease->raise();
        btn_mergencyVent->raise();
        btn_Vent->raise();
        label_pressure1_1->raise();
        label_pressure1_2->raise();
        label_pressure1_3->raise();
        label_pressure1_4->raise();
        label_pressure2_4->raise();
        label_pressure2_3->raise();
        label_pressure2_1->raise();
        label_pressure2_2->raise();
        label_pressure3_4->raise();
        label_pressure3_2->raise();
        label_pressure3_1->raise();
        label_pressure3_3->raise();
        label_pressure4_4->raise();
        label_pressure4_1->raise();
        label_pressure4_3->raise();
        label_pressure4_2->raise();
        label_conden4_4->raise();
        label_conden3_1->raise();
        label_conden3_4->raise();
        label_conden4_1->raise();
        label_conden3_3->raise();
        label_conden4_2->raise();
        label_conden2_2->raise();
        label_conden4_3->raise();
        label_conden1_4->raise();
        label_conden2_4->raise();
        label_conden1_3->raise();
        label_conden2_1->raise();
        label_conden3_2->raise();
        label_conden1_1->raise();
        label_conden1_2->raise();
        label_conden2_3->raise();
        label_vent4_4->raise();
        label_vent4_3->raise();
        label_vent2_1->raise();
        label_vent4_1->raise();
        label_vent2_3->raise();
        label_vent1_3->raise();
        label_vent3_1->raise();
        label_vent3_4->raise();
        label_vent1_4->raise();
        label_vent2_4->raise();
        label_vent3_2->raise();
        label_vent1_2->raise();
        label_vent4_2->raise();
        label_vent2_2->raise();
        label_vent3_3->raise();
        label_vent1_1->raise();
        label_preHeater4_4->raise();
        label_preHeater4_1->raise();
        label_preHeater2_1->raise();
        label_preHeater3_2->raise();
        label_preHeater1_2->raise();
        label_preHeater2_2->raise();
        label_preHeater2_3->raise();
        label_preHeater1_1->raise();
        label_preHeater4_2->raise();
        label_preHeater1_4->raise();
        label_preHeater3_3->raise();
        label_preHeater4_3->raise();
        label_preHeater3_4->raise();
        label_preHeater3_1->raise();
        label_preHeater1_3->raise();
        label_preHeater2_4->raise();
        btn_wholeCar->raise();
        btn_car1->raise();
        btn_car2->raise();
        btn_car3->raise();
        btn_car4->raise();
        label->raise();
        label_remindInfo->raise();
        label_remindInfo1->raise();
        btn_EmergencyBroadcast->raise();
        btn_AllOpen->raise();
        btn_23NewWind->raise();
        btn_13NewWind->raise();
        btn_ALLClose->raise();
        btn_Speed_low->raise();
        btn_autowind->raise();
        label_3->raise();
        btn_Speed_high->raise();

        retranslateUi(AirConditionerPage);

        QMetaObject::connectSlotsByName(AirConditionerPage);
    } // setupUi

    void retranslateUi(QWidget *AirConditionerPage)
    {
        AirConditionerPage->setWindowTitle(QApplication::translate("AirConditionerPage", "Form", 0, QApplication::UnicodeUTF8));
        label_controlState4->setText(QString());
        label_controlState2->setText(QString());
        label_controlState->setText(QApplication::translate("AirConditionerPage", "\346\250\241\345\274\217", 0, QApplication::UnicodeUTF8));
        label_controlState3->setText(QString());
        label_controlState1->setText(QString());
        label_setTemperature4->setText(QString());
        label_setTemperature3->setText(QString());
        label_setTemperature1->setText(QString());
        label_setTemperature2->setText(QString());
        label_setTemperature->setText(QApplication::translate("AirConditionerPage", "\350\256\276\347\275\256\346\270\251\345\272\246(\342\204\203)", 0, QApplication::UnicodeUTF8));
        label_control4->setText(QString());
        label_control3->setText(QString());
        label_control1->setText(QString());
        label_innerTemperature->setText(QApplication::translate("AirConditionerPage", "\346\216\247\345\210\266\346\250\241\345\274\217", 0, QApplication::UnicodeUTF8));
        label_control2->setText(QString());
        label_pressure->setText(QApplication::translate("AirConditionerPage", "\345\216\213\347\274\251\346\234\272", 0, QApplication::UnicodeUTF8));
        label_conden->setText(QApplication::translate("AirConditionerPage", "\345\206\267\345\207\235\346\234\272", 0, QApplication::UnicodeUTF8));
        label_vent->setText(QApplication::translate("AirConditionerPage", "\351\200\232\351\243\216\346\234\272", 0, QApplication::UnicodeUTF8));
        label_preHeater->setText(QApplication::translate("AirConditionerPage", "\351\242\204\347\203\255\345\231\250", 0, QApplication::UnicodeUTF8));
        label_inputTemperature->setText(QString());
        label_4->setText(QApplication::translate("AirConditionerPage", "\350\256\276\347\275\256\346\270\251\345\272\246", 0, QApplication::UnicodeUTF8));
        btn_reduse->setText(QApplication::translate("AirConditionerPage", "\342\226\274", 0, QApplication::UnicodeUTF8));
        btn_add->setText(QApplication::translate("AirConditionerPage", "\342\226\262", 0, QApplication::UnicodeUTF8));
        btn_confirm->setText(QApplication::translate("AirConditionerPage", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
        btn_halfHeat->setText(QApplication::translate("AirConditionerPage", "\345\215\212\346\232\226", 0, QApplication::UnicodeUTF8));
        btn_halfCold->setText(QApplication::translate("AirConditionerPage", "\345\215\212\345\206\267", 0, QApplication::UnicodeUTF8));
        btn_wholeCold->setText(QApplication::translate("AirConditionerPage", "\345\205\250\345\206\267", 0, QApplication::UnicodeUTF8));
        btn_wholeHeat->setText(QApplication::translate("AirConditionerPage", "\345\205\250\346\232\226", 0, QApplication::UnicodeUTF8));
        btn_autoCold->setText(QApplication::translate("AirConditionerPage", "\350\207\252\345\212\250\345\210\266\345\206\267", 0, QApplication::UnicodeUTF8));
        btn_autoHeat->setText(QApplication::translate("AirConditionerPage", "\350\207\252\345\212\250\345\210\266\346\232\226", 0, QApplication::UnicodeUTF8));
        btn_Cease->setText(QApplication::translate("AirConditionerPage", "\345\201\234\346\255\242", 0, QApplication::UnicodeUTF8));
        btn_mergencyVent->setText(QApplication::translate("AirConditionerPage", "\347\264\247\346\200\245\351\200\232\351\243\216", 0, QApplication::UnicodeUTF8));
        btn_Vent->setText(QApplication::translate("AirConditionerPage", "\351\200\232\351\243\216", 0, QApplication::UnicodeUTF8));
        label_pressure1_1->setText(QApplication::translate("AirConditionerPage", "1", 0, QApplication::UnicodeUTF8));
        label_pressure1_2->setText(QApplication::translate("AirConditionerPage", "2", 0, QApplication::UnicodeUTF8));
        label_pressure1_3->setText(QApplication::translate("AirConditionerPage", "3", 0, QApplication::UnicodeUTF8));
        label_pressure1_4->setText(QApplication::translate("AirConditionerPage", "4", 0, QApplication::UnicodeUTF8));
        label_pressure2_4->setText(QApplication::translate("AirConditionerPage", "4", 0, QApplication::UnicodeUTF8));
        label_pressure2_3->setText(QApplication::translate("AirConditionerPage", "3", 0, QApplication::UnicodeUTF8));
        label_pressure2_1->setText(QApplication::translate("AirConditionerPage", "1", 0, QApplication::UnicodeUTF8));
        label_pressure2_2->setText(QApplication::translate("AirConditionerPage", "2", 0, QApplication::UnicodeUTF8));
        label_pressure3_4->setText(QApplication::translate("AirConditionerPage", "4", 0, QApplication::UnicodeUTF8));
        label_pressure3_2->setText(QApplication::translate("AirConditionerPage", "2", 0, QApplication::UnicodeUTF8));
        label_pressure3_1->setText(QApplication::translate("AirConditionerPage", "1", 0, QApplication::UnicodeUTF8));
        label_pressure3_3->setText(QApplication::translate("AirConditionerPage", "3", 0, QApplication::UnicodeUTF8));
        label_pressure4_4->setText(QApplication::translate("AirConditionerPage", "4", 0, QApplication::UnicodeUTF8));
        label_pressure4_1->setText(QApplication::translate("AirConditionerPage", "1", 0, QApplication::UnicodeUTF8));
        label_pressure4_3->setText(QApplication::translate("AirConditionerPage", "3", 0, QApplication::UnicodeUTF8));
        label_pressure4_2->setText(QApplication::translate("AirConditionerPage", "2", 0, QApplication::UnicodeUTF8));
        label_conden4_4->setText(QApplication::translate("AirConditionerPage", "4", 0, QApplication::UnicodeUTF8));
        label_conden3_1->setText(QApplication::translate("AirConditionerPage", "1", 0, QApplication::UnicodeUTF8));
        label_conden3_4->setText(QApplication::translate("AirConditionerPage", "4", 0, QApplication::UnicodeUTF8));
        label_conden4_1->setText(QApplication::translate("AirConditionerPage", "1", 0, QApplication::UnicodeUTF8));
        label_conden3_3->setText(QApplication::translate("AirConditionerPage", "3", 0, QApplication::UnicodeUTF8));
        label_conden4_2->setText(QApplication::translate("AirConditionerPage", "2", 0, QApplication::UnicodeUTF8));
        label_conden2_2->setText(QApplication::translate("AirConditionerPage", "2", 0, QApplication::UnicodeUTF8));
        label_conden4_3->setText(QApplication::translate("AirConditionerPage", "3", 0, QApplication::UnicodeUTF8));
        label_conden1_4->setText(QApplication::translate("AirConditionerPage", "4", 0, QApplication::UnicodeUTF8));
        label_conden2_4->setText(QApplication::translate("AirConditionerPage", "4", 0, QApplication::UnicodeUTF8));
        label_conden1_3->setText(QApplication::translate("AirConditionerPage", "3", 0, QApplication::UnicodeUTF8));
        label_conden2_1->setText(QApplication::translate("AirConditionerPage", "1", 0, QApplication::UnicodeUTF8));
        label_conden3_2->setText(QApplication::translate("AirConditionerPage", "2", 0, QApplication::UnicodeUTF8));
        label_conden1_1->setText(QApplication::translate("AirConditionerPage", "1", 0, QApplication::UnicodeUTF8));
        label_conden1_2->setText(QApplication::translate("AirConditionerPage", "2", 0, QApplication::UnicodeUTF8));
        label_conden2_3->setText(QApplication::translate("AirConditionerPage", "3", 0, QApplication::UnicodeUTF8));
        label_vent4_4->setText(QApplication::translate("AirConditionerPage", "4", 0, QApplication::UnicodeUTF8));
        label_vent4_3->setText(QApplication::translate("AirConditionerPage", "3", 0, QApplication::UnicodeUTF8));
        label_vent2_1->setText(QApplication::translate("AirConditionerPage", "1", 0, QApplication::UnicodeUTF8));
        label_vent4_1->setText(QApplication::translate("AirConditionerPage", "1", 0, QApplication::UnicodeUTF8));
        label_vent2_3->setText(QApplication::translate("AirConditionerPage", "3", 0, QApplication::UnicodeUTF8));
        label_vent1_3->setText(QApplication::translate("AirConditionerPage", "3", 0, QApplication::UnicodeUTF8));
        label_vent3_1->setText(QApplication::translate("AirConditionerPage", "1", 0, QApplication::UnicodeUTF8));
        label_vent3_4->setText(QApplication::translate("AirConditionerPage", "4", 0, QApplication::UnicodeUTF8));
        label_vent1_4->setText(QApplication::translate("AirConditionerPage", "4", 0, QApplication::UnicodeUTF8));
        label_vent2_4->setText(QApplication::translate("AirConditionerPage", "4", 0, QApplication::UnicodeUTF8));
        label_vent3_2->setText(QApplication::translate("AirConditionerPage", "2", 0, QApplication::UnicodeUTF8));
        label_vent1_2->setText(QApplication::translate("AirConditionerPage", "2", 0, QApplication::UnicodeUTF8));
        label_vent4_2->setText(QApplication::translate("AirConditionerPage", "2", 0, QApplication::UnicodeUTF8));
        label_vent2_2->setText(QApplication::translate("AirConditionerPage", "2", 0, QApplication::UnicodeUTF8));
        label_vent3_3->setText(QApplication::translate("AirConditionerPage", "3", 0, QApplication::UnicodeUTF8));
        label_vent1_1->setText(QApplication::translate("AirConditionerPage", "1", 0, QApplication::UnicodeUTF8));
        label_preHeater4_4->setText(QApplication::translate("AirConditionerPage", "4", 0, QApplication::UnicodeUTF8));
        label_preHeater4_1->setText(QApplication::translate("AirConditionerPage", "1", 0, QApplication::UnicodeUTF8));
        label_preHeater2_1->setText(QApplication::translate("AirConditionerPage", "1", 0, QApplication::UnicodeUTF8));
        label_preHeater3_2->setText(QApplication::translate("AirConditionerPage", "2", 0, QApplication::UnicodeUTF8));
        label_preHeater1_2->setText(QApplication::translate("AirConditionerPage", "2", 0, QApplication::UnicodeUTF8));
        label_preHeater2_2->setText(QApplication::translate("AirConditionerPage", "2", 0, QApplication::UnicodeUTF8));
        label_preHeater2_3->setText(QApplication::translate("AirConditionerPage", "3", 0, QApplication::UnicodeUTF8));
        label_preHeater1_1->setText(QApplication::translate("AirConditionerPage", "1", 0, QApplication::UnicodeUTF8));
        label_preHeater4_2->setText(QApplication::translate("AirConditionerPage", "2", 0, QApplication::UnicodeUTF8));
        label_preHeater1_4->setText(QApplication::translate("AirConditionerPage", "4", 0, QApplication::UnicodeUTF8));
        label_preHeater3_3->setText(QApplication::translate("AirConditionerPage", "3", 0, QApplication::UnicodeUTF8));
        label_preHeater4_3->setText(QApplication::translate("AirConditionerPage", "3", 0, QApplication::UnicodeUTF8));
        label_preHeater3_4->setText(QApplication::translate("AirConditionerPage", "4", 0, QApplication::UnicodeUTF8));
        label_preHeater3_1->setText(QApplication::translate("AirConditionerPage", "1", 0, QApplication::UnicodeUTF8));
        label_preHeater1_3->setText(QApplication::translate("AirConditionerPage", "3", 0, QApplication::UnicodeUTF8));
        label_preHeater2_4->setText(QApplication::translate("AirConditionerPage", "4", 0, QApplication::UnicodeUTF8));
        btn_wholeCar->setText(QApplication::translate("AirConditionerPage", "\346\225\264\350\275\246", 0, QApplication::UnicodeUTF8));
        btn_car1->setText(QApplication::translate("AirConditionerPage", "1", 0, QApplication::UnicodeUTF8));
        btn_car2->setText(QApplication::translate("AirConditionerPage", "2", 0, QApplication::UnicodeUTF8));
        btn_car3->setText(QApplication::translate("AirConditionerPage", "3", 0, QApplication::UnicodeUTF8));
        btn_car4->setText(QApplication::translate("AirConditionerPage", "4", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("AirConditionerPage", "\345\234\250\350\207\252\345\212\250\345\210\266\345\206\267\357\274\217\350\207\252\345\212\250\345\210\266\346\232\226\346\250\241\345\274\217\344\270\213\345\217\257\350\256\276\347\275\256\346\270\251\345\272\246", 0, QApplication::UnicodeUTF8));
        label_remindInfo->setText(QString());
        label_remindInfo1->setText(QString());
        btn_EmergencyBroadcast->setText(QApplication::translate("AirConditionerPage", "\347\264\247\346\200\245\345\271\277\346\222\255", 0, QApplication::UnicodeUTF8));
        btn_AllOpen->setText(QApplication::translate("AirConditionerPage", "\345\205\250\345\274\200", 0, QApplication::UnicodeUTF8));
        btn_23NewWind->setText(QApplication::translate("AirConditionerPage", "2/3\346\226\260\351\243\216", 0, QApplication::UnicodeUTF8));
        btn_13NewWind->setText(QApplication::translate("AirConditionerPage", "1/3\346\226\260\351\243\216", 0, QApplication::UnicodeUTF8));
        btn_ALLClose->setText(QApplication::translate("AirConditionerPage", "\345\205\250\345\205\263", 0, QApplication::UnicodeUTF8));
        btn_Speed_low->setText(QApplication::translate("AirConditionerPage", "\344\275\216\351\200\237", 0, QApplication::UnicodeUTF8));
        btn_autowind->setText(QApplication::translate("AirConditionerPage", "\350\207\252\345\212\250\346\216\247\345\210\266", 0, QApplication::UnicodeUTF8));
        label_2->setText(QString());
        label_3->setText(QApplication::translate("AirConditionerPage", "\351\243\216\351\207\217\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        btn_Speed_high->setText(QApplication::translate("AirConditionerPage", "\351\253\230\351\200\237", 0, QApplication::UnicodeUTF8));
        label_5->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AirConditionerPage: public Ui_AirConditionerPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AIRCONDITIONERPAGE_H
