#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "TmxFactory.h"
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    TmxFactory a_fac;
    QQuickWindow* a_win = new QQuickWindow();
    auto a_map = a_fac.loadFile("test.tmx", a_win);
    return app.exec();
}

