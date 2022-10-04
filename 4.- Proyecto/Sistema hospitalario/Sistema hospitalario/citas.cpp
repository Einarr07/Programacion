#include <iostream>
using namespace std;
#include <fstream>
#include <iomanip>
#include <string>
#include "medicos.h"
#include "pacientes.h"
#include "citas.h"

//Inicializa el el número de turno en cero.
int turno = 0;

void cargar_citas(tLista_c& lista_c)
{
    tCita cita;
    char aux;
    lista_c.cont = 0;
    ifstream archivo;
    //Se abre el archivo de texto Citas.txt
    archivo.open("Citas.txt");
    if (!archivo.is_open())
    {
        cout << "\t\t\t\t\t-------------------------------------" << endl;
        cout << "\t\t\t\t\t|NO SE A PODIDO ENCONTRAR EL ARCHIVO|" << endl;
        cout << "\t\t\t\t\t-------------------------------------" << endl << endl;
    }
    else {
        //Extrae la informacion del archivo
        archivo >> cita.codigo;
        while ((cita.codigo != -1) && (lista_c.cont < N_c))
        {
            archivo.get(aux);
            getline(archivo, cita.nombre);
            archivo >> cita.area;
            archivo.get(aux);
            getline(archivo, cita.doctor);
            archivo >> cita.turno;
            lista_c.elementos_c[lista_c.cont] = cita;

            lista_c.cont++;
            archivo >> cita.codigo;
        }
        turno = cita.turno;
        archivo.close(); //se cierra el archivo de texto
    }

}
//El proceso central de las citas recibe el contenido de medico y pacientes
void proceso_c(tLista_m& lista, tLista_p& lista_p, tLista_c& lista_c) {
    int op_c;
    do {
        op_c = menu_citas();
        switch (op_c) {
        case 1:
            ingresar_citas(lista, lista_p, lista_c);
            break;
        case 2:
            // Si no se ha ingresado citas, no se puede modificar
            if (lista_c.cont != 0) {
                modificar(lista_p, lista_c);
            }
            else {
                cout << "Turnos no registrado" << endl;
            }
            break;
        case 3:
            // Si se ha ingresado citas, no se puede consultar
            if (lista_c.cont != 0) {
                consultar(lista_p, lista_c);
            }
            else {
                cout << "Turnos no registrado" << endl;
            }
            break;
        case 4:
            // Antes de mostrar la lista de citas se ordena la información
            if (menu_ordenar_c() == 1) { // De acuerdo a que se ordena 
                ordenar(lista_c); //Ordenar por nombre
            }
            else {
                ordenar_turno(lista_c); //Ordenar por turno
            }
            mostrar(lista_c);
            break;
        case 5:
            // Si no se ha ingresado citas, no se puede eliminar
            if (lista_c.cont != 0) {
                eliminar(lista_p, lista_c); //Elimina información de una cita
            }
            else {
                cout << "Turnos no registrado" << endl;
            }
            break;
        }
    } while (op_c != 0);
    //Antes de guardar se ordena la información
    ordenar(lista_c);
    guardar_citas(lista_c);//Al final se guarda las citas en un archivo
}

//Menú principal de citas
int menu_citas() {
    int op_c = -1;
    while ((op_c < 0) || (op_c > 5))
    {
        cout << "\n\n\n\n\n";
        cout << "\t\t\t\t\t ------------------------------------------" << endl;
        cout << "\t\t\t\t\t |             MENU CITAS                 |" << endl;
        cout << "\t\t\t\t\t ------------------------------------------" << endl;

        cout << "\t\t\t\t\t   ---------------------------------------" << endl;
        cout << "\t\t\t\t\t   | 1.- INGRESAR CITA                   |" << endl;
        cout << "\t\t\t\t\t   | 2.- MODIFICAR CITA                  |" << endl;
        cout << "\t\t\t\t\t   | 3.- CONSULTAR CITA                  |" << endl;
        cout << "\t\t\t\t\t   | 4.- VER LISTA DE CITAS              |" << endl;
        cout << "\t\t\t\t\t   | 5.- ELIMINAR CITA                   |" << endl;
        cout << "\t\t\t\t\t   | 0.- SALIR                           |" << endl;
        cout << "\t\t\t\t\t   |_____________________________________|" << endl;

        cout << "\t\t  Opcion: ";
        cin >> op_c;
        if ((op_c < 0) || (op_c > 5))
        {
            cout << "\t\t\t\t\t   ---------------------------------------" << endl;
            cout << "\t\t\t\t\t   |OPCION INCORRECTA. INTENTA NUEVAENTE |" << endl;
            cout << "\t\t\t\t\t   ---------------------------------------" << endl;
        }
    }
    system("cls");
    return op_c;
}

//Añade citas a los pacientes ingresados
void ingresar_citas(tLista_m& lista, tLista_p& lista_p, tLista_c& lista_c) {
    bool encontrado = false;
    tCita cita;
    int codigo;
    bool tiene_cita;

    cout << endl;
    mostrar(lista_p); //Muestras los pacientes registrados
    cout << endl;

    cin.ignore(80, '\n');
    cout << "Ingrese el codigo del paciente: ";
    cin >> codigo; // Recibe un código
    for (int i = 0; i < lista_p.cont; i++) {
        // Verifica si el código representa a un paciente
        if (codigo == lista_p.elementos_p[i].codigo) {
            //Si ya se registro la cita de un paciente no puede volver a registrar
            tiene_cita = false;//verifica si el paciente ya tiene una cita

            for (int j = 0; j < lista_c.cont; j++) {
                if (codigo == lista_c.elementos_c[j].codigo) {
                    tiene_cita = true; // Paciente si tiene una cita
                }
            }
            if (!tiene_cita) { // Si el paciente no tiene una cita
                cita.codigo = codigo;
                cita.nombre = lista_p.elementos_p[i].nombre;
                encontrado = true; // Se puede añadir cita
                //cita.doctor = lista.elementos_m[i].nombre;
            }// else{cout << "Paciente ya tiene cita"}
        }// else{cout << "No existe"}
    }
    if (encontrado) {
        // Se enlista las especialidades de médicos
        cout << endl << "\tAREAS Y DOCTORES DISPONIBLES" << endl;;
        for (int i = 0; i < lista.cont; i++) {
            cout << "|------------------|--------------------| " << endl;
            cout << left << setw(1) << "| ";
            cout << left << setw(17) << lista.elementos_m[i].especialidad;
            cout << "| " << left << setw(19) << lista.elementos_m[i].nombre;
            cout << "|" << endl;
        }
        cout << "|__________________|____________________| " << endl << endl;

        cin.ignore(80, '\n'); // Descarta cualquier entrada pendiente
        bool existe = false; //verifica similitud de área y especialidad existente
        cout << "Ingrese el area requerida: ";
        getline(cin, cita.area);
        do {
            for (int j = 0; j < lista.cont; j++) {
                if (cita.area == lista.elementos_m[j].especialidad) {
                    existe = true; //señala que el área escrita existe
                }
            }

            if (!existe) {//si el área escrita para la cita no existe

                cout << "\t\t\t\t\t   -------------------------------------" << endl;
                cout << "\t\t\t\t\t   |        AREA NO ENCONTRADA         |" << endl;
                cout << "\t\t\t\t\t   -------------------------------------" << endl << endl;

                cout << "Ingrese el area requerida: ";
                getline(cin, cita.area); //Reicibe nuevamente el area requerida
            }
            else {
                turno++; //Variación de turno
                cita.turno = turno;// Se añade el numero del turno
                cin.sync();// Descarta cualquier entrada pendiente
            }
        } while (!existe);

        existe = false;
        cout << "Ingrese el nombre del doctor: ";
        getline(cin, cita.doctor);
        do {
            //LA ESPECIALIDAD TIENE QUE APARECER UNA SOLA VEZ, Y AGREGARSE SOLO UNA VEZ(Coregido)
            for (int j = 0; j < lista.cont; j++) {
                if (cita.doctor == lista.elementos_m[j].nombre) {
                    existe = true; //señala que el área escrita existe
                }
            }

            if (!existe) {//si el área escrita para la cita no existe
                cout << "\t\t\t\t\t   ---------------------------------------" << endl;
                cout << "\t\t\t\t\t   |        DOCTOR NO ENCONTRADO         |" << endl;
                cout << "\t\t\t\t\t   ---------------------------------------" << endl << endl;
                cout << "Ingrese el nombre del doctor: ";
                getline(cin, cita.doctor); // Recibe nuevamente el nombre del doctor
            }
            else {
                cout << "\t\t\t\t\t   -------------------------------------" << endl;
                cout << "\t\t\t\t\t   |     CITA REGISTRADA CON EXITO     |" << endl;
                cout << "\t\t\t\t\t   -------------------------------------" << endl;
                lista_c.elementos_c[lista_c.cont] = cita; // Almacena la información de cita
                cout << "TURNO ASIGNADO: " << lista_c.elementos_c[lista_c.cont].turno;
                lista_c.cont++;
                cout << endl;
            }
        } while (!existe);


    }
    else
    {
        cout << "\t\t\t\t\t   --------------------------" << endl;
        cout << "\t\t\t\t\t   | CODIGO NO ENCONTRADO   |" << endl;
        cout << "\t\t\t\t\t   --------------------------" << endl << endl;
        //Si no se crea la cita, se reduce el espacio de lista aumentada antes de ingresar a la función
    }
}

void modificar(tLista_p& lista_p, tLista_c& lista_c) {
    bool encontrado = false;
    int modificar;
    cout << endl;
    mostrar(lista_p); //Muestras los pacientes registrados
    cout << endl;
    cout << "Ingrese el codigo del paciente: ";
    cin >> modificar;
    //Verifica el código y se encuentra el índice 
    for (int i = 0; i < lista_c.cont; i++) {
        //Se accede si el turno del paciente ya fué asignado
        if (modificar == lista_c.elementos_c[i].codigo) {  // && (lista_c.elementos_c[i].turno != 0)) {
            encontrado = true; // Cumple con el código y turno
            turno++;
            lista_c.elementos_c[i].turno = turno;// Cambio de turno
            cout << "NUEVO TURNO ASIGNADO: " << lista_c.elementos_c[i].turno << endl;
        }
    }
    if (!encontrado)
    {
        cout << "\t\t\t\t\t   --------------------------" << endl;
        cout << "\t\t\t\t\t   | CODIGO NO ENCONTRADO   |" << endl;
        cout << "\t\t\t\t\t   --------------------------" << endl << endl;
    }

}

void consultar(tLista_p& lista_p, tLista_c& lista_c) {
    bool encontrado = false;
    int consulta; // Recibirá la información de usuario
    cout << "\n\n\n\n\n";
    cout << "\t\t\t\t\t   --------------------------------------------" << endl;
    cout << "\t\t\t\t\t   |              CONSULTAR CITA              |" << endl;
    cout << "\t\t\t\t\t   --------------------------------------------" << endl;

    cout << "\t\t\tIngrese el codigo del paciente: ";
    cin >> consulta;
    for (int i = 0; i < lista_c.cont; i++) {
        if (consulta == lista_c.elementos_c[i].codigo) {
            cout << ".-------------------------------------------------------------------------------------." << endl;
            cout << left << setw(1) << "| ";
            cout << left << setw(9) << "Codigo";
            cout << left << setw(22) << "| Nombre";
            cout << left << setw(22) << "| Area";
            cout << left << setw(22) << "| Doctor";
            cout << "| Turno  |" << endl;
            cout << "|----------|---------------------|---------------------|---------------------|--------|" << endl;
            cout << left << setw(1) << "| ";
            cout << left << setw(9) << lista_c.elementos_c[i].codigo;
            cout << "| " << left << setw(20) << lista_c.elementos_c[i].nombre;
            cout << "| " << left << setw(20) << lista_c.elementos_c[i].area;
            cout << "| " << left << setw(20) << lista_c.elementos_c[i].doctor;
            cout << "| " << lista_c.elementos_c[i].turno << "      |" << endl;
            cout << "|__________|_____________________|_____________________|_____________________|________|" << endl;
            encontrado = true;
        }
    }

    if (!encontrado)
    {
        cout << "\t\t\t\t\t   --------------------------" << endl;
        cout << "\t\t\t\t\t   | CODIGO NO ENCONTRADO   |" << endl;
        cout << "\t\t\t\t\t   --------------------------" << endl << endl;
    }
}
//Elimna la cita de acuerdo al código del paciente
void eliminar(tLista_p& lista_p, tLista_c& lista_c) {
    bool codigo_existe = false; //Verifica si el codigo ingresado existe
    int eliminar;
    if (lista_c.cont != 0) {
        cout << "Ingrese el codigo del paciente: ";
        cin >> eliminar;
        for (int i = 0; i < lista_c.cont; i++) {
            //Se verifica si el código existe 
            if (eliminar == lista_c.elementos_c[i].codigo) {
                codigo_existe = true;
                eliminar = i;
            }
        }
        if (!codigo_existe) {
            eliminar = -1;
        }
        if ((eliminar <= lista_c.cont) && (eliminar > 0)) {
            if (lista_c.cont != eliminar) {
                for (int i = eliminar; i <= lista_c.cont + 1; i++) {
                    lista_c.elementos_c[i].codigo = lista_c.elementos_c[i + 1].codigo;
                    lista_c.elementos_c[i].nombre = lista_c.elementos_c[i + 1].nombre;
                    lista_c.elementos_c[i].area = lista_c.elementos_c[i + 1].area;
                    lista_c.elementos_c[i].doctor = lista_c.elementos_c[i + 1].doctor;
                    lista_c.elementos_c[i].turno = lista_c.elementos_c[i + 1].turno;
                }
            }
            else {//Si la cita está al final, solo se elimina
                lista_c.elementos_c[lista_c.cont].codigo = { '\0' };
                lista_c.elementos_c[lista_c.cont].nombre = { '\0' };
                lista_c.elementos_c[lista_c.cont].area = { '\0' };
                lista_c.elementos_c[lista_c.cont].doctor = { '\0' };
                lista_c.elementos_c[lista_c.cont].turno = { '\0' };
                turno--;
            }
            //Si se elimina una cita se elimina un espacio de lista.
            lista_c.cont--;
            cout << "\t\t\t\t\t   ------------------------------------------------------" << endl;
            cout << "\t\t\t\t\t   |             CITA ELIMINADA CORRECTAMENTE           |" << endl;
            cout << "\t\t\t\t\t   ------------------------------------------------------" << endl;
        }
        else
        {
            cout << "\t\t\t\t\t   --------------------------" << endl;
            cout << "\t\t\t\t\t   | CODIGO NO ENCONTRADO   |" << endl;
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
//Muestra lista de citas
void mostrar(tLista_c lista_c) {
    if (lista_c.cont != 0) {
        cout << endl << "\t\t------------------------------------------" << endl;
        cout << "\t\t|          DATOS DE CITAS                |" << endl;
        cout << "\t\t------------------------------------------" << endl;
        cout << ".-------------------------------------------------------------------------------------." << endl;
        cout << left << setw(1) << "|";
        cout << left << setw(10) << "Codigo";
        cout << left << setw(22) << "| Nombre";
        cout << left << setw(22) << "| Area";
        cout << left << setw(22) << "| Doctor";
        cout << "| Turno  |" << endl;
        for (int i = 0; i < lista_c.cont; i++) {
            cout << "|----------|---------------------|---------------------|---------------------|--------|" << endl;
            cout << left << setw(1) << "| ";
            cout << left << setw(9) << lista_c.elementos_c[i].codigo;
            cout << "| " << left << setw(20) << lista_c.elementos_c[i].nombre;
            cout << "| " << left << setw(20) << lista_c.elementos_c[i].area;
            cout << "| " << left << setw(20) << lista_c.elementos_c[i].doctor;
            cout << "| " << lista_c.elementos_c[i].turno << "      |" << endl;
        }
        cout << "|__________|_____________________|_____________________|_____________________|________|" << endl;
    }
    else {
        cout << "\t\t\t\t\t   --------------------------------------------------" << endl;
        cout << "\t\t\t\t\t   |        AUN NO SE REGRISTRA INFORMACION         |" << endl;
        cout << "\t\t\t\t\t   --------------------------------------------------" << endl;
    }
}
//Menú para ordenar de acuerdo al nombre o turno
int menu_ordenar_c() {
    int op_ordenar = -1;
    while ((op_ordenar < 1) || (op_ordenar > 2))
    {
        cout << "\n\n\n\n\n";
        cout << "\t\t\t\t\t   ------------------------------------------" << endl;
        cout << "\t\t\t\t\t   |               VER LISTA                |" << endl;
        cout << "\t\t\t\t\t   ------------------------------------------" << endl;

        cout << "\t\t\t\t\t   ------------------------------------------" << endl;
        cout << "\t\t\t\t\t   | 1.- ORDENADO POR NOMBRE                |" << endl;
        cout << "\t\t\t\t\t   | 2.- ORDENADO POR TURNO                 |" << endl;
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

void ordenar(tLista_c& lista_c) //Ordenar por el nombre
{
    int i = 0;
    bool inter = true;
    tCita temp;
    if (lista_c.cont == 0) {
        cout << "\t\t --------------------------------------------------" << endl;
        cout << "\t\t |ERROR: No existen pacietnes en el registro.. !! |" << endl;
        cout << "\t\t --------------------------------------------------" << endl << endl << endl;
    }
    else {
        while ((i < lista_c.cont - 1) && inter) {
            inter = false;
            for (int j = lista_c.cont - 1; j > i; j--) {
                if (lista_c.elementos_c[j].nombre < lista_c.elementos_c[j - 1].nombre) {
                    temp = lista_c.elementos_c[j];
                    lista_c.elementos_c[j] = lista_c.elementos_c[j - 1];
                    lista_c.elementos_c[j - 1] = temp;
                    inter = true;
                }
            }
            if (inter) {
                i++;
            }
        }
    }
}

void ordenar_turno(tLista_c& lista_c) //Ordenar por el número de turno
{
    int i = 0;
    bool inter = true;
    tCita temp;
    if (lista_c.cont == 0) {
        cout << "\t\t --------------------------------------------------" << endl;
        cout << "\t\t |ERROR: No existen pacietnes en el registro.. !! |" << endl;
        cout << "\t\t --------------------------------------------------" << endl << endl << endl;
    }
    else {
        while ((i < lista_c.cont - 1) && inter) {
            inter = false;
            for (int j = lista_c.cont - 1; j > i; j--) {
                if (lista_c.elementos_c[j].turno < lista_c.elementos_c[j - 1].turno) {
                    temp = lista_c.elementos_c[j];
                    lista_c.elementos_c[j] = lista_c.elementos_c[j - 1];
                    lista_c.elementos_c[j - 1] = temp;
                    inter = true;
                }
            }
            if (inter) {
                i++;
            }
        }
    }
}

//Guarda las citas en una archivo "Citas.txt"
void guardar_citas(tLista_c& lista_c) {
    ofstream archivo;
    archivo.open("Citas.txt");//Abre archivo Citas.txt

    for (int i = 0; i < lista_c.cont; i++) {
        archivo << lista_c.elementos_c[i].codigo << endl;
        archivo << lista_c.elementos_c[i].nombre << endl;
        archivo << lista_c.elementos_c[i].area << endl;
        archivo << lista_c.elementos_c[i].doctor << endl;
        archivo << lista_c.elementos_c[i].turno << endl;
    }
    archivo << -1;
    archivo.close();
}

