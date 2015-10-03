#-------------------------------------------------
#
# Project created by QtCreator 2015-09-18T20:33:05
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = dispatcher
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    scheduler.cpp

HEADERS  += mainwindow.h \
    scheduler.h

FORMS    += mainwindow.ui
