#include "widget.h"
#include <QApplication>
#include"login.h"
#include <QSslSocket>
#include <QDebug>


int main(int argc, char *argv[])
{
   qRegisterMetaType<QVector<QString>>("QVector<QString>");
    QApplication a(argc, argv);

//    Widget w;
//    w.show();

    Login w;
    w.show();
    return a.exec();
}
