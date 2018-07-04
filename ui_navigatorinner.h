/********************************************************************************
** Form generated from reading UI file 'navigatorinner.ui'
**
** Created: Thu Jan 11 11:16:18 2018
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NAVIGATORINNER_H
#define UI_NAVIGATORINNER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NavigatorInner
{
public:

    void setupUi(QWidget *NavigatorInner)
    {
        if (NavigatorInner->objectName().isEmpty())
            NavigatorInner->setObjectName(QString::fromUtf8("NavigatorInner"));
        NavigatorInner->resize(1024, 60);
        NavigatorInner->setStyleSheet(QString::fromUtf8("QWidget\n"
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
"QLabel\n"
"{\n"
"	color: white;\n"
"	font: 20px, \"SimHei\";\n"
"	border:1px solid white;\n"
"}\n"
"	"));

        retranslateUi(NavigatorInner);

        QMetaObject::connectSlotsByName(NavigatorInner);
    } // setupUi

    void retranslateUi(QWidget *NavigatorInner)
    {
        NavigatorInner->setWindowTitle(QApplication::translate("NavigatorInner", "Form", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class NavigatorInner: public Ui_NavigatorInner {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NAVIGATORINNER_H
