/********************************************************************************
** Form generated from reading UI file 'setpasswordpage.ui'
**
** Created: Thu Jan 11 11:16:18 2018
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETPASSWORDPAGE_H
#define UI_SETPASSWORDPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SetPasswordPage
{
public:
    QLabel *label1;
    QPushButton *btn_4;
    QPushButton *btn_clear;
    QPushButton *btn_5;
    QPushButton *btn_6;
    QPushButton *btn_3;
    QPushButton *btn_2;
    QPushButton *btn_1;
    QPushButton *btn_0;
    QLabel *label2;
    QLabel *label3;
    QLabel *label_remind;
    QPushButton *btn_9;
    QPushButton *btn_8;
    QPushButton *btn_7;
    QPushButton *btn_back;
    QPushButton *btn_confirm;
    QPushButton *btn_currentPwd;
    QPushButton *btn_newPwd;
    QPushButton *btn_confirmPwd;
    QLabel *label_pwdConfirm;
    QLabel *label_confirm2;

    void setupUi(QWidget *SetPasswordPage)
    {
        if (SetPasswordPage->objectName().isEmpty())
            SetPasswordPage->setObjectName(QString::fromUtf8("SetPasswordPage"));
        SetPasswordPage->resize(1024, 618);
        SetPasswordPage->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	color: white;\n"
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
"	font: 30px, \"SimHei\";\n"
"    color: black;\n"
"	background-color: rgb(250, 250, 250);\n"
"}\n"
"QPushButton:disabled\n"
"{\n"
"	border-radius:5px;\n"
"	font: 30px, \"SimHei\";\n"
"    color: grey;\n"
"	background-color: rgb(221,221,221);\n"
"}"));
        label1 = new QLabel(SetPasswordPage);
        label1->setObjectName(QString::fromUtf8("label1"));
        label1->setGeometry(QRect(50, 110, 150, 50));
        btn_4 = new QPushButton(SetPasswordPage);
        btn_4->setObjectName(QString::fromUtf8("btn_4"));
        btn_4->setGeometry(QRect(660, 170, 80, 80));
        btn_clear = new QPushButton(SetPasswordPage);
        btn_clear->setObjectName(QString::fromUtf8("btn_clear"));
        btn_clear->setGeometry(QRect(750, 350, 170, 80));
        btn_5 = new QPushButton(SetPasswordPage);
        btn_5->setObjectName(QString::fromUtf8("btn_5"));
        btn_5->setGeometry(QRect(750, 170, 80, 80));
        btn_6 = new QPushButton(SetPasswordPage);
        btn_6->setObjectName(QString::fromUtf8("btn_6"));
        btn_6->setGeometry(QRect(840, 170, 80, 80));
        btn_3 = new QPushButton(SetPasswordPage);
        btn_3->setObjectName(QString::fromUtf8("btn_3"));
        btn_3->setGeometry(QRect(840, 260, 80, 80));
        btn_2 = new QPushButton(SetPasswordPage);
        btn_2->setObjectName(QString::fromUtf8("btn_2"));
        btn_2->setGeometry(QRect(750, 260, 80, 80));
        btn_1 = new QPushButton(SetPasswordPage);
        btn_1->setObjectName(QString::fromUtf8("btn_1"));
        btn_1->setGeometry(QRect(660, 260, 80, 80));
        btn_0 = new QPushButton(SetPasswordPage);
        btn_0->setObjectName(QString::fromUtf8("btn_0"));
        btn_0->setGeometry(QRect(660, 350, 80, 80));
        label2 = new QLabel(SetPasswordPage);
        label2->setObjectName(QString::fromUtf8("label2"));
        label2->setGeometry(QRect(50, 210, 150, 50));
        label3 = new QLabel(SetPasswordPage);
        label3->setObjectName(QString::fromUtf8("label3"));
        label3->setGeometry(QRect(50, 310, 150, 50));
        label_remind = new QLabel(SetPasswordPage);
        label_remind->setObjectName(QString::fromUtf8("label_remind"));
        label_remind->setGeometry(QRect(50, 460, 401, 21));
        btn_9 = new QPushButton(SetPasswordPage);
        btn_9->setObjectName(QString::fromUtf8("btn_9"));
        btn_9->setGeometry(QRect(840, 80, 80, 80));
        btn_8 = new QPushButton(SetPasswordPage);
        btn_8->setObjectName(QString::fromUtf8("btn_8"));
        btn_8->setGeometry(QRect(750, 80, 80, 80));
        btn_7 = new QPushButton(SetPasswordPage);
        btn_7->setObjectName(QString::fromUtf8("btn_7"));
        btn_7->setGeometry(QRect(660, 80, 80, 80));
        btn_back = new QPushButton(SetPasswordPage);
        btn_back->setObjectName(QString::fromUtf8("btn_back"));
        btn_back->setEnabled(true);
        btn_back->setGeometry(QRect(890, 550, 98, 40));
        btn_back->setStyleSheet(QString::fromUtf8("	border-radius: 5px;\n"
"	font: 20px, \"SimHei\";"));
        btn_confirm = new QPushButton(SetPasswordPage);
        btn_confirm->setObjectName(QString::fromUtf8("btn_confirm"));
        btn_confirm->setGeometry(QRect(720, 550, 98, 40));
        btn_confirm->setStyleSheet(QString::fromUtf8("	border-radius: 5px;\n"
"	font: 20px, \"SimHei\";"));
        btn_currentPwd = new QPushButton(SetPasswordPage);
        btn_currentPwd->setObjectName(QString::fromUtf8("btn_currentPwd"));
        btn_currentPwd->setGeometry(QRect(217, 110, 300, 50));
        btn_newPwd = new QPushButton(SetPasswordPage);
        btn_newPwd->setObjectName(QString::fromUtf8("btn_newPwd"));
        btn_newPwd->setGeometry(QRect(220, 210, 300, 50));
        btn_confirmPwd = new QPushButton(SetPasswordPage);
        btn_confirmPwd->setObjectName(QString::fromUtf8("btn_confirmPwd"));
        btn_confirmPwd->setGeometry(QRect(220, 310, 300, 50));
        label_pwdConfirm = new QLabel(SetPasswordPage);
        label_pwdConfirm->setObjectName(QString::fromUtf8("label_pwdConfirm"));
        label_pwdConfirm->setGeometry(QRect(530, 110, 50, 50));
        label_pwdConfirm->setStyleSheet(QString::fromUtf8(""));
        label_confirm2 = new QLabel(SetPasswordPage);
        label_confirm2->setObjectName(QString::fromUtf8("label_confirm2"));
        label_confirm2->setGeometry(QRect(50, 420, 401, 21));
        label_confirm2->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));

        retranslateUi(SetPasswordPage);

        QMetaObject::connectSlotsByName(SetPasswordPage);
    } // setupUi

    void retranslateUi(QWidget *SetPasswordPage)
    {
        SetPasswordPage->setWindowTitle(QApplication::translate("SetPasswordPage", "Form", 0, QApplication::UnicodeUTF8));
        label1->setText(QApplication::translate("SetPasswordPage", "\345\275\223\345\211\215\345\257\206\347\240\201", 0, QApplication::UnicodeUTF8));
        btn_4->setText(QApplication::translate("SetPasswordPage", "4", 0, QApplication::UnicodeUTF8));
        btn_clear->setText(QApplication::translate("SetPasswordPage", "\346\270\205\347\251\272", 0, QApplication::UnicodeUTF8));
        btn_5->setText(QApplication::translate("SetPasswordPage", "5", 0, QApplication::UnicodeUTF8));
        btn_6->setText(QApplication::translate("SetPasswordPage", "6", 0, QApplication::UnicodeUTF8));
        btn_3->setText(QApplication::translate("SetPasswordPage", "3", 0, QApplication::UnicodeUTF8));
        btn_2->setText(QApplication::translate("SetPasswordPage", "2", 0, QApplication::UnicodeUTF8));
        btn_1->setText(QApplication::translate("SetPasswordPage", "1", 0, QApplication::UnicodeUTF8));
        btn_0->setText(QApplication::translate("SetPasswordPage", "0", 0, QApplication::UnicodeUTF8));
        label2->setText(QApplication::translate("SetPasswordPage", "\346\226\260\345\257\206\347\240\201", 0, QApplication::UnicodeUTF8));
        label3->setText(QApplication::translate("SetPasswordPage", "\347\241\256\350\256\244\346\226\260\345\257\206\347\240\201", 0, QApplication::UnicodeUTF8));
        label_remind->setText(QApplication::translate("SetPasswordPage", "3\344\270\252\345\257\206\347\240\201\350\276\223\345\205\245\345\256\214\346\257\225\345\220\216\350\257\267\347\202\271\345\207\273\345\217\263\344\270\213\350\247\222\357\274\273\347\241\256\350\256\244\357\274\275\351\224\256\343\200\202", 0, QApplication::UnicodeUTF8));
        btn_9->setText(QApplication::translate("SetPasswordPage", "9", 0, QApplication::UnicodeUTF8));
        btn_8->setText(QApplication::translate("SetPasswordPage", "8", 0, QApplication::UnicodeUTF8));
        btn_7->setText(QApplication::translate("SetPasswordPage", "7", 0, QApplication::UnicodeUTF8));
        btn_back->setText(QApplication::translate("SetPasswordPage", "\350\277\224\345\233\236", 0, QApplication::UnicodeUTF8));
        btn_confirm->setText(QApplication::translate("SetPasswordPage", "\347\241\256\350\256\244", 0, QApplication::UnicodeUTF8));
        btn_currentPwd->setText(QString());
        btn_newPwd->setText(QString());
        btn_confirmPwd->setText(QString());
        label_pwdConfirm->setText(QString());
        label_confirm2->setText(QApplication::translate("SetPasswordPage", "\346\226\260\345\257\206\347\240\201\350\276\223\345\205\245\344\270\215\344\270\200\350\207\264\357\274\214\350\257\267\351\207\215\346\226\260\350\276\223\345\205\245\343\200\202", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SetPasswordPage: public Ui_SetPasswordPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETPASSWORDPAGE_H
