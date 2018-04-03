#ifndef QTMXTILE_H
#define QTMXTILE_H

#include <QObject>
#include <QSharedPointer>
#include <QRectF>
#include <QSGTexture>
#include <QQuickItem>
#include "RenderItem.h"
#include "qtmxmap_global.h"
class QTMXMAPSHARED_EXPORT QTmxTile : public QObject
{
    Q_OBJECT
public:
    explicit QTmxTile(int p_tileId, int fieldID, int z= 0,QObject *parent = 0);

    void setRenderItem( QSharedPointer<RenderItem>p_renderItem);
    void setNewTexture(QSGTexture* p_texture, QQuickItem* p_parent);
    void setPosition( int x, int y);
    void setWidth( int width);
    void setHeight( int height);
    void setRect( QRectF p_rect);
    int getTileId()const;
    void update();
    const QRectF& getRect() const;
    int getFieldId() const;

signals:

public slots:

private:
    int m_fielID;
    int m_z;
    QRectF m_rect;
    int m_tileId;
    QSharedPointer<RenderItem>m_renderItem;
};

#endif // QTMXTILE_H
