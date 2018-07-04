#ifndef AIRCONDITIONERPAGE_H
#define AIRCONDITIONERPAGE_H

#include "mybase.h"

class QLabel;
class QPushButton;
class QTimer;
class QButtonGroup;
class VehicleLogo;
namespace Ui {
    class AirConditionerPage;
}

class AirConditionerPage : public MyBase
{
    Q_OBJECT

public:
    explicit AirConditionerPage(QWidget *parent = 0);
    ~AirConditionerPage();

    void updatePage();
    void setControlState(QLabel *label, bool onState, QString controlState);
    void getTemperature(QLabel *label, QString temperature);
    void getEquipmentState(QLabel *label, bool equipState, bool equipFault);
    void modeSet(int);
    void disableSetTemp(bool ifAutoMode);
    void setFlag(int vehicleNo);
    void setModeFlag(int mode);
    void displayModeState();
    void setLimits();
    void newWindSet(int id);
    void displayNewWindState();
    void saveSpeedState(bool state);
    void setControlMode(QLabel *label, bool onState, bool controlState);
private:
    Ui::AirConditionerPage *ui;
    unsigned short int temp;
    QButtonGroup *vehicleButtons;
    QButtonGroup *modeButtons;
    QButtonGroup *newWindButtons;
    QButtonGroup *windSpd;

    //0:autoHeat 1:autoCold
    bool autoMode;
    unsigned short int currentMode, currentWind, currentWindSpd;
    QTimer *timerMode, *timerTemp, *timerWind;
    int currentVehicle;

    //cold mode configurable
    bool coldForbidden;
    VehicleLogo *vehicleLogo;
private slots:
    void on_btn_EmergencyBroadcast_clicked();
    void selectVehicle(int);
    void selectMode(int);
    void selectWind(int);
    void on_btn_confirm_clicked();
    void on_btn_add_clicked();
    void on_btn_reduse_clicked();
    void setSpeedState(int state);

    void resetFlag();
    void resetTempFlag();
    void resetWindFlag();

};

#endif // AIRCONDITIONERPAGE_H
