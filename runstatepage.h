#ifndef RUNSTATEPAGE_H
#define RUNSTATEPAGE_H

#include "mybase.h"


namespace Ui {
    class RunStatePage;
}
class VehicleLogo;
class QLabel;

class RunStatePage : public MyBase
{
    Q_OBJECT

public:
    explicit RunStatePage(QWidget *parent = 0);
    ~RunStatePage();

    void updatePage();
    void setAssistantState(QLabel *label, bool onState, bool stopState, bool faultState, bool runState, int outputVoltage);
    void setExtentPower(QLabel *label, bool valid);
    void setTractionState(QLabel *label, bool onState, bool cutOffState, bool faultState, int current);
    void setBrakeState(QLabel *label, bool onState, bool emergencyState, bool keepState, bool airState, bool stayState);
    void getTemperature(QLabel *label, bool onState, QString temperature);
    void getOuterTemperature(QLabel *label, bool onState, int temperature);
    void getAPAbnormal(QLabel *label, bool abnormal);
    void getPreStart(QLabel *label, bool start);
    void getOverLoad(QLabel *label, bool overLoad);
    void getRun(QLabel *label, bool run);
    //void getBrakePressure(QLabel *label, signed short int pressureValue);
    void setWashMode(QLabel *label, bool washMode);
    bool setAirBrakeState(bool release, bool apply);
    bool setParkBrakeState(bool release, bool apply);
    void setDoorState(QLabel *label, bool onLine, bool cut, bool seriousFault, bool slightFault, bool emergencyUnlock, bool obstacle, bool notInPlace, bool open, bool close, bool lock);
    bool getOnLineState();
    void setRidingRate(QLabel *label, QString rate);
   private:
    Ui::RunStatePage *ui;
    bool faultState1,faultState2,faultState3,faultState4;
    VehicleLogo *vehicleLogo;
    QList<bool> tractionStates;
    //QList<bool> airBrakeState;
    //QList<bool> airBrakeStateError;
    //bool currentAirBrakeState;
    bool airBrake1, airBrake2, airBrake3, airBrake4, airBrake5, airBrake6, airBrake7, airBrake8;
    bool parkBrake1, parkBrake2, parkBrake3, parkBrake4;

private slots:
    void on_btn_EmergencyBroadcast_clicked();
};

#endif // RUNSTATEPAGE_H
