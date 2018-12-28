#ifndef CAPACIDADDAO_H
#define CAPACIDADDAO_H

#include <QString>
#include <memory>
#include <vector>

class Capacidad;

class CapacidadDao
{
public:
    CapacidadDao();
    void init() const;

    void add(Capacidad &capac) const;
    void update(const Capacidad &capac) const;
    void remove(QString id) const;
    std::unique_ptr<std::vector<std::unique_ptr<Capacidad>>> find() const;
};

#endif // CAPACIDADDAO_H
