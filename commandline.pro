QT -= gui
QT += core

TEMPLATE = app
TARGET = todo

CONFIG += c++11 console
CONFIG -= app_bundle

DESTDIR = $$PWD/bin
OBJECTS_DIR = $$PWD/bin

SOURCES = src/main.cpp

include(src/types/types.pri)
include(src/interfaces/interfaces.pri)
include(src/commands/commands.pri)
