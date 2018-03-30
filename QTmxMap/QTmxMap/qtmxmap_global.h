#ifndef QTMXMAP_GLOBAL_H
#define QTMXMAP_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(QTMXMAP_LIBRARY)
#  define QTMXMAPSHARED_EXPORT Q_DECL_EXPORT
#else
#  define QTMXMAPSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // QTMXMAP_GLOBAL_H
