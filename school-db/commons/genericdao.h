#ifndef GENERICDAO_H
#define GENERICDAO_H

#include <iostream>
#include <memory>
#include <vector>
#include <QString>

using namespace std;

template<class T>
class GenericDao{

public:
    void init() const;

    void add(T &obj) const;
    void update(const T &obj) const;
    void remove(QString id) const;
    std::unique_ptr<std::vector<std::unique_ptr<T>>> find() const;

};

#endif // GENERICDAO_H
