#ifndef FILEIO_H
#define FILEIO_H

#include <QObject>

class FIleIO : public QObject
{
    Q_OBJECT
public:
    explicit FIleIO(QObject *parent = nullptr);

signals:

public slots:
};

#endif // FILEIO_H