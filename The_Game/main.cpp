#include <QGuiApplication>
#include <QQmlEngine>
#include <QQmlComponent>
#include <QSharedPointer>
#include <QQuickView>
#include <QDebug>
#include "TmxFactory.h"
#include "Camera.h"
#include "GameRuntime.h"
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    TmxFactory a_fac;
    GameRuntime* a_win = new GameRuntime();

    auto a_map = a_fac.loadFile("test.tmx", a_win, a_win->getCamera());
    a_win->setTileMap(a_map);
    a_win->show();
    a_win->resize(800,600);
    a_win->start();
    return app.exec();
}

