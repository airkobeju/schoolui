#include "fecha.h"
#include <QtDebug>

Fecha::Fecha()
{

}

Fecha::Fecha(int year, int month, int day)
{
    this->year = year;
    this->month = month;
    this->day = day;
}

Fecha &Fecha::operator=(const Fecha &f1)
{
    if(&f1 != this){          //evita la autoasignaci¢n
        this->year = f1.getYear();
        this->month = f1.getMonth();
        this->day = f1.getDay();
    }
    else qDebug()<<"Intento de asignar un objeto a si mismo";

    return (*this);
}

int Fecha::getYear() const
{
    return year;
}

void Fecha::setYear(int value)
{
    year = value;
}

int Fecha::getMonth() const
{
    return month;
}

void Fecha::setMonth(int value)
{
    month = value;
}

int Fecha::getDay() const
{
    return day;
}

void Fecha::setDay(int value)
{
    day = value;
}
