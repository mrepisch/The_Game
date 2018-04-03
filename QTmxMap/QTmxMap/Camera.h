#ifndef CAMERA_H
#define CAMERA_H

// External includes
#include <QQuickItem>

// Internal includes
#include "qtmxmap_global.h"
// External forward declarations
class QSGTransformNode;


//! Camera class
/*!
 This class derived from QQUickitem and holds a QSGTransformNode.
 The node transforms every child QQUickItem of the Camera.
 Dont forget! If you want to move the camera on the x axis you shoud think about *-1 the x direction vector.
 */
class QTMXMAPSHARED_EXPORT Camera : public QQuickItem {
public:

  //! Constructor
  /*!
   \param parent the parent of the camare witch is usualy the contentItem of the QQUickWindow
   */
  Camera( QQuickItem* parent);

  //! Implementet updatefunction for QQUickItem
  QSGNode* updatePaintNode(QSGNode *node, UpdatePaintNodeData *);

private:

  //! Transaformations node pointer.
  QSGTransformNode* cameraNode_;
};


#endif // CAMERA_H
