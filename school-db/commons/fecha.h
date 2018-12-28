#ifndef FECHA_H
#define FECHA_H


class Fecha
{
public:
    Fecha();
    Fecha(int year, int month, int day);

    Fecha &operator=(const Fecha &f1);

    int getYear() const;
    void setYear(int value);

    int getMonth() const;
    void setMonth(int value);

    int getDay() const;
    void setDay(int value);

private:
    int year, month, day;
};

#endif // FECHA_H
