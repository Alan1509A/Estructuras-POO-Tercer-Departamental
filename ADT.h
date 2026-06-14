#ifndef ADT_H
#define ADT_H

#include <iostream>
using namespace std;

class ADT {
private:
    int datos[100];
    int n;

public:
    ADT() { n = 0; }

    void insertar(int x) {
        datos[n++] = x;
    }

    void eliminar(int x) {
        for (int i = 0; i < n; i++) {
            if (datos[i] == x) {
                for (int j = i; j < n - 1; j++)
                    datos[j] = datos[j + 1];
                n--;
                return;
            }
        }
    }

    bool buscar(int x) {
        for (int i = 0; i < n; i++)
            if (datos[i] == x) return true;
        return false;
    }

    void mostrar() {
        for (int i = 0; i < n; i++)
            cout << datos[i] << " ";
        cout << endl;
    }
};

#endif