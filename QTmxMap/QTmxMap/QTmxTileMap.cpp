#include "QTmxTileMap.h"

QTmxTileMap::QTmxTileMap(const QString t_renderOrder, const QString t_orientation, int width, int height, int tileWidth, int tileHeight, QObject *parent) : QObject(parent)
{
    if( t_renderOrder == QStringLiteral("right-down"))
    {
        m_renderOrder = e_right_down;
    }
    if( t_orientation == QStringLiteral("orthogonal"))
    {
        m_orientation = e_orthogonal;
    }
    else
    {
        m_orientation = e_isometric;
    }
    m_width = width;
    m_height = height;
    m_tileHeigth = tileHeight;
    m_tileWidth = tileWidth;
}

void QTmxTileMap::addTileSet(QSharedPointer<QTmxTileSet> p_tileSet)
{
    if( !p_tileSet.isNull())
    {
        m_tileSets.append(p_tileSet);
    }
}

void QTmxTileMap::addObjectLayer(QSharedPointer<QTmxObjectGroup> p_objectLayer)
{
    if( !p_objectLayer.isNull())
    {
        m_objectGroups.append(p_objectLayer);
    }
}

