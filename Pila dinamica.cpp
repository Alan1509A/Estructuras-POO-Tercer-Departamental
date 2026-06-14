#include <iostream>
#include <fstream> 
using namespace std;

class Estructura {
public:
    virtual void insertar(int x)=0;
    virtual void eliminar()=0;
    virtual void mostrar()=0;
    virtual void guardarEnArchivos(string nombre)=0; // Metodo base
};

class Nodo{
public:
    int dato;
    Nodo* sig;
    Nodo(int x){ dato=x; sig=NULL; }
};

class PilaDinamica : public Estructura {
private:
    Nodo* tope;

public:
    PilaDinamica(){ tope=NULL; }

    void insertar(int x){
        Nodo* nuevo = new Nodo(x);
        nuevo->sig = tope;
        tope = nuevo;
    }

    void eliminar(){
        if(tope){
            Nodo* aux = tope;
            tope = tope->sig;
            delete aux;
        }
    }

    void mostrar(){
        Nodo* aux = tope;
        while(aux){
            cout<<aux->dato<<" ";
            aux=aux->sig;
        }
        cout<<endl;
    }

    void guardarEnArchivos(string nombre){
        // Guardar TXT
        ofstream txt(nombre + ".txt");
        if(txt.is_open()){
            Nodo* aux = tope;
            while(aux){ txt << aux->dato << "\n"; aux = aux->sig; }
            txt.close();
            cout << " [TXT] " << nombre << ".txt generado.\n";
        }
        // Guardar JSON
        ofstream json(nombre + ".json");
        if(json.is_open()){
            json << "[\n";
            Nodo* aux = tope;
            while(aux){
                json << "  " << aux->dato;
                if(aux->sig != NULL) json << ","; // Coma si hay siguiente
                json << "\n";
                aux = aux->sig;
            }
            json << "]\n";
            json.close();
            cout << " [JSON] " << nombre << ".json generado.\n";
        }
    }
};

int main(){
    Estructura* pila = new PilaDinamica();
    int op,val;

    do{
        cout<<"\n1.Push 2.Pop 3.Mostrar 4.Guardar en Archivos 0.Salir\nOpcion: ";
        cin>>op;

        switch(op){
            case 1: cout<<"Valor: "; cin>>val; pila->insertar(val); break;
            case 2: pila->eliminar(); break;
            case 3: pila->mostrar(); break;
            case 4: pila->guardarEnArchivos("PilaDinamicaSalida"); break;
        }
    }while(op!=0);

    delete pila;
    return 0;
}