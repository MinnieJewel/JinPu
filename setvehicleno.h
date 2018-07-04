#ifndef SETVEHICLENO_H
#define SETVEHICLENO_H

#include <QWidget>
#include "mybase.h"

class QButtonGroup;
class QTimer;
namespace Ui {
    class SetVehicleNo;
}

class SetVehicleNo : public MyBase
{
    Q_OBJECT

public:
    explicit SetVehicleNo(QWidget *parent = 0);
    ~SetVehicleNo();

private:
    Ui::SetVehicleNo *ui;
    bool ifSetVehicleNo;
    QButtonGroup *buttonGroup;
    QString vehicleNo;
    QString lineNo;
    QTimer *timer;

private slots:
    void on_btn_back_clicked();
    void on_btn_confirm_clicked();
    void on_btn_lineNo_clicked();
    void on_btn_vehicleNo_clicked();
    void setSelectedButton(bool);
    void setCurrentNo(int);
    void resetHmiSetWheelDiaCommand();
};

#endif // SETVEHICLENO_H
