#ifndef EMERGENCYBROADCAST_H
#define EMERGENCYBROADCAST_H

#include "mybase.h"

namespace Ui {
    class EmergencyBroadcast;
}
class QButtonGroup;
class QTimer;
class EmergencyBroadcast : public MyBase
{
    Q_OBJECT

public:
    explicit EmergencyBroadcast(QWidget *parent = 0);
    ~EmergencyBroadcast();
    void setBroadcastCode(int code);
    void setButtonStyle(int);

private:
    Ui::EmergencyBroadcast *ui;
    int broadcastCode;
    void sendBroadcastCode(int code);
    QButtonGroup *broadCastButtons;
    QTimer *timer, *broadcastStopTimer;

private slots:
    void on_btn_cease_clicked();
    void on_btn_Back_clicked();
    void setEmergencyBroadcastCode(int);
    void resetHmiBroadcastCommand();
    void setBroadcastStopCommand();
};

#endif // EMERGENCYBROADCAST_H
