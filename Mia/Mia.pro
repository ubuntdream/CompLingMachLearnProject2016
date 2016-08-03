#-------------------------------------------------
#
# Project created by QtCreator 2016-06-19T21:09:16
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Mia
TEMPLATE = app

CONFIG += c++11

SOURCES += main.cpp\
        mainwindow.cpp \
    Control/control.cpp \
    Model/value.cpp \
    Model/dicevalidator.cpp \
    Model/player.cpp \
    Control/statistic.cpp \
    Control/ki.cpp

HEADERS  += mainwindow.h \
    Control/control.h \
    Model/value.h \
    Model/dicevalidator.h \
    Model/player.h \
    Control/statistic.h \
    Control/ki.h

FORMS    += mainwindow.ui
