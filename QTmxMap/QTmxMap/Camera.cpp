// External include
#include <QSGTransformNode>
#include <QDebug>

// Internal includes
#include "Camera.h"

Camera::Camera(QQuickItem *parent) : QQuickItem(parent) {
  cameraNode_ = new QSGTransformNode();
}

QSGNode* Camera::updatePaintNode(QSGNode *node, QQuickItem::UpdatePaintNodeData *) {
  return cameraNode_;
}

