#ifndef MATRICULA_H
#define MATRICULA_H

#include <QString>

#include "schooldb_global.h"

class SCHOOLDBSHARED_EXPORT Matricula
{
public:
    Matricula();

    QString getId() const;
    void setId(const QString &value);

    QString getCodigo() const;
    void setCodigo(const QString &value);

    QString getAlumnoId() const;
    void setAlumnoId(const QString &value);

    QString getGradoId() const;
    void setGradoId(const QString &value);

    QString getYearLectivoId() const;
    void setYearLectivoId(const QString &value);

private:
    QString id, codigo, alumnoId, gradoId, yearLectivoId;
};

#endif // MATRICULA_H
