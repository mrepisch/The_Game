#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "OpenGlWindow.h"
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    OpenGlWindow window;
    window.show();
    return app.exec();
}

