#ifndef CAPACIDAD_H
#define CAPACIDAD_H

#include <QString>

#include "schooldb_global.h"

class SCHOOLDBSHARED_EXPORT Capacidad
{
public:
    Capacidad();
    QString getId() const;
    void setId(const QString &value);

    QString getDescripcion() const;
    void setDescripcion(const QString &value);

    QString getDetalle() const;
    void setDetalle(const QString &value);

    QString getCompetenciaId() const;
    void setCompetenciaId(const QString &value);

private:

    QString id, descripcion, detalle, competenciaId;

};

#endif // CAPACIDAD_H
