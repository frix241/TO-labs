#ifndef PILA_H
#define PILA_H

#include <iostream>
#include <memory>

namespace lab06 {

// Actividad d) Pila genérica de capacidad fija. Corrige dos errores del
// código de la guía: usa new T[n] (no new T(n)) y respeta el límite real.
template <class T>
class Pila
{
public:
    explicit Pila(int nelem = 10)
        : nelementos(nelem > 0 ? nelem : 10)
        , cadena(std::make_unique<T[]>(static_cast<std::size_t>(nelementos)))
        , limite(0)
    {
    }

    bool insertar(const T &elem)
    {
        if (limite >= nelementos) {
            return false; // pila llena
        }
        cadena[limite++] = elem;
        return true;
    }

    bool sacar(T &elem)
    {
        if (limite == 0) {
            return false; // pila vacía
        }
        elem = cadena[--limite];
        return true;
    }

    void mostrarPila() const
    {
        for (int i = 0; i < limite; ++i) {
            std::cout << cadena[i] << (i + 1 < limite ? ", " : "");
        }
        std::cout << std::endl;
    }

    int tamanio() const { return limite; }
    int capacidad() const { return nelementos; }
    bool vacia() const { return limite == 0; }
    bool llena() const { return limite == nelementos; }

private:
    int nelementos;
    std::unique_ptr<T[]> cadena;
    int limite;
};

} // namespace lab06

#endif // PILA_H
