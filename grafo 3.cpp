#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <fstream>
#include <algorithm>
#include <utility> // Agregado para usar std::pair

using namespace std;

class Grafo {
private:
    // La lista ahora guarda pares: Nodo -> Vector de [Destino, Peso]
    map<string, vector<pair<string, int>>> adjList;

    // Se agrego el parametro 'costoAcumulado'
    void buscarRutasDFS(string actual, string destino, map<string, bool>& visitado, vector<string>& rutaActual, bool& encontroRuta, int costoAcumulado) {
        visitado[actual] = true;
        rutaActual.push_back(actual);

        if (actual == destino) {
            encontroRuta = true;
            cout << " -> Ruta: ";
            for (size_t i = 0; i < rutaActual.size(); i++) {
                cout << rutaActual[i] << (i == rutaActual.size() - 1 ? "" : " -> ");
            }
            // Al final de la ruta, mostramos lo gastado
            cout << " | Gasto Total: " << costoAcumulado << endl;
        } else {
            // Iteramos sobre los pares (vecino, peso)
            for (const auto& arista : adjList[actual]) {
                string vecino = arista.first;
                int peso = arista.second;
                
                if (!visitado[vecino]) {
                    buscarRutasDFS(vecino, destino, visitado, rutaActual, encontroRuta, costoAcumulado + peso);
                }
            }
        }

        rutaActual.pop_back();
        visitado[actual] = false;
    }

public:
    void agregarNodo(const string& u) {
        if (adjList.find(u) == adjList.end()) {
            adjList[u] = vector<pair<string, int>>();
            cout << "[Ok] Nodo '" << u << "' agregado correctamente." << endl;
        } else {
            cout << "[Aviso] El nodo '" << u << "' ya existe." << endl;
        }
    }

    void eliminarNodo(const string& u) {
        if (adjList.find(u) == adjList.end()) {
            cout << "[Error] El nodo '" << u << "' no existe." << endl;
            return;
        }
        adjList.erase(u);
        for (auto& par : adjList) {
            auto& vecinos = par.second;
            // Utilizamos remove_if con una expresion lambda para buscar en el pair
            vecinos.erase(remove_if(vecinos.begin(), vecinos.end(),
                          [&u](const pair<string, int>& p) { return p.first == u; }), 
                          vecinos.end());
        }
        cout << "[Ok] Nodo '" << u << "' y todas sus conexiones eliminados." << endl;
    }

    // Se agrego el parametro 'peso'
    void agregarArista(const string& u, const string& v, int peso) {
        if (adjList.find(u) == adjList.end()) adjList[u] = vector<pair<string, int>>();
        if (adjList.find(v) == adjList.end()) adjList[v] = vector<pair<string, int>>();
        
        adjList[u].push_back(make_pair(v, peso));
        cout << "[Ok] Ruta agregada: " << u << " -> " << v << " (Peso: " << peso << ")" << endl;
    }

    void eliminarArista(const string& u, const string& v) {
        if (adjList.find(u) != adjList.end()) {
            auto& vecinos = adjList[u];
            auto it = remove_if(vecinos.begin(), vecinos.end(),
                                [&v](const pair<string, int>& p) { return p.first == v; });
            if (it != vecinos.end()) {
                vecinos.erase(it, vecinos.end());
                cout << "[Ok] Ruta hacia '" << v << "' eliminada desde '" << u << "'." << endl;
            } else {
                cout << "[Error] No existe una ruta directa de '" << u << "' a '" << v << "'." << endl;
            }
        } else {
            cout << "[Error] El nodo origen '" << u << "' no existe." << endl;
        }
    }

    void mostrarGrafo() {
        cout << "\n================ ESTADO DEL GRAFO ================" << endl;
        if (adjList.empty()) {
            cout << "El grafo esta vacio." << endl;
        }
        for (const auto& par : adjList) {
            cout << "  Nodo [" << par.first << "] conecta con: ";
            if (par.second.empty()) cout << "(Ninguno)";
            for (const auto& arista : par.second) {
                cout << "[" << arista.first << "|$" << arista.second << "] ";
            }
            cout << endl;
        }
        cout << "==================================================\n" << endl;
    }

    void mostrarRutas(const string& origen, const string& destino) {
        if (adjList.find(origen) == adjList.end() || adjList.find(destino) == adjList.end()) {
            cout << "[Error] Uno o ambos nodos no existen en el grafo." << endl;
            return;
        }

        map<string, bool> visitado;
        vector<string> rutaActual;
        bool encontroRuta = false;
        
        for (const auto& par : adjList) visitado[par.first] = false;
        
        cout << "\nBuscando rutas desde '" << origen << "' hasta '" << destino << "':" << endl;
        
        // Iniciamos con costoAcumulado = 0
        buscarRutasDFS(origen, destino, visitado, rutaActual, encontroRuta, 0);

        if (!encontroRuta) {
            cout << "No se encontraron rutas disponibles de '" << origen << "' a '" << destino << "'." << endl;
        }
        cout << endl;
    }

    void guardarSalidaJSON(const string& nombreArchivo) {
        ofstream archivo(nombreArchivo);
        if (!archivo.is_open()) {
            cerr << "[Error] No se pudo crear el archivo JSON." << endl;
            return;
        }

        archivo << "{\n";
        archivo << "  \"grafo\": {\n";
        
        int contadorNodos = 0;
        for (const auto& par : adjList) {
            archivo << "    \"" << par.first << "\": [";
            for (size_t i = 0; i < par.second.size(); ++i) {
                // Guardamos el formato "Destino:Peso"
                archivo << "\"" << par.second[i].first << ":" << par.second[i].second << "\"";
                if (i < par.second.size() - 1) archivo << ", ";
            }
            archivo << "]";
            
            if (contadorNodos < adjList.size() - 1) archivo << ",";
            archivo << "\n";
            contadorNodos++;
        }
        
        archivo << "  }\n";
        archivo << "}\n";
        archivo.close();
        
        cout << "[Exito] Estructura exportada correctamente a: " << nombreArchivo << endl;
    }

    void cargarDesdeJSON(const string& nombreArchivo) {
        ifstream archivo(nombreArchivo);
        if (!archivo.is_open()) {
            cerr << "[Error] No se encontro el archivo '" << nombreArchivo << "'." << endl;
            return;
        }

        adjList.clear(); 
        string linea;
        string nodoOrigen = "";

        while (getline(archivo, linea)) {
            size_t posDosPuntos = linea.find("\": [");
            if (posDosPuntos != string::npos) {
                size_t posPrimeraComilla = linea.find_first_of("\"");
                nodoOrigen = linea.substr(posPrimeraComilla + 1, posDosPuntos - posPrimeraComilla - 1);
                
                if (adjList.find(nodoOrigen) == adjList.end()) {
                    adjList[nodoOrigen] = vector<pair<string, int>>();
                }

                size_t posFinArreglo = linea.find("]");
                if (posFinArreglo != string::npos) {
                    string arregloV = linea.substr(posDosPuntos + 3, posFinArreglo - (posDosPuntos + 3));
                    
                    size_t posInicioV = arregloV.find("\"");
                    while (posInicioV != string::npos) {
                        size_t posFinV = arregloV.find("\"", posInicioV + 1);
                        if (posFinV != string::npos) {
                            string vecinoRaw = arregloV.substr(posInicioV + 1, posFinV - posInicioV - 1);
                            
                            // Separar el nombre del vecino y su peso usando el caracter ":"
                            size_t separador = vecinoRaw.find(":");
                            string vecino = (separador != string::npos) ? vecinoRaw.substr(0, separador) : vecinoRaw;
                            int peso = (separador != string::npos) ? stoi(vecinoRaw.substr(separador + 1)) : 0; // 0 por defecto si no hay peso
                            
                            adjList[nodoOrigen].push_back(make_pair(vecino, peso));
                            
                            if (adjList.find(vecino) == adjList.end()) {
                                adjList[vecino] = vector<pair<string, int>>();
                            }
                            
                            posInicioV = arregloV.find("\"", posFinV + 1);
                        } else {
                            break;
                        }
                    }
                }
            }
        }
        archivo.close();
        cout << "[Exito] Grafo reconstruido desde el archivo: " << nombreArchivo << endl;
    }
};

int main() {
    Grafo g;

    // Inicialización automática con 5 nodos y pesos aleatorios
    g.agregarArista("A", "B", 10);
    g.agregarArista("B", "C", 25);
    g.agregarArista("C", "D", 5);
    g.agregarArista("D", "E", 100);
    g.agregarArista("E", "A", 50);
    g.agregarArista("B", "D", 40);
    g.agregarArista("C", "C", 0); // Loop sin costo

    int opcion, peso;
    string nodo1, nodo2, archivo;

    do {
        cout << "\n--- MENU GESTION DE GRAFOS PONDERADOS ---" << endl;
        cout << "1. Mostrar Grafo actual" << endl;
        cout << "2. Agregar Nodo" << endl;
        cout << "3. Eliminar Nodo" << endl;
        cout << "4. Agregar Arista y su Peso" << endl;
        cout << "5. Eliminar Arista" << endl;
        cout << "6. Buscar Rutas y calcular Costo Total" << endl;
        cout << "7. Guardar Grafo en JSON" << endl;
        cout << "8. Cargar Grafo desde JSON" << endl;
        cout << "9. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                g.mostrarGrafo();
                break;
            case 2:
                cout << "Ingrese el nombre del nuevo nodo: ";
                cin >> nodo1;
                g.agregarNodo(nodo1);
                break;
            case 3:
                cout << "Ingrese el nombre del nodo a eliminar: ";
                cin >> nodo1;
                g.eliminarNodo(nodo1);
                break;
            case 4:
                cout << "Ingrese nodo origen: ";
                cin >> nodo1;
                cout << "Ingrese nodo destino: ";
                cin >> nodo2;
                cout << "Ingrese el peso (costo) de esta ruta: ";
                cin >> peso;
                g.agregarArista(nodo1, nodo2, peso);
                break;
            case 5:
                cout << "Ingrese nodo origen: ";
                cin >> nodo1;
                cout << "Ingrese nodo destino: ";
                cin >> nodo2;
                g.eliminarArista(nodo1, nodo2);
                break;
            case 6:
                cout << "Ingrese nodo de origen: ";
                cin >> nodo1;
                cout << "Ingrese nodo de destino: ";
                cin >> nodo2;
                g.mostrarRutas(nodo1, nodo2);
                break;
            case 7:
                cout << "Nombre del archivo a guardar (ej. grafo.json): ";
                cin >> archivo;
                g.guardarSalidaJSON(archivo);
                break;
            case 8:
                cout << "Nombre del archivo a cargar (ej. grafo.json): ";
                cin >> archivo;
                g.cargarDesdeJSON(archivo);
                break;
            case 9:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "[Opcion Invalida] Reintente de nuevo." << endl;
        }
    } while (opcion != 9);

    return 0;
}