#ifndef CURSO_H
#define CURSO_H

#include <QString>

#include "schooldb_global.h"

class SCHOOLDBSHARED_EXPORT Curso
{
public:
    Curso();

    QString getId() const;
    void setId(const QString &value);

    QString getAsignaturaId() const;
    void setAsignaturaId(const QString &value);

    QString getGradoId() const;
    void setGradoId(const QString &value);

    QString getDetalle() const;
    void setDetalle(const QString &value);

private:
    QString id, asignaturaId, gradoId, detalle;
};

#endif // CURSO_H
