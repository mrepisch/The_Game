#include "OpenGlWindow.h"
#include <QTimer>
#include <Mesh.h>
OpenGlWindow::OpenGlWindow(QWindow *parent) : QWindow(parent)
{
    setSurfaceType(OpenGLSurface);

    QSurfaceFormat a_format;
    a_format.setDepthBufferSize(24);
    a_format.setMajorVersion(3);
    a_format.setMinorVersion(3);
    a_format.setSamples(2);
    a_format.setProfile(QSurfaceFormat::CoreProfile);
    resize(800,600);
    setFormat(a_format);
    create();
    m_context = new QOpenGLContext(this);
    m_context->setFormat(a_format);
    m_context->create();
    m_context->makeCurrent(this);
    initializeOpenGLFunctions();
    QTimer* a_timer = new QTimer(this);
    connect(a_timer, SIGNAL(timeout()),this, SLOT(update()));
    a_timer->start(16);


    Mesh* mesh = new Mesh("triangle");
    m_scene.addMesh(mesh);

}

OpenGlWindow::~OpenGlWindow()
{

}

void OpenGlWindow::render()
{
    m_context->makeCurrent(this);
    const qreal retinaScale = devicePixelRatio();
    glViewport(0, 0, width() * retinaScale, height() * retinaScale);

    m_scene.render();

    m_context->swapBuffers(this);
}

void OpenGlWindow::render(QPainter *painter)
{
    Q_UNUSED(painter);
}

void OpenGlWindow::update()
{
    render();
}

