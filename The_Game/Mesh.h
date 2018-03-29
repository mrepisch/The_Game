#ifndef MESH_H
#define MESH_H

#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>
#include <QOpenGLShaderProgram>
#include <QString>
#include <QHash>
#include <QMatrix4x4>
#include <QVector3D>
class Mesh
{
public:
    Mesh();
    Mesh(const QString& t_basicPrimitive);

    void render(const QMatrix4x4& t_projection);



private:
    void loadTriangle();
    QVector3D m_pos;
    QVector3D m_scl;
    QVector3D m_rot;
    QOpenGLVertexArrayObject m_vao;
    QOpenGLBuffer m_vertexPosition;
    QOpenGLBuffer m_vertexColor;
    QOpenGLShaderProgram m_shader;

    QHash<QString,int>m_shaderAttributes;
};

#endif // MESH_H
