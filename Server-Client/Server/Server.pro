#-------------------------------------------------
#
# Project created by QtCreator 2018-08-16T10:27:08
#
#-------------------------------------------------

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Server
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    lserver.cpp

HEADERS  += mainwindow.h \
    lserver.h

FORMS    += mainwindow.ui
