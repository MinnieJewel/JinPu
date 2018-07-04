#ifndef BRAKESTATEPAGE_H
#define BRAKESTATEPAGE_H

#include "mybase.h"
class QLabel;
class VehicleLogo;
namespace Ui {
    class BrakeStatePage;
}

class BrakeStatePage : public MyBase
{
    Q_OBJECT

public:
    explicit BrakeStatePage(QWidget *parent = 0);
    ~BrakeStatePage();

    void updatePage();
    void electBrakeCutOff(QLabel *label, bool cutOff);
    void getAxleSpeed(QLabel *label, signed short int speed1, signed short int speed2, signed short int speed3, signed short int speed4);
    void getMainReservoirPress(QLabel *label, signed short int press);
    void getAirReedPress(QLabel *label, signed short int  ASP);
    void getZeroSpeed(QLabel *label, bool zeroSpeed);
    void getAxleSlid(QLabel *label, bool slid);
    void getLoad(QLabel *label, signed short int load);
    void getBCP(QLabel *label, signed short int pressure);
    void getEmergencyBrake(QLabel *label, bool active, bool available);
    void getAirBrake(QLabel *label, bool release, bool apply);
    void getKeepBrake(QLabel *label, bool keep);
    void setParkBrakeState(QLabel *label, bool release, bool apply);

private:
    Ui::BrakeStatePage *ui;
    VehicleLogo *vehicleLogo;
    bool airBrake1, airBrake2, airBrake3, airBrake4,
    airBrake5, airBrake6, airBrake7, airBrake8;
    bool parkBrake1, parkBrake2, parkBrake3, parkBrake4;

private slots:
    void on_btn_EmergencyBroadcast_clicked();
};

#endif // BRAKESTATEPAGE_H
