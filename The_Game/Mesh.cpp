#include "Mesh.h"

Mesh::Mesh()
{

}

Mesh::Mesh(const QString &t_basicPrimitive)
{
    if( t_basicPrimitive == QStringLiteral("triangle"))
    {
        loadTriangle();
    }
}

void Mesh::render(const QMatrix4x4 &t_projection)
{
    m_shader.bind();
    m_shader.setUniformValue(m_shaderAttributes.value(QStringLiteral("projection")), t_projection);
    glDrawArrays(GL_TRIANGLES, 0 ,3);

}



void Mesh::loadTriangle()
{
    m_shader.addShaderFromSourceFile(QOpenGLShader::Vertex, QStringLiteral("basic_vertex.sha"));
    m_shader.addShaderFromSourceFile( QOpenGLShader::Fragment, QStringLiteral("basic_fragment.sha"));
    float a_posData[] = {
        -0.8f,0.8f,0.0f,
        0.8f,0.8f,0.0f,
        0.0f,0.8f,0.0f
    };
    float a_colorData[] = {
        1.0f,0.0f,0.0f,
        0.0f,1.0f,0.0f,
        0.0f,0.0f,1.0f
    };

    m_shader.link();
    m_shader.bind();
    m_vertexPosition.create();
    m_vertexPosition.setUsagePattern(QOpenGLBuffer::StaticDraw);
    m_vertexPosition.bind();
    m_vertexPosition.allocate(a_posData, 3*3*sizeof(float));

    m_vertexColor.create();

    m_vertexColor.setUsagePattern(QOpenGLBuffer::StaticDraw);
    m_vertexColor.bind();
    m_vertexColor.allocate(a_colorData, 3*3*sizeof(float));



    m_vao.create();
    m_vao.bind();
    m_shader.enableAttributeArray(m_vertexPosition.bufferId());
    m_shader.enableAttributeArray(m_vertexColor.bufferId());
    m_shader.setAttributeBuffer(m_vertexPosition.bufferId(), GL_FLOAT, 0, 3*3*sizeof(float));
    m_shader.setAttributeBuffer(m_vertexColor.bufferId(), GL_FLOAT, 0, 3*3*sizeof(float));
    m_shaderAttributes.insert(QStringLiteral("projection"),m_shader.uniformLocation("projection"));
    m_vao.release();
    m_vertexPosition.release();
    m_vertexColor.release();
    m_shader.release();
}

