#-------------------------------------------------
#
# Project created by QtCreator 2017-08-19T18:56:06
#
#-------------------------------------------------

QT       += core gui

CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = WallpaperManager
TEMPLATE = app


SOURCES += main.cpp\
        home.cpp \
    button_other_background.cpp \
    xml.cpp \
    all_other_background.cpp \
    imagedownloader.cpp

HEADERS  += home.h \
    button_other_background.h \
    xml.h \
    all_other_background.h \
    imagedownloader.h

FORMS    += home.ui \
    all_other_background.ui
