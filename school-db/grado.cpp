#include "grado.h"

Grado::Grado()
{

}

QString Grado::getCiclo() const
{
    return ciclo;
}

void Grado::setCiclo(const QString &value)
{
    ciclo = value;
}

QString Grado::getNivel() const
{
    return nivel;
}

void Grado::setNivel(const QString &value)
{
    nivel = value;
}

QString Grado::getOrdinal() const
{
    return ordinal;
}

void Grado::setOrdinal(const QString &value)
{
    ordinal = value;
}

QString Grado::getId() const
{
    return id;
}

void Grado::setId(const QString &value)
{
    id = value;
}
