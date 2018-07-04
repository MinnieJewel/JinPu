/********************************************************************************
** Form generated from reading UI file 'timesetpage.ui'
**
** Created: Wed Mar 28 10:57:15 2018
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIMESETPAGE_H
#define UI_TIMESETPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TimeSetPage
{
public:
    QPushButton *btn_9;
    QPushButton *btn_4;
    QPushButton *btn_6;
    QPushButton *btn_1;
    QPushButton *btn_0;
    QPushButton *btn_Clear;
    QPushButton *btn_5;
    QPushButton *btn_3;
    QPushButton *btn_2;
    QPushButton *btn_8;
    QPushButton *btn_7;
    QPushButton *btn_confirm;
    QPushButton *btn_back;
    QLabel *label_year;
    QLabel *label_month;
    QLabel *label_day;
    QLabel *label_minute;
    QLabel *label_hour;
    QLabel *label_second;
    QPushButton *btn_year;
    QPushButton *btn_month;
    QPushButton *btn_day;
    QPushButton *btn_second;
    QPushButton *btn_minute;
    QPushButton *btn_hour;
    QLabel *label_errorInfo;

    void setupUi(QWidget *TimeSetPage)
    {
        if (TimeSetPage->objectName().isEmpty())
            TimeSetPage->setObjectName(QString::fromUtf8("TimeSetPage"));
        TimeSetPage->resize(1024, 688);
        TimeSetPage->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	color: white;\n"
"\n"
"    border-color: gray;\n"
"	font: 20px, \"SimHei\";	\n"
"}\n"
"\n"
"QWidget\n"
"{\n"
"	background-color: black;\n"
"}\n"
"\n"
""));
        btn_9 = new QPushButton(TimeSetPage);
        btn_9->setObjectName(QString::fromUtf8("btn_9"));
        btn_9->setGeometry(QRect(810, 110, 80, 80));
        btn_9->setStyleSheet(QString::fromUtf8("	border-radius: 5px;\n"
"	font: 20px, \"SimHei\";\n"
"    color: black;\n"
"	background-color: rgb(250, 250, 250);"));
        btn_4 = new QPushButton(TimeSetPage);
        btn_4->setObjectName(QString::fromUtf8("btn_4"));
        btn_4->setGeometry(QRect(630, 200, 80, 80));
        btn_4->setStyleSheet(QString::fromUtf8("	border-radius: 5px;\n"
"	font: 20px, \"SimHei\";\n"
"    color: black;\n"
"	background-color: rgb(250, 250, 250);"));
        btn_6 = new QPushButton(TimeSetPage);
        btn_6->setObjectName(QString::fromUtf8("btn_6"));
        btn_6->setGeometry(QRect(810, 200, 80, 80));
        btn_6->setStyleSheet(QString::fromUtf8("	border-radius: 5px;\n"
"	font: 20px, \"SimHei\";\n"
"    color: black;\n"
"	background-color: rgb(250, 250, 250);"));
        btn_1 = new QPushButton(TimeSetPage);
        btn_1->setObjectName(QString::fromUtf8("btn_1"));
        btn_1->setGeometry(QRect(630, 290, 80, 80));
        btn_1->setStyleSheet(QString::fromUtf8("	border-radius: 5px;\n"
"	font: 20px, \"SimHei\";\n"
"    color: black;\n"
"	background-color: rgb(250, 250, 250);"));
        btn_0 = new QPushButton(TimeSetPage);
        btn_0->setObjectName(QString::fromUtf8("btn_0"));
        btn_0->setGeometry(QRect(630, 380, 80, 80));
        btn_0->setStyleSheet(QString::fromUtf8("	border-radius: 5px;\n"
"	font: 20px, \"SimHei\";\n"
"    color: black;\n"
"	background-color: rgb(250, 250, 250);"));
        btn_Clear = new QPushButton(TimeSetPage);
        btn_Clear->setObjectName(QString::fromUtf8("btn_Clear"));
        btn_Clear->setGeometry(QRect(720, 380, 170, 80));
        btn_Clear->setStyleSheet(QString::fromUtf8("	border-radius: 5px;\n"
"	font: 20px, \"SimHei\";\n"
"    color: black;\n"
"	background-color: rgb(250, 250, 250);"));
        btn_5 = new QPushButton(TimeSetPage);
        btn_5->setObjectName(QString::fromUtf8("btn_5"));
        btn_5->setGeometry(QRect(720, 200, 80, 80));
        btn_5->setStyleSheet(QString::fromUtf8("	border-radius: 5px;\n"
"	font: 20px, \"SimHei\";\n"
"    color: black;\n"
"	background-color: rgb(250, 250, 250);"));
        btn_3 = new QPushButton(TimeSetPage);
        btn_3->setObjectName(QString::fromUtf8("btn_3"));
        btn_3->setGeometry(QRect(810, 290, 80, 80));
        btn_3->setStyleSheet(QString::fromUtf8("	border-radius: 5px;\n"
"	font: 20px, \"SimHei\";\n"
"    color: black;\n"
"	background-color: rgb(250, 250, 250);"));
        btn_2 = new QPushButton(TimeSetPage);
        btn_2->setObjectName(QString::fromUtf8("btn_2"));
        btn_2->setGeometry(QRect(720, 290, 80, 80));
        btn_2->setStyleSheet(QString::fromUtf8("	border-radius: 5px;\n"
"	font: 20px, \"SimHei\";\n"
"    color: black;\n"
"	background-color: rgb(250, 250, 250);"));
        btn_8 = new QPushButton(TimeSetPage);
        btn_8->setObjectName(QString::fromUtf8("btn_8"));
        btn_8->setGeometry(QRect(720, 110, 80, 80));
        btn_8->setStyleSheet(QString::fromUtf8("	border-radius: 5px;\n"
"	font: 20px, \"SimHei\";\n"
"    color: black;\n"
"	background-color: rgb(250, 250, 250);"));
        btn_7 = new QPushButton(TimeSetPage);
        btn_7->setObjectName(QString::fromUtf8("btn_7"));
        btn_7->setGeometry(QRect(630, 110, 80, 80));
        btn_7->setStyleSheet(QString::fromUtf8("	border-radius:5px;\n"
"	font: 20px, \"SimHei\";\n"
"    color: black;\n"
"	background-color: rgb(250, 250, 250);"));
        btn_confirm = new QPushButton(TimeSetPage);
        btn_confirm->setObjectName(QString::fromUtf8("btn_confirm"));
        btn_confirm->setGeometry(QRect(630, 530, 98, 40));
        btn_confirm->setStyleSheet(QString::fromUtf8("QPushButton:disabled\n"
"{\n"
"		border-radius:5px;\n"
"	font: 20px, \"SimHei\";\n"
"    color: grey;\n"
"	background-color: rgb(221,221,221);\n"
"}\n"
"	\n"
"QPushButton\n"
"{\n"
"	border-radius: 5px;\n"
"	font: 20px, \"SimHei\";\n"
"    color: black;\n"
"	background-color: rgb(250, 250, 250);\n"
"}"));
        btn_back = new QPushButton(TimeSetPage);
        btn_back->setObjectName(QString::fromUtf8("btn_back"));
        btn_back->setGeometry(QRect(780, 530, 98, 40));
        btn_back->setStyleSheet(QString::fromUtf8("QPushButton:disabled\n"
"{\n"
"		border-radius:5px;\n"
"	font: 20px, \"SimHei\";\n"
"    color: white;\n"
"	background-color: grey;\n"
"}\n"
"	\n"
"QPushButton\n"
"{\n"
"	border-radius: 5px;\n"
"	font: 20px, \"SimHei\";\n"
"    color: black;\n"
"	background-color: rgb(250, 250, 250);\n"
"}\n"
""));
        label_year = new QLabel(TimeSetPage);
        label_year->setObjectName(QString::fromUtf8("label_year"));
        label_year->setGeometry(QRect(160, 150, 21, 41));
        label_year->setStyleSheet(QString::fromUtf8("	color: white;\n"
"	font: 20px, \"SimHei\";	"));
        label_month = new QLabel(TimeSetPage);
        label_month->setObjectName(QString::fromUtf8("label_month"));
        label_month->setGeometry(QRect(360, 150, 21, 41));
        label_month->setStyleSheet(QString::fromUtf8("	color: white;\n"
"	font: 20px, \"SimHei\";	"));
        label_day = new QLabel(TimeSetPage);
        label_day->setObjectName(QString::fromUtf8("label_day"));
        label_day->setGeometry(QRect(560, 150, 21, 41));
        label_day->setStyleSheet(QString::fromUtf8("	color: white;\n"
"	font: 20px, \"SimHei\";	"));
        label_minute = new QLabel(TimeSetPage);
        label_minute->setObjectName(QString::fromUtf8("label_minute"));
        label_minute->setGeometry(QRect(360, 310, 21, 41));
        label_minute->setStyleSheet(QString::fromUtf8("	color: white;\n"
"	font: 20px, \"SimHei\";	"));
        label_hour = new QLabel(TimeSetPage);
        label_hour->setObjectName(QString::fromUtf8("label_hour"));
        label_hour->setGeometry(QRect(160, 310, 21, 41));
        label_hour->setStyleSheet(QString::fromUtf8("	color: white;\n"
"	font: 20px, \"SimHei\";	"));
        label_second = new QLabel(TimeSetPage);
        label_second->setObjectName(QString::fromUtf8("label_second"));
        label_second->setGeometry(QRect(560, 310, 21, 41));
        label_second->setStyleSheet(QString::fromUtf8("	color: white;\n"
"	font: 20px, \"SimHei\";	"));
        btn_year = new QPushButton(TimeSetPage);
        btn_year->setObjectName(QString::fromUtf8("btn_year"));
        btn_year->setGeometry(QRect(30, 150, 111, 40));
        btn_year->setStyleSheet(QString::fromUtf8("	border-radius: 0px;\n"
"	font: 20px, \"SimHei\";\n"
"    color: black;\n"
"	background-color: rgb(250, 250, 250);"));
        btn_month = new QPushButton(TimeSetPage);
        btn_month->setObjectName(QString::fromUtf8("btn_month"));
        btn_month->setGeometry(QRect(230, 150, 111, 40));
        btn_month->setStyleSheet(QString::fromUtf8("	border-radius: 0px;\n"
"	font: 20px, \"SimHei\";\n"
"    color: black;\n"
"	background-color: rgb(250, 250, 250);"));
        btn_day = new QPushButton(TimeSetPage);
        btn_day->setObjectName(QString::fromUtf8("btn_day"));
        btn_day->setGeometry(QRect(430, 150, 111, 40));
        btn_day->setStyleSheet(QString::fromUtf8("	border-radius: 0px;\n"
"	font: 20px, \"SimHei\";\n"
"    color: black;\n"
"	background-color: rgb(250, 250, 250);"));
        btn_second = new QPushButton(TimeSetPage);
        btn_second->setObjectName(QString::fromUtf8("btn_second"));
        btn_second->setGeometry(QRect(430, 310, 111, 40));
        btn_second->setStyleSheet(QString::fromUtf8("	border-radius: 0px;\n"
"	font: 20px, \"SimHei\";\n"
"    color: black;\n"
"	background-color: rgb(250, 250, 250);"));
        btn_minute = new QPushButton(TimeSetPage);
        btn_minute->setObjectName(QString::fromUtf8("btn_minute"));
        btn_minute->setGeometry(QRect(230, 310, 111, 40));
        btn_minute->setStyleSheet(QString::fromUtf8("	border-radius: 0px;\n"
"	font: 20px, \"SimHei\";\n"
"    color: black;\n"
"	background-color: rgb(250, 250, 250);"));
        btn_hour = new QPushButton(TimeSetPage);
        btn_hour->setObjectName(QString::fromUtf8("btn_hour"));
        btn_hour->setGeometry(QRect(30, 310, 111, 40));
        btn_hour->setStyleSheet(QString::fromUtf8("	border-radius: 0px;\n"
"	font: 20px, \"SimHei\";\n"
"    color: black;\n"
"	background-color: rgb(250, 250, 250);"));
        label_errorInfo = new QLabel(TimeSetPage);
        label_errorInfo->setObjectName(QString::fromUtf8("label_errorInfo"));
        label_errorInfo->setGeometry(QRect(170, 450, 281, 31));
        label_errorInfo->setStyleSheet(QString::fromUtf8("color:red;"));

        retranslateUi(TimeSetPage);

        QMetaObject::connectSlotsByName(TimeSetPage);
    } // setupUi

    void retranslateUi(QWidget *TimeSetPage)
    {
        TimeSetPage->setWindowTitle(QApplication::translate("TimeSetPage", "Form", 0, QApplication::UnicodeUTF8));
        btn_9->setText(QApplication::translate("TimeSetPage", "9", 0, QApplication::UnicodeUTF8));
        btn_4->setText(QApplication::translate("TimeSetPage", "4", 0, QApplication::UnicodeUTF8));
        btn_6->setText(QApplication::translate("TimeSetPage", "6", 0, QApplication::UnicodeUTF8));
        btn_1->setText(QApplication::translate("TimeSetPage", "1", 0, QApplication::UnicodeUTF8));
        btn_0->setText(QApplication::translate("TimeSetPage", "0", 0, QApplication::UnicodeUTF8));
        btn_Clear->setText(QApplication::translate("TimeSetPage", "\346\270\205\347\251\272", 0, QApplication::UnicodeUTF8));
        btn_5->setText(QApplication::translate("TimeSetPage", "5", 0, QApplication::UnicodeUTF8));
        btn_3->setText(QApplication::translate("TimeSetPage", "3", 0, QApplication::UnicodeUTF8));
        btn_2->setText(QApplication::translate("TimeSetPage", "2", 0, QApplication::UnicodeUTF8));
        btn_8->setText(QApplication::translate("TimeSetPage", "8", 0, QApplication::UnicodeUTF8));
        btn_7->setText(QApplication::translate("TimeSetPage", "7", 0, QApplication::UnicodeUTF8));
        btn_confirm->setText(QApplication::translate("TimeSetPage", "\347\241\256\350\256\244", 0, QApplication::UnicodeUTF8));
        btn_back->setText(QApplication::translate("TimeSetPage", "\350\277\224\345\233\236", 0, QApplication::UnicodeUTF8));
        label_year->setText(QApplication::translate("TimeSetPage", "\345\271\264", 0, QApplication::UnicodeUTF8));
        label_month->setText(QApplication::translate("TimeSetPage", "\346\234\210", 0, QApplication::UnicodeUTF8));
        label_day->setText(QApplication::translate("TimeSetPage", "\346\227\245", 0, QApplication::UnicodeUTF8));
        label_minute->setText(QApplication::translate("TimeSetPage", "\345\210\206", 0, QApplication::UnicodeUTF8));
        label_hour->setText(QApplication::translate("TimeSetPage", "\346\227\266", 0, QApplication::UnicodeUTF8));
        label_second->setText(QApplication::translate("TimeSetPage", "\347\247\222", 0, QApplication::UnicodeUTF8));
        btn_year->setText(QString());
        btn_month->setText(QString());
        btn_day->setText(QString());
        btn_second->setText(QString());
        btn_minute->setText(QString());
        btn_hour->setText(QString());
        label_errorInfo->setText(QApplication::translate("TimeSetPage", "\346\227\240\346\225\210\347\232\204\346\227\266\351\227\264\346\240\274\345\274\217\357\274\214\350\257\267\351\207\215\346\226\260\350\276\223\345\205\245\357\274\201", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TimeSetPage: public Ui_TimeSetPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIMESETPAGE_H
