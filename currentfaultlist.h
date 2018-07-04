#ifndef CURRENTFAULTLIST_H
#define CURRENTFAULTLIST_H

#include "mybase.h"
class QTableWidget;
class CrrcFault;
class QTableWidgetItem;
class FaultInfoPage;
class QButtonGroup;
class QPushButton;
namespace Ui {
    class CurrentFaultList;
}

class CurrentFaultList : public MyBase
{
    Q_OBJECT

public:
    explicit CurrentFaultList(QWidget *parent = 0);
    ~CurrentFaultList();
    QTableWidget *currentFaultListTable;
    void setTableHeader();
    void setTableItems();
    void updatePage();
    void installCrrcFault(CrrcFault *crrcFault);

private:
    Ui::CurrentFaultList *ui;
    CrrcFault *crrcFault;
    int page;
    QList<QString> title;
    QPushButton *button[12];


private slots:
    void on_btn_back_clicked();
    void on_btn_next_clicked();
    void on_btn_pre_clicked();
    void on_btn_lastPage_clicked();
    void on_btn_firstPage_clicked();
};

#endif // CURRENTFAULTLIST_H
