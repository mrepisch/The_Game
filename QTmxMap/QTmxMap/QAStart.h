#ifndef QASTART_H
#define QASTART_H
#include <QVector>
#include <QTmxTileMap.h>
#include "qtmxmap_global.h"
class QTMXMAPSHARED_EXPORT QAStart
{
public:
    static QVector<int>FindPath(int startTile,int endTile,const QTmxTileMap* t_tilemap);

};

#endif // QASTART_H
