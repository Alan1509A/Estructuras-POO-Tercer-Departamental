#ifndef LISTAPUNTEROS_H
#define LISTAPUNTEROS_H

#include <iostream>
#include "Nodo.h"
using namespace std;

template <typename T>
class ListaPunteros {
private:
    Nodo<T>* cabeza;

public:
    ListaPunteros() {
        cabeza = NULL;
    }

    void insertar(T valor) {
        Nodo<T>* nuevo = new Nodo<T>(valor);
        nuevo->siguiente = cabeza;
        cabeza = nuevo;
    }

    void mostrar() {
        Nodo<T>* temp = cabeza;
        while (temp != NULL) {
            cout << temp->dato << " -> ";
            temp = temp->siguiente;
        }
        cout << "NULL\n";
    }
};

#endif