#ifndef QTMXOBJECTGROUP_H
#define QTMXOBJECTGROUP_H

#include <QObject>
#include <QVector>
#include <QSharedPointer>
#include "qtmxmap_global.h"
#include <QTmxObject.h>


class QTMXMAPSHARED_EXPORT QTmxObjectGroup : public QObject
{
    Q_OBJECT
public:
    explicit QTmxObjectGroup(const QString& p_name, QObject *parent = 0);

    void addObject( QSharedPointer<QTmxObject>p_object);
    QSharedPointer<QTmxObject> getObject( int id);
    void addProperties( QHash<QString,QString>p_properties);
    const QHash<QString,QString>getProperties();
    const QString& getName();
    void update();
signals:

public slots:

private:
    QVector<QSharedPointer<QTmxObject> >m_objects;
    QHash<QString,QString>m_properties;
    QString m_name;
};

#endif // QTMXOBJECTGROUP_H
