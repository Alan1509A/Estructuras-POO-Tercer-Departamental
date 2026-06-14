#ifndef PILA_H
#define PILA_H

#include <iostream>
#include <fstream> // Necesario para crear archivos aqui adentro
using namespace std;

class Pila {
private:
    int arr[100];
    int top;

public:
    Pila() { top = -1; }

    void push(int x) {
        if (top < 99) arr[++top] = x;
    }

    void pop() {
        if (top >= 0) top--;
    }

    void mostrar() {
        for (int i = top; i >= 0; i--)
            cout << arr[i] << endl;
    }

    // --- NUEVA FUNCION PARA ARCHIVOS ---
    void guardarEnArchivos() {
        // Guardar TXT
        ofstream txt("PilaSalida.txt");
        if(txt.is_open()) {
            for (int i = top; i >= 0; i--) txt << arr[i] << "\n";
            txt.close();
            cout << " [TXT] PilaSalida.txt generado." << endl;
        }
        
        // Guardar JSON
        ofstream json("PilaSalida.json");
        if(json.is_open()) {
            json << "[\n";
            for (int i = top; i >= 0; i--) {
                json << "  " << arr[i];
                if (i > 0) json << ","; // Controlamos la coma final
                json << "\n";
            }
            json << "]\n";
            json.close();
            cout << " [JSON] PilaSalida.json generado." << endl;
        }
    }
};

#endif