#include "alumno.h"

Alumno::Alumno()
{

}

QString Alumno::getApellido() const
{
    return apellido;
}

void Alumno::setApellido(const QString &value)
{
    apellido = value;
}

QString Alumno::getNombre() const
{
    return nombre;
}

void Alumno::setNombre(const QString &value)
{
    nombre = value;
}

Fecha Alumno::getNacimiento() const
{
    return nacimiento;
}

void Alumno::setNacimiento(const Fecha &value)
{
    nacimiento = value;
}

QString Alumno::getDni() const
{
    return dni;
}

void Alumno::setDni(const QString &value)
{
    dni = value;
}

int Alumno::getId() const
{
    return id;
}

void Alumno::setId(int value)
{
    id = value;
}
