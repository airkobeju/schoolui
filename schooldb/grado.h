#ifndef GRADO_H
#define GRADO_H

#include <QString>

#include "schooldb_global.h"

class SCHOOLDBSHARED_EXPORT Grado
{
public:
    Grado();

    QString getCiclo() const;
    void setCiclo(const QString &value);

    QString getNivel() const;
    void setNivel(const QString &value);

    QString getOrdinal() const;
    void setOrdinal(const QString &value);

    QString getId() const;
    void setId(const QString &value);

private:
    QString id, ciclo, nivel, ordinal;
};

#endif // GRADO_H
