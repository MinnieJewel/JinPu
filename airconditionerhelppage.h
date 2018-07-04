#ifndef AIRCONDITIONERHELPPAGE_H
#define AIRCONDITIONERHELPPAGE_H

#include "mybase.h"

namespace Ui {
    class AirConditionerHelpPage;
}

class AirConditionerHelpPage : public MyBase
{
    Q_OBJECT

public:
    explicit AirConditionerHelpPage(QWidget *parent = 0);
    ~AirConditionerHelpPage();

private:
    Ui::AirConditionerHelpPage *ui;

private slots:
    void on_btn_back_clicked();
};

#endif // AIRCONDITIONERHELPPAGE_H
