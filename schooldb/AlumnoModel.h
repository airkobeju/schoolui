#ifndef ALUMNOMODEL_H
#define ALUMNOMODEL_H

#include <QAbstractListModel>
#include <QHash>
#include <vector>
#include <memory>

#include "schooldb_global.h"
#include "alumno.h"
#include "DatabaseManager.h"

class SCHOOLDBSHARED_EXPORT AlumnoModel : public QAbstractListModel
{
    Q_OBJECT
public:

    enum Roles {
        IdRole = Qt::UserRole + 1,
        NameRole,
    };

    AlumnoModel(QObject* parent = nullptr);

    QModelIndex add(const Alumno& item);

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex& index, const QVariant& value, int role) override;
    bool removeRows(int row, int count, const QModelIndex& parent) override;
    QHash<int, QByteArray> roleNames() const override;

private:
    bool isIndexValid(const QModelIndex& index) const;

private:
    DatabaseManager& mDb;
    std::unique_ptr<std::vector<std::unique_ptr<Alumno>>> mAlumnos;
};

#endif // ALUMNOMODEL_H
