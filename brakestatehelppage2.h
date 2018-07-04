#ifndef BRAKESTATEHELPPAGE2_H
#define BRAKESTATEHELPPAGE2_H

#include "mybase.h"

namespace Ui {
    class BrakestateHelpPage2;
}

class BrakestateHelpPage2 : public MyBase
{
    Q_OBJECT

public:
    explicit BrakestateHelpPage2(QWidget *parent = 0);
    ~BrakestateHelpPage2();

private:
    Ui::BrakestateHelpPage2 *ui;
};

#endif // BRAKESTATEHELPPAGE2_H
