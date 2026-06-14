#include <iostream>
#include <fstream>
using namespace std;

class Estructura {
public:
    virtual void insertar(int x)=0;
    virtual void eliminar()=0;
    virtual void mostrar()=0;
    virtual void guardarEnArchivos(string nombre)=0;
};

class Nodo{
public:
    int dato;
    Nodo* sig;
    Nodo(int x){ dato=x; sig=NULL; }
};

class ListaDinamica : public Estructura {
private:
    Nodo* inicio;

public:
    ListaDinamica(){ inicio=NULL; }

    void insertar(int x){
        Nodo* nuevo=new Nodo(x);
        nuevo->sig=inicio;
        inicio=nuevo;
    }

    void eliminar(){
        if(inicio){
            Nodo* aux=inicio;
            inicio=inicio->sig;
            delete aux;
        }
    }

    void mostrar(){
        Nodo* aux=inicio;
        while(aux){
            cout<<aux->dato<<" ";
            aux=aux->sig;
        }
        cout<<endl;
    }

    void guardarEnArchivos(string nombre){
        ofstream txt(nombre + ".txt");
        if(txt.is_open()){
            Nodo* aux = inicio;
            while(aux){ txt << aux->dato << "\n"; aux = aux->sig; }
            txt.close();
            cout << " [TXT] " << nombre << ".txt generado.\n";
        }
        ofstream json(nombre + ".json");
        if(json.is_open()){
            json << "[\n";
            Nodo* aux = inicio;
            while(aux){
                json << "  " << aux->dato;
                if(aux->sig != NULL) json << ",";
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
    Estructura* lista = new ListaDinamica();
    int op,val;

    do{
        cout<<"\n1.Insertar 2.Eliminar 3.Mostrar 4.Guardar en Archivos 0.Salir\nOpcion: ";
        cin>>op;

        switch(op){
            case 1: cout<<"Valor: "; cin>>val; lista->insertar(val); break;
            case 2: lista->eliminar(); break;
            case 3: lista->mostrar(); break;
            case 4: lista->guardarEnArchivos("ListaDinamicaSalida"); break;
        }
    }while(op!=0);

    delete lista;
    return 0;
}