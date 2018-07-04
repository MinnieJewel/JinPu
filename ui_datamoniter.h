/********************************************************************************
** Form generated from reading UI file 'datamoniter.ui'
**
** Created: Thu Jan 11 11:16:18 2018
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATAMONITER_H
#define UI_DATAMONITER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DataMoniter
{
public:
    QPushButton *btn_hmi;
    QPushButton *btn_ccu1;
    QPushButton *btn_riom;
    QPushButton *btn_erm;
    QPushButton *btn_fau;
    QPushButton *btn_bcu;
    QPushButton *btn_dcu;
    QPushButton *btn_siv;
    QPushButton *btn_edcu1;
    QPushButton *btn_pis;
    QPushButton *btn_hvac;
    QPushButton *btn_atc;
    QPushButton *btn_pds;
    QPushButton *btn_bcg;
    QPushButton *btn_bms;
    QPushButton *btn_back;
    QPushButton *btn_ccu2;
    QPushButton *btn_edcu2;

    void setupUi(QWidget *DataMoniter)
    {
        if (DataMoniter->objectName().isEmpty())
            DataMoniter->setObjectName(QString::fromUtf8("DataMoniter"));
        DataMoniter->resize(1024, 768);
        DataMoniter->setStyleSheet(QString::fromUtf8("QLabel\n"
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
"QPushButton:pressed\n"
"{\n"
"	font: 20px, \"SimHei\";\n"
"    color: white;\n"
"	background-color: rgb(189, 214, 238);\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
""));
        btn_hmi = new QPushButton(DataMoniter);
        btn_hmi->setObjectName(QString::fromUtf8("btn_hmi"));
        btn_hmi->setGeometry(QRect(920, 10, 80, 30));
        btn_ccu1 = new QPushButton(DataMoniter);
        btn_ccu1->setObjectName(QString::fromUtf8("btn_ccu1"));
        btn_ccu1->setGeometry(QRect(920, 52, 80, 30));
        btn_riom = new QPushButton(DataMoniter);
        btn_riom->setObjectName(QString::fromUtf8("btn_riom"));
        btn_riom->setGeometry(QRect(920, 136, 80, 30));
        btn_erm = new QPushButton(DataMoniter);
        btn_erm->setObjectName(QString::fromUtf8("btn_erm"));
        btn_erm->setGeometry(QRect(920, 178, 80, 30));
        btn_fau = new QPushButton(DataMoniter);
        btn_fau->setObjectName(QString::fromUtf8("btn_fau"));
        btn_fau->setGeometry(QRect(920, 682, 80, 30));
        btn_bcu = new QPushButton(DataMoniter);
        btn_bcu->setObjectName(QString::fromUtf8("btn_bcu"));
        btn_bcu->setGeometry(QRect(920, 220, 80, 30));
        btn_dcu = new QPushButton(DataMoniter);
        btn_dcu->setObjectName(QString::fromUtf8("btn_dcu"));
        btn_dcu->setGeometry(QRect(920, 262, 80, 30));
        btn_siv = new QPushButton(DataMoniter);
        btn_siv->setObjectName(QString::fromUtf8("btn_siv"));
        btn_siv->setGeometry(QRect(920, 304, 80, 30));
        btn_edcu1 = new QPushButton(DataMoniter);
        btn_edcu1->setObjectName(QString::fromUtf8("btn_edcu1"));
        btn_edcu1->setGeometry(QRect(920, 346, 80, 30));
        btn_pis = new QPushButton(DataMoniter);
        btn_pis->setObjectName(QString::fromUtf8("btn_pis"));
        btn_pis->setGeometry(QRect(920, 430, 80, 30));
        btn_hvac = new QPushButton(DataMoniter);
        btn_hvac->setObjectName(QString::fromUtf8("btn_hvac"));
        btn_hvac->setGeometry(QRect(920, 472, 80, 30));
        btn_atc = new QPushButton(DataMoniter);
        btn_atc->setObjectName(QString::fromUtf8("btn_atc"));
        btn_atc->setGeometry(QRect(920, 514, 80, 30));
        btn_pds = new QPushButton(DataMoniter);
        btn_pds->setObjectName(QString::fromUtf8("btn_pds"));
        btn_pds->setGeometry(QRect(920, 556, 80, 30));
        btn_bcg = new QPushButton(DataMoniter);
        btn_bcg->setObjectName(QString::fromUtf8("btn_bcg"));
        btn_bcg->setGeometry(QRect(920, 598, 80, 30));
        btn_bms = new QPushButton(DataMoniter);
        btn_bms->setObjectName(QString::fromUtf8("btn_bms"));
        btn_bms->setGeometry(QRect(920, 640, 80, 30));
        btn_back = new QPushButton(DataMoniter);
        btn_back->setObjectName(QString::fromUtf8("btn_back"));
        btn_back->setGeometry(QRect(920, 730, 80, 30));
        btn_ccu2 = new QPushButton(DataMoniter);
        btn_ccu2->setObjectName(QString::fromUtf8("btn_ccu2"));
        btn_ccu2->setGeometry(QRect(920, 94, 80, 30));
        btn_edcu2 = new QPushButton(DataMoniter);
        btn_edcu2->setObjectName(QString::fromUtf8("btn_edcu2"));
        btn_edcu2->setGeometry(QRect(920, 388, 80, 30));

        retranslateUi(DataMoniter);

        QMetaObject::connectSlotsByName(DataMoniter);
    } // setupUi

    void retranslateUi(QWidget *DataMoniter)
    {
        DataMoniter->setWindowTitle(QApplication::translate("DataMoniter", "Form", 0, QApplication::UnicodeUTF8));
        btn_hmi->setText(QApplication::translate("DataMoniter", "HMI", 0, QApplication::UnicodeUTF8));
        btn_ccu1->setText(QApplication::translate("DataMoniter", "CCU1", 0, QApplication::UnicodeUTF8));
        btn_riom->setText(QApplication::translate("DataMoniter", "RIOM", 0, QApplication::UnicodeUTF8));
        btn_erm->setText(QApplication::translate("DataMoniter", "ERM", 0, QApplication::UnicodeUTF8));
        btn_fau->setText(QApplication::translate("DataMoniter", "FAU", 0, QApplication::UnicodeUTF8));
        btn_bcu->setText(QApplication::translate("DataMoniter", "BCU", 0, QApplication::UnicodeUTF8));
        btn_dcu->setText(QApplication::translate("DataMoniter", "DCU", 0, QApplication::UnicodeUTF8));
        btn_siv->setText(QApplication::translate("DataMoniter", "SIV", 0, QApplication::UnicodeUTF8));
        btn_edcu1->setText(QApplication::translate("DataMoniter", "EDCU1", 0, QApplication::UnicodeUTF8));
        btn_pis->setText(QApplication::translate("DataMoniter", "PIS", 0, QApplication::UnicodeUTF8));
        btn_hvac->setText(QApplication::translate("DataMoniter", "HVAC", 0, QApplication::UnicodeUTF8));
        btn_atc->setText(QApplication::translate("DataMoniter", "ATC", 0, QApplication::UnicodeUTF8));
        btn_pds->setText(QApplication::translate("DataMoniter", "PDS", 0, QApplication::UnicodeUTF8));
        btn_bcg->setText(QApplication::translate("DataMoniter", "BCG", 0, QApplication::UnicodeUTF8));
        btn_bms->setText(QApplication::translate("DataMoniter", "BMS", 0, QApplication::UnicodeUTF8));
        btn_back->setText(QApplication::translate("DataMoniter", "\350\277\224\345\233\236", 0, QApplication::UnicodeUTF8));
        btn_ccu2->setText(QApplication::translate("DataMoniter", "CCU2", 0, QApplication::UnicodeUTF8));
        btn_edcu2->setText(QApplication::translate("DataMoniter", "EDCU2", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DataMoniter: public Ui_DataMoniter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATAMONITER_H
