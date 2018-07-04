#ifndef HISTORYFAULT_H
#define HISTORYFAULT_H

#include "mybase.h"

class QTableWidget;
class CrrcFault;
class QTableWidgetItem;

namespace Ui {
    class HistoryFault;
}

class HistoryFault : public MyBase
{
    Q_OBJECT

public:
    explicit HistoryFault(QWidget *parent = 0);
    ~HistoryFault();
    QTableWidget *historyFaultListTable;
    void setTableHeader();
    void setTableItems();
    void updatePage();
    void installCrrcFault(CrrcFault *crrcFault);

private:
    Ui::HistoryFault *ui;
    CrrcFault *crrcFault;
    int page;
    QList<QString> title;

private slots:
    void on_btn_back_clicked();
    void on_btn_next_clicked();
    void on_btn_pre_clicked();
    void on_btn_lastPage_clicked();
    void on_btn_firstPage_clicked();
    };

#endif // HISTORYFAULT_H
