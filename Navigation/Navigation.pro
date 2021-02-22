#-------------------------------------------------
#
# Project created by QtCreator 2020-3-29T19:37:50
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Navigation
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    welcome.cpp

HEADERS  += mainwindow.h \
    tool.h \
    welcome.h

RESOURCES += \
    image.qrc

FORMS += \
    mainwindow.ui \
    welcome.ui

RC_ICONS = HIT.ico
