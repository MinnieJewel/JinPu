#ifndef PANEL_H
#define PANEL_H

#include <QWidget>

namespace Ui {
    class Panel;
}

class Panel : public QWidget
{
    Q_OBJECT

public:
    explicit Panel(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    void setCurrentSpeed(double speed);
    ~Panel();

private:
    Ui::Panel *ui;
    QPainter* pPainter;
    double currentSpeed;
};

#endif // PANEL_H
