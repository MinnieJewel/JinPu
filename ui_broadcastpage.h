/********************************************************************************
** Form generated from reading UI file 'broadcastpage.ui'
**
** Created: Wed Jan 11 11:06:07 2017
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BROADCASTPAGE_H
#define UI_BROADCASTPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BroadCastPage
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QWidget *BroadCastPage)
    {
        if (BroadCastPage->objectName().isEmpty())
            BroadCastPage->setObjectName(QString::fromUtf8("BroadCastPage"));
        BroadCastPage->resize(1024, 768);
        BroadCastPage->setStyleSheet(QString::fromUtf8("QLabel\n"
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
        pushButton = new QPushButton(BroadCastPage);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(170, 150, 98, 27));
        pushButton_2 = new QPushButton(BroadCastPage);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(370, 150, 98, 27));
        pushButton_3 = new QPushButton(BroadCastPage);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(570, 150, 98, 27));

        retranslateUi(BroadCastPage);

        QMetaObject::connectSlotsByName(BroadCastPage);
    } // setupUi

    void retranslateUi(QWidget *BroadCastPage)
    {
        BroadCastPage->setWindowTitle(QApplication::translate("BroadCastPage", "Form", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("BroadCastPage", "PushButton", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("BroadCastPage", "PushButton", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("BroadCastPage", "PushButton", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BroadCastPage: public Ui_BroadCastPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BROADCASTPAGE_H
