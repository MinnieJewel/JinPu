#ifndef CHARGERPAGE_H
#define CHARGERPAGE_H

#include "mybase.h"

namespace Ui {
    class ChargerPage;
}

class QLabel;
class QTimer;
class VehicleLogo;

class ChargerPage : public MyBase
{
    Q_OBJECT

public:
    explicit ChargerPage(QWidget *parent = 0);
    ~ChargerPage();

    void updatePage();
    void chargeState(QLabel *label, bool onLine, bool fault);
    void chargeTemperature(QLabel *label, unsigned short int temperature);
    void chargeVoltage(QLabel *label, unsigned short int voltage);
    void chargeCurrent(QLabel *label, unsigned short int current);
    void netVoltage(QLabel *label, unsigned short int netVoltage);
    void supportVoltage(QLabel *label, unsigned short int supportVoltage);
    void netCurrent(QLabel *label, unsigned short int netCurrent);

private:
    Ui::ChargerPage *ui;
    VehicleLogo *vehicleLogo;
    QTimer *timer;

private slots:

    void on_btn_EmergencyBroadcast_clicked();
    void on_btn_reset2_clicked();
    void on_btn_reset1_clicked();
    void resetFlag();
    void setToggleButton1(bool);
    void setToggleButton2(bool);
};

#endif // CHARGERPAGE_H
