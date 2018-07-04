#ifndef RUNNINGRECORDPAGE_H
#define RUNNINGRECORDPAGE_H

#include <QWidget>
#include "mybase.h"

class QTableWidget;
namespace Ui {
    class RunningRecordPage;
}

class RunningRecordPage : public MyBase
{
    Q_OBJECT

public:
    explicit RunningRecordPage(QWidget *parent = 0);
    ~RunningRecordPage();
    QTableWidget *recordTable;
    QList<QString> title, recordItem, recordState, StartTime, recordCapacity;
    void updatePage();
    void setTableHeader();
    void setTableContent();

private:
    Ui::RunningRecordPage *ui;

private slots:
    void on_btn_back_clicked();
};

#endif // RUNNINGRECORDPAGE_H
