#include "demos.h"

#include "aritmetica.h"
#include "contenedor.h"
#include "ejercicio2_contenedor.h"
#include "ejercicio3_comun1.h"
#include "lista_enlazada.h"
#include "mayor.h"
#include "pila.h"

#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>

namespace {

void titulo(const char *texto)
{
    std::cout << "\n=== " << texto << " ===\n\n";
}

} // namespace

void demoActividadA()
{
    titulo("ACTIVIDAD A | FUNCION PLANTILLA ARITMETICA");

    std::cout << "aritmetica<int>(10, 45, '+')      = "
              << lab06::aritmetica<int>(10, 45, '+') << '\n';
    std::cout << "aritmetica<int>(10, 45, '*')      = "
              << lab06::aritmetica<int>(10, 45, '*') << '\n';
    std::cout << "aritmetica<double>(3.45, 8.10, '+') = "
              << lab06::aritmetica<double>(3.45, 8.10, '+') << '\n';
    std::cout << "aritmetica<double>(3.45, 8.10, '/') = "
              << lab06::aritmetica<double>(3.45, 8.10, '/') << '\n';
    std::cout << "aritmetica<float>(0.14f, 0.147f, '-') = "
              << lab06::aritmetica<float>(0.14f, 0.147f, '-') << '\n';

    try {
        std::cout << "aritmetica<int>(8, 0, '/')        = ";
        std::cout << lab06::aritmetica<int>(8, 0, '/') << '\n';
    } catch (const std::domain_error &e) {
        std::cout << "excepcion -> " << e.what() << '\n';
    }
}

void demoActividadB()
{
    titulo("ACTIVIDAD B | FUNCION PLANTILLA MAYOR DE");

    const char c1 = lab06::mayorDe<char>('e', 'z');
    const char c2 = lab06::mayorDe<char>('a', 'B');
    const char c3 = lab06::mayorDe<char>('Q', 'm');
    const int n1 = lab06::mayorDe<int>(9, 4);
    const double d1 = lab06::mayorDe<double>(3.25, 8.10);

    std::cout << "mayorDe<char>('e', 'z')      = " << c1 << '\n';
    std::cout << "mayorDe<char>('a', 'B')      = " << c2
              << "   (alfabetico, no ASCII)\n";
    std::cout << "mayorDe<char>('Q', 'm')      = " << c3 << '\n';
    std::cout << "mayorDe<int>(9, 4)           = " << n1 << '\n';
    std::cout << "mayorDe<double>(3.25, 8.10)  = " << d1 << '\n';
}

void demoActividadC()
{
    titulo("ACTIVIDAD C | CLASE PLANTILLA CONTENEDOR");

    lab06::Contenedor<int> z;
    z.metodo2(10, 0);
    z.metodo2(50, 1);
    z.metodo2(60, 2);
    z.metodo2(70, 3);

    std::cout << "Contenedor<int> z: ";
    z.mostrar();
    std::cout << "z.metodo1(2) = " << z.metodo1(2) << '\n';

    lab06::Contenedor<double> d;
    d.metodo2(3.14, 0);
    d.metodo2(2.71, 1);
    d.metodo2(1.62, 2);
    d.metodo2(0.57, 3);

    std::cout << "Contenedor<double> d: ";
    d.mostrar();

    try {
        z.metodo2(99, 4);
    } catch (const std::out_of_range &e) {
        std::cout << "z.metodo2(99, 4) -> excepcion: " << e.what() << '\n';
    }
}

void demoActividadD()
{
    titulo("ACTIVIDAD D | CLASE PLANTILLA PILA");

    lab06::Pila<int> pila1(4);
    std::cout << "Pila<int> pila1(4):\n";
    std::cout << "insertar(1): " << std::boolalpha << pila1.insertar(1) << '\n';
    std::cout << "insertar(3): " << pila1.insertar(3) << '\n';
    std::cout << "insertar(5): " << pila1.insertar(5) << '\n';
    std::cout << "insertar(7): " << pila1.insertar(7) << '\n';
    std::cout << "insertar(9): " << pila1.insertar(9)
              << "  (capacidad maxima alcanzada)\n";
    std::cout << "contenido: ";
    pila1.mostrarPila();

    lab06::Pila<char> pila2(4);
    std::cout << "\nPila<char> pila2(4):\n";
    pila2.insertar('a');
    pila2.insertar('b');
    pila2.insertar('c');
    std::cout << "contenido: ";
    pila2.mostrarPila();

    int cima = 0;
    pila1.sacar(cima);
    std::cout << "\nsacar(pila1) -> " << cima << " | nuevo contenido: ";
    pila1.mostrarPila();
}

void demoEjercicio1()
{
    titulo("EJERCICIO 1 | LISTA ENLAZADA SIMPLE PLANTILLA");

    lab06::ListaEnlazada<int> edades;
    edades.agregar(18);
    edades.agregar(20);
    edades.agregar(19);
    edades.agregar(22);
    std::cout << "Secuencia de edades (" << edades.tamanio() << " nodos):\n";
    edades.mostrar();

    lab06::ListaEnlazada<std::string> palabras;
    palabras.agregar("plantillas");
    palabras.agregar("C++");
    palabras.agregar("Qt");
    palabras.agregar("UNSA");
    std::cout << "\nSecuencia de palabras (" << palabras.tamanio() << " nodos):\n";
    palabras.mostrar();
}

void demoEjercicio2()
{
    titulo("EJERCICIO 2 | ESPECIALIZACION TOTAL DE PLANTILLA");

    ej2::Contenedor<int> cint(5);
    ej2::Contenedor<char> cchar('t');

    std::cout << "Contenedor<int> cint(5).add()        = " << cint.add() << '\n';
    std::cout << "Contenedor<char> cchar('t').uppercase() = "
              << cchar.uppercase() << '\n';
    std::cout << "\nLa especializacion <char> reemplaza toda la clase:\n";
    std::cout << "solo expone uppercase(), no add().\n";
}

void demoEjercicio3()
{
    titulo("EJERCICIO 3 | PARAMETROS DE PLANTILLA NO TIPO");

    ej3::Comun1<int, 5> objInt;
    ej3::Comun1<double, 5> objFloat;
    ej3::Comun1<> obj;

    objInt.set(0, 10);
    objInt.set(1, 20);
    objFloat.set(2, 3.1);
    obj.set(0, 'H');

    std::cout << "Comun1<int, 5>     objInt.get(0)   = " << objInt.get(0) << '\n';
    std::cout << "Comun1<double, 5>  objFloat.get(2) = " << objFloat.get(2) << '\n';
    std::cout << "Comun1<>           obj.get(4)      = '"
              << obj.get(4) << "'  (char nulo, codigo "
              << static_cast<int>(obj.get(4)) << ")\n";
    std::cout << "Comun1<>           obj.get(0)      = '"
              << obj.get(0) << "'\n";
}
