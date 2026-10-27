#include "demos.h"

#include <QCommandLineOption>
#include <QCommandLineParser>
#include <QCoreApplication>
#include <QStringList>

#include <iostream>
#include <string>

namespace {

struct Demo {
    const char *clave;
    const char *nombre;
    void (*funcion)();
};

const Demo demos[] = {
    {"a", "Actividad A - aritmetica", demoActividadA},
    {"b", "Actividad B - mayor de dos valores", demoActividadB},
    {"c", "Actividad C - contenedor", demoActividadC},
    {"d", "Actividad D - pila", demoActividadD},
    {"e1", "Ejercicio 1 - lista enlazada", demoEjercicio1},
    {"e2", "Ejercicio 2 - especializacion", demoEjercicio2},
    {"e3", "Ejercicio 3 - parametros no tipo", demoEjercicio3},
};


} // namespace

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    QCoreApplication::setApplicationName("lab06_templates");
    QCoreApplication::setApplicationVersion("1.0");
    QCoreApplication::setOrganizationName("UNSA - Tecnologia de Objetos");

    QCommandLineParser parser;
    parser.setApplicationDescription(
        "Laboratorio 06 - Plantillas (templates) en C++ | Qt Console Application");
    parser.addHelpOption();
    parser.addVersionOption();

    QCommandLineOption demoOption(
        QStringList() << "d" << "demo",
        "Ejecuta una demostracion: a, b, c, d, e1, e2, e3 o all.",
        "demo", "all");
    parser.addOption(demoOption);
    parser.process(app);

    const std::string seleccion = parser.value(demoOption).toLower().toStdString();

    std::cout << "Laboratorio 06 - Templates en C++ | Qt " << QT_VERSION_STR
              << " | consola\n";

    if (seleccion == "all") {
        for (const Demo &demo : demos) {
            demo.funcion();
        }
        std::cout << "\nFin de la demostracion: 7 bloques ejecutados.\n";
        return 0;
    }

    for (const Demo &demo : demos) {
        if (seleccion == demo.clave) {
            demo.funcion();
            return 0;
        }
    }

    std::cerr << "Demo no reconocida: " << seleccion
              << ". Use --help para ver las opciones.\n";
    return 1;
}
