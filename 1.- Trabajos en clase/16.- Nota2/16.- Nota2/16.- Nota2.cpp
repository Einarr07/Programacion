#include <iostream>
using namespace std;

int main()
{
    int nota;
    cout << "Nota (0-10): ";
    cin >> nota;
    switch (nota) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    {
        cout << "Suspenso";
    }
    break;
    //
    case 5:
    case 6:
    {
        cout << "Aprobado";
    }
    break;
    //
    case 7:
    case 8:
    {
        cout << "Notable";
    }
    break;
    //
    case 9:
    case 10:
    {
        cout << "Sobresaliente";
    }
    break;
    //
    default:
    {
        cout << "¡No valido!";
    }
    }
}