// External includes
#include <QSGSimpleTextureNode>
#include <QDebug>
// Internal includes
#include "Tile.h"



Tile::Tile(QQuickItem* const parent) : QQuickItem(parent) {
  setFlag(QQuickItem::ItemHasContents, true);
  textureNode_ = NULL;
}

Tile::~Tile() {}

void Tile::setTexture(QSGTexture *texture) {
  if(textureNode_ != NULL) {
    textureNode_->setTexture(texture);
  }
}

void Tile::setTextureNode(QSGSimpleTextureNode *textureNode) {
  textureNode_ = textureNode;
}

void Tile::setRect(const QRectF rect) {
  if(textureNode_ != NULL) {
    textureNode_->setRect(rect);
  }
}

QRectF Tile::getRect() const {

  if(textureNode_ != NULL) {
    return textureNode_->rect();
  }
  return QRectF();
}

QSGNode* Tile::updatePaintNode(QSGNode* oldNode, QQuickItem::UpdatePaintNodeData*) {

  return textureNode_;
}


