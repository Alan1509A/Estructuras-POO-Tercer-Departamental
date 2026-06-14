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

class ColaDinamica : public Estructura {
private:
    Nodo *frente,*fin;

public:
    ColaDinamica(){ frente=fin=NULL; }

    void insertar(int x){
        Nodo* nuevo=new Nodo(x);
        if(!fin) frente=fin=nuevo;
        else{
            fin->sig=nuevo;
            fin=nuevo;
        }
    }

    void eliminar(){
        if(frente){
            Nodo* aux=frente;
            frente=frente->sig;
            if(!frente) fin=NULL; 
            delete aux;
        }
    }

    void mostrar(){
        Nodo* aux=frente;
        while(aux){
            cout<<aux->dato<<" ";
            aux=aux->sig;
        }
        cout<<endl;
    }

    void guardarEnArchivos(string nombre){
        ofstream txt(nombre + ".txt");
        if(txt.is_open()){
            Nodo* aux = frente;
            while(aux){ txt << aux->dato << "\n"; aux = aux->sig; }
            txt.close();
            cout << " [TXT] " << nombre << ".txt generado.\n";
        }
        ofstream json(nombre + ".json");
        if(json.is_open()){
            json << "[\n";
            Nodo* aux = frente;
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
    Estructura* cola = new ColaDinamica();
    int op,val;

    do{
        cout<<"\n1.Enqueue 2.Dequeue 3.Mostrar 4.Guardar en Archivos 0.Salir\nOpcion: ";
        cin>>op;

        switch(op){
            case 1: cout<<"Valor: "; cin>>val; cola->insertar(val); break;
            case 2: cola->eliminar(); break;
            case 3: cola->mostrar(); break;
            case 4: cola->guardarEnArchivos("ColaDinamicaSalida"); break;
        }
    }while(op!=0);

    delete cola;
    return 0;
}