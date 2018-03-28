#ifndef SCENE_H
#define SCENE_H


#include <QVector>
class Mesh;

class Scene
{
public:
    Scene();
    ~Scene();
    void update();

    void render();
    void resize(int width, int height);
    void addMesh( Mesh* p_mesh);

private:
    QVector<Mesh*>m_meshes;

};

#endif // SCENE_H
