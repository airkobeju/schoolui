#include "sesiondesempeno.h"

SesionDesempeno::SesionDesempeno()
{

}

QString SesionDesempeno::getId() const
{
    return id;
}

void SesionDesempeno::setId(const QString &value)
{
    id = value;
}

QString SesionDesempeno::getSesionId() const
{
    return sesionId;
}

void SesionDesempeno::setSesionId(const QString &value)
{
    sesionId = value;
}

QString SesionDesempeno::getDesempenoId() const
{
    return desempenoId;
}

void SesionDesempeno::setDesempenoId(const QString &value)
{
    desempenoId = value;
}
