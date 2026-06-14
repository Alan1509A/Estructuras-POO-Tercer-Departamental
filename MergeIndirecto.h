#ifndef MERGEINDIRECTO_H
#define MERGEINDIRECTO_H

#include <iostream>
using namespace std;

template <typename T>
class MergeIndirecto {
private:
    T* datos;
    T** indices;
    int n;

public:
    MergeIndirecto(T arr[], int size) {
        datos = arr;
        n = size;
        indices = new T*[n];
        for (int i = 0; i < n; i++)
            indices[i] = &datos[i];
    }

    void merge(int l, int m, int r) {
        int n1 = m - l + 1;
        int n2 = r - m;

        T* L[n1];
        T* R[n2];

        for (int i = 0; i < n1; i++)
            L[i] = indices[l + i];
        for (int j = 0; j < n2; j++)
            R[j] = indices[m + 1 + j];

        int i = 0, j = 0, k = l;

        while (i < n1 && j < n2) {
            if (*L[i] <= *R[j])
                indices[k++] = L[i++];
            else
                indices[k++] = R[j++];
        }

        while (i < n1)
            indices[k++] = L[i++];

        while (j < n2)
            indices[k++] = R[j++];
    }

    void ordenar(int l, int r) {
        if (l < r) {
            int m = (l + r) / 2;
            ordenar(l, m);
            ordenar(m + 1, r);
            merge(l, m, r);
        }
    }

    void imprimir() {
        for (int i = 0; i < n; i++)
            cout << *indices[i] << " ";
        cout << endl;
    }
};

#endif