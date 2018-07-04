#ifndef RUNNINGRECORDCLEARPAGE_H
#define RUNNINGRECORDCLEARPAGE_H

#include <QWidget>
#include "mybase.h"
class QButtonGroup;
class QTimer;

namespace Ui {
    class RunningRecordClearPage;
}

class RunningRecordClearPage : public MyBase
{
    Q_OBJECT

public:
    explicit RunningRecordClearPage(QWidget *parent = 0);
    ~RunningRecordClearPage();
    void updatePage();

public slots:
    void onClearButtonClick(int button);
    void resetServiceFlag();
    void resetERMAP1Flag();
    void resetERMAP2Flag();
    void resetTractionFlag();
    void resetAuxFlag();

private:
    Ui::RunningRecordClearPage *ui;
    QButtonGroup *buttonGroup;
    QTimer *timerERMAP1, *timerERMAP2, *timerTraction, *timerService, *timerAux;
    int timerCounter;

private slots:
    void on_btn_back_clicked();
};

#endif // RUNNINGRECORDCLEARPAGE_H
