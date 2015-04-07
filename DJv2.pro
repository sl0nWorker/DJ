#-------------------------------------------------
#
# Project created by QtCreator 2015-04-07T16:54:28
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DJv2
TEMPLATE = app


SOURCES += main.cpp \
    Game.cpp \
    Platforms.cpp \
    Player.cpp \
    Button.cpp

HEADERS  += \
    Game.h \
    constants.h \
    Platforms.h \
    Player.h \
    Button.h

RESOURCES += \
    Resource.qrc
