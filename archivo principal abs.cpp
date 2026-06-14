#include <iostream>
#include "BubbleSort.h"
#include "QuickSort.h"
#include "MergeSort.h"
#include "BubbleIndirecto.h"
#include "QuickIndirecto.h"
#include "MergeIndirecto.h"
#include "Pila.h"
#include "ADT.h"
#include "ListaPunteros.h"
#include "GestorArchivos.h" 

using namespace std;

void limpiar() { system("cls"); }
void pausa() { system("pause"); }

// 📌 ORDENAMIENTO DIRECTO
void menuDirecto() {
    int op;
    do {
        limpiar();
        cout << "\n--- ORDENAMIENTO DIRECTO ---\n";
        cout << "1. Bubble Sort\n2. Quick Sort\n3. Merge Sort\n0. Regresar\nOpcion: ";
        cin >> op;

        int arr[] = {5, 3, 8, 1, 2};

        switch(op) {
            case 1: {
                BubbleSort<int> b(arr, 5);
                b.ordenar();
                b.imprimir();
                // Generamos los archivos
                GestorArchivos<int>::guardarTXT(arr, 5, "BubbleDirecto.txt");
                GestorArchivos<int>::guardarJSON(arr, 5, "BubbleDirecto.json");
                pausa();
                break;
            }
            case 2: {
                QuickSort<int> q(arr, 5);
                q.ordenar(0, 4);
                q.imprimir();
                GestorArchivos<int>::guardarTXT(arr, 5, "QuickDirecto.txt");
                GestorArchivos<int>::guardarJSON(arr, 5, "QuickDirecto.json");
                pausa();
                break;
            }
            case 3: {
                MergeSort<int> m(arr, 5);
                m.ordenar(0, 4);
                m.imprimir();
                GestorArchivos<int>::guardarTXT(arr, 5, "MergeDirecto.txt");
                GestorArchivos<int>::guardarJSON(arr, 5, "MergeDirecto.json");
                pausa();
                break;
            }
        }
    } while(op != 0);
}

// 📌 ORDENAMIENTO INDIRECTO
void menuIndirecto() {
    int op;
    do {
        limpiar();
        cout << "\n--- ORDENAMIENTO INDIRECTO ---\n";
        cout << "1. Bubble Indirecto\n2. Quick Indirecto\n3. Merge Indirecto\n0. Regresar\nOpcion: ";
        cin >> op;

        int arr[] = {10, 4, 7, 2, 9};

        switch(op) {
            case 1: {
                BubbleIndirecto<int> b(arr, 5);
                b.ordenar();
                b.imprimir();
                GestorArchivos<int>::guardarTXT(arr, 5, "BubbleIndirecto.txt");
                GestorArchivos<int>::guardarJSON(arr, 5, "BubbleIndirecto.json");
                pausa();
                break;
            }
            case 2: {
                QuickIndirecto<int> q(arr, 5);
                q.ordenar(0, 4);
                q.imprimir();
                GestorArchivos<int>::guardarTXT(arr, 5, "QuickIndirecto.txt");
                GestorArchivos<int>::guardarJSON(arr, 5, "QuickIndirecto.json");
                pausa();
                break;
            }
            case 3: {
                MergeIndirecto<int> m(arr, 5);
                m.ordenar(0, 4);
                m.imprimir();
                GestorArchivos<int>::guardarTXT(arr, 5, "MergeIndirecto.txt");
                GestorArchivos<int>::guardarJSON(arr, 5, "MergeIndirecto.json");
                pausa();
                break;
            }
        }
    } while(op != 0);
}

// 📌 PILA
void menuPila() {
    Pila p;
    int op, val;
    do {
        limpiar();
        cout << "\n--- PILA ---\n";
        cout << "1. Push\n2. Pop\n3. Mostrar\n4. Guardar en Archivos\n0. Regresar\nOpcion: ";
        cin >> op;
        switch(op) {
            case 1: cout << "Valor: "; cin >> val; p.push(val); break;
            case 2: p.pop(); break;
            case 3: p.mostrar(); pausa(); break;
            case 4: p.guardarEnArchivos(); pausa(); break; // Nueva opcion
        }
    } while(op != 0);
}


// ?? ADT
void menuADT() {
    ADT adt;
    int op, val;

    do {
        limpiar();
        cout << "\n--- ADT ---\n";
        cout << "1. Insertar\n";
        cout << "2. Eliminar\n";
        cout << "3. Buscar\n";
        cout << "4. Mostrar\n";
        cout << "0. Regresar\n";
        cout << "Opcion: ";
        cin >> op;

        switch(op) {
            case 1:
                cout << "Valor: ";
                cin >> val;
                adt.insertar(val);
                break;
            case 2:
                cout << "Valor: ";
                cin >> val;
                adt.eliminar(val);
                break;
            case 3:
                cout << "Valor: ";
                cin >> val;
                cout << (adt.buscar(val) ? "Encontrado\n" : "No encontrado\n");
                pausa();
                break;
            case 4:
                adt.mostrar();
                pausa();
                break;
        }
    } while(op != 0);
}

// ?? PUNTEROS (MANEJO INDIRECTO)
void menuPunteros() {
    ListaPunteros<int> lista;
    int op, val;

    do {
        limpiar();
        cout << "\n--- MANEJO INDIRECTO (PUNTEROS) ---\n";
        cout << "1. Insertar\n";
        cout << "2. Mostrar\n";
        cout << "0. Regresar\n";
        cout << "Opcion: ";
        cin >> op;

        switch(op) {
            case 1:
                cout << "Valor: ";
                cin >> val;
                lista.insertar(val);
                break;
            case 2:
                lista.mostrar();
                pausa();
                break;
        }
    } while(op != 0);
}

// ?? MEN  PRINCIPAL
int main() {
    int op;

    do {
        limpiar();
        cout << "\n===== MENU PRINCIPAL =====\n";
        cout << "1. Ordenamiento Directo\n";
        cout << "2. Ordenamiento Indirecto\n";
        cout << "3. Pila\n";
        cout << "4. ADT\n";
        cout << "5. Manejo indirecto con punteros\n";
        cout << "0. Salir\n";
        cout << "Opcion: ";
        cin >> op;

        switch(op) {
            case 1: menuDirecto(); break;
            case 2: menuIndirecto(); break;
            case 3: menuPila(); break;
            case 4: menuADT(); break;
            case 5: menuPunteros(); break;
        }

    } while(op != 0);

    return 0;
}