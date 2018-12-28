#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <cstdlib>
#include <iostream>
#include <string>

#include "bsoncxx/builder/basic/kvp.hpp"
#include "bsoncxx/json.hpp"
#include "bsoncxx/stdx/make_unique.hpp"
#include "bsoncxx/builder/basic/document.hpp"

#include "mongocxx/client.hpp"
#include "mongocxx/instance.hpp"
#include "mongocxx/logger.hpp"
#include "mongocxx/options/client.hpp"
#include "mongocxx/uri.hpp"

#include <memory>

#include <QString>

#include "alumnodao.h"
#include "asignaturadao.h"
#include "asistenciadao.h"
#include "capacidaddao.h"
#include "competenciadao.h"
#include "cursodao.h"
#include "desempenodao.h"
#include "gradodao.h"


class DatabaseManager
{
public:
//    static void debugQuery(const QSqlQuery& query);

    static DatabaseManager& instance();
    ~DatabaseManager();

protected:
    explicit DatabaseManager();

private:
    mongocxx::instance mongoInstance;
    const mongocxx::uri uri = mongocxx::uri{};
    std::unique_ptr<mongocxx::client> mDatabase( mongocxx::client(uri) );

public:
    const AlumnoDao alumnoDao;
    const AsignaturaDao asignaturaDao;
    const AsistenciaDao asistenciaDao;
    const CapacidadDao capacidadDao;
    const CompetenciaDao competenciaDao;
    const CursoDao cursoDao;
    const DesempenoDao desempenoDao;
    const GradoDao gradoDao;
};

#endif // DATABASEMANAGER_H
