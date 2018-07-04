/********************************************************************************
** Form generated from reading UI file 'publishsetpage.ui'
**
** Created: Thu Jan 11 11:16:18 2018
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PUBLISHSETPAGE_H
#define UI_PUBLISHSETPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PublishSetPage
{
public:
    QPushButton *btn_Tc1;
    QPushButton *btn_Restart;
    QPushButton *btn_Tc2;
    QPushButton *btn_Back;
    QLabel *label;

    void setupUi(QWidget *PublishSetPage)
    {
        if (PublishSetPage->objectName().isEmpty())
            PublishSetPage->setObjectName(QString::fromUtf8("PublishSetPage"));
        PublishSetPage->resize(1024, 768);
        PublishSetPage->setStyleSheet(QString::fromUtf8("QLabel\n"
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
        btn_Tc1 = new QPushButton(PublishSetPage);
        btn_Tc1->setObjectName(QString::fromUtf8("btn_Tc1"));
        btn_Tc1->setGeometry(QRect(240, 160, 141, 40));
        btn_Restart = new QPushButton(PublishSetPage);
        btn_Restart->setObjectName(QString::fromUtf8("btn_Restart"));
        btn_Restart->setGeometry(QRect(550, 440, 131, 40));
        btn_Tc2 = new QPushButton(PublishSetPage);
        btn_Tc2->setObjectName(QString::fromUtf8("btn_Tc2"));
        btn_Tc2->setGeometry(QRect(560, 160, 141, 40));
        btn_Back = new QPushButton(PublishSetPage);
        btn_Back->setObjectName(QString::fromUtf8("btn_Back"));
        btn_Back->setGeometry(QRect(800, 440, 101, 40));
        btn_Back->setStyleSheet(QString::fromUtf8(""));
        label = new QLabel(PublishSetPage);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(200, 280, 551, 51));
        label->setStyleSheet(QString::fromUtf8("border-color:black;\n"
"color:red;"));

        retranslateUi(PublishSetPage);

        QMetaObject::connectSlotsByName(PublishSetPage);
    } // setupUi

    void retranslateUi(QWidget *PublishSetPage)
    {
        PublishSetPage->setWindowTitle(QApplication::translate("PublishSetPage", "Form", 0, QApplication::UnicodeUTF8));
        btn_Tc1->setText(QApplication::translate("PublishSetPage", "\350\256\276\347\275\256\344\270\272TC1\347\253\257", 0, QApplication::UnicodeUTF8));
        btn_Restart->setText(QApplication::translate("PublishSetPage", "\351\207\215\345\220\257\346\230\276\347\244\272\345\261\217", 0, QApplication::UnicodeUTF8));
        btn_Tc2->setText(QApplication::translate("PublishSetPage", "\350\256\276\347\275\256\344\270\272TC2\347\253\257", 0, QApplication::UnicodeUTF8));
        btn_Back->setText(QApplication::translate("PublishSetPage", "\350\277\224\345\233\236", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("PublishSetPage", "\350\256\276\347\275\256\345\256\214\346\210\220\345\220\216\357\274\214\350\257\267\347\202\271\345\207\273\357\274\273\351\207\215\345\220\257\346\230\276\347\244\272\345\261\217\357\274\275\346\214\211\351\222\256\357\274\214\351\207\215\346\226\260\345\220\257\345\212\250\346\230\276\347\244\272\345\261\217\343\200\202", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class PublishSetPage: public Ui_PublishSetPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PUBLISHSETPAGE_H
