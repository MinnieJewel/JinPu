#ifndef VEHICLELOGO_H
#define VEHICLELOGO_H

#include <QWidget>

namespace Ui {
    class VehicleLogo;
}
class QLabel;
class VehicleLogo : public QWidget
{
    Q_OBJECT

public:
    explicit VehicleLogo(QWidget *parent = 0);
    ~VehicleLogo();
    void updateVehicleState(bool tc1Active, bool tc2Active, bool forward, bool backward,
                            bool riom3OnLine, bool riom4OnLine, bool up1, bool down1, bool up2, bool down2, bool doorAllClose);
    void updatePanState(QLabel *label, bool riomOnLine, bool up, bool down);
    void updateVehicleNo(QString lineNo, QString vehicleNo);
    void updateHSCB(bool hscb1, bool hscb2);
private:
    Ui::VehicleLogo *ui;

};

#endif // VEHICLELOGO_H
