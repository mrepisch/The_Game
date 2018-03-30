#ifndef TMXMAPDATA_H
#define TMXMAPDATA_H

// External includes
#include <QHash>
#include <QList>
#include <QString>
#include <QPointF>

// Internal includes
#include "TmxReader.h"
#include "qtmxmap_global.h"

//! Structure to store the object data in it
/*!
 Xml structure of the object data:
<object id="7" type="coin" x="500" y="268" width="54" height="42">
   <properties>
    <property name="collision" value="isstatic=true;block=true"/>
    <property name="object" value="type=coin"/>
    <property name="render" value="texture=coin.png;zindex=1"/>
   </properties>
  </object>
 */
struct SObjectData {
  QHash<QString,QString>objectAttributes;
  QList<QHash<QString,QString> >propertys;
  QList<QPointF>points;
}typedef STileObjectData;

//! Structure to store the tile data in it
/*!
 Xml Structure of the tile data:
  <tile id="43">
   <properties>
    <property name="collision" value="isstatic=true;block=true;sendevent=false"/>
   </properties>
    <object id="7" type="coin" x="500" y="268" width="54" height="42">
      <properties>
        <property name="render" value="texture=coin.png;zindex=1"/>
      </properties>
    </object>
  </tile>
 */
struct STileData {
  QString tileID;
  QList<QHash<QString,QString> > propertys;
  QList<SObjecGrouptData*> objectData;
} typedef STileData;

//! Structure of the tileset data
/*!
 Xml structure of the tilesetdata
  <tileset firstgid="1" name="Tileset" tilewidth="64" tileheight="64" tilecount="80" columns="8">
    <image source="tilesets/Tileset.png" width="512" height="640"/>
    <tile id="1"></tile>
    <tile id="2"></tile>
    <tile id="3"></tile>
    ...
  </tileset>
 */
struct STilesetData {
  QHash<QString,QString> attributes;
  QHash<QString,QString> image;
  QList<STileData*> tileData;
} typedef STilesetData;

//! Strcture to store the layerdata
/*!
 Xml strcture of the layer:
 <layer name="background" width="50" height="10">
  <data encoding="csv">
    26,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    26,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    26,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    26,0,0,0,0,0,0,0,0,0,0,0,0,0,0,44,10,47,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    26,0,0,0,0,0,0,0,0,0,39,39,0,0,44,10,45,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    26,0,0,0,0,10,10,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    26,10,10,10,10,18,18,10,10,11,0,0,0,10,10,10,10,10,10,10,10,10,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,26,0,0,0,26,18,18,18,18,18,18,18,18,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,26,0,0,0,26,18,18,26,18,18,18,18,18,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,26,0,0,0,26,18,18,18,18,18,18,18,18,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
  </data>
 </layer>
 */
struct SLayerData {
  QHash<QString,QString> layerAttributes;
  QList<QHash<QString,QString> > propertys;
  QList<int> tilesID;
  int zindex;
} typedef SLayerData;

//! Structure to store objectgroup data
/*!
 <objectgroup name="Objektebene 2">
  <object id="7" type="coin" x="500" y="268" width="54" height="42">
   <properties>
    <property name="collision" value="isstatic=true;block=true"/>
    ...
   </properties>
  </object>
  <object id="9" name="coin" type="coin" x="1003" y="109" width="54" height="42">
   <properties>
    <property name="collision" value="isstatic=true;block=true"/>
    ...
   </properties>
  </object>
  ...
 </objectgroup>
 */
struct SObjecGrouptData {
  QList<QHash<QString,QString > >propertys;
  QHash<QString,QString>attributes;
  QList<SObjectData*>objects;
  int zindex;
};

//! This class holds the Data of a TMX map
/*!
  This class holds the Data of a TMX map.
  You are able to acces the data from the getters.
  The TmxReader class loads the data into the class.
  For this reasion the TmxReader class is a friend of this class.
  The reasion for this is that we can acces the private members directly
*/
class QTMXMAPSHARED_EXPORT TmxMapData {
public:
  //!Default Konstruktor
  TmxMapData();

  //! Destructor
  ~TmxMapData();

  //! Getter to acces the mapattribute data
  QHash<QString,QString>getMapAttributes();

  //! Getter for accesing the tileset data
  QHash<QString,STilesetData*>getTilesetData();

  //! Getter for accesing the layerdata
  QHash<QString,SLayerData*>getLayerData();

  //! Getter for accesing the objectgroup data
  QList<SObjecGrouptData*>getObjectGroups();

private:
  //Frend deklaration
  friend class TmxReader;

  //QHash with the map attributes. Key = attributename, value = attributvalue
  QHash<QString,QString>mapAttributes_;

  //QHash with the tilesetdata. Key = tilesetname, value = tilesetdata structure
  QHash<QString,STilesetData*>tilesetData_;

  //QHash with the layerdata. Key = layername, value = layerdata structure
  QHash<QString,SLayerData*>layers_;

  //QList with the Object Group data
  QList<SObjecGrouptData*>objectGroups_;

};



#endif // TMXMAPDATA_H
