#ifndef REPAIRPAGE_H
#define REPAIRPAGE_H

#include <QWidget>

namespace Ui {
    class RepairPage;
}

class RepairPage : public QWidget
{
    Q_OBJECT

public:
    explicit RepairPage(QWidget *parent = 0);
    ~RepairPage();

private:
    Ui::RepairPage *ui;
};

#endif // REPAIRPAGE_H
