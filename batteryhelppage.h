#ifndef BATTERYHELPPAGE_H
#define BATTERYHELPPAGE_H

#include "mybase.h"

namespace Ui {
    class BatteryHelpPage;
}

class BatteryHelpPage : public MyBase
{
    Q_OBJECT

public:
    explicit BatteryHelpPage(QWidget *parent = 0);
    ~BatteryHelpPage();

private:
    Ui::BatteryHelpPage *ui;

private slots:
    void on_btn_back_clicked();
};

#endif // BATTERYHELPPAGE_H
