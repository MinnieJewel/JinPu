/********************************************************************************
** Form generated from reading UI file 'brakestatehelppage2.ui'
**
** Created: Thu Jan 11 11:16:18 2018
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BRAKESTATEHELPPAGE2_H
#define UI_BRAKESTATEHELPPAGE2_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BrakestateHelpPage2
{
public:
    QLabel *label_voltage4_1;
    QLabel *label_viewItem;
    QLabel *label_breakLevel1_2;
    QLabel *label_voltage1_2;
    QLabel *label_current1_1;
    QLabel *label_voltage4_2;
    QLabel *label_current1_2;
    QLabel *label_viewComment;
    QLabel *label_current1;
    QLabel *label_voltage1_1;
    QLabel *label_breakLevel1;
    QLabel *label_voltage3_1;
    QLabel *label_breakLevel1_1;
    QLabel *label_voltage4;
    QLabel *label_voltage3;
    QLabel *label_breakLevel2;
    QLabel *label_breakLevel2_2;
    QLabel *label_current2_2;
    QLabel *label_voltage;
    QLabel *label_voltage3_2;
    QLabel *label_breakLevel2_1;
    QLabel *label_current2_1;
    QLabel *label_voltage1;
    QLabel *label_viewCondition;
    QLabel *label_current2;
    QLabel *label_voltage_2;
    QLabel *label_defaultInfo1_18;
    QLabel *label_defaultInfo1_19;
    QLabel *label_defaultInfo1_20;
    QLabel *label_breakLevel_2;
    QLabel *label_defaultInfo1_21;
    QLabel *label_defaultInfo1_2;
    QLabel *label_defaultInfo1_22;
    QLabel *label_defaultInfo1_23;
    QLabel *label_defaultInfo1_1;
    QLabel *label_defaultInfo1;

    void setupUi(QWidget *BrakestateHelpPage2)
    {
        if (BrakestateHelpPage2->objectName().isEmpty())
            BrakestateHelpPage2->setObjectName(QString::fromUtf8("BrakestateHelpPage2"));
        BrakestateHelpPage2->resize(1024, 708);
        BrakestateHelpPage2->setStyleSheet(QString::fromUtf8("QLabel\n"
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
        label_voltage4_1 = new QLabel(BrakestateHelpPage2);
        label_voltage4_1->setObjectName(QString::fromUtf8("label_voltage4_1"));
        label_voltage4_1->setGeometry(QRect(400, 160, 150, 35));
        label_voltage4_1->setStyleSheet(QString::fromUtf8("background-color: white;"));
        label_viewItem = new QLabel(BrakestateHelpPage2);
        label_viewItem->setObjectName(QString::fromUtf8("label_viewItem"));
        label_viewItem->setGeometry(QRect(400, 55, 150, 35));
        label_viewItem->setStyleSheet(QString::fromUtf8("background-color: rgb(0,255,0);"));
        label_breakLevel1_2 = new QLabel(BrakestateHelpPage2);
        label_breakLevel1_2->setObjectName(QString::fromUtf8("label_breakLevel1_2"));
        label_breakLevel1_2->setGeometry(QRect(550, 265, 474, 35));
        label_voltage1_2 = new QLabel(BrakestateHelpPage2);
        label_voltage1_2->setObjectName(QString::fromUtf8("label_voltage1_2"));
        label_voltage1_2->setGeometry(QRect(550, 90, 474, 35));
        label_current1_1 = new QLabel(BrakestateHelpPage2);
        label_current1_1->setObjectName(QString::fromUtf8("label_current1_1"));
        label_current1_1->setGeometry(QRect(400, 195, 150, 35));
        label_current1_1->setStyleSheet(QString::fromUtf8("background-color: rgb(0,255,0);"));
        label_voltage4_2 = new QLabel(BrakestateHelpPage2);
        label_voltage4_2->setObjectName(QString::fromUtf8("label_voltage4_2"));
        label_voltage4_2->setGeometry(QRect(550, 160, 474, 35));
        label_current1_2 = new QLabel(BrakestateHelpPage2);
        label_current1_2->setObjectName(QString::fromUtf8("label_current1_2"));
        label_current1_2->setGeometry(QRect(550, 195, 474, 35));
        label_viewComment = new QLabel(BrakestateHelpPage2);
        label_viewComment->setObjectName(QString::fromUtf8("label_viewComment"));
        label_viewComment->setGeometry(QRect(550, 55, 474, 35));
        label_current1 = new QLabel(BrakestateHelpPage2);
        label_current1->setObjectName(QString::fromUtf8("label_current1"));
        label_current1->setGeometry(QRect(250, 195, 150, 35));
        label_voltage1_1 = new QLabel(BrakestateHelpPage2);
        label_voltage1_1->setObjectName(QString::fromUtf8("label_voltage1_1"));
        label_voltage1_1->setGeometry(QRect(400, 90, 150, 35));
        label_voltage1_1->setStyleSheet(QString::fromUtf8(""));
        label_breakLevel1 = new QLabel(BrakestateHelpPage2);
        label_breakLevel1->setObjectName(QString::fromUtf8("label_breakLevel1"));
        label_breakLevel1->setGeometry(QRect(250, 265, 150, 35));
        label_voltage3_1 = new QLabel(BrakestateHelpPage2);
        label_voltage3_1->setObjectName(QString::fromUtf8("label_voltage3_1"));
        label_voltage3_1->setGeometry(QRect(400, 125, 150, 35));
        label_voltage3_1->setStyleSheet(QString::fromUtf8("background-color: red;"));
        label_breakLevel1_1 = new QLabel(BrakestateHelpPage2);
        label_breakLevel1_1->setObjectName(QString::fromUtf8("label_breakLevel1_1"));
        label_breakLevel1_1->setGeometry(QRect(400, 265, 150, 35));
        label_breakLevel1_1->setStyleSheet(QString::fromUtf8("background-color: red;"));
        label_voltage4 = new QLabel(BrakestateHelpPage2);
        label_voltage4->setObjectName(QString::fromUtf8("label_voltage4"));
        label_voltage4->setGeometry(QRect(250, 160, 150, 35));
        label_voltage3 = new QLabel(BrakestateHelpPage2);
        label_voltage3->setObjectName(QString::fromUtf8("label_voltage3"));
        label_voltage3->setGeometry(QRect(250, 125, 150, 35));
        label_breakLevel2 = new QLabel(BrakestateHelpPage2);
        label_breakLevel2->setObjectName(QString::fromUtf8("label_breakLevel2"));
        label_breakLevel2->setGeometry(QRect(250, 300, 150, 35));
        label_breakLevel2_2 = new QLabel(BrakestateHelpPage2);
        label_breakLevel2_2->setObjectName(QString::fromUtf8("label_breakLevel2_2"));
        label_breakLevel2_2->setGeometry(QRect(550, 300, 474, 35));
        label_current2_2 = new QLabel(BrakestateHelpPage2);
        label_current2_2->setObjectName(QString::fromUtf8("label_current2_2"));
        label_current2_2->setGeometry(QRect(550, 230, 474, 35));
        label_voltage = new QLabel(BrakestateHelpPage2);
        label_voltage->setObjectName(QString::fromUtf8("label_voltage"));
        label_voltage->setGeometry(QRect(0, 55, 250, 140));
        label_voltage3_2 = new QLabel(BrakestateHelpPage2);
        label_voltage3_2->setObjectName(QString::fromUtf8("label_voltage3_2"));
        label_voltage3_2->setGeometry(QRect(550, 125, 474, 35));
        label_breakLevel2_1 = new QLabel(BrakestateHelpPage2);
        label_breakLevel2_1->setObjectName(QString::fromUtf8("label_breakLevel2_1"));
        label_breakLevel2_1->setGeometry(QRect(400, 300, 150, 35));
        label_breakLevel2_1->setStyleSheet(QString::fromUtf8("background-color: white;"));
        label_current2_1 = new QLabel(BrakestateHelpPage2);
        label_current2_1->setObjectName(QString::fromUtf8("label_current2_1"));
        label_current2_1->setGeometry(QRect(400, 230, 150, 35));
        label_current2_1->setStyleSheet(QString::fromUtf8(""));
        label_voltage1 = new QLabel(BrakestateHelpPage2);
        label_voltage1->setObjectName(QString::fromUtf8("label_voltage1"));
        label_voltage1->setGeometry(QRect(250, 90, 150, 35));
        label_viewCondition = new QLabel(BrakestateHelpPage2);
        label_viewCondition->setObjectName(QString::fromUtf8("label_viewCondition"));
        label_viewCondition->setGeometry(QRect(250, 55, 150, 35));
        label_current2 = new QLabel(BrakestateHelpPage2);
        label_current2->setObjectName(QString::fromUtf8("label_current2"));
        label_current2->setGeometry(QRect(250, 230, 150, 35));
        label_voltage_2 = new QLabel(BrakestateHelpPage2);
        label_voltage_2->setObjectName(QString::fromUtf8("label_voltage_2"));
        label_voltage_2->setGeometry(QRect(0, 195, 250, 140));
        label_defaultInfo1_18 = new QLabel(BrakestateHelpPage2);
        label_defaultInfo1_18->setObjectName(QString::fromUtf8("label_defaultInfo1_18"));
        label_defaultInfo1_18->setGeometry(QRect(400, 370, 150, 35));
        label_defaultInfo1_18->setStyleSheet(QString::fromUtf8(""));
        label_defaultInfo1_19 = new QLabel(BrakestateHelpPage2);
        label_defaultInfo1_19->setObjectName(QString::fromUtf8("label_defaultInfo1_19"));
        label_defaultInfo1_19->setGeometry(QRect(250, 370, 150, 35));
        label_defaultInfo1_20 = new QLabel(BrakestateHelpPage2);
        label_defaultInfo1_20->setObjectName(QString::fromUtf8("label_defaultInfo1_20"));
        label_defaultInfo1_20->setGeometry(QRect(550, 405, 474, 35));
        label_breakLevel_2 = new QLabel(BrakestateHelpPage2);
        label_breakLevel_2->setObjectName(QString::fromUtf8("label_breakLevel_2"));
        label_breakLevel_2->setGeometry(QRect(0, 335, 250, 105));
        label_defaultInfo1_21 = new QLabel(BrakestateHelpPage2);
        label_defaultInfo1_21->setObjectName(QString::fromUtf8("label_defaultInfo1_21"));
        label_defaultInfo1_21->setGeometry(QRect(250, 405, 150, 35));
        label_defaultInfo1_2 = new QLabel(BrakestateHelpPage2);
        label_defaultInfo1_2->setObjectName(QString::fromUtf8("label_defaultInfo1_2"));
        label_defaultInfo1_2->setGeometry(QRect(550, 335, 474, 35));
        label_defaultInfo1_22 = new QLabel(BrakestateHelpPage2);
        label_defaultInfo1_22->setObjectName(QString::fromUtf8("label_defaultInfo1_22"));
        label_defaultInfo1_22->setGeometry(QRect(550, 370, 474, 35));
        label_defaultInfo1_22->setStyleSheet(QString::fromUtf8("font: 13px, \"SimHei\";	"));
        label_defaultInfo1_23 = new QLabel(BrakestateHelpPage2);
        label_defaultInfo1_23->setObjectName(QString::fromUtf8("label_defaultInfo1_23"));
        label_defaultInfo1_23->setGeometry(QRect(400, 405, 150, 35));
        label_defaultInfo1_23->setStyleSheet(QString::fromUtf8("background-color: white;"));
        label_defaultInfo1_1 = new QLabel(BrakestateHelpPage2);
        label_defaultInfo1_1->setObjectName(QString::fromUtf8("label_defaultInfo1_1"));
        label_defaultInfo1_1->setGeometry(QRect(400, 335, 150, 35));
        label_defaultInfo1_1->setStyleSheet(QString::fromUtf8("background-color: rgb(0,255,0);"));
        label_defaultInfo1 = new QLabel(BrakestateHelpPage2);
        label_defaultInfo1->setObjectName(QString::fromUtf8("label_defaultInfo1"));
        label_defaultInfo1->setGeometry(QRect(250, 335, 150, 35));

        retranslateUi(BrakestateHelpPage2);

        QMetaObject::connectSlotsByName(BrakestateHelpPage2);
    } // setupUi

    void retranslateUi(QWidget *BrakestateHelpPage2)
    {
        BrakestateHelpPage2->setWindowTitle(QApplication::translate("BrakestateHelpPage2", "Form", 0, QApplication::UnicodeUTF8));
        label_voltage4_1->setText(QString());
        label_viewItem->setText(QString());
        label_breakLevel1_2->setText(QApplication::translate("BrakestateHelpPage2", "\351\230\262\346\273\221\347\263\273\347\273\237\345\267\245\344\275\234\344\270\215\346\255\243\345\270\270", 0, QApplication::UnicodeUTF8));
        label_voltage1_2->setText(QApplication::translate("BrakestateHelpPage2", "\351\230\262\346\273\221\347\263\273\347\273\237\345\267\245\344\275\234\346\255\243\345\270\270\357\274\214\347\263\273\347\273\237\346\227\240\351\230\262\346\273\221\346\216\247\345\210\266", 0, QApplication::UnicodeUTF8));
        label_current1_1->setText(QString());
        label_voltage4_2->setText(QString());
        label_current1_2->setText(QApplication::translate("BrakestateHelpPage2", "\351\230\262\346\273\221\347\263\273\347\273\237\345\267\245\344\275\234\346\255\243\345\270\270\357\274\214\350\275\264\346\234\211\351\230\262\346\273\221\346\216\247\345\210\266", 0, QApplication::UnicodeUTF8));
        label_viewComment->setText(QApplication::translate("BrakestateHelpPage2", "\351\230\262\346\273\221\347\263\273\347\273\237\345\267\245\344\275\234\346\255\243\345\270\270\357\274\214\347\263\273\347\273\237\346\234\211\351\230\262\346\273\221\346\216\247\345\210\266", 0, QApplication::UnicodeUTF8));
        label_current1->setText(QApplication::translate("BrakestateHelpPage2", "\346\234\211\351\230\262\346\273\221\346\216\247\345\210\266", 0, QApplication::UnicodeUTF8));
        label_voltage1_1->setText(QString());
        label_breakLevel1->setText(QApplication::translate("BrakestateHelpPage2", "\346\225\205\351\232\234", 0, QApplication::UnicodeUTF8));
        label_voltage3_1->setText(QString());
        label_breakLevel1_1->setText(QString());
        label_voltage4->setText(QApplication::translate("BrakestateHelpPage2", "\351\200\232\344\277\241\345\274\202\345\270\270", 0, QApplication::UnicodeUTF8));
        label_voltage3->setText(QApplication::translate("BrakestateHelpPage2", "\346\225\205\351\232\234", 0, QApplication::UnicodeUTF8));
        label_breakLevel2->setText(QApplication::translate("BrakestateHelpPage2", "\351\200\232\344\277\241\345\274\202\345\270\270", 0, QApplication::UnicodeUTF8));
        label_breakLevel2_2->setText(QString());
        label_current2_2->setText(QApplication::translate("BrakestateHelpPage2", "\351\230\262\346\273\221\347\263\273\347\273\237\345\267\245\344\275\234\346\255\243\345\270\270\357\274\214\350\275\264\346\227\240\351\230\262\346\273\221\346\216\247\345\210\266", 0, QApplication::UnicodeUTF8));
        label_voltage->setText(QApplication::translate("BrakestateHelpPage2", "\351\230\262\346\273\221\347\263\273\347\273\237", 0, QApplication::UnicodeUTF8));
        label_voltage3_2->setText(QApplication::translate("BrakestateHelpPage2", "\351\230\262\346\273\221\347\263\273\347\273\237\345\267\245\344\275\234\344\270\215\346\255\243\345\270\270", 0, QApplication::UnicodeUTF8));
        label_breakLevel2_1->setText(QString());
        label_current2_1->setText(QString());
        label_voltage1->setText(QApplication::translate("BrakestateHelpPage2", "\346\227\240\351\230\262\346\273\221\346\216\247\345\210\266", 0, QApplication::UnicodeUTF8));
        label_viewCondition->setText(QApplication::translate("BrakestateHelpPage2", "\346\234\211\351\230\262\346\273\221\346\216\247\345\210\266", 0, QApplication::UnicodeUTF8));
        label_current2->setText(QApplication::translate("BrakestateHelpPage2", "\346\227\240\351\230\262\346\273\221\346\216\247\345\210\266", 0, QApplication::UnicodeUTF8));
        label_voltage_2->setText(QApplication::translate("BrakestateHelpPage2", "\350\275\264\351\230\262\346\273\221", 0, QApplication::UnicodeUTF8));
        label_defaultInfo1_18->setText(QString());
        label_defaultInfo1_19->setText(QApplication::translate("BrakestateHelpPage2", "\346\225\264\350\275\246\345\210\266\345\212\250\346\234\252\345\210\207\351\231\244", 0, QApplication::UnicodeUTF8));
        label_defaultInfo1_20->setText(QString());
        label_breakLevel_2->setText(QApplication::translate("BrakestateHelpPage2", "\346\225\264\350\275\246\345\210\266\345\212\250\345\210\207\351\231\244\n"
"\344\277\235\346\214\201\345\210\266\345\212\250\345\210\207\351\231\244", 0, QApplication::UnicodeUTF8));
        label_defaultInfo1_21->setText(QApplication::translate("BrakestateHelpPage2", "\351\200\232\344\277\241\345\274\202\345\270\270", 0, QApplication::UnicodeUTF8));
        label_defaultInfo1_2->setText(QString());
        label_defaultInfo1_22->setText(QApplication::translate("BrakestateHelpPage2", "\346\225\264\350\275\246\345\210\266\345\212\250\345\210\207\351\231\244\346\227\266\350\257\264\346\230\216\346\227\240\346\255\244\347\212\266\346\200\201\357\274\214\344\277\235\346\214\201\345\210\266\345\212\250\345\210\207\351\231\244\346\227\266\350\241\250\346\230\216\345\217\270\346\234\272\345\256\244\346\234\252\346\277\200\346\264\273\346\210\226\350\200\205\346\227\240\346\255\244\347\212\266\346\200\201", 0, QApplication::UnicodeUTF8));
        label_defaultInfo1_23->setText(QString());
        label_defaultInfo1_1->setText(QString());
        label_defaultInfo1->setText(QApplication::translate("BrakestateHelpPage2", "\346\225\264\350\275\246\345\210\266\345\212\250\345\210\207\351\231\244", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BrakestateHelpPage2: public Ui_BrakestateHelpPage2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BRAKESTATEHELPPAGE2_H
