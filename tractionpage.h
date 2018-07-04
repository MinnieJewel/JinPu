#ifndef TRACTIONPAGE_H
#define TRACTIONPAGE_H

#include "mybase.h"

class QLabel;
class VehicleLogo;
namespace Ui {
    class TractionPage;
}

class TractionPage : public MyBase
{
    Q_OBJECT

public:
    explicit TractionPage(QWidget *parent = 0);
    ~TractionPage();
    void updatePage();
    void setTractionState(QLabel *label, bool onState, bool cutOffState, bool faultState);
    void setTractionAllowed(QLabel *label, bool tractionAllowed);
    void setHSCB(QLabel *label, bool onState, bool HSCBState);
    void setAllBrakeReleased(QLabel *label, bool allBrakeReleased);
    void setEBState(QLabel *label, bool EBEffect, bool EBAvailable, bool EBSlide, bool EBDecrease, bool EBCut);
    void setEBEffect(QLabel *label, unsigned short int EBEffect);
    void setSafetyBrake(QLabel *label, bool safetyBrake);
    void setLineCurr(QLabel *label, unsigned int lineCurr);
    void setInverterCurr(QLabel *label, unsigned int inverterCurr);
    void setContector(QLabel *label, bool contectorState);
    void setChargeContector(QLabel *label, bool chargeContectorState);
    void setIsolateState(QLabel *label, bool isolateState);

private:
    Ui::TractionPage *ui;
    VehicleLogo *vehicleLogo;
    QList<bool> tractionStates;

private slots:
    void on_btn_EmergencyBroadcast_clicked();
};

#endif // TRACTIONPAGE_H
