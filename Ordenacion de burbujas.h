#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include "Ordenador.h"

template <typename T>
class BubbleSort : public Ordenador<T> {
public:
    BubbleSort(T a[], int size) : Ordenador<T>(a, size) {}

    void ordenar() {
        for (int i = 0; i < this->n - 1; i++) {
            for (int j = 0; j < this->n - i - 1; j++) {
                if (this->arr[j] > this->arr[j + 1]) {
                    swap(this->arr[j], this->arr[j + 1]);
                }
            }
        }
    }
};

#endif