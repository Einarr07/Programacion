#include <iostream>
using namespace std;
#include <fstream>
#include <iomanip>
#include "pacientes.h"

void cargar_paciente(tLista_p& lista_p) //Cargar lista de pacientes de un archivo
{
    tPacientes pacientes;
    char aux;
    lista_p.cont = 0;
    ifstream archivo;
    //Se ábre el archivo con los datos de pacientes
    archivo.open("Pacientes.txt");
    if (!archivo.is_open())
    {
        cout << "\t\t\t\t\t-------------------------------------" << endl;
        cout << "\t\t\t\t\t|NO SE A PODIDO ENCONTRAR EL ARCHIVO|" << endl;
        cout << "\t\t\t\t\t-------------------------------------" << endl << endl;
    }
    else {
        //Extrae la informacion del archivo
        archivo >> pacientes.codigo;
        //Cargar mientras no sea -1 y los no se llegue al límite
        while ((pacientes.codigo != -1) && (lista_p.cont < N_p))
        {
            archivo.get(aux);
            getline(archivo, pacientes.nombre);
            archivo >> pacientes.cedula;
            archivo >> pacientes.edad;
            lista_p.elementos_p[lista_p.cont] = pacientes;

            lista_p.cont++;
            archivo >> pacientes.codigo;
        }
        archivo.close(); //Se cierra el archivo de texto Pacientes
    }
}

int menu_pacientes() { //Menú de las opciones en el área de Pacientes
    int op_p = -1;
    while ((op_p < 0) || (op_p > 4)) {
        cout << "\n\n\n\n\n";
        cout << "\t\t\t\t\t ------------------------------------------" << endl;
        cout << "\t\t\t\t\t |             MENU PACIENTES             |" << endl;
        cout << "\t\t\t\t\t ------------------------------------------" << endl;

        cout << "\t\t\t\t\t   ---------------------------------------" << endl;
        cout << "\t\t\t\t\t   | 1.- INGRESAR PACIENTE               |" << endl;
        cout << "\t\t\t\t\t   | 2.- ELIMINAR PACIENTE               |" << endl;
        cout << "\t\t\t\t\t   | 3.- BUSCAR PACIENTE                 |" << endl;
        cout << "\t\t\t\t\t   | 4.- VER LISTA DE PACIENTES          |" << endl;
        cout << "\t\t\t\t\t   | 0.- SALIR                           |" << endl;
        cout << "\t\t\t\t\t   |_____________________________________|" << endl;

        cout << "\t\t  Opcion: ";
        cin >> op_p;
        if ((op_p < 0) || (op_p > 4))
        {
            cout << "\t\t\t\t\t   ---------------------------------------" << endl;
            cout << "\t\t\t\t\t   |OPCION INCORRECTA. INTENTA NUEVAENTE |" << endl;
            cout << "\t\t\t\t\t   ---------------------------------------" << endl;
        }
    }
    system("cls");
    return op_p;
}

//Proceso central de manejo de información
void proceso_p(tLista_p& lista_p) {
    int op_m2;
    do {
        op_m2 = menu_pacientes(); //Recibe la información de menu_pacientes
        switch (op_m2)
        {
        case 1:
            aniadir(lista_p); //Añadir Pacientes 
            break;
        case 2:
            eliminar(lista_p); // Eliminar Pacientes
            break;
        case 3:
            buscar(lista_p); // Buscar Pacientes
            break;
        case 4:
            // Antes de mostrar se ordena la información
            ordenar(lista_p);
            mostrar(lista_p);
            break;
        }
    } while (op_m2 != 0);//Se repite hasta selecionar 0. Salir
    //Al final se ordena y se guarda en el archivo.
    ordenar(lista_p);
    guardar_pacientes(lista_p);
}
//
void ordenar(tLista_p& lista_p) //Ordenar por el nombre
{
    int i = 0;
    bool inter = true;
    tPacientes temp; // Guarda momentaneamente una lista
    if (lista_p.cont == 0) {
        cout << "\t\t --------------------------------------------------" << endl;
        cout << "\t\t |ERROR: No existen pacietnes en el registro.. !! |" << endl;
        cout << "\t\t --------------------------------------------------" << endl << endl << endl;
    }
    else {
        while ((i < lista_p.cont - 1) && inter) {
            inter = false;
            for (int j = lista_p.cont - 1; j > i; j--) {
                if (lista_p.elementos_p[j].nombre < lista_p.elementos_p[j - 1].nombre) {
                    temp = lista_p.elementos_p[j];
                    lista_p.elementos_p[j] = lista_p.elementos_p[j - 1];
                    lista_p.elementos_p[j - 1] = temp;
                    inter = true;
                }
            }
            if (inter) {
                i++;
            }
        }
    }
}
// Busca la información de un paciente de acuerdo con su código
void buscar(tLista_p lista_p) {
    int buscar_p; // Para recibir el código ingresado por el usuario
    cout << "\n\n\n\n";
    cout << "\t\t\t\t\t   --------------------------------------------" << endl;
    cout << "\t\t\t\t\t   |               BUSCAR PACIENTE            |" << endl;
    cout << "\t\t\t\t\t   --------------------------------------------" << endl;
    cout << "\t\t\tIngrese el codigo del paciente: ";
    cin >> buscar_p;
    bool encontrado = false;
    int i = 0; //Itera en el bucle while
    while (!encontrado && i < lista_p.cont) {
        if (buscar_p == lista_p.elementos_p[i].codigo) {
            encontrado = true;
        }
        else {
            i++;
        }
    }
    if (encontrado) {
        cout << endl;
        cout << "|-----------|---------------|--------------------|--------|" << endl;
        cout << left << setw(1) << "| ";
        cout << left << setw(10) << "Codigo";
        cout << left << setw(16) << "| Cedula";
        cout << left << setw(21) << "| Nombre";
        cout << "| Edad   |" << endl;
        cout << "|-----------|---------------|--------------------|--------|" << endl;
        cout << left << setw(1) << "| ";
        cout << left << setw(10) << lista_p.elementos_p[i].codigo;
        cout << "| " << left << setw(14) << lista_p.elementos_p[i].cedula;
        cout << "| " << left << setw(19) << lista_p.elementos_p[i].nombre;
        cout << "| " << lista_p.elementos_p[i].edad << "     |" << endl;
        cout << "|___________|_______________|____________________|________|" << endl;
    }
    else
    {
        cout << "\t\t\t\t\t   -----------------------------------------" << endl;
        cout << "\t\t\t\t\t   |        PACIENTE NO ENCONTRADO         |" << endl;
        cout << "\t\t\t\t\t   -----------------------------------------" << endl;
    }
}
//Agrega pacientes a la lista
void aniadir(tLista_p& lista_p) {
    tPacientes pacientes;
    cin.ignore(80, '\n'); // Descartamos cualquier entrada pendiente
    cout << "Codigo: ";
    cin >> pacientes.codigo;
    cout << "Cedula: ";
    cin >> pacientes.cedula;
    cin.ignore(80, '\n'); // Descartamos cualquier entrada pendiente
    cout << "Nombre: ";
    getline(cin, pacientes.nombre);
    cout << "Edad: ";
    cin >> pacientes.edad;
    cin.sync(); // Descartamos cualquier entrada pendiente
    lista_p.elementos_p[lista_p.cont] = pacientes;// Almacena en una lista la informacion escrita
    lista_p.cont++;
    cout << endl;
}
//Elimina la información de un paciente por medio del código
void eliminar(tLista_p& lista_p) {
    int eliminar;
    bool encontrado = false;
    if (lista_p.cont != 0) {
        cout << "Codigo del paciente a eliminar: ";
        cin >> eliminar;
        //Se encuentra el índice, si el codigo ingresado es correcto
        for (int i = 0; i < lista_p.cont; i++) {//QUITE EL =
            if (eliminar == lista_p.elementos_p[i].codigo) {
                encontrado = true; //Señala que si es un codigo valida
                eliminar = i;
            }
        }
        if (!encontrado) {
            eliminar = -1;
        }
        // Si existe el código del paciente, se puede eliminar
        if ((eliminar <= lista_p.cont) && (eliminar > 0)) {

            if (lista_p.cont != eliminar) {
                for (int i = eliminar; i <= lista_p.cont + 1; i++) {
                    lista_p.elementos_p[i].codigo = lista_p.elementos_p[i + 1].codigo;
                    lista_p.elementos_p[i].cedula = lista_p.elementos_p[i + 1].cedula;
                    lista_p.elementos_p[i].nombre = lista_p.elementos_p[i + 1].nombre;
                    lista_p.elementos_p[i].edad = lista_p.elementos_p[i + 1].edad;
                }
            }
            else {//si la informacion está al final, solo se elimina
                lista_p.elementos_p[lista_p.cont].codigo = { '\0' };
                lista_p.elementos_p[lista_p.cont].cedula = { '\0' };
                lista_p.elementos_p[lista_p.cont].nombre = { '\0' };
                lista_p.elementos_p[lista_p.cont].edad = { '\0' };
            }
            // si se elimina un dato, se elimina un espacio de lista 
            lista_p.cont--;
            cout << "\t\t\t\t\t   ------------------------------------------------------" << endl;
            cout << "\t\t\t\t\t   |           PACIENTE ELIMINADO CORRECTAMENTE         |" << endl;
            cout << "\t\t\t\t\t   ------------------------------------------------------" << endl;
        }
        else
        {
            cout << "\t\t\t\t\t   --------------------------" << endl;
            cout << "\t\t\t\t\t   | EL PACIENTE NO EXISTE  |" << endl;
            cout << "\t\t\t\t\t   --------------------------" << endl << endl;
        }
    }
    else
    {
        cout << "\t\t\t\t\t   --------------------------------------------------" << endl;
        cout << "\t\t\t\t\t   |        AUN NO SE REGRISTRA INFORMACION         |" << endl;
        cout << "\t\t\t\t\t   --------------------------------------------------" << endl;
    }
}
//Muestra todos los pacientes ingresados
void mostrar(tLista_p lista_p) {
    if (lista_p.cont != 0) { //Si existe datos
        cout << endl << "\t\t\t\t------------------------------------------" << endl;
        cout << "\t\t\t\t|          DATOS DE PACIENTES            |" << endl;
        cout << "\t\t\t\t------------------------------------------" << endl;
        cout << "|-----------|---------------|--------------------|--------|" << endl;
        cout << left << setw(1) << "| ";
        cout << left << setw(10) << "Codigo";
        cout << left << setw(16) << "| Cedula";
        cout << left << setw(21) << "| Nombre";
        cout << "| Edad   |" << endl;
        for (int i = 0; i < lista_p.cont; i++) {
            cout << "|-----------|---------------|--------------------|--------|" << endl;
            cout << left << setw(1) << "| ";
            cout << left << setw(10) << lista_p.elementos_p[i].codigo;
            cout << "| " << left << setw(14) << lista_p.elementos_p[i].cedula;
            cout << "| " << left << setw(19) << lista_p.elementos_p[i].nombre;
            cout << "| " << lista_p.elementos_p[i].edad << "     |" << endl;
        }
        cout << "|___________|_______________|____________________|________|" << endl;
    }
    else
    {
        cout << "\t\t\t\t\t   --------------------------------------------------" << endl;
        cout << "\t\t\t\t\t   |        AUN NO SE REGRISTRA INFORMACION         |" << endl;
        cout << "\t\t\t\t\t   --------------------------------------------------" << endl;
    }
}
//Almacena la informacion de los pacientes en un archivo "Pacientes.txt"
void guardar_pacientes(const tLista_p lista_p) {
    ofstream archivo;
    archivo.open("Pacientes.txt"); //Abre archivo
    for (int i = 0; i < lista_p.cont; i++) {
        archivo << lista_p.elementos_p[i].codigo << endl;
        archivo << lista_p.elementos_p[i].nombre << endl;
        archivo << lista_p.elementos_p[i].cedula << endl;
        archivo << lista_p.elementos_p[i].edad << endl;
    }
    archivo << -1;

    archivo.close();
}