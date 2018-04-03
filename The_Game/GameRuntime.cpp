#include "GameRuntime.h"
#include <QTmxTile.h>
#include <QDebug>
GameRuntime::GameRuntime() : QQuickWindow()
{
    m_cam = QSharedPointer<Camera>(new Camera(contentItem()));
    connect(&m_gameLoop, SIGNAL(timeout()),this, SLOT(updateCycle()) );

}

void GameRuntime::setTileMap(QSharedPointer<QTmxTileMap> p_tilemap)
{
    m_tileMap = p_tilemap;
}

void GameRuntime::start()
{
    m_isRunning = true;
    m_gameLoop.start(16);
}

void GameRuntime::end()
{
    m_isRunning = false;
    m_gameLoop.stop();
}

QSharedPointer<Camera> GameRuntime::getCamera()
{
    return m_cam;
}


void GameRuntime::updateCycle()
{
    m_tileMap->update();
    m_cam->update();
    update();
}

void GameRuntime::mouseReleaseEvent(QMouseEvent *event)
{
    QSharedPointer<QTmxTile>a_startTile = m_tileMap->queryTileByPosition(event->x(), event->y(),QStringLiteral("mainLayer"));
    if( !a_startTile.isNull())
    {
    auto a_tile = m_tileMap->querySourundingTiles( a_startTile->getFieldId(), "mainLayer" );
    auto a_tileset = m_tileMap->queryTileset(QStringLiteral("Tileset"));

        if( !a_tileset.isNull())
        {
            for( int i = 0; i < a_tile.size(); ++i)
            {
                if( !a_tile[i].isNull())
                {
                    a_tile[i]->setNewTexture( a_tileset->getTextureForTile(147),m_cam.data()  );
                }
            }
        }
    }

}
