#include "QTmxTileSet.h"
#include <QQuickWindow>
#include <QSGTexture>

QTmxTileSet::QTmxTileSet(const QString& t_name, int tileWidth, int tileHeight, int tileCount, QObject *parent) : QObject(parent)
{
    m_name = t_name;
    m_tileWidth = tileWidth;
    m_tileHeight = tileHeight;
    m_tileCount = tileCount;
}

void QTmxTileSet::addImage(const QString &t_path, int width, int height, QQuickWindow* p_window)
{

    m_atlas.reset(new TextureAtlas(p_window,t_path,m_tileWidth,m_tileHeight,0) );
}

void QTmxTileSet::addTileData(int t_id, QHash<QString, QString> a_attributes)
{
    STileSetTileData* a_data = new STileSetTileData();
    a_data->id = t_id;
    a_data->a_attributes = a_attributes;
    m_tileData.append(a_data);
}

const QHash<QString, QString> QTmxTileSet::getTileData(int t_id)
{
    QHash<QString,QString> r_data;
    foreach( STileSetTileData* a_iter , m_tileData)
    {
        if( a_iter->id == t_id)
        {
            r_data = a_iter->a_attributes;
            break;
        }
    }
    return r_data;
}

QSGTexture *QTmxTileSet::getTextureForTile(int t_id)
{
    return m_atlas->getTextureNode(t_id);
}

