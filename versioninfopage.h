#ifndef VERSIONINFOPAGE_H
#define VERSIONINFOPAGE_H

#include "mybase.h"

class QLabel;
class VehicleLogo;
namespace Ui {
    class VersionInfoPage;
}

class VersionInfoPage : public MyBase
{
    Q_OBJECT

public:
    explicit VersionInfoPage(QWidget *parent = 0);
    ~VersionInfoPage();
    void updatePage();
    void getCCUVersion(QLabel *label, QString softVersion, QString MVBVersion, QString SDBVersion, QString VxWorksVersion);
    void getBCUVersion(QLabel *label, QString CB01, QString soft, QString EB01);

private:
    Ui::VersionInfoPage *ui;
   // VehicleLogo *vehicleLogo;

private slots:
    void on_btn_back_clicked();
};

#endif // VERSIONINFOPAGE_H
