/********************************************************************************
** Form generated from reading UI file 'headerinner.ui'
**
** Created: Thu Jan 11 11:16:18 2018
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HEADERINNER_H
#define UI_HEADERINNER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFormLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HeaderInner
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label1;
    QLabel *labelName;
    QLabel *labelTime;

    void setupUi(QWidget *HeaderInner)
    {
        if (HeaderInner->objectName().isEmpty())
            HeaderInner->setObjectName(QString::fromUtf8("HeaderInner"));
        HeaderInner->resize(1024, 60);
        HeaderInner->setStyleSheet(QString::fromUtf8("QLabel\n"
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
        formLayoutWidget = new QWidget(HeaderInner);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(340, 270, 160, 80));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label1 = new QLabel(HeaderInner);
        label1->setObjectName(QString::fromUtf8("label1"));
        label1->setGeometry(QRect(0, 0, 3115, 60));
        labelName = new QLabel(HeaderInner);
        labelName->setObjectName(QString::fromUtf8("labelName"));
        labelName->setGeometry(QRect(312, 0, 3115, 60));
        labelTime = new QLabel(HeaderInner);
        labelTime->setObjectName(QString::fromUtf8("labelTime"));
        labelTime->setGeometry(QRect(624, 0, 400, 60));

        retranslateUi(HeaderInner);

        QMetaObject::connectSlotsByName(HeaderInner);
    } // setupUi

    void retranslateUi(QWidget *HeaderInner)
    {
        HeaderInner->setWindowTitle(QApplication::translate("HeaderInner", "Form", 0, QApplication::UnicodeUTF8));
        label1->setText(QString());
        labelName->setText(QString());
        labelTime->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class HeaderInner: public Ui_HeaderInner {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HEADERINNER_H
