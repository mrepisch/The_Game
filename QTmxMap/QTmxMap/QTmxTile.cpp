#include "QTmxTile.h"

void QTmxTile::setRenderItem(QSharedPointer<RenderItem> p_renderItem)
{

    m_renderItem = p_renderItem;
}

QTmxTile::QTmxTile(int p_tileId,int fieldID, int z ,QObject *parent) :QObject(parent)
{
    m_tileId = p_tileId;
    m_fielID = fieldID;
    m_z = z;
}

void QTmxTile::setNewTexture(QSGTexture *p_texture, QQuickItem *p_parent)
{
    if( !m_renderItem.isNull())
    {
        m_renderItem->setTexture(p_texture);
        m_renderItem->setZ(m_z);
    }
    else
    {
        m_renderItem = QSharedPointer<RenderItem>(new RenderItem(p_parent));
        m_renderItem->setVisible(true);
        m_renderItem->setTexture(p_texture);
        m_renderItem->setRect(m_rect);
        m_renderItem->setZ(m_z);

    }

}

void QTmxTile::setPosition(int x, int y)
{
    m_rect.setX(x);
    m_rect.setY(y);
}

void QTmxTile::setWidth(int width)
{
    m_rect.setWidth(width);
}

void QTmxTile::setHeight(int height)
{
    m_rect.setHeight(height);
}

void QTmxTile::setRect(QRectF p_rect)
{
    m_rect = p_rect;
}

int QTmxTile::getTileId() const
{
    return m_tileId;
}

void QTmxTile::update()
{
    if( !m_renderItem.isNull())
    {
        m_renderItem->setRect(m_rect);
        m_renderItem->update();
    }
}

int QTmxTile::getFieldId() const
{
    return m_fielID;
}

const QRectF &QTmxTile::getRect() const
{
    return m_rect;
}

