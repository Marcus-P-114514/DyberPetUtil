#ifndef DYBERPETRESPACKER_GLOBAL_H
#define DYBERPETRESPACKER_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(DYBERPETRESPACKER_LIBRARY)
#  define DYBERPETRESPACKER_EXPORT Q_DECL_EXPORT
#else
#  define DYBERPETRESPACKER_EXPORT Q_DECL_IMPORT
#endif

#endif // DYBERPETRESPACKER_GLOBAL_H