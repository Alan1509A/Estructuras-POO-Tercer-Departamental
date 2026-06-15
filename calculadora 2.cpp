#include <iostream>
#include <fstream>

using namespace std;

class Calculadora
{
public:
    int suma(int a,int b){ return a+b; }
    int resta(int a,int b){ return a-b; }
    int mult(int a,int b){ return a*b; }
    float div(int a,int b){ return (float)a/b; }
};

int main()
{
    int a,b;

    cin >> a;
    cin >> b;

    Calculadora c;

    ofstream archivo("calculadora.csv");

    archivo << "Operacion,Resultado\n";
    archivo << "Suma," << c.suma(a,b) << "\n";
    archivo << "Resta," << c.resta(a,b) << "\n";
    archivo << "Multiplicacion," << c.mult(a,b) << "\n";
    archivo << "Division," << c.div(a,b) << "\n";

    archivo.close();
    return 0;
}