#include <iostream>
using namespace std;
//
void tablas(int tabla, int& contador);
//
int main()
{
    int numTablas, numMultiplicar = 0;
    cout << "Hasta que numero desea calcular las tablas: " << endl;
    cin >> numTablas;
    for (int i = 1; i <= numTablas; i++)
    {
        cout << "Tabla del " << i << endl;
        cout << "---------------" << endl;
        tablas(i, numMultiplicar);
        cout << endl;

    }
    cout << "Numero de multiplicarciones " << numMultiplicar << endl;
    return 0;
}
//
void tablas(int tabla, int& contador)
{
    for (int j = 1; j <= 10; j++)
    {
        cout << tabla << " x" << j << " = " << tabla * j << endl;
        contador++;
    }
    cout << endl;
}