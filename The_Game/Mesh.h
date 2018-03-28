#ifndef MESH_H
#define MESH_H

#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>
#include <QOpenGLShaderProgram>
#include <QString>
#include <QHash>
#include <QMatrix4x4>
class Mesh
{
public:
    Mesh();
    Mesh(const QString& t_basicPrimitive);

    void render(const QMatrix4x4& t_projection);

private:
    void loadTriangle();

    QOpenGLVertexArrayObject m_vao;
    QOpenGLBuffer m_vertexPosition;
    QOpenGLBuffer m_vertexColor;
    QOpenGLShaderProgram m_shader;

    QHash<QString,int>m_shaderAttributes;
};

#endif // MESH_H
