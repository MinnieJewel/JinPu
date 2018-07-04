#ifndef MYFUNCTION_H
#define MYFUNCTION_H

class QString;

class MyFunction
{
public:
    MyFunction();
    static bool configureValid();
    static QString getString(QString name);
    static int getInt(QString name);
    static void set(QString name, QString value);
    static void set(QString name, int value);

private:
    static QString path;
};

#endif // MYFUNCTION_H
