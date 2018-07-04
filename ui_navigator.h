/********************************************************************************
** Form generated from reading UI file 'navigator.ui'
**
** Created: Thu Jan 11 11:16:18 2018
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NAVIGATOR_H
#define UI_NAVIGATOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Navigator
{
public:
    QLabel *NavigatorBackground;
    QPushButton *nbtn1_1;
    QPushButton *nbtn1_2;
    QPushButton *nbtn1_3;
    QPushButton *nbtn1_4;
    QPushButton *nbtn1_5;
    QPushButton *nbtn1_6;
    QPushButton *nbtn1_7;
    QPushButton *nbtn1_8;
    QPushButton *nbtn1_9;
    QPushButton *nbtn1_10;
    QPushButton *nbtn1_11;

    void setupUi(QWidget *Navigator)
    {
        if (Navigator->objectName().isEmpty())
            Navigator->setObjectName(QString::fromUtf8("Navigator"));
        Navigator->resize(1024, 70);
        Navigator->setStyleSheet(QString::fromUtf8("QWidget\n"
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
"\n"
"\n"
"\n"
"QLabel\n"
"{\n"
"	color: white;\n"
"	font: 20px, \"SimHei\";\n"
"	border:1px solid white;\n"
"}\n"
""));
        NavigatorBackground = new QLabel(Navigator);
        NavigatorBackground->setObjectName(QString::fromUtf8("NavigatorBackground"));
        NavigatorBackground->setGeometry(QRect(0, 0, 1024, 70));
        nbtn1_1 = new QPushButton(Navigator);
        nbtn1_1->setObjectName(QString::fromUtf8("nbtn1_1"));
        nbtn1_1->setGeometry(QRect(10, 15, 80, 40));
        nbtn1_1->setStyleSheet(QString::fromUtf8(""));
        nbtn1_2 = new QPushButton(Navigator);
        nbtn1_2->setObjectName(QString::fromUtf8("nbtn1_2"));
        nbtn1_2->setGeometry(QRect(100, 15, 80, 40));
        nbtn1_3 = new QPushButton(Navigator);
        nbtn1_3->setObjectName(QString::fromUtf8("nbtn1_3"));
        nbtn1_3->setGeometry(QRect(190, 15, 80, 40));
        nbtn1_4 = new QPushButton(Navigator);
        nbtn1_4->setObjectName(QString::fromUtf8("nbtn1_4"));
        nbtn1_4->setGeometry(QRect(280, 15, 80, 40));
        nbtn1_5 = new QPushButton(Navigator);
        nbtn1_5->setObjectName(QString::fromUtf8("nbtn1_5"));
        nbtn1_5->setGeometry(QRect(370, 15, 80, 40));
        nbtn1_6 = new QPushButton(Navigator);
        nbtn1_6->setObjectName(QString::fromUtf8("nbtn1_6"));
        nbtn1_6->setGeometry(QRect(460, 15, 80, 40));
        nbtn1_6->setStyleSheet(QString::fromUtf8(""));
        nbtn1_7 = new QPushButton(Navigator);
        nbtn1_7->setObjectName(QString::fromUtf8("nbtn1_7"));
        nbtn1_7->setGeometry(QRect(550, 15, 80, 40));
        nbtn1_8 = new QPushButton(Navigator);
        nbtn1_8->setObjectName(QString::fromUtf8("nbtn1_8"));
        nbtn1_8->setGeometry(QRect(640, 15, 80, 40));
        nbtn1_9 = new QPushButton(Navigator);
        nbtn1_9->setObjectName(QString::fromUtf8("nbtn1_9"));
        nbtn1_9->setGeometry(QRect(730, 15, 80, 40));
        nbtn1_9->setStyleSheet(QString::fromUtf8(""));
        nbtn1_10 = new QPushButton(Navigator);
        nbtn1_10->setObjectName(QString::fromUtf8("nbtn1_10"));
        nbtn1_10->setGeometry(QRect(820, 15, 80, 40));
        nbtn1_10->setStyleSheet(QString::fromUtf8(""));
        nbtn1_11 = new QPushButton(Navigator);
        nbtn1_11->setObjectName(QString::fromUtf8("nbtn1_11"));
        nbtn1_11->setGeometry(QRect(930, 15, 80, 40));

        retranslateUi(Navigator);

        QMetaObject::connectSlotsByName(Navigator);
    } // setupUi

    void retranslateUi(QWidget *Navigator)
    {
        Navigator->setWindowTitle(QApplication::translate("Navigator", "Form", 0, QApplication::UnicodeUTF8));
        NavigatorBackground->setText(QString());
        nbtn1_1->setText(QString());
        nbtn1_2->setText(QString());
        nbtn1_3->setText(QString());
        nbtn1_4->setText(QString());
        nbtn1_5->setText(QString());
        nbtn1_6->setText(QString());
        nbtn1_7->setText(QString());
        nbtn1_8->setText(QString());
        nbtn1_9->setText(QString());
        nbtn1_10->setText(QString());
        nbtn1_11->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Navigator: public Ui_Navigator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NAVIGATOR_H
