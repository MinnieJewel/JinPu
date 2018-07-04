#ifndef TRACTIONHELPPAGE_H
#define TRACTIONHELPPAGE_H

#include "mybase.h"

namespace Ui {
    class TractionHelpPage;
}

class TractionHelpPage : public MyBase
{
    Q_OBJECT

public:
    explicit TractionHelpPage(QWidget *parent = 0);
    ~TractionHelpPage();

private:
    Ui::TractionHelpPage *ui;

private slots:
    void on_btn_nextPage_clicked();
    void on_btn_back_clicked();
};

#endif // TRACTIONHELPPAGE_H
