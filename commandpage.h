#ifndef COMMANDPAGE_H
#define COMMANDPAGE_H

#include <mybase.h>

namespace Ui {
    class CommandPage;
}

class CommandPage : public MyBase
{
    Q_OBJECT

public:
    explicit CommandPage(QWidget *parent = 0);
    ~CommandPage();

private:
    Ui::CommandPage *ui;
};

#endif // COMMANDPAGE_H
