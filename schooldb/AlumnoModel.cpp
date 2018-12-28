#include "AlumnoModel.h"

using namespace std;

AlumnoModel::AlumnoModel(QObject* parent) :
    QAbstractListModel(parent),
    mDb(DatabaseManager::instance()),
    mAlumnos(mDb.alumnoDao.alumnos())
{
}

QModelIndex AlumnoModel::add(const Alumno& item)
{
    int rowIndex = rowCount();
    beginInsertRows(QModelIndex(), rowIndex, rowIndex);
    unique_ptr<Alumno> newAlumno(new Alumno(item));
    mDb.alumnoDao.add(*newAlumno);
    mAlumnos->push_back(move(newAlumno));
    endInsertRows();
    return index(rowIndex, 0);
}

int AlumnoModel::rowCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent);
    return mAlumnos->size();
}

QVariant AlumnoModel::data(const QModelIndex& index, int role) const
{
    if (!isIndexValid(index)) {
        return QVariant();
    }
    const Alumno& alumno = *mAlumnos->at(index.row());

    switch (role) {
        case Roles::IdRole:
            return alumno.getId();

        case Roles::NameRole:
        case Qt::DisplayRole:
            return alumno.getNombre();

        default:
            return QVariant();
    }
}

bool AlumnoModel::setData(const QModelIndex& index, const QVariant& value, int role)
{
    if (!isIndexValid(index)
            || role != Roles::NameRole) {
        return false;
    }
    Alumno& alumno = *mAlumnos->at(index.row());
    alumno.setNombre(value.toString());
    mDb.alumnoDao.update(alumno);
    emit dataChanged(index, index);
    return true;
}

bool AlumnoModel::removeRows(int row, int count, const QModelIndex& parent)
{
    if (row < 0
            || row >= rowCount()
            || count < 0
            || (row + count) > rowCount()) {
        return false;
    }
    beginRemoveRows(parent, row, row + count - 1);
    int countLeft = count;
    while (countLeft--) {
        const Alumno& alumno = *mAlumnos->at(row + countLeft);
        mDb.alumnoDao.remove(alumno.getDni());
    }
    mAlumnos->erase(mAlumnos->begin() + row,
                  mAlumnos->begin() + row + count);
    endRemoveRows();
    return true;
}

QHash<int, QByteArray> AlumnoModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[Roles::IdRole] = "id";
    roles[Roles::NameRole] = "name";
    return roles;
}

bool AlumnoModel::isIndexValid(const QModelIndex& index) const
{
    if (index.row() < 0
            || index.row() >= rowCount()
            || !index.isValid()) {
        return false;
    }
    return true;
}

