include(../defaults.pri)

TEMPLATE = app
CONFIG += console

LIBS += -L../lib -lcore \

SOURCES += main.cpp \
    simple.cpp \
    scenario.cpp

HEADERS += \
    catch.hpp \
