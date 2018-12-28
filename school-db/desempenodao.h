#ifndef DESEMPENODAO_H
#define DESEMPENODAO_H

#include "desempeno.h"

#include <memory>
#include <vector>
#include <QString>

class DesempenoDao
{
public:
    DesempenoDao();
    void init() const;

    void add(Desempeno &des) const;
    void update(const Desempeno &des) const;
    void remove(QString id) const;
    std::unique_ptr<std::vector<std::unique_ptr<Desempeno>>> find() const;
};

#endif // DESEMPENODAO_H
