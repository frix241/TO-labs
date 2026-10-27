#ifndef EJERCICIO2_CONTENEDOR_H
#define EJERCICIO2_CONTENEDOR_H

namespace ej2 {

// Ejercicio 2) Plantilla primaria: incrementa el valor recibido.
template <class T>
class Contenedor
{
    T elemento;

public:
    explicit Contenedor(T arg) { elemento = arg; }
    T add() { return ++elemento; }
};

// Especialización total para char: reemplaza toda la implementación.
// Por eso esta versión NO tiene el método add(), solo uppercase().
template <>
class Contenedor<char>
{
    char elemento;

public:
    explicit Contenedor(char arg) { elemento = arg; }

    char uppercase()
    {
        if ((elemento >= 'a') && (elemento <= 'z')) {
            elemento += 'A' - 'a';
        }
        return elemento;
    }
};

} // namespace ej2

#endif // EJERCICIO2_CONTENEDOR_H
