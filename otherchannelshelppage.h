#ifndef OTHERCHANNELSHELPPAGE_H
#define OTHERCHANNELSHELPPAGE_H

#include "mybase.h"

namespace Ui {
    class OtherChannelsHelpPage;
}

class OtherChannelsHelpPage : public MyBase
{
    Q_OBJECT

public:
    explicit OtherChannelsHelpPage(QWidget *parent = 0);
    ~OtherChannelsHelpPage();

private:
    Ui::OtherChannelsHelpPage *ui;

private slots:
    void on_btn_back_clicked();
};

#endif // OTHERCHANNELSHELPPAGE_H
