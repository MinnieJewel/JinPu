/********************************************************************************
** Form generated from reading UI file 'speedtestpage.ui'
**
** Created: Thu Jan 11 11:16:18 2018
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPEEDTESTPAGE_H
#define UI_SPEEDTESTPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SpeedTestPage
{
public:
    QPushButton *btn_start;
    QPushButton *btn_cease;
    QPushButton *btn_back;

    void setupUi(QWidget *SpeedTestPage)
    {
        if (SpeedTestPage->objectName().isEmpty())
            SpeedTestPage->setObjectName(QString::fromUtf8("SpeedTestPage"));
        SpeedTestPage->resize(1024, 688);
        SpeedTestPage->setStyleSheet(QString::fromUtf8("QLabel\n"
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
        btn_start = new QPushButton(SpeedTestPage);
        btn_start->setObjectName(QString::fromUtf8("btn_start"));
        btn_start->setGeometry(QRect(330, 620, 98, 40));
        btn_cease = new QPushButton(SpeedTestPage);
        btn_cease->setObjectName(QString::fromUtf8("btn_cease"));
        btn_cease->setGeometry(QRect(460, 620, 98, 40));
        btn_back = new QPushButton(SpeedTestPage);
        btn_back->setObjectName(QString::fromUtf8("btn_back"));
        btn_back->setGeometry(QRect(830, 620, 98, 40));

        retranslateUi(SpeedTestPage);

        QMetaObject::connectSlotsByName(SpeedTestPage);
    } // setupUi

    void retranslateUi(QWidget *SpeedTestPage)
    {
        SpeedTestPage->setWindowTitle(QApplication::translate("SpeedTestPage", "Form", 0, QApplication::UnicodeUTF8));
        btn_start->setText(QApplication::translate("SpeedTestPage", "\345\274\200\345\247\213\346\265\213\350\257\225", 0, QApplication::UnicodeUTF8));
        btn_cease->setText(QApplication::translate("SpeedTestPage", "\347\273\223\346\235\237\346\265\213\350\257\225", 0, QApplication::UnicodeUTF8));
        btn_back->setText(QApplication::translate("SpeedTestPage", "\350\277\224\345\233\236", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SpeedTestPage: public Ui_SpeedTestPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPEEDTESTPAGE_H
