#include <iostream>
#include <fstream>

using namespace std;

class Grafo {

private:
    int matriz[5][5];

public:

    Grafo() {

        for(int i=0;i<5;i++)
            for(int j=0;j<5;j++)
                matriz[i][j]=0;
    }

    void conectar(int a,int b){

        matriz[a][b]=1;
        matriz[b][a]=1;
    }

    void mostrar(){

        cout<<"\nMatriz del grafo:\n";

        for(int i=0;i<5;i++){

            for(int j=0;j<5;j++){

                cout<<matriz[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    void guardarTXT(){

        ofstream archivo("grafo.txt");

        for(int i=0;i<5;i++){

            for(int j=0;j<5;j++){

                archivo<<matriz[i][j]<<" ";
            }

            archivo<<endl;
        }

        archivo.close();

        cout<<"\nGuardado en grafo.txt\n";
    }
};

int main(){

    Grafo g;

    int opcion,a,b;

    do{

        cout<<"\n1. Agregar conexion";
        cout<<"\n2. Mostrar grafo";
        cout<<"\n3. Guardar archivo TXT";
        cout<<"\n4. Salir";
        cout<<"\nOpcion: ";
        cin>>opcion;

        switch(opcion){

            case 1:

                cout<<"Nodo 1 (0-4): ";
                cin>>a;

                cout<<"Nodo 2 (0-4): ";
                cin>>b;

                g.conectar(a,b);
                break;

            case 2:
                g.mostrar();
                break;

            case 3:
                g.guardarTXT();
                break;
        }

    }while(opcion!=4);

    return 0;
}