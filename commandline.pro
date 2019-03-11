QT -= gui
QT += core

TEMPLATE = app
TARGET = todo

CONFIG += c++11 console
CONFIG -= app_bundle

DEFINES += QT_DEPRECATED_WARNINGS
SOURCES += main.cpp

DESTDIR = $$PWD/bin
OBJECTS_DIR = $$PWD/bin

include(commands/commands.pri)
