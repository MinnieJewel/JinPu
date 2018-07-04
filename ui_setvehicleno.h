/********************************************************************************
** Form generated from reading UI file 'setvehicleno.ui'
**
** Created: Thu Jan 11 11:16:18 2018
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETVEHICLENO_H
#define UI_SETVEHICLENO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SetVehicleNo
{
public:
    QLabel *label_vehicleNo;
    QLabel *label_lineNo;
    QPushButton *btn_vehicleNo;
    QPushButton *btn_lineNo;
    QPushButton *btn_2;
    QPushButton *btn_7;
    QPushButton *btn_Clear;
    QPushButton *btn_3;
    QPushButton *btn_1;
    QPushButton *btn_6;
    QPushButton *btn_5;
    QPushButton *btn_0;
    QPushButton *btn_9;
    QPushButton *btn_4;
    QPushButton *btn_back;
    QPushButton *btn_8;
    QPushButton *btn_confirm;
    QLabel *label_info;

    void setupUi(QWidget *SetVehicleNo)
    {
        if (SetVehicleNo->objectName().isEmpty())
            SetVehicleNo->setObjectName(QString::fromUtf8("SetVehicleNo"));
        SetVehicleNo->resize(1024, 688);
        SetVehicleNo->setStyleSheet(QString::fromUtf8("QLabel\n"
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
"}"));
        label_vehicleNo = new QLabel(SetVehicleNo);
        label_vehicleNo->setObjectName(QString::fromUtf8("label_vehicleNo"));
        label_vehicleNo->setGeometry(QRect(80, 140, 70, 50));
        label_vehicleNo->setStyleSheet(QString::fromUtf8("border-color:black;\n"
""));
        label_lineNo = new QLabel(SetVehicleNo);
        label_lineNo->setObjectName(QString::fromUtf8("label_lineNo"));
        label_lineNo->setGeometry(QRect(80, 240, 70, 50));
        label_lineNo->setStyleSheet(QString::fromUtf8("border-color:black;"));
        btn_vehicleNo = new QPushButton(SetVehicleNo);
        btn_vehicleNo->setObjectName(QString::fromUtf8("btn_vehicleNo"));
        btn_vehicleNo->setGeometry(QRect(200, 140, 300, 50));
        btn_lineNo = new QPushButton(SetVehicleNo);
        btn_lineNo->setObjectName(QString::fromUtf8("btn_lineNo"));
        btn_lineNo->setGeometry(QRect(200, 240, 300, 50));
        btn_2 = new QPushButton(SetVehicleNo);
        btn_2->setObjectName(QString::fromUtf8("btn_2"));
        btn_2->setGeometry(QRect(730, 260, 80, 80));
        btn_2->setStyleSheet(QString::fromUtf8("	border-radius: 5px;\n"
"	font: 20px, \"SimHei\";\n"
"    color: black;\n"
"	background-color: rgb(250, 250, 250);"));
        btn_7 = new QPushButton(SetVehicleNo);
        btn_7->setObjectName(QString::fromUtf8("btn_7"));
        btn_7->setGeometry(QRect(640, 80, 80, 80));
        btn_7->setStyleSheet(QString::fromUtf8("	border-radius:5px;\n"
"	font: 20px, \"SimHei\";\n"
"    color: black;\n"
"	background-color: rgb(250, 250, 250);"));
        btn_Clear = new QPushButton(SetVehicleNo);
        btn_Clear->setObjectName(QString::fromUtf8("btn_Clear"));
        btn_Clear->setGeometry(QRect(730, 350, 170, 80));
        btn_Clear->setStyleSheet(QString::fromUtf8("	border-radius: 5px;\n"
"	font: 20px, \"SimHei\";\n"
"    color: black;\n"
"	background-color: rgb(250, 250, 250);"));
        btn_3 = new QPushButton(SetVehicleNo);
        btn_3->setObjectName(QString::fromUtf8("btn_3"));
        btn_3->setGeometry(QRect(820, 260, 80, 80));
        btn_3->setStyleSheet(QString::fromUtf8("	border-radius: 5px;\n"
"	font: 20px, \"SimHei\";\n"
"    color: black;\n"
"	background-color: rgb(250, 250, 250);"));
        btn_1 = new QPushButton(SetVehicleNo);
        btn_1->setObjectName(QString::fromUtf8("btn_1"));
        btn_1->setGeometry(QRect(640, 260, 80, 80));
        btn_1->setStyleSheet(QString::fromUtf8("	border-radius: 5px;\n"
"	font: 20px, \"SimHei\";\n"
"    color: black;\n"
"	background-color: rgb(250, 250, 250);"));
        btn_6 = new QPushButton(SetVehicleNo);
        btn_6->setObjectName(QString::fromUtf8("btn_6"));
        btn_6->setGeometry(QRect(820, 170, 80, 80));
        btn_6->setStyleSheet(QString::fromUtf8("	border-radius: 5px;\n"
"	font: 20px, \"SimHei\";\n"
"    color: black;\n"
"	background-color: rgb(250, 250, 250);"));
        btn_5 = new QPushButton(SetVehicleNo);
        btn_5->setObjectName(QString::fromUtf8("btn_5"));
        btn_5->setGeometry(QRect(730, 170, 80, 80));
        btn_5->setStyleSheet(QString::fromUtf8("	border-radius: 5px;\n"
"	font: 20px, \"SimHei\";\n"
"    color: black;\n"
"	background-color: rgb(250, 250, 250);"));
        btn_0 = new QPushButton(SetVehicleNo);
        btn_0->setObjectName(QString::fromUtf8("btn_0"));
        btn_0->setGeometry(QRect(640, 350, 80, 80));
        btn_0->setStyleSheet(QString::fromUtf8("	border-radius: 5px;\n"
"	font: 20px, \"SimHei\";\n"
"    color: black;\n"
"	background-color: rgb(250, 250, 250);"));
        btn_9 = new QPushButton(SetVehicleNo);
        btn_9->setObjectName(QString::fromUtf8("btn_9"));
        btn_9->setGeometry(QRect(820, 80, 80, 80));
        btn_9->setStyleSheet(QString::fromUtf8("	border-radius: 5px;\n"
"	font: 20px, \"SimHei\";\n"
"    color: black;\n"
"	background-color: rgb(250, 250, 250);"));
        btn_4 = new QPushButton(SetVehicleNo);
        btn_4->setObjectName(QString::fromUtf8("btn_4"));
        btn_4->setGeometry(QRect(640, 170, 80, 80));
        btn_4->setStyleSheet(QString::fromUtf8("	border-radius: 5px;\n"
"	font: 20px, \"SimHei\";\n"
"    color: black;\n"
"	background-color: rgb(250, 250, 250);"));
        btn_back = new QPushButton(SetVehicleNo);
        btn_back->setObjectName(QString::fromUtf8("btn_back"));
        btn_back->setGeometry(QRect(790, 500, 98, 40));
        btn_back->setStyleSheet(QString::fromUtf8("QPushButton:disabled\n"
"{\n"
"		border-radius:5px;\n"
"	font: 20px, \"SimHei\";\n"
"    color: white;\n"
"	background-color: grey;\n"
"}\n"
"	\n"
"QPushButton\n"
"{\n"
"	border-radius: 5px;\n"
"	font: 20px, \"SimHei\";\n"
"    color: black;\n"
"	background-color: rgb(250, 250, 250);\n"
"}\n"
""));
        btn_8 = new QPushButton(SetVehicleNo);
        btn_8->setObjectName(QString::fromUtf8("btn_8"));
        btn_8->setGeometry(QRect(730, 80, 80, 80));
        btn_8->setStyleSheet(QString::fromUtf8("	border-radius: 5px;\n"
"	font: 20px, \"SimHei\";\n"
"    color: black;\n"
"	background-color: rgb(250, 250, 250);"));
        btn_confirm = new QPushButton(SetVehicleNo);
        btn_confirm->setObjectName(QString::fromUtf8("btn_confirm"));
        btn_confirm->setGeometry(QRect(640, 500, 98, 40));
        btn_confirm->setStyleSheet(QString::fromUtf8("QPushButton:disabled\n"
"{\n"
"		border-radius:5px;\n"
"	font: 20px, \"SimHei\";\n"
"    color: grey;\n"
"	background-color: rgb(221,221,221);\n"
"}\n"
"	\n"
"QPushButton\n"
"{\n"
"	border-radius: 5px;\n"
"	font: 20px, \"SimHei\";\n"
"    color: black;\n"
"	background-color: rgb(250, 250, 250);\n"
"}"));
        label_info = new QLabel(SetVehicleNo);
        label_info->setObjectName(QString::fromUtf8("label_info"));
        label_info->setGeometry(QRect(200, 420, 251, 91));
        label_info->setStyleSheet(QString::fromUtf8("border-color:black;\n"
"color:red;"));

        retranslateUi(SetVehicleNo);

        QMetaObject::connectSlotsByName(SetVehicleNo);
    } // setupUi

    void retranslateUi(QWidget *SetVehicleNo)
    {
        SetVehicleNo->setWindowTitle(QApplication::translate("SetVehicleNo", "Form", 0, QApplication::UnicodeUTF8));
        label_vehicleNo->setText(QApplication::translate("SetVehicleNo", "\345\210\227\350\275\246\345\217\267", 0, QApplication::UnicodeUTF8));
        label_lineNo->setText(QApplication::translate("SetVehicleNo", "\347\272\277\350\267\257\345\217\267", 0, QApplication::UnicodeUTF8));
        btn_vehicleNo->setText(QString());
        btn_lineNo->setText(QString());
        btn_2->setText(QApplication::translate("SetVehicleNo", "2", 0, QApplication::UnicodeUTF8));
        btn_7->setText(QApplication::translate("SetVehicleNo", "7", 0, QApplication::UnicodeUTF8));
        btn_Clear->setText(QApplication::translate("SetVehicleNo", "\346\270\205\347\251\272", 0, QApplication::UnicodeUTF8));
        btn_3->setText(QApplication::translate("SetVehicleNo", "3", 0, QApplication::UnicodeUTF8));
        btn_1->setText(QApplication::translate("SetVehicleNo", "1", 0, QApplication::UnicodeUTF8));
        btn_6->setText(QApplication::translate("SetVehicleNo", "6", 0, QApplication::UnicodeUTF8));
        btn_5->setText(QApplication::translate("SetVehicleNo", "5", 0, QApplication::UnicodeUTF8));
        btn_0->setText(QApplication::translate("SetVehicleNo", "0", 0, QApplication::UnicodeUTF8));
        btn_9->setText(QApplication::translate("SetVehicleNo", "9", 0, QApplication::UnicodeUTF8));
        btn_4->setText(QApplication::translate("SetVehicleNo", "4", 0, QApplication::UnicodeUTF8));
        btn_back->setText(QApplication::translate("SetVehicleNo", "\350\277\224\345\233\236", 0, QApplication::UnicodeUTF8));
        btn_8->setText(QApplication::translate("SetVehicleNo", "8", 0, QApplication::UnicodeUTF8));
        btn_confirm->setText(QApplication::translate("SetVehicleNo", "\347\241\256\350\256\244", 0, QApplication::UnicodeUTF8));
        label_info->setText(QApplication::translate("SetVehicleNo", "\345\210\227\350\275\246\345\217\267\350\214\203\345\233\264\345\234\2501\357\275\23620\344\271\213\351\227\264\n"
"\347\272\277\350\267\257\345\217\267\350\214\203\345\233\264\345\234\2500\357\275\236255\344\271\213\351\227\264", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SetVehicleNo: public Ui_SetVehicleNo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETVEHICLENO_H
