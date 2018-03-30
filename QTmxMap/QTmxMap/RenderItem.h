#ifndef Tile_H
#define Tile_H

// External includes
#include <QQuickItem>
#include <QSGTexture>

// External forward declarations
class QSGSimpleTextureNode;


//! A render item class.
/*!
  A render item is a visual item and is rendered using the scene graph.
*/
class RenderItem : public QQuickItem {
 public:
  //! A constructor.
  /*!
    \param parent The parent render item.
    \param textureNode A texture node.
  */
  RenderItem(QQuickItem* const parent);

  //! A destructor.
  virtual ~RenderItem();

  //! Sets the texture of the texture node.
  /*!
    \param texture A texture.
  */
  void setTexture(QSGTexture* const texture);

  //! Sets the texture node.
  /*!
    \param texture A texture node.
  */
  void setTextureNode(QSGSimpleTextureNode* textureNode);

  //! Sets the rectangle.
  /*!
    \param rect A rectangle.
  */
  void setRect(const QRectF rect);

  //! Gets the rectangle of the texture node.
  /*!
    \return A rectangle.
  */
  QRectF getRect() const;


  //! protected Implementation of the QuickItem
  //! This function will get the call id in every frame of the window.
  //! If you want to change anything in the Object to render it has to be done in this methode.
  //! To change somthing you have to override to oldNode pointer with a new Node oder and return the new node
  //! or you can also just manupulate the old node to make the object changing colors for example.
  QSGNode* updatePaintNode(QSGNode* oldNode, QQuickItem::UpdatePaintNodeData*);

 private:
  // Disables the use of copy constructors and assignment operators.
  Q_DISABLE_COPY(RenderItem);

  // Holds a texture node.
  QSGSimpleTextureNode* textureNode_;
};


#endif // Tile_H
