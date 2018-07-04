#ifndef TRACTIONHELPPAGE2_H
#define TRACTIONHELPPAGE2_H

#include "mybase.h"

namespace Ui {
    class TractionHelpPage2;
}

class TractionHelpPage2 : public MyBase
{
    Q_OBJECT

public:
    explicit TractionHelpPage2(QWidget *parent = 0);
    ~TractionHelpPage2();

private:
    Ui::TractionHelpPage2 *ui;

private slots:
    void on_btn_prePage_clicked();
    void on_btn_back_clicked();
};

#endif // TRACTIONHELPPAGE2_H
