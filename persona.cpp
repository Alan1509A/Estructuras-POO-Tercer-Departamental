#include <iostream>
#include <fstream>

using namespace std;

class Persona
{
private:
    string nombre;
    int edad;

public:
    Persona(string n,int e)
    {
        nombre=n;
        edad=e;
    }

    string getNombre(){ return nombre; }
    int getEdad(){ return edad; }
};

int main()
{
    Persona p("Juan",20);

    ofstream archivo("persona.csv");

    archivo << "Nombre,Edad\n";
    archivo << p.getNombre() << "," << p.getEdad() << "\n";

    archivo.close();
    return 0;
}