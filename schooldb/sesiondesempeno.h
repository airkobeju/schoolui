#ifndef SESIONDESEMPENO_H
#define SESIONDESEMPENO_H


#include <QString>

#include "schooldb_global.h"

class SCHOOLDBSHARED_EXPORT SesionDesempeno
{
public:
    SesionDesempeno();

    QString getId() const;
    void setId(const QString &value);

    QString getSesionId() const;
    void setSesionId(const QString &value);

    QString getDesempenoId() const;
    void setDesempenoId(const QString &value);

private:

    QString id, sesionId, desempenoId;
};

#endif // SESIONDESEMPENO_H
