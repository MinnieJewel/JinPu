/********************************************************************************
** Form generated from reading UI file 'batteryhelppage.ui'
**
** Created: Thu Jan 11 11:16:18 2018
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BATTERYHELPPAGE_H
#define UI_BATTERYHELPPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BatteryHelpPage
{
public:
    QLabel *label_viewComment;
    QLabel *label_viewCondition;
    QLabel *label_voltage_2;
    QLabel *label_voltage4;
    QLabel *label_voltage4_2;
    QLabel *label_voltage3_2;
    QLabel *label_voltage3_1;
    QLabel *label_viewItem;
    QLabel *label_voltage;
    QLabel *label_voltage3;
    QLabel *label_voltage4_1;
    QLabel *label_breakLevel2_3;
    QLabel *label_voltage4_3;
    QLabel *label_voltage4_4;
    QLabel *label_voltage4_5;
    QPushButton *btn_back;
    QLabel *NavigatorBackground;

    void setupUi(QWidget *BatteryHelpPage)
    {
        if (BatteryHelpPage->objectName().isEmpty())
            BatteryHelpPage->setObjectName(QString::fromUtf8("BatteryHelpPage"));
        BatteryHelpPage->resize(1024, 708);
        BatteryHelpPage->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	color: white;\n"
"	border: 2px groove gray;\n"
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
        label_viewComment = new QLabel(BatteryHelpPage);
        label_viewComment->setObjectName(QString::fromUtf8("label_viewComment"));
        label_viewComment->setGeometry(QRect(550, 215, 474, 35));
        label_viewCondition = new QLabel(BatteryHelpPage);
        label_viewCondition->setObjectName(QString::fromUtf8("label_viewCondition"));
        label_viewCondition->setGeometry(QRect(250, 215, 150, 35));
        label_voltage_2 = new QLabel(BatteryHelpPage);
        label_voltage_2->setObjectName(QString::fromUtf8("label_voltage_2"));
        label_voltage_2->setGeometry(QRect(0, 5, 250, 211));
        label_voltage4 = new QLabel(BatteryHelpPage);
        label_voltage4->setObjectName(QString::fromUtf8("label_voltage4"));
        label_voltage4->setGeometry(QRect(250, 285, 150, 35));
        label_voltage4_2 = new QLabel(BatteryHelpPage);
        label_voltage4_2->setObjectName(QString::fromUtf8("label_voltage4_2"));
        label_voltage4_2->setGeometry(QRect(550, 285, 474, 35));
        label_voltage3_2 = new QLabel(BatteryHelpPage);
        label_voltage3_2->setObjectName(QString::fromUtf8("label_voltage3_2"));
        label_voltage3_2->setGeometry(QRect(550, 250, 474, 35));
        label_voltage3_1 = new QLabel(BatteryHelpPage);
        label_voltage3_1->setObjectName(QString::fromUtf8("label_voltage3_1"));
        label_voltage3_1->setGeometry(QRect(400, 250, 150, 35));
        label_voltage3_1->setStyleSheet(QString::fromUtf8("background-color: blue;"));
        label_viewItem = new QLabel(BatteryHelpPage);
        label_viewItem->setObjectName(QString::fromUtf8("label_viewItem"));
        label_viewItem->setGeometry(QRect(400, 215, 150, 35));
        label_viewItem->setStyleSheet(QString::fromUtf8("background-color: rgb(0,255,0);"));
        label_voltage = new QLabel(BatteryHelpPage);
        label_voltage->setObjectName(QString::fromUtf8("label_voltage"));
        label_voltage->setGeometry(QRect(0, 215, 250, 140));
        label_voltage3 = new QLabel(BatteryHelpPage);
        label_voltage3->setObjectName(QString::fromUtf8("label_voltage3"));
        label_voltage3->setGeometry(QRect(250, 250, 150, 35));
        label_voltage4_1 = new QLabel(BatteryHelpPage);
        label_voltage4_1->setObjectName(QString::fromUtf8("label_voltage4_1"));
        label_voltage4_1->setGeometry(QRect(400, 285, 150, 35));
        label_voltage4_1->setStyleSheet(QString::fromUtf8("background-color: yellow;"));
        label_breakLevel2_3 = new QLabel(BatteryHelpPage);
        label_breakLevel2_3->setObjectName(QString::fromUtf8("label_breakLevel2_3"));
        label_breakLevel2_3->setGeometry(QRect(250, 5, 774, 211));
        label_voltage4_3 = new QLabel(BatteryHelpPage);
        label_voltage4_3->setObjectName(QString::fromUtf8("label_voltage4_3"));
        label_voltage4_3->setGeometry(QRect(550, 320, 474, 35));
        label_voltage4_4 = new QLabel(BatteryHelpPage);
        label_voltage4_4->setObjectName(QString::fromUtf8("label_voltage4_4"));
        label_voltage4_4->setGeometry(QRect(400, 320, 150, 35));
        label_voltage4_4->setStyleSheet(QString::fromUtf8(""));
        label_voltage4_5 = new QLabel(BatteryHelpPage);
        label_voltage4_5->setObjectName(QString::fromUtf8("label_voltage4_5"));
        label_voltage4_5->setGeometry(QRect(250, 320, 150, 35));
        btn_back = new QPushButton(BatteryHelpPage);
        btn_back->setObjectName(QString::fromUtf8("btn_back"));
        btn_back->setGeometry(QRect(15, 653, 100, 40));
        btn_back->setStyleSheet(QString::fromUtf8("font: 20px, \"SimHei\";\n"
"color: black;\n"
"background-color: rgb(250, 250, 250);\n"
"border-radius: 5px;"));
        NavigatorBackground = new QLabel(BatteryHelpPage);
        NavigatorBackground->setObjectName(QString::fromUtf8("NavigatorBackground"));
        NavigatorBackground->setGeometry(QRect(0, 637, 1024, 70));
        NavigatorBackground->raise();
        label_viewComment->raise();
        label_viewCondition->raise();
        label_voltage_2->raise();
        label_voltage4->raise();
        label_voltage4_2->raise();
        label_voltage3_2->raise();
        label_voltage3_1->raise();
        label_viewItem->raise();
        label_voltage->raise();
        label_voltage3->raise();
        label_voltage4_1->raise();
        label_breakLevel2_3->raise();
        label_voltage4_3->raise();
        label_voltage4_4->raise();
        label_voltage4_5->raise();
        btn_back->raise();

        retranslateUi(BatteryHelpPage);

        QMetaObject::connectSlotsByName(BatteryHelpPage);
    } // setupUi

    void retranslateUi(QWidget *BatteryHelpPage)
    {
        BatteryHelpPage->setWindowTitle(QApplication::translate("BatteryHelpPage", "Form", 0, QApplication::UnicodeUTF8));
        label_viewComment->setText(QString());
        label_viewCondition->setText(QApplication::translate("BatteryHelpPage", "1", 0, QApplication::UnicodeUTF8));
        label_voltage_2->setText(QApplication::translate("BatteryHelpPage", "\345\205\205\347\224\265\347\224\265\345\216\213\345\200\274/\346\224\276\347\224\265\347\224\265\345\216\213\345\200\274/\n"
"\347\256\261\345\206\205\346\270\251\345\272\246\345\200\274/\345\205\205\347\224\265\347\224\265\346\265\201\345\200\274/\n"
"\346\224\276\347\224\265\347\224\265\346\265\201\345\200\274/\350\266\205\345\216\213\347\224\265\346\261\240/\n"
"\344\275\216\345\216\213\347\224\265\346\261\240/\350\266\205\346\270\251\347\224\265\346\261\240/\n"
"\350\266\205\345\206\205\351\230\273\347\224\265\346\261\240/\n"
"\350\266\205\345\216\213\346\212\245\350\255\246\347\224\265\346\261\240\345\200\274/\n"
"\345\234\260\345\216\213\346\212\245\350\255\246\347\224\265\346\261\240\345\200\274/\n"
"\350\266\205\346\270\251\346\212\245\350\255\246\347\224\265\346\261\240\345\200\274/\n"
"\350\266\205\345\206\205\351\230\273\346\212\245\350\255\246\347\224\265\346\261\240\345\200\274", 0, QApplication::UnicodeUTF8));
        label_voltage4->setText(QApplication::translate("BatteryHelpPage", "3", 0, QApplication::UnicodeUTF8));
        label_voltage4_2->setText(QString());
        label_voltage3_2->setText(QString());
        label_voltage3_1->setText(QString());
        label_viewItem->setText(QString());
        label_voltage->setText(QApplication::translate("BatteryHelpPage", "\346\212\245\350\255\246\346\214\207\347\244\272\347\201\257\347\212\266\346\200\201", 0, QApplication::UnicodeUTF8));
        label_voltage3->setText(QApplication::translate("BatteryHelpPage", "2", 0, QApplication::UnicodeUTF8));
        label_voltage4_1->setText(QString());
        label_breakLevel2_3->setText(QApplication::translate("BatteryHelpPage", "\346\230\276\347\244\272\345\256\236\351\231\205\345\200\274", 0, QApplication::UnicodeUTF8));
        label_voltage4_3->setText(QString());
        label_voltage4_4->setText(QString());
        label_voltage4_5->setText(QApplication::translate("BatteryHelpPage", "\346\227\240\346\225\210", 0, QApplication::UnicodeUTF8));
        btn_back->setText(QApplication::translate("BatteryHelpPage", "\350\277\224\345\233\236", 0, QApplication::UnicodeUTF8));
        NavigatorBackground->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class BatteryHelpPage: public Ui_BatteryHelpPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BATTERYHELPPAGE_H
