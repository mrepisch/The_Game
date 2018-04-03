#include "QTmxObjectGroup.h"

QTmxObjectGroup::QTmxObjectGroup(const QString& p_name, QObject *parent) : QObject(parent)
{
    m_name = p_name;
}

void QTmxObjectGroup::addObject(QSharedPointer<QTmxObject> p_object)
{
    if( !p_object.isNull())
    {
        m_objects.append(p_object);
    }
}

QSharedPointer<QTmxObject> QTmxObjectGroup::getObject(int id)
{
    QSharedPointer<QTmxObject> r_object;
    foreach( QSharedPointer<QTmxObject> a_iter , m_objects)
    {
        if( a_iter->getId() == id)
        {
            r_object = a_iter;
        }
    }
    return r_object;
}

void QTmxObjectGroup::addProperties(QHash<QString, QString> p_properties)
{
    m_properties = p_properties;
}

const QHash<QString, QString> QTmxObjectGroup::getProperties()
{
    return m_properties;
}

const QString &QTmxObjectGroup::getName()
{
    return m_name;
}

void QTmxObjectGroup::update()
{
    foreach( QSharedPointer<QTmxObject>a_iter , m_objects){
        a_iter->update();
    }
}

