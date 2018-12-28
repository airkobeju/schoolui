#include "matricula.h"

Matricula::Matricula()
{

}

QString Matricula::getId() const
{
    return id;
}

void Matricula::setId(const QString &value)
{
    id = value;
}

QString Matricula::getCodigo() const
{
    return codigo;
}

void Matricula::setCodigo(const QString &value)
{
    codigo = value;
}

QString Matricula::getAlumnoId() const
{
    return alumnoId;
}

void Matricula::setAlumnoId(const QString &value)
{
    alumnoId = value;
}

QString Matricula::getGradoId() const
{
    return gradoId;
}

void Matricula::setGradoId(const QString &value)
{
    gradoId = value;
}

QString Matricula::getYearLectivoId() const
{
    return yearLectivoId;
}

void Matricula::setYearLectivoId(const QString &value)
{
    yearLectivoId = value;
}
