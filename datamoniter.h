#ifndef DATAMONITER_H
#define DATAMONITER_H

#include "mybase.h"


class QButtonGroup;
class QTableWidget;
namespace Ui {
    class DataMoniter;
}

class DataMoniter : public MyBase
{
    Q_OBJECT

public:
    explicit DataMoniter(QWidget *parent = 0);
    ~DataMoniter();
    void showPortData(int deviceNo);
    void showPortDataByPage();
    void getDataByPorts(QList<struct port *> ports);
    void cleanContent();

private:
    Ui::DataMoniter *ui;
    QButtonGroup *buttonGroup;
    QTableWidget *portDataTable;
    int selectPort;
    QMap<unsigned short int, struct port_data> devicePorts;
    void updatePage();
    void setTableContent();
    void setTableTitle();
    //void cleanContent();

private slots:
    void on_btn_back_clicked();
    void onBtnClicked(int id);
};

#endif // DATAMONITER_H
