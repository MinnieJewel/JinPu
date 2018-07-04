/********************************************************************************
** Form generated from reading UI file 'maintainloginpage.ui'
**
** Created: Thu Jan 11 11:16:18 2018
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINTAINLOGINPAGE_H
#define UI_MAINTAINLOGINPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MaintainLoginPage
{
public:
    QPushButton *pushButton9;
    QPushButton *pushButton0;
    QPushButton *pushButton3;
    QPushButton *pushButton4;
    QPushButton *pushButton2;
    QPushButton *btn_back;
    QPushButton *pushButton1;
    QPushButton *pushButton_clear;
    QPushButton *btn_confirm;
    QPushButton *pushButton8;
    QLabel *label_input;
    QPushButton *pushButton6;
    QLabel *label1;
    QPushButton *pushButton5;
    QPushButton *pushButton7;
    QLabel *label_remindInfo;

    void setupUi(QWidget *MaintainLoginPage)
    {
        if (MaintainLoginPage->objectName().isEmpty())
            MaintainLoginPage->setObjectName(QString::fromUtf8("MaintainLoginPage"));
        MaintainLoginPage->resize(1024, 688);
        MaintainLoginPage->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	color: white;\n"
"	border: 2px groove, gray;\n"
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
        pushButton9 = new QPushButton(MaintainLoginPage);
        pushButton9->setObjectName(QString::fromUtf8("pushButton9"));
        pushButton9->setGeometry(QRect(830, 70, 80, 80));
        pushButton0 = new QPushButton(MaintainLoginPage);
        pushButton0->setObjectName(QString::fromUtf8("pushButton0"));
        pushButton0->setGeometry(QRect(650, 340, 80, 80));
        pushButton3 = new QPushButton(MaintainLoginPage);
        pushButton3->setObjectName(QString::fromUtf8("pushButton3"));
        pushButton3->setGeometry(QRect(830, 250, 80, 80));
        pushButton4 = new QPushButton(MaintainLoginPage);
        pushButton4->setObjectName(QString::fromUtf8("pushButton4"));
        pushButton4->setGeometry(QRect(650, 160, 80, 80));
        pushButton2 = new QPushButton(MaintainLoginPage);
        pushButton2->setObjectName(QString::fromUtf8("pushButton2"));
        pushButton2->setGeometry(QRect(740, 250, 80, 80));
        btn_back = new QPushButton(MaintainLoginPage);
        btn_back->setObjectName(QString::fromUtf8("btn_back"));
        btn_back->setEnabled(true);
        btn_back->setGeometry(QRect(880, 550, 98, 40));
        btn_back->setStyleSheet(QString::fromUtf8("	border-radius: 5px;\n"
"	font: 20px, \"SimHei\";"));
        pushButton1 = new QPushButton(MaintainLoginPage);
        pushButton1->setObjectName(QString::fromUtf8("pushButton1"));
        pushButton1->setGeometry(QRect(650, 250, 80, 80));
        pushButton_clear = new QPushButton(MaintainLoginPage);
        pushButton_clear->setObjectName(QString::fromUtf8("pushButton_clear"));
        pushButton_clear->setGeometry(QRect(740, 340, 170, 80));
        btn_confirm = new QPushButton(MaintainLoginPage);
        btn_confirm->setObjectName(QString::fromUtf8("btn_confirm"));
        btn_confirm->setGeometry(QRect(710, 550, 98, 40));
        btn_confirm->setStyleSheet(QString::fromUtf8("	border-radius: 5px;\n"
"	font: 20px, \"SimHei\";"));
        pushButton8 = new QPushButton(MaintainLoginPage);
        pushButton8->setObjectName(QString::fromUtf8("pushButton8"));
        pushButton8->setGeometry(QRect(740, 70, 80, 80));
        label_input = new QLabel(MaintainLoginPage);
        label_input->setObjectName(QString::fromUtf8("label_input"));
        label_input->setGeometry(QRect(240, 200, 350, 50));
        label_input->setStyleSheet(QString::fromUtf8("	border: 2px groove, gray;\n"
"    border-color: gray;"));
        pushButton6 = new QPushButton(MaintainLoginPage);
        pushButton6->setObjectName(QString::fromUtf8("pushButton6"));
        pushButton6->setGeometry(QRect(830, 160, 80, 80));
        label1 = new QLabel(MaintainLoginPage);
        label1->setObjectName(QString::fromUtf8("label1"));
        label1->setGeometry(QRect(60, 200, 150, 50));
        pushButton5 = new QPushButton(MaintainLoginPage);
        pushButton5->setObjectName(QString::fromUtf8("pushButton5"));
        pushButton5->setGeometry(QRect(740, 160, 80, 80));
        pushButton7 = new QPushButton(MaintainLoginPage);
        pushButton7->setObjectName(QString::fromUtf8("pushButton7"));
        pushButton7->setGeometry(QRect(650, 70, 80, 80));
        label_remindInfo = new QLabel(MaintainLoginPage);
        label_remindInfo->setObjectName(QString::fromUtf8("label_remindInfo"));
        label_remindInfo->setGeometry(QRect(320, 280, 231, 31));
        label_remindInfo->setStyleSheet(QString::fromUtf8("	color: red;\n"
"	font: 20px, \"SimHei\";	"));

        retranslateUi(MaintainLoginPage);

        QMetaObject::connectSlotsByName(MaintainLoginPage);
    } // setupUi

    void retranslateUi(QWidget *MaintainLoginPage)
    {
        MaintainLoginPage->setWindowTitle(QApplication::translate("MaintainLoginPage", "Form", 0, QApplication::UnicodeUTF8));
        pushButton9->setText(QApplication::translate("MaintainLoginPage", "9", 0, QApplication::UnicodeUTF8));
        pushButton0->setText(QApplication::translate("MaintainLoginPage", "0", 0, QApplication::UnicodeUTF8));
        pushButton3->setText(QApplication::translate("MaintainLoginPage", "3", 0, QApplication::UnicodeUTF8));
        pushButton4->setText(QApplication::translate("MaintainLoginPage", "4", 0, QApplication::UnicodeUTF8));
        pushButton2->setText(QApplication::translate("MaintainLoginPage", "2", 0, QApplication::UnicodeUTF8));
        btn_back->setText(QApplication::translate("MaintainLoginPage", "\350\277\224\345\233\236", 0, QApplication::UnicodeUTF8));
        pushButton1->setText(QApplication::translate("MaintainLoginPage", "1", 0, QApplication::UnicodeUTF8));
        pushButton_clear->setText(QApplication::translate("MaintainLoginPage", "\346\270\205\347\251\272", 0, QApplication::UnicodeUTF8));
        btn_confirm->setText(QApplication::translate("MaintainLoginPage", "\347\241\256\350\256\244", 0, QApplication::UnicodeUTF8));
        pushButton8->setText(QApplication::translate("MaintainLoginPage", "8", 0, QApplication::UnicodeUTF8));
        label_input->setText(QString());
        pushButton6->setText(QApplication::translate("MaintainLoginPage", "6", 0, QApplication::UnicodeUTF8));
        label1->setText(QApplication::translate("MaintainLoginPage", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", 0, QApplication::UnicodeUTF8));
        pushButton5->setText(QApplication::translate("MaintainLoginPage", "5", 0, QApplication::UnicodeUTF8));
        pushButton7->setText(QApplication::translate("MaintainLoginPage", "7", 0, QApplication::UnicodeUTF8));
        label_remindInfo->setText(QApplication::translate("MaintainLoginPage", "\345\257\206\347\240\201\351\224\231\350\257\257\357\274\214\350\257\267\351\207\215\346\226\260\350\276\223\345\205\245\357\274\201", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MaintainLoginPage: public Ui_MaintainLoginPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINTAINLOGINPAGE_H
