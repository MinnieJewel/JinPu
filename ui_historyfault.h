/********************************************************************************
** Form generated from reading UI file 'historyfault.ui'
**
** Created: Thu Jan 11 11:16:18 2018
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HISTORYFAULT_H
#define UI_HISTORYFAULT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HistoryFault
{
public:
    QPushButton *btn_firstPage;
    QPushButton *btn_next;
    QPushButton *btn_back;
    QPushButton *btn_lastPage;
    QPushButton *btn_pre;
    QLabel *label_page;

    void setupUi(QWidget *HistoryFault)
    {
        if (HistoryFault->objectName().isEmpty())
            HistoryFault->setObjectName(QString::fromUtf8("HistoryFault"));
        HistoryFault->resize(1024, 708);
        HistoryFault->setStyleSheet(QString::fromUtf8("QLabel\n"
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
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"	font: 20px, \"SimHei\";\n"
"    color: white;\n"
"	background-color: rgb(189, 214, 238);\n"
"	border-radius: 5px;\n"
"}"));
        btn_firstPage = new QPushButton(HistoryFault);
        btn_firstPage->setObjectName(QString::fromUtf8("btn_firstPage"));
        btn_firstPage->setGeometry(QRect(395, 650, 50, 40));
        btn_next = new QPushButton(HistoryFault);
        btn_next->setObjectName(QString::fromUtf8("btn_next"));
        btn_next->setGeometry(QRect(660, 650, 98, 40));
        btn_back = new QPushButton(HistoryFault);
        btn_back->setObjectName(QString::fromUtf8("btn_back"));
        btn_back->setGeometry(QRect(895, 650, 98, 40));
        btn_lastPage = new QPushButton(HistoryFault);
        btn_lastPage->setObjectName(QString::fromUtf8("btn_lastPage"));
        btn_lastPage->setGeometry(QRect(785, 650, 50, 40));
        btn_pre = new QPushButton(HistoryFault);
        btn_pre->setObjectName(QString::fromUtf8("btn_pre"));
        btn_pre->setGeometry(QRect(470, 650, 98, 40));
        label_page = new QLabel(HistoryFault);
        label_page->setObjectName(QString::fromUtf8("label_page"));
        label_page->setGeometry(QRect(575, 650, 80, 40));
        label_page->setStyleSheet(QString::fromUtf8("border-color:black;"));
        label_page->setAlignment(Qt::AlignCenter);

        retranslateUi(HistoryFault);

        QMetaObject::connectSlotsByName(HistoryFault);
    } // setupUi

    void retranslateUi(QWidget *HistoryFault)
    {
        HistoryFault->setWindowTitle(QApplication::translate("HistoryFault", "Form", 0, QApplication::UnicodeUTF8));
        btn_firstPage->setText(QApplication::translate("HistoryFault", "\351\246\226\351\241\265", 0, QApplication::UnicodeUTF8));
        btn_next->setText(QApplication::translate("HistoryFault", "\344\270\213\344\270\200\351\241\265", 0, QApplication::UnicodeUTF8));
        btn_back->setText(QApplication::translate("HistoryFault", "\350\277\224\345\233\236", 0, QApplication::UnicodeUTF8));
        btn_lastPage->setText(QApplication::translate("HistoryFault", "\345\260\276\351\241\265", 0, QApplication::UnicodeUTF8));
        btn_pre->setText(QApplication::translate("HistoryFault", "\344\270\212\344\270\200\351\241\265", 0, QApplication::UnicodeUTF8));
        label_page->setText(QApplication::translate("HistoryFault", "1/50", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class HistoryFault: public Ui_HistoryFault {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTORYFAULT_H
