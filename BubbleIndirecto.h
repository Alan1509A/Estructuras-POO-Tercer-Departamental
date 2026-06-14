#ifndef BUBBLEINDIRECTO_H
#define BUBBLEINDIRECTO_H

#include <iostream>
#include <algorithm>
using namespace std;

template <typename T>
class BubbleIndirecto {
private:
    T* datos;
    T** indices;
    int n;

public:
    BubbleIndirecto(T arr[], int size) {
        datos = arr;
        n = size;
        indices = new T*[n];
        for (int i = 0; i < n; i++)
            indices[i] = &datos[i];
    }

    void ordenar() {
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (*indices[j] > *indices[j + 1]) {
                    swap(indices[j], indices[j + 1]);
                }
            }
        }
    }

    void imprimir() {
        for (int i = 0; i < n; i++)
            cout << *indices[i] << " ";
        cout << endl;
    }
};

#endif