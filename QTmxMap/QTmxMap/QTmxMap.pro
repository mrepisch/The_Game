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

SOURCES += \
    QTmxTileMap.cpp \
    TmxFactory.cpp \
    TextureAtlas.cpp \
    QTmxObjectGroup.cpp \
    RenderItem.cpp \
    QTmxObject.cpp \
    QTmxMapLayer.cpp \
    Camera.cpp \
    QTmxTileset.cpp \
    QTmxTile.cpp \
    QAStart.cpp

HEADERS +=\
        qtmxmap_global.h \
    QTmxTileMap.h \
    TmxFactory.h \
    TextureAtlas.h \
    QTmxObjectGroup.h \
    QTmxObject.h \
    RenderItem.h \
    QTmxMapLayer.h \
    Camera.h \
    QTmxTileset.h \
    QTmxTile.h \
    QAStart.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
