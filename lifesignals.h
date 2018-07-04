#ifndef LIFESIGNALS_H
#define LIFESIGNALS_H

#include <QWidget>
#include <QTableWidget>
#include "mybase.h"
#include "vehiclelogo.h"
namespace Ui {
    class LifeSignals;
}

class LifeSignals : public MyBase
{
    Q_OBJECT

public:
    explicit LifeSignals(QWidget *parent = 0);
    ~LifeSignals();
    void updatePage();

private:
    Ui::LifeSignals *ui;
    VehicleLogo *vehicleLogo;
    QTableWidget *lifeSignalsTable;
    unsigned short int hmi1Lfsign, hmi2Lfsign;

private slots:
    void on_btn_back_clicked();
};

#endif // LIFESIGNALS_H
