#include "QTmxObject.h"

QTmxObject::QTmxObject(int p_id, const QString& p_name, const QString& p_type, int x, int y, int width, int height,  QObject *parent) : QObject(parent)
{
    m_id = p_id;
    m_name = p_name;
    m_type = p_type;
    m_rect.setRect(x,y,width,height);
}


void QTmxObject::addPropertys(const QHash<QString, QString> &p_properties)
{
    m_properties = p_properties;
}

const QString QTmxObject::getPropertyValue(const QString &t_name) const
{
    QString r_value;
    QHashIterator<QString,QString>a_iter(m_properties);
    while( a_iter.hasNext())
    {
        a_iter.next();
        if( a_iter.key() == t_name)
        {
            r_value = a_iter.value();
        }
    }
    return r_value;
}

const QStringList QTmxObject::getPropertyNames() const
{
    return m_properties.keys();
}

void QTmxObject::setTexture(const QString &t_texturePath)
{
    //TODO: IMPLEMENET
    //m_renderItem.reset( new RenderItem());
}

int QTmxObject::getId()
{
    return m_id;
}

const QRect &QTmxObject::getRect()
{
    return m_rect;
}

void QTmxObject::setPosition(int x, int y)
{
    m_rect.setX(x);
    m_rect.setY(y);
}

void QTmxObject::update()
{
    m_renderItem->update();
}
