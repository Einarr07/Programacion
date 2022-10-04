#include <iostream>
using namespace std;
#include <fstream>
#include <iomanip>
#include "medicos.h"
#include <string.h>

//Cargar lista de un archivo
void cargar_medico(tLista_m& lista)
{
    tMedicos medicos;
    char aux;
    lista.cont = 0;
    ifstream archivo;
    //Se ábre el archivo con datos de médicos
    archivo.open("Medicos.txt");
    if (!archivo.is_open())
    {
        cout << "\t\t\t\t\t-------------------------------------" << endl;
        cout << "\t\t\t\t\t|NO SE A PODIDO ENCONTRAR EL ARCHIVO|" << endl;
        cout << "\t\t\t\t\t-------------------------------------" << endl << endl;
    }
    else {
        //Extrae la informacion del archivo
        getline(archivo, medicos.nombre);
        while ((medicos.nombre != "XXX") && (lista.cont < N))
        {
            getline(archivo, medicos.especialidad);
            archivo >> medicos.cedula;
            archivo >> medicos.edad;
            archivo >> medicos.celular;
            archivo >> medicos.correo;
            archivo.get(aux);
            lista.elementos_m[lista.cont] = medicos;
            lista.cont++;
            getline(archivo, medicos.nombre);
        }
        archivo.close(); //Cerrar archivo de texto
    }
}

int menu_medicos() { //Menú de médicos
    int op_m = -1;
    while ((op_m < 0) || (op_m > 4))
    {

        cout << "\n\n\n\n\n";
        cout << "\t\t\t\t\t ------------------------------------------" << endl;
        cout << "\t\t\t\t\t |             MENU MEDICOS               |" << endl;
        cout << "\t\t\t\t\t ------------------------------------------" << endl;

        cout << "\t\t\t\t\t   ---------------------------------------" << endl;
        cout << "\t\t\t\t\t   | 1.- INGRESAR MEDICO                 |" << endl;
        cout << "\t\t\t\t\t   | 2.- ELIMINAR MEDICO                 |" << endl;
        cout << "\t\t\t\t\t   | 3.- BUSCAR MEDICO                   |" << endl;
        cout << "\t\t\t\t\t   | 4.- VER LISTA DE MEDICO             |" << endl;
        cout << "\t\t\t\t\t   | 0.- SALIR                           |" << endl;
        cout << "\t\t\t\t\t   |_____________________________________|" << endl;
        cout << "\t\t  Opcion: ";
        cin >> op_m;
        if ((op_m < 0) || (op_m > 4))
        {
            cout << "\t\t\t\t\t   ---------------------------------------" << endl;
            cout << "\t\t\t\t\t   |OPCION INCORRECTA. INTENTA NUEVAENTE |" << endl;
            cout << "\t\t\t\t\t   ---------------------------------------" << endl;
        }
    }
    system("cls");
    return op_m;
}

//Proceso central de manejo de información
void proceso(tLista_m& lista) {
    int op_m2; // obtiene la elección del usuario del menú de médicos
    do {
        op_m2 = menu_medicos();//llama a la función: menu_medicos 
        switch (op_m2) {
        case 1:
            aniadir(lista); //Ingresar médicos
            break;
        case 2:
            eliminar(lista); // Eliminar médicos
            break;
        case 3:
            buscar(lista); // Buscar médicos 
            break;
        case 4:
            // Antes de mostrar la lista de médicos se ordena la información
            if (menu_ordenar() == 1) { // De acuerdo a que se ordena 
                ordenar(lista);// Ordenar por nombre
            }
            else {
                ordenar_especialidad(lista); // Ordenar por especialidad
            }
            mostrar(lista); // Vizualizar lista de médicos ordenada
            break;
        }
    } while (op_m2 != 0);//Se repite hasta selecionar 0. Salir
    //Al final se ordena y se guarda en el archivo.
    ordenar(lista);
    guardar_medico(lista);
}
//
int menu_ordenar() { //Menú para saber de acuerdo a que se ordena
    int op_ordenar = -1;
    while ((op_ordenar < 1) || (op_ordenar > 2))
    {
        cout << "\n\n\n\n\n";
        cout << "\t\t\t\t\t   ------------------------------------------" << endl;
        cout << "\t\t\t\t\t   |               VER LISTA                |" << endl;
        cout << "\t\t\t\t\t   ------------------------------------------" << endl;
        cout << "\t\t\t\t\t   ------------------------------------------" << endl;
        cout << "\t\t\t\t\t   | 1.- ORDENADO POR NOMBRE                |" << endl;
        cout << "\t\t\t\t\t   | 2.- ORDENADO POR ESPECIALIDAD          |" << endl;
        cout << "\t\t\t\t\t   |________________________________________|" << endl;
        cout << "\t\t  Opcion: ";
        cin >> op_ordenar;
        if ((op_ordenar < 1) || (op_ordenar > 2))
        {
            cout << "\t\t\t\t\t   ---------------------------------------" << endl;
            cout << "\t\t\t\t\t   |OPCION INCORRECTA. INTENTA NUEVAENTE |" << endl;
            cout << "\t\t\t\t\t   ---------------------------------------" << endl;
        }
    }
    system("cls");
    return op_ordenar;
}
//
void ordenar(tLista_m& lista) //Ordenar por el nombre
{
    int i = 0;
    bool inter = true;
    tMedicos temp; // Guarda momentaneamente una lista
    if (lista.cont == 0)
    {
        cout << "\t\t ------------------------------------------------" << endl;
        cout << "\t\t |ERROR: No existen medicos en el registro.. !! |" << endl;
        cout << "\t\t ------------------------------------------------" << endl << endl << endl;
    }
    else {
        while ((i < lista.cont - 1) && inter) {
            inter = false;
            for (int j = lista.cont - 1; j > i; j--) {
                if (lista.elementos_m[j].nombre < lista.elementos_m[j - 1].nombre) {
                    temp = lista.elementos_m[j];
                    lista.elementos_m[j] = lista.elementos_m[j - 1];
                    lista.elementos_m[j - 1] = temp;
                    inter = true;
                }
            }
            if (inter) {
                i++;
            }
        }
    }
}
//
void ordenar_especialidad(tLista_m& lista) //Ordenar por especialidad
{
    int i = 0;
    bool inter = true;
    tMedicos temp; // Guarda momentaneamente una lista
    if (lista.cont == 0)
    {
        cout << "\t\t ------------------------------------------------" << endl;
        cout << "\t\t |ERROR: No existen medicos en el registro.. !! |" << endl;
        cout << "\t\t ------------------------------------------------" << endl << endl << endl;
    }
    else {
        while ((i < lista.cont - 1) && inter) {
            inter = false;
            for (int j = lista.cont - 1; j > i; j--) {
                if (lista.elementos_m[j].especialidad < lista.elementos_m[j - 1].especialidad) {
                    temp = lista.elementos_m[j];
                    lista.elementos_m[j] = lista.elementos_m[j - 1];
                    lista.elementos_m[j - 1] = temp;
                    inter = true;
                }
            }
            if (inter) {
                i++;
            }
        }
    }
}
// Busca la información de un médico de acuerdo con la cédula
void buscar(tLista_m lista)
{
    string buscar_m; // Registra la cédula ingresada por el usuario
    cout << "\n\n\n\n\n";
    cout << "\t\t\t\t\t   ------------------------------------------" << endl;
    cout << "\t\t\t\t\t   |               BUSCAR MEDICO            |" << endl;
    cout << "\t\t\t\t\t   ------------------------------------------" << endl;
    cout << "\t\t\tIngrese el numero de cedula del medico: ";
    cin >> buscar_m;
    bool encontrado = false; // Verifica si corresponde a una cédula válida
    int i = 0; //Itera en el bucle while
    while (!encontrado && i < lista.cont) {
        if (buscar_m == lista.elementos_m[i].cedula) {
            encontrado = true; // Corresponde a una cédula existente
        }
        else {
            i++;
        }
    }
    if (encontrado)// Si corresponde a una cédula existente
    {
        cout << "\n\n\n\n\n";
        cout << ".---------------------------------------------------"
            << "--------------------------------------------." << endl;
        cout << left << setw(1) << "| ";
        cout << left << setw(15) << "Nombre";
        cout << left << setw(20) << "| Especialidad";
        cout << left << setw(14) << "| Cedula";
        cout << left << setw(5) << "| Edad ";
        cout << left << setw(14) << "| Celular";
        cout << left << setw(15) << "|\t Correo  \t|" << endl;

        cout << "|----------------|-------------------|-------------|"
            << "------|-------------|-----------------------|" << endl;
        cout << left << setw(1) << "| ";
        cout << left << setw(15) << lista.elementos_m[i].nombre;
        cout << "| " << left << setw(18) << lista.elementos_m[i].especialidad;
        cout << "| " << left << setw(12) << lista.elementos_m[i].cedula;
        cout << "| " << left << setw(5) << lista.elementos_m[i].edad;
        cout << "| " << left << setw(12) << lista.elementos_m[i].celular;
        cout << "| " << left << setw(22) << lista.elementos_m[i].correo << "|" << endl;
        cout << "|________________|___________________|_____________|"
            << "______|_____________|_______________________|" << endl;

    }
    else {
        cout << endl;
        cout << "\t\t\t\t\t   ---------------------------------------" << endl;
        cout << "\t\t\t\t\t   |        MEDICO NO ENCONTRADO         |" << endl;
        cout << "\t\t\t\t\t   ---------------------------------------" << endl;
    }
}

// añade informacion de medicos
void aniadir(tLista_m& lista) {
    tMedicos medicos; // Declaracion de variable 
    cin.ignore(80, '\n');// Descartamos cualquier entrada pendiente
    cout << "Nombre: ";
    getline(cin, medicos.nombre);
    cout << "Especialidad: ";
    getline(cin, medicos.especialidad);
    cout << "Cedula: ";
    cin >> medicos.cedula;
    cout << "Edad: ";
    cin >> medicos.edad;
    cout << "Celular: ";
    cin >> medicos.celular;
    cout << "Correo: ";
    cin >> medicos.correo;
    cin.sync(); // Descartamos cualquier entrada pendiente
    lista.elementos_m[lista.cont] = medicos; // Almacena en una lista la informacion escrita

    lista.cont++;
    cout << endl;
}

// Elimina información de médicos por medio de la cédula
void eliminar(tLista_m& lista) {
    //int eliminar;
    string eliminar; // Agrega información del usuario
    if (lista.cont != 0) {
        cout << "Numero de cedula de medico a eliminar: ";
        cin >> eliminar;
        int j = 0; // itera en bucle do-while
        bool existe = false; // Identifica si la cédula corresponde a un médico
        do {
            if (eliminar == lista.elementos_m[j].cedula) {// Verifica si la cédula corresponde a un médico
                existe = true;// Cédula si corresponde a un médico
            }
            j++;
        } while (!existe && (j < lista.cont)); //Mientras no se encuentre la cédula o ya no existan datos
        j--;// Disminuye en 1 del último aumento
        if (existe) { //Si la cédula corresponde a un médico
            if (lista.cont != j + 1) { // Si el médico a eliminar no se encuentra en la útima posición
                for (int i = j; i <= lista.cont + 1; i++) { //Eliminar médico
                    lista.elementos_m[i].nombre = lista.elementos_m[i + 1].nombre;
                    lista.elementos_m[i].especialidad = lista.elementos_m[i + 1].especialidad;
                    lista.elementos_m[i].cedula = lista.elementos_m[i + 1].cedula;
                    lista.elementos_m[i].edad = lista.elementos_m[i + 1].edad;
                    lista.elementos_m[i].celular = lista.elementos_m[i + 1].celular;
                    lista.elementos_m[i].correo = lista.elementos_m[i + 1].correo;
                }
            }
            else {//Si la informacion está al final, solo se elimina
                lista.elementos_m[lista.cont].nombre = { '\0' };
                lista.elementos_m[lista.cont].especialidad = { '\0' };
                lista.elementos_m[lista.cont].cedula = { '\0' };
                lista.elementos_m[lista.cont].edad = { '\0' };
                lista.elementos_m[lista.cont].celular = { '\0' };
                lista.elementos_m[lista.cont].correo = { '\0' };
            }

            lista.cont--;// si se elimina un dato, se elimina un espacio de lista
            cout << "\t\t\t\t\t   ------------------------------------------------------" << endl;
            cout << "\t\t\t\t\t   |           MEDICO ELIMINADO CORRECTAMENTE           |" << endl;
            cout << "\t\t\t\t\t   ------------------------------------------------------" << endl;
        }
        else
        {
            cout << "\t\t\t\t\t   ------------------------" << endl;
            cout << "\t\t\t\t\t   | EL MEDICO NO EXISTE  |" << endl;
            cout << "\t\t\t\t\t   ------------------------" << endl << endl;
        }
    }
    else {
        cout << "\t\t\t\t\t   --------------------------------------------------" << endl;
        cout << "\t\t\t\t\t   |        AUN NO SE REGRISTRA INFORMACION         |" << endl;
        cout << "\t\t\t\t\t   --------------------------------------------------" << endl;
    }
}

//Muestra la información de todos los medicos ingresados
void mostrar(tLista_m lista) {
    cout << endl << "----------------------------------------------------"
        << "---------------------------------------------" << endl;
    cout << "|                                     DATOS DE MEDICOS                                          |" << endl;
    cout << "----------------------------------------------------"
        << "---------------------------------------------" << endl;
    cout << left << setw(1) << "| ";
    cout << left << setw(15) << "Nombre";
    cout << left << setw(20) << "| Especialidad";
    cout << left << setw(14) << "| Cedula";
    cout << left << setw(5) << "| Edad ";
    cout << left << setw(14) << "| Celular";
    cout << left << setw(15) << "|\t Correo  \t|" << endl;
    if (lista.cont != 0) {
        for (int i = 0; i < lista.cont; i++) {// i comienza en 1
            cout << "|----------------|-------------------|-------------|"
                << "------|-------------|-----------------------|" << endl;
            cout << left << setw(1) << "| ";
            cout << left << setw(15) << lista.elementos_m[i].nombre;
            cout << "| " << left << setw(18) << lista.elementos_m[i].especialidad;
            cout << "| " << left << setw(12) << lista.elementos_m[i].cedula;
            cout << "| " << left << setw(5) << lista.elementos_m[i].edad;
            cout << "| " << left << setw(12) << lista.elementos_m[i].celular;
            cout << "| " << left << setw(22) << lista.elementos_m[i].correo << "|" << endl;
        }
        cout << "|________________|___________________|_____________|"
            << "______|_____________|_______________________|" << endl;
    }
    else {
        cout << "\t\t\t\t\t   --------------------------------------------------" << endl;
        cout << "\t\t\t\t\t   |        AUN NO SE REGRISTRA INFORMACION         |" << endl;
        cout << "\t\t\t\t\t   --------------------------------------------------" << endl;
    }
}

// Almacena la informacion de medicos en un archivo "Medicos.txt"
void guardar_medico(const tLista_m lista) {
    ofstream archivo;
    archivo.open("Medicos.txt");//con: "Medicos.txt",ios::app ; no se reemplaza el archivo
    for (int i = 0; i < lista.cont; i++) { //i comienza en 1
        archivo << lista.elementos_m[i].nombre << endl;
        archivo << lista.elementos_m[i].especialidad << endl;
        archivo << lista.elementos_m[i].cedula << endl;
        archivo << lista.elementos_m[i].edad << endl;
        archivo << lista.elementos_m[i].celular << endl;
        archivo << lista.elementos_m[i].correo << endl;
    }
    archivo << "XXX";
    archivo.close();
}