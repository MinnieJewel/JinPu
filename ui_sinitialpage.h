/********************************************************************************
** Form generated from reading UI file 'sinitialpage.ui'
**
** Created: Tue Oct 18 11:42:41 2016
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SINITIALPAGE_H
#define UI_SINITIALPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SInitialPage
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QLabel *label_11;

    void setupUi(QWidget *SInitialPage)
    {
        if (SInitialPage->objectName().isEmpty())
            SInitialPage->setObjectName(QString::fromUtf8("SInitialPage"));
        SInitialPage->resize(1024, 618);
        SInitialPage->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	color: white;\n"
"	border: 2px groove, gray;\n"
"    border-color: gray;\n"
"	font: 20px, \"SimHei\";\n"
"	\n"
"}\n"
"\n"
"QWidget\n"
"{\n"
"	background-color: black;\n"
"}"));
        label = new QLabel(SInitialPage);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(400, 39, 120, 60));
        label->setStyleSheet(QString::fromUtf8("    border-color: black;"));
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(SInitialPage);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(646, 39, 120, 60));
        label_2->setStyleSheet(QString::fromUtf8("    border-color: black;"));
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(SInitialPage);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(370, 132, 180, 40));
        label_4 = new QLabel(SInitialPage);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(615, 132, 180, 40));
        label_5 = new QLabel(SInitialPage);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(370, 203, 180, 40));
        label_6 = new QLabel(SInitialPage);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(615, 203, 180, 40));
        label_7 = new QLabel(SInitialPage);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(370, 273, 180, 40));
        label_8 = new QLabel(SInitialPage);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(615, 273, 180, 40));
        label_9 = new QLabel(SInitialPage);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(370, 343, 180, 40));
        label_10 = new QLabel(SInitialPage);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(615, 343, 180, 40));
        pushButton = new QPushButton(SInitialPage);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(200, 132, 120, 40));
        pushButton_2 = new QPushButton(SInitialPage);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(200, 203, 120, 40));
        pushButton_3 = new QPushButton(SInitialPage);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(200, 273, 120, 40));
        pushButton_4 = new QPushButton(SInitialPage);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(200, 343, 120, 40));
        label_11 = new QLabel(SInitialPage);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(60, 450, 711, 31));
        label_11->setStyleSheet(QString::fromUtf8("    border-color: black;\n"
"	font: 15px, \"SimHei\";"));
        label_11->setAlignment(Qt::AlignCenter);

        retranslateUi(SInitialPage);

        QMetaObject::connectSlotsByName(SInitialPage);
    } // setupUi

    void retranslateUi(QWidget *SInitialPage)
    {
        SInitialPage->setWindowTitle(QApplication::translate("SInitialPage", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("SInitialPage", "\346\226\260\350\256\276\345\256\232\345\200\274", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("SInitialPage", "\345\275\223\345\211\215\350\256\276\345\256\232\345\200\274", 0, QApplication::UnicodeUTF8));
        label_3->setText(QString());
        label_4->setText(QString());
        label_5->setText(QString());
        label_6->setText(QString());
        label_7->setText(QString());
        label_8->setText(QString());
        label_9->setText(QString());
        label_10->setText(QString());
        pushButton->setText(QApplication::translate("SInitialPage", "\345\247\213\345\217\221\347\253\231", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("SInitialPage", "\347\273\210\347\202\271\347\253\231", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("SInitialPage", "\345\275\223\345\211\215\347\253\231", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("SInitialPage", "\344\270\213\344\270\200\347\253\231", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("SInitialPage", "\350\257\267\350\256\276\345\256\232\344\273\245\344\270\212\345\220\204\346\235\241\345\220\216\357\274\214\346\214\211\345\217\263\344\270\213\350\247\222\357\274\273\347\241\256\350\256\244\357\274\275\351\224\256\343\200\202\347\255\211\345\276\205\357\274\273\347\241\256\350\256\244\357\274\275\346\214\211\351\222\256\345\274\271\350\265\267\357\274\214\344\270\224\345\275\223\345\211\215\350\256\276\345\256\232\345\200\274\344\270\200\350\207\264\346\227\266\357\274\214\350\241\250\346\230\216\350\256\276\347\275\256\347\224\237\346\225\210\343\200\202", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SInitialPage: public Ui_SInitialPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SINITIALPAGE_H
