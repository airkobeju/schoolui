#include "desempeno.h"

Desempeno::Desempeno()
{

}

QString Desempeno::getId() const
{
    return id;
}

void Desempeno::setId(const QString &value)
{
    id = value;
}

QString Desempeno::getDescripcion() const
{
    return descripcion;
}

void Desempeno::setDescripcion(const QString &value)
{
    descripcion = value;
}

QString Desempeno::getDetalle() const
{
    return detalle;
}

void Desempeno::setDetalle(const QString &value)
{
    detalle = value;
}

QString Desempeno::getCapacidadId() const
{
    return capacidadId;
}

void Desempeno::setCapacidadId(const QString &value)
{
    capacidadId = value;
}
