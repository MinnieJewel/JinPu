/********************************************************************************
** Form generated from reading UI file 'runningrecordpage.ui'
**
** Created: Thu Jan 11 11:16:18 2018
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RUNNINGRECORDPAGE_H
#define UI_RUNNINGRECORDPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RunningRecordPage
{
public:
    QPushButton *btn_back;

    void setupUi(QWidget *RunningRecordPage)
    {
        if (RunningRecordPage->objectName().isEmpty())
            RunningRecordPage->setObjectName(QString::fromUtf8("RunningRecordPage"));
        RunningRecordPage->resize(1024, 688);
        RunningRecordPage->setStyleSheet(QString::fromUtf8("QLabel\n"
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
        btn_back = new QPushButton(RunningRecordPage);
        btn_back->setObjectName(QString::fromUtf8("btn_back"));
        btn_back->setGeometry(QRect(880, 610, 98, 40));

        retranslateUi(RunningRecordPage);

        QMetaObject::connectSlotsByName(RunningRecordPage);
    } // setupUi

    void retranslateUi(QWidget *RunningRecordPage)
    {
        RunningRecordPage->setWindowTitle(QApplication::translate("RunningRecordPage", "Form", 0, QApplication::UnicodeUTF8));
        btn_back->setText(QApplication::translate("RunningRecordPage", "\351\200\200\345\207\272", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class RunningRecordPage: public Ui_RunningRecordPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RUNNINGRECORDPAGE_H
