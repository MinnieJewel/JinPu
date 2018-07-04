#ifndef SIVTESTPAGE_H
#define SIVTESTPAGE_H

#include "mybase.h"

class VehicleLogo;
class QLabel;
namespace Ui {
    class SIVTestPage;
}

class SIVTestPage : public MyBase
{
    Q_OBJECT

public:
    explicit SIVTestPage(QWidget *parent = 0);
    ~SIVTestPage();
    void getState(QLabel *label, bool state);
    void updatePage();

private:
    Ui::SIVTestPage *ui;
    VehicleLogo *vehicleLogo;
};

#endif // SIVTESTPAGE_H
