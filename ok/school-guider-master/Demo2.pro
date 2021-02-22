#-------------------------------------------------
#
# Project created by QtCreator 2018-01-10T15:10:38
#
#-------------------------------------------------

QT       += core gui
RC_FILE = proj.rc

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Demo2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mysite.cpp \
    myroad.cpp \
    loginbox.cpp \
    mydialog.cpp

HEADERS  += mainwindow.h \
    mysite.h \
    myroad.h \
    loginbox.h \
    mydialog.h

FORMS    += mainwindow.ui \
    loginbox.ui \
    mydialog.ui
