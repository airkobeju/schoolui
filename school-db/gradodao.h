#ifndef GRADODAO_H
#define GRADODAO_H

#include <memory>
#include <vector>

#include <QString>
#include "grado.h"

class GradoDao
{
public:
    GradoDao();
    void init() const;

    void add(Grado &gra) const;
    void update(const Grado &gra) const;
    void remove(QString id) const;
    std::unique_ptr<std::vector<std::unique_ptr<Grado>>> find() const;
};

#endif // GRADODAO_H
