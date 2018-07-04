/********************************************************************************
** Form generated from reading UI file 'assistantpage.ui'
**
** Created: Thu Jan 11 11:16:18 2018
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ASSISTANTPAGE_H
#define UI_ASSISTANTPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AssistantPage
{
public:
    QLabel *label_car3SIVOutputCurrent;
    QLabel *label_car4SIVOutputCurrent;
    QLabel *label_car2SIVOutputCurrent;
    QLabel *label_SIVOutputCurrent;
    QLabel *label_car2No;
    QLabel *label_car2SIVOutputVoltage;
    QLabel *label_car1SIVInputVoltage;
    QLabel *label_SIVInputVoltage;
    QLabel *label_car1SIVOutputRate;
    QLabel *label_vehicleNo;
    QLabel *label_car3SIVOutputRate;
    QLabel *label_SIVOutputRate;
    QLabel *label_car4SIVInputVoltage;
    QLabel *label_car4No;
    QLabel *label_car1SIVOutputVoltage;
    QLabel *label_car3SIVOutputVoltage;
    QLabel *label_car3No;
    QLabel *label_SIVOutputVoltage;
    QLabel *label_car4SIVOutputRate;
    QLabel *label_car2SIVOutputRate;
    QLabel *label_car4SIVOutputVoltage;
    QLabel *label_car1SIVOutputCurrent;
    QLabel *label_car3SIVInputVoltage;
    QLabel *label_car1No;
    QLabel *label_car2SIVInputVoltage;
    QLabel *label_lineVoltage1;
    QLabel *label_extendEnable1;
    QLabel *label_lineVoltage;
    QLabel *label_car2SIVOutputVoltage_2;
    QLabel *label_lineVoltage2;
    QLabel *label_car2SIVOutputCurrent_2;
    QLabel *label_extendEnable2;
    QLabel *label_car3SIVOutputCurrent_2;
    QLabel *label_car3SIVOutputVoltage_2;
    QLabel *label_extendEnable;
    QLabel *label_reset2;
    QLabel *label_cut;
    QLabel *label_cut3;
    QLabel *label_reset1;
    QLabel *label_cut2;
    QLabel *label_cut4;
    QLabel *label_reset4;
    QLabel *label_reset;
    QLabel *label_cut1;
    QLabel *label_reset3;
    QPushButton *btn_reset1;
    QPushButton *btn_cut1;
    QPushButton *btn_cut2;
    QPushButton *btn_reset2;
    QPushButton *btn_EmergencyBroadcast;

    void setupUi(QWidget *AssistantPage)
    {
        if (AssistantPage->objectName().isEmpty())
            AssistantPage->setObjectName(QString::fromUtf8("AssistantPage"));
        AssistantPage->resize(1024, 618);
        AssistantPage->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	color: white;\n"
"	border: 2px groove, gray;\n"
"    border-color: gray;\n"
"	font: 17px, \"SimHei\";	\n"
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
"}\n"
"\n"
"QPushButton:disabled\n"
"{\n"
"		border-radius:5px;\n"
"	font: 20px, \"SimHei\";\n"
"    color: grey;\n"
"	background-color: rgb(221,221,221);\n"
"}"));
        label_car3SIVOutputCurrent = new QLabel(AssistantPage);
        label_car3SIVOutputCurrent->setObjectName(QString::fromUtf8("label_car3SIVOutputCurrent"));
        label_car3SIVOutputCurrent->setGeometry(QRect(546, 271, 210, 40));
        label_car3SIVOutputCurrent->setAlignment(Qt::AlignCenter);
        label_car4SIVOutputCurrent = new QLabel(AssistantPage);
        label_car4SIVOutputCurrent->setObjectName(QString::fromUtf8("label_car4SIVOutputCurrent"));
        label_car4SIVOutputCurrent->setGeometry(QRect(755, 271, 180, 40));
        label_car4SIVOutputCurrent->setAlignment(Qt::AlignCenter);
        label_car2SIVOutputCurrent = new QLabel(AssistantPage);
        label_car2SIVOutputCurrent->setObjectName(QString::fromUtf8("label_car2SIVOutputCurrent"));
        label_car2SIVOutputCurrent->setGeometry(QRect(337, 271, 210, 40));
        label_car2SIVOutputCurrent->setAlignment(Qt::AlignCenter);
        label_SIVOutputCurrent = new QLabel(AssistantPage);
        label_SIVOutputCurrent->setObjectName(QString::fromUtf8("label_SIVOutputCurrent"));
        label_SIVOutputCurrent->setGeometry(QRect(10, 271, 140, 40));
        label_car2No = new QLabel(AssistantPage);
        label_car2No->setObjectName(QString::fromUtf8("label_car2No"));
        label_car2No->setGeometry(QRect(337, 116, 210, 40));
        label_car2No->setAlignment(Qt::AlignCenter);
        label_car2SIVOutputVoltage = new QLabel(AssistantPage);
        label_car2SIVOutputVoltage->setObjectName(QString::fromUtf8("label_car2SIVOutputVoltage"));
        label_car2SIVOutputVoltage->setGeometry(QRect(337, 193, 210, 40));
        label_car2SIVOutputVoltage->setAlignment(Qt::AlignCenter);
        label_car1SIVInputVoltage = new QLabel(AssistantPage);
        label_car1SIVInputVoltage->setObjectName(QString::fromUtf8("label_car1SIVInputVoltage"));
        label_car1SIVInputVoltage->setGeometry(QRect(149, 154, 190, 40));
        label_car1SIVInputVoltage->setAlignment(Qt::AlignCenter);
        label_SIVInputVoltage = new QLabel(AssistantPage);
        label_SIVInputVoltage->setObjectName(QString::fromUtf8("label_SIVInputVoltage"));
        label_SIVInputVoltage->setGeometry(QRect(10, 154, 140, 40));
        label_car1SIVOutputRate = new QLabel(AssistantPage);
        label_car1SIVOutputRate->setObjectName(QString::fromUtf8("label_car1SIVOutputRate"));
        label_car1SIVOutputRate->setGeometry(QRect(149, 232, 190, 40));
        label_car1SIVOutputRate->setAlignment(Qt::AlignCenter);
        label_vehicleNo = new QLabel(AssistantPage);
        label_vehicleNo->setObjectName(QString::fromUtf8("label_vehicleNo"));
        label_vehicleNo->setGeometry(QRect(10, 116, 140, 40));
        label_car3SIVOutputRate = new QLabel(AssistantPage);
        label_car3SIVOutputRate->setObjectName(QString::fromUtf8("label_car3SIVOutputRate"));
        label_car3SIVOutputRate->setGeometry(QRect(546, 232, 210, 40));
        label_car3SIVOutputRate->setAlignment(Qt::AlignCenter);
        label_SIVOutputRate = new QLabel(AssistantPage);
        label_SIVOutputRate->setObjectName(QString::fromUtf8("label_SIVOutputRate"));
        label_SIVOutputRate->setGeometry(QRect(10, 232, 140, 40));
        label_car4SIVInputVoltage = new QLabel(AssistantPage);
        label_car4SIVInputVoltage->setObjectName(QString::fromUtf8("label_car4SIVInputVoltage"));
        label_car4SIVInputVoltage->setGeometry(QRect(755, 154, 180, 40));
        label_car4SIVInputVoltage->setAlignment(Qt::AlignCenter);
        label_car4No = new QLabel(AssistantPage);
        label_car4No->setObjectName(QString::fromUtf8("label_car4No"));
        label_car4No->setGeometry(QRect(755, 116, 180, 40));
        label_car4No->setAlignment(Qt::AlignCenter);
        label_car1SIVOutputVoltage = new QLabel(AssistantPage);
        label_car1SIVOutputVoltage->setObjectName(QString::fromUtf8("label_car1SIVOutputVoltage"));
        label_car1SIVOutputVoltage->setGeometry(QRect(149, 193, 190, 40));
        label_car1SIVOutputVoltage->setAlignment(Qt::AlignCenter);
        label_car3SIVOutputVoltage = new QLabel(AssistantPage);
        label_car3SIVOutputVoltage->setObjectName(QString::fromUtf8("label_car3SIVOutputVoltage"));
        label_car3SIVOutputVoltage->setGeometry(QRect(546, 193, 210, 40));
        label_car3SIVOutputVoltage->setAlignment(Qt::AlignCenter);
        label_car3No = new QLabel(AssistantPage);
        label_car3No->setObjectName(QString::fromUtf8("label_car3No"));
        label_car3No->setGeometry(QRect(546, 116, 210, 40));
        label_car3No->setAlignment(Qt::AlignCenter);
        label_SIVOutputVoltage = new QLabel(AssistantPage);
        label_SIVOutputVoltage->setObjectName(QString::fromUtf8("label_SIVOutputVoltage"));
        label_SIVOutputVoltage->setGeometry(QRect(10, 193, 140, 40));
        label_car4SIVOutputRate = new QLabel(AssistantPage);
        label_car4SIVOutputRate->setObjectName(QString::fromUtf8("label_car4SIVOutputRate"));
        label_car4SIVOutputRate->setGeometry(QRect(755, 232, 180, 40));
        label_car4SIVOutputRate->setAlignment(Qt::AlignCenter);
        label_car2SIVOutputRate = new QLabel(AssistantPage);
        label_car2SIVOutputRate->setObjectName(QString::fromUtf8("label_car2SIVOutputRate"));
        label_car2SIVOutputRate->setGeometry(QRect(337, 232, 210, 40));
        label_car2SIVOutputRate->setAlignment(Qt::AlignCenter);
        label_car4SIVOutputVoltage = new QLabel(AssistantPage);
        label_car4SIVOutputVoltage->setObjectName(QString::fromUtf8("label_car4SIVOutputVoltage"));
        label_car4SIVOutputVoltage->setGeometry(QRect(755, 193, 180, 40));
        label_car4SIVOutputVoltage->setAlignment(Qt::AlignCenter);
        label_car1SIVOutputCurrent = new QLabel(AssistantPage);
        label_car1SIVOutputCurrent->setObjectName(QString::fromUtf8("label_car1SIVOutputCurrent"));
        label_car1SIVOutputCurrent->setGeometry(QRect(149, 271, 190, 40));
        label_car1SIVOutputCurrent->setAlignment(Qt::AlignCenter);
        label_car3SIVInputVoltage = new QLabel(AssistantPage);
        label_car3SIVInputVoltage->setObjectName(QString::fromUtf8("label_car3SIVInputVoltage"));
        label_car3SIVInputVoltage->setGeometry(QRect(546, 154, 210, 40));
        label_car3SIVInputVoltage->setAlignment(Qt::AlignCenter);
        label_car1No = new QLabel(AssistantPage);
        label_car1No->setObjectName(QString::fromUtf8("label_car1No"));
        label_car1No->setGeometry(QRect(149, 116, 190, 40));
        label_car1No->setScaledContents(false);
        label_car1No->setAlignment(Qt::AlignCenter);
        label_car2SIVInputVoltage = new QLabel(AssistantPage);
        label_car2SIVInputVoltage->setObjectName(QString::fromUtf8("label_car2SIVInputVoltage"));
        label_car2SIVInputVoltage->setGeometry(QRect(337, 154, 210, 40));
        label_car2SIVInputVoltage->setAlignment(Qt::AlignCenter);
        label_lineVoltage1 = new QLabel(AssistantPage);
        label_lineVoltage1->setObjectName(QString::fromUtf8("label_lineVoltage1"));
        label_lineVoltage1->setGeometry(QRect(149, 350, 190, 40));
        label_lineVoltage1->setAlignment(Qt::AlignCenter);
        label_extendEnable1 = new QLabel(AssistantPage);
        label_extendEnable1->setObjectName(QString::fromUtf8("label_extendEnable1"));
        label_extendEnable1->setGeometry(QRect(149, 310, 190, 40));
        label_extendEnable1->setAlignment(Qt::AlignCenter);
        label_lineVoltage = new QLabel(AssistantPage);
        label_lineVoltage->setObjectName(QString::fromUtf8("label_lineVoltage"));
        label_lineVoltage->setGeometry(QRect(10, 350, 140, 40));
        label_car2SIVOutputVoltage_2 = new QLabel(AssistantPage);
        label_car2SIVOutputVoltage_2->setObjectName(QString::fromUtf8("label_car2SIVOutputVoltage_2"));
        label_car2SIVOutputVoltage_2->setGeometry(QRect(337, 310, 210, 40));
        label_car2SIVOutputVoltage_2->setAlignment(Qt::AlignCenter);
        label_lineVoltage2 = new QLabel(AssistantPage);
        label_lineVoltage2->setObjectName(QString::fromUtf8("label_lineVoltage2"));
        label_lineVoltage2->setGeometry(QRect(755, 350, 180, 40));
        label_lineVoltage2->setAlignment(Qt::AlignCenter);
        label_car2SIVOutputCurrent_2 = new QLabel(AssistantPage);
        label_car2SIVOutputCurrent_2->setObjectName(QString::fromUtf8("label_car2SIVOutputCurrent_2"));
        label_car2SIVOutputCurrent_2->setGeometry(QRect(337, 350, 210, 40));
        label_car2SIVOutputCurrent_2->setAlignment(Qt::AlignCenter);
        label_extendEnable2 = new QLabel(AssistantPage);
        label_extendEnable2->setObjectName(QString::fromUtf8("label_extendEnable2"));
        label_extendEnable2->setGeometry(QRect(755, 310, 180, 40));
        label_extendEnable2->setAlignment(Qt::AlignCenter);
        label_car3SIVOutputCurrent_2 = new QLabel(AssistantPage);
        label_car3SIVOutputCurrent_2->setObjectName(QString::fromUtf8("label_car3SIVOutputCurrent_2"));
        label_car3SIVOutputCurrent_2->setGeometry(QRect(546, 350, 210, 40));
        label_car3SIVOutputCurrent_2->setAlignment(Qt::AlignCenter);
        label_car3SIVOutputVoltage_2 = new QLabel(AssistantPage);
        label_car3SIVOutputVoltage_2->setObjectName(QString::fromUtf8("label_car3SIVOutputVoltage_2"));
        label_car3SIVOutputVoltage_2->setGeometry(QRect(546, 310, 210, 40));
        label_car3SIVOutputVoltage_2->setAlignment(Qt::AlignCenter);
        label_extendEnable = new QLabel(AssistantPage);
        label_extendEnable->setObjectName(QString::fromUtf8("label_extendEnable"));
        label_extendEnable->setGeometry(QRect(10, 310, 140, 40));
        label_reset2 = new QLabel(AssistantPage);
        label_reset2->setObjectName(QString::fromUtf8("label_reset2"));
        label_reset2->setGeometry(QRect(337, 390, 210, 40));
        label_reset2->setAlignment(Qt::AlignCenter);
        label_cut = new QLabel(AssistantPage);
        label_cut->setObjectName(QString::fromUtf8("label_cut"));
        label_cut->setGeometry(QRect(10, 429, 140, 40));
        label_cut3 = new QLabel(AssistantPage);
        label_cut3->setObjectName(QString::fromUtf8("label_cut3"));
        label_cut3->setGeometry(QRect(546, 429, 210, 40));
        label_cut3->setAlignment(Qt::AlignCenter);
        label_reset1 = new QLabel(AssistantPage);
        label_reset1->setObjectName(QString::fromUtf8("label_reset1"));
        label_reset1->setGeometry(QRect(149, 390, 190, 40));
        label_cut2 = new QLabel(AssistantPage);
        label_cut2->setObjectName(QString::fromUtf8("label_cut2"));
        label_cut2->setGeometry(QRect(337, 429, 210, 40));
        label_cut2->setAlignment(Qt::AlignCenter);
        label_cut4 = new QLabel(AssistantPage);
        label_cut4->setObjectName(QString::fromUtf8("label_cut4"));
        label_cut4->setGeometry(QRect(755, 429, 180, 40));
        label_reset4 = new QLabel(AssistantPage);
        label_reset4->setObjectName(QString::fromUtf8("label_reset4"));
        label_reset4->setGeometry(QRect(755, 390, 180, 40));
        label_reset = new QLabel(AssistantPage);
        label_reset->setObjectName(QString::fromUtf8("label_reset"));
        label_reset->setGeometry(QRect(10, 390, 140, 40));
        label_cut1 = new QLabel(AssistantPage);
        label_cut1->setObjectName(QString::fromUtf8("label_cut1"));
        label_cut1->setGeometry(QRect(149, 429, 190, 40));
        label_reset3 = new QLabel(AssistantPage);
        label_reset3->setObjectName(QString::fromUtf8("label_reset3"));
        label_reset3->setGeometry(QRect(546, 390, 210, 40));
        label_reset3->setAlignment(Qt::AlignCenter);
        btn_reset1 = new QPushButton(AssistantPage);
        btn_reset1->setObjectName(QString::fromUtf8("btn_reset1"));
        btn_reset1->setGeometry(QRect(190, 390, 98, 35));
        btn_cut1 = new QPushButton(AssistantPage);
        btn_cut1->setObjectName(QString::fromUtf8("btn_cut1"));
        btn_cut1->setGeometry(QRect(190, 429, 98, 35));
        btn_cut2 = new QPushButton(AssistantPage);
        btn_cut2->setObjectName(QString::fromUtf8("btn_cut2"));
        btn_cut2->setGeometry(QRect(790, 429, 98, 35));
        btn_reset2 = new QPushButton(AssistantPage);
        btn_reset2->setObjectName(QString::fromUtf8("btn_reset2"));
        btn_reset2->setGeometry(QRect(790, 390, 98, 35));
        btn_EmergencyBroadcast = new QPushButton(AssistantPage);
        btn_EmergencyBroadcast->setObjectName(QString::fromUtf8("btn_EmergencyBroadcast"));
        btn_EmergencyBroadcast->setGeometry(QRect(860, 560, 130, 40));

        retranslateUi(AssistantPage);

        QMetaObject::connectSlotsByName(AssistantPage);
    } // setupUi

    void retranslateUi(QWidget *AssistantPage)
    {
        AssistantPage->setWindowTitle(QApplication::translate("AssistantPage", "Form", 0, QApplication::UnicodeUTF8));
        label_car3SIVOutputCurrent->setText(QApplication::translate("AssistantPage", "--", 0, QApplication::UnicodeUTF8));
        label_car4SIVOutputCurrent->setText(QString());
        label_car2SIVOutputCurrent->setText(QApplication::translate("AssistantPage", "--", 0, QApplication::UnicodeUTF8));
        label_SIVOutputCurrent->setText(QApplication::translate("AssistantPage", "SIV\350\276\223\345\207\272\347\224\265\346\265\201(A)", 0, QApplication::UnicodeUTF8));
        label_car2No->setText(QApplication::translate("AssistantPage", "2", 0, QApplication::UnicodeUTF8));
        label_car2SIVOutputVoltage->setText(QApplication::translate("AssistantPage", "--", 0, QApplication::UnicodeUTF8));
        label_car1SIVInputVoltage->setText(QString());
        label_SIVInputVoltage->setText(QApplication::translate("AssistantPage", "SIV\350\276\223\345\205\245\347\224\265\345\216\213(V)", 0, QApplication::UnicodeUTF8));
        label_car1SIVOutputRate->setText(QString());
        label_vehicleNo->setText(QApplication::translate("AssistantPage", "\350\275\246\345\217\267", 0, QApplication::UnicodeUTF8));
        label_car3SIVOutputRate->setText(QApplication::translate("AssistantPage", "--", 0, QApplication::UnicodeUTF8));
        label_SIVOutputRate->setText(QApplication::translate("AssistantPage", "SIV\350\276\223\345\207\272\351\242\221\347\216\207(Hz)", 0, QApplication::UnicodeUTF8));
        label_car4SIVInputVoltage->setText(QString());
        label_car4No->setText(QApplication::translate("AssistantPage", "4", 0, QApplication::UnicodeUTF8));
        label_car1SIVOutputVoltage->setText(QString());
        label_car3SIVOutputVoltage->setText(QApplication::translate("AssistantPage", "--", 0, QApplication::UnicodeUTF8));
        label_car3No->setText(QApplication::translate("AssistantPage", "3", 0, QApplication::UnicodeUTF8));
        label_SIVOutputVoltage->setText(QApplication::translate("AssistantPage", "SIV\350\276\223\345\207\272\347\224\265\345\216\213(V)", 0, QApplication::UnicodeUTF8));
        label_car4SIVOutputRate->setText(QString());
        label_car2SIVOutputRate->setText(QApplication::translate("AssistantPage", "--", 0, QApplication::UnicodeUTF8));
        label_car4SIVOutputVoltage->setText(QString());
        label_car1SIVOutputCurrent->setText(QString());
        label_car3SIVInputVoltage->setText(QApplication::translate("AssistantPage", "--", 0, QApplication::UnicodeUTF8));
        label_car1No->setText(QApplication::translate("AssistantPage", "1", 0, QApplication::UnicodeUTF8));
        label_car2SIVInputVoltage->setText(QApplication::translate("AssistantPage", "--", 0, QApplication::UnicodeUTF8));
        label_lineVoltage1->setText(QString());
        label_extendEnable1->setText(QString());
        label_lineVoltage->setText(QApplication::translate("AssistantPage", "\346\257\215\347\272\277\347\224\265\345\216\213(V)", 0, QApplication::UnicodeUTF8));
        label_car2SIVOutputVoltage_2->setText(QApplication::translate("AssistantPage", "--", 0, QApplication::UnicodeUTF8));
        label_lineVoltage2->setText(QString());
        label_car2SIVOutputCurrent_2->setText(QApplication::translate("AssistantPage", "--", 0, QApplication::UnicodeUTF8));
        label_extendEnable2->setText(QString());
        label_car3SIVOutputCurrent_2->setText(QApplication::translate("AssistantPage", "--", 0, QApplication::UnicodeUTF8));
        label_car3SIVOutputVoltage_2->setText(QApplication::translate("AssistantPage", "--", 0, QApplication::UnicodeUTF8));
        label_extendEnable->setText(QApplication::translate("AssistantPage", "\346\211\251\345\261\225\344\275\277\350\203\275", 0, QApplication::UnicodeUTF8));
        label_reset2->setText(QApplication::translate("AssistantPage", "--", 0, QApplication::UnicodeUTF8));
        label_cut->setText(QApplication::translate("AssistantPage", "\345\210\207\351\231\244", 0, QApplication::UnicodeUTF8));
        label_cut3->setText(QApplication::translate("AssistantPage", "--", 0, QApplication::UnicodeUTF8));
        label_reset1->setText(QString());
        label_cut2->setText(QApplication::translate("AssistantPage", "--", 0, QApplication::UnicodeUTF8));
        label_cut4->setText(QString());
        label_reset4->setText(QString());
        label_reset->setText(QApplication::translate("AssistantPage", "\345\244\215\344\275\215", 0, QApplication::UnicodeUTF8));
        label_cut1->setText(QString());
        label_reset3->setText(QApplication::translate("AssistantPage", "--", 0, QApplication::UnicodeUTF8));
        btn_reset1->setText(QApplication::translate("AssistantPage", "\345\244\215\344\275\215", 0, QApplication::UnicodeUTF8));
        btn_cut1->setText(QApplication::translate("AssistantPage", "\345\210\207\351\231\244", 0, QApplication::UnicodeUTF8));
        btn_cut2->setText(QApplication::translate("AssistantPage", "\345\210\207\351\231\244", 0, QApplication::UnicodeUTF8));
        btn_reset2->setText(QApplication::translate("AssistantPage", "\345\244\215\344\275\215", 0, QApplication::UnicodeUTF8));
        btn_EmergencyBroadcast->setText(QApplication::translate("AssistantPage", "\347\264\247\346\200\245\345\271\277\346\222\255", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AssistantPage: public Ui_AssistantPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ASSISTANTPAGE_H
