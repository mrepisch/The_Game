#ifndef QTMXOBJECT_H
#define QTMXOBJECT_H

#include <QObject>
#include <QHash>
#include <QString>
#include <QStringList>
#include <QRectF>
#include "RenderItem.h"
class QTmxObject : public QObject
{
    Q_OBJECT
public:
    explicit QTmxObject( int p_id, const QString& p_name, const QString& p_type, int x, int y, int width, int height, QObject *parent = 0);
    void addPropertys( const QHash<QString, QString>& p_properties);
    const QString getPropertyValue( const QString& t_name) const;
    const QStringList getPropertyNames() const;
    void setTexture( const QString& t_texturePath);
    int getId();
    const QRect& getRect();
    void setPosition( int x, int y);

signals:

public slots:

private:
    QHash<QString,QString>m_properties;
    int m_id;
    QRect m_rect;
    QString m_name;
    QString m_type;
    QScopedPointer<RenderItem> m_renderItem;
};

#endif // QTMXOBJECT_H


