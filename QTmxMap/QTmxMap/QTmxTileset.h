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


class QTmxTileset : public QObject
{
    Q_OBJECT
public:
    explicit QTmxTileset(int t_firstId, const QString& t_name, int tileWidth, int tileHeight, int tileCount, QObject *parent = 0);
    void addImage(const QString& t_path, int width, int height, QQuickWindow *p_window);
    void addTileData(int t_id, QHash<QString,QString>a_attributes);
    const QHash<QString,QString>getTileData( int t_id) const;
    QSGTexture* getTextureForTile( int t_id) const;

    const QString& name() const;
    int tileWidth() const;
    int tileHeight() const;


signals:

public slots:

private:

    struct STileSetTileData
    {
        int id;
        QHash<QString,QString>a_attributes;
    };
    int m_firstId;
    QString m_name;
    int m_tileWidth;
    int m_tileHeight;
    int m_tileCount;
    QScopedPointer<TextureAtlas> m_atlas;
    QVector<STileSetTileData*>m_tileData;
};

#endif // QTMXTILESET_H
