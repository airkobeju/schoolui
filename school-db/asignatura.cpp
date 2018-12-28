#include "asignatura.h"

Asignatura::Asignatura()
{

}

QString Asignatura::getId() const
{
    return id;
}

void Asignatura::setId(const QString &value)
{
    id = value;
}

QString Asignatura::getDetalle() const
{
    return detalle;
}

void Asignatura::setDetalle(const QString &value)
{
    detalle = value;
}

QString Asignatura::getDescripcion() const
{
    return descripcion;
}

void Asignatura::setDescripcion(const QString &value)
{
    descripcion = value;
}
