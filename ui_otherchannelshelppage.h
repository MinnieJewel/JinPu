/********************************************************************************
** Form generated from reading UI file 'otherchannelshelppage.ui'
**
** Created: Thu Jan 11 11:16:18 2018
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OTHERCHANNELSHELPPAGE_H
#define UI_OTHERCHANNELSHELPPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OtherChannelsHelpPage
{
public:
    QLabel *label_breakLevel4_5;
    QLabel *label_breakLevel4_3;
    QLabel *label_viewComment;
    QLabel *label_voltage1;
    QLabel *label_viewCondition;
    QLabel *label_voltage1_2;
    QLabel *label_voltage;
    QLabel *label_viewItem;
    QLabel *label_breakLevel4_4;
    QLabel *label_voltage1_1;
    QLabel *label_current_2;
    QLabel *label_voltage4_6;
    QLabel *label_voltage_4;
    QLabel *label_voltage3_6;
    QLabel *label_voltage4_7;
    QLabel *label_voltage4_8;
    QLabel *label_voltage3_7;
    QLabel *label_voltage3_8;
    QLabel *NavigatorBackground;
    QPushButton *btn_back;

    void setupUi(QWidget *OtherChannelsHelpPage)
    {
        if (OtherChannelsHelpPage->objectName().isEmpty())
            OtherChannelsHelpPage->setObjectName(QString::fromUtf8("OtherChannelsHelpPage"));
        OtherChannelsHelpPage->resize(1024, 708);
        OtherChannelsHelpPage->setStyleSheet(QString::fromUtf8("QLabel\n"
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
        label_breakLevel4_5 = new QLabel(OtherChannelsHelpPage);
        label_breakLevel4_5->setObjectName(QString::fromUtf8("label_breakLevel4_5"));
        label_breakLevel4_5->setGeometry(QRect(250, 30, 150, 35));
        label_breakLevel4_3 = new QLabel(OtherChannelsHelpPage);
        label_breakLevel4_3->setObjectName(QString::fromUtf8("label_breakLevel4_3"));
        label_breakLevel4_3->setGeometry(QRect(550, 30, 474, 35));
        label_viewComment = new QLabel(OtherChannelsHelpPage);
        label_viewComment->setObjectName(QString::fromUtf8("label_viewComment"));
        label_viewComment->setGeometry(QRect(550, 65, 474, 35));
        label_voltage1 = new QLabel(OtherChannelsHelpPage);
        label_voltage1->setObjectName(QString::fromUtf8("label_voltage1"));
        label_voltage1->setGeometry(QRect(250, 100, 150, 35));
        label_viewCondition = new QLabel(OtherChannelsHelpPage);
        label_viewCondition->setObjectName(QString::fromUtf8("label_viewCondition"));
        label_viewCondition->setGeometry(QRect(250, 65, 150, 35));
        label_voltage1_2 = new QLabel(OtherChannelsHelpPage);
        label_voltage1_2->setObjectName(QString::fromUtf8("label_voltage1_2"));
        label_voltage1_2->setGeometry(QRect(550, 100, 474, 35));
        label_voltage = new QLabel(OtherChannelsHelpPage);
        label_voltage->setObjectName(QString::fromUtf8("label_voltage"));
        label_voltage->setGeometry(QRect(0, 65, 250, 70));
        label_viewItem = new QLabel(OtherChannelsHelpPage);
        label_viewItem->setObjectName(QString::fromUtf8("label_viewItem"));
        label_viewItem->setGeometry(QRect(400, 65, 150, 35));
        label_viewItem->setStyleSheet(QString::fromUtf8("background-color: rgb(0,255,0);"));
        label_breakLevel4_4 = new QLabel(OtherChannelsHelpPage);
        label_breakLevel4_4->setObjectName(QString::fromUtf8("label_breakLevel4_4"));
        label_breakLevel4_4->setGeometry(QRect(400, 30, 150, 35));
        label_breakLevel4_4->setStyleSheet(QString::fromUtf8(""));
        label_voltage1_1 = new QLabel(OtherChannelsHelpPage);
        label_voltage1_1->setObjectName(QString::fromUtf8("label_voltage1_1"));
        label_voltage1_1->setGeometry(QRect(400, 100, 150, 35));
        label_voltage1_1->setStyleSheet(QString::fromUtf8("background-color:yellow;"));
        label_current_2 = new QLabel(OtherChannelsHelpPage);
        label_current_2->setObjectName(QString::fromUtf8("label_current_2"));
        label_current_2->setGeometry(QRect(0, 30, 250, 35));
        label_voltage4_6 = new QLabel(OtherChannelsHelpPage);
        label_voltage4_6->setObjectName(QString::fromUtf8("label_voltage4_6"));
        label_voltage4_6->setGeometry(QRect(550, 170, 474, 35));
        label_voltage_4 = new QLabel(OtherChannelsHelpPage);
        label_voltage_4->setObjectName(QString::fromUtf8("label_voltage_4"));
        label_voltage_4->setGeometry(QRect(0, 135, 250, 70));
        label_voltage3_6 = new QLabel(OtherChannelsHelpPage);
        label_voltage3_6->setObjectName(QString::fromUtf8("label_voltage3_6"));
        label_voltage3_6->setGeometry(QRect(550, 135, 474, 35));
        label_voltage4_7 = new QLabel(OtherChannelsHelpPage);
        label_voltage4_7->setObjectName(QString::fromUtf8("label_voltage4_7"));
        label_voltage4_7->setGeometry(QRect(250, 170, 150, 35));
        label_voltage4_8 = new QLabel(OtherChannelsHelpPage);
        label_voltage4_8->setObjectName(QString::fromUtf8("label_voltage4_8"));
        label_voltage4_8->setGeometry(QRect(400, 170, 150, 35));
        label_voltage4_8->setStyleSheet(QString::fromUtf8("background-color: yellow;"));
        label_voltage3_7 = new QLabel(OtherChannelsHelpPage);
        label_voltage3_7->setObjectName(QString::fromUtf8("label_voltage3_7"));
        label_voltage3_7->setGeometry(QRect(250, 135, 150, 35));
        label_voltage3_8 = new QLabel(OtherChannelsHelpPage);
        label_voltage3_8->setObjectName(QString::fromUtf8("label_voltage3_8"));
        label_voltage3_8->setGeometry(QRect(400, 135, 150, 35));
        label_voltage3_8->setStyleSheet(QString::fromUtf8("background-color: rgb(0,255,0);"));
        NavigatorBackground = new QLabel(OtherChannelsHelpPage);
        NavigatorBackground->setObjectName(QString::fromUtf8("NavigatorBackground"));
        NavigatorBackground->setGeometry(QRect(0, 640, 1024, 70));
        btn_back = new QPushButton(OtherChannelsHelpPage);
        btn_back->setObjectName(QString::fromUtf8("btn_back"));
        btn_back->setGeometry(QRect(15, 653, 100, 40));
        btn_back->setStyleSheet(QString::fromUtf8("font: 20px, \"SimHei\";\n"
"color: black;\n"
"background-color: rgb(250, 250, 250);\n"
"border-radius: 5px;"));

        retranslateUi(OtherChannelsHelpPage);

        QMetaObject::connectSlotsByName(OtherChannelsHelpPage);
    } // setupUi

    void retranslateUi(QWidget *OtherChannelsHelpPage)
    {
        OtherChannelsHelpPage->setWindowTitle(QApplication::translate("OtherChannelsHelpPage", "Form", 0, QApplication::UnicodeUTF8));
        label_breakLevel4_5->setText(QApplication::translate("OtherChannelsHelpPage", "\346\230\276\347\244\272\346\235\241\344\273\266", 0, QApplication::UnicodeUTF8));
        label_breakLevel4_3->setText(QApplication::translate("OtherChannelsHelpPage", "\345\244\207\346\263\250", 0, QApplication::UnicodeUTF8));
        label_viewComment->setText(QString());
        label_voltage1->setText(QApplication::translate("OtherChannelsHelpPage", "\346\234\252\346\227\201\350\267\257", 0, QApplication::UnicodeUTF8));
        label_viewCondition->setText(QApplication::translate("OtherChannelsHelpPage", "\346\227\201\350\267\257", 0, QApplication::UnicodeUTF8));
        label_voltage1_2->setText(QString());
        label_voltage->setText(QApplication::translate("OtherChannelsHelpPage", "\346\227\201\350\267\257", 0, QApplication::UnicodeUTF8));
        label_viewItem->setText(QString());
        label_breakLevel4_4->setText(QApplication::translate("OtherChannelsHelpPage", "\346\230\276\347\244\272", 0, QApplication::UnicodeUTF8));
        label_voltage1_1->setText(QString());
        label_current_2->setText(QApplication::translate("OtherChannelsHelpPage", "\346\230\276\347\244\272\351\241\271\347\233\256", 0, QApplication::UnicodeUTF8));
        label_voltage4_6->setText(QString());
        label_voltage_4->setText(QApplication::translate("OtherChannelsHelpPage", "ATP\345\210\207\351\231\244", 0, QApplication::UnicodeUTF8));
        label_voltage3_6->setText(QString());
        label_voltage4_7->setText(QApplication::translate("OtherChannelsHelpPage", "\346\234\252\345\210\207\351\231\244", 0, QApplication::UnicodeUTF8));
        label_voltage4_8->setText(QString());
        label_voltage3_7->setText(QApplication::translate("OtherChannelsHelpPage", "\345\210\207\351\231\244", 0, QApplication::UnicodeUTF8));
        label_voltage3_8->setText(QString());
        NavigatorBackground->setText(QString());
        btn_back->setText(QApplication::translate("OtherChannelsHelpPage", "\350\277\224\345\233\236", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class OtherChannelsHelpPage: public Ui_OtherChannelsHelpPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OTHERCHANNELSHELPPAGE_H
