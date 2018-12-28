#include "alumnodao.h"

#include <bsoncxx/builder/basic/array.hpp>
#include <bsoncxx/builder/basic/document.hpp>
#include <bsoncxx/builder/basic/kvp.hpp>
#include <bsoncxx/types.hpp>

#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/uri.hpp>

using bsoncxx::builder::basic::kvp;
using bsoncxx::builder::basic::make_array;
using bsoncxx::builder::basic::make_document;

AlumnoDao::AlumnoDao(mongocxx::client &database) :
    mDatabase(database)
{

}

void AlumnoDao::init() const
{

}

void AlumnoDao::add(Alumno &alu) const
{

}

void AlumnoDao::update(const Alumno &alu) const
{

}

void AlumnoDao::remove(QString id) const
{

}

std::unique_ptr<std::vector<std::unique_ptr<Alumno> > > AlumnoDao::find() const
{

}
