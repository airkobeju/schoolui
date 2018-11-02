#include "asistencia.h"

Asistencia::Asistencia()
{

}

QString Asistencia::getId() const
{
    return id;
}

void Asistencia::setId(const QString &value)
{
    id = value;
}

QString Asistencia::getSesionId() const
{
    return sesionId;
}

void Asistencia::setSesionId(const QString &value)
{
    sesionId = value;
}

QString Asistencia::getAlumnoId() const
{
    return AlumnoId;
}

void Asistencia::setAlumnoId(const QString &value)
{
    AlumnoId = value;
}

bool Asistencia::getIsPresent() const
{
    return isPresent;
}

void Asistencia::setIsPresent(bool value)
{
    isPresent = value;
}
