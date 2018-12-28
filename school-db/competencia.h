#ifndef COMPETENCIA_H
#define COMPETENCIA_H

#include <QString>

#include "school-db_global.h"

class SCHOOLDBSHARED_EXPORT Competencia
{
public:
    Competencia();

    QString getId() const;
    void setId(const QString &value);

    QString getDescripcion() const;
    void setDescripcion(const QString &value);

    QString getDetalle() const;
    void setDetalle(const QString &value);

    QString getYearLectivoId() const;
    void setYearLectivoId(const QString &value);

private:

    QString id, descripcion, detalle, yearLectivoId;

};

#endif // COMPETENCIA_H
