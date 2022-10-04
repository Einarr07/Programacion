#include <iostream>
using namespace std;

int main()
{
    int num;
    cout << "Introduce un numero entre 1 y 10: ";
    cin >> num;

    if ((num >= 1) && (num <= 10)) {
        cout << "Numero dentro del intervalo de valores validos";
    }
    else {
        cout << "Numero no valido!";
    }
    return 0;
}