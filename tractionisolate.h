#ifndef TRACTIONISOLATE_H
#define TRACTIONISOLATE_H

#include "mybase.h"
class QButtonGroup;

namespace Ui {
    class TractionIsolate;
}

class TractionIsolate : public MyBase
{
    Q_OBJECT

public:
    explicit TractionIsolate(QWidget *parent = 0);
    ~TractionIsolate();

private:
    Ui::TractionIsolate *ui;
    QButtonGroup *buttonGroup;
    bool buttonState[8];
    void changeButtonStyle(int id, bool clicked);

private slots:
    void on_btn_back_clicked();
    void buttonOnClicked(int buttonId);
};

#endif // TRACTIONISOLATE_H
