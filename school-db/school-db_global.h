#ifndef SCHOOLDB_GLOBAL_H
#define SCHOOLDB_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(SCHOOLDB_LIBRARY)
#  define SCHOOLDBSHARED_EXPORT Q_DECL_EXPORT
#else
#  define SCHOOLDBSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // SCHOOLDB_GLOBAL_H
