#include <iostream>
using namespace std;

int main()
{
    //variables 
    double cateto1, cateto2, hipotenusa;

    //programa
    cout << "Bienvenido al programa para calcular la hipotenusa de un triangulo " << endl;
    cout << endl;
    cout << "Ingrse el primer cateto (base)" << endl;
    cin >> cateto1;
    cout << "Ingrese el segundo cateto" << endl;
    cin >> cateto2;

    //formula 
    hipotenusa = sqrt((cateto1 * cateto1) + (cateto2 * cateto2));
    cout << "El valor de la Hipotenusa es: " << hipotenusa;

    return 0;
}