#ifndef ALUMNODAO_H
#define ALUMNODAO_H

#include <memory>
#include <vector>

#include <QString>

class QSqlDatabase;
class Alumno;

class AlumnoDao
{
public:
    AlumnoDao(QSqlDatabase& database);
    void init() const;

    void add(Alumno& item) const;
    void update(const Alumno& item) const;
    void remove(QString dni) const;
    std::unique_ptr<std::vector<std::unique_ptr<Alumno>>> alumnos() const;

private:
    QSqlDatabase& mDatabase;
};

#endif // ALUMNODAO_H
