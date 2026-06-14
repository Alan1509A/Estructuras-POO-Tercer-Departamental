#ifndef GESTORARCHIVOS_H
#define GESTORARCHIVOS_H

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

template <typename T>
class GestorArchivos {
public:
    // Guardar arreglo en TXT
    static void guardarTXT(T arr[], int n, string nombreArchivo) {
        ofstream archivo(nombreArchivo.c_str());
        if (archivo.is_open()) {
            for (int i = 0; i < n; i++) {
                archivo << arr[i] << "\n";
            }
            archivo.close();
            cout << " [TXT] '" << nombreArchivo << "' generado exitosamente." << endl;
        } else {
            cout << " [ERROR] No se pudo crear " << nombreArchivo << endl;
        }
    }

    // Guardar arreglo en JSON
    static void guardarJSON(T arr[], int n, string nombreArchivo) {
        ofstream archivo(nombreArchivo.c_str());
        if (archivo.is_open()) {
            archivo << "[\n";
            for (int i = 0; i < n; i++) {
                archivo << "  " << arr[i];
                // Agrega una coma si no es el ultimo elemento
                if (i < n - 1) archivo << ",";
                archivo << "\n";
            }
            archivo << "]\n";
            archivo.close();
            cout << " [JSON] '" << nombreArchivo << "' generado exitosamente." << endl;
        } else {
            cout << " [ERROR] No se pudo crear " << nombreArchivo << endl;
        }
    }
};

#endif