#include "myfunction.h"
#include <QFile>
#include <QSettings>
#include <QDebug>
#include "global.h"

MyFunction::MyFunction()
{
    _LOG << "MyFunction constructor";
}


QString MyFunction::path = QString("./configure.ini");

bool MyFunction::configureValid()
{
    if (QFile::exists("./configure.ini"))
    {
        QSettings *configure = new QSettings(path, QSettings::IniFormat, 0);

        if (configure->value("/Check/life").toInt() == 1)
        {
            delete configure;

            return true;
        }

        else
        {
            delete configure;

            return false;
        }
    }
    else
    {
        return false;
    }
}

QString MyFunction::getString(QString name)
{
    QSettings *configure = new QSettings(path, QSettings::IniFormat, 0);
    QString value = configure->value(name).toString();

    delete configure;
    return value;
}

int MyFunction::getInt(QString name)
{
    QSettings *configure = new QSettings(path, QSettings::IniFormat, 0);
    int value = configure->value(name).toInt();

    delete configure;
    return value;
}

void MyFunction::set(QString name, int value)
{
    QSettings *configure = new QSettings(path, QSettings::IniFormat, 0);
    configure->setValue(name, value);

    delete configure;
}

void MyFunction::set(QString name, QString value)
{
    QSettings *configure = new QSettings(path, QSettings::IniFormat, 0);
    configure->setValue(name, value);

    delete configure;
}
