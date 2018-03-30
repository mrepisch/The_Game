#ifndef QTXMMAPLAYER_H
#define QTXMMAPLAYER_H

#include <QObject>
#include <QVector>
#include "RenderItem.h"

typedef QVector<QVector<RenderItem> > TileArray;

class QTxmMapLayer : public QObject
{
    Q_OBJECT
public:
    explicit QTxmMapLayer(int tileCountX, int tilecountY,QObject *parent = 0);

signals:

public slots:

private:
    TileArray m_tiles;
};

#endif // QTXMMAPLAYER_H
