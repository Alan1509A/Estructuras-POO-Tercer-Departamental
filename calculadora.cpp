#include <iostream>
#include <fstream>

using namespace std;

class Suma
{
private:
    int a,b,resultado;

public:
    Suma(int x,int y)
    {
        a=x;
        b=y;
        resultado=a+b;
    }

    int getA(){ return a; }
    int getB(){ return b; }
    int getResultado(){ return resultado; }
};

int main()
{
    int a,b;

    cin >> a;
    cin >> b;

    Suma s(a,b);

    ofstream archivo("suma.csv");

    archivo << "A,B,Resultado\n";
    archivo << s.getA() << "," << s.getB() << "," << s.getResultado();

    archivo.close();
    return 0;
}