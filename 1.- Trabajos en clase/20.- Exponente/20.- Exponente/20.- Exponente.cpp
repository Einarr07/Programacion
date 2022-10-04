#include <iostream>
using namespace std;

float potencia(float base, int exponente);

int main()
{
    int base, exponente;
    //
    cout << "***Este programa permite calcular las potencias***" << endl;
    cout << endl;
    cout << "Ingres por favor la base: ";
    cin >> base;
    cout << "Ingrese por favor el exponente: ";
    cin >> exponente;

    cout << "El resultado es: " << potencia(base, exponente) << endl;
    return 0;
}
//
float potencia(float base, int exponente)
{
    float resultado = 1;
    for (int i = 1; i <= exponente; i++)
    {
        resultado = resultado * base;
    }
    return resultado;
}