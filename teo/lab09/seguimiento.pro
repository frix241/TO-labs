QT += core widgets testlib
CONFIG += c++20 testcase
TEMPLATE = app
TARGET = seguimiento_academico
INCLUDEPATH += src
SOURCES += src/main.cpp src/mainwindow.cpp src/actividad.cpp src/repositorio.cpp src/legacy_adapter.cpp src/actividad_controller.cpp
HEADERS += src/mainwindow.h src/actividad.h src/repositorio.h src/legacy_adapter.h src/actividad_controller.h
