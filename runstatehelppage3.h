#ifndef RUNSTATEHELPPAGE3_H
#define RUNSTATEHELPPAGE3_H

#include "mybase.h"

namespace Ui {
    class RunstateHelpPage3;
}

class RunstateHelpPage3 : public MyBase
{
    Q_OBJECT

public:
    explicit RunstateHelpPage3(QWidget *parent = 0);
    ~RunstateHelpPage3();

    void updatePage();
private:
    Ui::RunstateHelpPage3 *ui;

private slots:
    void on_btn_nextPage_clicked();
    void on_btn_prePage_clicked();
    void on_btn_back_clicked();
};

#endif // RUNSTATEHELPPAGE3_H
