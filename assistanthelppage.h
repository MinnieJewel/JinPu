#ifndef ASSISTANTHELPPAGE_H
#define ASSISTANTHELPPAGE_H

#include "mybase.h"

namespace Ui {
    class AssistantHelpPage;
}

class AssistantHelpPage : public MyBase
{
    Q_OBJECT

public:
    explicit AssistantHelpPage(QWidget *parent = 0);
    ~AssistantHelpPage();

private:
    Ui::AssistantHelpPage *ui;

private slots:
    void on_btn_back_clicked();
};

#endif // ASSISTANTHELPPAGE_H
