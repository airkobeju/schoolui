#-------------------------------------------------
#
# Project created by QtCreator 2018-10-29T15:18:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = desktop
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++14

SOURCES += \
        main.cpp \
        mainwindow.cpp

HEADERS += \
        mainwindow.h

FORMS += \
        mainwindow.ui

CONFIG += mobility
MOBILITY = 


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

unix:!macx: LIBS += -L$$OUT_PWD/../school-db/ -lschool-db

INCLUDEPATH += $$PWD/../school-db
DEPENDPATH += $$PWD/../school-db

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
