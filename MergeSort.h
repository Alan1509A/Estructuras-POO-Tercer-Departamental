#ifndef MERGESORT_H
#define MERGESORT_H

#include "Ordenador.h"

template <typename T>
class MergeSort : public Ordenador<T> {
public:
    MergeSort(T a[], int size) : Ordenador<T>(a, size) {}

    void merge(int l, int m, int r) {
        int n1 = m - l + 1;
        int n2 = r - m;

        T L[n1], R[n2];

        for (int i = 0; i < n1; i++)
            L[i] = this->arr[l + i];
        for (int j = 0; j < n2; j++)
            R[j] = this->arr[m + 1 + j];

        int i = 0, j = 0, k = l;

        while (i < n1 && j < n2) {
            if (L[i] <= R[j])
                this->arr[k++] = L[i++];
            else
                this->arr[k++] = R[j++];
        }

        while (i < n1)
            this->arr[k++] = L[i++];

        while (j < n2)
            this->arr[k++] = R[j++];
    }

    void ordenar(int l, int r) {
        if (l < r) {
            int m = (l + r) / 2;
            ordenar(l, m);
            ordenar(m + 1, r);
            merge(l, m, r);
        }
    }
};

#endif