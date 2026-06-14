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

class ListaEstatica : public Estructura {
private:
    int arr[5];
    int n;

public:
    ListaEstatica(){ n=0; }

    void insertar(int x){
        if(n<5) arr[n++]=x;
    }

    void eliminar(){
        if(n>0) n--;
    }

    void mostrar(){
        for(int i=0;i<n;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }

    void guardarEnArchivos(string nombre){
        ofstream txt(nombre + ".txt");
        if(txt.is_open()){
            for(int i=0; i<n; i++) txt << arr[i] << "\n";
            txt.close();
            cout << " [TXT] " << nombre << ".txt generado.\n";
        }
        ofstream json(nombre + ".json");
        if(json.is_open()){
            json << "[\n";
            for(int i=0; i<n; i++){
                json << "  " << arr[i];
                if(i < n - 1) json << ",";
                json << "\n";
            }
            json << "]\n";
            json.close();
            cout << " [JSON] " << nombre << ".json generado.\n";
        }
    }
};

int main(){
    Estructura* lista = new ListaEstatica();
    int op,val;

    do{
        cout<<"\n1.Insertar 2.Eliminar 3.Mostrar 4.Guardar en Archivos 0.Salir\nOpcion: ";
        cin>>op;

        switch(op){
            case 1: cout<<"Valor: "; cin>>val; lista->insertar(val); break;
            case 2: lista->eliminar(); break;
            case 3: lista->mostrar(); break;
            case 4: lista->guardarEnArchivos("ListaEstaticaSalida"); break;
        }
    }while(op!=0);

    delete lista;
    return 0;
}