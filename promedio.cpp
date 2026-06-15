#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int n[5];
    int suma=0;

    for(int i=0;i<5;i++)
    {
        cin >> n[i];
        suma += n[i];
    }

    float promedio = suma / 5.0;

    ofstream archivo("promedio.csv");

    archivo << "Suma,Promedio\n";
    archivo << suma << "," << promedio << "\n";

    archivo.close();
    return 0;
}