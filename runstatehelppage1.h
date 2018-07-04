#ifndef RUNSTATEHELPPAGE1_H
#define RUNSTATEHELPPAGE1_H

#include "mybase.h"

namespace Ui {
    class RunstateHelpPage1;
}

class RunstateHelpPage1 : public MyBase
{
    Q_OBJECT

public:
    explicit RunstateHelpPage1(QWidget *parent = 0);
    ~RunstateHelpPage1();

    void updatePage();

private:
    Ui::RunstateHelpPage1 *ui;

private slots:
    void on_btn_back_clicked();
    void on_btn_nextPage_clicked();
};

#endif // RUNSTATEHELPPAGE1_H
