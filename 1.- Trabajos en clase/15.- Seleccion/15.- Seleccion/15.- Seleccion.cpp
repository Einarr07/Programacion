#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    /*
      int op1;

      cout << "Ingrese un numero para determinar si el numero es multiplo de 6" << endl;
      cin >> op1;

      if (op1 % 6==0) {
          cout << "Es multiplo" << endl;
      }

      else {
          cout << "No es multiplo " << endl;
      }
      return 0;
    */

    double op1, op2;
    int opcion;

    cout << "---Bienvenido---" << endl;
    cout << "Que operacion te gustaria ingresar el dia de hoy" << endl;
    cout << "Nota: Recuerda que la division para cero n existe" << endl;
    cout << "1.- Sumar" << endl;
    cout << "2.- Restar" << endl;
    cout << "3.- Multiplicacion" << endl;
    cout << "4.- Division" << endl;
    cout << "Opcion: ";
    cin >> opcion;


    cout << "|" << setw(8) << "Ingrese el primer valor" << "|" << endl;
    cin >> op1;
    cout << "|" << setw(8) << "Ingrese el segundo valor" << "|" << endl;
    cin >> op2;

    if (opcion == 1) {
        cout << "El resultado de la suma es:" << op1 + op2 << endl;
    }
    else if (opcion == 2) {
        cout << "El resultado de la resta es:" << op1 - op2 << endl;
    }
    else if (opcion == 3) {
        cout << "El resultado de la multiplicacion es:" << op1 * op2 << endl;
    }
    else {
        cout << "El resultado de la division es:" << op1 / op2 << endl;
    }

}