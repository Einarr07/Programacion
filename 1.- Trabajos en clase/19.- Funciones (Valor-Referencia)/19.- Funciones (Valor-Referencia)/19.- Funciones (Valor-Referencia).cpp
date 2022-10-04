#include <iostream>
using namespace std;
//
int porValor(int i);
void porReferencia(int& j);
//
int main()
{
    int i = 5, j = 6;
    cout << "i antes de llamar a la funcion: " << i << endl;
    cout << "El cuadro de i: " << porValor(i) << endl;
    cout << "i despues de llamar a la funcion: " << i << endl;
    cout << endl;
    cout << "j antes de llamar a la funcion: " << j << endl;
    porReferencia(j);
    cout << "El cuadro de j: " << j << endl;
    cout << "j despues de llamar a la funcion: " << j << endl;
    return 0;
}
//
int porValor(int x)
{
    x = x * x;
    return x;
}
//
void porReferencia(int& y)
{
    y = y * y;

}