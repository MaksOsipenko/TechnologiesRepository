TARGET = application

QT -= gui
QT += network

CONFIG += c++11
CONFIG += console

HEADERS += mytcpserver.h

SOURCES += main.cpp
SOURCES += mytcpserver.cpp

!isEmpty(target.path): INSTALLS += target
