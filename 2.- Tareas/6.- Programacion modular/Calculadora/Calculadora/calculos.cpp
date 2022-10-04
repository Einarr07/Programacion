#include<iostream>
#include<iomanip>
#include<math.h>
#include "calculos.h"
using namespace std;
int menu() {
    int op;
    cout << setw(50) << "-------------------------------------------" << endl;
    cout << setw(50) << "|  **BIENVENIDO A LA CALCULADORA EPN**    |" << endl;
    cout << setw(50) << "-------------------------------------------" << endl;
    cout << setw(40) << "------------------------" << endl;
    cout << setw(40) << "| 1.- SUMAR            |" << endl;
    cout << setw(40) << "| 2.- RESTAR           |" << endl;
    cout << setw(40) << "| 3.- MULTIPLICAR      |" << endl;
    cout << setw(40) << "| 4.- DIVIDIR          |" << endl;
    cout << setw(40) << "| 5.- POTENCIA         |" << endl;
    cout << setw(40) << "| 6.- RAIZ CUADRADA    |" << endl;
    cout << setw(40) << "| 7.- FACTORIAL        |" << endl;
    cout << setw(40) << "| 0.- SALIR            |" << endl;
    cout << setw(40) << "------------------------" << endl;
    cout << " Opcion: ";
    cin >> op;
    return  op;
}
void suma() 
{
    float primero, segundo, respuesta;
    system("cls");
    cout << setw(45) << "----------" << endl;
    cout << setw(45) << "|  SUMA   |" << endl;
    cout << setw(45) << "----------" << endl;
    cout << setw(33) << "Ingrese el primer numero: ";
    cin >> primero;
    cout << setw(34) << "Ingrese el segundo numero: ";
    cin >> segundo;
    respuesta = primero + segundo;
    cout << setw(30) << "RESPUESTA (+): [" << respuesta << "]" << endl << endl;
}
void resta() 
{
    float primero, segundo, respuesta;
    system("cls");
    cout << setw(45) << "------------" << endl;
    cout << setw(45) << "|  RESTA   |" << endl;
    cout << setw(45) << "------------" << endl;
    cout << setw(33) << "Ingrese el primer numero: ";
    cin >> primero;
    cout << setw(34) << "Ingrese el segundo numero: ";
    cin >> segundo;
    respuesta = primero - segundo;
    cout << setw(30) << "RESPUESTA (-): [" << respuesta << "]" << endl << endl;
}
void multiplicacion() 
{
    float primero, segundo, respuesta;
    system("cls");
    cout << setw(45) << "---------------------" << endl;
    cout << setw(45) << "|  MULTIPLICACION   |" << endl;
    cout << setw(45) << "---------------------" << endl;
    cout << setw(33) << "Ingrese el primer numero: ";
    cin >> primero;
    cout << setw(34) << "Ingrese el segundo numero: ";
    cin >> segundo;
    respuesta = primero * segundo;
    cout << setw(30) << "RESPUESTA (*): [" << respuesta << "]" << endl << endl;
}
void division() 
{
    float primero, segundo, respuesta;
    system("cls");
    cout << setw(45) << "---------------" << endl;
    cout << setw(45) << "|  DIVISION   |" << endl;
    cout << setw(45) << "---------------" << endl;
    cout << setw(33) << "Ingrese el primer numero: ";
    cin >> primero;
    cout << setw(34) << "Ingrese el segundo numero: ";
    cin >> segundo;
    respuesta = primero / segundo;
    cout << setw(30) << "RESPUESTA (/): [" << respuesta << "]" << endl << endl;
}
void potencia() 
{
    float primero, segundo, respuesta;
    system("cls");
    cout << setw(45) << "---------------" << endl;
    cout << setw(45) << "|  POTENCIA   |" << endl;
    cout << setw(45) << "---------------" << endl;
    cout << setw(29) << "Ingrese la base: ";
    cin >> primero;
    cout << setw(34) << "Ingrese el exponente: ";
    cin >> segundo;
    respuesta = pow(primero, segundo);
    cout << setw(30) << "LA POTENCIA ES: [" << respuesta << "]" << endl << endl;
}
void raiz() 
{
    float primero, segundo, respuesta;
    system("cls");
    cout << setw(45) << "-----------" << endl;
    cout << setw(45) << "|  RAIZ   |" << endl;
    cout << setw(45) << "-----------" << endl;
    cout << setw(25) << "Ingresa el numero: ";
    cin >> primero;
    respuesta = sqrt(primero);
    cout << setw(30) << "LA RAIZ CUADRADO ES: [" << respuesta << "]" << endl << endl;
}
void factorial() 
{
    int total = 1, primero;
    system("cls");
    cout << setw(45) << "-------------------" << endl;
    cout << setw(45) << "|  EL FACTORIAL   |" << endl;
    cout << setw(45) << "-------------------" << endl;
    cout << setw(25) << "Ingrese el numero: ";
    cin >> primero;
    for (int i = 1; i < primero + 1; i++) 
    {
        total = total * i;
    }
    cout << setw(30) << "EL FACTORIAL ES: [" << total << "]" << endl << endl;
}