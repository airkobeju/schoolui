#ifndef CURSODAO_H
#define CURSODAO_H

#include "commons/genericdao.h"
#include "curso.h"

class CursoDao: public GenericDao<Curso>
{
public:
    CursoDao();
    void init() const;

    void add(Curso &cur) const;
    void update(const Curso &cur) const;
    void remove(QString id) const;
    std::unique_ptr<std::vector<std::unique_ptr<Curso>>> find() const;
};

#endif // CURSODAO_H
