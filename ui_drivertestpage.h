/********************************************************************************
** Form generated from reading UI file 'drivertestpage.ui'
**
** Created: Thu Jan 11 11:16:18 2018
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DRIVERTESTPAGE_H
#define UI_DRIVERTESTPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DriverTestPage
{
public:
    QLabel *label2;
    QLabel *label_Level1;
    QLabel *label1;
    QLabel *label4;
    QLabel *label_Level;
    QLabel *label_traction1;
    QLabel *label3;
    QLabel *label_traction;
    QLabel *label;
    QLabel *label_Level2;
    QLabel *label_brake;
    QLabel *label_brake1;
    QLabel *label_brakePercent1;
    QLabel *label_brakePercent;
    QPushButton *btn_back;

    void setupUi(QWidget *DriverTestPage)
    {
        if (DriverTestPage->objectName().isEmpty())
            DriverTestPage->setObjectName(QString::fromUtf8("DriverTestPage"));
        DriverTestPage->resize(1024, 618);
        DriverTestPage->setStyleSheet(QString::fromUtf8("QLabel\n"
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
"}\n"
""));
        label2 = new QLabel(DriverTestPage);
        label2->setObjectName(QString::fromUtf8("label2"));
        label2->setGeometry(QRect(350, 105, 210, 30));
        label_Level1 = new QLabel(DriverTestPage);
        label_Level1->setObjectName(QString::fromUtf8("label_Level1"));
        label_Level1->setGeometry(QRect(161, 134, 399, 60));
        label_Level1->setLayoutDirection(Qt::LeftToRight);
        label_Level1->setAlignment(Qt::AlignCenter);
        label1 = new QLabel(DriverTestPage);
        label1->setObjectName(QString::fromUtf8("label1"));
        label1->setGeometry(QRect(161, 105, 190, 30));
        label4 = new QLabel(DriverTestPage);
        label4->setObjectName(QString::fromUtf8("label4"));
        label4->setGeometry(QRect(768, 105, 180, 30));
        label_Level = new QLabel(DriverTestPage);
        label_Level->setObjectName(QString::fromUtf8("label_Level"));
        label_Level->setGeometry(QRect(32, 134, 130, 60));
        label_Level->setStyleSheet(QString::fromUtf8(""));
        label_traction1 = new QLabel(DriverTestPage);
        label_traction1->setObjectName(QString::fromUtf8("label_traction1"));
        label_traction1->setGeometry(QRect(161, 221, 787, 60));
        label_traction1->setLayoutDirection(Qt::LeftToRight);
        label_traction1->setAlignment(Qt::AlignCenter);
        label3 = new QLabel(DriverTestPage);
        label3->setObjectName(QString::fromUtf8("label3"));
        label3->setGeometry(QRect(559, 105, 210, 30));
        label_traction = new QLabel(DriverTestPage);
        label_traction->setObjectName(QString::fromUtf8("label_traction"));
        label_traction->setGeometry(QRect(32, 221, 130, 60));
        label_traction->setStyleSheet(QString::fromUtf8(""));
        label = new QLabel(DriverTestPage);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(32, 105, 130, 30));
        label_Level2 = new QLabel(DriverTestPage);
        label_Level2->setObjectName(QString::fromUtf8("label_Level2"));
        label_Level2->setGeometry(QRect(559, 134, 389, 60));
        label_Level2->setStyleSheet(QString::fromUtf8(""));
        label_brake = new QLabel(DriverTestPage);
        label_brake->setObjectName(QString::fromUtf8("label_brake"));
        label_brake->setGeometry(QRect(32, 280, 130, 60));
        label_brake->setStyleSheet(QString::fromUtf8(""));
        label_brake1 = new QLabel(DriverTestPage);
        label_brake1->setObjectName(QString::fromUtf8("label_brake1"));
        label_brake1->setGeometry(QRect(161, 280, 787, 60));
        label_brake1->setLayoutDirection(Qt::LeftToRight);
        label_brake1->setAlignment(Qt::AlignCenter);
        label_brakePercent1 = new QLabel(DriverTestPage);
        label_brakePercent1->setObjectName(QString::fromUtf8("label_brakePercent1"));
        label_brakePercent1->setGeometry(QRect(161, 193, 787, 30));
        label_brakePercent1->setLayoutDirection(Qt::LeftToRight);
        label_brakePercent1->setAlignment(Qt::AlignCenter);
        label_brakePercent = new QLabel(DriverTestPage);
        label_brakePercent->setObjectName(QString::fromUtf8("label_brakePercent"));
        label_brakePercent->setGeometry(QRect(32, 193, 130, 30));
        label_brakePercent->setStyleSheet(QString::fromUtf8(""));
        btn_back = new QPushButton(DriverTestPage);
        btn_back->setObjectName(QString::fromUtf8("btn_back"));
        btn_back->setGeometry(QRect(820, 490, 98, 40));

        retranslateUi(DriverTestPage);

        QMetaObject::connectSlotsByName(DriverTestPage);
    } // setupUi

    void retranslateUi(QWidget *DriverTestPage)
    {
        DriverTestPage->setWindowTitle(QApplication::translate("DriverTestPage", "Form", 0, QApplication::UnicodeUTF8));
        label2->setText(QApplication::translate("DriverTestPage", "2", 0, QApplication::UnicodeUTF8));
        label_Level1->setText(QString());
        label1->setText(QApplication::translate("DriverTestPage", "1", 0, QApplication::UnicodeUTF8));
        label4->setText(QApplication::translate("DriverTestPage", "4", 0, QApplication::UnicodeUTF8));
        label_Level->setText(QApplication::translate("DriverTestPage", "\345\217\270\346\216\247\345\231\250\347\272\247\344\275\215", 0, QApplication::UnicodeUTF8));
        label_traction1->setText(QString());
        label3->setText(QApplication::translate("DriverTestPage", "3", 0, QApplication::UnicodeUTF8));
        label_traction->setText(QApplication::translate("DriverTestPage", "    \347\211\265\345\274\225\n"
"\357\274\210CCU->BCU\357\274\211", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("DriverTestPage", "\350\275\246\345\217\267", 0, QApplication::UnicodeUTF8));
        label_Level2->setText(QString());
        label_brake->setText(QApplication::translate("DriverTestPage", "    \345\210\266\345\212\250\n"
"\357\274\210CCU->BCU\357\274\211", 0, QApplication::UnicodeUTF8));
        label_brake1->setText(QString());
        label_brakePercent1->setText(QString());
        label_brakePercent->setText(QApplication::translate("DriverTestPage", "\345\210\266\345\212\250\345\212\233\347\231\276\345\210\206\346\257\224", 0, QApplication::UnicodeUTF8));
        btn_back->setText(QApplication::translate("DriverTestPage", "\350\277\224\345\233\236", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DriverTestPage: public Ui_DriverTestPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DRIVERTESTPAGE_H
