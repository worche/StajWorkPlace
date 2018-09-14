#-------------------------------------------------
#
# Project created by QtCreator 2018-08-16T09:43:36
#
#-------------------------------------------------

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Client
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    lsocket.cpp

HEADERS  += mainwindow.h \
    lsocket.h

FORMS    += mainwindow.ui
