// Internal Include
#include "TmxReader.h"
#include "TmxMapData.h"

// External Includes
#include <QFile>
#include <QXmlStreamAttributes>
#include <QDebug>
#include <QStringList>


TmxReader::TmxReader() {}

TmxMapData *TmxReader::readTmxFile(const QString& tmxFile) {
  QFile xmlFile(tmxFile);
  xmlFile.open(QIODevice::ReadOnly);
  xmlStream_.setDevice(&xmlFile);
  TmxMapData* mapData = new TmxMapData();
  STilesetData* tilesetData = NULL;
  int zindexCounter = 0;
  while( xmlStream_.readNext() && !xmlStream_.atEnd() ) {
    if(xmlStream_.isStartElement()) {
      if(xmlStream_.name() == QStringLiteral("map")) {
        mapData->mapAttributes_ = readAttributes();
      }
      else if(xmlStream_.name() ==  QStringLiteral("tileset")) {
        tilesetData = new STilesetData();
        tilesetData->attributes = readAttributes();
        mapData->tilesetData_.insert(tilesetData->attributes[ QStringLiteral("name") ],tilesetData);
      }
      else if(xmlStream_.name() == QStringLiteral("image") && tilesetData != NULL) {
        tilesetData->image = readAttributes();
      }
      else if(xmlStream_.name() == QStringLiteral("tile")) {
        if(tilesetData != NULL){
          tilesetData->tileData.append(readTileFromTileset());
        }
      }
      else if( xmlStream_.name() == QStringLiteral("layer")) {
        SLayerData* layer = readLayerData();
         ++ zindexCounter;
        layer->zindex = zindexCounter;
        mapData->layers_.insert(layer->layerAttributes[QStringLiteral("name")],layer);
      }
      else if( xmlStream_.name() == QStringLiteral("objectgroup")) {
        SObjecGrouptData* objectgroup = readObjectGroupTag();
         ++ zindexCounter;
        objectgroup->zindex = zindexCounter;
        mapData->objectGroups_.append(objectgroup);
      }
    }
  }
  return mapData;
}

QHash<QString, QString> TmxReader::readAttributes() {
  QHash<QString,QString>attributes;
  QXmlStreamAttributes attr = xmlStream_.attributes();
  for( int i = 0; i < attr.size(); ++i ) {
      attributes.insert(attr.at(i).name().toString(), attr.at(i).value().toString());
  }
  return attributes;
}

STileData* TmxReader::readTileFromTileset( void ) {
  STileData* data = new STileData();
  bool isAtEnd = false;
  QHash<QString,QString>attributes = readAttributes();
  data->tileID = attributes.value(QStringLiteral("id"));
  SObjecGrouptData* objectData = NULL;
  do {
    if(xmlStream_.isStartElement()) {
      if(xmlStream_.name() == QStringLiteral("property")) {
        data->propertys.append(readAttributes());
      }
      else if(xmlStream_.name() == QStringLiteral("objectgroup")) {
        objectData = readObjectGroupTag();
      }
    }
    if(xmlStream_.name() == QStringLiteral("tile") && xmlStream_.isEndElement()) {
      isAtEnd = true;
      if( objectData != NULL) {
        data->objectData.append(objectData);
      }
    }
  } while(xmlStream_.readNext() && !isAtEnd);
  return data;
}

SLayerData *TmxReader::readLayerData(void) {
  SLayerData* data = new SLayerData();
  data->layerAttributes = readAttributes();
  bool isAtEnd = false;
  do {
    if( xmlStream_.isStartElement()) {
      if( xmlStream_.name() == QStringLiteral("data")) {
        QString text = xmlStream_.readElementText();
        QStringList tilesSplit = text.split(QStringLiteral(","));
        for(int i = 0; i < tilesSplit.size(); ++i) {
          data->tilesID.append(tilesSplit.at(i).toInt());
        }
      }
     else if(xmlStream_.name() == QStringLiteral("property")) {
        data->propertys.append(readAttributes());
      }
    }
    if(xmlStream_.name() == QStringLiteral("layer") && xmlStream_.isEndElement()) {
      isAtEnd = true;
    }
  } while(xmlStream_.readNext() && !isAtEnd);
  return data;
}

SObjecGrouptData *TmxReader::readObjectGroupTag() {
  bool isAtEnd = false;
  SObjecGrouptData* data = new SObjecGrouptData();
  data->attributes = readAttributes();
  while( xmlStream_.readNext() && !isAtEnd) {
    if(xmlStream_.isStartElement()) {
      if(xmlStream_.name() == QStringLiteral("properties")) {
        data->propertys = readPropertys();
      }
      else if( xmlStream_.name() == QStringLiteral("object")){
        data->objects.append( readObject() );
      }
    }
    if(xmlStream_.name() == QStringLiteral("objectgroup") && xmlStream_.isEndElement()) {
      isAtEnd = true;
    }
  }
  return data;
}

QList<QHash<QString,QString> > TmxReader::readPropertys() {
  QList<QHash<QString,QString> > props;
  bool isAtEnd = false;
  do {
    if( xmlStream_.isStartElement()) {
      if( xmlStream_.name() == QStringLiteral("property")) {
        props.append(readAttributes());
      }
    }
    if( xmlStream_.name() == QStringLiteral("properties") && xmlStream_.isEndElement()) {
      isAtEnd = true;
    }
  } while(xmlStream_.readNext() && !isAtEnd);
  return props;
}

SObjectData *TmxReader::readObject() {
  SObjectData* data = new SObjectData();
  bool isAtEnd = false;
  do {
    if(xmlStream_.isStartElement()) {
      if(xmlStream_.name() ==QStringLiteral( "object")) {
        data->objectAttributes = readAttributes();
      }else if(xmlStream_.name() == QStringLiteral("polyline")){
        QString strpoint = readAttributes()[QStringLiteral("points")];
        QStringList pointSplit = strpoint.split(" ");
        for( int i = 0; i < pointSplit.size(); ++i ) {
          data->points.append(QPointF(pointSplit.at(i).split(QStringLiteral(",")).at(0).toFloat(),pointSplit.at(i).split(",").at(1).toFloat()));
        }
      }
      else if(xmlStream_.name() == QStringLiteral("properties")) {
        data->propertys = readPropertys();
      }
    }
    if(xmlStream_.name() == QStringLiteral("object") && xmlStream_.isEndElement()) {
      isAtEnd = true;
    }
  } while(xmlStream_.readNext() && !isAtEnd);
  return data;
}

