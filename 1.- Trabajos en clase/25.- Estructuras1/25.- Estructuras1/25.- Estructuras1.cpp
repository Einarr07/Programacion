#include <iostream>
#include <string>
using namespace std;

typedef struct
{
    string nombre;
    string apellido;
    int edad;
}tPersona;

int main()
{
    tPersona persona1, persona2, persona3;
    persona1.nombre = "Carlos";
    persona1.apellido = "Guevara";
    persona1.edad = 25;

    persona2.nombre = "Eduar";
    persona2.apellido = "kolen";
    persona2.edad = 21;

    cout << "Nombre: " << persona1.nombre << endl 
        << "Apellido: " << persona1.apellido << endl 
        << "Edad: " << persona1.edad << endl;
    cout << endl;
    cout << "Nombre: " << persona2.nombre << endl 
        << "Apellido: " << persona2.apellido << endl 
        << "Edad: " << persona2.edad << endl;

    cout << "Ingrese su primer nombre: ";
    cin >> persona3.nombre;
    cout << "Ingrese su primer apellido: ";
    cin >> persona3.apellido;
    cout << "Ingrese su edad: ";
    cin >> persona3.edad;
    cout << endl;
    cout << "Nombre: " << persona3.nombre << endl 
        << "Apellido: " << persona3.apellido << endl 
        << "Edad: " << persona3.edad << endl;
    return 0;
}