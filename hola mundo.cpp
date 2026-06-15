#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream archivo("hola.csv");

    archivo << "Mensaje\n";
    archivo << "Hola Mundo\n";

    archivo.close();
    return 0;
}