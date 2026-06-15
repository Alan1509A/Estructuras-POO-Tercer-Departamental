#include <iostream>
#include <fstream>

using namespace std;

class CalculadoraBase
{
public:
    int suma(int a,int b){ return a+b; }
};

class CalculadoraNueva : public CalculadoraBase
{
public:
    int mult(int a,int b){ return a*b; }
};

int main()
{
    CalculadoraNueva c;

    ofstream archivo("herencia.csv");

    archivo << "Operacion,Resultado\n";
    archivo << "Suma," << c.suma(5,10) << "\n";
    archivo << "Multiplicacion," << c.mult(5,10) << "\n";

    archivo.close();
    return 0;
}