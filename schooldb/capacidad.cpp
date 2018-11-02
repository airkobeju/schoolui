#include "capacidad.h"

Capacidad::Capacidad()
{

}

QString Capacidad::getId() const
{
    return id;
}

void Capacidad::setId(const QString &value)
{
    id = value;
}

QString Capacidad::getDescripcion() const
{
    return descripcion;
}

void Capacidad::setDescripcion(const QString &value)
{
    descripcion = value;
}

QString Capacidad::getDetalle() const
{
    return detalle;
}

void Capacidad::setDetalle(const QString &value)
{
    detalle = value;
}

QString Capacidad::getCompetenciaId() const
{
    return competenciaId;
}

void Capacidad::setCompetenciaId(const QString &value)
{
    competenciaId = value;
}
