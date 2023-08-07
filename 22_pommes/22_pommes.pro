TEMPLATE = subdirs

SUBDIRS += \
    core \
    gui \
    tests \    
    console \    

# Declare the ordering
gui.depends = core
tests.depends = core
console.depends = core

# Enable parallel building
CONFIG += ordered

OTHER_FILES += \
    defaults.pri

include(defaults.pri)
