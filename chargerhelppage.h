#ifndef CHARGERHELPPAGE_H
#define CHARGERHELPPAGE_H

#include "mybase.h"

namespace Ui {
    class ChargerHelpPage;
}

class ChargerHelpPage : public MyBase
{
    Q_OBJECT

public:
    explicit ChargerHelpPage(QWidget *parent = 0);
    ~ChargerHelpPage();

private:
    Ui::ChargerHelpPage *ui;

private slots:
    void on_btn_back_clicked();
};

#endif // CHARGERHELPPAGE_H
