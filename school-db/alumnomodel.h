#ifndef ALUMNOMODEL_H
#define ALUMNOMODEL_H

#include <QAbstractListModel>
#include <QHash>
#include <vector>
#include <memory>

#include "school-db_global.h"
#include "alumno.h"
#include "databasemanager.h"

class SCHOOLDBSHARED_EXPORT AlumnoModel : public QAbstractListModel
{
    Q_OBJECT
public:

    AlumnoModel();
};

#endif // ALUMNOMODEL_H
