/********************************************************************************
** Form generated from reading UI file 'mainpage.ui'
**
** Created: Thu Jan 11 11:16:18 2018
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINPAGE_H
#define UI_MAINPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainPage
{
public:
    QPushButton *btn_EmergencyBroadcast;
    QLabel *label_washing;
    QLabel *label_BHBBreak;
    QLabel *label_Broadcast;
    QLabel *label_totalKilometers;
    QLabel *label_totalHours;
    QLabel *label_EmergencyBrake;
    QLabel *label_idleMp1;
    QLabel *label_idleMp2;
    QLabel *label_slideMP2;
    QLabel *label_slideMP1;
    QLabel *label_slideTC1;
    QLabel *label_slideTC2;

    void setupUi(QWidget *MainPage)
    {
        if (MainPage->objectName().isEmpty())
            MainPage->setObjectName(QString::fromUtf8("MainPage"));
        MainPage->resize(1024, 618);
        MainPage->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	color: white;\n"
"	border: 2px groove, gray;\n"
"    border-color: gray;\n"
"	font: 20px, \"SimHei\";\n"
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
        btn_EmergencyBroadcast = new QPushButton(MainPage);
        btn_EmergencyBroadcast->setObjectName(QString::fromUtf8("btn_EmergencyBroadcast"));
        btn_EmergencyBroadcast->setGeometry(QRect(860, 560, 130, 40));
        label_washing = new QLabel(MainPage);
        label_washing->setObjectName(QString::fromUtf8("label_washing"));
        label_washing->setGeometry(QRect(900, 360, 100, 90));
        label_washing->setStyleSheet(QString::fromUtf8("border-radius:15px;\n"
"font: 17px, \"SimHei\";\n"
"color:black;\n"
"background-color: rgb(255, 255, 0);\n"
""));
        label_washing->setAlignment(Qt::AlignCenter);
        label_BHBBreak = new QLabel(MainPage);
        label_BHBBreak->setObjectName(QString::fromUtf8("label_BHBBreak"));
        label_BHBBreak->setGeometry(QRect(900, 190, 100, 90));
        label_BHBBreak->setStyleSheet(QString::fromUtf8("border-radius:15px;\n"
"font:17px, \"SimHei\";\n"
"color:black;\n"
"background-color: rgb(255, 255, 0);\n"
""));
        label_BHBBreak->setAlignment(Qt::AlignCenter);
        label_Broadcast = new QLabel(MainPage);
        label_Broadcast->setObjectName(QString::fromUtf8("label_Broadcast"));
        label_Broadcast->setGeometry(QRect(900, 90, 100, 90));
        label_Broadcast->setStyleSheet(QString::fromUtf8("border-radius:15px;\n"
"background-color: rgb(85, 255, 255);\n"
"font:17px, \"SimHei\";\n"
"color:black;\n"
""));
        label_Broadcast->setAlignment(Qt::AlignCenter);
        label_totalKilometers = new QLabel(MainPage);
        label_totalKilometers->setObjectName(QString::fromUtf8("label_totalKilometers"));
        label_totalKilometers->setGeometry(QRect(280, 580, 141, 31));
        label_totalKilometers->setStyleSheet(QString::fromUtf8("border-color:black;"));
        label_totalHours = new QLabel(MainPage);
        label_totalHours->setObjectName(QString::fromUtf8("label_totalHours"));
        label_totalHours->setGeometry(QRect(590, 580, 141, 31));
        label_totalHours->setStyleSheet(QString::fromUtf8("border-color:black;"));
        label_EmergencyBrake = new QLabel(MainPage);
        label_EmergencyBrake->setObjectName(QString::fromUtf8("label_EmergencyBrake"));
        label_EmergencyBrake->setGeometry(QRect(900, 290, 100, 60));
        label_EmergencyBrake->setStyleSheet(QString::fromUtf8("border-radius:15px;\n"
"background-color: rgb(255, 0, 0);\n"
"font:17px, \"SimHei\";\n"
"color:black;\n"
""));
        label_EmergencyBrake->setAlignment(Qt::AlignCenter);
        label_idleMp1 = new QLabel(MainPage);
        label_idleMp1->setObjectName(QString::fromUtf8("label_idleMp1"));
        label_idleMp1->setGeometry(QRect(360, 130, 100, 40));
        label_idleMp1->setStyleSheet(QString::fromUtf8("font:20px, \"SimHei\";\n"
"color: rgb(255, 170, 0);\n"
""));
        label_idleMp1->setAlignment(Qt::AlignCenter);
        label_idleMp2 = new QLabel(MainPage);
        label_idleMp2->setObjectName(QString::fromUtf8("label_idleMp2"));
        label_idleMp2->setGeometry(QRect(560, 130, 100, 40));
        label_idleMp2->setStyleSheet(QString::fromUtf8("font:20px, \"SimHei\";\n"
"color: rgb(255, 170, 0);\n"
""));
        label_idleMp2->setAlignment(Qt::AlignCenter);
        label_slideMP2 = new QLabel(MainPage);
        label_slideMP2->setObjectName(QString::fromUtf8("label_slideMP2"));
        label_slideMP2->setGeometry(QRect(560, 190, 100, 40));
        label_slideMP2->setStyleSheet(QString::fromUtf8("font:20px, \"SimHei\";\n"
"color: rgb(255, 170, 0);"));
        label_slideMP2->setAlignment(Qt::AlignCenter);
        label_slideMP1 = new QLabel(MainPage);
        label_slideMP1->setObjectName(QString::fromUtf8("label_slideMP1"));
        label_slideMP1->setGeometry(QRect(360, 190, 100, 40));
        label_slideMP1->setStyleSheet(QString::fromUtf8("font:20px, \"SimHei\";\n"
"color: rgb(255, 170, 0);"));
        label_slideMP1->setAlignment(Qt::AlignCenter);
        label_slideTC1 = new QLabel(MainPage);
        label_slideTC1->setObjectName(QString::fromUtf8("label_slideTC1"));
        label_slideTC1->setGeometry(QRect(170, 190, 100, 40));
        label_slideTC1->setStyleSheet(QString::fromUtf8("font:20px, \"SimHei\";\n"
"color: rgb(255, 170, 0);"));
        label_slideTC1->setAlignment(Qt::AlignCenter);
        label_slideTC2 = new QLabel(MainPage);
        label_slideTC2->setObjectName(QString::fromUtf8("label_slideTC2"));
        label_slideTC2->setGeometry(QRect(750, 190, 100, 40));
        label_slideTC2->setStyleSheet(QString::fromUtf8("font:20px, \"SimHei\";\n"
"color: rgb(255, 170, 0);"));
        label_slideTC2->setAlignment(Qt::AlignCenter);

        retranslateUi(MainPage);

        QMetaObject::connectSlotsByName(MainPage);
    } // setupUi

    void retranslateUi(QWidget *MainPage)
    {
        MainPage->setWindowTitle(QApplication::translate("MainPage", "Form", 0, QApplication::UnicodeUTF8));
        btn_EmergencyBroadcast->setText(QApplication::translate("MainPage", "\347\264\247\346\200\245\345\271\277\346\222\255", 0, QApplication::UnicodeUTF8));
        label_washing->setText(QApplication::translate("MainPage", "\346\264\227\350\275\246\n"
"\346\250\241\345\274\217", 0, QApplication::UnicodeUTF8));
        label_BHBBreak->setText(QApplication::translate("MainPage", "\346\257\215\347\272\277\n"
"\351\253\230\351\200\237\n"
"\346\226\255\350\267\257\345\231\250\n"
"\346\226\255\345\274\200", 0, QApplication::UnicodeUTF8));
        label_Broadcast->setText(QApplication::translate("MainPage", "\345\215\212\350\207\252\345\212\250\n"
"\345\271\277\346\222\255", 0, QApplication::UnicodeUTF8));
        label_totalKilometers->setText(QString());
        label_totalHours->setText(QString());
        label_EmergencyBrake->setText(QApplication::translate("MainPage", "\347\264\247\346\200\245\345\210\266\345\212\250", 0, QApplication::UnicodeUTF8));
        label_idleMp1->setText(QApplication::translate("MainPage", "\347\251\272\350\275\254", 0, QApplication::UnicodeUTF8));
        label_idleMp2->setText(QApplication::translate("MainPage", "\347\251\272\350\275\254", 0, QApplication::UnicodeUTF8));
        label_slideMP2->setText(QApplication::translate("MainPage", "\346\273\221\350\241\214", 0, QApplication::UnicodeUTF8));
        label_slideMP1->setText(QApplication::translate("MainPage", "\346\273\221\350\241\214", 0, QApplication::UnicodeUTF8));
        label_slideTC1->setText(QApplication::translate("MainPage", "\346\273\221\350\241\214", 0, QApplication::UnicodeUTF8));
        label_slideTC2->setText(QApplication::translate("MainPage", "\346\273\221\350\241\214", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainPage: public Ui_MainPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINPAGE_H
