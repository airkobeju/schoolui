#ifndef ASIGNATURA_H
#define ASIGNATURA_H

#include <QString>

#include "schooldb_global.h"

class SCHOOLDBSHARED_EXPORT Asignatura
{
public:
    Asignatura();

    QString getId() const;
    void setId(const QString &value);

    QString getDetalle() const;
    void setDetalle(const QString &value);

    QString getDescripcion() const;
    void setDescripcion(const QString &value);

private:
    QString id, detalle, descripcion;
};

#endif // ASIGNATURA_H
