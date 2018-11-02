#ifndef DESEMPENO_H
#define DESEMPENO_H

#include <QString>

#include "school-db_global.h"

class SCHOOLDBSHARED_EXPORT Desempeno
{
public:
    Desempeno();

    QString getId() const;
    void setId(const QString &value);

    QString getDescripcion() const;
    void setDescripcion(const QString &value);

    QString getDetalle() const;
    void setDetalle(const QString &value);

    QString getCapacidadId() const;
    void setCapacidadId(const QString &value);

private:
    QString id, descripcion, detalle, capacidadId;

};

#endif // DESEMPENO_H
