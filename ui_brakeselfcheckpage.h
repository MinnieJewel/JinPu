/********************************************************************************
** Form generated from reading UI file 'brakeselfcheckpage.ui'
**
** Created: Mon Jan 15 11:37:36 2018
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BRAKESELFCHECKPAGE_H
#define UI_BRAKESELFCHECKPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BrakeSelfCheckPage
{
public:
    QLabel *label_Bogie3_2;
    QLabel *label_Bogie2_1;
    QLabel *label_CAR2_DI1;
    QLabel *label_slideDetect;
    QLabel *label_CAR4_DI1;
    QLabel *label_Bogie1_1;
    QLabel *label_No;
    QLabel *label_BogieCut;
    QLabel *label_CAR3_DI1;
    QLabel *label_Bogie4_2;
    QLabel *label_CAR1_DI1;
    QLabel *label_22;
    QLabel *label_23;
    QPushButton *btn_start;
    QPushButton *btn_cease;
    QPushButton *btn_exit;
    QLabel *label_Bogie1_2;
    QLabel *label_Bogie2_2;
    QLabel *label_Bogie3_1;
    QLabel *label_Bogie4_1;
    QPushButton *btn_antiSlip;
    QPushButton *btn_brakeDetect;
    QPushButton *btn_serialDetect;
    QLabel *label_errorInfo;
    QLabel *label_time;
    QLabel *label_time2;
    QLabel *label_time1;
    QLabel *label_prepare;
    QLabel *label_prepare2;
    QLabel *label_prepare1;
    QLabel *label_slideDetect_2;
    QLabel *label_slideDetect_3;
    QLabel *label_slideDetect_4;
    QLabel *label_slideDetect_5;
    QLabel *label_slideDetect_6;
    QLabel *label_timeout;
    QPushButton *btn_keepBrake;

    void setupUi(QWidget *BrakeSelfCheckPage)
    {
        if (BrakeSelfCheckPage->objectName().isEmpty())
            BrakeSelfCheckPage->setObjectName(QString::fromUtf8("BrakeSelfCheckPage"));
        BrakeSelfCheckPage->resize(1024, 708);
        BrakeSelfCheckPage->setStyleSheet(QString::fromUtf8("QLabel\n"
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
"}\n"
"QPushButton:disabled\n"
"{\n"
"		border-radius:5px;\n"
"	font: 20px, \"SimHei\";\n"
"    color: grey;\n"
"	background-color: rgb(221,221,221);\n"
"}\n"
"	"));
        label_Bogie3_2 = new QLabel(BrakeSelfCheckPage);
        label_Bogie3_2->setObjectName(QString::fromUtf8("label_Bogie3_2"));
        label_Bogie3_2->setGeometry(QRect(560, 230, 100, 30));
        label_Bogie2_1 = new QLabel(BrakeSelfCheckPage);
        label_Bogie2_1->setObjectName(QString::fromUtf8("label_Bogie2_1"));
        label_Bogie2_1->setGeometry(QRect(362, 230, 100, 30));
        label_CAR2_DI1 = new QLabel(BrakeSelfCheckPage);
        label_CAR2_DI1->setObjectName(QString::fromUtf8("label_CAR2_DI1"));
        label_CAR2_DI1->setGeometry(QRect(362, 140, 200, 30));
        label_slideDetect = new QLabel(BrakeSelfCheckPage);
        label_slideDetect->setObjectName(QString::fromUtf8("label_slideDetect"));
        label_slideDetect->setGeometry(QRect(50, 300, 130, 40));
        label_slideDetect->setStyleSheet(QString::fromUtf8("border-color:black;"));
        label_CAR4_DI1 = new QLabel(BrakeSelfCheckPage);
        label_CAR4_DI1->setObjectName(QString::fromUtf8("label_CAR4_DI1"));
        label_CAR4_DI1->setGeometry(QRect(757, 140, 180, 30));
        label_Bogie1_1 = new QLabel(BrakeSelfCheckPage);
        label_Bogie1_1->setObjectName(QString::fromUtf8("label_Bogie1_1"));
        label_Bogie1_1->setGeometry(QRect(193, 230, 85, 30));
        label_No = new QLabel(BrakeSelfCheckPage);
        label_No->setObjectName(QString::fromUtf8("label_No"));
        label_No->setGeometry(QRect(24, 140, 170, 30));
        label_BogieCut = new QLabel(BrakeSelfCheckPage);
        label_BogieCut->setObjectName(QString::fromUtf8("label_BogieCut"));
        label_BogieCut->setGeometry(QRect(24, 230, 170, 30));
        label_BogieCut->setStyleSheet(QString::fromUtf8("	color: white;\n"
"	border: 2px groove, gray;\n"
"    border-color: gray;\n"
"	font: 20px, \"SimHei\";	"));
        label_CAR3_DI1 = new QLabel(BrakeSelfCheckPage);
        label_CAR3_DI1->setObjectName(QString::fromUtf8("label_CAR3_DI1"));
        label_CAR3_DI1->setGeometry(QRect(560, 140, 199, 30));
        label_Bogie4_2 = new QLabel(BrakeSelfCheckPage);
        label_Bogie4_2->setObjectName(QString::fromUtf8("label_Bogie4_2"));
        label_Bogie4_2->setGeometry(QRect(757, 230, 90, 30));
        label_CAR1_DI1 = new QLabel(BrakeSelfCheckPage);
        label_CAR1_DI1->setObjectName(QString::fromUtf8("label_CAR1_DI1"));
        label_CAR1_DI1->setGeometry(QRect(193, 140, 170, 30));
        label_22 = new QLabel(BrakeSelfCheckPage);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(50, 350, 601, 31));
        label_22->setStyleSheet(QString::fromUtf8("border-color:black;"));
        label_23 = new QLabel(BrakeSelfCheckPage);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(50, 400, 601, 31));
        label_23->setStyleSheet(QString::fromUtf8("border-color:black;"));
        btn_start = new QPushButton(BrakeSelfCheckPage);
        btn_start->setObjectName(QString::fromUtf8("btn_start"));
        btn_start->setGeometry(QRect(750, 300, 98, 40));
        btn_cease = new QPushButton(BrakeSelfCheckPage);
        btn_cease->setObjectName(QString::fromUtf8("btn_cease"));
        btn_cease->setGeometry(QRect(750, 360, 98, 40));
        btn_exit = new QPushButton(BrakeSelfCheckPage);
        btn_exit->setObjectName(QString::fromUtf8("btn_exit"));
        btn_exit->setGeometry(QRect(840, 550, 98, 40));
        label_Bogie1_2 = new QLabel(BrakeSelfCheckPage);
        label_Bogie1_2->setObjectName(QString::fromUtf8("label_Bogie1_2"));
        label_Bogie1_2->setGeometry(QRect(277, 230, 86, 30));
        label_Bogie2_2 = new QLabel(BrakeSelfCheckPage);
        label_Bogie2_2->setObjectName(QString::fromUtf8("label_Bogie2_2"));
        label_Bogie2_2->setGeometry(QRect(461, 230, 101, 30));
        label_Bogie3_1 = new QLabel(BrakeSelfCheckPage);
        label_Bogie3_1->setObjectName(QString::fromUtf8("label_Bogie3_1"));
        label_Bogie3_1->setGeometry(QRect(658, 230, 101, 30));
        label_Bogie4_1 = new QLabel(BrakeSelfCheckPage);
        label_Bogie4_1->setObjectName(QString::fromUtf8("label_Bogie4_1"));
        label_Bogie4_1->setGeometry(QRect(846, 230, 91, 30));
        btn_antiSlip = new QPushButton(BrakeSelfCheckPage);
        btn_antiSlip->setObjectName(QString::fromUtf8("btn_antiSlip"));
        btn_antiSlip->setGeometry(QRect(440, 300, 98, 40));
        btn_brakeDetect = new QPushButton(BrakeSelfCheckPage);
        btn_brakeDetect->setObjectName(QString::fromUtf8("btn_brakeDetect"));
        btn_brakeDetect->setGeometry(QRect(320, 300, 98, 40));
        btn_serialDetect = new QPushButton(BrakeSelfCheckPage);
        btn_serialDetect->setObjectName(QString::fromUtf8("btn_serialDetect"));
        btn_serialDetect->setGeometry(QRect(200, 300, 98, 40));
        label_errorInfo = new QLabel(BrakeSelfCheckPage);
        label_errorInfo->setObjectName(QString::fromUtf8("label_errorInfo"));
        label_errorInfo->setGeometry(QRect(40, 510, 651, 111));
        label_errorInfo->setStyleSheet(QString::fromUtf8("border-color:black;\n"
"color: red;\n"
"font:20px, \"SimHei\";	"));
        label_time = new QLabel(BrakeSelfCheckPage);
        label_time->setObjectName(QString::fromUtf8("label_time"));
        label_time->setGeometry(QRect(24, 170, 170, 30));
        label_time2 = new QLabel(BrakeSelfCheckPage);
        label_time2->setObjectName(QString::fromUtf8("label_time2"));
        label_time2->setGeometry(QRect(560, 170, 377, 30));
        label_time1 = new QLabel(BrakeSelfCheckPage);
        label_time1->setObjectName(QString::fromUtf8("label_time1"));
        label_time1->setGeometry(QRect(193, 170, 369, 30));
        label_prepare = new QLabel(BrakeSelfCheckPage);
        label_prepare->setObjectName(QString::fromUtf8("label_prepare"));
        label_prepare->setGeometry(QRect(24, 200, 170, 30));
        label_prepare2 = new QLabel(BrakeSelfCheckPage);
        label_prepare2->setObjectName(QString::fromUtf8("label_prepare2"));
        label_prepare2->setGeometry(QRect(560, 200, 377, 30));
        label_prepare1 = new QLabel(BrakeSelfCheckPage);
        label_prepare1->setObjectName(QString::fromUtf8("label_prepare1"));
        label_prepare1->setGeometry(QRect(193, 200, 369, 30));
        label_slideDetect_2 = new QLabel(BrakeSelfCheckPage);
        label_slideDetect_2->setObjectName(QString::fromUtf8("label_slideDetect_2"));
        label_slideDetect_2->setGeometry(QRect(60, 450, 101, 40));
        label_slideDetect_2->setStyleSheet(QString::fromUtf8("border-color:black;"));
        label_slideDetect_3 = new QLabel(BrakeSelfCheckPage);
        label_slideDetect_3->setObjectName(QString::fromUtf8("label_slideDetect_3"));
        label_slideDetect_3->setGeometry(QRect(180, 450, 91, 40));
        label_slideDetect_3->setStyleSheet(QString::fromUtf8("background-color:rgb(0, 255, 0);"));
        label_slideDetect_4 = new QLabel(BrakeSelfCheckPage);
        label_slideDetect_4->setObjectName(QString::fromUtf8("label_slideDetect_4"));
        label_slideDetect_4->setGeometry(QRect(440, 450, 91, 40));
        label_slideDetect_4->setStyleSheet(QString::fromUtf8("background-color: red;"));
        label_slideDetect_5 = new QLabel(BrakeSelfCheckPage);
        label_slideDetect_5->setObjectName(QString::fromUtf8("label_slideDetect_5"));
        label_slideDetect_5->setGeometry(QRect(280, 450, 91, 40));
        label_slideDetect_5->setStyleSheet(QString::fromUtf8("border-color:black;"));
        label_slideDetect_6 = new QLabel(BrakeSelfCheckPage);
        label_slideDetect_6->setObjectName(QString::fromUtf8("label_slideDetect_6"));
        label_slideDetect_6->setGeometry(QRect(530, 450, 131, 40));
        label_slideDetect_6->setStyleSheet(QString::fromUtf8("border-color:black;"));
        label_timeout = new QLabel(BrakeSelfCheckPage);
        label_timeout->setObjectName(QString::fromUtf8("label_timeout"));
        label_timeout->setGeometry(QRect(50, 630, 101, 40));
        label_timeout->setStyleSheet(QString::fromUtf8("border-color:black;\n"
"color: red;\n"
"font:20px, \"SimHei\";	"));
        btn_keepBrake = new QPushButton(BrakeSelfCheckPage);
        btn_keepBrake->setObjectName(QString::fromUtf8("btn_keepBrake"));
        btn_keepBrake->setGeometry(QRect(750, 420, 145, 40));

        retranslateUi(BrakeSelfCheckPage);

        QMetaObject::connectSlotsByName(BrakeSelfCheckPage);
    } // setupUi

    void retranslateUi(QWidget *BrakeSelfCheckPage)
    {
        BrakeSelfCheckPage->setWindowTitle(QApplication::translate("BrakeSelfCheckPage", "Form", 0, QApplication::UnicodeUTF8));
        label_Bogie3_2->setText(QString());
        label_Bogie2_1->setText(QString());
        label_CAR2_DI1->setText(QApplication::translate("BrakeSelfCheckPage", "2", 0, QApplication::UnicodeUTF8));
        label_slideDetect->setText(QApplication::translate("BrakeSelfCheckPage", "\350\207\252\346\243\200\345\206\205\345\256\271", 0, QApplication::UnicodeUTF8));
        label_CAR4_DI1->setText(QApplication::translate("BrakeSelfCheckPage", "4", 0, QApplication::UnicodeUTF8));
        label_Bogie1_1->setText(QString());
        label_No->setText(QApplication::translate("BrakeSelfCheckPage", "\350\275\246\345\217\267", 0, QApplication::UnicodeUTF8));
        label_BogieCut->setText(QApplication::translate("BrakeSelfCheckPage", "\350\275\254\345\220\221\346\236\266\350\207\252\346\243\200\347\273\223\346\236\234", 0, QApplication::UnicodeUTF8));
        label_CAR3_DI1->setText(QApplication::translate("BrakeSelfCheckPage", "3", 0, QApplication::UnicodeUTF8));
        label_Bogie4_2->setText(QString());
        label_CAR1_DI1->setText(QApplication::translate("BrakeSelfCheckPage", "1", 0, QApplication::UnicodeUTF8));
        label_22->setText(QApplication::translate("BrakeSelfCheckPage", "\346\214\211\344\270\213\357\274\273\345\274\200\345\247\213\357\274\275\351\224\256\357\274\214\350\277\233\350\241\214\345\210\266\345\212\250\350\207\252\346\243\200\343\200\202\346\214\211\344\270\213\357\274\273\345\201\234\346\255\242\357\274\275\351\224\256\357\274\214\345\201\234\346\255\242\345\210\266\345\212\250\350\207\252\346\243\200\343\200\202", 0, QApplication::UnicodeUTF8));
        label_23->setText(QApplication::translate("BrakeSelfCheckPage", "\357\274\273\346\263\250\346\204\217\357\274\275\350\207\252\346\243\200\350\277\233\350\241\214\344\270\255\350\257\267\344\277\235\346\214\201\346\234\254\351\241\265\351\235\242\357\274\214\345\210\207\346\215\242\345\210\260\345\205\266\344\273\226\351\241\265\351\235\242\344\274\232\347\273\210\346\255\242\350\207\252\346\243\200\343\200\202", 0, QApplication::UnicodeUTF8));
        btn_start->setText(QApplication::translate("BrakeSelfCheckPage", "\345\274\200\345\247\213", 0, QApplication::UnicodeUTF8));
        btn_cease->setText(QApplication::translate("BrakeSelfCheckPage", "\345\201\234\346\255\242", 0, QApplication::UnicodeUTF8));
        btn_exit->setText(QApplication::translate("BrakeSelfCheckPage", "\351\200\200\345\207\272", 0, QApplication::UnicodeUTF8));
        label_Bogie1_2->setText(QString());
        label_Bogie2_2->setText(QString());
        label_Bogie3_1->setText(QString());
        label_Bogie4_1->setText(QString());
        btn_antiSlip->setText(QApplication::translate("BrakeSelfCheckPage", "\351\230\262\346\273\221\350\207\252\346\243\200", 0, QApplication::UnicodeUTF8));
        btn_brakeDetect->setText(QApplication::translate("BrakeSelfCheckPage", "\345\210\266\345\212\250\350\207\252\346\243\200", 0, QApplication::UnicodeUTF8));
        btn_serialDetect->setText(QApplication::translate("BrakeSelfCheckPage", "\350\277\236\347\273\255\350\207\252\346\243\200", 0, QApplication::UnicodeUTF8));
        label_errorInfo->setText(QApplication::translate("BrakeSelfCheckPage", "\350\207\252\346\243\200\346\235\241\344\273\266\344\270\215\346\273\241\350\266\263\357\274\214\350\257\267\346\243\200\346\237\245\344\273\245\344\270\213\346\235\241\344\273\266\346\230\257\345\220\246\346\273\241\350\266\263\357\274\232\n"
"1 \345\210\227\350\275\246\346\234\252\346\226\275\345\212\240\347\264\247\346\200\245\345\210\266\345\212\250   2 \345\210\227\350\275\246\346\234\252\346\226\275\345\212\240\345\274\272\350\277\253\347\274\223\350\247\243\357\274\210\345\274\272\350\277\253\347\274\223\350\247\243\346\214\211\351\222\256\347\201\257\347\201\255\357\274\211\n"
"3 \345\210\227\350\275\246\345\244\204\344\272\216\351\235\231\346\255\242\347\212\266\346\200\201     4 \346\200\273\351\243\216\345\216\213\345\212\233\345\244\247\344\272\2167.0bar\n"
"5 \346\211\200\346\234\211\350\275\246\350\276\206\345\210\266\345\212\250\345\202\250\351\243\216\347\274\270\345\216\213\345\212\233\345\244\247\344\272\2166.5bar", 0, QApplication::UnicodeUTF8));
        label_time->setText(QApplication::translate("BrakeSelfCheckPage", "\346\234\252\350\207\252\346\243\200\346\227\266\351\227\264", 0, QApplication::UnicodeUTF8));
        label_time2->setText(QString());
        label_time1->setText(QString());
        label_prepare->setText(QApplication::translate("BrakeSelfCheckPage", "\350\207\252\346\243\200\345\207\206\345\244\207", 0, QApplication::UnicodeUTF8));
        label_prepare2->setText(QString());
        label_prepare1->setText(QString());
        label_slideDetect_2->setText(QApplication::translate("BrakeSelfCheckPage", "\350\207\252\346\243\200\345\207\206\345\244\207\357\274\232", 0, QApplication::UnicodeUTF8));
        label_slideDetect_3->setText(QString());
        label_slideDetect_4->setText(QString());
        label_slideDetect_5->setText(QApplication::translate("BrakeSelfCheckPage", "\346\235\241\344\273\266\346\273\241\350\266\263", 0, QApplication::UnicodeUTF8));
        label_slideDetect_6->setText(QApplication::translate("BrakeSelfCheckPage", "\346\235\241\344\273\266\346\234\252\346\273\241\350\266\263", 0, QApplication::UnicodeUTF8));
        label_timeout->setText(QApplication::translate("BrakeSelfCheckPage", "\350\207\252\346\243\200\350\266\205\346\227\266\357\274\201", 0, QApplication::UnicodeUTF8));
        btn_keepBrake->setText(QApplication::translate("BrakeSelfCheckPage", "\344\277\235\346\214\201\345\210\266\345\212\250\345\210\207\351\231\244", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BrakeSelfCheckPage: public Ui_BrakeSelfCheckPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BRAKESELFCHECKPAGE_H
