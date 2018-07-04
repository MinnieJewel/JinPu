/********************************************************************************
** Form generated from reading UI file 'repairpage.ui'
**
** Created: Thu Jan 11 11:16:18 2018
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPAIRPAGE_H
#define UI_REPAIRPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RepairPage
{
public:

    void setupUi(QWidget *RepairPage)
    {
        if (RepairPage->objectName().isEmpty())
            RepairPage->setObjectName(QString::fromUtf8("RepairPage"));
        RepairPage->resize(400, 300);

        retranslateUi(RepairPage);

        QMetaObject::connectSlotsByName(RepairPage);
    } // setupUi

    void retranslateUi(QWidget *RepairPage)
    {
        RepairPage->setWindowTitle(QApplication::translate("RepairPage", "Form", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class RepairPage: public Ui_RepairPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPAIRPAGE_H
