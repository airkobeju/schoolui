#ifndef YEARLECTIVO_H
#define YEARLECTIVO_H

#include <QString>

#include "schooldb_global.h"

class SCHOOLDBSHARED_EXPORT YearLectivo
{
public:
    YearLectivo();

    QString getId() const;
    void setId(const QString &value);

    int getYear() const;
    void setYear(int value);

private:
    QString id;
    int year;
};

#endif // YEARLECTIVO_H
