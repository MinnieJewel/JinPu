#include "firealertpage.h"
#include "ui_firealertpage.h"
#include "vehiclelogo.h"
#include <QDebug>
#include "global.h"
#include <QTimer>
#include <QLabel>

#define _OFFLINE ("background-color:white;")
#define _TRANSFAULT ("border-image: url(:/image/fireAlarmOffLine.png);")
#define _ALARM ("border-image: url(:/image/fireAlarmWarning.png);")
#define _FAULT ("border-image: url(:/image/fireAlarmError.png);")
#define _RUN ("border-image: url(:/image/fireAlarmOk.png);")

enum alarmState{
    offLine = 0,
    transFault,
    fireAlarm,
    fault,
    run
};

FireAlertPage::FireAlertPage(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::FireAlertPage)
{
    ui->setupUi(this);
     _LOG << "FireAlertPage constructor";
    this->vehicleLogo = new VehicleLogo(this);
    this->vehicleLogo->setGeometry(0, 10, this->vehicleLogo->width(), this->vehicleLogo->height());
    ui->label_transFailed->hide();
    this->timer = new QTimer;
    this->timer->stop();
    connect(this->timer, SIGNAL(timeout()), this, SLOT(resetFlag()));
}

FireAlertPage::~FireAlertPage()
{
    delete ui;
}

void FireAlertPage::updatePage()
{
    this->vehicleLogo->updateVehicleState(this->database->CTHM_TC1Active, this->database->CTHM_TC2Active, this->database->CTHM_Forward, this->database->CTHM_Backward,
    this->database->CTHM_Mp1RIOMGWOn, this->database->CTHM_Mp2RIOMGWOn, this->database->RIOM3_DIM1Ch18, this->database->RIOM3_DIM1Ch19, this->database->RIOM4_DIM1Ch18,
    this->database->RIOM4_DIM1Ch19, this->database->DICT_Tc1DI1I15AllDoorClosed_A1 | this->database->DICT_Tc2DI1I15AllDoorClosed_A2);
    this->vehicleLogo->updateVehicleNo(this->database->lineNo, this->database->vehicleNo);
    this->vehicleLogo->updateHSCB(this->database->TR3CT_HSCBState, this->database->TR4CT_HSCBState);
    //parameters to record current detector states

    int tc1Alert1 = this->detectorFault(this->database->CTHM_FAU1On || this->database->CTHM_FAU2On, this->database->FA1CT_Det11FireAlert, this->database->FA1CT_Det11ComFault,
                                         this->database->FA1CT_Det11FanFault, this->database->FA1CT_Det11Polluted,
                                         this->database->FA2CT_Det11FireAlert, this->database->FA2CT_Det11ComFault,
                                         this->database->FA2CT_Det11FanFault, this->database->FA2CT_Det11Polluted);

    int tc1Alert2 = this->detectorFault(this->database->CTHM_FAU1On || this->database->CTHM_FAU2On, this->database->FA1CT_Det12FireAlert, this->database->FA1CT_Det12ComFault,
                                         this->database->FA1CT_Det12FanFault, this->database->FA1CT_Det12Polluted,
                                         this->database->FA2CT_Det12FireAlert, this->database->FA2CT_Det12ComFault,
                                         this->database->FA2CT_Det12FanFault, this->database->FA2CT_Det12Polluted);

    int tc1Alert3 = this->detectorFault(this->database->CTHM_FAU1On || this->database->CTHM_FAU2On, this->database->FA1CT_Det13FireAlert, this->database->FA1CT_Det13ComFault,
                                         this->database->FA1CT_Det13FanFault, this->database->FA1CT_Det13Polluted,
                                         this->database->FA2CT_Det13FireAlert, this->database->FA2CT_Det13ComFault,
                                         this->database->FA2CT_Det13FanFault, this->database->FA2CT_Det13Polluted);

    int tc1Alert4 = this->detectorFault(this->database->CTHM_FAU1On || this->database->CTHM_FAU2On, this->database->FA1CT_Det14FireAlert, this->database->FA1CT_Det14ComFault,
                                         this->database->FA1CT_Det14FanFault, this->database->FA1CT_Det14Polluted,
                                         this->database->FA2CT_Det14FireAlert, this->database->FA2CT_Det14ComFault,
                                         this->database->FA2CT_Det14FanFault, this->database->FA2CT_Det14Polluted);

    int tc1Alert5 = this->detectorFault(this->database->CTHM_FAU1On || this->database->CTHM_FAU2On, this->database->FA1CT_Det15FireAlert, this->database->FA1CT_Det15ComFault,
                                         this->database->FA1CT_Det15FanFault, this->database->FA1CT_Det15Polluted,
                                         this->database->FA2CT_Det15FireAlert, this->database->FA2CT_Det15ComFault,
                                         this->database->FA2CT_Det15FanFault, this->database->FA2CT_Det15Polluted);

    int tc1Alert6 = this->detectorFault(this->database->CTHM_FAU1On || this->database->CTHM_FAU2On, this->database->FA1CT_Det16FireAlert, this->database->FA1CT_Det16ComFault,
                                         this->database->FA1CT_Det16FanFault, this->database->FA1CT_Det16Polluted,
                                         this->database->FA2CT_Det16FireAlert, this->database->FA2CT_Det16ComFault,
                                         this->database->FA2CT_Det16FanFault, this->database->FA2CT_Det16Polluted);

    int tc1Alert7 = this->detectorFault(this->database->CTHM_FAU1On || this->database->CTHM_FAU2On, this->database->FA1CT_Det17FireAlert, this->database->FA1CT_Det17ComFault,
                                         this->database->FA1CT_Det17FanFault, this->database->FA1CT_Det17Polluted,
                                         this->database->FA2CT_Det17FireAlert, this->database->FA2CT_Det17ComFault,
                                         this->database->FA2CT_Det17FanFault, this->database->FA2CT_Det17Polluted);

    int tc2Alert1 = this->detectorFault(this->database->CTHM_FAU1On || this->database->CTHM_FAU2On, this->database->FA1CT_Det61FireAlert, this->database->FA1CT_Det61ComFault,
                                         this->database->FA1CT_Det61FanFault, this->database->FA1CT_Det61Polluted,
                                         this->database->FA2CT_Det61FireAlert, this->database->FA2CT_Det61ComFault,
                                         this->database->FA2CT_Det61FanFault, this->database->FA2CT_Det61Polluted);

    int tc2Alert2 = this->detectorFault(this->database->CTHM_FAU1On || this->database->CTHM_FAU2On, this->database->FA1CT_Det62FireAlert, this->database->FA1CT_Det62ComFault,
                                         this->database->FA1CT_Det62FanFault, this->database->FA1CT_Det62Polluted,
                                         this->database->FA2CT_Det62FireAlert, this->database->FA2CT_Det62ComFault,
                                         this->database->FA2CT_Det62FanFault, this->database->FA2CT_Det62Polluted);

    int tc2Alert3 = this->detectorFault(this->database->CTHM_FAU1On || this->database->CTHM_FAU2On, this->database->FA1CT_Det63FireAlert, this->database->FA1CT_Det63ComFault,
                                         this->database->FA1CT_Det63FanFault, this->database->FA1CT_Det63Polluted,
                                         this->database->FA2CT_Det63FireAlert, this->database->FA2CT_Det63ComFault,
                                         this->database->FA2CT_Det63FanFault, this->database->FA2CT_Det63Polluted);

    int tc2Alert4 = this->detectorFault(this->database->CTHM_FAU1On || this->database->CTHM_FAU2On, this->database->FA1CT_Det64FireAlert, this->database->FA1CT_Det64ComFault,
                                         this->database->FA1CT_Det64FanFault, this->database->FA1CT_Det64Polluted,
                                         this->database->FA2CT_Det64FireAlert, this->database->FA2CT_Det64ComFault,
                                         this->database->FA2CT_Det64FanFault, this->database->FA2CT_Det64Polluted);

    int tc2Alert5 = this->detectorFault(this->database->CTHM_FAU1On || this->database->CTHM_FAU2On, this->database->FA1CT_Det65FireAlert, this->database->FA1CT_Det65ComFault,
                                         this->database->FA1CT_Det65FanFault, this->database->FA1CT_Det65Polluted,
                                         this->database->FA2CT_Det65FireAlert, this->database->FA2CT_Det65ComFault,
                                         this->database->FA2CT_Det65FanFault, this->database->FA2CT_Det65Polluted);

    int tc2Alert6 = this->detectorFault(this->database->CTHM_FAU1On || this->database->CTHM_FAU2On, this->database->FA1CT_Det66FireAlert, this->database->FA1CT_Det66ComFault,
                                         this->database->FA1CT_Det66FanFault, this->database->FA1CT_Det66Polluted,
                                         this->database->FA2CT_Det66FireAlert, this->database->FA2CT_Det66ComFault,
                                         this->database->FA2CT_Det66FanFault, this->database->FA2CT_Det66Polluted);

    int tc2Alert7 = this->detectorFault(this->database->CTHM_FAU1On || this->database->CTHM_FAU2On, this->database->FA1CT_Det67FireAlert, this->database->FA1CT_Det67ComFault,
                                         this->database->FA1CT_Det67FanFault, this->database->FA1CT_Det67Polluted,
                                         this->database->FA2CT_Det67FireAlert, this->database->FA2CT_Det67ComFault,
                                         this->database->FA2CT_Det67FanFault, this->database->FA2CT_Det67Polluted);


    int mp1Alert1 = this->detectorFault(this->database->CTHM_FAU1On || this->database->CTHM_FAU2On, this->database->FA1CT_Det31FireAlert, this->database->FA1CT_Det31ComFault,
                                         this->database->FA1CT_Det31FanFault, this->database->FA1CT_Det31Polluted,
                                         this->database->FA2CT_Det31FireAlert, this->database->FA2CT_Det31ComFault,
                                         this->database->FA2CT_Det31FanFault, this->database->FA2CT_Det31Polluted);

    int mp1Alert2 = this->detectorFault(this->database->CTHM_FAU1On || this->database->CTHM_FAU2On, this->database->FA1CT_Det32FireAlert, this->database->FA1CT_Det32ComFault,
                                         this->database->FA1CT_Det32FanFault, this->database->FA1CT_Det32Polluted,
                                         this->database->FA2CT_Det32FireAlert, this->database->FA2CT_Det32ComFault,
                                         this->database->FA2CT_Det32FanFault, this->database->FA2CT_Det32Polluted);

    int mp1Alert3 = this->detectorFault(this->database->CTHM_FAU1On || this->database->CTHM_FAU2On, this->database->FA1CT_Det33FireAlert, this->database->FA1CT_Det33ComFault,
                                         this->database->FA1CT_Det33FanFault, this->database->FA1CT_Det33Polluted,
                                         this->database->FA2CT_Det33FireAlert, this->database->FA2CT_Det33ComFault,
                                         this->database->FA2CT_Det33FanFault, this->database->FA2CT_Det33Polluted);

    int mp1Alert4 = this->detectorFault(this->database->CTHM_FAU1On || this->database->CTHM_FAU2On, this->database->FA1CT_Det34FireAlert, this->database->FA1CT_Det34ComFault,
                                         this->database->FA1CT_Det34FanFault, this->database->FA1CT_Det34Polluted,
                                         this->database->FA2CT_Det34FireAlert, this->database->FA2CT_Det34ComFault,
                                         this->database->FA2CT_Det34FanFault, this->database->FA2CT_Det34Polluted);

    int mp2Alert1 = this->detectorFault(this->database->CTHM_FAU1On || this->database->CTHM_FAU2On, this->database->FA1CT_Det41FireAlert, this->database->FA1CT_Det41ComFault,
                                         this->database->FA1CT_Det41FanFault, this->database->FA1CT_Det41Polluted,
                                         this->database->FA2CT_Det41FireAlert, this->database->FA2CT_Det41ComFault,
                                         this->database->FA2CT_Det41FanFault, this->database->FA2CT_Det41Polluted);

    int mp2Alert2 = this->detectorFault(this->database->CTHM_FAU1On || this->database->CTHM_FAU2On, this->database->FA1CT_Det42FireAlert, this->database->FA1CT_Det42ComFault,
                                         this->database->FA1CT_Det42FanFault, this->database->FA1CT_Det42Polluted,
                                         this->database->FA2CT_Det42FireAlert, this->database->FA2CT_Det42ComFault,
                                         this->database->FA2CT_Det42FanFault, this->database->FA2CT_Det42Polluted);

    int mp2Alert3 = this->detectorFault(this->database->CTHM_FAU1On || this->database->CTHM_FAU2On, this->database->FA1CT_Det43FireAlert, this->database->FA1CT_Det43ComFault,
                                         this->database->FA1CT_Det43FanFault, this->database->FA1CT_Det43Polluted,
                                         this->database->FA2CT_Det43FireAlert, this->database->FA2CT_Det43ComFault,
                                         this->database->FA2CT_Det43FanFault, this->database->FA2CT_Det43Polluted);

    int mp2Alert4 = this->detectorFault(this->database->CTHM_FAU1On || this->database->CTHM_FAU2On, this->database->FA1CT_Det44FireAlert, this->database->FA1CT_Det44ComFault,
                                         this->database->FA1CT_Det44FanFault, this->database->FA1CT_Det44Polluted,
                                         this->database->FA2CT_Det44FireAlert, this->database->FA2CT_Det44ComFault,
                                         this->database->FA2CT_Det44FanFault, this->database->FA2CT_Det44Polluted);


    this->setFireAlert(ui->carA1_T1, tc1Alert1);
    this->setFireAlert(ui->carA1_T2, tc1Alert2);
    this->setFireAlert(ui->carA1_T3, tc1Alert3);
    this->setFireAlert(ui->carA1_T4, tc1Alert4);
    this->setFireAlert(ui->carA1_T5, tc1Alert5);
    this->setFireAlert(ui->carA1_T6, tc1Alert6);
    this->setFireAlert(ui->carA1_T7, tc1Alert7);
    this->setFireAlert(ui->carB1_1, mp1Alert1);
    this->setFireAlert(ui->carB1_2, mp1Alert2);
    this->setFireAlert(ui->carB1_3, mp1Alert3);
    this->setFireAlert(ui->carB1_4, mp1Alert4);
    this->setFireAlert(ui->carB2_1, mp2Alert1);
    this->setFireAlert(ui->carB2_2, mp2Alert2);
    this->setFireAlert(ui->carB2_3, mp2Alert3);
    this->setFireAlert(ui->carB2_4, mp2Alert4);
    this->setFireAlert(ui->carA2_T1, tc2Alert1);
    this->setFireAlert(ui->carA2_T2, tc2Alert2);
    this->setFireAlert(ui->carA2_T3, tc2Alert3);
    this->setFireAlert(ui->carA2_T4, tc2Alert4);
    this->setFireAlert(ui->carA2_T5, tc2Alert5);
    this->setFireAlert(ui->carA2_T6, tc2Alert6);
    this->setFireAlert(ui->carA2_T7, tc2Alert7);

    int fireAlertButtonStateTc1 = this->database->FA1CT_Det11FireAlert || this->database->FA2CT_Det11FireAlert
                                || this->database->FA1CT_Det12FireAlert || this->database->FA2CT_Det12FireAlert
                                || this->database->FA1CT_Det13FireAlert || this->database->FA2CT_Det13FireAlert
                                || this->database->FA1CT_Det14FireAlert || this->database->FA2CT_Det14FireAlert
                                || this->database->FA1CT_Det15FireAlert || this->database->FA2CT_Det15FireAlert
                                || this->database->FA1CT_Det16FireAlert || this->database->FA2CT_Det16FireAlert
                                || this->database->FA1CT_Det17FireAlert || this->database->FA2CT_Det17FireAlert;

    int fireAlertButtionStateTc2 = this->database->FA1CT_Det61FireAlert || this->database->FA2CT_Det61FireAlert
                                  || this->database->FA1CT_Det62FireAlert || this->database->FA2CT_Det62FireAlert
                                  || this->database->FA1CT_Det63FireAlert || this->database->FA2CT_Det63FireAlert
                                  || this->database->FA1CT_Det64FireAlert || this->database->FA2CT_Det64FireAlert
                                  || this->database->FA1CT_Det65FireAlert || this->database->FA2CT_Det65FireAlert
                                  || this->database->FA1CT_Det66FireAlert || this->database->FA2CT_Det66FireAlert
                                  || this->database->FA1CT_Det67FireAlert || this->database->FA2CT_Det67FireAlert;

    int fireAlertButtonStateMp1 = this->database->FA1CT_Det31FireAlert || this->database->FA2CT_Det31FireAlert
                                  || this->database->FA1CT_Det32FireAlert || this->database->FA2CT_Det32FireAlert
                                  || this->database->FA1CT_Det33FireAlert || this->database->FA2CT_Det33FireAlert
                                  || this->database->FA1CT_Det34FireAlert || this->database->FA2CT_Det34FireAlert;

    int fireAlertButtonStateMp2 = this->database->FA1CT_Det41FireAlert || this->database->FA2CT_Det41FireAlert
                                  || this->database->FA1CT_Det42FireAlert || this->database->FA2CT_Det42FireAlert
                                  || this->database->FA1CT_Det43FireAlert || this->database->FA2CT_Det43FireAlert
                                  || this->database->FA1CT_Det44FireAlert || this->database->FA2CT_Det44FireAlert;


    if(fireAlertButtonStateTc1 || fireAlertButtionStateTc2 || fireAlertButtonStateMp1 || fireAlertButtonStateMp2)
    {
        this->database->setFireButtonState(true);
    }
    else
    {
         this->database->setFireButtonState(false);
    }


    if(this->database->FA1CT_FAComFault || this->database->FA2CT_FAComFault)
    {
        ui->label_transFailed->show();
    }
    else
    {
        ui->label_transFailed->hide();
    }
}

int FireAlertPage::detectorFault(bool online, bool det1FireAlert, bool det1CommAlert, bool det1AirAlert, bool det1PollAlert, bool det2FireAlert, bool det2CommAlert, bool det2AirAlert, bool det2PollAlert)
{
   // _LOG << "online:" << online;
    if(!online)
        return offLine;
    else if(det1CommAlert || det2CommAlert)
        return  transFault;
    else if (det1FireAlert || det2FireAlert)
        return fireAlarm;
    else if (det1AirAlert || det1PollAlert || det2AirAlert || det2PollAlert)
        return fault;
    else
        return run;
}


void FireAlertPage::setFireAlert(QLabel *label, int state)
{
    //_LOG << "state:" << state;
    if (offLine == state)
        label->setStyleSheet(_OFFLINE);
    else if (transFault == state)
        label->setStyleSheet(_TRANSFAULT);
    else if (fireAlarm == state)
        label->setStyleSheet(_ALARM);
    else if (fault == state)
        label->setStyleSheet(_FAULT);
    else if (run == state)
        label->setStyleSheet(_RUN);
}



void FireAlertPage::on_btn_quiet_clicked()
{
    this->database->hmiMuteFau = true;
    this->database->flagChecker = 0xAA;
    this->timer->start(5000);
    ui->btn_quiet->setEnabled(false);
}

void FireAlertPage::on_btn_reset_clicked()
{
    this->database->hmiResetFau = true;
    this->database->flagChecker = 0xAA;
    this->timer->start(5000);
    ui->btn_reset->setEnabled(false);
}

void FireAlertPage::resetFlag()
{
    this->database->flagChecker = 0x55;
    this->database->hmiMuteFau = false;
    this->database->hmiResetFau = false;
    ui->btn_quiet->setEnabled(true);
    ui->btn_reset->setEnabled(true);
    this->timer->stop();
}

void FireAlertPage::on_btn_EmergencyBroadcast_clicked()
{
    emit this->changePage(uEmergencyBroadcast);
}
