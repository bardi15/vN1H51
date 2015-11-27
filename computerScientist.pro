QT += core
QT -= gui

TARGET = computerScientist
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    workingclass.cpp \
    infodisplay.cpp \
    compsciclass.cpp
    infodisplay.cpp

HEADERS += \
    infodisplay.h \
    workingclass.h \
    compsciclass.h
    infodisplay.h
