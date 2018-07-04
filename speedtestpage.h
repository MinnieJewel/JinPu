#ifndef SPEEDTESTPAGE_H
#define SPEEDTESTPAGE_H

#include <QWidget>
#include "mybase.h"

class QTableWidget;
namespace Ui {
    class SpeedTestPage;
}

class SpeedTestPage : public MyBase
{
    Q_OBJECT

public:
    explicit SpeedTestPage(QWidget *parent = 0);
    ~SpeedTestPage();
    void updatePage();
    bool judgeTest();

private:
    Ui::SpeedTestPage *ui;
    QTableWidget *speedTable;
    QList<QString> title;
    bool validState;
    QList< QList<QString> > dataList;
    void setTableHeader();
    void setTableContent();

private slots:
    void on_btn_cease_clicked();
    void on_btn_start_clicked();
    void on_btn_back_clicked();
};

#endif // SPEEDTESTPAGE_H
