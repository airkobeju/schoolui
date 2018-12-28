#ifndef ALUMNODAO_H
#define ALUMNODAO_H

#include <memory>
#include <vector>

#include <QString>
#include <mongocxx/client.hpp>

class Alumno;

class AlumnoDao
{
public:
    AlumnoDao(mongocxx::client& database);
    void init() const;

    void add(Alumno &alu) const;
    void update(const Alumno &alu) const;
    void remove(QString id) const;
    std::unique_ptr<std::vector<std::unique_ptr<Alumno>>> find() const;


private:
    mongocxx::client& mDatabase;
};

#endif // ALUMNODAO_H
