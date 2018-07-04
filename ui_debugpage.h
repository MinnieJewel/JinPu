/********************************************************************************
** Form generated from reading UI file 'debugpage.ui'
**
** Created: Thu Jan 11 11:16:18 2018
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEBUGPAGE_H
#define UI_DEBUGPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DebugPage
{
public:
    QPushButton *btn_LifeSignal;
    QPushButton *btn_RIOMDebug;
    QPushButton *btn_RIOMDetailInfo;
    QPushButton *btn_Back;
    QPushButton *btn_PublishSet;
    QPushButton *btn_versionInfo;
    QPushButton *btn_DataMoniter;

    void setupUi(QWidget *DebugPage)
    {
        if (DebugPage->objectName().isEmpty())
            DebugPage->setObjectName(QString::fromUtf8("DebugPage"));
        DebugPage->resize(1024, 768);
        DebugPage->setStyleSheet(QString::fromUtf8("\n"
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
        btn_LifeSignal = new QPushButton(DebugPage);
        btn_LifeSignal->setObjectName(QString::fromUtf8("btn_LifeSignal"));
        btn_LifeSignal->setGeometry(QRect(220, 100, 150, 40));
        btn_RIOMDebug = new QPushButton(DebugPage);
        btn_RIOMDebug->setObjectName(QString::fromUtf8("btn_RIOMDebug"));
        btn_RIOMDebug->setGeometry(QRect(410, 100, 150, 40));
        btn_RIOMDetailInfo = new QPushButton(DebugPage);
        btn_RIOMDetailInfo->setObjectName(QString::fromUtf8("btn_RIOMDetailInfo"));
        btn_RIOMDetailInfo->setGeometry(QRect(600, 100, 150, 40));
        btn_Back = new QPushButton(DebugPage);
        btn_Back->setObjectName(QString::fromUtf8("btn_Back"));
        btn_Back->setGeometry(QRect(830, 320, 100, 40));
        btn_PublishSet = new QPushButton(DebugPage);
        btn_PublishSet->setObjectName(QString::fromUtf8("btn_PublishSet"));
        btn_PublishSet->setGeometry(QRect(790, 100, 150, 40));
        btn_versionInfo = new QPushButton(DebugPage);
        btn_versionInfo->setObjectName(QString::fromUtf8("btn_versionInfo"));
        btn_versionInfo->setGeometry(QRect(30, 100, 150, 40));
        btn_DataMoniter = new QPushButton(DebugPage);
        btn_DataMoniter->setObjectName(QString::fromUtf8("btn_DataMoniter"));
        btn_DataMoniter->setGeometry(QRect(30, 190, 150, 40));

        retranslateUi(DebugPage);

        QMetaObject::connectSlotsByName(DebugPage);
    } // setupUi

    void retranslateUi(QWidget *DebugPage)
    {
        DebugPage->setWindowTitle(QApplication::translate("DebugPage", "Form", 0, QApplication::UnicodeUTF8));
        btn_LifeSignal->setText(QApplication::translate("DebugPage", "\347\224\237\345\221\275\344\277\241\345\217\267", 0, QApplication::UnicodeUTF8));
        btn_RIOMDebug->setText(QApplication::translate("DebugPage", "RIOM\350\260\203\350\257\225", 0, QApplication::UnicodeUTF8));
        btn_RIOMDetailInfo->setText(QApplication::translate("DebugPage", "RIOM\350\257\246\347\273\206\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        btn_Back->setText(QApplication::translate("DebugPage", "\350\277\224 \345\233\236", 0, QApplication::UnicodeUTF8));
        btn_PublishSet->setText(QApplication::translate("DebugPage", "\345\207\272\345\216\202\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        btn_versionInfo->setText(QApplication::translate("DebugPage", "\347\211\210\346\234\254\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        btn_DataMoniter->setText(QApplication::translate("DebugPage", "\346\225\260\346\215\256\347\233\221\346\216\247", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DebugPage: public Ui_DebugPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEBUGPAGE_H
