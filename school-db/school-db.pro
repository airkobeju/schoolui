#-------------------------------------------------
#
# Project created by QtCreator 2018-10-18T16:32:34
#
#-------------------------------------------------

QT       -= gui

TARGET = school-db
TEMPLATE = lib
CONFIG += lib c++14

DEFINES += SCHOOLDB_LIBRARY

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        schooldb.cpp \
    alumno.cpp \
    grado.cpp \
    asignatura.cpp \
    yearlectivo.cpp \
    matricula.cpp \
    curso.cpp \
    sesion.cpp \
    commons/fecha.cpp \
    competencia.cpp \
    capacidad.cpp \
    desempeno.cpp \
    sesiondesempeno.cpp \
    asistencia.cpp \
    alumnodao.cpp \
    asignaturadao.cpp \
    asistenciadao.cpp \
    capacidaddao.cpp \
    competenciadao.cpp \
    cursodao.cpp \
    desempenodao.cpp \
    gradodao.cpp \
    databasemanager.cpp \
    alumnomodel.cpp

HEADERS += \
        schooldb.h \
        school-db_global.h \ 
    alumno.h \
    school-db_global.h \
    grado.h \
    asignatura.h \
    yearlectivo.h \
    matricula.h \
    curso.h \
    sesion.h \
    commons/fecha.h \
    competencia.h \
    capacidad.h \
    desempeno.h \
    sesiondesempeno.h \
    asistencia.h \
    alumnodao.h \
    asignaturadao.h \
    asistenciadao.h \
    capacidaddao.h \
    competenciadao.h \
    cursodao.h \
    commons/genericdao.h \
    desempenodao.h \
    gradodao.h \
    databasemanager.h \
    alumnomodel.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

unix:!macx: LIBS += -L/usr/local/lib/ -lmongocxx

INCLUDEPATH += /usr/local/include/mongocxx/v_noabi
DEPENDPATH += /usr/local/include/mongocxx/v_noabi

unix:!macx: LIBS += -L/usr/local/lib/ -lbsoncxx

INCLUDEPATH += /usr/local/include/bsoncxx/v_noabi
DEPENDPATH += /usr/local/include/bsoncxx/v_noabi
