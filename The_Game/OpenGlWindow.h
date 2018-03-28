#ifndef OPENGLWINDOW_H
#define OPENGLWINDOW_H
#include <QWindow>
#include <QOpenGLFunctions>
#include <QOpenGLContext>
#include <QOpenGLPaintDevice>

#include "Scene.h"

class OpenGlWindow : public QWindow, public QOpenGLFunctions
{
    Q_OBJECT
public:
    OpenGlWindow(QWindow *parent = 0);
    ~OpenGlWindow();
    void render();
    void render(QPainter *painter);

public slots:
    void update();
    void renderLater();
    void renderNow();

private:
    QOpenGLContext *m_context;
    QOpenGLPaintDevice *m_device;
    Scene m_scene;
};

#endif // OPENGLWINDOW_H
