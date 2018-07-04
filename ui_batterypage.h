/********************************************************************************
** Form generated from reading UI file 'batterypage.ui'
**
** Created: Thu Jan 11 11:16:18 2018
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BATTERYPAGE_H
#define UI_BATTERYPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BatteryPage
{
public:
    QLabel *label_chargeVoltage2;
    QLabel *label_chargeVoltage4;
    QLabel *label_chargeVoltage3;
    QLabel *label_chargeVoltage1;
    QLabel *label_dischargeVoltage3;
    QLabel *label_chargeCurrent1;
    QLabel *label_dischargeCurrent4;
    QLabel *label_chargeCurrent3;
    QLabel *label_chargeVoltage;
    QLabel *label_car2No;
    QLabel *label_dischargeCurrent;
    QLabel *label_vehicleNo;
    QLabel *label_car1No;
    QLabel *label_temperature2;
    QLabel *label_dischargeVoltage;
    QLabel *label_temperature3;
    QLabel *label_chargeCurrent;
    QLabel *label_temperature;
    QLabel *label_car4No;
    QLabel *label_dischargeCurrent1;
    QLabel *label_temperature1;
    QLabel *label_chargeCurrent4;
    QLabel *label_car3No;
    QLabel *label_chargeCurrent2;
    QLabel *label_dischargeCurrent2;
    QLabel *label_dischargeCurrent3;
    QLabel *label_dischargeVoltage1;
    QLabel *label_dischargeVoltage2;
    QLabel *label_temperature4;
    QLabel *label_dischargeVoltage4;
    QLabel *label_lowerVoltage4;
    QLabel *label_overTemperature4;
    QLabel *label_lightState;
    QLabel *label_lightState3;
    QLabel *label_overTemperature1;
    QLabel *label_lowerVoltage1;
    QLabel *label_lightState4;
    QLabel *label_overResistance3;
    QLabel *label_lightState2;
    QLabel *label_lightState1;
    QLabel *label_overVoltage3;
    QLabel *label_overTemperature2;
    QLabel *label_lowerVoltage;
    QLabel *label_overTemperature;
    QLabel *label_overResistance1;
    QLabel *label_overVoltage4;
    QLabel *label_overVoltage;
    QLabel *label_overTemperature3;
    QLabel *label_overResistance2;
    QLabel *label_overVoltage2;
    QLabel *label_overResistance4;
    QLabel *label_lowerVoltage2;
    QLabel *label_overVoltage1;
    QLabel *label_lowerVoltage3;
    QLabel *label_overResistance;
    QLabel *label_overAlarmTemp;
    QLabel *label_overAlarmVol;
    QLabel *label_overAlarmRes2;
    QLabel *label_overAlarmRes3;
    QLabel *label_overAlarmVol3;
    QLabel *label_overAlarmTemp3;
    QLabel *label_lowerAlarmVol3;
    QLabel *label_lowerAlarmVol;
    QLabel *label_overAlarmVol4_1;
    QLabel *label_lowerAlarmVol2;
    QLabel *label_overAlarmVol2;
    QLabel *label_overAlarmTemp2;
    QLabel *label_overAlarmVol1_1;
    QLabel *label_overAlarmRes;
    QLabel *label_overAlarmVol1_2;
    QLabel *label_overAlarmVol4_2;
    QLabel *label_lowerAlarmVol4_2;
    QLabel *label_lowerAlarmVol4_1;
    QLabel *label_overAlarmTemp4_1;
    QLabel *label_overAlarmTemp4_2;
    QLabel *label_overAlarmRes4_1;
    QLabel *label_overAlarmRes4_2;
    QLabel *label_lowerAlarmVol1_2;
    QLabel *label_lowerAlarmVol1_1;
    QLabel *label_overAlarmTemp1_1;
    QLabel *label_overAlarmTemp1_2;
    QLabel *label_overAlarmRes1_2;
    QLabel *label_overAlarmRes1_1;
    QPushButton *btn_EmergencyBroadcast;

    void setupUi(QWidget *BatteryPage)
    {
        if (BatteryPage->objectName().isEmpty())
            BatteryPage->setObjectName(QString::fromUtf8("BatteryPage"));
        BatteryPage->resize(1024, 618);
        BatteryPage->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	color: white;\n"
"	border: 2px groove, gray;\n"
"    border-color: gray;\n"
"	font: 15px, \"SimHei\";	\n"
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
        label_chargeVoltage2 = new QLabel(BatteryPage);
        label_chargeVoltage2->setObjectName(QString::fromUtf8("label_chargeVoltage2"));
        label_chargeVoltage2->setGeometry(QRect(357, 128, 200, 30));
        label_chargeVoltage2->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_chargeVoltage4 = new QLabel(BatteryPage);
        label_chargeVoltage4->setObjectName(QString::fromUtf8("label_chargeVoltage4"));
        label_chargeVoltage4->setGeometry(QRect(755, 128, 180, 30));
        label_chargeVoltage4->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_chargeVoltage3 = new QLabel(BatteryPage);
        label_chargeVoltage3->setObjectName(QString::fromUtf8("label_chargeVoltage3"));
        label_chargeVoltage3->setGeometry(QRect(556, 128, 200, 30));
        label_chargeVoltage3->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_chargeVoltage1 = new QLabel(BatteryPage);
        label_chargeVoltage1->setObjectName(QString::fromUtf8("label_chargeVoltage1"));
        label_chargeVoltage1->setGeometry(QRect(169, 128, 190, 30));
        label_chargeVoltage1->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_dischargeVoltage3 = new QLabel(BatteryPage);
        label_dischargeVoltage3->setObjectName(QString::fromUtf8("label_dischargeVoltage3"));
        label_dischargeVoltage3->setGeometry(QRect(556, 157, 200, 30));
        label_dischargeVoltage3->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_chargeCurrent1 = new QLabel(BatteryPage);
        label_chargeCurrent1->setObjectName(QString::fromUtf8("label_chargeCurrent1"));
        label_chargeCurrent1->setGeometry(QRect(169, 215, 190, 30));
        label_chargeCurrent1->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_dischargeCurrent4 = new QLabel(BatteryPage);
        label_dischargeCurrent4->setObjectName(QString::fromUtf8("label_dischargeCurrent4"));
        label_dischargeCurrent4->setGeometry(QRect(755, 244, 180, 30));
        label_dischargeCurrent4->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_chargeCurrent3 = new QLabel(BatteryPage);
        label_chargeCurrent3->setObjectName(QString::fromUtf8("label_chargeCurrent3"));
        label_chargeCurrent3->setGeometry(QRect(556, 215, 200, 30));
        label_chargeCurrent3->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_chargeVoltage = new QLabel(BatteryPage);
        label_chargeVoltage->setObjectName(QString::fromUtf8("label_chargeVoltage"));
        label_chargeVoltage->setGeometry(QRect(0, 128, 170, 30));
        label_car2No = new QLabel(BatteryPage);
        label_car2No->setObjectName(QString::fromUtf8("label_car2No"));
        label_car2No->setGeometry(QRect(357, 99, 200, 30));
        label_car2No->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_dischargeCurrent = new QLabel(BatteryPage);
        label_dischargeCurrent->setObjectName(QString::fromUtf8("label_dischargeCurrent"));
        label_dischargeCurrent->setGeometry(QRect(0, 244, 170, 30));
        label_vehicleNo = new QLabel(BatteryPage);
        label_vehicleNo->setObjectName(QString::fromUtf8("label_vehicleNo"));
        label_vehicleNo->setGeometry(QRect(0, 99, 170, 30));
        label_car1No = new QLabel(BatteryPage);
        label_car1No->setObjectName(QString::fromUtf8("label_car1No"));
        label_car1No->setGeometry(QRect(169, 99, 190, 30));
        label_car1No->setScaledContents(false);
        label_car1No->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_temperature2 = new QLabel(BatteryPage);
        label_temperature2->setObjectName(QString::fromUtf8("label_temperature2"));
        label_temperature2->setGeometry(QRect(357, 186, 200, 30));
        label_temperature2->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_dischargeVoltage = new QLabel(BatteryPage);
        label_dischargeVoltage->setObjectName(QString::fromUtf8("label_dischargeVoltage"));
        label_dischargeVoltage->setGeometry(QRect(0, 157, 170, 30));
        label_temperature3 = new QLabel(BatteryPage);
        label_temperature3->setObjectName(QString::fromUtf8("label_temperature3"));
        label_temperature3->setGeometry(QRect(556, 186, 200, 30));
        label_temperature3->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_chargeCurrent = new QLabel(BatteryPage);
        label_chargeCurrent->setObjectName(QString::fromUtf8("label_chargeCurrent"));
        label_chargeCurrent->setGeometry(QRect(0, 215, 170, 30));
        label_temperature = new QLabel(BatteryPage);
        label_temperature->setObjectName(QString::fromUtf8("label_temperature"));
        label_temperature->setGeometry(QRect(0, 186, 170, 30));
        label_car4No = new QLabel(BatteryPage);
        label_car4No->setObjectName(QString::fromUtf8("label_car4No"));
        label_car4No->setGeometry(QRect(755, 99, 180, 30));
        label_car4No->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_dischargeCurrent1 = new QLabel(BatteryPage);
        label_dischargeCurrent1->setObjectName(QString::fromUtf8("label_dischargeCurrent1"));
        label_dischargeCurrent1->setGeometry(QRect(169, 244, 190, 30));
        label_dischargeCurrent1->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_temperature1 = new QLabel(BatteryPage);
        label_temperature1->setObjectName(QString::fromUtf8("label_temperature1"));
        label_temperature1->setGeometry(QRect(169, 186, 190, 30));
        label_temperature1->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_chargeCurrent4 = new QLabel(BatteryPage);
        label_chargeCurrent4->setObjectName(QString::fromUtf8("label_chargeCurrent4"));
        label_chargeCurrent4->setGeometry(QRect(755, 215, 180, 30));
        label_chargeCurrent4->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_car3No = new QLabel(BatteryPage);
        label_car3No->setObjectName(QString::fromUtf8("label_car3No"));
        label_car3No->setGeometry(QRect(556, 99, 200, 30));
        label_car3No->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_chargeCurrent2 = new QLabel(BatteryPage);
        label_chargeCurrent2->setObjectName(QString::fromUtf8("label_chargeCurrent2"));
        label_chargeCurrent2->setGeometry(QRect(357, 215, 200, 30));
        label_chargeCurrent2->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_dischargeCurrent2 = new QLabel(BatteryPage);
        label_dischargeCurrent2->setObjectName(QString::fromUtf8("label_dischargeCurrent2"));
        label_dischargeCurrent2->setGeometry(QRect(357, 244, 200, 30));
        label_dischargeCurrent2->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_dischargeCurrent3 = new QLabel(BatteryPage);
        label_dischargeCurrent3->setObjectName(QString::fromUtf8("label_dischargeCurrent3"));
        label_dischargeCurrent3->setGeometry(QRect(556, 244, 200, 30));
        label_dischargeCurrent3->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_dischargeVoltage1 = new QLabel(BatteryPage);
        label_dischargeVoltage1->setObjectName(QString::fromUtf8("label_dischargeVoltage1"));
        label_dischargeVoltage1->setGeometry(QRect(169, 157, 190, 30));
        label_dischargeVoltage1->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_dischargeVoltage2 = new QLabel(BatteryPage);
        label_dischargeVoltage2->setObjectName(QString::fromUtf8("label_dischargeVoltage2"));
        label_dischargeVoltage2->setGeometry(QRect(357, 157, 200, 30));
        label_dischargeVoltage2->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_temperature4 = new QLabel(BatteryPage);
        label_temperature4->setObjectName(QString::fromUtf8("label_temperature4"));
        label_temperature4->setGeometry(QRect(755, 186, 180, 30));
        label_temperature4->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_dischargeVoltage4 = new QLabel(BatteryPage);
        label_dischargeVoltage4->setObjectName(QString::fromUtf8("label_dischargeVoltage4"));
        label_dischargeVoltage4->setGeometry(QRect(755, 157, 180, 30));
        label_dischargeVoltage4->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_lowerVoltage4 = new QLabel(BatteryPage);
        label_lowerVoltage4->setObjectName(QString::fromUtf8("label_lowerVoltage4"));
        label_lowerVoltage4->setGeometry(QRect(755, 301, 180, 30));
        label_lowerVoltage4->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_overTemperature4 = new QLabel(BatteryPage);
        label_overTemperature4->setObjectName(QString::fromUtf8("label_overTemperature4"));
        label_overTemperature4->setGeometry(QRect(755, 330, 180, 30));
        label_overTemperature4->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_lightState = new QLabel(BatteryPage);
        label_lightState->setObjectName(QString::fromUtf8("label_lightState"));
        label_lightState->setGeometry(QRect(0, 388, 170, 30));
        label_lightState3 = new QLabel(BatteryPage);
        label_lightState3->setObjectName(QString::fromUtf8("label_lightState3"));
        label_lightState3->setGeometry(QRect(556, 388, 200, 30));
        label_lightState3->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_overTemperature1 = new QLabel(BatteryPage);
        label_overTemperature1->setObjectName(QString::fromUtf8("label_overTemperature1"));
        label_overTemperature1->setGeometry(QRect(169, 330, 190, 30));
        label_overTemperature1->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_lowerVoltage1 = new QLabel(BatteryPage);
        label_lowerVoltage1->setObjectName(QString::fromUtf8("label_lowerVoltage1"));
        label_lowerVoltage1->setGeometry(QRect(169, 301, 190, 30));
        label_lowerVoltage1->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_lightState4 = new QLabel(BatteryPage);
        label_lightState4->setObjectName(QString::fromUtf8("label_lightState4"));
        label_lightState4->setGeometry(QRect(755, 388, 180, 30));
        label_lightState4->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_overResistance3 = new QLabel(BatteryPage);
        label_overResistance3->setObjectName(QString::fromUtf8("label_overResistance3"));
        label_overResistance3->setGeometry(QRect(556, 359, 200, 30));
        label_overResistance3->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_lightState2 = new QLabel(BatteryPage);
        label_lightState2->setObjectName(QString::fromUtf8("label_lightState2"));
        label_lightState2->setGeometry(QRect(357, 388, 200, 30));
        label_lightState2->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_lightState1 = new QLabel(BatteryPage);
        label_lightState1->setObjectName(QString::fromUtf8("label_lightState1"));
        label_lightState1->setGeometry(QRect(169, 388, 190, 30));
        label_lightState1->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_overVoltage3 = new QLabel(BatteryPage);
        label_overVoltage3->setObjectName(QString::fromUtf8("label_overVoltage3"));
        label_overVoltage3->setGeometry(QRect(556, 273, 200, 30));
        label_overVoltage3->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_overTemperature2 = new QLabel(BatteryPage);
        label_overTemperature2->setObjectName(QString::fromUtf8("label_overTemperature2"));
        label_overTemperature2->setGeometry(QRect(357, 330, 200, 30));
        label_overTemperature2->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_lowerVoltage = new QLabel(BatteryPage);
        label_lowerVoltage->setObjectName(QString::fromUtf8("label_lowerVoltage"));
        label_lowerVoltage->setGeometry(QRect(0, 301, 170, 30));
        label_overTemperature = new QLabel(BatteryPage);
        label_overTemperature->setObjectName(QString::fromUtf8("label_overTemperature"));
        label_overTemperature->setGeometry(QRect(0, 330, 170, 30));
        label_overResistance1 = new QLabel(BatteryPage);
        label_overResistance1->setObjectName(QString::fromUtf8("label_overResistance1"));
        label_overResistance1->setGeometry(QRect(169, 359, 190, 30));
        label_overResistance1->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_overVoltage4 = new QLabel(BatteryPage);
        label_overVoltage4->setObjectName(QString::fromUtf8("label_overVoltage4"));
        label_overVoltage4->setGeometry(QRect(755, 273, 180, 30));
        label_overVoltage4->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_overVoltage = new QLabel(BatteryPage);
        label_overVoltage->setObjectName(QString::fromUtf8("label_overVoltage"));
        label_overVoltage->setGeometry(QRect(0, 273, 170, 30));
        label_overTemperature3 = new QLabel(BatteryPage);
        label_overTemperature3->setObjectName(QString::fromUtf8("label_overTemperature3"));
        label_overTemperature3->setGeometry(QRect(556, 330, 200, 30));
        label_overTemperature3->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_overResistance2 = new QLabel(BatteryPage);
        label_overResistance2->setObjectName(QString::fromUtf8("label_overResistance2"));
        label_overResistance2->setGeometry(QRect(357, 359, 200, 30));
        label_overResistance2->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_overVoltage2 = new QLabel(BatteryPage);
        label_overVoltage2->setObjectName(QString::fromUtf8("label_overVoltage2"));
        label_overVoltage2->setGeometry(QRect(357, 273, 200, 30));
        label_overVoltage2->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_overResistance4 = new QLabel(BatteryPage);
        label_overResistance4->setObjectName(QString::fromUtf8("label_overResistance4"));
        label_overResistance4->setGeometry(QRect(755, 359, 180, 30));
        label_overResistance4->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_lowerVoltage2 = new QLabel(BatteryPage);
        label_lowerVoltage2->setObjectName(QString::fromUtf8("label_lowerVoltage2"));
        label_lowerVoltage2->setGeometry(QRect(357, 301, 200, 30));
        label_lowerVoltage2->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_overVoltage1 = new QLabel(BatteryPage);
        label_overVoltage1->setObjectName(QString::fromUtf8("label_overVoltage1"));
        label_overVoltage1->setGeometry(QRect(169, 273, 190, 30));
        label_overVoltage1->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_lowerVoltage3 = new QLabel(BatteryPage);
        label_lowerVoltage3->setObjectName(QString::fromUtf8("label_lowerVoltage3"));
        label_lowerVoltage3->setGeometry(QRect(556, 301, 200, 30));
        label_lowerVoltage3->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_overResistance = new QLabel(BatteryPage);
        label_overResistance->setObjectName(QString::fromUtf8("label_overResistance"));
        label_overResistance->setGeometry(QRect(0, 359, 170, 30));
        label_overAlarmTemp = new QLabel(BatteryPage);
        label_overAlarmTemp->setObjectName(QString::fromUtf8("label_overAlarmTemp"));
        label_overAlarmTemp->setGeometry(QRect(0, 475, 170, 30));
        label_overAlarmVol = new QLabel(BatteryPage);
        label_overAlarmVol->setObjectName(QString::fromUtf8("label_overAlarmVol"));
        label_overAlarmVol->setGeometry(QRect(0, 417, 170, 30));
        label_overAlarmRes2 = new QLabel(BatteryPage);
        label_overAlarmRes2->setObjectName(QString::fromUtf8("label_overAlarmRes2"));
        label_overAlarmRes2->setGeometry(QRect(357, 504, 200, 30));
        label_overAlarmRes2->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_overAlarmRes3 = new QLabel(BatteryPage);
        label_overAlarmRes3->setObjectName(QString::fromUtf8("label_overAlarmRes3"));
        label_overAlarmRes3->setGeometry(QRect(556, 504, 200, 30));
        label_overAlarmRes3->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_overAlarmVol3 = new QLabel(BatteryPage);
        label_overAlarmVol3->setObjectName(QString::fromUtf8("label_overAlarmVol3"));
        label_overAlarmVol3->setGeometry(QRect(556, 417, 200, 30));
        label_overAlarmVol3->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_overAlarmTemp3 = new QLabel(BatteryPage);
        label_overAlarmTemp3->setObjectName(QString::fromUtf8("label_overAlarmTemp3"));
        label_overAlarmTemp3->setGeometry(QRect(556, 475, 200, 30));
        label_overAlarmTemp3->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_lowerAlarmVol3 = new QLabel(BatteryPage);
        label_lowerAlarmVol3->setObjectName(QString::fromUtf8("label_lowerAlarmVol3"));
        label_lowerAlarmVol3->setGeometry(QRect(556, 446, 200, 30));
        label_lowerAlarmVol3->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_lowerAlarmVol = new QLabel(BatteryPage);
        label_lowerAlarmVol->setObjectName(QString::fromUtf8("label_lowerAlarmVol"));
        label_lowerAlarmVol->setGeometry(QRect(0, 446, 170, 30));
        label_overAlarmVol4_1 = new QLabel(BatteryPage);
        label_overAlarmVol4_1->setObjectName(QString::fromUtf8("label_overAlarmVol4_1"));
        label_overAlarmVol4_1->setGeometry(QRect(755, 417, 90, 30));
        label_overAlarmVol4_1->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_lowerAlarmVol2 = new QLabel(BatteryPage);
        label_lowerAlarmVol2->setObjectName(QString::fromUtf8("label_lowerAlarmVol2"));
        label_lowerAlarmVol2->setGeometry(QRect(357, 446, 200, 30));
        label_lowerAlarmVol2->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_overAlarmVol2 = new QLabel(BatteryPage);
        label_overAlarmVol2->setObjectName(QString::fromUtf8("label_overAlarmVol2"));
        label_overAlarmVol2->setGeometry(QRect(357, 417, 200, 30));
        label_overAlarmVol2->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_overAlarmTemp2 = new QLabel(BatteryPage);
        label_overAlarmTemp2->setObjectName(QString::fromUtf8("label_overAlarmTemp2"));
        label_overAlarmTemp2->setGeometry(QRect(357, 475, 200, 30));
        label_overAlarmTemp2->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_overAlarmVol1_1 = new QLabel(BatteryPage);
        label_overAlarmVol1_1->setObjectName(QString::fromUtf8("label_overAlarmVol1_1"));
        label_overAlarmVol1_1->setGeometry(QRect(169, 417, 95, 30));
        label_overAlarmVol1_1->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_overAlarmRes = new QLabel(BatteryPage);
        label_overAlarmRes->setObjectName(QString::fromUtf8("label_overAlarmRes"));
        label_overAlarmRes->setGeometry(QRect(0, 504, 170, 30));
        label_overAlarmVol1_2 = new QLabel(BatteryPage);
        label_overAlarmVol1_2->setObjectName(QString::fromUtf8("label_overAlarmVol1_2"));
        label_overAlarmVol1_2->setGeometry(QRect(263, 417, 95, 30));
        label_overAlarmVol1_2->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_overAlarmVol4_2 = new QLabel(BatteryPage);
        label_overAlarmVol4_2->setObjectName(QString::fromUtf8("label_overAlarmVol4_2"));
        label_overAlarmVol4_2->setGeometry(QRect(845, 417, 90, 30));
        label_overAlarmVol4_2->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_lowerAlarmVol4_2 = new QLabel(BatteryPage);
        label_lowerAlarmVol4_2->setObjectName(QString::fromUtf8("label_lowerAlarmVol4_2"));
        label_lowerAlarmVol4_2->setGeometry(QRect(845, 446, 90, 30));
        label_lowerAlarmVol4_2->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_lowerAlarmVol4_1 = new QLabel(BatteryPage);
        label_lowerAlarmVol4_1->setObjectName(QString::fromUtf8("label_lowerAlarmVol4_1"));
        label_lowerAlarmVol4_1->setGeometry(QRect(755, 446, 90, 30));
        label_lowerAlarmVol4_1->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_overAlarmTemp4_1 = new QLabel(BatteryPage);
        label_overAlarmTemp4_1->setObjectName(QString::fromUtf8("label_overAlarmTemp4_1"));
        label_overAlarmTemp4_1->setGeometry(QRect(755, 475, 90, 30));
        label_overAlarmTemp4_1->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_overAlarmTemp4_2 = new QLabel(BatteryPage);
        label_overAlarmTemp4_2->setObjectName(QString::fromUtf8("label_overAlarmTemp4_2"));
        label_overAlarmTemp4_2->setGeometry(QRect(845, 475, 90, 30));
        label_overAlarmTemp4_2->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_overAlarmRes4_1 = new QLabel(BatteryPage);
        label_overAlarmRes4_1->setObjectName(QString::fromUtf8("label_overAlarmRes4_1"));
        label_overAlarmRes4_1->setGeometry(QRect(755, 504, 90, 30));
        label_overAlarmRes4_1->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_overAlarmRes4_2 = new QLabel(BatteryPage);
        label_overAlarmRes4_2->setObjectName(QString::fromUtf8("label_overAlarmRes4_2"));
        label_overAlarmRes4_2->setGeometry(QRect(845, 504, 90, 30));
        label_overAlarmRes4_2->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_lowerAlarmVol1_2 = new QLabel(BatteryPage);
        label_lowerAlarmVol1_2->setObjectName(QString::fromUtf8("label_lowerAlarmVol1_2"));
        label_lowerAlarmVol1_2->setGeometry(QRect(263, 446, 95, 30));
        label_lowerAlarmVol1_2->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_lowerAlarmVol1_1 = new QLabel(BatteryPage);
        label_lowerAlarmVol1_1->setObjectName(QString::fromUtf8("label_lowerAlarmVol1_1"));
        label_lowerAlarmVol1_1->setGeometry(QRect(169, 446, 95, 30));
        label_lowerAlarmVol1_1->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_overAlarmTemp1_1 = new QLabel(BatteryPage);
        label_overAlarmTemp1_1->setObjectName(QString::fromUtf8("label_overAlarmTemp1_1"));
        label_overAlarmTemp1_1->setGeometry(QRect(169, 475, 95, 30));
        label_overAlarmTemp1_1->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_overAlarmTemp1_2 = new QLabel(BatteryPage);
        label_overAlarmTemp1_2->setObjectName(QString::fromUtf8("label_overAlarmTemp1_2"));
        label_overAlarmTemp1_2->setGeometry(QRect(263, 475, 95, 30));
        label_overAlarmTemp1_2->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_overAlarmRes1_2 = new QLabel(BatteryPage);
        label_overAlarmRes1_2->setObjectName(QString::fromUtf8("label_overAlarmRes1_2"));
        label_overAlarmRes1_2->setGeometry(QRect(263, 504, 95, 30));
        label_overAlarmRes1_2->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_overAlarmRes1_1 = new QLabel(BatteryPage);
        label_overAlarmRes1_1->setObjectName(QString::fromUtf8("label_overAlarmRes1_1"));
        label_overAlarmRes1_1->setGeometry(QRect(169, 504, 95, 30));
        label_overAlarmRes1_1->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        btn_EmergencyBroadcast = new QPushButton(BatteryPage);
        btn_EmergencyBroadcast->setObjectName(QString::fromUtf8("btn_EmergencyBroadcast"));
        btn_EmergencyBroadcast->setGeometry(QRect(860, 570, 130, 40));

        retranslateUi(BatteryPage);

        QMetaObject::connectSlotsByName(BatteryPage);
    } // setupUi

    void retranslateUi(QWidget *BatteryPage)
    {
        BatteryPage->setWindowTitle(QApplication::translate("BatteryPage", "Form", 0, QApplication::UnicodeUTF8));
        label_chargeVoltage2->setText(QApplication::translate("BatteryPage", "--", 0, QApplication::UnicodeUTF8));
        label_chargeVoltage4->setText(QString());
        label_chargeVoltage3->setText(QApplication::translate("BatteryPage", "--", 0, QApplication::UnicodeUTF8));
        label_chargeVoltage1->setText(QString());
        label_dischargeVoltage3->setText(QApplication::translate("BatteryPage", "--", 0, QApplication::UnicodeUTF8));
        label_chargeCurrent1->setText(QString());
        label_dischargeCurrent4->setText(QString());
        label_chargeCurrent3->setText(QApplication::translate("BatteryPage", "--", 0, QApplication::UnicodeUTF8));
        label_chargeVoltage->setText(QApplication::translate("BatteryPage", "\345\205\205\347\224\265\347\224\265\345\216\213\345\200\274(V)", 0, QApplication::UnicodeUTF8));
        label_car2No->setText(QApplication::translate("BatteryPage", "2", 0, QApplication::UnicodeUTF8));
        label_dischargeCurrent->setText(QApplication::translate("BatteryPage", "\346\224\276\347\224\265\347\224\265\346\265\201\345\200\274(A)", 0, QApplication::UnicodeUTF8));
        label_vehicleNo->setText(QApplication::translate("BatteryPage", "\350\275\246\345\217\267", 0, QApplication::UnicodeUTF8));
        label_car1No->setText(QApplication::translate("BatteryPage", "1", 0, QApplication::UnicodeUTF8));
        label_temperature2->setText(QApplication::translate("BatteryPage", "--", 0, QApplication::UnicodeUTF8));
        label_dischargeVoltage->setText(QApplication::translate("BatteryPage", "\346\224\276\347\224\265\347\224\265\345\216\213\345\200\274(V)", 0, QApplication::UnicodeUTF8));
        label_temperature3->setText(QApplication::translate("BatteryPage", "--", 0, QApplication::UnicodeUTF8));
        label_chargeCurrent->setText(QApplication::translate("BatteryPage", "\345\205\205\347\224\265\347\224\265\346\265\201\345\200\274(A)", 0, QApplication::UnicodeUTF8));
        label_temperature->setText(QApplication::translate("BatteryPage", "\347\256\261\345\206\205\346\270\251\345\272\246\345\200\274(\342\204\203)", 0, QApplication::UnicodeUTF8));
        label_car4No->setText(QApplication::translate("BatteryPage", "4", 0, QApplication::UnicodeUTF8));
        label_dischargeCurrent1->setText(QString());
        label_temperature1->setText(QString());
        label_chargeCurrent4->setText(QString());
        label_car3No->setText(QApplication::translate("BatteryPage", "3", 0, QApplication::UnicodeUTF8));
        label_chargeCurrent2->setText(QApplication::translate("BatteryPage", "--", 0, QApplication::UnicodeUTF8));
        label_dischargeCurrent2->setText(QApplication::translate("BatteryPage", "--", 0, QApplication::UnicodeUTF8));
        label_dischargeCurrent3->setText(QApplication::translate("BatteryPage", "--", 0, QApplication::UnicodeUTF8));
        label_dischargeVoltage1->setText(QString());
        label_dischargeVoltage2->setText(QApplication::translate("BatteryPage", "--", 0, QApplication::UnicodeUTF8));
        label_temperature4->setText(QString());
        label_dischargeVoltage4->setText(QString());
        label_lowerVoltage4->setText(QString());
        label_overTemperature4->setText(QString());
        label_lightState->setText(QApplication::translate("BatteryPage", "\346\212\245\350\255\246\346\214\207\347\244\272\347\201\257\347\212\266\346\200\201", 0, QApplication::UnicodeUTF8));
        label_lightState3->setText(QApplication::translate("BatteryPage", "--", 0, QApplication::UnicodeUTF8));
        label_overTemperature1->setText(QString());
        label_lowerVoltage1->setText(QString());
        label_lightState4->setText(QString());
        label_overResistance3->setText(QApplication::translate("BatteryPage", "--", 0, QApplication::UnicodeUTF8));
        label_lightState2->setText(QApplication::translate("BatteryPage", "--", 0, QApplication::UnicodeUTF8));
        label_lightState1->setText(QString());
        label_overVoltage3->setText(QApplication::translate("BatteryPage", "--", 0, QApplication::UnicodeUTF8));
        label_overTemperature2->setText(QApplication::translate("BatteryPage", "--", 0, QApplication::UnicodeUTF8));
        label_lowerVoltage->setText(QApplication::translate("BatteryPage", "\344\275\216\345\216\213\347\224\265\346\261\240\346\225\260\351\207\217(\344\270\252)", 0, QApplication::UnicodeUTF8));
        label_overTemperature->setText(QApplication::translate("BatteryPage", "\350\266\205\346\270\251\347\224\265\346\261\240\346\225\260\351\207\217(\344\270\252)", 0, QApplication::UnicodeUTF8));
        label_overResistance1->setText(QString());
        label_overVoltage4->setText(QString());
        label_overVoltage->setText(QApplication::translate("BatteryPage", "\350\266\205\345\216\213\347\224\265\346\261\240\346\225\260\351\207\217(\344\270\252)", 0, QApplication::UnicodeUTF8));
        label_overTemperature3->setText(QApplication::translate("BatteryPage", "--", 0, QApplication::UnicodeUTF8));
        label_overResistance2->setText(QApplication::translate("BatteryPage", "--", 0, QApplication::UnicodeUTF8));
        label_overVoltage2->setText(QApplication::translate("BatteryPage", "--", 0, QApplication::UnicodeUTF8));
        label_overResistance4->setText(QString());
        label_lowerVoltage2->setText(QApplication::translate("BatteryPage", "--", 0, QApplication::UnicodeUTF8));
        label_overVoltage1->setText(QString());
        label_lowerVoltage3->setText(QApplication::translate("BatteryPage", "--", 0, QApplication::UnicodeUTF8));
        label_overResistance->setText(QApplication::translate("BatteryPage", "\350\266\205\345\206\205\351\230\273\347\224\265\346\261\240\346\225\260\351\207\217(\344\270\252)", 0, QApplication::UnicodeUTF8));
        label_overAlarmTemp->setText(QApplication::translate("BatteryPage", "\350\266\205\346\270\251\346\212\245\350\255\246\347\224\265\345\216\213\345\200\274(mV)", 0, QApplication::UnicodeUTF8));
        label_overAlarmVol->setText(QApplication::translate("BatteryPage", "\350\266\205\345\216\213\346\212\245\350\255\246\347\224\265\345\216\213\345\200\274(mV)", 0, QApplication::UnicodeUTF8));
        label_overAlarmRes2->setText(QApplication::translate("BatteryPage", "--", 0, QApplication::UnicodeUTF8));
        label_overAlarmRes3->setText(QApplication::translate("BatteryPage", "--", 0, QApplication::UnicodeUTF8));
        label_overAlarmVol3->setText(QApplication::translate("BatteryPage", "--", 0, QApplication::UnicodeUTF8));
        label_overAlarmTemp3->setText(QApplication::translate("BatteryPage", "--", 0, QApplication::UnicodeUTF8));
        label_lowerAlarmVol3->setText(QApplication::translate("BatteryPage", "--", 0, QApplication::UnicodeUTF8));
        label_lowerAlarmVol->setText(QApplication::translate("BatteryPage", "\344\275\216\345\216\213\346\212\245\350\255\246\347\224\265\345\216\213\345\200\274(mV)", 0, QApplication::UnicodeUTF8));
        label_overAlarmVol4_1->setText(QString());
        label_lowerAlarmVol2->setText(QApplication::translate("BatteryPage", "--", 0, QApplication::UnicodeUTF8));
        label_overAlarmVol2->setText(QApplication::translate("BatteryPage", "--", 0, QApplication::UnicodeUTF8));
        label_overAlarmTemp2->setText(QApplication::translate("BatteryPage", "--", 0, QApplication::UnicodeUTF8));
        label_overAlarmVol1_1->setText(QString());
        label_overAlarmRes->setText(QApplication::translate("BatteryPage", "\350\266\205\345\206\205\351\230\273\346\212\245\350\255\246\347\224\265\345\216\213\345\200\274(mV)", 0, QApplication::UnicodeUTF8));
        label_overAlarmVol1_2->setText(QString());
        label_overAlarmVol4_2->setText(QString());
        label_lowerAlarmVol4_2->setText(QString());
        label_lowerAlarmVol4_1->setText(QString());
        label_overAlarmTemp4_1->setText(QString());
        label_overAlarmTemp4_2->setText(QString());
        label_overAlarmRes4_1->setText(QString());
        label_overAlarmRes4_2->setText(QString());
        label_lowerAlarmVol1_2->setText(QString());
        label_lowerAlarmVol1_1->setText(QString());
        label_overAlarmTemp1_1->setText(QString());
        label_overAlarmTemp1_2->setText(QString());
        label_overAlarmRes1_2->setText(QString());
        label_overAlarmRes1_1->setText(QString());
        btn_EmergencyBroadcast->setText(QApplication::translate("BatteryPage", "\347\264\247\346\200\245\345\271\277\346\222\255", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BatteryPage: public Ui_BatteryPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BATTERYPAGE_H
