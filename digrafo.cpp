#include <iostream>
#include <fstream>

using namespace std;

class Digrafo{

private:
    int matriz[4][4];

public:

    Digrafo(){

        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++)
                matriz[i][j]=0;
    }

    void conectar(int origen,int destino){

        matriz[origen][destino]=1;
    }

    void mostrar(){

        cout<<"\nDigrafo:\n";

        for(int i=0;i<4;i++){

            for(int j=0;j<4;j++){

                cout<<matriz[i][j]<<" ";
            }

            cout<<endl;
        }
    }

    void guardarJSON(){

        ofstream archivo("digrafo.json");

        archivo<<"{\n";
        archivo<<"\"matriz\":[";

        for(int i=0;i<4;i++){

            archivo<<"[";

            for(int j=0;j<4;j++){

                archivo<<matriz[i][j];

                if(j<3)
                    archivo<<",";
            }

            archivo<<"]";

            if(i<3)
                archivo<<",";
        }

        archivo<<"]\n}";

        archivo.close();

        cout<<"\nGuardado en digrafo.json\n";
    }
};

int main(){

    Digrafo d;

    int op,a,b;

    do{

        cout<<"\n1. Agregar direccion";
        cout<<"\n2. Mostrar digrafo";
        cout<<"\n3. Guardar JSON";
        cout<<"\n4. Salir";
        cout<<"\nOpcion: ";
        cin>>op;

        switch(op){

            case 1:

                cout<<"Origen: ";
                cin>>a;

                cout<<"Destino: ";
                cin>>b;

                d.conectar(a,b);
                break;

            case 2:
                d.mostrar();
                break;

            case 3:
                d.guardarJSON();
                break;
        }

    }while(op!=4);

    return 0;
}