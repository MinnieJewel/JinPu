#ifndef SETPASSWORDPAGE_H
#define SETPASSWORDPAGE_H

#include "mybase.h"

class QButtonGroup;

namespace Ui {
    class SetPasswordPage;
}

class SetPasswordPage : public MyBase
{
    Q_OBJECT

public:
    explicit SetPasswordPage(QWidget *parent = 0);
    void setButtonStyle(int);
    bool checkPwdValue();
    void initialValues();
    ~SetPasswordPage();

private:
    Ui::SetPasswordPage *ui;
    QString oldPassword, newPassword, confirmPassword;
    QButtonGroup *inputButtons;
    QButtonGroup *passwordButtons;
    int currentButton;


private slots:
    void on_btn_back_clicked();
    void on_btn_confirm_clicked();
    void typeInPassword(int);
    void selectInsert(int);

};

#endif // SETPASSWORDPAGE_H
