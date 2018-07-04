#ifndef OTHERCHANNELSPAGE_H
#define OTHERCHANNELSPAGE_H

#include "mybase.h"

namespace Ui {
    class OtherChannelsPage;
}

class QLabel;
class VehicleLogo;

class OtherChannelsPage : public MyBase
{
    Q_OBJECT

public:
    explicit OtherChannelsPage(QWidget *parent = 0);
    ~OtherChannelsPage();

    void updatePage();
    void brakeNoRemission(QLabel *label, bool remission);
    void parkBrake(QLabel *label, bool parkBrake);
    void doorSafe(QLabel *label, bool safe);
    void alert(QLabel *label, bool alert);
    void ATPCutOff(QLabel *label, bool cutoff);

private:
    Ui::OtherChannelsPage *ui;
    VehicleLogo *vehicleLogo;

private slots:
    void on_btn_EmergencyBroadcast_clicked();
};

#endif // OTHERCHANNELSPAGE_H
