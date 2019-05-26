QT -= gui
QT += core

TEMPLATE = app
TARGET = todo

CONFIG += c++11 console
CONFIG -= app_bundle

SOURCES += src/main.cpp

DESTDIR = $$PWD/bin
OBJECTS_DIR = $$PWD/bin

include(src/commands/commands.pri)
