#-------------------------------------------------
#
# Project created by QtCreator 2016-11-25T19:37:50
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Navigation
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    data.cpp \
    viewspot.cpp

HEADERS  += mainwindow.h \
    data.h \
    viewspot.h

RESOURCES += \
    map.qrc
QMAKE_CXXFLAGS += -std=c++0x

DISTFILES +=
