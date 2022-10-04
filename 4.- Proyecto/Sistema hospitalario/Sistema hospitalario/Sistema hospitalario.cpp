#include <iostream>
#include <iomanip>
using namespace std;
#include "medicos.h"
#include "pacientes.h"
#include "citas.h"

int menu_principal();
//declaración de variables
tLista_m lista;
tLista_p lista_p;
tLista_c lista_c;

int main() {
    int op; // opción del menú principal
    bool ok = false; // verifica si se carga correctamente el archivo
    cargar_medico(lista);
    cargar_paciente(lista_p);
    cargar_citas(lista_c);
    do {
        op = menu_principal(); // Opción del usuario
        switch (op) {
        case 1:
            proceso(lista); // Menú de médicos
            break;
        case 2:
            proceso_p(lista_p); // Menú de Pacientes
            break;
        case 3:
            if ((lista.cont != 0) && (lista_p.cont != 0)) { // Si existe información de médicos y pacientes
                proceso_c(lista, lista_p, lista_c); // Menú de citas
            }
            else {
                cout << "\t\t\t\t\t----------------------------------------" << endl;
                cout << "\t\t\t\t\t|FALTAN DATOS PARA REALIZAR EL PROCESO |" << endl;
                cout << "\t\t\t\t\t----------------------------------------" << endl;
            }
            break;

        }
    } while (op != 0);
}

int menu_principal() {
    int op_principal = -1;
    while ((op_principal < 0) || (op_principal > 3))
    {
        cout << "\n\n\n\n\n";
        cout << "\t\t\t\t---------------------------------------------------------" << endl;
        cout << "\t\t\t\t|               HOSPITAL SAN FRANCISCO DE QUITO         |" << endl;
        cout << "\t\t\t\t---------------------------------------------------------" << endl;

        cout << "\t\t\t\t\t  ........................................" << endl;
        cout << "\t\t\t\t\t  :          1.- MENU MEDICOS            :" << endl;
        cout << "\t\t\t\t\t  :                                      :" << endl;
        cout << "\t\t\t\t\t  :          2.- MENU PACIENTES          :" << endl;
        cout << "\t\t\t\t\t  :                                      :" << endl;
        cout << "\t\t\t\t\t  :          3.- MENU CITAS              :" << endl;
        cout << "\t\t\t\t\t  :                                      :" << endl;
        cout << "\t\t\t\t\t  :          0.- SALIR                   :" << endl;
        cout << "\t\t\t\t\t  ........................................" << endl;
        cout << "\t\t  Opcion: ";
        cin >> op_principal;
        if ((op_principal < 0) || (op_principal > 3))
        {
            cout << "\t\t\t\t\t   ---------------------------------------" << endl;
            cout << "\t\t\t\t\t   |OPCION INCORRECTA. INTENTA NUEVAENTE |" << endl;
            cout << "\t\t\t\t\t   ---------------------------------------" << endl;
        }
    }
    system("cls");
    return op_principal;
}