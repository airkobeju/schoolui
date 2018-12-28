#ifndef ASISTENCIADAO_H
#define ASISTENCIADAO_H

#include <QString>
#include <memory>
#include <vector>

class Asistencia;

class AsistenciaDao
{
public:
    AsistenciaDao();
    void init() const;

    void add(Asistencia &asis) const;
    void update(const Asistencia &asis) const;
    void remove(QString id) const;
    std::unique_ptr<std::vector<std::unique_ptr<Asistencia>>> find() const;
};

#endif // ASISTENCIADAO_H
