// External includes
#include <QSGSimpleTextureNode>
#include <QDebug>
// Internal includes
#include "RenderItem.h"



RenderItem::RenderItem(QQuickItem* const parent) : QQuickItem(parent) {
  setFlag(QQuickItem::ItemHasContents, true);
  textureNode_ = NULL;
  m_texture = NULL;
}

RenderItem::~RenderItem() {}

void RenderItem::setTexture(QSGTexture *texture) {
  if( texture != NULL)
  {
      if( textureNode_ == NULL)
      {
          textureNode_ = new QSGSimpleTextureNode();
      }
      m_texture = texture;
  }
}

void RenderItem::setTextureNode(QSGSimpleTextureNode *textureNode) {
  textureNode_ = textureNode;
}

void RenderItem::setRect(const QRectF rect) {
    m_rect = rect;
}

QRectF RenderItem::getRect() const {
    return m_rect;
}

QSGNode* RenderItem::updatePaintNode(QSGNode* oldNode, QQuickItem::UpdatePaintNodeData*) {

  if(textureNode_!= NULL, m_texture != NULL)
  {
    textureNode_->setTexture(m_texture);
    textureNode_->setRect(m_rect);
  }

  return textureNode_;
}


