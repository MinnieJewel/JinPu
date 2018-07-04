#ifndef RUNSTATEHELPPAGE2_H
#define RUNSTATEHELPPAGE2_H

#include "mybase.h"

namespace Ui {
    class RunstateHelpPage2;
}

class RunstateHelpPage2 : public MyBase
{
    Q_OBJECT

public:
    explicit RunstateHelpPage2(QWidget *parent = 0);
    ~RunstateHelpPage2();

    void updatePage();

private:
    Ui::RunstateHelpPage2 *ui;

private slots:
    void on_btn_prePage_clicked();
    void on_btn_nextPage_clicked();
    void on_btn_back_clicked();
};

#endif // RUNSTATEHELPPAGE2_H
