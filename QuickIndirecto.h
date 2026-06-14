#ifndef QUICKINDIRECTO_H
#define QUICKINDIRECTO_H

#include <iostream>
#include <algorithm>
using namespace std;

template <typename T>
class QuickIndirecto {
private:
    T* datos;
    T** indices;
    int n;

public:
    QuickIndirecto(T arr[], int size) {
        datos = arr;
        n = size;
        indices = new T*[n];
        for (int i = 0; i < n; i++)
            indices[i] = &datos[i];
    }

    int particion(int low, int high) {
        T* pivot = indices[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (*indices[j] < *pivot) {
                i++;
                swap(indices[i], indices[j]);
            }
        }
        swap(indices[i + 1], indices[high]);
        return i + 1;
    }

    void ordenar(int low, int high) {
        if (low < high) {
            int pi = particion(low, high);
            ordenar(low, pi - 1);
            ordenar(pi + 1, high);
        }
    }

    void imprimir() {
        for (int i = 0; i < n; i++)
            cout << *indices[i] << " ";
        cout << endl;
    }
};

#endif