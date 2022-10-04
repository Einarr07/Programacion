// Arreglos.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.

#include <iostream>
#include <iomanip>
using namespace std;
//
int menu();
//ejercicio 1
void calificaciones();
void agregar(double lista[]);
void buscar(double lista[], double dato);
void ordenar(double a[]);
void eliminar(double a[]);
void insertar(double a[]);
int contador = 0;
const int Max = 50;
double lista5[Max];
//ejercicio 2
void palindromo();
void impresion();
int lista[Max], lista2[Max], lista3[Max], contador2;
const int Maxx = 20;
//ejercicio 3
void duplicados(int Inicial[], int Aux[], int Final[]);
const int MAX = 20;
//ejercicio 4
void iniciar(int guardar[]);
int lanzar();
void game(int guardar[]);
void dados(int guardar[]);
void inversoo(int x[]);
const int veces = 36000;

int main()
{
    int op = menu();
    while (op != 0)
    {
        switch (op)
        {
        case 1:
        {
            system("cls");
            int opcion;
            calificaciones();
            agregar(lista5);
            do {
                cout << " ****** OPCIONES ***** " << endl;
                cout << "1.-Agregar mas calificaciones." << endl;
                cout << "2.-Buscar una calificacion." << endl;
                cout << "3.-Elimminar una calificacion." << endl;
                cout << "4.-Ordenar las calificaciones." << endl;
                cout << "5.-Insertar una calificacion." << endl;
                cout << "6.-Salir." << endl;
                cout << "SELECCIONE: ";
                cin >> opcion;
                switch (opcion)
                {
                case 1:
                    if (contador < 50) {
                        agregar(lista5);
                    }
                    else {
                        cout << "El maximo a sido alcanzado" << endl;
                    }
                    break;
                case 2:
                    int dato;
                    cout << "Ingresa la calificacion a buscar: ";
                    cin >> dato;
                    buscar(lista5, dato);
                    break;
                case 3:
                    eliminar(lista5);
                    break;
                case 4:
                    ordenar(lista5);
                    break;
                case 5:
                    insertar(lista5);
                    break;
                case 6:
                    cout << "Gracias por usar nuestro sistema de calificaciones" << endl;
                    contador = 0;
                    break;
                default:
                    cout << "La opcion que tratas de ingresar no es valida" << endl;
                }
            } while (opcion != 6);
            contador = 0;
            opcion = 0;
        }
        break;
        case 2:
        {
            system("cls");
            cout <<  setw(25) << " *** Palindromos ***" << endl;
            palindromo();
            inversoo(lista);
            impresion();
            for (int i = 0; i < contador2; i++) {
                lista3[i] = 0;
            }
            contador = 0;
        }
        break;
        case 3:
        {
            system("cls");
            int arreglo1[MAX], arreglo2[MAX], arreglo3[MAX];
            duplicados(arreglo1, arreglo2, arreglo3);
            for (int i = 0; i < MAX; i++) {
                arreglo1[i] = 0;
            }
        }
        break;
        case 4:
        {
            system("cls");
            int x[11];
            srand(time(0));
            iniciar(x);
            game(x);
            dados(x);
        }
        break;
        default:
        {
            cout << "La opcion es incorrecta, intenta de neuvo " << endl;
        }
            break;
        }
        op = menu();
    }
    return 0;
}
// 
int menu()
{
    int op = -1;
    while ((op < 0) || (op > 4))
    {
        cout << "***** MENU *****" << endl;
        cout << "1.- CALIFICACIONES " << endl;
        cout << "2.- Palindromo " << endl;
        cout << "3.- Duplicados " << endl;
        cout << "4.- Dados " << endl;
        cout << "0.- SALIR " << endl;
        cout << "Opcion:";
        cin >> op;
        if ((op < 0) || (op > 4))
        {
            cout << "La opcion que tratas de ingresar no es valida." << endl;
        }
    }
    return op;
}
//ejercicio 1
void calificaciones()
{
    cout << setw(25) << "***BIENVENIDO AL SISTEMA DE CALIFICACIONES***" << endl;
    cout << "El ingreso de califiaciones sera de 1 a 10" << endl;
    cout << "NOTA: Si quieres dejar de ingresar calificaciones pon -1" << endl;
}
//ejercicio 1
void agregar(double lista[])
{
    int calif, x;
    do
    {
        do {
            cout << "Ingresa la calificacion Numero " << contador + 1 << ": ";
            cin >> lista[contador];
            if (lista[contador] > 10 || lista[contador] < -1) {
                cout << "El rango de calificaciones es del 0 al 10." << endl;
                cout << "Ingresa nuevamente: " << endl;
            }
        } while (lista[contador] > 10 || lista[contador] < -1);
        if (lista[contador] == -1)
        {
            lista[contador] = lista[contador];
            x = lista[contador];
        }
        else
        {
            x = lista[contador];
            contador++;
        }
    } while (x != -1 && contador < Max);
}
//ejercicio 1
void buscar(double lista[], double dato)
{
    bool c = false;
    for (int i = 0; i < contador; i++)
    {
        if (lista[i] == dato and lista[i] < 11)
        {
            cout << setw(45) << "**La calificacion a sidon encontrada**" << endl;
            cout << "La calificacion esta en la posicion: " << i + 1 << endl;
            c = true;
        }
    }
    if (c == false)
    {
        cout << "La calificacion que ingresaste no existe." << endl;
    }
    else {
        cout << "Posiciones de las calificaciones:" << endl;
        for (int i = 0; i < contador; i++) {
            cout << setw(35) << "Calificacion " << i + 1 << ":";
            if (lista[i]<11 && lista[i]>-1) {
                cout << "[" << lista[i] << "]" << endl;
            }
            else {
                cout << "***" << endl;
            }
        }
    }
}
//ejercicio 1
void ordenar(double a[])
{
    int i, j, aux;
    for (i = 0; i < contador; i++)
    {
        for (j = i + 1; j < contador; j++)
        {
            if (a[j] <= a[i])
            {
                aux = a[i];
                a[i] = a[j];
                a[j] = aux;
            }
        }
    }
    cout << setw(25) << "Las calificaciones en orden son:" << endl;
    for (int i = 0; i < contador; i++)
    {

        if (a[i]<11 && a[i]>-1) {
            cout << setw(25) << "Calificacion " << i + 1 << ": [" << a[i] << "]" << endl;
        }
    }
}
//ejercicio 1
void eliminar(double a[])
{
    int eliminar;
    cout << setw(25) << "Las calificaciones son: " << endl;
    for (int i = 0; i < contador; i++)
    {
        cout << setw(25) << "Calificacion " << i + 1 << ":";
        if (a[i]<11 && a[i]>-1) {
            cout << "[" << a[i] << "]" << endl;
        }
        else {
            cout << "---" << endl;
        }
    }
    cout << setw(25) << "Ingresa la posicion de la calificacion que deseas eliminar: ";
    cin >> eliminar;
    cout << setw(25) << "DATOS ACTUALIZADOS:" << endl;
    a[eliminar - 1] = 12;
    for (int i = 0; i < contador; i++)
    {
        cout << setw(25) << "Calificacion " << i + 1 << ":";
        if (a[i]<11 && a[i]>-1) {
            cout << "[" << a[i] << "]" << endl;
        }
        else {
            cout << "---" << endl;
        }
    }
}
//ejercicio 1
void insertar(double a[])
{
    bool c = false;
    int dato;
    cout << "Las calificaciones son:" << endl;
    for (int i = 0; i < contador; i++)
    {
        cout << "Calificacion " << i + 1 << ":";
        if (a[i]<11 && a[i]>-1) {
            cout << "[" << a[i] << "]" << endl;
        }
        else {
            cout << "---" << endl;
        }
    }
    int x;
    cout << "Ingrese la posicion de la calificacion a modificar: ";
    cin >> dato;
    if (dato > contador) {
        cout << "La posicion no existe." << endl;
    }
    else {
        x = a[dato - 1];
        cout << "Ingresa la nueva calificacion: ";
        cin >> a[dato - 1];
        if (a[dato - 1] > 10 || a[dato - 1] < 0) {
            cout << "Ingresa la calificacion en el rango solicitado" << endl;
            a[dato - 1] = x;
        }
        cout << "DATOS ACTUALIZADOS:" << endl;
        for (int i = 0; i < contador; i++)
        {
            cout << "Calificacion " << i + 1 << ":";
            if (a[i]<11 && a[i]>-1) {
                cout << "[" << a[i] << "]" << endl;
            }
            else {
                cout << "---" << endl;
            }
        }
    }
}
//ejercicio 2
void palindromo() {
    cout << "Cuantos numeros deseas ingresar?" << endl;
    cout << "-> ";
    cin >> contador2;
    for (int i = 0; i < contador2; i++) {
        cout << "Ingrese el numero " << i + 1 << ":";
        cin >> lista[i];
        lista2[i] = lista[i];
    }
}
//ejercicio 2
void impresion() {
    cout << "El resultado de los datos ingresados son:" << endl;
    for (int i = 0; i < contador2; i++) {
        if (lista2[i] == lista3[i]) {
            cout << "[" << lista2[i] << "] " << "-> Es un Palindrommo." << endl;
        }
        else {
            cout << "[" << lista2[i] << "] " << "-> No es un Palindrommo." << endl;
        }
    }
    cout << "Gracias por usar nuestro sistema de palindromos" << endl;
    cout << "El programa a finalizado" << endl;
}
//ejercicio 3
void duplicados(int Inicial[], int Aux[], int Final[]) {
    int n, i, j = 0, z = 0, k, cont, num;

    cout << setw(60) << " ***** BIENVENIDO A DUPLICADOS******" << endl;
    cout << "Por favor ingresa numeros en este rango: 10-100" << endl;

    for (i = 0; i < MAX; i++)
    {
        do {
            cout << "Ingresa el numero " << i + 1 << ": ";
            cin >> Inicial[i];
            if (Inicial[i] < 10 || Inicial[i]>100) {
                cout << "Por favor ingresa un numero en el rango solicitado." << endl;
            }
        } while (Inicial[i] < 10 || Inicial[i]>100);
    }

    for (i = 0; i < MAX; i++)
    {
        cont = 0;

        num = Inicial[i];

        Aux[j] = num;

        j++;

        for (k = 0; k < MAX; k++)
        {
            if (Aux[k] == num)
            {
                cont++;
            }
        }

        if (cont == 1)
        {
            Final[z] = num;

            z++;
        }
    }

    cout << setw(50) << "LA LISTA DE NUMEROS SIN REPETIRSE ES: " << endl;

    for (i = 0; i < z; i++)
    {
        cout << "[" << Final[i] << "]";
    }
    cout << endl;
    cont = 0;
}
//ejercicio 4 
void dados(int guardar[]) {
    cout << setw(60) << " ***** BIENVENIDO AL LANZAMIENTO DE UN DADO *****" << endl;
    for (int i = 0; i < 11; i++) {
        cout << setw(30) << "[" << i + 2 << "] --> [" << guardar[i] << "]" << endl;
    }
}
void inversoo(int x[]) {
    int resto;
    for (int i = 0; i < contador2; i++) {
        while (lista[i] > 0) {
            resto = lista[i] % 10;
            lista[i] = lista[i] / 10;
            lista3[i] = lista3[i] * 10 + resto;
        }
    }
}
void iniciar(int guardar[]) {
    for (int i = 0; i < 11; i++) {
        guardar[i] = 0;
    }
}
int lanzar() {
    return (rand() % 6) + 1;
}
void game(int guardar[]) {
    int datos1;
    for (int i = 0; i < veces; i++) {
        datos1 = lanzar() + lanzar();
        guardar[datos1 - 2]++;
    }
}