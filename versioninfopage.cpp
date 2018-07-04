#include "versioninfopage.h"
#include "ui_versioninfopage.h"
#include <QDebug>
#include "global.h"
#include "vehiclelogo.h"

VersionInfoPage::VersionInfoPage(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::VersionInfoPage)
{
    ui->setupUi(this);
    _LOG << "VersionInfoPage constructor";
//    this->vehicleLogo = new VehicleLogo(this);
//    this->vehicleLogo->setGeometry(0, 10, this->vehicleLogo->width(), this->vehicleLogo->height());
}

VersionInfoPage::~VersionInfoPage()
{
    delete ui;
}

void VersionInfoPage::getCCUVersion(QLabel *label, QString softVersion, QString MVBVersion, QString SDBVersion, QString VxWorksVersion)
{
    QString temp = "soft:";
    temp += softVersion;

    temp += "  MVB:";
    temp += MVBVersion;

    temp += "  SDB:";
    temp += SDBVersion;

    temp += "  VXW:";
    temp += VxWorksVersion;

    label->setText(temp);
}


void VersionInfoPage::getBCUVersion(QLabel *label, QString CB01, QString soft, QString EB01)
{
    QString temp = "CB01:";
    temp += CB01;

    temp += " soft:";
    temp += soft;

    temp += " EB01:";
    temp += EB01;

    label->setText(temp);
}

void VersionInfoPage::updatePage()
{
//    this->vehicleLogo->updateVehicleState(this->database->CTHM_TC1Active, this->database->CTHM_TC2Active, this->database->CTHM_Forward, this->database->CTHM_Backward,
//    this->database->CTHM_Mp1RIOMGWOn, this->database->CTHM_Mp2RIOMGWOn, this->database->RIOM3_DIM1Ch18, this->database->RIOM3_DIM1Ch19, this->database->RIOM4_DIM1Ch18,
//    this->database->RIOM4_DIM1Ch19, this->database->DICT_Tc1DI1I15AllDoorClosed_A1 | this->database->DICT_Tc2DI1I15AllDoorClosed_A2);

    ui->label_HMI1->setText(this->database->hmiVersionA1);
    ui->label_HMI4->setText(this->database->hmiVersionA2);
    this->getCCUVersion(ui->label_CCU1, this->database->ccu1OsVersion, this->database->ccu1MvbVersion, this->database->ccu1SdbVersion, this->database->ccu1VxWorksVersion);
    this->getCCUVersion(ui->label_CCU2, this->database->ccu2OsVersion, this->database->ccu2MvbVersion, this->database->ccu2SdbVersion, this->database->ccu2VxWorksVersion);
    ui->label_ERM1->setText(this->database->erm1OsVersion);
    ui->label_ERM2->setText(this->database->erm2OsVersion);
    ui->label_GW1->setText(this->database->gwVersionTc1);
    ui->label_GW2->setText(this->database->gwVersionMp1);
    ui->label_GW3->setText(this->database->gwVersionMp2);
    ui->label_GW4->setText(this->database->gwVersionTc2);
    ui->label_DI1->setText(this->database->diVersionTc1);
    ui->label_DI2->setText(this->database->diVersionMp1);
    ui->label_DI3->setText(this->database->diVersionMp2);
    ui->label_DI4->setText(this->database->diVersionTc2);
    ui->label_DO1->setText(this->database->doVersionTc1);
    ui->label_DO2->setText(this->database->doVersionMp1);
    ui->label_DO3->setText(this->database->doVersionMp2);
    ui->label_DO4->setText(this->database->doVersionTc2);
    ui->label_AX1->setText(this->database->axVersionTc1);
    ui->label_AX4->setText(this->database->axVersionTc2);
    ui->label_SIV1->setText(this->database->siv1Version);
    ui->label_SIV4->setText(this->database->siv2Version);
    ui->label_SIVGW1->setText("GW: " + this->database->sivGW1Version);
    ui->label_SIVGW4->setText("GW: " + this->database->sivGW2version);

    ui->label_car2DCUGW->setText("GW: "+ this->database->dcuGwVersionMp1);
    ui->label_car3DCUGW->setText("GW: " + this->database->dcuGwVersionMp2);
    ui->label_car2DCU1->setText(this->database->dcu1VersionMp1);
    ui->label_car2DCU2->setText(this->database->dcu2VersionMp1);
    ui->label_car2DCU3->setText(this->database->dcu3VersionMp1);
    ui->label_car2DCU4->setText(this->database->dcu4VersionMp1);
    ui->label_car3DCU1->setText(this->database->dcu1VersionMp2);
    ui->label_car3DCU2->setText(this->database->dcu2VersionMp2);
    ui->label_car3DCU3->setText(this->database->dcu3VersionMp2);
    ui->label_car3DCU4->setText(this->database->dcu4VersionMp2);

    ui->label_HVAC1->setText(this->database->hvacVersionTc1);
    ui->label_HVAC2->setText(this->database->hvacVersionMp1);
    ui->label_HVAC3->setText(this->database->hvacVersionMp2);
    ui->label_HVAC4->setText(this->database->hvacVersionTc2);

    ui->label_car1Door1_1->setText(this->database->car1Door1Version);
    //_LOG << "door1 version: " << this->database->hmiEDCU1_D1Version;

    ui->label_car1Door1_2->setText(this->database->car1Door2Version);
    ui->label_car1Door1_3->setText(this->database->car1Door3Version);
    ui->label_car1Door1_4->setText(this->database->car1Door4Version);
    ui->label_car1Door2_1->setText(this->database->car1Door5Version);
    ui->label_car1Door2_2->setText(this->database->car1Door6Version);
    ui->label_car1Door2_3->setText(this->database->car1Door7Version);
    ui->label_car1Door2_4->setText(this->database->car1Door8Version);

    ui->label_car2Door1_1->setText(this->database->car3Door1Version);
    ui->label_car2Door1_2->setText(this->database->car3Door2Version);
    ui->label_car2Door1_3->setText(this->database->car3Door3Version);
    ui->label_car2Door1_4->setText(this->database->car3Door4Version);
    ui->label_car2Door2_1->setText(this->database->car3Door5Version);
    ui->label_car2Door2_2->setText(this->database->car3Door6Version);
    ui->label_car2Door2_3->setText(this->database->car3Door7Version);
    ui->label_car2Door2_4->setText(this->database->car3Door8Version);

    ui->label_car3Door1_1->setText(this->database->car4Door1Version);
    ui->label_car3Door1_2->setText(this->database->car4Door2Version);
    ui->label_car3Door1_3->setText(this->database->car4Door3Version);
    ui->label_car3Door1_4->setText(this->database->car4Door4Version);
    ui->label_car3Door2_1->setText(this->database->car4Door5Version);
    ui->label_car3Door2_2->setText(this->database->car4Door6Version);
    ui->label_car3Door2_3->setText(this->database->car4Door7Version);
    ui->label_car3Door2_4->setText(this->database->car4Door8Version);

    ui->label_car4Door1_1->setText(this->database->car6Door1Version);
    ui->label_car4Door1_2->setText(this->database->car6Door2Version);
    ui->label_car4Door1_3->setText(this->database->car6Door3Version);
    ui->label_car4Door1_4->setText(this->database->car6Door4Version);
    ui->label_car4Door2_1->setText(this->database->car6Door5Version);
    ui->label_car4Door2_2->setText(this->database->car6Door6Version);
    ui->label_car4Door2_3->setText(this->database->car6Door7Version);
    ui->label_car4Door2_4->setText(this->database->car6Door8Version);

    ui->label_PIS1->setText(this->database->pisVersion1);
    ui->label_PIS4->setText(this->database->pisVersion2);
    ui->label_FAU1->setText(this->database->fauVersion1);
    ui->label_FAU4->setText(this->database->fauVersion2);

    ui->label_BCG1->setText(this->database->bcgVersion1);
    ui->label_BCG4->setText(this->database->bcgVersion2);

    ui->label_BMS1->setText(this->database->bmsVersion1);
    ui->label_BMS4->setText(this->database->bmsVersion2);

    this->getBCUVersion(ui->label_BCU1, this->database->bcuCB01Version1, this->database->bcuMVBVersion1, this->database->bcuEB01Version1);
    this->getBCUVersion(ui->label_BCU2, this->database->bcuCB01Version2, this->database->bcuMVBVersion2, this->database->bcuEB01Version2);
}

void VersionInfoPage::on_btn_back_clicked()
{
    emit this->changePage(uDebugPage);
}
