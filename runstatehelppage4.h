#ifndef RUNSTATEHELPPAGE4_H
#define RUNSTATEHELPPAGE4_H

#include "mybase.h"

namespace Ui {
    class RunstateHelpPage4;
}

class RunstateHelpPage4 : public MyBase
{
    Q_OBJECT

public:
    explicit RunstateHelpPage4(QWidget *parent = 0);
    ~RunstateHelpPage4();

    void updatePage();

private:
    Ui::RunstateHelpPage4 *ui;

private slots:
    void on_btn_prePage_clicked();
    void on_btn_back_clicked();
};

#endif // RUNSTATEHELPPAGE4_H
