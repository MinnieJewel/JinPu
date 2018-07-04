#ifndef BATTERYPAGE_H
#define BATTERYPAGE_H

#include "mybase.h"

namespace Ui {
    class BatteryPage;
}

class QLabel;
class VehicleLogo;

class BatteryPage : public MyBase
{
    Q_OBJECT

public:
    explicit BatteryPage(QWidget *parent = 0);
    ~BatteryPage();
    void updatePage();
    void chargeVoltage(QLabel *label, unsigned short int chargeVoltage);
    void dischargeVoltage(QLabel *label, unsigned short int dischargeVoltage);
    void boxTemperature(QLabel *label, unsigned short int temperature);
    void chargeCurrent(QLabel *label, unsigned short int chargeCurrent);
    void dischargeCurrent(QLabel *label, unsigned short int dischargeCurrent);
    void overVolBattery(QLabel *label, unsigned char overVolBatteryNum);
    void lowVolBattery(QLabel *label, unsigned char lowVolBatteryNum);
    void overTempBattery(QLabel *label, unsigned char overBatteryNum);
    void overResBattery(QLabel *label, unsigned char overResBatteryNum);
    void alertState(QLabel *label, unsigned char state);
    void alertValue(QLabel *label, unsigned short int value);

private:
    Ui::BatteryPage *ui;
    VehicleLogo *vehicleLogo;

private slots:
    void on_btn_EmergencyBroadcast_clicked();
};

#endif // BATTERYPAGE_H
