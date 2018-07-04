/********************************************************************************
** Form generated from reading UI file 'allports.ui'
**
** Created: Thu Jan 11 11:16:18 2018
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALLPORTS_H
#define UI_ALLPORTS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AllPorts
{
public:
    QLabel *label_DI1;
    QLabel *label_DI2;
    QLabel *label_DI3;
    QLabel *label_DI4;
    QLabel *label_DO;
    QLabel *label_AX;
    QLabel *label;
    QPushButton *btn_back;
    QPushButton *btn_tc1;
    QPushButton *btn_mp1;
    QPushButton *btn_mp2;
    QPushButton *btn_tc2;
    QPushButton *btn_prev;
    QPushButton *btn_next;
    QLabel *label_pageIndex;

    void setupUi(QWidget *AllPorts)
    {
        if (AllPorts->objectName().isEmpty())
            AllPorts->setObjectName(QString::fromUtf8("AllPorts"));
        AllPorts->resize(1024, 768);
        AllPorts->setMaximumSize(QSize(1024, 768));
        AllPorts->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	color: white;\n"
"	border: 2px groove, gray;\n"
"    border-color: gray;\n"
"	font: 12px, \"SimHei\";\n"
"	\n"
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
        label_DI1 = new QLabel(AllPorts);
        label_DI1->setObjectName(QString::fromUtf8("label_DI1"));
        label_DI1->setGeometry(QRect(40, 40, 66, 17));
        label_DI2 = new QLabel(AllPorts);
        label_DI2->setObjectName(QString::fromUtf8("label_DI2"));
        label_DI2->setGeometry(QRect(130, 40, 66, 17));
        label_DI3 = new QLabel(AllPorts);
        label_DI3->setObjectName(QString::fromUtf8("label_DI3"));
        label_DI3->setGeometry(QRect(220, 40, 66, 17));
        label_DI4 = new QLabel(AllPorts);
        label_DI4->setObjectName(QString::fromUtf8("label_DI4"));
        label_DI4->setGeometry(QRect(310, 40, 66, 17));
        label_DO = new QLabel(AllPorts);
        label_DO->setObjectName(QString::fromUtf8("label_DO"));
        label_DO->setGeometry(QRect(400, 40, 66, 17));
        label_AX = new QLabel(AllPorts);
        label_AX->setObjectName(QString::fromUtf8("label_AX"));
        label_AX->setGeometry(QRect(490, 40, 66, 17));
        label = new QLabel(AllPorts);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 705, 1024, 60));
        btn_back = new QPushButton(AllPorts);
        btn_back->setObjectName(QString::fromUtf8("btn_back"));
        btn_back->setGeometry(QRect(10, 715, 100, 40));
        btn_tc1 = new QPushButton(AllPorts);
        btn_tc1->setObjectName(QString::fromUtf8("btn_tc1"));
        btn_tc1->setGeometry(QRect(120, 715, 100, 40));
        btn_mp1 = new QPushButton(AllPorts);
        btn_mp1->setObjectName(QString::fromUtf8("btn_mp1"));
        btn_mp1->setGeometry(QRect(230, 715, 100, 40));
        btn_mp2 = new QPushButton(AllPorts);
        btn_mp2->setObjectName(QString::fromUtf8("btn_mp2"));
        btn_mp2->setGeometry(QRect(340, 715, 100, 40));
        btn_tc2 = new QPushButton(AllPorts);
        btn_tc2->setObjectName(QString::fromUtf8("btn_tc2"));
        btn_tc2->setGeometry(QRect(450, 715, 100, 40));
        btn_prev = new QPushButton(AllPorts);
        btn_prev->setObjectName(QString::fromUtf8("btn_prev"));
        btn_prev->setGeometry(QRect(700, 715, 100, 40));
        btn_next = new QPushButton(AllPorts);
        btn_next->setObjectName(QString::fromUtf8("btn_next"));
        btn_next->setGeometry(QRect(900, 715, 100, 40));
        label_pageIndex = new QLabel(AllPorts);
        label_pageIndex->setObjectName(QString::fromUtf8("label_pageIndex"));
        label_pageIndex->setGeometry(QRect(822, 710, 55, 45));
        label_pageIndex->setStyleSheet(QString::fromUtf8("	color: white;\n"
"	font: 20px, \"SimHei\";\n"
"	border:0px;"));

        retranslateUi(AllPorts);

        QMetaObject::connectSlotsByName(AllPorts);
    } // setupUi

    void retranslateUi(QWidget *AllPorts)
    {
        AllPorts->setWindowTitle(QApplication::translate("AllPorts", "Form", 0, QApplication::UnicodeUTF8));
        label_DI1->setText(QApplication::translate("AllPorts", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_DI2->setText(QApplication::translate("AllPorts", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_DI3->setText(QApplication::translate("AllPorts", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_DI4->setText(QApplication::translate("AllPorts", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_DO->setText(QApplication::translate("AllPorts", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_AX->setText(QApplication::translate("AllPorts", "TextLabel", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        btn_back->setText(QApplication::translate("AllPorts", "\350\277\224 \345\233\236", 0, QApplication::UnicodeUTF8));
        btn_tc1->setText(QApplication::translate("AllPorts", "TC1", 0, QApplication::UnicodeUTF8));
        btn_mp1->setText(QApplication::translate("AllPorts", "Mp1", 0, QApplication::UnicodeUTF8));
        btn_mp2->setText(QApplication::translate("AllPorts", "Mp2", 0, QApplication::UnicodeUTF8));
        btn_tc2->setText(QApplication::translate("AllPorts", "TC2", 0, QApplication::UnicodeUTF8));
        btn_prev->setText(QApplication::translate("AllPorts", "\344\270\212\344\270\200\351\241\265", 0, QApplication::UnicodeUTF8));
        btn_next->setText(QApplication::translate("AllPorts", "\344\270\213\344\270\200\351\241\265", 0, QApplication::UnicodeUTF8));
        label_pageIndex->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AllPorts: public Ui_AllPorts {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALLPORTS_H
