QT += core
QT -= gui

TARGET = computerScientist
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    compSciClass.cpp
    infodisplay.cpp

HEADERS += \
    compSciClass.h
    infodisplay.h
