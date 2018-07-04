/********************************************************************************
** Form generated from reading UI file 'emergencybroadcast.ui'
**
** Created: Thu Jan 11 11:16:18 2018
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMERGENCYBROADCAST_H
#define UI_EMERGENCYBROADCAST_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EmergencyBroadcast
{
public:
    QPushButton *btn0;
    QPushButton *btn1;
    QPushButton *btn2;
    QPushButton *btn3;
    QPushButton *btn4;
    QPushButton *btn5;
    QPushButton *btn6;
    QPushButton *btn7;
    QPushButton *btn_Back;
    QPushButton *btn_cease;
    QPushButton *btn8;

    void setupUi(QWidget *EmergencyBroadcast)
    {
        if (EmergencyBroadcast->objectName().isEmpty())
            EmergencyBroadcast->setObjectName(QString::fromUtf8("EmergencyBroadcast"));
        EmergencyBroadcast->resize(1024, 708);
        EmergencyBroadcast->setStyleSheet(QString::fromUtf8("QLabel\n"
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
        btn0 = new QPushButton(EmergencyBroadcast);
        btn0->setObjectName(QString::fromUtf8("btn0"));
        btn0->setGeometry(QRect(50, 70, 260, 61));
        btn0->setStyleSheet(QString::fromUtf8("	font: 30px"));
        btn1 = new QPushButton(EmergencyBroadcast);
        btn1->setObjectName(QString::fromUtf8("btn1"));
        btn1->setGeometry(QRect(380, 70, 260, 61));
        btn1->setStyleSheet(QString::fromUtf8("	font: 30px"));
        btn2 = new QPushButton(EmergencyBroadcast);
        btn2->setObjectName(QString::fromUtf8("btn2"));
        btn2->setGeometry(QRect(710, 70, 260, 61));
        btn2->setStyleSheet(QString::fromUtf8("	font: 30px"));
        btn3 = new QPushButton(EmergencyBroadcast);
        btn3->setObjectName(QString::fromUtf8("btn3"));
        btn3->setGeometry(QRect(50, 180, 260, 61));
        btn3->setStyleSheet(QString::fromUtf8("	font: 30px"));
        btn4 = new QPushButton(EmergencyBroadcast);
        btn4->setObjectName(QString::fromUtf8("btn4"));
        btn4->setGeometry(QRect(380, 180, 260, 61));
        btn4->setStyleSheet(QString::fromUtf8("	font: 30px"));
        btn5 = new QPushButton(EmergencyBroadcast);
        btn5->setObjectName(QString::fromUtf8("btn5"));
        btn5->setGeometry(QRect(710, 180, 260, 61));
        btn5->setStyleSheet(QString::fromUtf8("	font: 30px"));
        btn6 = new QPushButton(EmergencyBroadcast);
        btn6->setObjectName(QString::fromUtf8("btn6"));
        btn6->setGeometry(QRect(50, 290, 260, 61));
        btn6->setStyleSheet(QString::fromUtf8("	font: 30px"));
        btn7 = new QPushButton(EmergencyBroadcast);
        btn7->setObjectName(QString::fromUtf8("btn7"));
        btn7->setGeometry(QRect(380, 290, 260, 61));
        btn7->setStyleSheet(QString::fromUtf8("	font: 30px"));
        btn_Back = new QPushButton(EmergencyBroadcast);
        btn_Back->setObjectName(QString::fromUtf8("btn_Back"));
        btn_Back->setGeometry(QRect(850, 570, 98, 40));
        btn_cease = new QPushButton(EmergencyBroadcast);
        btn_cease->setObjectName(QString::fromUtf8("btn_cease"));
        btn_cease->setGeometry(QRect(690, 570, 98, 40));
        btn8 = new QPushButton(EmergencyBroadcast);
        btn8->setObjectName(QString::fromUtf8("btn8"));
        btn8->setGeometry(QRect(710, 290, 260, 61));
        btn8->setStyleSheet(QString::fromUtf8("	font: 30px"));

        retranslateUi(EmergencyBroadcast);

        QMetaObject::connectSlotsByName(EmergencyBroadcast);
    } // setupUi

    void retranslateUi(QWidget *EmergencyBroadcast)
    {
        EmergencyBroadcast->setWindowTitle(QApplication::translate("EmergencyBroadcast", "Form", 0, QApplication::UnicodeUTF8));
        btn0->setText(QApplication::translate("EmergencyBroadcast", "\346\227\240\347\264\247\346\200\245\345\271\277\346\222\255", 0, QApplication::UnicodeUTF8));
        btn1->setText(QApplication::translate("EmergencyBroadcast", "\346\225\205\351\232\234\347\253\231\345\217\260\346\270\205\345\256\242", 0, QApplication::UnicodeUTF8));
        btn2->setText(QApplication::translate("EmergencyBroadcast", "\346\270\205\345\256\242\350\255\246\347\244\272", 0, QApplication::UnicodeUTF8));
        btn3->setText(QApplication::translate("EmergencyBroadcast", "\346\225\221\346\217\264\347\253\231\345\217\260\346\270\205\345\256\242", 0, QApplication::UnicodeUTF8));
        btn4->setText(QApplication::translate("EmergencyBroadcast", "\345\214\272\351\227\264\346\270\205\345\256\242", 0, QApplication::UnicodeUTF8));
        btn5->setText(QApplication::translate("EmergencyBroadcast", "\345\205\266\344\273\226\347\253\231\345\217\260\346\270\205\345\256\242", 0, QApplication::UnicodeUTF8));
        btn6->setText(QApplication::translate("EmergencyBroadcast", "\345\244\247\345\260\217\344\272\244\350\267\257\350\275\254\346\215\242", 0, QApplication::UnicodeUTF8));
        btn7->setText(QApplication::translate("EmergencyBroadcast", "\346\225\205\351\232\234\344\270\264\346\227\266\345\201\234\350\275\246", 0, QApplication::UnicodeUTF8));
        btn_Back->setText(QApplication::translate("EmergencyBroadcast", "\350\277\224\345\233\236", 0, QApplication::UnicodeUTF8));
        btn_cease->setText(QApplication::translate("EmergencyBroadcast", "\345\201\234\346\255\242\345\271\277\346\222\255", 0, QApplication::UnicodeUTF8));
        btn8->setText(QApplication::translate("EmergencyBroadcast", "\345\205\266\344\273\226\344\270\264\346\227\266\345\201\234\350\275\246", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class EmergencyBroadcast: public Ui_EmergencyBroadcast {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMERGENCYBROADCAST_H
