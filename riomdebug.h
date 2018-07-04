#ifndef RIOMDEBUG_H
#define RIOMDEBUG_H

#include <QWidget>
#include <QTableWidget>
#include "mybase.h"
#include "vehiclelogo.h"

namespace Ui {
    class RIOMDebug;
}

class RIOMDebug : public MyBase
{
    Q_OBJECT

public:
    explicit RIOMDebug(QWidget *parent = 0);
    ~RIOMDebug();
    void setTableSize();
    void updatePage();
    void RLDState(QLabel *label, bool state);

private:
    Ui::RIOMDebug *ui;
     VehicleLogo *vehicleLogo;
    QTableWidget *RIOMDebugTable;


private slots:
    void on_btn_back_clicked();
};

#endif // RIOMDEBUG_H
