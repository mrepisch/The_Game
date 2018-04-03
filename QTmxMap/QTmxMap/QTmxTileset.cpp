#include "QTmxTileset.h"
#include "TextureAtlas.h"
QTmxTileset::QTmxTileset(int p_firstId,const QString &t_name, int tileWidth, int tileHeight, int tileCount, QObject *parent)
{
    m_firstId = p_firstId;
    m_name = t_name;
    m_tileWidth = tileWidth;
    m_tileHeight = tileHeight;
    m_tileCount = tileCount;
}

void QTmxTileset::addImage(const QString &t_path, int width, int height, QQuickWindow *p_window)
{
    m_atlas.reset(new TextureAtlas(p_window,t_path,m_tileWidth,m_tileHeight,m_firstId));
}

void QTmxTileset::addTileData(int t_id, QHash<QString, QString> a_attributes)
{
    STileSetTileData* a_tileData = new STileSetTileData;
    a_tileData->id = t_id;
    a_tileData->a_attributes = a_attributes;
    m_tileData.append(a_tileData);
}

const QHash<QString, QString> QTmxTileset::getTileData(int t_id) const
{
    QHash<QString,QString>r_data;
    foreach(STileSetTileData* a_iter , m_tileData)
    {
        if( a_iter->id == t_id)
        {
            r_data = a_iter->a_attributes;
        }
    }
    return r_data;
}

QSGTexture *QTmxTileset::getTextureForTile(int t_id) const
{
    if( t_id != 0)
    {
        return m_atlas->getTextureNode( t_id);
    }
    return NULL;
}

const QString &QTmxTileset::name() const
{
    return m_name;
}

int QTmxTileset::tileWidth() const
{
    return m_tileWidth;
}

int QTmxTileset::tileHeight() const
{
    return m_tileHeight;
}
