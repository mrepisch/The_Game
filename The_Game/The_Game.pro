TEMPLATE = app

QT += qml quick
CONFIG += c++11

SOURCES += main.cpp \
    OpenGlWindow.cpp \
    Scene.cpp \
    Mesh.cpp \
    Camera.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    OpenGlWindow.h \
    Scene.h \
    Mesh.h \
    Camera.h

DISTFILES += \
    basic_vertex.sha \
    basic_fragment.sha

