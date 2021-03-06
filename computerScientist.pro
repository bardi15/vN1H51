QT += core
QT -= gui
QT += sql

TARGET = computerScientist
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    workingclass.cpp \
    infodisplay.cpp \
    scientist.cpp \
    opengreeting.cpp \
    service.cpp \
    computer.cpp \
    computertype.cpp
    infodisplay.cpp

HEADERS += \
    infodisplay.h \
    workingclass.h \
    scientist.h \
    opengreeting.h \
    service.h \
    computer.h \
    computertype.h
    infodisplay.h
