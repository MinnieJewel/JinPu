/********************************************************************************
** Form generated from reading UI file 'setparameterpage.ui'
**
** Created: Thu Jan 11 11:16:18 2018
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETPARAMETERPAGE_H
#define UI_SETPARAMETERPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SetParameterPage
{
public:
    QPushButton *btn_wheelDia;
    QPushButton *btn_Back;
    QPushButton *btn_setTime;
    QPushButton *pushButton_3;
    QPushButton *btn_setVehicleNo;
    QPushButton *btn_tractionIsolate;

    void setupUi(QWidget *SetParameterPage)
    {
        if (SetParameterPage->objectName().isEmpty())
            SetParameterPage->setObjectName(QString::fromUtf8("SetParameterPage"));
        SetParameterPage->resize(1024, 688);
        SetParameterPage->setStyleSheet(QString::fromUtf8("QLabel\n"
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
        btn_wheelDia = new QPushButton(SetParameterPage);
        btn_wheelDia->setObjectName(QString::fromUtf8("btn_wheelDia"));
        btn_wheelDia->setGeometry(QRect(120, 140, 120, 40));
        btn_Back = new QPushButton(SetParameterPage);
        btn_Back->setObjectName(QString::fromUtf8("btn_Back"));
        btn_Back->setGeometry(QRect(770, 570, 98, 40));
        btn_setTime = new QPushButton(SetParameterPage);
        btn_setTime->setObjectName(QString::fromUtf8("btn_setTime"));
        btn_setTime->setGeometry(QRect(770, 140, 120, 40));
        pushButton_3 = new QPushButton(SetParameterPage);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(440, 140, 120, 40));
        btn_setVehicleNo = new QPushButton(SetParameterPage);
        btn_setVehicleNo->setObjectName(QString::fromUtf8("btn_setVehicleNo"));
        btn_setVehicleNo->setGeometry(QRect(440, 260, 291, 40));
        btn_tractionIsolate = new QPushButton(SetParameterPage);
        btn_tractionIsolate->setObjectName(QString::fromUtf8("btn_tractionIsolate"));
        btn_tractionIsolate->setGeometry(QRect(120, 260, 120, 40));

        retranslateUi(SetParameterPage);

        QMetaObject::connectSlotsByName(SetParameterPage);
    } // setupUi

    void retranslateUi(QWidget *SetParameterPage)
    {
        SetParameterPage->setWindowTitle(QApplication::translate("SetParameterPage", "Form", 0, QApplication::UnicodeUTF8));
        btn_wheelDia->setText(QApplication::translate("SetParameterPage", "\350\275\256\345\276\204\345\200\274", 0, QApplication::UnicodeUTF8));
        btn_Back->setText(QApplication::translate("SetParameterPage", "\350\277\224\345\233\236", 0, QApplication::UnicodeUTF8));
        btn_setTime->setText(QApplication::translate("SetParameterPage", "\346\227\266\351\227\264\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("SetParameterPage", "\345\257\206\347\240\201\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        btn_setVehicleNo->setText(QApplication::translate("SetParameterPage", "\345\210\227\350\275\246\345\217\267/\347\272\277\350\267\257\345\217\267\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        btn_tractionIsolate->setText(QApplication::translate("SetParameterPage", "\347\211\265\345\274\225\351\232\224\347\246\273", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SetParameterPage: public Ui_SetParameterPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETPARAMETERPAGE_H
