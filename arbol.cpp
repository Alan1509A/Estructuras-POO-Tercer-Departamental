#include <iostream>
#include <fstream>

using namespace std;

class Nodo{

public:

    int dato;
    Nodo* izq;
    Nodo* der;

    Nodo(int d){

        dato=d;
        izq=NULL;
        der=NULL;
    }
};

class Arbol{

private:

    Nodo* raiz;

    void insertarRec(Nodo*& nodo,int valor){

        if(nodo==NULL){

            nodo=new Nodo(valor);
            return;
        }

        if(valor<nodo->dato)
            insertarRec(nodo->izq,valor);

        else
            insertarRec(nodo->der,valor);
    }

    void mostrarRec(Nodo* nodo){

        if(nodo==NULL)
            return;

        mostrarRec(nodo->izq);

        cout<<nodo->dato<<" ";

        mostrarRec(nodo->der);
    }

    void guardarRec(Nodo* nodo,ofstream& archivo){

        if(nodo==NULL)
            return;

        archivo<<nodo->dato<<" ";

        guardarRec(nodo->izq,archivo);

        guardarRec(nodo->der,archivo);
    }

public:

    Arbol(){

        raiz=NULL;
    }

    void insertar(int valor){

        insertarRec(raiz,valor);
    }

    void mostrar(){

        mostrarRec(raiz);
        cout<<endl;
    }

    void guardarJSON(){

        ofstream archivo("arbol.json");

        archivo<<"{\n";
        archivo<<"\"datos\":\"";

        guardarRec(raiz,archivo);

        archivo<<"\"\n}";

        archivo.close();

        cout<<"\nGuardado en arbol.json\n";
    }
};

int main(){

    Arbol a;

    int op,valor;

    do{

        cout<<"\n1. Insertar nodo";
        cout<<"\n2. Mostrar arbol";
        cout<<"\n3. Guardar JSON";
        cout<<"\n4. Salir";
        cout<<"\nOpcion: ";
        cin>>op;

        switch(op){

            case 1:

                cout<<"Valor: ";
                cin>>valor;

                a.insertar(valor);
                break;

            case 2:
                a.mostrar();
                break;

            case 3:
                a.guardarJSON();
                break;
        }

    }while(op!=4);

    return 0;
}