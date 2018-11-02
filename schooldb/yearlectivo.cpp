#include "yearlectivo.h"

YearLectivo::YearLectivo()
{

}

QString YearLectivo::getId() const
{
    return id;
}

void YearLectivo::setId(const QString &value)
{
    id = value;
}

int YearLectivo::getYear() const
{
    return year;
}

void YearLectivo::setYear(int value)
{
    year = value;
}
