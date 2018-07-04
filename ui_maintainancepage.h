/********************************************************************************
** Form generated from reading UI file 'maintainancepage.ui'
**
** Created: Thu Jan 11 11:16:18 2018
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINTAINANCEPAGE_H
#define UI_MAINTAINANCEPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MaintainancePage
{
public:
    QPushButton *btn_test;
    QPushButton *btn_paraSet;
    QPushButton *btn_RunningRecord;
    QPushButton *btn_historyRecord;
    QPushButton *btn_RunningRecordClear;
    QPushButton *btn_mainpage;
    QPushButton *btn_setRecord;

    void setupUi(QWidget *MaintainancePage)
    {
        if (MaintainancePage->objectName().isEmpty())
            MaintainancePage->setObjectName(QString::fromUtf8("MaintainancePage"));
        MaintainancePage->resize(1024, 648);
        MaintainancePage->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	color: white;\n"
"	border: 2px groove, gray;\n"
"    border-color: gray;\n"
"	font: 20px, \"SimHei\";\n"
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
        btn_test = new QPushButton(MaintainancePage);
        btn_test->setObjectName(QString::fromUtf8("btn_test"));
        btn_test->setGeometry(QRect(150, 130, 200, 40));
        btn_paraSet = new QPushButton(MaintainancePage);
        btn_paraSet->setObjectName(QString::fromUtf8("btn_paraSet"));
        btn_paraSet->setGeometry(QRect(410, 130, 200, 40));
        btn_RunningRecord = new QPushButton(MaintainancePage);
        btn_RunningRecord->setObjectName(QString::fromUtf8("btn_RunningRecord"));
        btn_RunningRecord->setGeometry(QRect(150, 250, 200, 40));
        btn_historyRecord = new QPushButton(MaintainancePage);
        btn_historyRecord->setObjectName(QString::fromUtf8("btn_historyRecord"));
        btn_historyRecord->setGeometry(QRect(670, 130, 200, 40));
        btn_RunningRecordClear = new QPushButton(MaintainancePage);
        btn_RunningRecordClear->setObjectName(QString::fromUtf8("btn_RunningRecordClear"));
        btn_RunningRecordClear->setGeometry(QRect(410, 250, 200, 40));
        btn_mainpage = new QPushButton(MaintainancePage);
        btn_mainpage->setObjectName(QString::fromUtf8("btn_mainpage"));
        btn_mainpage->setGeometry(QRect(740, 480, 98, 40));
        btn_setRecord = new QPushButton(MaintainancePage);
        btn_setRecord->setObjectName(QString::fromUtf8("btn_setRecord"));
        btn_setRecord->setGeometry(QRect(670, 250, 200, 40));

        retranslateUi(MaintainancePage);

        QMetaObject::connectSlotsByName(MaintainancePage);
    } // setupUi

    void retranslateUi(QWidget *MaintainancePage)
    {
        MaintainancePage->setWindowTitle(QApplication::translate("MaintainancePage", "Form", 0, QApplication::UnicodeUTF8));
        btn_test->setText(QApplication::translate("MaintainancePage", "\346\265\213\350\257\225", 0, QApplication::UnicodeUTF8));
        btn_paraSet->setText(QApplication::translate("MaintainancePage", "\345\217\202\346\225\260\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        btn_RunningRecord->setText(QApplication::translate("MaintainancePage", "\350\277\220\350\241\214\350\256\260\345\275\225", 0, QApplication::UnicodeUTF8));
        btn_historyRecord->setText(QApplication::translate("MaintainancePage", "\346\225\205\351\232\234\350\256\260\345\275\225", 0, QApplication::UnicodeUTF8));
        btn_RunningRecordClear->setText(QApplication::translate("MaintainancePage", "\350\277\220\350\241\214\350\256\260\345\275\225\346\270\205\351\233\266", 0, QApplication::UnicodeUTF8));
        btn_mainpage->setText(QApplication::translate("MaintainancePage", "\344\270\273\350\217\234\345\215\225", 0, QApplication::UnicodeUTF8));
        btn_setRecord->setText(QApplication::translate("MaintainancePage", "\350\277\220\350\241\214\350\256\260\345\275\225\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MaintainancePage: public Ui_MaintainancePage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINTAINANCEPAGE_H
