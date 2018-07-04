/********************************************************************************
** Form generated from reading UI file 'chargerhelppage.ui'
**
** Created: Thu Jan 11 11:16:18 2018
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHARGERHELPPAGE_H
#define UI_CHARGERHELPPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChargerHelpPage
{
public:
    QLabel *label_voltage4_1;
    QLabel *label_viewItem;
    QLabel *label_viewCondition;
    QLabel *label_voltage4_2;
    QLabel *label_voltage3;
    QLabel *label_breakLevel2_3;
    QLabel *label_voltage4;
    QLabel *label_voltage;
    QLabel *label_voltage3_1;
    QLabel *label_voltage3_2;
    QLabel *label_viewComment;
    QLabel *label_voltage_2;
    QPushButton *btn_back;
    QLabel *NavigatorBackground;

    void setupUi(QWidget *ChargerHelpPage)
    {
        if (ChargerHelpPage->objectName().isEmpty())
            ChargerHelpPage->setObjectName(QString::fromUtf8("ChargerHelpPage"));
        ChargerHelpPage->resize(1024, 708);
        ChargerHelpPage->setStyleSheet(QString::fromUtf8("QLabel\n"
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
        label_voltage4_1 = new QLabel(ChargerHelpPage);
        label_voltage4_1->setObjectName(QString::fromUtf8("label_voltage4_1"));
        label_voltage4_1->setGeometry(QRect(400, 75, 150, 35));
        label_voltage4_1->setStyleSheet(QString::fromUtf8("background-color: white;"));
        label_viewItem = new QLabel(ChargerHelpPage);
        label_viewItem->setObjectName(QString::fromUtf8("label_viewItem"));
        label_viewItem->setGeometry(QRect(400, 5, 150, 35));
        label_viewItem->setStyleSheet(QString::fromUtf8("background-color: rgb(0,255,0);"));
        label_viewCondition = new QLabel(ChargerHelpPage);
        label_viewCondition->setObjectName(QString::fromUtf8("label_viewCondition"));
        label_viewCondition->setGeometry(QRect(250, 5, 150, 35));
        label_voltage4_2 = new QLabel(ChargerHelpPage);
        label_voltage4_2->setObjectName(QString::fromUtf8("label_voltage4_2"));
        label_voltage4_2->setGeometry(QRect(550, 75, 474, 35));
        label_voltage3 = new QLabel(ChargerHelpPage);
        label_voltage3->setObjectName(QString::fromUtf8("label_voltage3"));
        label_voltage3->setGeometry(QRect(250, 40, 150, 35));
        label_breakLevel2_3 = new QLabel(ChargerHelpPage);
        label_breakLevel2_3->setObjectName(QString::fromUtf8("label_breakLevel2_3"));
        label_breakLevel2_3->setGeometry(QRect(250, 110, 774, 140));
        label_voltage4 = new QLabel(ChargerHelpPage);
        label_voltage4->setObjectName(QString::fromUtf8("label_voltage4"));
        label_voltage4->setGeometry(QRect(250, 75, 150, 35));
        label_voltage = new QLabel(ChargerHelpPage);
        label_voltage->setObjectName(QString::fromUtf8("label_voltage"));
        label_voltage->setGeometry(QRect(0, 5, 250, 105));
        label_voltage3_1 = new QLabel(ChargerHelpPage);
        label_voltage3_1->setObjectName(QString::fromUtf8("label_voltage3_1"));
        label_voltage3_1->setGeometry(QRect(400, 40, 150, 35));
        label_voltage3_1->setStyleSheet(QString::fromUtf8("background-color: red;"));
        label_voltage3_2 = new QLabel(ChargerHelpPage);
        label_voltage3_2->setObjectName(QString::fromUtf8("label_voltage3_2"));
        label_voltage3_2->setGeometry(QRect(550, 40, 474, 35));
        label_viewComment = new QLabel(ChargerHelpPage);
        label_viewComment->setObjectName(QString::fromUtf8("label_viewComment"));
        label_viewComment->setGeometry(QRect(550, 5, 474, 35));
        label_voltage_2 = new QLabel(ChargerHelpPage);
        label_voltage_2->setObjectName(QString::fromUtf8("label_voltage_2"));
        label_voltage_2->setGeometry(QRect(0, 110, 250, 140));
        btn_back = new QPushButton(ChargerHelpPage);
        btn_back->setObjectName(QString::fromUtf8("btn_back"));
        btn_back->setGeometry(QRect(15, 653, 100, 40));
        btn_back->setStyleSheet(QString::fromUtf8("font: 20px, \"SimHei\";\n"
"color: black;\n"
"background-color: rgb(250, 250, 250);\n"
"border-radius: 5px;"));
        NavigatorBackground = new QLabel(ChargerHelpPage);
        NavigatorBackground->setObjectName(QString::fromUtf8("NavigatorBackground"));
        NavigatorBackground->setGeometry(QRect(0, 637, 1024, 70));
        NavigatorBackground->raise();
        label_voltage4_1->raise();
        label_viewItem->raise();
        label_viewCondition->raise();
        label_voltage4_2->raise();
        label_voltage3->raise();
        label_breakLevel2_3->raise();
        label_voltage4->raise();
        label_voltage->raise();
        label_voltage3_1->raise();
        label_voltage3_2->raise();
        label_viewComment->raise();
        label_voltage_2->raise();
        btn_back->raise();

        retranslateUi(ChargerHelpPage);

        QMetaObject::connectSlotsByName(ChargerHelpPage);
    } // setupUi

    void retranslateUi(QWidget *ChargerHelpPage)
    {
        ChargerHelpPage->setWindowTitle(QApplication::translate("ChargerHelpPage", "Form", 0, QApplication::UnicodeUTF8));
        label_voltage4_1->setText(QString());
        label_viewItem->setText(QString());
        label_viewCondition->setText(QApplication::translate("ChargerHelpPage", "\346\255\243\345\270\270", 0, QApplication::UnicodeUTF8));
        label_voltage4_2->setText(QString());
        label_voltage3->setText(QApplication::translate("ChargerHelpPage", "\346\225\205\351\232\234", 0, QApplication::UnicodeUTF8));
        label_breakLevel2_3->setText(QApplication::translate("ChargerHelpPage", "\346\230\276\347\244\272\345\256\236\351\231\205\345\200\274", 0, QApplication::UnicodeUTF8));
        label_voltage4->setText(QApplication::translate("ChargerHelpPage", "\351\200\232\344\277\241\345\274\202\345\270\270", 0, QApplication::UnicodeUTF8));
        label_voltage->setText(QApplication::translate("ChargerHelpPage", "\350\223\204\347\224\265\346\261\240\347\212\266\346\200\201", 0, QApplication::UnicodeUTF8));
        label_voltage3_1->setText(QString());
        label_voltage3_2->setText(QApplication::translate("ChargerHelpPage", "\350\223\204\347\224\265\346\261\240\345\267\245\344\275\234\344\270\215\346\255\243\345\270\270", 0, QApplication::UnicodeUTF8));
        label_viewComment->setText(QApplication::translate("ChargerHelpPage", "\350\223\204\347\224\265\346\261\240\345\267\245\344\275\234\346\255\243\345\270\270", 0, QApplication::UnicodeUTF8));
        label_voltage_2->setText(QApplication::translate("ChargerHelpPage", "\350\223\204\347\224\265\346\261\240\346\270\251\345\272\246/\350\223\204\347\224\265\346\261\240\347\224\265\345\216\213/ \n"
"\350\223\204\347\224\265\346\261\240\347\224\265\346\265\201/\347\224\265\347\275\221\347\224\265\345\216\213/ \n"
"\346\224\257\346\222\221\347\224\265\345\256\271\347\224\265\345\216\213/\347\224\265\347\275\221\344\276\247\347\224\265\346\265\201", 0, QApplication::UnicodeUTF8));
        btn_back->setText(QApplication::translate("ChargerHelpPage", "\350\277\224\345\233\236", 0, QApplication::UnicodeUTF8));
        NavigatorBackground->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ChargerHelpPage: public Ui_ChargerHelpPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHARGERHELPPAGE_H
