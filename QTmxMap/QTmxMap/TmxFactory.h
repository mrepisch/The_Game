#ifndef TMXFACTORY_H
#define TMXFACTORY_H

#include <QString>
#include <QSharedPointer>
#include <QXmlStreamReader>
#include <QHash>
#include <QQuickWindow>
#include "QTmxTileMap.h"
#include "QTmxTileSet.h"
#include "QTmxObjectGroup.h"
#include "QTmxObject.h"
#include "qtmxmap_global.h"
class QTMXMAPSHARED_EXPORT TmxFactory
{
public:
    TmxFactory();

    QSharedPointer<QTmxTileMap>loadFile(const QString& t_path, QQuickWindow* t_window);
private:

    QHash<QString,QString>readAttributes();
    QHash<QString,QString>readProperties();

    QSharedPointer<QTmxTileSet>readTileSet(QQuickWindow *p_window);
    QSharedPointer<QTmxObjectGroup>readObjectGroup();
    QSharedPointer<QTmxObject>readObject();
    QXmlStreamReader m_xmlReader;

};

#endif // TMXFACTORY_H
