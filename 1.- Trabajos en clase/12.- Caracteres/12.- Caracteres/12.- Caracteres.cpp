#include <iostream>
#include <cctype>
using namespace std;

int main()
{
    char caracter1 = 'A', caracter2 = '1', caracter3 = '&';
    cout << "Caracter 1 (" << caracter1 << ").-" << endl;
    cout << "Alfanumerico?" << isalnum(caracter1) << endl;
    cout << "Alfanumerico?" << isalnum(caracter1) << endl;
    cout << "Digito ? " << isdigit(caracter1) << endl;
    cout << "Mayuscula?" << isupper(caracter1) << endl;
    caracter1 = tolower(caracter1);
    cout << "En miniscula: " << caracter1 << endl;
    //
    cout << "Caracter 2 (" << caracter2 << ").-" << endl;
    cout << "Alfabetico? " << isalpha(caracter2) << endl;
    cout << "Digito? " << isdigit(caracter2) << endl;
    //
    cout << "Caracter 3 (" << caracter3 << ").-" << endl;
    cout << "Alfanumerico? " << isalnum(caracter3) << endl;
    cout << "Alfanumerico?" << isalpha(caracter3) << endl;
    cout << "Digito? " << isdigit(caracter3) << endl;
    cout << (caracter1 * caracter2) << endl;

    return 0;
}