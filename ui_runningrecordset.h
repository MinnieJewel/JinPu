/********************************************************************************
** Form generated from reading UI file 'runningrecordset.ui'
**
** Created: Thu Jan 11 11:16:18 2018
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RUNNINGRECORDSET_H
#define UI_RUNNINGRECORDSET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RunningRecordSet
{
public:
    QPushButton *btn_setServiceKilometer;
    QLabel *label2;
    QLabel *label2_2;
    QPushButton *btn_setTagRunningKilometer;
    QPushButton *btn_clear;
    QPushButton *btn_7;
    QPushButton *btn_5;
    QPushButton *btn_1;
    QPushButton *btn_confirm;
    QPushButton *btn_4;
    QPushButton *btn_8;
    QPushButton *btn_0;
    QPushButton *btn_6;
    QPushButton *btn_2;
    QPushButton *btn_back;
    QPushButton *btn_3;
    QPushButton *btn_9;
    QLabel *label_errorInfo;
    QPushButton *btn_resetSIV1;
    QPushButton *btn_resetSIV2;
    QPushButton *btn_resetDCU1;
    QPushButton *btn_resetDCU2;
    QPushButton *btn_resetDCU3;
    QPushButton *btn_resetDCU4;

    void setupUi(QWidget *RunningRecordSet)
    {
        if (RunningRecordSet->objectName().isEmpty())
            RunningRecordSet->setObjectName(QString::fromUtf8("RunningRecordSet"));
        RunningRecordSet->resize(1024, 708);
        RunningRecordSet->setStyleSheet(QString::fromUtf8("QLabel\n"
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
"\n"
"}\n"
"\n"
"QPushButton:disabled\n"
"{\n"
"		border-radius:5px;\n"
"	font: 20px, \"SimHei\";\n"
"    color: grey;\n"
"	background-color: rgb(221,221,221);\n"
"}"));
        btn_setServiceKilometer = new QPushButton(RunningRecordSet);
        btn_setServiceKilometer->setObjectName(QString::fromUtf8("btn_setServiceKilometer"));
        btn_setServiceKilometer->setGeometry(QRect(260, 120, 300, 50));
        label2 = new QLabel(RunningRecordSet);
        label2->setObjectName(QString::fromUtf8("label2"));
        label2->setGeometry(QRect(60, 120, 150, 50));
        label2->setStyleSheet(QString::fromUtf8("border-color: rgb(0, 0, 0);"));
        label2_2 = new QLabel(RunningRecordSet);
        label2_2->setObjectName(QString::fromUtf8("label2_2"));
        label2_2->setGeometry(QRect(60, 240, 150, 50));
        label2_2->setStyleSheet(QString::fromUtf8("border-color: rgb(0, 0, 0);"));
        btn_setTagRunningKilometer = new QPushButton(RunningRecordSet);
        btn_setTagRunningKilometer->setObjectName(QString::fromUtf8("btn_setTagRunningKilometer"));
        btn_setTagRunningKilometer->setGeometry(QRect(260, 240, 300, 50));
        btn_clear = new QPushButton(RunningRecordSet);
        btn_clear->setObjectName(QString::fromUtf8("btn_clear"));
        btn_clear->setGeometry(QRect(610, 460, 90, 40));
        btn_clear->setStyleSheet(QString::fromUtf8("font: 20px, \"SimHei\";\n"
"    color: black;\n"
"	background-color: rgb(250, 250, 250);\n"
"	border-radius: 5px;"));
        btn_7 = new QPushButton(RunningRecordSet);
        btn_7->setObjectName(QString::fromUtf8("btn_7"));
        btn_7->setGeometry(QRect(610, 540, 90, 40));
        btn_7->setStyleSheet(QString::fromUtf8("font: 20px, \"SimHei\";\n"
"    color: black;\n"
"	background-color: rgb(250, 250, 250);\n"
"	border-radius: 5px;"));
        btn_5 = new QPushButton(RunningRecordSet);
        btn_5->setObjectName(QString::fromUtf8("btn_5"));
        btn_5->setGeometry(QRect(410, 540, 90, 40));
        btn_5->setStyleSheet(QString::fromUtf8("font: 20px, \"SimHei\";\n"
"    color: black;\n"
"	background-color: rgb(250, 250, 250);\n"
"	border-radius: 5px;"));
        btn_1 = new QPushButton(RunningRecordSet);
        btn_1->setObjectName(QString::fromUtf8("btn_1"));
        btn_1->setGeometry(QRect(10, 540, 90, 40));
        btn_1->setStyleSheet(QString::fromUtf8("font: 20px, \"SimHei\";\n"
"    color: black;\n"
"	background-color: rgb(250, 250, 250);\n"
"	border-radius: 5px;"));
        btn_confirm = new QPushButton(RunningRecordSet);
        btn_confirm->setObjectName(QString::fromUtf8("btn_confirm"));
        btn_confirm->setGeometry(QRect(810, 460, 90, 40));
        btn_confirm->setStyleSheet(QString::fromUtf8("QPushButton{font: 20px, \"SimHei\";\n"
"    color: black;\n"
"	background-color: rgb(250, 250, 250);\n"
"	border-radius: 5px;}\n"
"QPushButton:disabled\n"
"{\n"
"		border-radius:5px;\n"
"	font: 20px, \"SimHei\";\n"
"    color: grey;\n"
"	background-color: rgb(221,221,221);\n"
"}"));
        btn_4 = new QPushButton(RunningRecordSet);
        btn_4->setObjectName(QString::fromUtf8("btn_4"));
        btn_4->setGeometry(QRect(310, 540, 90, 40));
        btn_4->setStyleSheet(QString::fromUtf8("font: 20px, \"SimHei\";\n"
"    color: black;\n"
"	background-color: rgb(250, 250, 250);\n"
"	border-radius: 5px;"));
        btn_8 = new QPushButton(RunningRecordSet);
        btn_8->setObjectName(QString::fromUtf8("btn_8"));
        btn_8->setGeometry(QRect(710, 540, 90, 40));
        btn_8->setStyleSheet(QString::fromUtf8("font: 20px, \"SimHei\";\n"
"    color: black;\n"
"	background-color: rgb(250, 250, 250);\n"
"	border-radius: 5px;"));
        btn_0 = new QPushButton(RunningRecordSet);
        btn_0->setObjectName(QString::fromUtf8("btn_0"));
        btn_0->setGeometry(QRect(910, 540, 90, 40));
        btn_0->setStyleSheet(QString::fromUtf8("font: 20px, \"SimHei\";\n"
"    color: black;\n"
"	background-color: rgb(250, 250, 250);\n"
"	border-radius: 5px;"));
        btn_6 = new QPushButton(RunningRecordSet);
        btn_6->setObjectName(QString::fromUtf8("btn_6"));
        btn_6->setGeometry(QRect(510, 540, 90, 40));
        btn_6->setStyleSheet(QString::fromUtf8("font: 20px, \"SimHei\";\n"
"    color: black;\n"
"	background-color: rgb(250, 250, 250);\n"
"	border-radius: 5px;"));
        btn_2 = new QPushButton(RunningRecordSet);
        btn_2->setObjectName(QString::fromUtf8("btn_2"));
        btn_2->setGeometry(QRect(110, 540, 90, 40));
        btn_2->setStyleSheet(QString::fromUtf8("font: 20px, \"SimHei\";\n"
"    color: black;\n"
"	background-color: rgb(250, 250, 250);\n"
"	border-radius: 5px;"));
        btn_back = new QPushButton(RunningRecordSet);
        btn_back->setObjectName(QString::fromUtf8("btn_back"));
        btn_back->setGeometry(QRect(910, 460, 90, 40));
        btn_back->setStyleSheet(QString::fromUtf8("QPushButton{font: 20px, \"SimHei\";\n"
"    color: black;\n"
"	background-color: rgb(250, 250, 250);\n"
"	border-radius: 5px;}\n"
"QPushButton:disabled\n"
"{\n"
"		border-radius:5px;\n"
"	font: 20px, \"SimHei\";\n"
"    color: grey;\n"
"	background-color: rgb(221,221,221);\n"
"}"));
        btn_3 = new QPushButton(RunningRecordSet);
        btn_3->setObjectName(QString::fromUtf8("btn_3"));
        btn_3->setGeometry(QRect(210, 540, 90, 40));
        btn_3->setStyleSheet(QString::fromUtf8("font: 20px, \"SimHei\";\n"
"    color: black;\n"
"	background-color: rgb(250, 250, 250);\n"
"	border-radius: 5px;"));
        btn_9 = new QPushButton(RunningRecordSet);
        btn_9->setObjectName(QString::fromUtf8("btn_9"));
        btn_9->setGeometry(QRect(810, 540, 90, 40));
        btn_9->setStyleSheet(QString::fromUtf8("font: 20px, \"SimHei\";\n"
"    color: black;\n"
"	background-color: rgb(250, 250, 250);\n"
"	border-radius: 5px;"));
        label_errorInfo = new QLabel(RunningRecordSet);
        label_errorInfo->setObjectName(QString::fromUtf8("label_errorInfo"));
        label_errorInfo->setGeometry(QRect(260, 310, 291, 41));
        label_errorInfo->setStyleSheet(QString::fromUtf8("border-width:0;\n"
"color:red;"));
        btn_resetSIV1 = new QPushButton(RunningRecordSet);
        btn_resetSIV1->setObjectName(QString::fromUtf8("btn_resetSIV1"));
        btn_resetSIV1->setGeometry(QRect(810, 62, 180, 40));
        btn_resetSIV2 = new QPushButton(RunningRecordSet);
        btn_resetSIV2->setObjectName(QString::fromUtf8("btn_resetSIV2"));
        btn_resetSIV2->setGeometry(QRect(810, 120, 180, 40));
        btn_resetDCU1 = new QPushButton(RunningRecordSet);
        btn_resetDCU1->setObjectName(QString::fromUtf8("btn_resetDCU1"));
        btn_resetDCU1->setGeometry(QRect(810, 180, 180, 40));
        btn_resetDCU2 = new QPushButton(RunningRecordSet);
        btn_resetDCU2->setObjectName(QString::fromUtf8("btn_resetDCU2"));
        btn_resetDCU2->setGeometry(QRect(810, 240, 180, 40));
        btn_resetDCU3 = new QPushButton(RunningRecordSet);
        btn_resetDCU3->setObjectName(QString::fromUtf8("btn_resetDCU3"));
        btn_resetDCU3->setGeometry(QRect(810, 300, 180, 40));
        btn_resetDCU4 = new QPushButton(RunningRecordSet);
        btn_resetDCU4->setObjectName(QString::fromUtf8("btn_resetDCU4"));
        btn_resetDCU4->setGeometry(QRect(810, 360, 180, 40));

        retranslateUi(RunningRecordSet);

        QMetaObject::connectSlotsByName(RunningRecordSet);
    } // setupUi

    void retranslateUi(QWidget *RunningRecordSet)
    {
        RunningRecordSet->setWindowTitle(QApplication::translate("RunningRecordSet", "Form", 0, QApplication::UnicodeUTF8));
        btn_setServiceKilometer->setText(QString());
        label2->setText(QApplication::translate("RunningRecordSet", "\346\243\200\344\277\256\351\207\214\347\250\213\350\256\276\345\256\232", 0, QApplication::UnicodeUTF8));
        label2_2->setText(QApplication::translate("RunningRecordSet", "\350\277\220\350\241\214\346\200\273\351\207\214\347\250\213\350\256\276\345\256\232", 0, QApplication::UnicodeUTF8));
        btn_setTagRunningKilometer->setText(QString());
        btn_clear->setText(QApplication::translate("RunningRecordSet", "\346\270\205\347\251\272", 0, QApplication::UnicodeUTF8));
        btn_7->setText(QApplication::translate("RunningRecordSet", "7", 0, QApplication::UnicodeUTF8));
        btn_5->setText(QApplication::translate("RunningRecordSet", "5", 0, QApplication::UnicodeUTF8));
        btn_1->setText(QApplication::translate("RunningRecordSet", "1", 0, QApplication::UnicodeUTF8));
        btn_confirm->setText(QApplication::translate("RunningRecordSet", "\347\241\256\350\256\244", 0, QApplication::UnicodeUTF8));
        btn_4->setText(QApplication::translate("RunningRecordSet", "4", 0, QApplication::UnicodeUTF8));
        btn_8->setText(QApplication::translate("RunningRecordSet", "8", 0, QApplication::UnicodeUTF8));
        btn_0->setText(QApplication::translate("RunningRecordSet", "0", 0, QApplication::UnicodeUTF8));
        btn_6->setText(QApplication::translate("RunningRecordSet", "6", 0, QApplication::UnicodeUTF8));
        btn_2->setText(QApplication::translate("RunningRecordSet", "2", 0, QApplication::UnicodeUTF8));
        btn_back->setText(QApplication::translate("RunningRecordSet", "\350\277\224\345\233\236", 0, QApplication::UnicodeUTF8));
        btn_3->setText(QApplication::translate("RunningRecordSet", "3", 0, QApplication::UnicodeUTF8));
        btn_9->setText(QApplication::translate("RunningRecordSet", "9", 0, QApplication::UnicodeUTF8));
        label_errorInfo->setText(QApplication::translate("RunningRecordSet", "\346\225\260\346\215\256\350\276\223\345\205\245\351\224\231\350\257\257\357\274\214\350\257\267\351\207\215\346\226\260\350\276\223\345\205\245\357\274\201", 0, QApplication::UnicodeUTF8));
        btn_resetSIV1->setText(QApplication::translate("RunningRecordSet", "\351\207\215\350\256\276SIV1\350\203\275\351\207\217\350\256\241\346\225\260", 0, QApplication::UnicodeUTF8));
        btn_resetSIV2->setText(QApplication::translate("RunningRecordSet", "\351\207\215\350\256\276SIV2\350\203\275\351\207\217\350\256\241\346\225\260", 0, QApplication::UnicodeUTF8));
        btn_resetDCU1->setText(QApplication::translate("RunningRecordSet", "\351\207\215\350\256\276DCU1\350\203\275\351\207\217\350\256\241\346\225\260", 0, QApplication::UnicodeUTF8));
        btn_resetDCU2->setText(QApplication::translate("RunningRecordSet", "\351\207\215\350\256\276DCU2\350\203\275\351\207\217\350\256\241\346\225\260", 0, QApplication::UnicodeUTF8));
        btn_resetDCU3->setText(QApplication::translate("RunningRecordSet", "\351\207\215\350\256\276DCU3\350\203\275\351\207\217\350\256\241\346\225\260", 0, QApplication::UnicodeUTF8));
        btn_resetDCU4->setText(QApplication::translate("RunningRecordSet", "\351\207\215\350\256\276DCU4\350\203\275\351\207\217\350\256\241\346\225\260", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class RunningRecordSet: public Ui_RunningRecordSet {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RUNNINGRECORDSET_H
