#ifndef COMPETENCIADAO_H
#define COMPETENCIADAO_H

#include <memory>
#include <vector>

#include <QString>

class Competencia;

class CompetenciaDao
{
public:
    CompetenciaDao();
    void init() const;

    void add(Competencia &comp) const;
    void update(const Competencia &comp) const;
    void remove(QString id) const;
    std::unique_ptr<std::vector<std::unique_ptr<Competencia>>> find() const;
};

#endif // COMPETENCIADAO_H
