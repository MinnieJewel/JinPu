/********************************************************************************
** Form generated from reading UI file 'tractionisolate.ui'
**
** Created: Thu Jan 11 11:16:18 2018
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRACTIONISOLATE_H
#define UI_TRACTIONISOLATE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TractionIsolate
{
public:
    QPushButton *btn_mp1tcu1;
    QPushButton *btn_mp1tcu2;
    QPushButton *btn_mp1tcu3;
    QPushButton *btn_mp1tcu4;
    QPushButton *btn_mp2tcu1;
    QPushButton *btn_mp2tcu3;
    QPushButton *btn_mp2tcu4;
    QPushButton *btn_mp2tcu2;
    QPushButton *btn_back;

    void setupUi(QWidget *TractionIsolate)
    {
        if (TractionIsolate->objectName().isEmpty())
            TractionIsolate->setObjectName(QString::fromUtf8("TractionIsolate"));
        TractionIsolate->resize(1024, 618);
        TractionIsolate->setStyleSheet(QString::fromUtf8("QLabel\n"
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
"	border-radius: 5px;\n"
"	font: 20px, \"SimHei\";\n"
"    color: black;\n"
"	background-color: rgb(250, 250, 250);\n"
"}"));
        btn_mp1tcu1 = new QPushButton(TractionIsolate);
        btn_mp1tcu1->setObjectName(QString::fromUtf8("btn_mp1tcu1"));
        btn_mp1tcu1->setGeometry(QRect(220, 90, 200, 50));
        btn_mp1tcu2 = new QPushButton(TractionIsolate);
        btn_mp1tcu2->setObjectName(QString::fromUtf8("btn_mp1tcu2"));
        btn_mp1tcu2->setGeometry(QRect(220, 170, 200, 50));
        btn_mp1tcu3 = new QPushButton(TractionIsolate);
        btn_mp1tcu3->setObjectName(QString::fromUtf8("btn_mp1tcu3"));
        btn_mp1tcu3->setGeometry(QRect(220, 250, 200, 50));
        btn_mp1tcu4 = new QPushButton(TractionIsolate);
        btn_mp1tcu4->setObjectName(QString::fromUtf8("btn_mp1tcu4"));
        btn_mp1tcu4->setGeometry(QRect(220, 330, 200, 50));
        btn_mp2tcu1 = new QPushButton(TractionIsolate);
        btn_mp2tcu1->setObjectName(QString::fromUtf8("btn_mp2tcu1"));
        btn_mp2tcu1->setGeometry(QRect(520, 90, 200, 50));
        btn_mp2tcu3 = new QPushButton(TractionIsolate);
        btn_mp2tcu3->setObjectName(QString::fromUtf8("btn_mp2tcu3"));
        btn_mp2tcu3->setGeometry(QRect(520, 250, 200, 50));
        btn_mp2tcu4 = new QPushButton(TractionIsolate);
        btn_mp2tcu4->setObjectName(QString::fromUtf8("btn_mp2tcu4"));
        btn_mp2tcu4->setGeometry(QRect(520, 330, 200, 50));
        btn_mp2tcu2 = new QPushButton(TractionIsolate);
        btn_mp2tcu2->setObjectName(QString::fromUtf8("btn_mp2tcu2"));
        btn_mp2tcu2->setGeometry(QRect(520, 170, 200, 50));
        btn_back = new QPushButton(TractionIsolate);
        btn_back->setObjectName(QString::fromUtf8("btn_back"));
        btn_back->setGeometry(QRect(790, 520, 98, 40));

        retranslateUi(TractionIsolate);

        QMetaObject::connectSlotsByName(TractionIsolate);
    } // setupUi

    void retranslateUi(QWidget *TractionIsolate)
    {
        TractionIsolate->setWindowTitle(QApplication::translate("TractionIsolate", "Form", 0, QApplication::UnicodeUTF8));
        btn_mp1tcu1->setText(QApplication::translate("TractionIsolate", "Mp1 \347\211\265\345\274\225TCU1\351\232\224\347\246\273", 0, QApplication::UnicodeUTF8));
        btn_mp1tcu2->setText(QApplication::translate("TractionIsolate", "Mp1 \347\211\265\345\274\225TCU2\351\232\224\347\246\273", 0, QApplication::UnicodeUTF8));
        btn_mp1tcu3->setText(QApplication::translate("TractionIsolate", "Mp1 \347\211\265\345\274\225TCU3\351\232\224\347\246\273", 0, QApplication::UnicodeUTF8));
        btn_mp1tcu4->setText(QApplication::translate("TractionIsolate", "Mp1 \347\211\265\345\274\225TCU4\351\232\224\347\246\273", 0, QApplication::UnicodeUTF8));
        btn_mp2tcu1->setText(QApplication::translate("TractionIsolate", "Mp2 \347\211\265\345\274\225TCU1\351\232\224\347\246\273", 0, QApplication::UnicodeUTF8));
        btn_mp2tcu3->setText(QApplication::translate("TractionIsolate", "Mp2 \347\211\265\345\274\225TCU3\351\232\224\347\246\273", 0, QApplication::UnicodeUTF8));
        btn_mp2tcu4->setText(QApplication::translate("TractionIsolate", "Mp2 \347\211\265\345\274\225TCU4\351\232\224\347\246\273", 0, QApplication::UnicodeUTF8));
        btn_mp2tcu2->setText(QApplication::translate("TractionIsolate", "Mp2 \347\211\265\345\274\225TCU2\351\232\224\347\246\273", 0, QApplication::UnicodeUTF8));
        btn_back->setText(QApplication::translate("TractionIsolate", "\350\277\224\345\233\236", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TractionIsolate: public Ui_TractionIsolate {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRACTIONISOLATE_H
