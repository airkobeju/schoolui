#include "curso.h"

Curso::Curso()
{

}

QString Curso::getId() const
{
    return id;
}

void Curso::setId(const QString &value)
{
    id = value;
}

QString Curso::getAsignaturaId() const
{
    return asignaturaId;
}

void Curso::setAsignaturaId(const QString &value)
{
    asignaturaId = value;
}

QString Curso::getGradoId() const
{
    return gradoId;
}

void Curso::setGradoId(const QString &value)
{
    gradoId = value;
}

QString Curso::getDetalle() const
{
    return detalle;
}

void Curso::setDetalle(const QString &value)
{
    detalle = value;
}
