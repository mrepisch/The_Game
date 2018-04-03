#ifndef TMXFACTORY_H
#define TMXFACTORY_H

#include <QString>
#include <QSharedPointer>
#include <QXmlStreamReader>
#include <QHash>
#include <QQuickWindow>
#include "QTmxTileMap.h"
#include "QTmxTileset.h"
#include "QTmxObjectGroup.h"
#include "QTmxObject.h"
#include "QTmxMapLayer.h"
#include "Camera.h"
#include "qtmxmap_global.h"
class QTMXMAPSHARED_EXPORT TmxFactory
{
public:
    TmxFactory();

    QSharedPointer<QTmxTileMap>loadFile(const QString& p_path, QQuickWindow* p_window, QSharedPointer<Camera>p_camera );
private:

    QHash<QString,QString>readAttributes();
    QHash<QString,QString>readProperties();

    QSharedPointer<QTmxTileset>readTileSet(QQuickWindow *p_window);
    QSharedPointer<QTmxObjectGroup>readObjectGroup();
    QSharedPointer<QTmxObject>readObject();
    QSharedPointer<QTmxMapLayer>readLayer();

    QXmlStreamReader m_xmlReader;

};

#endif // TMXFACTORY_H
