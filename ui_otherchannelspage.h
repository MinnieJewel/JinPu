/********************************************************************************
** Form generated from reading UI file 'otherchannelspage.ui'
**
** Created: Thu Jan 11 11:16:18 2018
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OTHERCHANNELSPAGE_H
#define UI_OTHERCHANNELSPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OtherChannelsPage
{
public:
    QLabel *label_emeByPass1;
    QLabel *label_emeByPass2;
    QLabel *label_emeByPass3;
    QLabel *label_ATPCutOff;
    QLabel *label_car1DoorSafe;
    QLabel *label_car1No;
    QLabel *label_car2ParkBrake;
    QLabel *label_car4No;
    QLabel *label_emeByPass;
    QLabel *label_car1ParkBrake;
    QLabel *label_car4BrakeNoRemission;
    QLabel *label_vehicleNo;
    QLabel *label_car3No;
    QLabel *label_car2ATPCutOff;
    QLabel *label_car2DoorSafe;
    QLabel *label_emeByPass4;
    QLabel *label_car3DoorSafe;
    QLabel *label_car3ATPCutOff;
    QLabel *label_car1BrakeNoRemission;
    QLabel *label_car2BrakeNoRemission;
    QLabel *label_car4DoorSafe;
    QLabel *label_car3ParkBrake;
    QLabel *label_car2No;
    QLabel *label_car1ATPCutOff;
    QLabel *label_brakeNoRemission;
    QLabel *label_car4ParkBrake;
    QLabel *label_car4ATPCutOff;
    QLabel *label_car3BrakeNoRemission;
    QLabel *label_parkBrake;
    QLabel *label_doorSafe;
    QPushButton *btn_EmergencyBroadcast;

    void setupUi(QWidget *OtherChannelsPage)
    {
        if (OtherChannelsPage->objectName().isEmpty())
            OtherChannelsPage->setObjectName(QString::fromUtf8("OtherChannelsPage"));
        OtherChannelsPage->resize(1024, 618);
        OtherChannelsPage->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	color: white;\n"
"	border: 2px groove, gray;\n"
"    border-color: gray;\n"
"	font: 17px, \"SimHei\";	\n"
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
        label_emeByPass1 = new QLabel(OtherChannelsPage);
        label_emeByPass1->setObjectName(QString::fromUtf8("label_emeByPass1"));
        label_emeByPass1->setGeometry(QRect(159, 259, 190, 40));
        label_emeByPass1->setAlignment(Qt::AlignCenter);
        label_emeByPass2 = new QLabel(OtherChannelsPage);
        label_emeByPass2->setObjectName(QString::fromUtf8("label_emeByPass2"));
        label_emeByPass2->setGeometry(QRect(347, 259, 210, 40));
        label_emeByPass2->setAlignment(Qt::AlignCenter);
        label_emeByPass3 = new QLabel(OtherChannelsPage);
        label_emeByPass3->setObjectName(QString::fromUtf8("label_emeByPass3"));
        label_emeByPass3->setGeometry(QRect(556, 259, 210, 40));
        label_emeByPass3->setAlignment(Qt::AlignCenter);
        label_ATPCutOff = new QLabel(OtherChannelsPage);
        label_ATPCutOff->setObjectName(QString::fromUtf8("label_ATPCutOff"));
        label_ATPCutOff->setGeometry(QRect(30, 298, 130, 40));
        label_car1DoorSafe = new QLabel(OtherChannelsPage);
        label_car1DoorSafe->setObjectName(QString::fromUtf8("label_car1DoorSafe"));
        label_car1DoorSafe->setGeometry(QRect(159, 220, 190, 40));
        label_car1DoorSafe->setAlignment(Qt::AlignCenter);
        label_car1No = new QLabel(OtherChannelsPage);
        label_car1No->setObjectName(QString::fromUtf8("label_car1No"));
        label_car1No->setGeometry(QRect(159, 103, 190, 40));
        label_car1No->setScaledContents(false);
        label_car1No->setAlignment(Qt::AlignCenter);
        label_car2ParkBrake = new QLabel(OtherChannelsPage);
        label_car2ParkBrake->setObjectName(QString::fromUtf8("label_car2ParkBrake"));
        label_car2ParkBrake->setGeometry(QRect(347, 181, 210, 40));
        label_car2ParkBrake->setAlignment(Qt::AlignCenter);
        label_car4No = new QLabel(OtherChannelsPage);
        label_car4No->setObjectName(QString::fromUtf8("label_car4No"));
        label_car4No->setGeometry(QRect(763, 103, 180, 40));
        label_car4No->setAlignment(Qt::AlignCenter);
        label_emeByPass = new QLabel(OtherChannelsPage);
        label_emeByPass->setObjectName(QString::fromUtf8("label_emeByPass"));
        label_emeByPass->setGeometry(QRect(30, 259, 130, 40));
        label_car1ParkBrake = new QLabel(OtherChannelsPage);
        label_car1ParkBrake->setObjectName(QString::fromUtf8("label_car1ParkBrake"));
        label_car1ParkBrake->setGeometry(QRect(159, 181, 190, 40));
        label_car1ParkBrake->setAlignment(Qt::AlignCenter);
        label_car4BrakeNoRemission = new QLabel(OtherChannelsPage);
        label_car4BrakeNoRemission->setObjectName(QString::fromUtf8("label_car4BrakeNoRemission"));
        label_car4BrakeNoRemission->setGeometry(QRect(763, 142, 180, 40));
        label_car4BrakeNoRemission->setAlignment(Qt::AlignCenter);
        label_vehicleNo = new QLabel(OtherChannelsPage);
        label_vehicleNo->setObjectName(QString::fromUtf8("label_vehicleNo"));
        label_vehicleNo->setGeometry(QRect(30, 103, 130, 40));
        label_car3No = new QLabel(OtherChannelsPage);
        label_car3No->setObjectName(QString::fromUtf8("label_car3No"));
        label_car3No->setGeometry(QRect(556, 103, 210, 40));
        label_car3No->setAlignment(Qt::AlignCenter);
        label_car2ATPCutOff = new QLabel(OtherChannelsPage);
        label_car2ATPCutOff->setObjectName(QString::fromUtf8("label_car2ATPCutOff"));
        label_car2ATPCutOff->setGeometry(QRect(347, 298, 210, 40));
        label_car2ATPCutOff->setAlignment(Qt::AlignCenter);
        label_car2DoorSafe = new QLabel(OtherChannelsPage);
        label_car2DoorSafe->setObjectName(QString::fromUtf8("label_car2DoorSafe"));
        label_car2DoorSafe->setGeometry(QRect(347, 220, 210, 40));
        label_car2DoorSafe->setAlignment(Qt::AlignCenter);
        label_emeByPass4 = new QLabel(OtherChannelsPage);
        label_emeByPass4->setObjectName(QString::fromUtf8("label_emeByPass4"));
        label_emeByPass4->setGeometry(QRect(763, 259, 180, 40));
        label_emeByPass4->setAlignment(Qt::AlignCenter);
        label_car3DoorSafe = new QLabel(OtherChannelsPage);
        label_car3DoorSafe->setObjectName(QString::fromUtf8("label_car3DoorSafe"));
        label_car3DoorSafe->setGeometry(QRect(556, 220, 210, 40));
        label_car3DoorSafe->setAlignment(Qt::AlignCenter);
        label_car3ATPCutOff = new QLabel(OtherChannelsPage);
        label_car3ATPCutOff->setObjectName(QString::fromUtf8("label_car3ATPCutOff"));
        label_car3ATPCutOff->setGeometry(QRect(556, 298, 210, 40));
        label_car3ATPCutOff->setAlignment(Qt::AlignCenter);
        label_car1BrakeNoRemission = new QLabel(OtherChannelsPage);
        label_car1BrakeNoRemission->setObjectName(QString::fromUtf8("label_car1BrakeNoRemission"));
        label_car1BrakeNoRemission->setGeometry(QRect(159, 142, 190, 40));
        label_car1BrakeNoRemission->setAlignment(Qt::AlignCenter);
        label_car2BrakeNoRemission = new QLabel(OtherChannelsPage);
        label_car2BrakeNoRemission->setObjectName(QString::fromUtf8("label_car2BrakeNoRemission"));
        label_car2BrakeNoRemission->setGeometry(QRect(347, 142, 210, 40));
        label_car2BrakeNoRemission->setAlignment(Qt::AlignCenter);
        label_car4DoorSafe = new QLabel(OtherChannelsPage);
        label_car4DoorSafe->setObjectName(QString::fromUtf8("label_car4DoorSafe"));
        label_car4DoorSafe->setGeometry(QRect(763, 220, 180, 40));
        label_car4DoorSafe->setAlignment(Qt::AlignCenter);
        label_car3ParkBrake = new QLabel(OtherChannelsPage);
        label_car3ParkBrake->setObjectName(QString::fromUtf8("label_car3ParkBrake"));
        label_car3ParkBrake->setGeometry(QRect(556, 181, 210, 40));
        label_car3ParkBrake->setAlignment(Qt::AlignCenter);
        label_car2No = new QLabel(OtherChannelsPage);
        label_car2No->setObjectName(QString::fromUtf8("label_car2No"));
        label_car2No->setGeometry(QRect(347, 103, 210, 40));
        label_car2No->setAlignment(Qt::AlignCenter);
        label_car1ATPCutOff = new QLabel(OtherChannelsPage);
        label_car1ATPCutOff->setObjectName(QString::fromUtf8("label_car1ATPCutOff"));
        label_car1ATPCutOff->setGeometry(QRect(159, 298, 190, 40));
        label_car1ATPCutOff->setAlignment(Qt::AlignCenter);
        label_brakeNoRemission = new QLabel(OtherChannelsPage);
        label_brakeNoRemission->setObjectName(QString::fromUtf8("label_brakeNoRemission"));
        label_brakeNoRemission->setGeometry(QRect(30, 142, 130, 40));
        label_car4ParkBrake = new QLabel(OtherChannelsPage);
        label_car4ParkBrake->setObjectName(QString::fromUtf8("label_car4ParkBrake"));
        label_car4ParkBrake->setGeometry(QRect(763, 181, 180, 40));
        label_car4ParkBrake->setAlignment(Qt::AlignCenter);
        label_car4ATPCutOff = new QLabel(OtherChannelsPage);
        label_car4ATPCutOff->setObjectName(QString::fromUtf8("label_car4ATPCutOff"));
        label_car4ATPCutOff->setGeometry(QRect(763, 298, 180, 40));
        label_car4ATPCutOff->setAlignment(Qt::AlignCenter);
        label_car3BrakeNoRemission = new QLabel(OtherChannelsPage);
        label_car3BrakeNoRemission->setObjectName(QString::fromUtf8("label_car3BrakeNoRemission"));
        label_car3BrakeNoRemission->setGeometry(QRect(556, 142, 210, 40));
        label_car3BrakeNoRemission->setAlignment(Qt::AlignCenter);
        label_parkBrake = new QLabel(OtherChannelsPage);
        label_parkBrake->setObjectName(QString::fromUtf8("label_parkBrake"));
        label_parkBrake->setGeometry(QRect(30, 181, 130, 40));
        label_doorSafe = new QLabel(OtherChannelsPage);
        label_doorSafe->setObjectName(QString::fromUtf8("label_doorSafe"));
        label_doorSafe->setGeometry(QRect(30, 220, 130, 40));
        btn_EmergencyBroadcast = new QPushButton(OtherChannelsPage);
        btn_EmergencyBroadcast->setObjectName(QString::fromUtf8("btn_EmergencyBroadcast"));
        btn_EmergencyBroadcast->setGeometry(QRect(860, 560, 130, 40));

        retranslateUi(OtherChannelsPage);

        QMetaObject::connectSlotsByName(OtherChannelsPage);
    } // setupUi

    void retranslateUi(QWidget *OtherChannelsPage)
    {
        OtherChannelsPage->setWindowTitle(QApplication::translate("OtherChannelsPage", "Form", 0, QApplication::UnicodeUTF8));
        label_emeByPass1->setText(QString());
        label_emeByPass2->setText(QApplication::translate("OtherChannelsPage", "--", 0, QApplication::UnicodeUTF8));
        label_emeByPass3->setText(QApplication::translate("OtherChannelsPage", "--", 0, QApplication::UnicodeUTF8));
        label_ATPCutOff->setText(QApplication::translate("OtherChannelsPage", "ATP\345\210\207\351\231\244", 0, QApplication::UnicodeUTF8));
        label_car1DoorSafe->setText(QString());
        label_car1No->setText(QApplication::translate("OtherChannelsPage", "1", 0, QApplication::UnicodeUTF8));
        label_car2ParkBrake->setText(QApplication::translate("OtherChannelsPage", "--", 0, QApplication::UnicodeUTF8));
        label_car4No->setText(QApplication::translate("OtherChannelsPage", "4", 0, QApplication::UnicodeUTF8));
        label_emeByPass->setText(QApplication::translate("OtherChannelsPage", "\347\264\247\346\200\245\345\210\266\345\212\250\346\227\201\350\267\257", 0, QApplication::UnicodeUTF8));
        label_car1ParkBrake->setText(QString());
        label_car4BrakeNoRemission->setText(QString());
        label_vehicleNo->setText(QApplication::translate("OtherChannelsPage", "\350\275\246\345\217\267", 0, QApplication::UnicodeUTF8));
        label_car3No->setText(QApplication::translate("OtherChannelsPage", "3", 0, QApplication::UnicodeUTF8));
        label_car2ATPCutOff->setText(QApplication::translate("OtherChannelsPage", "--", 0, QApplication::UnicodeUTF8));
        label_car2DoorSafe->setText(QApplication::translate("OtherChannelsPage", "--", 0, QApplication::UnicodeUTF8));
        label_emeByPass4->setText(QString());
        label_car3DoorSafe->setText(QApplication::translate("OtherChannelsPage", "--", 0, QApplication::UnicodeUTF8));
        label_car3ATPCutOff->setText(QApplication::translate("OtherChannelsPage", "--", 0, QApplication::UnicodeUTF8));
        label_car1BrakeNoRemission->setText(QString());
        label_car2BrakeNoRemission->setText(QApplication::translate("OtherChannelsPage", "--", 0, QApplication::UnicodeUTF8));
        label_car4DoorSafe->setText(QString());
        label_car3ParkBrake->setText(QApplication::translate("OtherChannelsPage", "--", 0, QApplication::UnicodeUTF8));
        label_car2No->setText(QApplication::translate("OtherChannelsPage", "2", 0, QApplication::UnicodeUTF8));
        label_car1ATPCutOff->setText(QString());
        label_brakeNoRemission->setText(QApplication::translate("OtherChannelsPage", "\345\210\266\345\212\250\344\270\215\347\274\223\350\247\243\346\227\201\350\267\257", 0, QApplication::UnicodeUTF8));
        label_car4ParkBrake->setText(QString());
        label_car4ATPCutOff->setText(QString());
        label_car3BrakeNoRemission->setText(QApplication::translate("OtherChannelsPage", "--", 0, QApplication::UnicodeUTF8));
        label_parkBrake->setText(QApplication::translate("OtherChannelsPage", "\345\201\234\346\224\276\345\210\266\345\212\250\346\227\201\350\267\257", 0, QApplication::UnicodeUTF8));
        label_doorSafe->setText(QApplication::translate("OtherChannelsPage", "\351\227\250\345\256\211\345\205\250\347\272\277\346\227\201\350\267\257", 0, QApplication::UnicodeUTF8));
        btn_EmergencyBroadcast->setText(QApplication::translate("OtherChannelsPage", "\347\264\247\346\200\245\345\271\277\346\222\255", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class OtherChannelsPage: public Ui_OtherChannelsPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OTHERCHANNELSPAGE_H
