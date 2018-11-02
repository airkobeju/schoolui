#ifndef ALUMNO_H
#define ALUMNO_H

#include <QString>
#include "commons/fecha.h"
#include "school-db_global.h"

class SCHOOLDBSHARED_EXPORT Alumno
{
public:
    Alumno();

    QString getApellido() const;
    void setApellido(const QString &value);

    QString getNombre() const;
    void setNombre(const QString &value);

    Fecha getNacimiento() const;
    void setNacimiento(const Fecha &value);

    QString getDni() const;
    void setDni(const QString &value);

    QString getId() const;
    void setId(const QString &value);

private:
    QString id, apellido, nombre, dni;
    Fecha nacimiento;

};

#endif // ALUMNO_H
