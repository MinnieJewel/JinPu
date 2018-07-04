/********************************************************************************
** Form generated from reading UI file 'wheeldiaset.ui'
**
** Created: Thu May 24 10:33:18 2018
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WHEELDIASET_H
#define UI_WHEELDIASET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WheelDiaSet
{
public:
    QLabel *label_carNo4;
    QLabel *label_wheelDia;
    QLabel *label_carNo;
    QPushButton *btn_clear;
    QPushButton *btn_back;
    QLabel *label_carNo2;
    QLabel *label_carNo1;
    QLabel *label_carNo3;
    QPushButton *btn_wheelDia1;
    QPushButton *btn_wheelDia2;
    QPushButton *btn_wheelDia3;
    QPushButton *btn_wheelDia4;
    QPushButton *btn_confirm;
    QPushButton *btn_1;
    QPushButton *btn_2;
    QPushButton *btn_3;
    QPushButton *btn_4;
    QPushButton *btn_5;
    QPushButton *btn_6;
    QPushButton *btn_7;
    QPushButton *btn_8;
    QPushButton *btn_9;
    QPushButton *btn_0;
    QLabel *label_errorInfo;
    QLabel *label_original3;
    QLabel *label_original1;
    QLabel *label_original;
    QLabel *label_original2;
    QLabel *label_original4;

    void setupUi(QWidget *WheelDiaSet)
    {
        if (WheelDiaSet->objectName().isEmpty())
            WheelDiaSet->setObjectName(QString::fromUtf8("WheelDiaSet"));
        WheelDiaSet->resize(1024, 688);
        WheelDiaSet->setStyleSheet(QString::fromUtf8("QLabel\n"
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
"}"));
        label_carNo4 = new QLabel(WheelDiaSet);
        label_carNo4->setObjectName(QString::fromUtf8("label_carNo4"));
        label_carNo4->setGeometry(QRect(800, 72, 180, 30));
        label_wheelDia = new QLabel(WheelDiaSet);
        label_wheelDia->setObjectName(QString::fromUtf8("label_wheelDia"));
        label_wheelDia->setGeometry(QRect(64, 130, 130, 30));
        label_wheelDia->setStyleSheet(QString::fromUtf8(""));
        label_carNo = new QLabel(WheelDiaSet);
        label_carNo->setObjectName(QString::fromUtf8("label_carNo"));
        label_carNo->setGeometry(QRect(64, 72, 130, 30));
        btn_clear = new QPushButton(WheelDiaSet);
        btn_clear->setObjectName(QString::fromUtf8("btn_clear"));
        btn_clear->setGeometry(QRect(620, 350, 90, 40));
        btn_clear->setStyleSheet(QString::fromUtf8("QPushButton{font: 20px, \"SimHei\";\n"
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
        btn_back = new QPushButton(WheelDiaSet);
        btn_back->setObjectName(QString::fromUtf8("btn_back"));
        btn_back->setGeometry(QRect(920, 350, 90, 40));
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
        label_carNo2 = new QLabel(WheelDiaSet);
        label_carNo2->setObjectName(QString::fromUtf8("label_carNo2"));
        label_carNo2->setGeometry(QRect(382, 72, 210, 30));
        label_carNo1 = new QLabel(WheelDiaSet);
        label_carNo1->setObjectName(QString::fromUtf8("label_carNo1"));
        label_carNo1->setGeometry(QRect(193, 72, 190, 30));
        label_carNo3 = new QLabel(WheelDiaSet);
        label_carNo3->setObjectName(QString::fromUtf8("label_carNo3"));
        label_carNo3->setGeometry(QRect(591, 72, 210, 30));
        btn_wheelDia1 = new QPushButton(WheelDiaSet);
        btn_wheelDia1->setObjectName(QString::fromUtf8("btn_wheelDia1"));
        btn_wheelDia1->setGeometry(QRect(195, 130, 188, 29));
        btn_wheelDia1->setStyleSheet(QString::fromUtf8("font: 20px, \"SimHei\";\n"
"color: black;\n"
"background-color: rgb(250, 250, 250);\n"
"border: 2px solid rgb(117,117,117);\n"
"\n"
"\n"
""));
        btn_wheelDia2 = new QPushButton(WheelDiaSet);
        btn_wheelDia2->setObjectName(QString::fromUtf8("btn_wheelDia2"));
        btn_wheelDia2->setGeometry(QRect(383, 130, 210, 29));
        btn_wheelDia2->setStyleSheet(QString::fromUtf8("font: 20px, \"SimHei\";\n"
"color: black;\n"
"background-color: rgb(250, 250, 250);\n"
"border: 2px solid rgb(117,117,117);"));
        btn_wheelDia3 = new QPushButton(WheelDiaSet);
        btn_wheelDia3->setObjectName(QString::fromUtf8("btn_wheelDia3"));
        btn_wheelDia3->setGeometry(QRect(592, 130, 210, 29));
        btn_wheelDia3->setStyleSheet(QString::fromUtf8("font: 20px, \"SimHei\";\n"
"color: black;\n"
"background-color: rgb(250, 250, 250);\n"
"border: 2px solid rgb(117,117,117);"));
        btn_wheelDia4 = new QPushButton(WheelDiaSet);
        btn_wheelDia4->setObjectName(QString::fromUtf8("btn_wheelDia4"));
        btn_wheelDia4->setGeometry(QRect(801, 130, 180, 29));
        btn_wheelDia4->setStyleSheet(QString::fromUtf8("font: 20px, \"SimHei\";\n"
"color: black;\n"
"background-color: rgb(250, 250, 250);\n"
"border: 2px solid rgb(117,117,117);"));
        btn_confirm = new QPushButton(WheelDiaSet);
        btn_confirm->setObjectName(QString::fromUtf8("btn_confirm"));
        btn_confirm->setGeometry(QRect(820, 350, 90, 40));
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
        btn_1 = new QPushButton(WheelDiaSet);
        btn_1->setObjectName(QString::fromUtf8("btn_1"));
        btn_1->setGeometry(QRect(20, 430, 90, 40));
        btn_1->setStyleSheet(QString::fromUtf8("font: 20px, \"SimHei\";\n"
"    color: black;\n"
"	background-color: rgb(250, 250, 250);\n"
"	border-radius: 5px;"));
        btn_2 = new QPushButton(WheelDiaSet);
        btn_2->setObjectName(QString::fromUtf8("btn_2"));
        btn_2->setGeometry(QRect(120, 430, 90, 40));
        btn_2->setStyleSheet(QString::fromUtf8("font: 20px, \"SimHei\";\n"
"    color: black;\n"
"	background-color: rgb(250, 250, 250);\n"
"	border-radius: 5px;"));
        btn_3 = new QPushButton(WheelDiaSet);
        btn_3->setObjectName(QString::fromUtf8("btn_3"));
        btn_3->setGeometry(QRect(220, 430, 90, 40));
        btn_3->setStyleSheet(QString::fromUtf8("font: 20px, \"SimHei\";\n"
"    color: black;\n"
"	background-color: rgb(250, 250, 250);\n"
"	border-radius: 5px;"));
        btn_4 = new QPushButton(WheelDiaSet);
        btn_4->setObjectName(QString::fromUtf8("btn_4"));
        btn_4->setGeometry(QRect(320, 430, 90, 40));
        btn_4->setStyleSheet(QString::fromUtf8("font: 20px, \"SimHei\";\n"
"    color: black;\n"
"	background-color: rgb(250, 250, 250);\n"
"	border-radius: 5px;"));
        btn_5 = new QPushButton(WheelDiaSet);
        btn_5->setObjectName(QString::fromUtf8("btn_5"));
        btn_5->setGeometry(QRect(420, 430, 90, 40));
        btn_5->setStyleSheet(QString::fromUtf8("font: 20px, \"SimHei\";\n"
"    color: black;\n"
"	background-color: rgb(250, 250, 250);\n"
"	border-radius: 5px;"));
        btn_6 = new QPushButton(WheelDiaSet);
        btn_6->setObjectName(QString::fromUtf8("btn_6"));
        btn_6->setGeometry(QRect(520, 430, 90, 40));
        btn_6->setStyleSheet(QString::fromUtf8("font: 20px, \"SimHei\";\n"
"    color: black;\n"
"	background-color: rgb(250, 250, 250);\n"
"	border-radius: 5px;"));
        btn_7 = new QPushButton(WheelDiaSet);
        btn_7->setObjectName(QString::fromUtf8("btn_7"));
        btn_7->setGeometry(QRect(620, 430, 90, 40));
        btn_7->setStyleSheet(QString::fromUtf8("font: 20px, \"SimHei\";\n"
"    color: black;\n"
"	background-color: rgb(250, 250, 250);\n"
"	border-radius: 5px;"));
        btn_8 = new QPushButton(WheelDiaSet);
        btn_8->setObjectName(QString::fromUtf8("btn_8"));
        btn_8->setGeometry(QRect(720, 430, 90, 40));
        btn_8->setStyleSheet(QString::fromUtf8("font: 20px, \"SimHei\";\n"
"    color: black;\n"
"	background-color: rgb(250, 250, 250);\n"
"	border-radius: 5px;"));
        btn_9 = new QPushButton(WheelDiaSet);
        btn_9->setObjectName(QString::fromUtf8("btn_9"));
        btn_9->setGeometry(QRect(820, 430, 90, 40));
        btn_9->setStyleSheet(QString::fromUtf8("font: 20px, \"SimHei\";\n"
"    color: black;\n"
"	background-color: rgb(250, 250, 250);\n"
"	border-radius: 5px;"));
        btn_0 = new QPushButton(WheelDiaSet);
        btn_0->setObjectName(QString::fromUtf8("btn_0"));
        btn_0->setGeometry(QRect(920, 430, 90, 40));
        btn_0->setStyleSheet(QString::fromUtf8("font: 20px, \"SimHei\";\n"
"    color: black;\n"
"	background-color: rgb(250, 250, 250);\n"
"	border-radius: 5px;"));
        label_errorInfo = new QLabel(WheelDiaSet);
        label_errorInfo->setObjectName(QString::fromUtf8("label_errorInfo"));
        label_errorInfo->setGeometry(QRect(100, 300, 611, 41));
        label_errorInfo->setStyleSheet(QString::fromUtf8("border-width:0;\n"
"color:red;"));
        label_original3 = new QLabel(WheelDiaSet);
        label_original3->setObjectName(QString::fromUtf8("label_original3"));
        label_original3->setGeometry(QRect(591, 101, 210, 30));
        label_original1 = new QLabel(WheelDiaSet);
        label_original1->setObjectName(QString::fromUtf8("label_original1"));
        label_original1->setGeometry(QRect(193, 101, 190, 30));
        label_original = new QLabel(WheelDiaSet);
        label_original->setObjectName(QString::fromUtf8("label_original"));
        label_original->setGeometry(QRect(64, 101, 130, 30));
        label_original2 = new QLabel(WheelDiaSet);
        label_original2->setObjectName(QString::fromUtf8("label_original2"));
        label_original2->setGeometry(QRect(382, 101, 210, 30));
        label_original4 = new QLabel(WheelDiaSet);
        label_original4->setObjectName(QString::fromUtf8("label_original4"));
        label_original4->setGeometry(QRect(800, 101, 180, 30));

        retranslateUi(WheelDiaSet);

        QMetaObject::connectSlotsByName(WheelDiaSet);
    } // setupUi

    void retranslateUi(QWidget *WheelDiaSet)
    {
        WheelDiaSet->setWindowTitle(QApplication::translate("WheelDiaSet", "Form", 0, QApplication::UnicodeUTF8));
        label_carNo4->setText(QApplication::translate("WheelDiaSet", "4", 0, QApplication::UnicodeUTF8));
        label_wheelDia->setText(QApplication::translate("WheelDiaSet", "\350\275\256\345\276\204\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        label_carNo->setText(QApplication::translate("WheelDiaSet", "\350\275\246\345\217\267", 0, QApplication::UnicodeUTF8));
        btn_clear->setText(QApplication::translate("WheelDiaSet", "\346\270\205\347\251\272", 0, QApplication::UnicodeUTF8));
        btn_back->setText(QApplication::translate("WheelDiaSet", "\350\277\224\345\233\236", 0, QApplication::UnicodeUTF8));
        label_carNo2->setText(QApplication::translate("WheelDiaSet", "2", 0, QApplication::UnicodeUTF8));
        label_carNo1->setText(QApplication::translate("WheelDiaSet", "1", 0, QApplication::UnicodeUTF8));
        label_carNo3->setText(QApplication::translate("WheelDiaSet", "3", 0, QApplication::UnicodeUTF8));
        btn_wheelDia1->setText(QString());
        btn_wheelDia2->setText(QString());
        btn_wheelDia3->setText(QString());
        btn_wheelDia4->setText(QString());
        btn_confirm->setText(QApplication::translate("WheelDiaSet", "\347\241\256\350\256\244", 0, QApplication::UnicodeUTF8));
        btn_1->setText(QApplication::translate("WheelDiaSet", "1", 0, QApplication::UnicodeUTF8));
        btn_2->setText(QApplication::translate("WheelDiaSet", "2", 0, QApplication::UnicodeUTF8));
        btn_3->setText(QApplication::translate("WheelDiaSet", "3", 0, QApplication::UnicodeUTF8));
        btn_4->setText(QApplication::translate("WheelDiaSet", "4", 0, QApplication::UnicodeUTF8));
        btn_5->setText(QApplication::translate("WheelDiaSet", "5", 0, QApplication::UnicodeUTF8));
        btn_6->setText(QApplication::translate("WheelDiaSet", "6", 0, QApplication::UnicodeUTF8));
        btn_7->setText(QApplication::translate("WheelDiaSet", "7", 0, QApplication::UnicodeUTF8));
        btn_8->setText(QApplication::translate("WheelDiaSet", "8", 0, QApplication::UnicodeUTF8));
        btn_9->setText(QApplication::translate("WheelDiaSet", "9", 0, QApplication::UnicodeUTF8));
        btn_0->setText(QApplication::translate("WheelDiaSet", "0", 0, QApplication::UnicodeUTF8));
        label_errorInfo->setText(QApplication::translate("WheelDiaSet", "\350\256\276\347\275\256\345\244\261\350\264\245\357\274\214\350\275\256\345\276\204\345\200\274\351\235\236\346\263\225\357\274\214\346\226\260\350\275\256\345\276\204\345\200\274\345\277\205\351\241\273\345\234\250\357\274\273770mm\357\274\214840mm\357\274\275\345\214\272\351\227\264\345\205\247\357\274\201", 0, QApplication::UnicodeUTF8));
        label_original3->setText(QString());
        label_original1->setText(QString());
        label_original->setText(QApplication::translate("WheelDiaSet", "\345\216\237\350\275\256\345\276\204\345\200\274", 0, QApplication::UnicodeUTF8));
        label_original2->setText(QString());
        label_original4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class WheelDiaSet: public Ui_WheelDiaSet {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WHEELDIASET_H
