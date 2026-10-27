#ifndef MAYOR_H
#define MAYOR_H

#include <cctype>

namespace lab06 {

// Actividad b) Función plantilla genérica: devuelve el mayor de dos valores.
template <typename T>
T mayorDe(T a, T b)
{
    return (a > b) ? a : b;
}

// Especialización para char: el orden debe ser alfabético y no el orden
// numerico del código ASCII. Se comparan las versiones en mayúscula para
// que 'a' y 'A' tengan el mismo peso, pero se devuelve el carácter original.
template <>
inline char mayorDe<char>(char a, char b)
{
    const unsigned char ua = static_cast<unsigned char>(
        std::toupper(static_cast<unsigned char>(a)));
    const unsigned char ub = static_cast<unsigned char>(
        std::toupper(static_cast<unsigned char>(b)));

    return (ua >= ub) ? a : b;
}

} // namespace lab06

#endif // MAYOR_H
