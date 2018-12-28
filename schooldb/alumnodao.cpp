#include "alumnodao.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>

#include "alumno.h"
#include "DatabaseManager.h"

using namespace std;

AlumnoDao::AlumnoDao(QSqlDatabase& database) :
    mDatabase(database)
{
}

void AlumnoDao::init() const
{
    if (!mDatabase.tables().contains("alumno")) {
        QSqlQuery query(mDatabase);
        /*TODO: crear tabla pendiente*/
        query.exec("CREATE TABLE alumno (\
        id INTEGER PRIMARY KEY AUTOINCREMENT, \
        apellido TEXT, nombre TEXT, nacimiento TEXT, dni TEXT)");

        DatabaseManager::debugQuery(query);
    }
}

void AlumnoDao::add(Alumno& item) const
{
    QSqlQuery query(mDatabase);
    query.prepare("INSERT INTO alumno (apellido, nombre, nacimiento, dni) VALUES (:apellido, :nombre, :nacimiento, :dni)");
    query.bindValue(":apellido", item.getApellido());
    query.bindValue(":nombre", item.getNombre());
    query.bindValue(":nacimiento", item.getNacimiento().toString());
    query.bindValue(":dni", item.getDni());
    query.exec();
    item.setId(query.lastInsertId().toInt());
    DatabaseManager::debugQuery(query);
}

void AlumnoDao::update(const Alumno& item)const
{
    QSqlQuery query(mDatabase);
    query.prepare("UPDATE alumno SET apellido = (:apellido), nombre = (:nombre) WHERE dni = (:dni)");
    query.bindValue(":apellido", item.getApellido());
    query.bindValue(":nombre", item.getNombre());
    query.bindValue(":dni", item.getDni());
    query.exec();
    DatabaseManager::debugQuery(query);
}

void AlumnoDao::remove(QString dni) const
{
    QSqlQuery query(mDatabase);
    query.prepare("DELETE FROM alumno WHERE dni = (:dni)");
    query.bindValue(":dni", dni);
    query.exec();
    DatabaseManager::debugQuery(query);
}

unique_ptr<vector<unique_ptr<Alumno>>> AlumnoDao::alumnos() const
{
    QSqlQuery query("SELECT * FROM alumno", mDatabase);
    query.exec();
    unique_ptr<vector<unique_ptr<Alumno>>> list(new vector<unique_ptr<Alumno>>());
    while(query.next()) {
        unique_ptr<Alumno> alumno(new Alumno());
        alumno->setId(query.value("id").toInt());
        alumno->setNombre(query.value("nombre").toString());
        alumno->setApellido(query.value("apellido").toString());
        alumno->setDni(query.value("dni").toString());
        /*TODO: arreglar Nacimiento*/
        //alumno->setNacimiento(new Fecha(query.value("nacimiento").toString()));
        list->push_back(move(alumno));
    }
    return list;
}
