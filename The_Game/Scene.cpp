#include "Scene.h"
#include "Mesh.h"
#include <QtMath>
Scene::Scene()
{

}

Scene::~Scene()
{
    qDeleteAll(m_meshes);
    m_meshes.clear();
}

void Scene::update()
{

}

void Scene::render()
{

    glClearColor(0.0f,0.0f,0.0f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    QMatrix4x4 matrix;
    matrix.perspective( 45.0f,(800/600),0.1f,100.0f);
    matrix.translate(0, 0, -5);
    //matrix.rotate(100.0f * m_frame / screen()->refreshRate(), 0, 1, 0);
    for( Mesh* a_mesh : m_meshes)
    {
        a_mesh->render(matrix);
    }
}

void Scene::resize(int width, int height)
{
    glViewport(0,0,width,height);
}

void Scene::addMesh(Mesh *p_mesh)
{
    if( p_mesh != nullptr)
    {
        m_meshes.append( p_mesh );
    }
}

