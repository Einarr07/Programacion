#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
using namespace std;
//
const int MAXX = 50;
int contador = 0;
//
typedef struct {
    string nombres;
    int ganados;
    int empatados;
    int puntos;
}tEquipos;
//
tEquipos equipos[MAXX];
void datosequipo();
void puntosyordenar();
int menuprincipal();
//
typedef struct {
    string nombre;
    int edad;
    string estudios;
    string contrato;
}tBecarios;
//
void procesoBecarios();
typedef struct {
    int dia;
    int mes;
    int ano;
}tFecha;
tFecha fechas[2];
void datosS();
void procesoS();
const int MAX = 100;
//
typedef struct {
    string nombre;
    int edad;
    double peso;
    string nif;
}tEstudiante;
//
typedef struct {
    tEstudiante elementos[MAX];
    int contador;
}tLista;
//
int menuZoo();
void cargar(tLista& lista, bool& ok);
void guardar(const tLista& lista);
void leerEstudiante(tEstudiante& estudiante);
void insertarEstudiante(tLista& lista, tEstudiante estudiante, bool& ok);
string nombreCompleto(tEstudiante estudiante);
void listado(const tLista& lista);
void buscar(const tLista& lista, string dato);
//
int menuZoo() 
{
    int op;
    do {
        cout << setw(45) << "|ZOOLOGICO DE QUITO|" << endl;
        cout << "1.-Registrar animal" << endl;
        cout << "2.-Base de datos de animales del zoologico" << endl;
        cout << "3.-Buscar animal" << endl;
        cout << "4.-Salir" << endl;
        cout << "Opcion: ";
        cin >> op;
    } while ((op < 0) || (op > 4));
    return op;
}
//
int main() 
{
    int op;
    do {
        op = menuprincipal();
        switch (op) 
        {
        case 1: 
        {
            system("cls");
            cout << "COLOCA UN '*' EN EL NOMBRE DEL EQUIPO PARA FINALIZAR" << endl;
            datosequipo();
            puntosyordenar();
            int x;
            do {
                cout << "SELECCIONA:" << endl;
                cout << "1.-Agregar equipo" << endl;
                cout << "2.-Salir" << endl;
                cout << "Opcion: ";
                cin >> x;
                if (x == 1)
                {
                    datosequipo();
                    puntosyordenar();
                }
                else 
                {
                    cout << setw(35) << "|GRACIAS|" << endl;
                }
            } while (x != 2);
            contador = 0;
            break;
        }
        case 2: 
        {
            system("cls");
            cout << setw (35) << "IMPORTANTE!!!!" << endl;
            cout << "Para el ejercicio del zoologico necesitaremos un archivo.txt donde los datos deberan estar ingresados de la siguiente forma: " << endl;
            cout << setw(35) << "EJEMPLO" << endl;
            cout << "LEON(nombre)" << endl;
            cout << "12564352(numero entero de identificacion)" << endl;
            cout << "120(Peso)" << endl;
            cout << "mamifero(tipo)" << endl;
            cout << "XXX(centinela)" << endl;
            tLista lista;
            tEstudiante estudiante;
            bool exito;
            int op, pos;
            cargar(lista, exito);
            if (!exito)
            {
                cout << "No se ha podido cargar la lista" << endl;
            }
            else {
                do {
                    op = menuZoo();
                    switch (op)
                    {
                    case 1:
                    {
                        leerEstudiante(estudiante);
                        insertarEstudiante(lista, estudiante, exito);
                        if (!exito)
                        {
                            cout << "La lista esta llena" << endl;
                        }
                    }
                    break;
                    case 2:
                    {
                        system("cls");
                        listado(lista);
                    }
                    break;
                    case 3:
                    {
                        system("cls");
                        string dat;
                        cout << "Ingresa el animal que desea buscar: ";
                        cin >> dat;
                        buscar(lista, dat);
                        listado(lista);
                    }
                    break;
                    }
                } while (op != 4);
                guardar(lista);
            }
            break;
        }
        case 3: 
        {
            system("cls");
            procesoBecarios();
            break;
        }
        case 4: 
        {
            system("cls");
            datosS();
            procesoS();
            break;
        }
        }
    } while (op != 0);

    cout << setw(65) << "|GRACIAS POR USAR EL PROGRAMA|" << endl;

}
//zoo
void cargar(tLista& lista, bool& ok) 
{
    tEstudiante estudiante;
    ifstream archivo;
    char aux;
    lista.contador = 0;
    archivo.open("archivo.txt");
    if (!archivo.is_open()) 
    {
        ok = false;
    }
    else 
    {
        ok = true;
        getline(archivo, estudiante.nombre);
        while ((estudiante.nombre != "XXX") && (lista.contador < MAX)) 
        {
            archivo >> estudiante.edad;
            archivo >> estudiante.peso;
            archivo >> estudiante.nif;
            archivo.get(aux);
            lista.elementos[lista.contador] = estudiante;
            lista.contador++;
            getline(archivo, estudiante.nombre);
        }
        archivo.close();
    }
}
void guardar(const tLista& lista) 
{
    ofstream archivo;
    archivo.open("archivo.txt");
    for (int i = 0; i < lista.contador; i++)
    {
        archivo << lista.elementos[i].nombre << endl;
        archivo << lista.elementos[i].edad << endl;
        archivo << lista.elementos[i].peso << endl;
        archivo << lista.elementos[i].nif << endl;
    }
    archivo << "XXX" << endl;
    archivo.close();
}
void leerEstudiante(tEstudiante& estudiante) 
{
    cin.ignore(80, '\n');
    cout << "Nombre: ";
    getline(cin, estudiante.nombre);
    cout << "Identificacion: ";
    cin >> estudiante.edad;
    cout << "Peso: ";
    cin >> estudiante.peso;
    cout << "Tipo de animal: ";
    cin >> estudiante.nif;
    cin.sync();
}
void insertarEstudiante(tLista& lista, tEstudiante estudiante, bool& ok)
{
    ok = true;
    if (lista.contador == MAX) 
    {
        ok = false;
    }
    else 
    {
        lista.elementos[lista.contador] = estudiante;
        lista.contador++;
    }
}
string nombreCompleto(tEstudiante estudiante) 
{
    return estudiante.nombre;
}
void mostrarEstudinates(tEstudiante estudiante) 
{
    cout << setw(25) << left << estudiante.edad;
    cout << setw(30) << left << nombreCompleto(estudiante);
    cout << setw(15) << left << estudiante.peso;
    cout << setw(30) << left << estudiante.nif << endl;
    cout << endl << endl;
}
void listado(const tLista& lista) 
{
    cout << setw(25) << left << "|IDENTIFICACION|" << setw(30) << left << "|NOMBRE|" << setw(15) << left << "|PESO(kg)|" << setw(30) << left << "|TIPO DE ANIMAL|" << endl;
    for (int i = 0; i < lista.contador; i++) 
    {
        mostrarEstudinates(lista.elementos[i]);
    }
}
void buscar(const tLista& lista, string dato) 
{
    bool a = false;
    for (int i = 0; i < lista.contador; i++) 
    {
        if (lista.elementos[i].nombre == dato) 
        {
            cout << "El elemento se encuentra en la posicion: " << i + 1 << endl;
            a = true;
        }
    }
    cout << endl;
    if (a == false) 
    {
        cout << "Elemento no encontrado" << endl;
        cout << endl;
    }
}
//Fechas
void datosS() 
{
    cout << setw(45) << "|BIENVENIDO|" << endl;
    for (int i = 0; i < 2; i++) 
    {
        cout << setw (15) << "|FECHA " << i + 1 << "|" << endl;
        do {
            cout << "Ingresa el dia, mes y anio (Ejemplo: 15 06 2021): ";
            cin >> fechas[i].dia >> fechas[i].mes >> fechas[i].ano;
            if (fechas[i].dia < 1 || fechas[i].dia>31 || fechas[i].mes < 1 || fechas[i].mes>12) 
            {
                cout << "El dia es en un rango de 1 - 31" << endl;
                cout << "El mes en un rango de 1 - 12" << endl;
                cout << "Intenta nuevamente" << endl;
            }
        } while (fechas[i].dia < 1 || fechas[i].dia>31 || fechas[i].mes < 1 || fechas[i].mes>12);
    }
}
void procesoS() {
    int puntos1, puntos2, punt1, punt2;
    if (fechas[0].dia < fechas[1].dia) 
    {
        puntos1 = 0;
        puntos2 = 1;
    }
    else 
    {
        if (fechas[0].dia > fechas[1].dia) 
        {
            puntos1 = 1;
            puntos2 = 0;
        }
        else 
        {
            puntos1 = 0;
            puntos2 = 0;
        }
    }
    if (fechas[0].mes < fechas[1].mes) 
    {
        punt1 = 0;
        punt2 = 5;
    }
    else 
    {
        if (fechas[0].mes > fechas[1].mes) 
        {
            punt1 = 5;
            punt2 = 0;
        }
        else 
        {
            punt1 = 0;
            punt2 = 0;
        }
    }
    int punts1, punts2;
    if (fechas[0].ano < fechas[1].ano) 
    {
        punts1 = 0;
        punts2 = 20;
    }
    else 
    {
        if (fechas[0].ano > fechas[1].ano) 
        {
            punts1 = 20;
            punts2 = 0;
        }
        else 
        {
            punts1 = 0;
            punts2 = 0;
        }
    }
    int total1, total2;
    total1 = puntos1 + punt1 + punts1;
    total2 = puntos2 + punt2 + punts2;
    if (total1 > total2) 
    {
        cout << endl;
        cout << setw(45) << "LA MAYOR FECHA ES: " << endl;
        cout << setw(35) << " |" << fechas[0].dia << " " << fechas[0].mes << " " << fechas[0].ano << "|" << endl;
        cout << endl;
    }
    else 
    {
        if (total1 < total2) 
        {
            cout << endl;
            cout << setw(45) << "LA MAYOR FECHA ES: " << endl;
            cout << setw(35) << "|" << fechas[1].dia << " " << fechas[1].mes << " " << fechas[1].ano << "|" << endl;
            cout << endl;
        }
        else 
        {
            cout << endl;
            cout << setw(45) << "|AMBAS FECHAS SON IGUALES|" << endl;
            cout << endl;
        }
    }
}
//Becarios
void procesoBecarios()
{
    int n;
    cout << setw(45) << "|BIENVENIDO|" << endl;
    cout << "Ingrese el numero de empleados: ";
    cin >> n;
    tBecarios beca[MAXX];
    for (int i = 0; i < n; i++) 
    {
        cin.ignore(80, '\n');
        cout << "Ingresa el nombre del " << i + 1 << " empleado: ";
        getline(cin, beca[i].nombre);
        cout << "Ingresa la edad de " << beca[i].nombre << ": ";
        cin >> beca[i].edad;
        cin.ignore(80, '\n');
        cout << "Ingresa el grado de estudios de " << beca[i].nombre << ": ";
        getline(cin, beca[i].estudios);
        cout << "Ingresa el tipo de contrato de " << beca[i].nombre << ": ";
        getline(cin, beca[i].contrato);
        cin.sync();
    }
    cout << setw(30) << left << "|EMPLEADO|" << setw(15) << left << "|EDAD|" << setw(35) << left << "|GRADO DE ESTUDIOS|" << setw(35) << left << "|CONTRATACION|" << endl;
    cout << endl;
    for (int i = 0; i < n; i++) 
    {
        cout << setw(30) << left << beca[i].nombre << " " << setw(15) << left << beca[i].edad << " " << setw(35) << left << beca[i].estudios << setw(35) << left << beca[i].contrato << endl;
    }
    cout << endl << endl;
}
//equipo
void datosequipo() 
{
    string a;
    do {
        cin.ignore(80, '\n');
        cout << "Nombre del equipo " << contador + 1 << ": ";
        getline(cin, a);
        if (a != "*") 
        {
            equipos[contador].nombres = a;
            cout << "Partidos ganados de " << equipos[contador].nombres << ": ";
            cin >> equipos[contador].ganados;
            cout << "Partidos empatados " << equipos[contador].nombres << ": ";
            cin >> equipos[contador].empatados;
            contador += 1;
        }
    } while (a != "*");
}
void puntosyordenar() 
{
    for (int i = 0; i < contador; i++) {
        equipos[i].puntos = equipos[i].ganados * 3 + equipos[i].empatados * 1;
    }
    cout << "--------------------------------------------------------------------" << endl;
    cout << setw(50) << left << "|EQUIPO|" << "   |PUNTOS|" << endl;
    for (int i = 0; i < contador; i++) 
    {
        cout << setw(50) << left << equipos[i].nombres << "    [" << equipos[i].puntos << "]" << endl;
    }
    int i, j, aux, min;

    for (i = 0; i < contador; i++)
    {
        min = i;
        for (j = i + 1; j < contador; j++)
        {
            if (equipos[j].puntos <= equipos[min].puntos)
            {
                min = j;
            }

        }
        aux = equipos[i].puntos;
        equipos[i].puntos = equipos[min].puntos;
        equipos[min].puntos = aux;
    }
    cout << setw(35) << "LOS PUNTOS EN ORDEN SON: " << endl;
    for (int i = 0; i < contador; i++) 
    {
        cout << "[" << equipos[i].puntos << "]" << endl;
    }
}
//principal
int menuprincipal()
{
    int op;
    cout << setw(35) << "|MENU GENERAL|" << endl;
    cout << "1.- EQUIPOS DE FUTBOL" << endl;
    cout << "2.- ZOOLOGICO" << endl;
    cout << "3.- BECARIOS" << endl;
    cout << "4.- FECHAS" << endl;
    cout << "0.- SALIR" << endl;
    cout << "OPCION: ";
    cin >> op;
    return op;
}
