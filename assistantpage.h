#ifndef ASSISTANTPAGE_H
#define ASSISTANTPAGE_H

#include "mybase.h"

namespace Ui {
    class AssistantPage;
}
class QLabel;
class QTimer;
class VehicleLogo;

class AssistantPage : public MyBase
{
    Q_OBJECT

public:
    explicit AssistantPage(QWidget *parent = 0);
    ~AssistantPage();

    void updatePage();
    void getAssistantState(QLabel *label, bool onState, bool fault, bool stop, bool run, QString carNo);
    void getSIVInputVoltage(QLabel *label, bool onState, unsigned short int voltage);
    void getSIVOutputVoltage(QLabel *label, bool onState, unsigned short int  voltage);
    void getSIVOutputRate(QLabel *label, bool onState, unsigned short int rate);
    void getSIVOutputCurrent(QLabel *label, bool onState, unsigned short int current);
    void getLineVoltage(QLabel *label, bool onState, unsigned short int voltage);
    void getExtendEnable(QLabel *label, bool onState, bool enable);
    void getDropPantStop(QLabel *label, bool onState, bool stop);

private:
    Ui::AssistantPage *ui;
    VehicleLogo *vehicleLogo;
    QTimer *timer;

private slots:
    void on_btn_EmergencyBroadcast_clicked();
    void on_pushButton_clicked();
    void resetFlag();
    void on_btn_reset1_clicked();
    void on_btn_reset2_clicked();
    void setToggleButton1(bool);
    void setToggleButton2(bool);
};

#endif // ASSISTANTPAGE_H
