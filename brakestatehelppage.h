#ifndef BRAKESTATEHELPPAGE_H
#define BRAKESTATEHELPPAGE_H

#include "mybase.h"

namespace Ui {
    class BrakestateHelpPage;
}

class BrakestateHelpPage : public MyBase
{
    Q_OBJECT

public:
    explicit BrakestateHelpPage(QWidget *parent = 0);
    ~BrakestateHelpPage();

private:
    Ui::BrakestateHelpPage *ui;

private slots:
    void on_btn_back_clicked();
};

#endif // BRAKESTATEHELPPAGE_H
