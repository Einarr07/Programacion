// Calificaciones.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
using namespace std;

int main()
{
    //
    double calificacion1, calificacion2, calificacion3, promedio;
    //
    cout << " ---Sistema de calificaciones--- " << endl;
    cout << endl;
    cout << "Estimado estudiante, ingrese sus 3 calificaciones" << endl;
    cout << "Nota: tenga en cuenta que la nota mas alta solo puede ser 10" << endl;
    cout << "Calificacion 1: ";
    cin >> calificacion1;
    cout << "Calificacion 2: ";
    cin >> calificacion2;
    cout << "Calificacion 3: ";
    cin >> calificacion3;
    //
    promedio = (calificacion1 + calificacion2 + calificacion3) / 3;
    //
    if (promedio > 10)
        cout << "Calificaciones no admitidas";
    else if (promedio == 10)
        cout << "Tu promedio es A";
    else if (promedio >= 9)
        cout << "Tu promedio es B";
    else if (promedio >= 8)
        cout << "Tu promedio es C";
    else if (promedio >= 0)
        cout << "Estas reprobado";
    

    return 0;

}
