#include "sesion.h"

Sesion::Sesion()
{

}

QString Sesion::getId() const
{
    return id;
}

void Sesion::setId(const QString &value)
{
    id = value;
}

QString Sesion::getTitulo() const
{
    return titulo;
}

void Sesion::setTitulo(const QString &value)
{
    titulo = value;
}

QString Sesion::getRecursoMet() const
{
    return recursoMet;
}

void Sesion::setRecursoMet(const QString &value)
{
    recursoMet = value;
}

QString Sesion::getSecuenciaDid() const
{
    return secuenciaDid;
}

void Sesion::setSecuenciaDid(const QString &value)
{
    secuenciaDid = value;
}

QString Sesion::getCursoId() const
{
    return cursoId;
}

void Sesion::setCursoId(const QString &value)
{
    cursoId = value;
}

Fecha Sesion::getFecha() const
{
    return fecha;
}

void Sesion::setFecha(const Fecha &value)
{
    fecha = value;
}
