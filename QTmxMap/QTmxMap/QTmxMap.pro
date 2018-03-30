#-------------------------------------------------
#
# Project created by QtCreator 2018-03-30T13:49:42
#
#-------------------------------------------------

QT       += xml quick

QT       -= gui

TARGET = QTmxMap
TEMPLATE = lib

DEFINES += QTMXMAP_LIBRARY

SOURCES += Qtmxmap.cpp \
    TmxReader.cpp \
    TmxMapData.cpp \
    Tile.cpp

HEADERS += Qtmxmap.h\
        qtmxmap_global.h \
    TmxReader.h \
    TmxMapData.h \
    Tile.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
