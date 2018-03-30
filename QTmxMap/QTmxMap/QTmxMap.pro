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
    QTxmMapLayer.cpp \
    TmxFactory.cpp \
    QTmxTileSet.cpp \
    TextureAtlas.cpp \
    QTmxObjectGroup.cpp \
    RenderItem.cpp \
    QTmxObject.cpp

HEADERS +=\
        qtmxmap_global.h \
    QTmxTileMap.h \
    QTxmMapLayer.h \
    TmxFactory.h \
    QTmxTileSet.h \
    TextureAtlas.h \
    QTmxObjectGroup.h \
    QTmxObject.h \
    RenderItem.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
