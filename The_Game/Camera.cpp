#include "Camera.h"

const float YAW = -90.0f;
const float PITCH = 0.0f;

Camera::Camera()
{

}

void Camera::setPosition(const QVector3D &t_newPos)
{
    m_pos = t_newPos;
}

void Camera::setRotation(const QVector3D &t_newRotation)
{
    m_rot = t_newRotation;
}

const QVector3D &Camera::getPosition()
{
    return m_pos;
}

const QVector3D &Camera::getRotation()
{
    return m_rot;
}

void Camera::update()
{

}

