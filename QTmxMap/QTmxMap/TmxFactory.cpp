#include <QFile>
#include <QDebug>
#include "TmxFactory.h"

const QString S_TILESET_TAGNAME = QStringLiteral("tileset");


TmxFactory::TmxFactory()
{

}

QSharedPointer<QTmxTileMap> TmxFactory::loadFile(const QString &t_path, QQuickWindow *t_window)
{
    QSharedPointer<QTmxTileMap>r_map;
    QFile a_tmxFile(t_path);
    if( a_tmxFile.exists())
    {
        a_tmxFile.open(QIODevice::ReadOnly);
        m_xmlReader.setDevice(&a_tmxFile);
        while( m_xmlReader.readNext() && !m_xmlReader.atEnd())
        {
            if( m_xmlReader.isStartElement() && m_xmlReader.name() == QStringLiteral("map") )
            {
                QHash<QString,QString>a_attr = readAttributes();
                r_map = QSharedPointer<QTmxTileMap>(new QTmxTileMap(
                            a_attr.value(QStringLiteral("renderorder")),
                            a_attr.value(QStringLiteral("orientation")),
                            a_attr.value(QStringLiteral("width")).toInt(),
                            a_attr.value(QStringLiteral("height")).toInt(),
                            a_attr.value(QStringLiteral("tilewidth")).toInt(),
                            a_attr.value(QStringLiteral("tileheight")).toInt() ) );
            }
            if( m_xmlReader.isStartElement() && m_xmlReader.name() == S_TILESET_TAGNAME)
            {
                QSharedPointer<QTmxTileSet>a_tileSet = readTileSet(t_window);
                r_map->addTileSet(a_tileSet);
            }
            if( m_xmlReader.isStartElement() &&m_xmlReader.name() == QStringLiteral("objectgroup"))
            {
                QSharedPointer<QTmxObjectGroup>a_objectGroup = readObjectGroup();
                r_map->addObjectLayer(a_objectGroup);
            }
        }
    }
    else
    {
        qCritical()<<QStringLiteral("Txm File not found");
    }
    return r_map;
}

QHash<QString, QString> TmxFactory::readAttributes()
{
    QHash<QString,QString>r_attributes;
    QXmlStreamAttributes attr = m_xmlReader.attributes();
    for( int i = 0; i < attr.size(); ++i ) {
        r_attributes.insert(attr.at(i).name().toString(), attr.at(i).value().toString());
    }
    return r_attributes;
}

QSharedPointer<QTmxTileSet> TmxFactory::readTileSet(QQuickWindow* p_window)
{

    QHash<QString,QString>a_tileSetAttr = readAttributes();
    QSharedPointer<QTmxTileSet>r_tileSet = QSharedPointer<QTmxTileSet>(new QTmxTileSet(
                                                                       a_tileSetAttr.value(QStringLiteral("name")),
                                                                       a_tileSetAttr.value(QStringLiteral("tileheight")).toInt(),
                                                                       a_tileSetAttr.value(QStringLiteral("tileheight")).toInt(),
                                                                       a_tileSetAttr.value(QStringLiteral("tilecount")).toInt()
               ));
    while(  m_xmlReader.readNext() && !m_xmlReader.atEnd() )
    {
        if( m_xmlReader.isStartElement() && m_xmlReader.name() == QStringLiteral("image"))
        {
            QHash<QString,QString>a_imageAttr = readAttributes();
            r_tileSet->addImage(a_imageAttr.value(QStringLiteral("source")),
                                a_imageAttr.value(QStringLiteral("width")).toInt(),
                                a_imageAttr.value(QStringLiteral("height")).toInt(),
                                p_window);
        }
        else if( m_xmlReader.isStartElement() && m_xmlReader.name() == QStringLiteral("tile"))
        {
            QHash<QString,QString>a_attr = readAttributes();
            QHash<QString,QString>a_props = readProperties();
            r_tileSet->addTileData(a_attr.value(QStringLiteral("id")).toInt(), a_props);
        }
        if( m_xmlReader.isEndElement() && m_xmlReader.name() == S_TILESET_TAGNAME)
        {
            break;
        }

    }
    return r_tileSet;
}

QSharedPointer<QTmxObjectGroup> TmxFactory::readObjectGroup()
{
    QHash<QString,QString>a_layerAttr = readAttributes();
    QSharedPointer<QTmxObjectGroup>r_group = QSharedPointer<QTmxObjectGroup>(new QTmxObjectGroup(a_layerAttr.value(QStringLiteral("name"))));
    while( m_xmlReader.readNext() && !m_xmlReader.atEnd())
    {
        if( m_xmlReader.isStartElement() && m_xmlReader.name() == QStringLiteral("properties"))
        {
            r_group->addProperties(readProperties());
        }
        else if(m_xmlReader.isStartElement() && m_xmlReader.name() == QStringLiteral("object") )
        {
            r_group->addObject(readObject());
        }
        if( m_xmlReader.isEndElement() && m_xmlReader.name() == QStringLiteral("objectgroup"))
        {
            break;
        }
    }
    return r_group;
}

QSharedPointer<QTmxObject> TmxFactory::readObject()
{
    QHash<QString,QString>a_objectAttr = readAttributes();
    QSharedPointer<QTmxObject>r_object = QSharedPointer<QTmxObject>(new QTmxObject(
                                                                        a_objectAttr.value(QStringLiteral("id")).toInt(),
                                                                        a_objectAttr.value(QStringLiteral("name")),
                                                                        a_objectAttr.value(QStringLiteral("type")),
                                                                        a_objectAttr.value(QStringLiteral("x")).toInt(),
                                                                        a_objectAttr.value(QStringLiteral("y")).toInt(),
                                                                        a_objectAttr.value(QStringLiteral("width")).toInt(),
                                                                        a_objectAttr.value(QStringLiteral("height")).toInt()
                                                                        ));
    while( m_xmlReader.readNext() && !m_xmlReader.atEnd())
    {
        if( m_xmlReader.isStartElement() && m_xmlReader.name() == QStringLiteral("properties") )
        {
            r_object->addPropertys(readProperties());
        }
        if( m_xmlReader.isEndElement() && m_xmlReader.name() == QStringLiteral("object"))
        {
            break;
        }
    }
    return r_object;
}

QHash<QString, QString> TmxFactory::readProperties()
{
    QHash<QString,QString>r_props;
    while( !m_xmlReader.isEndElement() && m_xmlReader.name() != QStringLiteral("properties") )
    {
        if( m_xmlReader.isStartElement() && m_xmlReader.name() == QStringLiteral("property"))
        {
            QHash<QString,QString>a_attr = readAttributes();
            r_props.insert(a_attr.value(QStringLiteral("name")), a_attr.value("value"));
        }
        m_xmlReader.readNext();
    }
    return r_props;
}

