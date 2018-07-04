/********************************************************************************
** Form generated from reading UI file 'sivtestpage.ui'
**
** Created: Thu Jan 11 11:16:18 2018
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIVTESTPAGE_H
#define UI_SIVTESTPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SIVTestPage
{
public:
    QLabel *label_CCU4;
    QLabel *label_cut1;
    QLabel *label_CCU3;
    QLabel *label_CCU2;
    QLabel *label_reset4;
    QLabel *label_cut4;
    QLabel *label_cut;
    QLabel *label_CCU;
    QLabel *label_cut2;
    QLabel *label_reset2;
    QLabel *label_reset1;
    QLabel *label_reset;
    QLabel *label_cut3;
    QLabel *label_CCU1;
    QLabel *label_reset3;

    void setupUi(QWidget *SIVTestPage)
    {
        if (SIVTestPage->objectName().isEmpty())
            SIVTestPage->setObjectName(QString::fromUtf8("SIVTestPage"));
        SIVTestPage->resize(1024, 688);
        SIVTestPage->setStyleSheet(QString::fromUtf8("QLabel\n"
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
        label_CCU4 = new QLabel(SIVTestPage);
        label_CCU4->setObjectName(QString::fromUtf8("label_CCU4"));
        label_CCU4->setGeometry(QRect(779, 146, 180, 30));
        label_cut1 = new QLabel(SIVTestPage);
        label_cut1->setObjectName(QString::fromUtf8("label_cut1"));
        label_cut1->setGeometry(QRect(172, 204, 190, 30));
        label_cut1->setLayoutDirection(Qt::LeftToRight);
        label_cut1->setAlignment(Qt::AlignCenter);
        label_CCU3 = new QLabel(SIVTestPage);
        label_CCU3->setObjectName(QString::fromUtf8("label_CCU3"));
        label_CCU3->setGeometry(QRect(570, 146, 210, 30));
        label_CCU2 = new QLabel(SIVTestPage);
        label_CCU2->setObjectName(QString::fromUtf8("label_CCU2"));
        label_CCU2->setGeometry(QRect(361, 146, 210, 30));
        label_reset4 = new QLabel(SIVTestPage);
        label_reset4->setObjectName(QString::fromUtf8("label_reset4"));
        label_reset4->setGeometry(QRect(779, 175, 180, 30));
        label_reset4->setAlignment(Qt::AlignCenter);
        label_cut4 = new QLabel(SIVTestPage);
        label_cut4->setObjectName(QString::fromUtf8("label_cut4"));
        label_cut4->setGeometry(QRect(779, 204, 180, 30));
        label_cut4->setAlignment(Qt::AlignCenter);
        label_cut = new QLabel(SIVTestPage);
        label_cut->setObjectName(QString::fromUtf8("label_cut"));
        label_cut->setGeometry(QRect(43, 204, 130, 30));
        label_cut->setStyleSheet(QString::fromUtf8(""));
        label_CCU = new QLabel(SIVTestPage);
        label_CCU->setObjectName(QString::fromUtf8("label_CCU"));
        label_CCU->setGeometry(QRect(43, 146, 130, 30));
        label_cut2 = new QLabel(SIVTestPage);
        label_cut2->setObjectName(QString::fromUtf8("label_cut2"));
        label_cut2->setGeometry(QRect(361, 204, 210, 30));
        label_cut2->setStyleSheet(QString::fromUtf8(""));
        label_cut2->setAlignment(Qt::AlignCenter);
        label_reset2 = new QLabel(SIVTestPage);
        label_reset2->setObjectName(QString::fromUtf8("label_reset2"));
        label_reset2->setGeometry(QRect(361, 175, 210, 30));
        label_reset2->setStyleSheet(QString::fromUtf8(""));
        label_reset2->setAlignment(Qt::AlignCenter);
        label_reset1 = new QLabel(SIVTestPage);
        label_reset1->setObjectName(QString::fromUtf8("label_reset1"));
        label_reset1->setGeometry(QRect(172, 175, 190, 30));
        label_reset1->setLayoutDirection(Qt::LeftToRight);
        label_reset1->setAlignment(Qt::AlignCenter);
        label_reset = new QLabel(SIVTestPage);
        label_reset->setObjectName(QString::fromUtf8("label_reset"));
        label_reset->setGeometry(QRect(43, 175, 130, 30));
        label_reset->setStyleSheet(QString::fromUtf8(""));
        label_cut3 = new QLabel(SIVTestPage);
        label_cut3->setObjectName(QString::fromUtf8("label_cut3"));
        label_cut3->setGeometry(QRect(570, 204, 210, 30));
        label_cut3->setStyleSheet(QString::fromUtf8(""));
        label_cut3->setAlignment(Qt::AlignCenter);
        label_CCU1 = new QLabel(SIVTestPage);
        label_CCU1->setObjectName(QString::fromUtf8("label_CCU1"));
        label_CCU1->setGeometry(QRect(172, 146, 190, 30));
        label_reset3 = new QLabel(SIVTestPage);
        label_reset3->setObjectName(QString::fromUtf8("label_reset3"));
        label_reset3->setGeometry(QRect(570, 175, 210, 30));
        label_reset3->setStyleSheet(QString::fromUtf8(""));
        label_reset3->setAlignment(Qt::AlignCenter);

        retranslateUi(SIVTestPage);

        QMetaObject::connectSlotsByName(SIVTestPage);
    } // setupUi

    void retranslateUi(QWidget *SIVTestPage)
    {
        SIVTestPage->setWindowTitle(QApplication::translate("SIVTestPage", "Form", 0, QApplication::UnicodeUTF8));
        label_CCU4->setText(QApplication::translate("SIVTestPage", "4", 0, QApplication::UnicodeUTF8));
        label_cut1->setText(QString());
        label_CCU3->setText(QApplication::translate("SIVTestPage", "3", 0, QApplication::UnicodeUTF8));
        label_CCU2->setText(QApplication::translate("SIVTestPage", "2", 0, QApplication::UnicodeUTF8));
        label_reset4->setText(QString());
        label_cut4->setText(QString());
        label_cut->setText(QApplication::translate("SIVTestPage", "\345\210\207\351\231\244", 0, QApplication::UnicodeUTF8));
        label_CCU->setText(QApplication::translate("SIVTestPage", "\350\275\246\345\217\267", 0, QApplication::UnicodeUTF8));
        label_cut2->setText(QApplication::translate("SIVTestPage", "--", 0, QApplication::UnicodeUTF8));
        label_reset2->setText(QApplication::translate("SIVTestPage", "--", 0, QApplication::UnicodeUTF8));
        label_reset1->setText(QString());
        label_reset->setText(QApplication::translate("SIVTestPage", "\345\244\215\344\275\215", 0, QApplication::UnicodeUTF8));
        label_cut3->setText(QApplication::translate("SIVTestPage", "--", 0, QApplication::UnicodeUTF8));
        label_CCU1->setText(QApplication::translate("SIVTestPage", "1", 0, QApplication::UnicodeUTF8));
        label_reset3->setText(QApplication::translate("SIVTestPage", "--", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SIVTestPage: public Ui_SIVTestPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIVTESTPAGE_H
