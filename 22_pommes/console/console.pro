include(../defaults.pri)

#you MUST include headers to subprojects, for instance like this
#"core" is not added here because it's already in defaults.pri

#INCLUDEPATH += $$PWD/../controllers

TEMPLATE = app
CONFIG += console

LIBS += -L../lib -llibcore \

SOURCES += main.cpp \
    gameController.cpp \
    textView.cpp

HEADERS += \
    gameController.h \
    textView.h
