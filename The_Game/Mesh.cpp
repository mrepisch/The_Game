#include "Mesh.h"

Mesh::Mesh()
{

}

Mesh::Mesh(const QString &t_basicPrimitive)
{
    if( t_basicPrimitive == QStringLiteral("triangle"))
    {
        loadTriangle();
        m_pos.setZ(10.0f);
        m_scl.setY(2.0f);
    }
}

void Mesh::render(const QMatrix4x4 &t_projection)
{
    QMatrix4x4 a_modelMat;
    a_modelMat.translate(m_pos);
    a_modelMat.scale(m_scl);

    bool a_succes = true;
    a_succes &= m_shader.bind();
    if( a_succes )
    {
        m_vao.bind();
        m_shader.setUniformValue("projection",t_projection);
        //m_shader.setUniformValue("model",a_modelMat);
        glDrawArrays(GL_TRIANGLES, 0, 3);

    }
    //m_vao.release();
    //m_shader.release();
}



void Mesh::loadTriangle()
{
    m_shader.addShaderFromSourceFile(QOpenGLShader::Vertex, QStringLiteral("../The_Game/basic_vertex.sha"));
    m_shader.addShaderFromSourceFile( QOpenGLShader::Fragment, QStringLiteral("../The_Game/basic_fragment.sha"));

    m_shader.link();


    float a_posData[] = {
        -1.0f, -1.0f, 0.0f,
         1.0f, -1.0f, 0.0f,
         0.0f,  1.0f, 0.0f
};
    float a_colorData[] = {
        1.0f,0.0f,0.0f,
        0.0f,1.0f,0.0f,
        0.0f,0.0f,1.0f
    };

    bool a_succes = true;

    a_succes &= m_vao.create();
    m_vao.bind();

    if( m_vao.isCreated())
    {
        m_vertexPosition = QOpenGLBuffer(QOpenGLBuffer::VertexBuffer);
        a_succes &= m_vertexPosition.create();
        m_vertexPosition.setUsagePattern(QOpenGLBuffer::StaticDraw);
        a_succes &= m_vertexPosition.bind();
        m_vertexPosition.allocate(a_posData, 9*sizeof(float));

        m_shader.bind();
        m_vertexPosition.bind();
        m_shader.enableAttributeArray("vertex");
        m_shader.setAttributeBuffer("vertex", GL_FLOAT,0,3);
    }




}

