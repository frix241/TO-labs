#ifndef EJERCICIO3_COMUN1_H
#define EJERCICIO3_COMUN1_H

namespace ej3 {

// Ejercicio 3) Plantilla con dos parámetros: un tipo y un entero N.
// El entero N es un parámetro de plantilla que no representa un tipo.
// Se inicializa el arreglo con T{} para evitar valores indeterminados.
template <class T = char, int N = 8>
class Comun1
{
    T bloque[N]{};

public:
    void set(int num, T tval)
    {
        if (num >= 0 && num < N) {
            bloque[num] = tval;
        }
    }

    T get(int num) const
    {
        if (num >= 0 && num < N) {
            return bloque[num];
        }
        return T{};
    }
};

} // namespace ej3

#endif // EJERCICIO3_COMUN1_H
