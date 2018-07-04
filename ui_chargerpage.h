/********************************************************************************
** Form generated from reading UI file 'chargerpage.ui'
**
** Created: Thu Jan 11 11:16:18 2018
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHARGERPAGE_H
#define UI_CHARGERPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChargerPage
{
public:
    QLabel *label_batteryVoltage;
    QLabel *label_batteryCurrent3;
    QLabel *label_batteryCurrent;
    QLabel *label_batteryCurrent1;
    QLabel *label_vehicleNo;
    QLabel *label_batteryState4;
    QLabel *label_batteryVoltage3;
    QLabel *label_batteryCurrent4;
    QLabel *label_batteryTemp4;
    QLabel *label_batteryState;
    QLabel *label_car4No;
    QLabel *label_batteryState1;
    QLabel *label_batteryTemp1;
    QLabel *label_car3No;
    QLabel *label_netVoltage2;
    QLabel *label_batteryVoltage2;
    QLabel *label_netVoltage4;
    QLabel *label_batteryState2;
    QLabel *label_batteryCurrent2;
    QLabel *label_batteryTemp;
    QLabel *label_netVoltage3;
    QLabel *label_batteryState3;
    QLabel *label_car2No;
    QLabel *label_batteryVoltage4;
    QLabel *label_batteryTemp2;
    QLabel *label_batteryTemp3;
    QLabel *label_netVoltage;
    QLabel *label_batteryVoltage1;
    QLabel *label_netVoltage1;
    QLabel *label_car1No;
    QLabel *label_netCurrent1;
    QLabel *label_netCurrent2;
    QLabel *label_netCurrent4;
    QLabel *label_supportVoltage3;
    QLabel *label_supportVoltage2;
    QLabel *label_supportVoltage;
    QLabel *label_netCurrent3;
    QLabel *label_supportVoltage4;
    QLabel *label_supportVoltage1;
    QLabel *label_netCurrent;
    QPushButton *btn_reset1;
    QPushButton *btn_cut1;
    QLabel *label_cut;
    QLabel *label_reset2;
    QLabel *label_reset1;
    QLabel *label_cut4;
    QLabel *label_cut2;
    QLabel *label_reset3;
    QLabel *label_cut1;
    QLabel *label_cut3;
    QLabel *label_reset;
    QLabel *label_reset4;
    QPushButton *btn_reset2;
    QPushButton *btn_cut2;
    QPushButton *btn_EmergencyBroadcast;

    void setupUi(QWidget *ChargerPage)
    {
        if (ChargerPage->objectName().isEmpty())
            ChargerPage->setObjectName(QString::fromUtf8("ChargerPage"));
        ChargerPage->resize(1024, 618);
        ChargerPage->setStyleSheet(QString::fromUtf8("QLabel\n"
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
"QPushButton\n"
"{\n"
"	font: 20px, \"SimHei\";\n"
"    color: black;\n"
"	background-color: rgb(250, 250, 250);\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QPushButton:disabled\n"
"{\n"
"		border-radius:5px;\n"
"	font: 20px, \"SimHei\";\n"
"    color: grey;\n"
"	background-color: rgb(221,221,221);\n"
"}"));
        label_batteryVoltage = new QLabel(ChargerPage);
        label_batteryVoltage->setObjectName(QString::fromUtf8("label_batteryVoltage"));
        label_batteryVoltage->setGeometry(QRect(10, 244, 130, 40));
        label_batteryVoltage->setStyleSheet(QString::fromUtf8("	font: 15px, \"SimHei\";	"));
        label_batteryCurrent3 = new QLabel(ChargerPage);
        label_batteryCurrent3->setObjectName(QString::fromUtf8("label_batteryCurrent3"));
        label_batteryCurrent3->setGeometry(QRect(536, 283, 210, 40));
        label_batteryCurrent3->setAlignment(Qt::AlignCenter);
        label_batteryCurrent = new QLabel(ChargerPage);
        label_batteryCurrent->setObjectName(QString::fromUtf8("label_batteryCurrent"));
        label_batteryCurrent->setGeometry(QRect(10, 283, 130, 40));
        label_batteryCurrent->setStyleSheet(QString::fromUtf8("	font: 15px, \"SimHei\";	"));
        label_batteryCurrent1 = new QLabel(ChargerPage);
        label_batteryCurrent1->setObjectName(QString::fromUtf8("label_batteryCurrent1"));
        label_batteryCurrent1->setGeometry(QRect(139, 283, 190, 40));
        label_batteryCurrent1->setAlignment(Qt::AlignCenter);
        label_vehicleNo = new QLabel(ChargerPage);
        label_vehicleNo->setObjectName(QString::fromUtf8("label_vehicleNo"));
        label_vehicleNo->setGeometry(QRect(10, 127, 130, 40));
        label_batteryState4 = new QLabel(ChargerPage);
        label_batteryState4->setObjectName(QString::fromUtf8("label_batteryState4"));
        label_batteryState4->setGeometry(QRect(745, 166, 180, 40));
        label_batteryState4->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_batteryVoltage3 = new QLabel(ChargerPage);
        label_batteryVoltage3->setObjectName(QString::fromUtf8("label_batteryVoltage3"));
        label_batteryVoltage3->setGeometry(QRect(536, 244, 210, 40));
        label_batteryVoltage3->setAlignment(Qt::AlignCenter);
        label_batteryCurrent4 = new QLabel(ChargerPage);
        label_batteryCurrent4->setObjectName(QString::fromUtf8("label_batteryCurrent4"));
        label_batteryCurrent4->setGeometry(QRect(745, 283, 180, 40));
        label_batteryCurrent4->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_batteryTemp4 = new QLabel(ChargerPage);
        label_batteryTemp4->setObjectName(QString::fromUtf8("label_batteryTemp4"));
        label_batteryTemp4->setGeometry(QRect(745, 205, 180, 40));
        label_batteryTemp4->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_batteryState = new QLabel(ChargerPage);
        label_batteryState->setObjectName(QString::fromUtf8("label_batteryState"));
        label_batteryState->setGeometry(QRect(10, 166, 130, 40));
        label_batteryState->setStyleSheet(QString::fromUtf8("	font: 15px, \"SimHei\";	"));
        label_car4No = new QLabel(ChargerPage);
        label_car4No->setObjectName(QString::fromUtf8("label_car4No"));
        label_car4No->setGeometry(QRect(745, 127, 180, 40));
        label_car4No->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_batteryState1 = new QLabel(ChargerPage);
        label_batteryState1->setObjectName(QString::fromUtf8("label_batteryState1"));
        label_batteryState1->setGeometry(QRect(139, 166, 190, 40));
        label_batteryState1->setAlignment(Qt::AlignCenter);
        label_batteryTemp1 = new QLabel(ChargerPage);
        label_batteryTemp1->setObjectName(QString::fromUtf8("label_batteryTemp1"));
        label_batteryTemp1->setGeometry(QRect(139, 205, 190, 40));
        label_batteryTemp1->setAlignment(Qt::AlignCenter);
        label_car3No = new QLabel(ChargerPage);
        label_car3No->setObjectName(QString::fromUtf8("label_car3No"));
        label_car3No->setGeometry(QRect(536, 127, 210, 40));
        label_car3No->setAlignment(Qt::AlignCenter);
        label_netVoltage2 = new QLabel(ChargerPage);
        label_netVoltage2->setObjectName(QString::fromUtf8("label_netVoltage2"));
        label_netVoltage2->setGeometry(QRect(328, 322, 209, 40));
        label_netVoltage2->setAlignment(Qt::AlignCenter);
        label_batteryVoltage2 = new QLabel(ChargerPage);
        label_batteryVoltage2->setObjectName(QString::fromUtf8("label_batteryVoltage2"));
        label_batteryVoltage2->setGeometry(QRect(328, 244, 209, 40));
        label_batteryVoltage2->setAlignment(Qt::AlignCenter);
        label_netVoltage4 = new QLabel(ChargerPage);
        label_netVoltage4->setObjectName(QString::fromUtf8("label_netVoltage4"));
        label_netVoltage4->setGeometry(QRect(745, 322, 180, 40));
        label_netVoltage4->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_batteryState2 = new QLabel(ChargerPage);
        label_batteryState2->setObjectName(QString::fromUtf8("label_batteryState2"));
        label_batteryState2->setGeometry(QRect(328, 166, 209, 40));
        label_batteryState2->setAlignment(Qt::AlignCenter);
        label_batteryCurrent2 = new QLabel(ChargerPage);
        label_batteryCurrent2->setObjectName(QString::fromUtf8("label_batteryCurrent2"));
        label_batteryCurrent2->setGeometry(QRect(328, 283, 209, 40));
        label_batteryCurrent2->setAlignment(Qt::AlignCenter);
        label_batteryTemp = new QLabel(ChargerPage);
        label_batteryTemp->setObjectName(QString::fromUtf8("label_batteryTemp"));
        label_batteryTemp->setGeometry(QRect(10, 205, 130, 40));
        label_batteryTemp->setStyleSheet(QString::fromUtf8("	font: 15px, \"SimHei\";	"));
        label_netVoltage3 = new QLabel(ChargerPage);
        label_netVoltage3->setObjectName(QString::fromUtf8("label_netVoltage3"));
        label_netVoltage3->setGeometry(QRect(536, 322, 210, 40));
        label_netVoltage3->setAlignment(Qt::AlignCenter);
        label_batteryState3 = new QLabel(ChargerPage);
        label_batteryState3->setObjectName(QString::fromUtf8("label_batteryState3"));
        label_batteryState3->setGeometry(QRect(536, 166, 210, 40));
        label_batteryState3->setAlignment(Qt::AlignCenter);
        label_car2No = new QLabel(ChargerPage);
        label_car2No->setObjectName(QString::fromUtf8("label_car2No"));
        label_car2No->setGeometry(QRect(328, 127, 209, 40));
        label_car2No->setAlignment(Qt::AlignCenter);
        label_batteryVoltage4 = new QLabel(ChargerPage);
        label_batteryVoltage4->setObjectName(QString::fromUtf8("label_batteryVoltage4"));
        label_batteryVoltage4->setGeometry(QRect(745, 244, 180, 40));
        label_batteryVoltage4->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_batteryTemp2 = new QLabel(ChargerPage);
        label_batteryTemp2->setObjectName(QString::fromUtf8("label_batteryTemp2"));
        label_batteryTemp2->setGeometry(QRect(328, 205, 209, 40));
        label_batteryTemp2->setAlignment(Qt::AlignCenter);
        label_batteryTemp3 = new QLabel(ChargerPage);
        label_batteryTemp3->setObjectName(QString::fromUtf8("label_batteryTemp3"));
        label_batteryTemp3->setGeometry(QRect(536, 205, 210, 40));
        label_batteryTemp3->setAlignment(Qt::AlignCenter);
        label_netVoltage = new QLabel(ChargerPage);
        label_netVoltage->setObjectName(QString::fromUtf8("label_netVoltage"));
        label_netVoltage->setGeometry(QRect(10, 322, 130, 40));
        label_netVoltage->setStyleSheet(QString::fromUtf8("	font: 15px, \"SimHei\";	"));
        label_batteryVoltage1 = new QLabel(ChargerPage);
        label_batteryVoltage1->setObjectName(QString::fromUtf8("label_batteryVoltage1"));
        label_batteryVoltage1->setGeometry(QRect(139, 244, 190, 40));
        label_batteryVoltage1->setAlignment(Qt::AlignCenter);
        label_netVoltage1 = new QLabel(ChargerPage);
        label_netVoltage1->setObjectName(QString::fromUtf8("label_netVoltage1"));
        label_netVoltage1->setGeometry(QRect(139, 322, 190, 40));
        label_netVoltage1->setAlignment(Qt::AlignCenter);
        label_car1No = new QLabel(ChargerPage);
        label_car1No->setObjectName(QString::fromUtf8("label_car1No"));
        label_car1No->setGeometry(QRect(139, 127, 190, 40));
        label_car1No->setScaledContents(false);
        label_car1No->setAlignment(Qt::AlignCenter);
        label_netCurrent1 = new QLabel(ChargerPage);
        label_netCurrent1->setObjectName(QString::fromUtf8("label_netCurrent1"));
        label_netCurrent1->setGeometry(QRect(139, 400, 190, 40));
        label_netCurrent1->setAlignment(Qt::AlignCenter);
        label_netCurrent2 = new QLabel(ChargerPage);
        label_netCurrent2->setObjectName(QString::fromUtf8("label_netCurrent2"));
        label_netCurrent2->setGeometry(QRect(328, 400, 209, 40));
        label_netCurrent2->setAlignment(Qt::AlignCenter);
        label_netCurrent4 = new QLabel(ChargerPage);
        label_netCurrent4->setObjectName(QString::fromUtf8("label_netCurrent4"));
        label_netCurrent4->setGeometry(QRect(745, 400, 180, 40));
        label_netCurrent4->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_supportVoltage3 = new QLabel(ChargerPage);
        label_supportVoltage3->setObjectName(QString::fromUtf8("label_supportVoltage3"));
        label_supportVoltage3->setGeometry(QRect(536, 361, 210, 40));
        label_supportVoltage3->setAlignment(Qt::AlignCenter);
        label_supportVoltage2 = new QLabel(ChargerPage);
        label_supportVoltage2->setObjectName(QString::fromUtf8("label_supportVoltage2"));
        label_supportVoltage2->setGeometry(QRect(328, 361, 209, 40));
        label_supportVoltage2->setAlignment(Qt::AlignCenter);
        label_supportVoltage = new QLabel(ChargerPage);
        label_supportVoltage->setObjectName(QString::fromUtf8("label_supportVoltage"));
        label_supportVoltage->setGeometry(QRect(10, 361, 130, 40));
        label_supportVoltage->setStyleSheet(QString::fromUtf8("	font: 15px, \"SimHei\";	"));
        label_netCurrent3 = new QLabel(ChargerPage);
        label_netCurrent3->setObjectName(QString::fromUtf8("label_netCurrent3"));
        label_netCurrent3->setGeometry(QRect(536, 400, 210, 40));
        label_netCurrent3->setAlignment(Qt::AlignCenter);
        label_supportVoltage4 = new QLabel(ChargerPage);
        label_supportVoltage4->setObjectName(QString::fromUtf8("label_supportVoltage4"));
        label_supportVoltage4->setGeometry(QRect(745, 361, 180, 40));
        label_supportVoltage4->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_supportVoltage1 = new QLabel(ChargerPage);
        label_supportVoltage1->setObjectName(QString::fromUtf8("label_supportVoltage1"));
        label_supportVoltage1->setGeometry(QRect(139, 361, 190, 40));
        label_supportVoltage1->setAlignment(Qt::AlignCenter);
        label_netCurrent = new QLabel(ChargerPage);
        label_netCurrent->setObjectName(QString::fromUtf8("label_netCurrent"));
        label_netCurrent->setGeometry(QRect(10, 400, 130, 40));
        label_netCurrent->setStyleSheet(QString::fromUtf8("	font: 15px, \"SimHei\";	"));
        btn_reset1 = new QPushButton(ChargerPage);
        btn_reset1->setObjectName(QString::fromUtf8("btn_reset1"));
        btn_reset1->setGeometry(QRect(180, 440, 98, 38));
        btn_cut1 = new QPushButton(ChargerPage);
        btn_cut1->setObjectName(QString::fromUtf8("btn_cut1"));
        btn_cut1->setGeometry(QRect(180, 480, 98, 38));
        btn_cut1->setCheckable(false);
        label_cut = new QLabel(ChargerPage);
        label_cut->setObjectName(QString::fromUtf8("label_cut"));
        label_cut->setGeometry(QRect(10, 478, 130, 40));
        label_cut->setStyleSheet(QString::fromUtf8("	font: 15px, \"SimHei\";	"));
        label_reset2 = new QLabel(ChargerPage);
        label_reset2->setObjectName(QString::fromUtf8("label_reset2"));
        label_reset2->setGeometry(QRect(328, 439, 209, 40));
        label_reset2->setAlignment(Qt::AlignCenter);
        label_reset1 = new QLabel(ChargerPage);
        label_reset1->setObjectName(QString::fromUtf8("label_reset1"));
        label_reset1->setGeometry(QRect(139, 439, 190, 40));
        label_reset1->setAlignment(Qt::AlignCenter);
        label_cut4 = new QLabel(ChargerPage);
        label_cut4->setObjectName(QString::fromUtf8("label_cut4"));
        label_cut4->setGeometry(QRect(745, 478, 180, 40));
        label_cut2 = new QLabel(ChargerPage);
        label_cut2->setObjectName(QString::fromUtf8("label_cut2"));
        label_cut2->setGeometry(QRect(328, 478, 209, 40));
        label_cut2->setAlignment(Qt::AlignCenter);
        label_reset3 = new QLabel(ChargerPage);
        label_reset3->setObjectName(QString::fromUtf8("label_reset3"));
        label_reset3->setGeometry(QRect(536, 439, 210, 40));
        label_reset3->setAlignment(Qt::AlignCenter);
        label_cut1 = new QLabel(ChargerPage);
        label_cut1->setObjectName(QString::fromUtf8("label_cut1"));
        label_cut1->setGeometry(QRect(139, 478, 190, 40));
        label_cut1->setAlignment(Qt::AlignCenter);
        label_cut3 = new QLabel(ChargerPage);
        label_cut3->setObjectName(QString::fromUtf8("label_cut3"));
        label_cut3->setGeometry(QRect(536, 478, 210, 40));
        label_cut3->setAlignment(Qt::AlignCenter);
        label_reset = new QLabel(ChargerPage);
        label_reset->setObjectName(QString::fromUtf8("label_reset"));
        label_reset->setGeometry(QRect(10, 439, 130, 40));
        label_reset->setStyleSheet(QString::fromUtf8("	font: 15px, \"SimHei\";	"));
        label_reset4 = new QLabel(ChargerPage);
        label_reset4->setObjectName(QString::fromUtf8("label_reset4"));
        label_reset4->setGeometry(QRect(745, 439, 180, 40));
        btn_reset2 = new QPushButton(ChargerPage);
        btn_reset2->setObjectName(QString::fromUtf8("btn_reset2"));
        btn_reset2->setGeometry(QRect(790, 440, 98, 38));
        btn_cut2 = new QPushButton(ChargerPage);
        btn_cut2->setObjectName(QString::fromUtf8("btn_cut2"));
        btn_cut2->setGeometry(QRect(790, 480, 98, 38));
        btn_cut2->setCheckable(false);
        btn_EmergencyBroadcast = new QPushButton(ChargerPage);
        btn_EmergencyBroadcast->setObjectName(QString::fromUtf8("btn_EmergencyBroadcast"));
        btn_EmergencyBroadcast->setGeometry(QRect(860, 560, 130, 40));
        label_reset1->raise();
        label_cut1->raise();
        btn_cut1->raise();
        label_batteryVoltage->raise();
        label_batteryCurrent3->raise();
        label_batteryCurrent->raise();
        label_batteryCurrent1->raise();
        label_vehicleNo->raise();
        label_batteryState4->raise();
        label_batteryVoltage3->raise();
        label_batteryCurrent4->raise();
        label_batteryTemp4->raise();
        label_batteryState->raise();
        label_car4No->raise();
        label_batteryState1->raise();
        label_batteryTemp1->raise();
        label_car3No->raise();
        label_netVoltage2->raise();
        label_batteryVoltage2->raise();
        label_netVoltage4->raise();
        label_batteryState2->raise();
        label_batteryCurrent2->raise();
        label_batteryTemp->raise();
        label_netVoltage3->raise();
        label_batteryState3->raise();
        label_car2No->raise();
        label_batteryVoltage4->raise();
        label_batteryTemp2->raise();
        label_batteryTemp3->raise();
        label_netVoltage->raise();
        label_batteryVoltage1->raise();
        label_netVoltage1->raise();
        label_car1No->raise();
        label_netCurrent1->raise();
        label_netCurrent2->raise();
        label_netCurrent4->raise();
        label_supportVoltage3->raise();
        label_supportVoltage2->raise();
        label_supportVoltage->raise();
        label_netCurrent3->raise();
        label_supportVoltage4->raise();
        label_supportVoltage1->raise();
        label_netCurrent->raise();
        btn_reset1->raise();
        label_cut->raise();
        label_reset2->raise();
        label_cut4->raise();
        label_cut2->raise();
        label_reset3->raise();
        label_cut3->raise();
        label_reset->raise();
        label_reset4->raise();
        btn_reset2->raise();
        btn_EmergencyBroadcast->raise();
        btn_cut2->raise();

        retranslateUi(ChargerPage);

        QMetaObject::connectSlotsByName(ChargerPage);
    } // setupUi

    void retranslateUi(QWidget *ChargerPage)
    {
        ChargerPage->setWindowTitle(QApplication::translate("ChargerPage", "Form", 0, QApplication::UnicodeUTF8));
        label_batteryVoltage->setText(QApplication::translate("ChargerPage", "\350\223\204\347\224\265\346\261\240\347\224\265\345\216\213(V)", 0, QApplication::UnicodeUTF8));
        label_batteryCurrent3->setText(QApplication::translate("ChargerPage", "--", 0, QApplication::UnicodeUTF8));
        label_batteryCurrent->setText(QApplication::translate("ChargerPage", "\350\223\204\347\224\265\346\261\240\347\224\265\346\265\201(A)", 0, QApplication::UnicodeUTF8));
        label_batteryCurrent1->setText(QString());
        label_vehicleNo->setText(QApplication::translate("ChargerPage", "\350\275\246\345\217\267", 0, QApplication::UnicodeUTF8));
        label_batteryState4->setText(QString());
        label_batteryVoltage3->setText(QApplication::translate("ChargerPage", "--", 0, QApplication::UnicodeUTF8));
        label_batteryCurrent4->setText(QString());
        label_batteryTemp4->setText(QString());
        label_batteryState->setText(QApplication::translate("ChargerPage", "\345\205\205\347\224\265\346\234\272\347\212\266\346\200\201", 0, QApplication::UnicodeUTF8));
        label_car4No->setText(QApplication::translate("ChargerPage", "4", 0, QApplication::UnicodeUTF8));
        label_batteryState1->setText(QString());
        label_batteryTemp1->setText(QString());
        label_car3No->setText(QApplication::translate("ChargerPage", "3", 0, QApplication::UnicodeUTF8));
        label_netVoltage2->setText(QApplication::translate("ChargerPage", "--", 0, QApplication::UnicodeUTF8));
        label_batteryVoltage2->setText(QApplication::translate("ChargerPage", "--", 0, QApplication::UnicodeUTF8));
        label_netVoltage4->setText(QString());
        label_batteryState2->setText(QApplication::translate("ChargerPage", "--", 0, QApplication::UnicodeUTF8));
        label_batteryCurrent2->setText(QApplication::translate("ChargerPage", "--", 0, QApplication::UnicodeUTF8));
        label_batteryTemp->setText(QApplication::translate("ChargerPage", "\350\223\204\347\224\265\346\261\240\346\270\251\345\272\246(\342\204\203)", 0, QApplication::UnicodeUTF8));
        label_netVoltage3->setText(QApplication::translate("ChargerPage", "--", 0, QApplication::UnicodeUTF8));
        label_batteryState3->setText(QApplication::translate("ChargerPage", "--", 0, QApplication::UnicodeUTF8));
        label_car2No->setText(QApplication::translate("ChargerPage", "2", 0, QApplication::UnicodeUTF8));
        label_batteryVoltage4->setText(QString());
        label_batteryTemp2->setText(QApplication::translate("ChargerPage", "--", 0, QApplication::UnicodeUTF8));
        label_batteryTemp3->setText(QApplication::translate("ChargerPage", "--", 0, QApplication::UnicodeUTF8));
        label_netVoltage->setText(QApplication::translate("ChargerPage", "\347\224\265\347\275\221\347\224\265\345\216\213(V)", 0, QApplication::UnicodeUTF8));
        label_batteryVoltage1->setText(QString());
        label_netVoltage1->setText(QString());
        label_car1No->setText(QApplication::translate("ChargerPage", "1", 0, QApplication::UnicodeUTF8));
        label_netCurrent1->setText(QString());
        label_netCurrent2->setText(QApplication::translate("ChargerPage", "--", 0, QApplication::UnicodeUTF8));
        label_netCurrent4->setText(QString());
        label_supportVoltage3->setText(QApplication::translate("ChargerPage", "--", 0, QApplication::UnicodeUTF8));
        label_supportVoltage2->setText(QApplication::translate("ChargerPage", "--", 0, QApplication::UnicodeUTF8));
        label_supportVoltage->setText(QApplication::translate("ChargerPage", "\346\224\257\346\222\221\347\224\265\345\256\271\347\224\265\345\216\213(V)", 0, QApplication::UnicodeUTF8));
        label_netCurrent3->setText(QApplication::translate("ChargerPage", "--", 0, QApplication::UnicodeUTF8));
        label_supportVoltage4->setText(QString());
        label_supportVoltage1->setText(QString());
        label_netCurrent->setText(QApplication::translate("ChargerPage", "\347\224\265\347\275\221\344\276\247\347\224\265\346\265\201(A)", 0, QApplication::UnicodeUTF8));
        btn_reset1->setText(QApplication::translate("ChargerPage", "\345\244\215\344\275\215", 0, QApplication::UnicodeUTF8));
        btn_cut1->setText(QApplication::translate("ChargerPage", "\345\210\207\351\231\244", 0, QApplication::UnicodeUTF8));
        label_cut->setText(QApplication::translate("ChargerPage", "\345\210\207\351\231\244", 0, QApplication::UnicodeUTF8));
        label_reset2->setText(QApplication::translate("ChargerPage", "--", 0, QApplication::UnicodeUTF8));
        label_reset1->setText(QString());
        label_cut4->setText(QString());
        label_cut2->setText(QApplication::translate("ChargerPage", "--", 0, QApplication::UnicodeUTF8));
        label_reset3->setText(QApplication::translate("ChargerPage", "--", 0, QApplication::UnicodeUTF8));
        label_cut1->setText(QString());
        label_cut3->setText(QApplication::translate("ChargerPage", "--", 0, QApplication::UnicodeUTF8));
        label_reset->setText(QApplication::translate("ChargerPage", "\346\225\205\351\232\234\345\244\215\344\275\215", 0, QApplication::UnicodeUTF8));
        label_reset4->setText(QString());
        btn_reset2->setText(QApplication::translate("ChargerPage", "\345\244\215\344\275\215", 0, QApplication::UnicodeUTF8));
        btn_cut2->setText(QApplication::translate("ChargerPage", "\345\210\207\351\231\244", 0, QApplication::UnicodeUTF8));
        btn_EmergencyBroadcast->setText(QApplication::translate("ChargerPage", "\347\264\247\346\200\245\345\271\277\346\222\255", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ChargerPage: public Ui_ChargerPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHARGERPAGE_H
