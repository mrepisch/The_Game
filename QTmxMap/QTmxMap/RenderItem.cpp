// External includes
#include <QSGSimpleTextureNode>
#include <QDebug>
// Internal includes
#include "RenderItem.h"



RenderItem::RenderItem(QQuickItem* const parent) : QQuickItem(parent) {
  setFlag(QQuickItem::ItemHasContents, true);
  textureNode_ = NULL;
}

RenderItem::~RenderItem() {}

void RenderItem::setTexture(QSGTexture *texture) {
  if(textureNode_ != NULL) {
    textureNode_->setTexture(texture);
  }
}

void RenderItem::setTextureNode(QSGSimpleTextureNode *textureNode) {
  textureNode_ = textureNode;
}

void RenderItem::setRect(const QRectF rect) {
  if(textureNode_ != NULL) {
    textureNode_->setRect(rect);
  }
}

QRectF RenderItem::getRect() const {

  if(textureNode_ != NULL) {
    return textureNode_->rect();
  }
  return QRectF();
}

QSGNode* RenderItem::updatePaintNode(QSGNode* oldNode, QQuickItem::UpdatePaintNodeData*) {

  return textureNode_;
}


