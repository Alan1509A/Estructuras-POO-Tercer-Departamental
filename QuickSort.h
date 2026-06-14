#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "Ordenador.h"

template <typename T>
class QuickSort : public Ordenador<T> {
public:
    QuickSort(T a[], int size) : Ordenador<T>(a, size) {}

    int particion(int low, int high) {
        T pivot = this->arr[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (this->arr[j] < pivot) {
                i++;
                swap(this->arr[i], this->arr[j]);
            }
        }
        swap(this->arr[i + 1], this->arr[high]);
        return i + 1;
    }

    void ordenar(int low, int high) {
        if (low < high) {
            int pi = particion(low, high);
            ordenar(low, pi - 1);
            ordenar(pi + 1, high);
        }
    }
};

#endif