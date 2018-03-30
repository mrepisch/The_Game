#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "TmxReader.h"
#include "TmxMapData.h"
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    TmxReader a_reader;
    TmxMapData* a_data =  a_reader.readTmxFile("map1.tmx");
    return app.exec();
}

