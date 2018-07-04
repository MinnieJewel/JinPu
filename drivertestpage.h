#ifndef DRIVERTESTPAGE_H
#define DRIVERTESTPAGE_H

#include "mybase.h"

namespace Ui {
    class DriverTestPage;
}

class QLabel;
class VehicleLogo;

class DriverTestPage : public MyBase
{
    Q_OBJECT

public:
    explicit DriverTestPage(QWidget *parent = 0);
    ~DriverTestPage();
    void setState(QLabel *label, bool state);
    void updatePage();
    VehicleLogo *vehicleLogo;

private:
    Ui::DriverTestPage *ui;
    QString perBrFrc;

private slots:
    void on_btn_back_clicked();
};

#endif // DRIVERTESTPAGE_H
