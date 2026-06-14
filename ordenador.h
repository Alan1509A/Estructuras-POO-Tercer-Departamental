#ifndef ORDENADOR_H
#define ORDENADOR_H

#include <iostream>
#include <algorithm>
using namespace std;

template <typename T>
class Ordenador {
protected:
    T* arr;
    int n;

public:
    Ordenador(T a[], int size) {
        arr = a;
        n = size;
    }

    void imprimir() {
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

#endif