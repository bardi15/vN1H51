QT += core
QT -= gui

TARGET = computerScientist
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    workingclass.cpp \
    infodisplay.cpp \
    scientist.cpp \
    opengreeting.cpp
    infodisplay.cpp

HEADERS += \
    infodisplay.h \
    workingclass.h \
    scientist.h \
    opengreeting.h
    infodisplay.h
