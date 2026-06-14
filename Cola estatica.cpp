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

class ColaEstatica : public Estructura {
private:
    int arr[5];
    int frente, fin;

public:
    ColaEstatica(){ frente=0; fin=0; }

    void insertar(int x){
        if(fin<5) arr[fin++]=x;
    }

    void eliminar(){
        if(frente<fin) frente++;
    }

    void mostrar(){
        for(int i=frente;i<fin;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }

    void guardarEnArchivos(string nombre){
        ofstream txt(nombre + ".txt");
        if(txt.is_open()){
            for(int i=frente; i<fin; i++) txt << arr[i] << "\n";
            txt.close();
            cout << " [TXT] " << nombre << ".txt generado.\n";
        }
        ofstream json(nombre + ".json");
        if(json.is_open()){
            json << "[\n";
            for(int i=frente; i<fin; i++){
                json << "  " << arr[i];
                if(i < fin - 1) json << ","; 
                json << "\n";
            }
            json << "]\n";
            json.close();
            cout << " [JSON] " << nombre << ".json generado.\n";
        }
    }
};

int main(){
    Estructura* cola = new ColaEstatica();
    int op, val;

    do{
        cout<<"\n1.Insertar 2.Eliminar 3.Mostrar 4.Guardar en Archivos 0.Salir\nOpcion: ";
        cin>>op;

        switch(op){
            case 1: cout<<"Valor: "; cin>>val; cola->insertar(val); break;
            case 2: cola->eliminar(); break;
            case 3: cola->mostrar(); break;
            case 4: cola->guardarEnArchivos("ColaEstaticaSalida"); break;
        }
    }while(op!=0);

    delete cola;
    return 0;
}