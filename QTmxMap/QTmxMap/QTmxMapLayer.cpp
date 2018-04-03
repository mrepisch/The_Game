#include "QTmxMapLayer.h"
#include "TextureAtlas.h"
#include "QTmxTileset.h"
#include "RenderItem.h"
#include <QStringList>
QTmxMapLayer::QTmxMapLayer(const QString &p_name, int width, int height, QObject *parent) : QObject(parent)
{
    m_name = p_name;
    m_width = width;
    m_height = height;
}

QTmxMapLayer::~QTmxMapLayer()
{
    m_tiles.clear();
}

void QTmxMapLayer::setTileData(const QString &t_tiles)
{
    m_tileData = t_tiles;
}

void QTmxMapLayer::addProperties(const QHash<QString, QString> &p_props)
{
    m_properties = p_props;
}

void QTmxMapLayer::initTileGrafic(QQuickItem *p_parent, const QTmxTileset* p_tileset)
{
    QStringList a_tiles = m_tileData.replace(QStringLiteral("\n"),QStringLiteral("")).split(QStringLiteral(","));

    int x = 0;
    int y = 0;
    int xTileCount = 0;
    int counter = 0;
    foreach( const QString a_tileIndex, a_tiles)
    {
        QSharedPointer<QTmxTile>a_tile;

        if( m_properties.contains("z"))
        {
            a_tile= QSharedPointer<QTmxTile>(new QTmxTile(a_tileIndex.toInt(),counter,m_properties.value(QStringLiteral("z")).toInt()));
        }
        a_tile= QSharedPointer<QTmxTile>(new QTmxTile(a_tileIndex.toInt(),counter));
        a_tile->setRect(QRectF(x,y,p_tileset->tileWidth(),p_tileset->tileHeight()));
        if( a_tileIndex != QStringLiteral("0"))
        {
            QSharedPointer<RenderItem>a_renderItem = QSharedPointer<RenderItem>( new RenderItem(p_parent));
            QSGSimpleTextureNode* a_textureNode = new QSGSimpleTextureNode();
            a_renderItem->setVisible(true);
            a_textureNode->setTexture(p_tileset->getTextureForTile(a_tileIndex.toInt()) );
            a_textureNode->setRect(QRectF(x,y,p_tileset->tileWidth(),p_tileset->tileHeight()));
            a_renderItem->setTextureNode(a_textureNode);
            a_renderItem->setRect(QRectF(x,y,p_tileset->tileWidth(),p_tileset->tileHeight()));
            int a_z = 0;
            if( m_properties.contains(QStringLiteral("z")))
            {
                a_z = m_properties.value(QStringLiteral("z")).toInt();
            }
            a_renderItem->setZ(a_z);
            a_tile->setRenderItem(a_renderItem);

        }
        m_tiles.append(a_tile);
        x += p_tileset->tileWidth();
        ++xTileCount;
        if( xTileCount >= m_width)
        {
            x = 0;
            xTileCount = 0;
            y += p_tileset->tileHeight();
        }
        ++counter;
    }

}

const QHash<QString, QString> &QTmxMapLayer::getProps()
{
    return m_properties;
}

const QString &QTmxMapLayer::name() const
{
    return m_name;
}

void QTmxMapLayer::update()
{
    foreach( QSharedPointer<QTmxTile>a_iter , m_tiles)
    {
        a_iter->update();
    }
}

QSharedPointer<QTmxTile> QTmxMapLayer::queryTileByPosition(int x, int y)
{
    QSharedPointer<QTmxTile>r_tile;
    foreach(const QSharedPointer<QTmxTile>a_iter , m_tiles)
    {
        const QRectF& a_tileRect = a_iter->getRect();
        if( a_tileRect.x() < x && a_tileRect.x() + a_tileRect.width() > x
            && a_tileRect.y() < y && a_tileRect.y() + a_tileRect.height() > y)
        {
            r_tile = a_iter;
            break;
        }
    }
    return r_tile;
}

QSharedPointer<QTmxTile> QTmxMapLayer::queryTileByFieldID(int p_fieldId) const
{
    QSharedPointer<QTmxTile>r_tile;
    foreach( QSharedPointer<QTmxTile>a_iter , m_tiles)
    {
        if( p_fieldId == a_iter->getFieldId())
        {
            r_tile = a_iter;
        }
    }
    return r_tile;
}

QVector<QSharedPointer<QTmxTile> > QTmxMapLayer::querySourundings(int p_tile) const
{
    QVector<int>a_toSearch;
    QSharedPointer<QTmxTile>a_startTile = queryTileByFieldID(p_tile);
    bool a_upOk = false;
    bool a_downOk = false;
    if( a_startTile->getRect().y() > 0 + a_startTile->getRect().height())
    {
        a_upOk = true;
        // UP
        a_toSearch.append(p_tile - m_width);


    }
    if( a_startTile->getRect().y() + a_startTile->getRect().height() <= m_height * a_startTile->getRect().height())
    {
        a_downOk = true;
        //DOWN
        a_toSearch.append(p_tile + m_width);
    }
    if( a_startTile->getRect().x() - a_startTile->getRect().width() >= 0)
    {
        // get the left tiles;
        a_toSearch.append(p_tile - 1);

        if(a_upOk)
        {
            //UP LEFT
            a_toSearch.append(p_tile - m_width - 1);
        }
        if( a_downOk)
        {
            // DOWN LEFT
            a_toSearch.append(p_tile + m_width - 1);
        }

    }
    if( a_startTile->getRect().x() + a_startTile->getRect().width() <= m_height * a_startTile->getRect().width())
    {
        //RIGHT TILES
        a_toSearch.append(p_tile + 1);
        if( a_upOk)
        {
            // UP RIGHT
            a_toSearch.append(p_tile - m_width + 1);
        }
        if( a_downOk)
        {
            // DOWN RIGHT
            a_toSearch.append(p_tile + m_width + 1);
        }

    }
    QVector<QSharedPointer<QTmxTile> >r_tiles;
    foreach( int a_iter , a_toSearch)
    {
        r_tiles.append(queryTileByFieldID(a_iter));
    }
    return r_tiles;
}

int QTmxMapLayer::width() const
{
    return m_width;
}

int QTmxMapLayer::height() const
{
    return m_height;
}

