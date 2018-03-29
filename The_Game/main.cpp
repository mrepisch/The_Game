#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "OpenGlWindow.h"
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    OpenGlWindow window;
    window.show();
    window.init();
    return app.exec();
}

