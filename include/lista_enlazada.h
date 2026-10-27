#ifndef LISTA_ENLAZADA_H
#define LISTA_ENLAZADA_H

#include <iostream>

namespace lab06 {

// Ejercicio 1) Lista enlazada simple implementada como clase plantilla.
// Permite armar secuencias de edades, palabras o cualquier otro tipo.
template <typename T>
class ListaEnlazada
{
public:
    ListaEnlazada() = default;

    ListaEnlazada(const ListaEnlazada &) = delete;
    ListaEnlazada &operator=(const ListaEnlazada &) = delete;

    ~ListaEnlazada()
    {
        Nodo *actual = cabeza;
        while (actual != nullptr) {
            Nodo *siguiente = actual->siguiente;
            delete actual;
            actual = siguiente;
        }
    }

    void agregar(const T &dato)
    {
        Nodo *nuevo = new Nodo(dato);
        if (cabeza == nullptr) {
            cabeza = nuevo;
        } else {
            Nodo *actual = cabeza;
            while (actual->siguiente != nullptr) {
                actual = actual->siguiente;
            }
            actual->siguiente = nuevo;
        }
        ++cantidad;
    }

    void mostrar() const
    {
        const Nodo *actual = cabeza;
        std::cout << "[";
        while (actual != nullptr) {
            std::cout << actual->dato;
            if (actual->siguiente != nullptr) {
                std::cout << " -> ";
            }
            actual = actual->siguiente;
        }
        std::cout << "]" << std::endl;
    }

    int tamanio() const { return cantidad; }
    bool vacia() const { return cabeza == nullptr; }

private:
    struct Nodo {
        T dato;
        Nodo *siguiente;

        explicit Nodo(const T &valor)
            : dato(valor)
            , siguiente(nullptr)
        {
        }
    };

    Nodo *cabeza = nullptr;
    int cantidad = 0;
};

} // namespace lab06

#endif // LISTA_ENLAZADA_H
