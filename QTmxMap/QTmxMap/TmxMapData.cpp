#include "TmxMapData.h"

TmxMapData::TmxMapData() { }

TmxMapData::~TmxMapData() {
  mapAttributes_.clear();
  qDeleteAll(tilesetData_);
  tilesetData_.clear();
  qDeleteAll(layers_);
  layers_.clear();
  qDeleteAll(objectGroups_);
  objectGroups_.clear();
}

QHash<QString, QString> TmxMapData::getMapAttributes() {
  return mapAttributes_;
}

QHash<QString, STilesetData *> TmxMapData::getTilesetData() {
  return tilesetData_;
}

QHash<QString, SLayerData *> TmxMapData::getLayerData() {
  return layers_;
}

QList<SObjecGrouptData *> TmxMapData::getObjectGroups() {
  return objectGroups_;
}


