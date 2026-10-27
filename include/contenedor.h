#ifndef CONTENEDOR_H
#define CONTENEDOR_H

#include <iostream>
#include <stdexcept>

namespace lab06 {

// Actividad c) Clase plantilla que almacena datos numéricos en un arreglo
// de tamaño fijo y permite insertarlos en una posición específica.
template <typename T>
class Contenedor
{
public:
    static constexpr int TAM = 4;

    Contenedor()
    {
        for (int i = 0; i < TAM; ++i) {
            array[i] = T{};
        }
    }

    T metodo1(int xx) const
    {
        validarIndice(xx);
        return array[xx];
    }

    void metodo2(T val, int i)
    {
        validarIndice(i);
        array[i] = val;
    }

    void mostrar() const
    {
        for (int i = 0; i < TAM; ++i) {
            std::cout << array[i] << (i + 1 < TAM ? " " : "");
        }
        std::cout << std::endl;
    }

private:
    T array[TAM];

    static void validarIndice(int i)
    {
        if (i < 0 || i >= TAM) {
            throw std::out_of_range("Indice fuera del rango [0, 3]");
        }
    }
};

} // namespace lab06

#endif // CONTENEDOR_H
