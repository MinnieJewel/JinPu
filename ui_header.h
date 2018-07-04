/********************************************************************************
** Form generated from reading UI file 'header.ui'
**
** Created: Thu Jan 11 11:16:18 2018
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HEADER_H
#define UI_HEADER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Header
{
public:
    QLabel *pageName;
    QLabel *netVoltage;
    QLabel *netVoltageValue;
    QLabel *netCurrent;
    QLabel *netCurrentValue;
    QLabel *speed;
    QLabel *speedValue;
    QLabel *level;
    QLabel *levelValue;
    QLabel *currentStation;
    QLabel *currentStationValue;
    QLabel *dataTime;
    QPushButton *faultButton;

    void setupUi(QWidget *Header)
    {
        if (Header->objectName().isEmpty())
            Header->setObjectName(QString::fromUtf8("Header"));
        Header->resize(1024, 80);
        Header->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"	background-color: black;\n"
"}\n"
"\n"
"QLabel\n"
"{\n"
"	color: white;\n"
"	font: 20px, \"SimHei\";\n"
"	border:1px solid white;\n"
"}\n"
"	\n"
"QPushButton\n"
"{\n"
"	background-color: black;\n"
"}"));
        pageName = new QLabel(Header);
        pageName->setObjectName(QString::fromUtf8("pageName"));
        pageName->setGeometry(QRect(0, 0, 108, 80));
        pageName->setAlignment(Qt::AlignCenter);
        netVoltage = new QLabel(Header);
        netVoltage->setObjectName(QString::fromUtf8("netVoltage"));
        netVoltage->setGeometry(QRect(108, 0, 110, 40));
        netVoltage->setAlignment(Qt::AlignCenter);
        netVoltageValue = new QLabel(Header);
        netVoltageValue->setObjectName(QString::fromUtf8("netVoltageValue"));
        netVoltageValue->setGeometry(QRect(108, 40, 110, 40));
        netVoltageValue->setAlignment(Qt::AlignCenter);
        netCurrent = new QLabel(Header);
        netCurrent->setObjectName(QString::fromUtf8("netCurrent"));
        netCurrent->setGeometry(QRect(218, 0, 110, 40));
        netCurrent->setAlignment(Qt::AlignCenter);
        netCurrentValue = new QLabel(Header);
        netCurrentValue->setObjectName(QString::fromUtf8("netCurrentValue"));
        netCurrentValue->setGeometry(QRect(218, 40, 110, 40));
        netCurrentValue->setAlignment(Qt::AlignCenter);
        speed = new QLabel(Header);
        speed->setObjectName(QString::fromUtf8("speed"));
        speed->setGeometry(QRect(328, 0, 120, 40));
        speed->setAlignment(Qt::AlignCenter);
        speedValue = new QLabel(Header);
        speedValue->setObjectName(QString::fromUtf8("speedValue"));
        speedValue->setGeometry(QRect(328, 40, 120, 40));
        speedValue->setAlignment(Qt::AlignCenter);
        level = new QLabel(Header);
        level->setObjectName(QString::fromUtf8("level"));
        level->setGeometry(QRect(448, 0, 180, 40));
        level->setAlignment(Qt::AlignCenter);
        levelValue = new QLabel(Header);
        levelValue->setObjectName(QString::fromUtf8("levelValue"));
        levelValue->setGeometry(QRect(448, 40, 180, 40));
        levelValue->setAlignment(Qt::AlignCenter);
        currentStation = new QLabel(Header);
        currentStation->setObjectName(QString::fromUtf8("currentStation"));
        currentStation->setGeometry(QRect(628, 0, 200, 40));
        currentStation->setAlignment(Qt::AlignCenter);
        currentStationValue = new QLabel(Header);
        currentStationValue->setObjectName(QString::fromUtf8("currentStationValue"));
        currentStationValue->setGeometry(QRect(628, 40, 200, 40));
        currentStationValue->setAlignment(Qt::AlignCenter);
        dataTime = new QLabel(Header);
        dataTime->setObjectName(QString::fromUtf8("dataTime"));
        dataTime->setGeometry(QRect(828, 0, 116, 80));
        dataTime->setAlignment(Qt::AlignCenter);
        faultButton = new QPushButton(Header);
        faultButton->setObjectName(QString::fromUtf8("faultButton"));
        faultButton->setGeometry(QRect(947, 2, 75, 78));
        faultButton->setCursor(QCursor(Qt::WhatsThisCursor));
        faultButton->setFocusPolicy(Qt::NoFocus);
        faultButton->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
""));

        retranslateUi(Header);

        QMetaObject::connectSlotsByName(Header);
    } // setupUi

    void retranslateUi(QWidget *Header)
    {
        Header->setWindowTitle(QApplication::translate("Header", "Form", 0, QApplication::UnicodeUTF8));
        pageName->setText(QApplication::translate("Header", "\347\275\221\347\273\234", 0, QApplication::UnicodeUTF8));
        netVoltage->setText(QApplication::translate("Header", "\347\275\221\345\216\213", 0, QApplication::UnicodeUTF8));
        netVoltageValue->setText(QString());
        netCurrent->setText(QApplication::translate("Header", "\347\275\221\346\265\201", 0, QApplication::UnicodeUTF8));
        netCurrentValue->setText(QString());
        speed->setText(QApplication::translate("Header", "\351\200\237\345\272\246", 0, QApplication::UnicodeUTF8));
        speedValue->setText(QString());
        level->setText(QApplication::translate("Header", "\347\211\265\345\274\225/\345\210\266\345\212\250\347\272\247\344\275\215", 0, QApplication::UnicodeUTF8));
        levelValue->setText(QString());
        currentStation->setText(QApplication::translate("Header", "\345\275\223\345\211\215\347\253\231", 0, QApplication::UnicodeUTF8));
        currentStationValue->setText(QString());
        dataTime->setText(QString());
        faultButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Header: public Ui_Header {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HEADER_H
