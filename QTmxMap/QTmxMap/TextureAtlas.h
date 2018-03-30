#ifndef TEXTUREATLAS_H
#define TEXTUREATLAS_H

//Internal includes

//external Includes
#include <QMap>
#include <QImage>
#include <QSGSimpleTextureNode>
#include <QQuickWindow>

#include "qtmxmap_global.h"



//! An textureatlas Class
/*!
 This class loads a QImage and generates subimages and stores them in a QMap.
 You can acces the atlas with a int as index. 0 = top left corner of the texture.
 To create an texture you have to use the QQUickWindow::createTextureFromImage() function
 */
class  QTMXMAPSHARED_EXPORT TextureAtlas {
public:
  //! konstruktor
  /*!
   * \param window, the QQUickWindow
   * \param texturePath, the path to the texture
   * \param tileWidth, the width of the tile
   * \param tileheight, the height of the tile
   */
  TextureAtlas( QQuickWindow* window, const QString& texturePath, int tileWidth, int tileheight, int startID );

  //! Get a Texture from the atlas
  /*!
   * \param index, the index of the Texture
   * \return QSGSimpleTextureNode Pointer or nullptr if there is no Texture with the given index
   */
  QSGTexture* getTextureNode( int index );

  //!Returns if this index is in the textureatlas
  bool hasIndex( int index );

  //!Returns the first ID in the atlas
  int getStartID( void );

  //! Returns the last ID int the atlas;
  int getEndID( void );

private:

  // The texture atlas
  QMap<int,QSGTexture*>atlas_;

  // The QImage object with the whole texture.
  QImage texture;

  //  The first id witch is stored in the atlas_ map
  int startID_;
};


#endif // TEXTUREATLAS_H
