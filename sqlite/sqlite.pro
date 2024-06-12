TARGET = application

QT -= gui
QT += network
QT += sql

CONFIG += c++11
CONFIG += console

HEADERS += mytcpserver.h

SOURCES += main.cpp
SOURCES += mytcpserver.cpp

!isEmpty(target.path): INSTALLS += target
