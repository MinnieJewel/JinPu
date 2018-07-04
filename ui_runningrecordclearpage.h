/********************************************************************************
** Form generated from reading UI file 'runningrecordclearpage.ui'
**
** Created: Thu Jan 11 11:16:18 2018
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RUNNINGRECORDCLEARPAGE_H
#define UI_RUNNINGRECORDCLEARPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RunningRecordClearPage
{
public:
    QLabel *label_4;
    QLabel *label_ServiceCapacity;
    QLabel *label_TractionCapacity;
    QLabel *label_Ap1Capacity;
    QLabel *label_AuxCostCapacity;
    QLabel *label_Ap2Capacity;
    QPushButton *btn_back;
    QLabel *label_26;
    QPushButton *btn_ServiceDistance;
    QPushButton *btn_TractionCost;
    QPushButton *btn_Ap1Time;
    QPushButton *btn_Ap2Time;
    QPushButton *btn_AuxCost;
    QLabel *label_tractionDisableInfo;
    QLabel *label_SIVDisableInfo;

    void setupUi(QWidget *RunningRecordClearPage)
    {
        if (RunningRecordClearPage->objectName().isEmpty())
            RunningRecordClearPage->setObjectName(QString::fromUtf8("RunningRecordClearPage"));
        RunningRecordClearPage->resize(1024, 708);
        RunningRecordClearPage->setStyleSheet(QString::fromUtf8("QLabel\n"
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
"}\n"
"\n"
"QPushButton:disabled\n"
"{\n"
"		border-radius:5px;\n"
"	font: 20px, \"SimHei\";\n"
"    color: grey;\n"
"	background-color: rgb(221,221,221);\n"
"}"));
        label_4 = new QLabel(RunningRecordClearPage);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(350, 110, 400, 41));
        label_ServiceCapacity = new QLabel(RunningRecordClearPage);
        label_ServiceCapacity->setObjectName(QString::fromUtf8("label_ServiceCapacity"));
        label_ServiceCapacity->setGeometry(QRect(350, 150, 400, 41));
        label_TractionCapacity = new QLabel(RunningRecordClearPage);
        label_TractionCapacity->setObjectName(QString::fromUtf8("label_TractionCapacity"));
        label_TractionCapacity->setGeometry(QRect(350, 270, 400, 80));
        label_Ap1Capacity = new QLabel(RunningRecordClearPage);
        label_Ap1Capacity->setObjectName(QString::fromUtf8("label_Ap1Capacity"));
        label_Ap1Capacity->setGeometry(QRect(350, 190, 400, 41));
        label_AuxCostCapacity = new QLabel(RunningRecordClearPage);
        label_AuxCostCapacity->setObjectName(QString::fromUtf8("label_AuxCostCapacity"));
        label_AuxCostCapacity->setGeometry(QRect(350, 350, 400, 41));
        label_Ap2Capacity = new QLabel(RunningRecordClearPage);
        label_Ap2Capacity->setObjectName(QString::fromUtf8("label_Ap2Capacity"));
        label_Ap2Capacity->setGeometry(QRect(350, 230, 400, 41));
        btn_back = new QPushButton(RunningRecordClearPage);
        btn_back->setObjectName(QString::fromUtf8("btn_back"));
        btn_back->setGeometry(QRect(770, 580, 98, 40));
        btn_back->setStyleSheet(QString::fromUtf8("	border-radius: 5px;"));
        label_26 = new QLabel(RunningRecordClearPage);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(110, 110, 240, 41));
        btn_ServiceDistance = new QPushButton(RunningRecordClearPage);
        btn_ServiceDistance->setObjectName(QString::fromUtf8("btn_ServiceDistance"));
        btn_ServiceDistance->setGeometry(QRect(110, 150, 240, 41));
        btn_TractionCost = new QPushButton(RunningRecordClearPage);
        btn_TractionCost->setObjectName(QString::fromUtf8("btn_TractionCost"));
        btn_TractionCost->setGeometry(QRect(110, 270, 240, 80));
        btn_Ap1Time = new QPushButton(RunningRecordClearPage);
        btn_Ap1Time->setObjectName(QString::fromUtf8("btn_Ap1Time"));
        btn_Ap1Time->setGeometry(QRect(110, 190, 240, 41));
        btn_Ap2Time = new QPushButton(RunningRecordClearPage);
        btn_Ap2Time->setObjectName(QString::fromUtf8("btn_Ap2Time"));
        btn_Ap2Time->setGeometry(QRect(110, 230, 240, 41));
        btn_AuxCost = new QPushButton(RunningRecordClearPage);
        btn_AuxCost->setObjectName(QString::fromUtf8("btn_AuxCost"));
        btn_AuxCost->setGeometry(QRect(110, 350, 240, 41));
        label_tractionDisableInfo = new QLabel(RunningRecordClearPage);
        label_tractionDisableInfo->setObjectName(QString::fromUtf8("label_tractionDisableInfo"));
        label_tractionDisableInfo->setGeometry(QRect(130, 490, 281, 31));
        label_tractionDisableInfo->setStyleSheet(QString::fromUtf8("font: 15px, \"SimHei\";\n"
"border:0px;\n"
"color:red;"));
        label_SIVDisableInfo = new QLabel(RunningRecordClearPage);
        label_SIVDisableInfo->setObjectName(QString::fromUtf8("label_SIVDisableInfo"));
        label_SIVDisableInfo->setGeometry(QRect(130, 520, 281, 31));
        label_SIVDisableInfo->setStyleSheet(QString::fromUtf8("font: 15px, \"SimHei\";\n"
"border:0px;\n"
"color:red;"));

        retranslateUi(RunningRecordClearPage);

        QMetaObject::connectSlotsByName(RunningRecordClearPage);
    } // setupUi

    void retranslateUi(QWidget *RunningRecordClearPage)
    {
        RunningRecordClearPage->setWindowTitle(QApplication::translate("RunningRecordClearPage", "Form", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("RunningRecordClearPage", "\350\256\260\345\275\225\345\256\271\351\207\217", 0, QApplication::UnicodeUTF8));
        label_ServiceCapacity->setText(QString());
        label_TractionCapacity->setText(QString());
        label_Ap1Capacity->setText(QString());
        label_AuxCostCapacity->setText(QString());
        label_Ap2Capacity->setText(QString());
        btn_back->setText(QApplication::translate("RunningRecordClearPage", "\351\200\200\345\207\272", 0, QApplication::UnicodeUTF8));
        label_26->setText(QApplication::translate("RunningRecordClearPage", "\350\256\260\345\275\225", 0, QApplication::UnicodeUTF8));
        btn_ServiceDistance->setText(QApplication::translate("RunningRecordClearPage", "\346\243\200\344\277\256\350\277\220\350\241\214\351\207\214\347\250\213(km)", 0, QApplication::UnicodeUTF8));
        btn_TractionCost->setText(QApplication::translate("RunningRecordClearPage", "\347\211\265\345\274\225\350\203\275\350\200\227\n"
"\345\206\215\347\224\237\350\203\275\350\200\227(kmh)", 0, QApplication::UnicodeUTF8));
        btn_Ap1Time->setText(QApplication::translate("RunningRecordClearPage", "TC1\347\251\272\345\216\213\346\234\272\350\277\220\350\241\214\346\227\266\351\227\264(kmh)", 0, QApplication::UnicodeUTF8));
        btn_Ap2Time->setText(QApplication::translate("RunningRecordClearPage", "TC2\347\251\272\345\216\213\346\234\272\350\277\220\350\241\214\346\227\266\351\227\264(kmh)", 0, QApplication::UnicodeUTF8));
        btn_AuxCost->setText(QApplication::translate("RunningRecordClearPage", "\350\276\205\345\212\251\350\203\275\350\200\227(kmh)", 0, QApplication::UnicodeUTF8));
        label_tractionDisableInfo->setText(QApplication::translate("RunningRecordClearPage", "\347\211\265\345\274\225\345\222\214\345\210\266\345\212\250\350\203\275\351\207\217\350\256\241\346\225\260\347\246\201\346\255\242\346\270\205\351\233\266", 0, QApplication::UnicodeUTF8));
        label_SIVDisableInfo->setText(QApplication::translate("RunningRecordClearPage", "\350\276\205\345\212\251\350\203\275\350\200\227\347\246\201\346\255\242\346\270\205\351\233\266", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class RunningRecordClearPage: public Ui_RunningRecordClearPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RUNNINGRECORDCLEARPAGE_H
