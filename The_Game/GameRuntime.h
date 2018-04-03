#ifndef GAMERUNTIME_H
#define GAMERUNTIME_H


#include <QSharedPointer>
#include "QTmxTileMap.h"
#include <QQuickWindow>
#include <QTimer>
#include <QObject>
#include "Camera.h"
class GameRuntime : public QQuickWindow
{
    Q_OBJECT
public:
    GameRuntime();

    void setTileMap(QSharedPointer<QTmxTileMap>p_tilemap);

    void start();

    void end();

    QSharedPointer<Camera> getCamera();



private slots:
    void updateCycle();

private:

    void mouseReleaseEvent(QMouseEvent *event);

    QSharedPointer<Camera>m_cam;
    bool m_isRunning = false;
    QTimer m_gameLoop;
    QQuickWindow* m_mainWindow;
    QSharedPointer<QTmxTileMap>m_tileMap;
};

#endif // GAMERUNTIME_H
