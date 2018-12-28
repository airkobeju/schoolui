#ifndef SESION_H
#define SESION_H

#include <QString>
#include "commons/fecha.h"
#include "school-db_global.h"

class SCHOOLDBSHARED_EXPORT Sesion
{
public:
    Sesion();

    QString getId() const;
    void setId(const QString &value);

    QString getTitulo() const;
    void setTitulo(const QString &value);

    QString getRecursoMet() const;
    void setRecursoMet(const QString &value);

    QString getSecuenciaDid() const;
    void setSecuenciaDid(const QString &value);

    QString getCursoId() const;
    void setCursoId(const QString &value);

    Fecha getFecha() const;
    void setFecha(const Fecha &value);

private:
    QString id, titulo, recursoMet, secuenciaDid, cursoId;
    Fecha fecha;
};

#endif // SESION_H
