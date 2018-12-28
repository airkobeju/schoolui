#include "databasemanager.h"

DatabaseManager::DatabaseManager() :
    mongoInstance(mongocxx::instance()),
    alumnoDao(*mDatabase(uri)),
    asignaturaDao(*mDatabase(uri))

{
    try
    {

        //        const AsignaturaDao asignaturaDao;
        //        const AsistenciaDao asistenciaDao;
        //        const CapacidadDao capacidadDao;
        //        const CompetenciaDao competenciaDao;
        //        const CursoDao cursoDao;
        //        const DesempenoDao desempenoDao;
        //        const GradoDao gradoDao;

        //mDatabase = mongocxx::client(uri);
        //            auto admin = client[db_name];
        //            auto result = admin.run_command(make_document(kvp("isMaster", 1)));
        //            std::cout << bsoncxx::to_json(result) << "\n";

    } catch (const std::exception& xcp) {
        std::cout << "connection failed: " << xcp.what() << "\n";
    }
}

DatabaseManager& DatabaseManager::instance()
{
    static DatabaseManager singleton;
    return singleton;
}
