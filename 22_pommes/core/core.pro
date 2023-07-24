include(../defaults.pri)

TEMPLATE = lib
TARGET = core
DESTDIR = ../lib

HEADERS += \
    array.hpp \
    config.h \
    game.h \
    observable.h \
    observer.h \
    player.h

SOURCES += \
    game.cpp \
    observable.cpp \
    player.cpp
