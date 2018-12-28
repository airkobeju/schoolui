#ifndef ASIGNATURADAO_H
#define ASIGNATURADAO_H

#include <QString>
#include <memory>
#include <vector>

#include "mongocxx/client.hpp"

class Asignatura;

class AsignaturaDao
{
public:
    AsignaturaDao(mongocxx::client& database);
    void init() const;

    void add(Asignatura &asig) const;
    void update(const Asignatura &asig) const;
    void remove(QString id)const;
    std::unique_ptr<std::vector<std::unique_ptr<Asignatura>>> find() const;

private:
    mongocxx::client& mDatabase;
};

#endif // ASIGNATURADAO_H
