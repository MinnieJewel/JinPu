#ifndef FIREALERTPAGE_H
#define FIREALERTPAGE_H

#include "mybase.h"

namespace Ui {
    class FireAlertPage;
}

class QLabel;
class QTimer;
class VehicleLogo;
class FireAlertPage : public MyBase
{
    Q_OBJECT

public:
    explicit FireAlertPage(QWidget *parent = 0);
    ~FireAlertPage();
    void updatePage();
    int detectorFault(bool online, bool det1FireAlert, bool det1CommAlert, bool det1AirAlert, bool det1PollAlert, bool det2FireAlert, bool det2CommAlert, bool det2AirAlert, bool det2PollAlert);
    void setFireAlert(QLabel *label, int state);


private:
    Ui::FireAlertPage *ui;
    VehicleLogo *vehicleLogo;
    QTimer *timer;

private slots:
    void on_btn_EmergencyBroadcast_clicked();
    void on_btn_reset_clicked();
    void on_btn_quiet_clicked();
    void resetFlag();
};

#endif // FIREALERTPAGE_H

