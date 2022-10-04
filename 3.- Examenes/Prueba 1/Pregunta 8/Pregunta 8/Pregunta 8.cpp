/*
a) Muestre un menú con 8 opciones:

1.-Sumar dos números.
2.-Restar dos números.
3.-Multiplicar dos números.
4.-Dividir dos números.
5.-Obtener el seno de un ángulo
6.-Obtener el coseno de un ángulo
7.-Obtener la tangente de un ángulo
0.-Salir.
bº) Pida por teclado la opción deseada, esta se seguirá solicitando si el usuario ingresa una opción incorrecta.

cº) Ejecute la opción seleccionada del menú.

dº) Repita los pasos a, b y c, mientras que, el usuario no seleccione la opción 8 (Salir) del menú.

5º) La división mostrará el cociente y el resto
*/

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
using namespace std;

int menu();
using namespace std;
void programa1();
void programa2();
void programa3();
void programa4();
void programa5();
void programa6();
void programa7();

int main()
{
    int opcion = menu();
    while (opcion != 0) {
        switch (opcion) {
        case 1:
        {
            programa1();
        }
        break;
        case 2:
        {
            programa2();
        }
        break;
        case 3:
        {
            programa3();
        }
        break;
        case 4:
        {
            programa4();
        }
        break;
        case 5:
        {
            programa5();
        }
        break;
        case 6:
        {
            programa6();
        }
        break;
        case 7:
        {
            programa7();
        }
        break;
        } // switch
        opcion = menu();
    } // while (opcion != 0)
    return 0;
}
int menu() {
    int op = -1;
    while ((op < 0) || (op > 7)) {
        cout << "*****Menú del programa*****" << endl;
        cout << "1 - Sumar dos números." << endl;
        cout << "2 - Restar dos números." << endl;
        cout << "3 - Multiplicar dos números." << endl;
        cout << "4 - Dividir dos números." << endl;
        cout << "5 - Obtener el seno de un ángulo" << endl;
        cout << "6 - Obtener el coseno de un ángulo" << endl;
        cout << "7 - Obtener la tangente de un ángulo" << endl;
        cout << "0 - Salir" << endl;
        cout << "Opción: " << endl;
        cin >> op;
        if ((op < 0) || (op > 7)) {
            cout << "¡Opción no válida!" << endl;
        }
    }
    return op;
}

void programa1() {
    double valor_1, valor_2, resultado;
    //
    cout << "***Bienvenido a la suma***" << endl;
    cout << "Ingrese el primer valor: " << endl;
    cin >> valor_1;
    cout << "Ingrese el segundo valor: " << endl;
    cin >> valor_2;
    //
    resultado = valor_1 + valor_2;
    //
    cout << "El resultado de la suma es: " << resultado << endl;

}

void programa2() {
    double valor_1, valor_2, resultado;
    //
    cout << "***Bienvenido a la resta***" << endl;
    cout << "Ingrese el primer valor: " << endl;
    cin >> valor_1;
    cout << "Ingrese el segundo valor: " << endl;
    cin >> valor_2;
    //
    resultado = valor_1 - valor_2;
    //
    cout << "El resultado de la resta es: " << resultado << endl;
}

void programa3() {
    double valor_1, valor_2, resultado;
    //
    cout << "***Bienvenido a la multiplicacion***" << endl;
    cout << "Ingrese el primer valor: " << endl;
    cin >> valor_1;
    cout << "Ingrese el segundo valor: " << endl;
    cin >> valor_2;
    //
    resultado = valor_1 * valor_2;
    //
    cout << "El resultado de la multiplicacion es: " << resultado << endl;
}
void programa4() {
    double valor_1, valor_2, resultado;
    //
    cout << "***Bienvenido a la division***" << endl;
    cout << "Ingrese el primer valor: " << endl;
    cin >> valor_1;
    cout << "Ingrese el segundo valor: " << endl;
    cin >> valor_2;
    //
    resultado = valor_1 / valor_2;
    //
    cout << "El resultado de la division es: " << resultado << endl;
}
void programa5() {
    
    double param, resultado;
    //
    cout << "***Bienvenido al seno de un angulo*" << endl;
    cout << "Introduce el angulo: ";
    cin >> param;
    //
    resultado = sin(param * ( 3.14159 / 180));
    //
    cout << "El seno es: " << resultado << endl;
}
void programa6() {
    double param, resultado;
    //
    cout << "***Bienvenido al coseno de un angulo*" << endl;
    cout << "Introduce el angulo: ";
    cin >> param;
    //
    resultado = cos(param * (3.14159 / 180));
    //
    cout << "El coseno es: " << resultado << endl;
}
void programa7() {
    double param, resultado;
    //
    cout << "***Bienvenido a la tangente de un angulo*" << endl;
    cout << "Introduce el angulo: ";
    cin >> param;
    //
    resultado = tan(param * (3.14159 / 180));
    //
    cout << "La tangente es: " << resultado << endl;
}