#include <iostream>
using namespace std;

int main()
{
    double a, b, aux;
    cout << "Por favor ingrese el primer valor" << endl;
    cin >> a;
    cout << "Por favor ingrese el segundo valor" << endl;
    cin >> b;

    cout << "el valor de a es: " << a << endl;
    cout << "el valor de b es: " << b << endl;

    //intercambio

    aux = a;

    a = b;

    b = aux;

    cout << "el valor de a es: " << a << endl;

    cout << "el valor de b es: " << b << endl;
}