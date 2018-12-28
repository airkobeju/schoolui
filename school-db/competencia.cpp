#include "competencia.h"

Competencia::Competencia()
{

}

QString Competencia::getId() const
{
    return id;
}

void Competencia::setId(const QString &value)
{
    id = value;
}

QString Competencia::getDescripcion() const
{
    return descripcion;
}

void Competencia::setDescripcion(const QString &value)
{
    descripcion = value;
}

QString Competencia::getDetalle() const
{
    return detalle;
}

void Competencia::setDetalle(const QString &value)
{
    detalle = value;
}

QString Competencia::getYearLectivoId() const
{
    return yearLectivoId;
}

void Competencia::setYearLectivoId(const QString &value)
{
    yearLectivoId = value;
}
