#ifndef NETWORK_H
#define NETWORK_H

#include <QWidget>
#include "mybase.h"

class VehicleLogo;
class QTimer;
class QLabel;
class QVector<QLabel>;
class CrrcFault;

namespace Ui {
    class NetWork;
}

class QLabel;

class NetWork : public MyBase
{
    Q_OBJECT

public:
    explicit NetWork(QWidget *parent = 0);
    ~NetWork();
    void showEvent(QShowEvent *event);
    void updatePage();
    void paintEvent(QPaintEvent *);
    void installCrrcFault(CrrcFault *crrcFault);

private:
    Ui::NetWork *ui;
    VehicleLogo *vehicleLogo;
    CrrcFault *crrcFault;
    void setDeviceState(QLabel *label, bool state, bool faultState);
    void setDeviceStateMaster(QLabel *label, bool state, bool master, bool faultState);
    QVector<QLabel *>labels;
};

#endif // NETWORK_H
