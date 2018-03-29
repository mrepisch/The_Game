#ifndef CAMERA_H
#define CAMERA_H

#include <QVector3D>
class Camera
{
public:
    Camera();

    void setPosition( const QVector3D& t_newPos);
    void setRotation( const QVector3D& t_newRotation);
    const QVector3D& getPosition();
    const QVector3D& getRotation();

    void update();
private:
    QVector3D m_pos;
    QVector3D m_rot;
    float m_yaw;
    float m_pitch;
    float m_front;
    float m_right;
    float m_worldUp;
};

#endif // CAMERA_H
