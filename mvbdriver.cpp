#include "mvbdriver.h"
#include "global.h"
#include <QDebug>
#include "database.h"

#define _HMI1_MVB_ADDRESS 0X31
#define _HMI2_MVB_ADDRESS 0X32

MvbDriver::MvbDriver()
{
    _LOG << "MvbDriver constructor";
}

bool MvbDriver::initialMvb(int position)
{
    short int value = 0;

    if(1 == position)
    {
        value = pixymvb_CfgHWInit(PIXYMVB_MIN_TMMODEL, PIXYMVB_PHY_EMD, _HMI1_MVB_ADDRESS, 1);

        return true;
    }
    else if (2 == position)
    {
        value = pixymvb_CfgHWInit(PIXYMVB_MIN_TMMODEL, PIXYMVB_PHY_EMD, _HMI2_MVB_ADDRESS, 1);

        return true;
    }
    else
    {
        _LOG << "invalid mvb device address";

        return false;
    }
}


void MvbDriver::addPorts(const QList<port *> &ports) const
{
    unsigned short int value = 0;

    foreach (struct port *pointer, ports)
    {
        if(uSinkPort == pointer->type)
        {
            value = pixymvb_AddPort(pointer->address, PIXYMVB_SNKPORT, 0x01 << pointer->size, NULL);
        }
        else if(uSourcePort == pointer->type)
        {
            value = pixymvb_AddPort(pointer->address, PIXYMVB_SRCPORT, 0x01 << pointer->size, NULL);
        }
        else if (uUserDefinePort == pointer->type)
        {
            value = 0;
        }

#ifndef USER_DEBUG_MODE
        if (value != PIXYMVB_OK)
        {
            qDebug() << "fail to add port" << pointer->address;
        }
#endif
    }
}


bool MvbDriver::setMvbOperation()
{
    unsigned short int value = 0;

    value = pixymvb_ChangeState(PIXYMVB_OPERATION_STATE);

    if (PIXYMVB_OK == value)
        return true;

    else
    {
        _LOG << "fail to set mvb to operation";
        return false;
    }
}


bool MvbDriver::setMvbConfigure()
{
    unsigned short int value = 0;

    value = pixymvb_ChangeState(PIXYMVB_CONFIG_STATE);

    if (PIXYMVB_OK == value)
        return true;
    else
    {
        _LOG << "fail to set mvb to configure";

        return false;
    }
}


bool MvbDriver::setMvbStop()
{
    unsigned short int value = 0;

    value = pixymvb_ChangeState(PIXYMVB_STOP_STATE);

    if(PIXYMVB_OK == value)
    {
        _LOG << "mvb board has been set to stop successfully";

        return true;
    }
    else
    {
        _LOG << "fail to set mvb stop";

        return false;
    }
}


void MvbDriver::synchronizeMvbData(const QList<port *> &allPorts, QMap<unsigned short, port_data *> &ports)
{
    foreach (struct port *pointer, allPorts)
    {
        if (ports.contains(pointer->address) == false)
            ports.insert(pointer->address, new struct port_data);

        if (pointer->type == uSinkPort)
        {
            pixymvb_GetPort(pointer->address, &(ports[pointer->address]->data),&(ports[pointer->address]->time));

        }
        else if (pointer->type == uSourcePort)
        {
            pixymvb_PutPort(pointer->address, &(ports[pointer->address]->data));
        }
    }
}

void MvbDriver::testInitial() const
{
    _LOG << "change mvb board state: " << pixymvb_ChangeState(PIXYMVB_CONFIG_STATE);
    _LOG << "initial mvb board: " << pixymvb_CfgHWInit(PIXYMVB_MIN_TMMODEL, PIXYMVB_PHY_EMD, 0x31, 1);
    _LOG << "add mvb port 0x0FF: " << pixymvb_AddPort(0x0FF, PIXYMVB_SNKPORT, 8, NULL);
    _LOG << "change mvb board operation: " << pixymvb_ChangeState(PIXYMVB_OPERATION_STATE);
}

void MvbDriver::testGetData() const
{
    PIXYMVB_Data data = {0};
    unsigned short int value = 0, time = 0;

    value = pixymvb_GetPort(0x0FF, &data, &time);

    _LOG << "return value: " << value << "data: " << data[0] << data[1] << data[2] << data[3] << "time: "<< time;
}

