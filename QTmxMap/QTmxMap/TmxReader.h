#ifndef TMXREADER_H
#define TMXREADER_H

//External includes
#include <QXmlStreamReader>
#include <QHash>
#include <QString>

#include "qtmxmap_global.h"

// Internal forward declarations
class TmxMapData;
struct SLayerData;
struct STileData;
struct SObjecGrouptData;
struct SObjectData;

//! An Tmx File Reader Class
/*!
  This class reads all the Data from a TMX file(Tiled Leveleditor
  and stores the Data in a TmxMapData Object.
  This class is a friend class of TmXMapData
*/
class QTMXMAPSHARED_EXPORT TmxReader {
public:

  //! Constructor
  TmxReader();

  //! \param tmxFile, path to the tmxFile
  /*!
    \param tmxFile The path of the tmx file
    \return TmxDataMap object pointer
  */
  TmxMapData* readTmxFile(const QString& tmxFile);

private:
  //! Reads all the Attributes from a Tag
  QHash<QString,QString> readAttributes();

  //! Reads the data from the <tileset> tag
  STileData* readTileFromTileset( void);

  //! Reads the data from the <layer> tag
  SLayerData* readLayerData( void );

  //! Reads the data from any <Objectgroup> tag
  SObjecGrouptData* readObjectGroupTag( void );

  //! Reads the data from the <propertys> tags
  QList<QHash<QString,QString> > readPropertys( void );

  //! Reads the data from any <object> tag
  SObjectData* readObject( void );

  //Stream Object to read the tmx xml file
  QXmlStreamReader xmlStream_;
};



#endif // TMXREADER_H
