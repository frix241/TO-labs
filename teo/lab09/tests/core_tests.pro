QT += core testlib
CONFIG += c++20 testcase console
TEMPLATE = app
TARGET = academico_tests
INCLUDEPATH += ../src
SOURCES += test_core.cpp ../src/actividad.cpp ../src/repositorio.cpp ../src/legacy_adapter.cpp ../src/actividad_controller.cpp
HEADERS += ../src/actividad.h ../src/repositorio.h ../src/legacy_adapter.h ../src/actividad_controller.h
