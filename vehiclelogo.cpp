#include "vehiclelogo.h"
#include "ui_vehiclelogo.h"
#include <QDebug>
#include "global.h"

#define _RUN ("font: 12px;background-color: rgb(0, 255, 0); border-radius:15px;border-radius: 14px;")
#define _DISACTIVE ("background-color: rgb(160, 160, 164); border-radius:15px;border-radius: 14px;")
#define _LEFTRUN ("border-image: url(:/image/left.png);")
#define _RIGHTRUN ("border-image: url(:/image/right.png);")
#define _DOWN ("background-color: black;border-image: url(:/image/down.PNG);")
#define _UP ("background-color: black;border-image: url(:/image/up.PNG);")
#define _OFFLINE ("font: 15px; color: rgb(0,0,0); background-color: white; border: 1px solid gray;")
#define _STOP ("font: 15px; color: rgb(0,0,0); background-color: blue; border: 1px solid gray;")
#define _CLOSEALL ("background-color:rgb(85, 0, 127);")
#define _OPENDOOR ("background-color:yellow;")
#define _BLACK ("font: 12px;background-color:black;")
VehicleLogo::VehicleLogo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VehicleLogo)
{
    ui->setupUi(this);
    _LOG << "VehicleLogo constructor";
    ui->label_tc1Direction->hide();
    ui->label_tc2Direction->hide();
}

VehicleLogo::~VehicleLogo()
{
    delete ui;
}

void VehicleLogo::updateVehicleState(bool tc1Active, bool tc2Active, bool forward, bool backward, bool riom3OnLine, bool riom4OnLine, bool up1, bool down1, bool up2, bool down2, bool doorAllClose)
{
    if(tc1Active)
    {
        ui->lblLeftHead1->setStyleSheet(_RUN);
        if(forward)
        {
            ui->label_tc1Direction->setStyleSheet(_LEFTRUN);
            ui->label_tc1Direction->show();
        }
        else if(backward)
        {
            ui->label_tc1Direction->setStyleSheet(_RIGHTRUN);
            ui->label_tc1Direction->show();
        }
        else
        {
            ui->label_tc1Direction->hide();
        }
    }
    else
    {
        ui->lblLeftHead1->setStyleSheet(_DISACTIVE);
        ui->label_tc1Direction->hide();
    }

    if(tc2Active)
    {
        ui->lblRightHead1->setStyleSheet(_RUN);
        if(forward)
        {
            ui->label_tc2Direction->setStyleSheet(_LEFTRUN);
            ui->label_tc2Direction->show();
        }
        else if(backward)
        {
            ui->label_tc2Direction->setStyleSheet(_RIGHTRUN);
            ui->label_tc2Direction->show();
        }
        else
        {
            ui->label_tc2Direction->hide();
        }
    }
    else
    {
        ui->lblRightHead1->setStyleSheet(_DISACTIVE);
        ui->label_tc2Direction->hide();
    }
    this->updatePanState(ui->pantograph1, riom3OnLine, up1, down1);
    this->updatePanState(ui->pantograph2, riom4OnLine, up2, down2);

    if(doorAllClose)
    {
        ui->label_allClose1->setStyleSheet(_CLOSEALL);
        ui->label_allClose2->setStyleSheet(_CLOSEALL);
    }
    else
    {
        ui->label_allClose1->setStyleSheet(_OPENDOOR);
        ui->label_allClose2->setStyleSheet(_OPENDOOR);
    }
}

void VehicleLogo::updatePanState(QLabel *label, bool riomOnLine, bool up, bool down)
{
    if(!riomOnLine)
    {
        label->setStyleSheet(_OFFLINE);
        return;
    }
    else if(!(up ^ down))
    {
        label->setStyleSheet(_STOP);
        return;
    }
    else if(up)
    {
        label->setStyleSheet(_UP);
        return;
    }
    else if(down)
    {
        label->setStyleSheet(_DOWN);
        return;
    }
}

void VehicleLogo::updateVehicleNo(QString lineNo, QString vehicleNo)
{
    ui->lblA1->setText("R" + lineNo + vehicleNo + "1");
    ui->lblB1->setText("R" + lineNo + vehicleNo + "2");
    ui->lblB2->setText("R" + lineNo + vehicleNo + "3");
    ui->lblA2->setText("R" + lineNo + vehicleNo + "4");
}

void VehicleLogo::updateHSCB(bool hscb1, bool hscb2)
{
    if (hscb1)
    {
        ui->label_HSCB1->setStyleSheet(_RUN);
    }
    else
    {
        ui->label_HSCB1->setStyleSheet(_BLACK);
    }

    if (hscb2)
    {
        ui->label_HSCB2->setStyleSheet(_RUN);
    }
    else
    {
        ui->label_HSCB2->setStyleSheet(_BLACK);
    }
}
