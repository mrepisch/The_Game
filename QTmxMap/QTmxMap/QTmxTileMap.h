#ifndef QTMXTILEMAP_H
#define QTMXTILEMAP_H

#include <QObject>
#include "QTmxTileset.h"
#include "QTmxObjectGroup.h"
#include "QTmxMapLayer.h"
#include <QTmxTile.h>
#include <Camera.h>
#include <QVector>
//<map version="1.0" orientation="orthogonal" renderorder="right-down" width="10" height="10" tilewidth="32" tileheight="32" nextobjectid="5">


class QTmxTileMap : public QObject
{
    Q_OBJECT
public:
    enum eRenderOder
    {
        e_right_down
    };

    enum EOrientation
    {
        e_orthogonal,
        e_isometric
    };

    explicit QTmxTileMap(const QString t_renderOrder,const QString t_orientation, int width, int height, int tileWidth, int tileHeight, QObject *parent = 0);

    void addTileSet( QSharedPointer<QTmxTileset>p_tileSet);
    void addTileLayer( QSharedPointer<QTmxMapLayer>p_layer);
    void addObjectLayer( QSharedPointer<QTmxObjectGroup>p_objectLayer);

    void initalizeGrafics( QQuickWindow *p_window, QQuickItem* p_parent);
    QSharedPointer<QTmxTile> queryTileByPosition(int x, int y, const QString &t_layerName);
    QSharedPointer<QTmxTileset> queryTileset( const QString& t_name);
    QSharedPointer<QTmxMapLayer>queryLayer( const QString& p_layerName);
    QVector<QSharedPointer<QTmxTile> >querySourundingTiles( int p_tile, const QString& p_layerName);

    void update();

signals:

public slots:

private:
    EOrientation m_orientation;
    eRenderOder m_renderOrder = e_right_down;
    int m_width;
    int m_height;
    int m_tileWidth;
    int m_tileHeigth;
    QVector<QSharedPointer<QTmxObjectGroup> >m_objectGroups;
    QVector<QSharedPointer<QTmxTileset> >m_tileSets;
    QVector<QSharedPointer<QTmxMapLayer> >m_layers;
};

#endif // QTMXTILEMAP_H
