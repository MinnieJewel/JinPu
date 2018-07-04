/********************************************************************************
** Form generated from reading UI file 'testpage.ui'
**
** Created: Thu Jan 11 11:16:18 2018
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTPAGE_H
#define UI_TESTPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestPage
{
public:
    QPushButton *btn_back;
    QPushButton *btn_breakTest;
    QPushButton *btn_tractionTest;
    QPushButton *btn_speedTest;
    QPushButton *btn_driverTest;

    void setupUi(QWidget *TestPage)
    {
        if (TestPage->objectName().isEmpty())
            TestPage->setObjectName(QString::fromUtf8("TestPage"));
        TestPage->resize(1024, 688);
        TestPage->setStyleSheet(QString::fromUtf8("QLabel\n"
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
        btn_back = new QPushButton(TestPage);
        btn_back->setObjectName(QString::fromUtf8("btn_back"));
        btn_back->setGeometry(QRect(740, 580, 98, 40));
        btn_breakTest = new QPushButton(TestPage);
        btn_breakTest->setObjectName(QString::fromUtf8("btn_breakTest"));
        btn_breakTest->setGeometry(QRect(110, 140, 220, 60));
        btn_tractionTest = new QPushButton(TestPage);
        btn_tractionTest->setObjectName(QString::fromUtf8("btn_tractionTest"));
        btn_tractionTest->setGeometry(QRect(620, 140, 220, 60));
        btn_speedTest = new QPushButton(TestPage);
        btn_speedTest->setObjectName(QString::fromUtf8("btn_speedTest"));
        btn_speedTest->setGeometry(QRect(620, 300, 220, 60));
        btn_driverTest = new QPushButton(TestPage);
        btn_driverTest->setObjectName(QString::fromUtf8("btn_driverTest"));
        btn_driverTest->setGeometry(QRect(110, 300, 220, 60));

        retranslateUi(TestPage);

        QMetaObject::connectSlotsByName(TestPage);
    } // setupUi

    void retranslateUi(QWidget *TestPage)
    {
        TestPage->setWindowTitle(QApplication::translate("TestPage", "Form", 0, QApplication::UnicodeUTF8));
        btn_back->setText(QApplication::translate("TestPage", "\350\277\224\345\233\236", 0, QApplication::UnicodeUTF8));
        btn_breakTest->setText(QApplication::translate("TestPage", "\345\210\266\345\212\250\347\263\273\347\273\237\350\207\252\346\243\200", 0, QApplication::UnicodeUTF8));
        btn_tractionTest->setText(QApplication::translate("TestPage", "\347\211\265\345\274\225\347\263\273\347\273\237\346\265\213\350\257\225", 0, QApplication::UnicodeUTF8));
        btn_speedTest->setText(QApplication::translate("TestPage", "\345\212\240\345\207\217\351\200\237\345\272\246\346\265\213\350\257\225", 0, QApplication::UnicodeUTF8));
        btn_driverTest->setText(QApplication::translate("TestPage", "\345\217\270\346\216\247\345\231\250\346\265\213\350\257\225", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TestPage: public Ui_TestPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTPAGE_H
