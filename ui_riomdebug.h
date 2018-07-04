/********************************************************************************
** Form generated from reading UI file 'riomdebug.ui'
**
** Created: Thu Jan 11 11:16:18 2018
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RIOMDEBUG_H
#define UI_RIOMDEBUG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RIOMDebug
{
public:
    QLabel *label_CAR4_DI3;
    QLabel *label_CAR3_DI4;
    QLabel *label_CAR2_AX;
    QLabel *label_CAR3_AX;
    QLabel *label_CAR4_DI4;
    QLabel *label_CAR3_GW;
    QLabel *label_CAR2_DI4;
    QLabel *label_CAR4_AX;
    QLabel *label_DI4;
    QLabel *label_CAR1_DI1;
    QLabel *label_GW;
    QLabel *label_CAR3_DI2;
    QLabel *label_DI2;
    QLabel *label_CAR1_DI4;
    QPushButton *btn_back;
    QLabel *label_CAR4_DI2;
    QLabel *label_CAR1_AX;
    QLabel *label_CAR4_DI1;
    QLabel *label_CAR1_GW;
    QLabel *label_CAR2_DO;
    QLabel *label_CAR3_DI1;
    QLabel *label_CAR1_DI3;
    QLabel *label_AX;
    QLabel *label_CAR4_DO;
    QLabel *label_CAR4_GW;
    QLabel *label_DO;
    QLabel *label_DI3;
    QLabel *label_CAR2_DI1;
    QLabel *label_CAR2_DI2;
    QLabel *label_DI1;
    QLabel *label_CAR2_GW;
    QLabel *label_CAR3_DO;
    QLabel *label_CAR3_DI3;
    QLabel *label_CAR1_DI2;
    QLabel *label_CAR1_DO;
    QLabel *label_CAR2_DI3;
    QLabel *label_CAR2_LAT;
    QLabel *label_GW_2;
    QLabel *label_CAR4_RLD;
    QLabel *label_CAR1_LAT;
    QLabel *label_CAR3_RLD;
    QLabel *label_CAR1_RLD;
    QLabel *label_CAR4_LAT;
    QLabel *label_CAR2_RLD;
    QLabel *label_CAR3_LAT;
    QLabel *label_AX_2;

    void setupUi(QWidget *RIOMDebug)
    {
        if (RIOMDebug->objectName().isEmpty())
            RIOMDebug->setObjectName(QString::fromUtf8("RIOMDebug"));
        RIOMDebug->resize(1024, 688);
        RIOMDebug->setStyleSheet(QString::fromUtf8("QLabel\n"
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
        label_CAR4_DI3 = new QLabel(RIOMDebug);
        label_CAR4_DI3->setObjectName(QString::fromUtf8("label_CAR4_DI3"));
        label_CAR4_DI3->setGeometry(QRect(787, 165, 180, 30));
        label_CAR4_DI3->setAlignment(Qt::AlignCenter);
        label_CAR3_DI4 = new QLabel(RIOMDebug);
        label_CAR3_DI4->setObjectName(QString::fromUtf8("label_CAR3_DI4"));
        label_CAR3_DI4->setGeometry(QRect(578, 194, 210, 30));
        label_CAR3_DI4->setAlignment(Qt::AlignCenter);
        label_CAR2_AX = new QLabel(RIOMDebug);
        label_CAR2_AX->setObjectName(QString::fromUtf8("label_CAR2_AX"));
        label_CAR2_AX->setGeometry(QRect(369, 252, 210, 30));
        label_CAR2_AX->setAlignment(Qt::AlignCenter);
        label_CAR3_AX = new QLabel(RIOMDebug);
        label_CAR3_AX->setObjectName(QString::fromUtf8("label_CAR3_AX"));
        label_CAR3_AX->setGeometry(QRect(578, 252, 210, 30));
        label_CAR3_AX->setAlignment(Qt::AlignCenter);
        label_CAR4_DI4 = new QLabel(RIOMDebug);
        label_CAR4_DI4->setObjectName(QString::fromUtf8("label_CAR4_DI4"));
        label_CAR4_DI4->setGeometry(QRect(787, 194, 180, 30));
        label_CAR4_DI4->setAlignment(Qt::AlignCenter);
        label_CAR3_GW = new QLabel(RIOMDebug);
        label_CAR3_GW->setObjectName(QString::fromUtf8("label_CAR3_GW"));
        label_CAR3_GW->setGeometry(QRect(578, 281, 210, 30));
        label_CAR3_GW->setAlignment(Qt::AlignCenter);
        label_CAR2_DI4 = new QLabel(RIOMDebug);
        label_CAR2_DI4->setObjectName(QString::fromUtf8("label_CAR2_DI4"));
        label_CAR2_DI4->setGeometry(QRect(369, 194, 210, 30));
        label_CAR2_DI4->setAlignment(Qt::AlignCenter);
        label_CAR4_AX = new QLabel(RIOMDebug);
        label_CAR4_AX->setObjectName(QString::fromUtf8("label_CAR4_AX"));
        label_CAR4_AX->setGeometry(QRect(787, 252, 180, 30));
        label_CAR4_AX->setAlignment(Qt::AlignCenter);
        label_DI4 = new QLabel(RIOMDebug);
        label_DI4->setObjectName(QString::fromUtf8("label_DI4"));
        label_DI4->setGeometry(QRect(51, 194, 130, 30));
        label_CAR1_DI1 = new QLabel(RIOMDebug);
        label_CAR1_DI1->setObjectName(QString::fromUtf8("label_CAR1_DI1"));
        label_CAR1_DI1->setGeometry(QRect(180, 107, 190, 30));
        label_CAR1_DI1->setAlignment(Qt::AlignCenter);
        label_GW = new QLabel(RIOMDebug);
        label_GW->setObjectName(QString::fromUtf8("label_GW"));
        label_GW->setGeometry(QRect(51, 281, 130, 30));
        label_CAR3_DI2 = new QLabel(RIOMDebug);
        label_CAR3_DI2->setObjectName(QString::fromUtf8("label_CAR3_DI2"));
        label_CAR3_DI2->setGeometry(QRect(578, 136, 210, 30));
        label_CAR3_DI2->setAlignment(Qt::AlignCenter);
        label_DI2 = new QLabel(RIOMDebug);
        label_DI2->setObjectName(QString::fromUtf8("label_DI2"));
        label_DI2->setGeometry(QRect(51, 136, 130, 30));
        label_CAR1_DI4 = new QLabel(RIOMDebug);
        label_CAR1_DI4->setObjectName(QString::fromUtf8("label_CAR1_DI4"));
        label_CAR1_DI4->setGeometry(QRect(180, 194, 190, 30));
        label_CAR1_DI4->setAlignment(Qt::AlignCenter);
        btn_back = new QPushButton(RIOMDebug);
        btn_back->setObjectName(QString::fromUtf8("btn_back"));
        btn_back->setGeometry(QRect(880, 550, 98, 40));
        label_CAR4_DI2 = new QLabel(RIOMDebug);
        label_CAR4_DI2->setObjectName(QString::fromUtf8("label_CAR4_DI2"));
        label_CAR4_DI2->setGeometry(QRect(787, 136, 180, 30));
        label_CAR4_DI2->setAlignment(Qt::AlignCenter);
        label_CAR1_AX = new QLabel(RIOMDebug);
        label_CAR1_AX->setObjectName(QString::fromUtf8("label_CAR1_AX"));
        label_CAR1_AX->setGeometry(QRect(180, 252, 190, 30));
        label_CAR1_AX->setAlignment(Qt::AlignCenter);
        label_CAR4_DI1 = new QLabel(RIOMDebug);
        label_CAR4_DI1->setObjectName(QString::fromUtf8("label_CAR4_DI1"));
        label_CAR4_DI1->setGeometry(QRect(787, 107, 180, 30));
        label_CAR4_DI1->setAlignment(Qt::AlignCenter);
        label_CAR1_GW = new QLabel(RIOMDebug);
        label_CAR1_GW->setObjectName(QString::fromUtf8("label_CAR1_GW"));
        label_CAR1_GW->setGeometry(QRect(180, 281, 190, 30));
        label_CAR1_GW->setAlignment(Qt::AlignCenter);
        label_CAR2_DO = new QLabel(RIOMDebug);
        label_CAR2_DO->setObjectName(QString::fromUtf8("label_CAR2_DO"));
        label_CAR2_DO->setGeometry(QRect(369, 223, 210, 30));
        label_CAR2_DO->setAlignment(Qt::AlignCenter);
        label_CAR3_DI1 = new QLabel(RIOMDebug);
        label_CAR3_DI1->setObjectName(QString::fromUtf8("label_CAR3_DI1"));
        label_CAR3_DI1->setGeometry(QRect(578, 107, 210, 30));
        label_CAR3_DI1->setAlignment(Qt::AlignCenter);
        label_CAR1_DI3 = new QLabel(RIOMDebug);
        label_CAR1_DI3->setObjectName(QString::fromUtf8("label_CAR1_DI3"));
        label_CAR1_DI3->setGeometry(QRect(180, 165, 190, 30));
        label_CAR1_DI3->setAlignment(Qt::AlignCenter);
        label_AX = new QLabel(RIOMDebug);
        label_AX->setObjectName(QString::fromUtf8("label_AX"));
        label_AX->setGeometry(QRect(51, 252, 130, 30));
        label_CAR4_DO = new QLabel(RIOMDebug);
        label_CAR4_DO->setObjectName(QString::fromUtf8("label_CAR4_DO"));
        label_CAR4_DO->setGeometry(QRect(787, 223, 180, 30));
        label_CAR4_DO->setAlignment(Qt::AlignCenter);
        label_CAR4_GW = new QLabel(RIOMDebug);
        label_CAR4_GW->setObjectName(QString::fromUtf8("label_CAR4_GW"));
        label_CAR4_GW->setGeometry(QRect(787, 281, 180, 30));
        label_CAR4_GW->setAlignment(Qt::AlignCenter);
        label_DO = new QLabel(RIOMDebug);
        label_DO->setObjectName(QString::fromUtf8("label_DO"));
        label_DO->setGeometry(QRect(51, 223, 130, 30));
        label_DI3 = new QLabel(RIOMDebug);
        label_DI3->setObjectName(QString::fromUtf8("label_DI3"));
        label_DI3->setGeometry(QRect(51, 165, 130, 30));
        label_CAR2_DI1 = new QLabel(RIOMDebug);
        label_CAR2_DI1->setObjectName(QString::fromUtf8("label_CAR2_DI1"));
        label_CAR2_DI1->setGeometry(QRect(369, 107, 210, 30));
        label_CAR2_DI1->setAlignment(Qt::AlignCenter);
        label_CAR2_DI2 = new QLabel(RIOMDebug);
        label_CAR2_DI2->setObjectName(QString::fromUtf8("label_CAR2_DI2"));
        label_CAR2_DI2->setGeometry(QRect(369, 136, 210, 30));
        label_CAR2_DI2->setAlignment(Qt::AlignCenter);
        label_DI1 = new QLabel(RIOMDebug);
        label_DI1->setObjectName(QString::fromUtf8("label_DI1"));
        label_DI1->setGeometry(QRect(51, 107, 130, 30));
        label_CAR2_GW = new QLabel(RIOMDebug);
        label_CAR2_GW->setObjectName(QString::fromUtf8("label_CAR2_GW"));
        label_CAR2_GW->setGeometry(QRect(369, 281, 210, 30));
        label_CAR2_GW->setAlignment(Qt::AlignCenter);
        label_CAR3_DO = new QLabel(RIOMDebug);
        label_CAR3_DO->setObjectName(QString::fromUtf8("label_CAR3_DO"));
        label_CAR3_DO->setGeometry(QRect(578, 223, 210, 30));
        label_CAR3_DO->setAlignment(Qt::AlignCenter);
        label_CAR3_DI3 = new QLabel(RIOMDebug);
        label_CAR3_DI3->setObjectName(QString::fromUtf8("label_CAR3_DI3"));
        label_CAR3_DI3->setGeometry(QRect(578, 165, 210, 30));
        label_CAR3_DI3->setAlignment(Qt::AlignCenter);
        label_CAR1_DI2 = new QLabel(RIOMDebug);
        label_CAR1_DI2->setObjectName(QString::fromUtf8("label_CAR1_DI2"));
        label_CAR1_DI2->setGeometry(QRect(180, 136, 190, 30));
        label_CAR1_DI2->setAlignment(Qt::AlignCenter);
        label_CAR1_DO = new QLabel(RIOMDebug);
        label_CAR1_DO->setObjectName(QString::fromUtf8("label_CAR1_DO"));
        label_CAR1_DO->setGeometry(QRect(180, 223, 190, 30));
        label_CAR1_DO->setAlignment(Qt::AlignCenter);
        label_CAR2_DI3 = new QLabel(RIOMDebug);
        label_CAR2_DI3->setObjectName(QString::fromUtf8("label_CAR2_DI3"));
        label_CAR2_DI3->setGeometry(QRect(369, 165, 210, 30));
        label_CAR2_DI3->setAlignment(Qt::AlignCenter);
        label_CAR2_LAT = new QLabel(RIOMDebug);
        label_CAR2_LAT->setObjectName(QString::fromUtf8("label_CAR2_LAT"));
        label_CAR2_LAT->setGeometry(QRect(369, 310, 210, 30));
        label_CAR2_LAT->setAlignment(Qt::AlignCenter);
        label_GW_2 = new QLabel(RIOMDebug);
        label_GW_2->setObjectName(QString::fromUtf8("label_GW_2"));
        label_GW_2->setGeometry(QRect(51, 339, 130, 30));
        label_CAR4_RLD = new QLabel(RIOMDebug);
        label_CAR4_RLD->setObjectName(QString::fromUtf8("label_CAR4_RLD"));
        label_CAR4_RLD->setGeometry(QRect(787, 339, 180, 30));
        label_CAR4_RLD->setAlignment(Qt::AlignCenter);
        label_CAR1_LAT = new QLabel(RIOMDebug);
        label_CAR1_LAT->setObjectName(QString::fromUtf8("label_CAR1_LAT"));
        label_CAR1_LAT->setGeometry(QRect(180, 310, 190, 30));
        label_CAR1_LAT->setAlignment(Qt::AlignCenter);
        label_CAR3_RLD = new QLabel(RIOMDebug);
        label_CAR3_RLD->setObjectName(QString::fromUtf8("label_CAR3_RLD"));
        label_CAR3_RLD->setGeometry(QRect(578, 339, 210, 30));
        label_CAR3_RLD->setAlignment(Qt::AlignCenter);
        label_CAR1_RLD = new QLabel(RIOMDebug);
        label_CAR1_RLD->setObjectName(QString::fromUtf8("label_CAR1_RLD"));
        label_CAR1_RLD->setGeometry(QRect(180, 339, 190, 30));
        label_CAR1_RLD->setAlignment(Qt::AlignCenter);
        label_CAR4_LAT = new QLabel(RIOMDebug);
        label_CAR4_LAT->setObjectName(QString::fromUtf8("label_CAR4_LAT"));
        label_CAR4_LAT->setGeometry(QRect(787, 310, 180, 30));
        label_CAR4_LAT->setAlignment(Qt::AlignCenter);
        label_CAR2_RLD = new QLabel(RIOMDebug);
        label_CAR2_RLD->setObjectName(QString::fromUtf8("label_CAR2_RLD"));
        label_CAR2_RLD->setGeometry(QRect(369, 339, 210, 30));
        label_CAR2_RLD->setAlignment(Qt::AlignCenter);
        label_CAR3_LAT = new QLabel(RIOMDebug);
        label_CAR3_LAT->setObjectName(QString::fromUtf8("label_CAR3_LAT"));
        label_CAR3_LAT->setGeometry(QRect(578, 310, 210, 30));
        label_CAR3_LAT->setAlignment(Qt::AlignCenter);
        label_AX_2 = new QLabel(RIOMDebug);
        label_AX_2->setObjectName(QString::fromUtf8("label_AX_2"));
        label_AX_2->setGeometry(QRect(51, 310, 130, 30));

        retranslateUi(RIOMDebug);

        QMetaObject::connectSlotsByName(RIOMDebug);
    } // setupUi

    void retranslateUi(QWidget *RIOMDebug)
    {
        RIOMDebug->setWindowTitle(QApplication::translate("RIOMDebug", "Form", 0, QApplication::UnicodeUTF8));
        label_CAR4_DI3->setText(QString());
        label_CAR3_DI4->setText(QString());
        label_CAR2_AX->setText(QString());
        label_CAR3_AX->setText(QString());
        label_CAR4_DI4->setText(QString());
        label_CAR3_GW->setText(QString());
        label_CAR2_DI4->setText(QString());
        label_CAR4_AX->setText(QString());
        label_DI4->setText(QApplication::translate("RIOMDebug", "DI4", 0, QApplication::UnicodeUTF8));
        label_CAR1_DI1->setText(QString());
        label_GW->setText(QApplication::translate("RIOMDebug", "IO-GW", 0, QApplication::UnicodeUTF8));
        label_CAR3_DI2->setText(QString());
        label_DI2->setText(QApplication::translate("RIOMDebug", "DI2", 0, QApplication::UnicodeUTF8));
        label_CAR1_DI4->setText(QString());
        btn_back->setText(QApplication::translate("RIOMDebug", "\350\277\224\345\233\236", 0, QApplication::UnicodeUTF8));
        label_CAR4_DI2->setText(QString());
        label_CAR1_AX->setText(QString());
        label_CAR4_DI1->setText(QString());
        label_CAR1_GW->setText(QString());
        label_CAR2_DO->setText(QString());
        label_CAR3_DI1->setText(QString());
        label_CAR1_DI3->setText(QString());
        label_AX->setText(QApplication::translate("RIOMDebug", "AX", 0, QApplication::UnicodeUTF8));
        label_CAR4_DO->setText(QString());
        label_CAR4_GW->setText(QString());
        label_DO->setText(QApplication::translate("RIOMDebug", "DO", 0, QApplication::UnicodeUTF8));
        label_DI3->setText(QApplication::translate("RIOMDebug", "DI3", 0, QApplication::UnicodeUTF8));
        label_CAR2_DI1->setText(QString());
        label_CAR2_DI2->setText(QString());
        label_DI1->setText(QApplication::translate("RIOMDebug", "DI1", 0, QApplication::UnicodeUTF8));
        label_CAR2_GW->setText(QString());
        label_CAR3_DO->setText(QString());
        label_CAR3_DI3->setText(QString());
        label_CAR1_DI2->setText(QString());
        label_CAR1_DO->setText(QString());
        label_CAR2_DI3->setText(QString());
        label_CAR2_LAT->setText(QString());
        label_GW_2->setText(QApplication::translate("RIOMDebug", "RLD", 0, QApplication::UnicodeUTF8));
        label_CAR4_RLD->setText(QString());
        label_CAR1_LAT->setText(QString());
        label_CAR3_RLD->setText(QString());
        label_CAR1_RLD->setText(QString());
        label_CAR4_LAT->setText(QString());
        label_CAR2_RLD->setText(QString());
        label_CAR3_LAT->setText(QString());
        label_AX_2->setText(QApplication::translate("RIOMDebug", "LAT", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class RIOMDebug: public Ui_RIOMDebug {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RIOMDEBUG_H
