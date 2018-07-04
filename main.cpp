#include <QApplication>
#include <QWSServer>
#include "global.h"
#include "widget.h"
#include "allports.h"
#include <QDebug>

// a recall function when there is a signal or a message
void customMessageHandler(QtMsgType type, const char *msg)
{
    if (type == QtDebugMsg)
    {
        QFile file("./log.txt");
        file.open(QIODevice::WriteOnly | QIODevice::Append);

        QTextStream textStream(&file);
        textStream << QString("%1").arg(msg) << endl;

        file.close();
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // use a special character set which could show Chinese correctively
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));

    // hide the mouse cursor and change the output stream to log file
#ifndef USER_DEBUG_MODE
    QApplication::setOverrideCursor(QCursor(Qt::BlankCursor));

   if (QWSServer::isCursorVisible())
    {
        QWSServer::setCursorVisible(false);
    }

    // a recall function used by QDebug
    //qInstallMsgHandler(customMessageHandler);
#endif


    Widget w;
    w.setWindowFlags(Qt::FramelessWindowHint);
    w.show();

    return a.exec();
}
