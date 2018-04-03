TEMPLATE = app

QT += qml quick
CONFIG += c++11

SOURCES += main.cpp \
    GameRuntime.cpp

RESOURCES += \
    qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    GameRuntime.h

DISTFILES += \
    basic_vertex.sha \
    basic_fragment.sha


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../debug/release/ -lEntityComponent
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../debug/debug/ -lEntityComponent
else:unix: LIBS += -L$$PWD/../debug/ -lEntityComponent

INCLUDEPATH += $$PWD/../QEntityComponent
DEPENDPATH += $$PWD/../QEntityComponent

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../debug/release/ -lQTmxMap
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../debug/debug/ -lQTmxMap
else:unix: LIBS += -L$$PWD/../debug/ -lQTmxMap

INCLUDEPATH += $$PWD/../QTmxMap/QTmxMap
DEPENDPATH += $$PWD/../QTmxMap/QTmxMap
