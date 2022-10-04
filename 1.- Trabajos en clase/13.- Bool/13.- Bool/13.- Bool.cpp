#include <iostream>
using namespace std;

int main()
{
    char caracter1 = 'A', caracter2 = '1', caracter3 = '&';
    bool resultado;
    int a = 2, b = 3, c = 4;

    resultado = a < 5;
    cout << "Resultado: " << resultado << endl;
    resultado = a * b + c >= 12;        // 10 >= 12 -> False
    cout << "Resultado: " << resultado << endl;
    resultado = a * (b + c) >= 12;      //14 >= 12 -> True
    cout << "Resultado: " << resultado << endl;
    resultado = a != b;                    // 2 != 3 -> True
    cout << "Resultado: " << resultado << endl;
    resultado = a * b > c + 5;      // 6 > 9 -> False
    cout << "Resultado: " << resultado << endl;
    resultado = a + b == c + 1;     // 5 == 5 -> True 
    cout << "Resultado: " << resultado << endl;

    return 0;
}