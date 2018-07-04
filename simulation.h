#ifndef SIMULATION_H
#define SIMULATION_H

#include "mybase.h"

namespace Ui {
    class Simulation;
}

class Simulation : public MyBase
{
    Q_OBJECT

public:
    explicit Simulation(QWidget *parent = 0);
    ~Simulation();

private:
    Ui::Simulation *ui;
	 void setMessage(QString message);

private slots:
    void on_ON_TOP_clicked();
    void on_btnConfirm_clicked();
    void on_btnClose_clicked();
};

#endif // SIMULATION_H
