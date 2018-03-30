// External includes
#include <QSGTexture>
#include <QFile>
#include <QDebug>
// Internal includes
#include "TextureAtlas.h"



TextureAtlas::TextureAtlas(QQuickWindow* window , const QString &texturePath, int tileWidth, int tileheight, int startID) {
  if(QFile::exists(texturePath)) {
    texture = QImage(texturePath);
    int x = 0;
    int y = 0;
    startID_ = startID;
    int amoutOfTiles = (texture.width() / tileWidth) * (texture.height() / tileheight);
    for(int i = 0; i < amoutOfTiles ; ++i ) {
      atlas_.insert(i + startID, window->createTextureFromImage(texture.copy(x,y,tileWidth,tileheight)));
      x += tileWidth;
      if( x >= texture.width() ) {
        x = 0;
        y += tileheight;
      }
    }
  }else {
    qDebug()<<"Textureatlas : Tilesetspath dosent extist";
  }
}

QSGTexture *TextureAtlas::getTextureNode(int index) {
  QSGTexture* node = NULL;
  if(atlas_.contains(index)) {
    node = atlas_.value(index);
  }
  return node;
}

bool TextureAtlas::hasIndex(int index) {
  return atlas_.contains(index);
}

int TextureAtlas::getStartID() {
  return startID_;
}

int TextureAtlas::getEndID() {
  return atlas_.size();
}

