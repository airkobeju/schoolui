#include "asignaturadao.h"

AsignaturaDao::AsignaturaDao(mongocxx::client &database):
    mDatabase(database)
{

}

void AsignaturaDao::init() const
{

}

void AsignaturaDao::add(Asignatura &asig) const
{

}

void AsignaturaDao::update(const Asignatura &asig) const
{

}

void AsignaturaDao::remove(QString id) const
{

}

std::unique_ptr<std::vector<std::unique_ptr<Asignatura> > > AsignaturaDao::find() const
{

}
