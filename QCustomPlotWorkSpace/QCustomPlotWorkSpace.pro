#-------------------------------------------------
#
# Project created by QtCreator 2018-09-05T10:16:52
#
#-------------------------------------------------

QT       += core gui
QT += printsupport


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QCustomPlotWorkSpace
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    qcustomplot.cpp

HEADERS  += mainwindow.h \
    qcustomplot.h

FORMS    += mainwindow.ui

RESOURCES += \
    fonts.qrc
