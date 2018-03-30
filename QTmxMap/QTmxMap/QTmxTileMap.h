#ifndef QTMXTILEMAP_H
#define QTMXTILEMAP_H

#include <QObject>
#include "QTmxTileSet.h"
#include "QTmxObjectGroup.h"
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

    void addTileSet( QSharedPointer<QTmxTileSet>p_tileSet);
    void addTileLayer( );
    void addObjectLayer( QSharedPointer<QTmxObjectGroup>p_objectLayer);
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
    QVector<QSharedPointer<QTmxTileSet> >m_tileSets;

};

#endif // QTMXTILEMAP_H
