TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS +=-ftemplate-depth=550

SOURCES += main.cpp
