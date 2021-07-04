#-------------------------------------------------
#
# Project created by QtCreator 2020-11-03T10:33:56
#
#-------------------------------------------------

QT       += core gui sql network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MyWidget
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    myform.cpp \
    browmanager.cpp \
    login.cpp \
    daofactory.cpp \
    userdao.cpp \
    userentity.cpp \
    frienddao.cpp \
    friendentity.cpp \
    network.cpp

HEADERS  += widget.h \
    myform.h \
    browmanager.h \
    login.h \
    daofactory.h \
    userdao.h \
    userentity.h \
    frienddao.h \
    friendentity.h \
    network.h

FORMS    += widget.ui \
    myform.ui \
    login.ui

RESOURCES += \
    img.qrc
