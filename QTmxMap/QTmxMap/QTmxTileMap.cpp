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

void QTmxTileMap::addTileSet(QSharedPointer<QTmxTileset> p_tileSet)
{
    if( !p_tileSet.isNull())
    {
        m_tileSets.append(p_tileSet);
    }
}

void QTmxTileMap::addTileLayer(QSharedPointer<QTmxMapLayer> p_layer)
{
    if(!p_layer.isNull())
    {
        m_layers.append(p_layer);
    }
}

void QTmxTileMap::addObjectLayer(QSharedPointer<QTmxObjectGroup> p_objectLayer)
{
    if( !p_objectLayer.isNull())
    {
        m_objectGroups.append(p_objectLayer);
    }
}

void QTmxTileMap::initalizeGrafics(QQuickWindow *p_window, QQuickItem *p_parent)
{
    foreach( QSharedPointer<QTmxMapLayer>a_iter , m_layers)
    {
        a_iter->initTileGrafic(p_parent,m_tileSets[0].data());
    }
}

QSharedPointer<QTmxTile> QTmxTileMap::queryTileByPosition(int x, int y, const QString& t_layerName)
{
    QSharedPointer<QTmxTile> r_tile;

    foreach( QSharedPointer<QTmxMapLayer>a_layer , m_layers)
    {
        if( a_layer->name() == t_layerName)
        {
            r_tile = a_layer->queryTileByPosition(x,y);
        }
    }
    return r_tile;
}

QSharedPointer<QTmxMapLayer> QTmxTileMap::queryLayer(const QString &p_layerName)
{
    QSharedPointer<QTmxMapLayer>r_layer;
    foreach( QSharedPointer<QTmxMapLayer>a_layer , m_layers)
    {
        if( a_layer->name() == p_layerName)
        {
            r_layer = a_layer;
            break;
        }
    }

    return r_layer;
}

QVector<QSharedPointer<QTmxTile> > QTmxTileMap::querySourundingTiles(int p_tile, const QString &p_layerName)
{
    QSharedPointer<QTmxMapLayer>a_layer = queryLayer(p_layerName);
    return a_layer->querySourundings(p_tile);
}

QSharedPointer<QTmxTileset> QTmxTileMap::queryTileset(const QString &t_name)
{
    QSharedPointer<QTmxTileset> r_tileSet;
    foreach( QSharedPointer<QTmxTileset>a_iter , m_tileSets)
    {
        if( a_iter->name() == t_name)
        {
            r_tileSet = a_iter;
        }
    }
    return r_tileSet;
}



void QTmxTileMap::update()
{
    foreach( QSharedPointer<QTmxMapLayer>a_iter , m_layers)
    {
        a_iter->update();
    }
    foreach( QSharedPointer<QTmxObjectGroup>a_iter, m_objectGroups)
    {
        a_iter->update();
    }
}

