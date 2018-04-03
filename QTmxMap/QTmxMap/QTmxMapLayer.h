#ifndef QTMXMAPLAYER_H
#define QTMXMAPLAYER_H

#include <QObject>
#include <QTmxTile.h>

class QTmxTileset;


class QTmxMapLayer : public QObject
{
    Q_OBJECT
public:
    explicit QTmxMapLayer(const QString& p_name, int width, int height, QObject *parent = 0);
    ~QTmxMapLayer();
    void setTileData(const QString& t_tiles);
    void addProperties( const QHash<QString,QString>& p_props);
    void initTileGrafic(QQuickItem* p_parent, const QTmxTileset* p_tileset);
    const QHash<QString,QString>& getProps();
    int width() const;
    int height() const;
    const QString& name()const;
    void update();
    QSharedPointer<QTmxTile> queryTileByPosition(int x, int y);
    QVector<QSharedPointer<QTmxTile> > querySourundings(int p_tile) const;
    QSharedPointer<QTmxTile>queryTileByFieldID( int p_fieldId) const;


signals:

public slots:

private:
    QHash<QString,QString>m_properties;
    QString m_name;
    int m_width;
    int m_height;
    QString m_tileData;
    QVector<QSharedPointer<QTmxTile> >m_tiles;
};

#endif // QTMXMAPLAYER_H
