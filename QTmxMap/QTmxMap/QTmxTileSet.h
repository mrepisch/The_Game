#ifndef QTMXTILESET_H
#define QTMXTILESET_H

#include <QObject>
#include <QHash>
#include <QVector>
#include <QString>
#include <QScopedPointer>
#include "TextureAtlas.h"

class QQuickWindow;
class QSGTexture;


class QTmxTileSet : public QObject
{
    Q_OBJECT
public:
    explicit QTmxTileSet(const QString& t_name, int tileWidth, int tileHeight, int tileCount, QObject *parent = 0);
    void addImage(const QString& t_path, int width, int height, QQuickWindow *p_window);
    void addTileData(int t_id, QHash<QString,QString>a_attributes);
    const QHash<QString,QString>getTileData( int t_id);
    QSGTexture* getTextureForTile( int t_id);

signals:

public slots:

private:

    struct STileSetTileData
    {
        int id;
        QHash<QString,QString>a_attributes;
    };

    QString m_name;
    int m_tileWidth;
    int m_tileHeight;
    int m_tileCount;
    QScopedPointer<TextureAtlas> m_atlas;
    QVector<STileSetTileData*>m_tileData;
};

#endif // QTMXTILESET_H
