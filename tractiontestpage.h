#ifndef TRACTIONTESTPAGE_H
#define TRACTIONTESTPAGE_H

#include "mybase.h"

namespace Ui {
    class TractionTestPage;
}

class VehicleLogo;
class QLabel;
class TractionTestPage : public MyBase
{
    Q_OBJECT

public:
    explicit TractionTestPage(QWidget *parent = 0);
    ~TractionTestPage();

    void updatePage();
    void testState(QLabel *label, bool state);

private:
    Ui::TractionTestPage *ui;
    VehicleLogo *vehicleLogo;

private slots:
    void on_btn_back_clicked();
};

#endif // TRACTIONTESTPAGE_H
