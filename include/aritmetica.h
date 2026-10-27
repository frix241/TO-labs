#ifndef ARITMETICA_H
#define ARITMETICA_H

#include <stdexcept>

namespace lab06 {

// Actividad a) Función plantilla que realiza una operación aritmética
// con dos valores del mismo tipo, sin importar si son enteros,
// flotantes o doubles.
template <typename T>
T aritmetica(T a, T b, char operador)
{
    switch (operador) {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        if (b == T{}) {
            throw std::domain_error("No se puede dividir entre cero");
        }
        return a / b;
    default:
        throw std::invalid_argument("Operador aritmetico no valido");
    }
}

} // namespace lab06

#endif // ARITMETICA_H
