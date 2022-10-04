#include <iostream>
using namespace std;
#include <iomanip>

int menu(); // 1: Tablas de multiplicación; 2: Sumatorio
int suma(int n); // Sumatorio

int main() {
    int opcion = menu();
    while (opcion != 0) {
        switch (opcion) {
        case 1:
        {
            for (int i = 1; i <= 10; i++) {
                cout << "Tabla del " << i << endl;
                cout << "--------------" << endl;
                for (int j = 1; j <= 10; j++) {
                    cout << setw(2) << i << " x "
                        << setw(2) << j << " = "
                        << setw(3) << i * j << endl;
                }
            }
        }
        break;
        case 2:
        {
            int num = 0;
            while (num <= 0) {
                cout << "Hasta (positivo)? ";
                cin >> num;
            }
            cout << "La suma de los números del 1 al "
                << num << " es: " << suma(num) << endl;
        }
        } // switch
        opcion = menu();
    } // while (opcion != 0)
    return 0;
}

int menu() {
    int op = -1;
    while ((op < 0) || (op > 2)) {
        cout << "*****Menú del programa*****" << endl;
        cout << "1 - Tablas de multiplicar" << endl;
        cout << "2 - Sumatorio" << endl;
        cout << "0 - Salir" << endl;
        cout << "Opción: " << endl;
        cin >> op;
        if ((op < 0) || (op > 2)) {
            cout << "¡Opción no válida!" << endl;
        }
    }
    return op;
}
int suma(int n) {
    int total = 0;
    for (int i = 1; i <= n; i++) {
        total = total + i;
    }
    return total;
}