#ifndef ASISTENCIA_H
#define ASISTENCIA_H


#include <QString>

#include "school-db_global.h"

class SCHOOLDBSHARED_EXPORT Asistencia
{
public:
    Asistencia();

    QString getId() const;
    void setId(const QString &value);

    QString getSesionId() const;
    void setSesionId(const QString &value);

    QString getAlumnoId() const;
    void setAlumnoId(const QString &value);

    bool getIsPresent() const;
    void setIsPresent(bool value);

private:
    QString id, sesionId, AlumnoId;
    bool isPresent;

};

#endif // ASISTENCIA_H
