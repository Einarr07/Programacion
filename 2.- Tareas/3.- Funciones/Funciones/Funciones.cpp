#include <iostream>
#include <stdio.h>
#include<math.h>
using namespace std;
//Programa 1
void datos_taylor();
double proceso_taylor(double respuesta_taylor);
//Programa 2
void segundo_despues(int hora, int minuto, int segundo);
void segundo_despues_proceso(int hora, int minuto, int segundo);
//Programa 3
float hipotenusa();
//Programa 4
void pedir_datos_cubo();
void proceso_cubo(int x);
void comprobacion_cubo(int x, int y);
//Programa 5
void pedir_datos();
int Inverso(int x);
void impresion();
//Programa 6
void calculo_hora(int x);
void datos();
int calculo_minutos(int x);
int calculo_total();
//Datos programa 1
double x;
//Datos programa 2
int hour, minute, second;
//Datos programa 4
int numero_cubo, numero_cubo_2 = numero_cubo, igualdad_cubo;
//Datos programa 5
int numero, resto, inverso, numero_2;
//Datos progtrama 6
int hora, minuto, segundo, segundo1, segundo2;


int main() 
{
	int option;
	do
	{
		cout << "***** Bienvenido al programa *****" << endl;
		cout << "Escoje la opcion a ejecutar" << endl;
		cout << "1.- Funcion exponencial" << endl;
		cout << "2.- Hora despues" << endl;
		cout << "3.- Hipotenusa de un triangulo recto" << endl;
		cout << "4.- Numeros de tres sifras" << endl;
		cout << "5.- Funcion inverso" << endl;
		cout << "6.- La hora en tres argumentos enteros" << endl;
		cout << "7.- Salir del programa" << endl;
		cout << "Ingrese el numero: ";
		cin >> option;
		switch (option)
		{
		case 1:
			system("cls");
			datos_taylor();
			cout << "La respuesta es: " << proceso_taylor(x) <<endl;
			//
			cout << endl;
			break;
		case 2:
			system("cls");
			cout << "La hora un segundo despues es: " << endl;
			segundo_despues(hour, minute, second);
			segundo_despues_proceso(hour, minute, second);
			//
			cout << endl;
			break;
		case 3:
			system("cls");
			float contador, d;
			contador = 1;
			while (contador <= 3) 
			{
				system("cls");
				cout << "--- Triangulo numero " << contador << " ---" << endl;
				d = hipotenusa();
				cout << "La hipotenusa es: " << d << endl;
				contador = contador + 1;
			}
			//
			cout << endl;
			break;
		case 4:
			system("cls");
			pedir_datos_cubo();
			proceso_cubo(numero_cubo);
			comprobacion_cubo(numero_cubo, igualdad_cubo);
			igualdad_cubo = 0;
			//
			cout << endl;
			break;
		case 5:
			system("cls");
			cout << "**Funcion inversa**" << endl;
			pedir_datos();
			Inverso(numero);
			impresion();
			inverso = 0;
			//
			cout << endl;
			break;
		case 6:
			system("cls");
			datos();
			calculo_hora(hora);
			cout << "El total de los segundos transcurridos desde las 12 del medio dia son: " << calculo_total() << " segundos." << endl;
			//
			cout << endl;
			break;
		case 7:
			system("cls");
			cout << " *** Gracias por usar el programa ***" << endl;
			option = 7;
			break;
		default:
			system("cls");
			cout << " Error de sintaxis!!, inteta de nuevo " << endl;

			cout << endl;
			break;
		}
	} 
	while (option != 7);
	return 0;
}
//Programa 1
void datos_taylor()
{
	cout << "***** Bievnenido al programa funcion exponencial *****" << endl;
	cout << "** Este programa calcula la funcion exponencial mediante la serie Taylor**" << endl;
	cout << "Ingrese el valor de x: ";
	cin >> x;
}
double proceso_taylor(double respuesta_taylor)
{
	double repeticion, exponente, denominador, i, division, total, respuesta;
	i = 0;
	repeticion = 1;
	denominador = 1;
	total = 0;
	while (repeticion <= 10) 
	{
		i = i + 1;
		exponente = pow(respuesta_taylor, i);
		denominador = denominador * i;
		division = exponente / denominador;
		total = total + division;
		repeticion = repeticion + 1;
	}
	respuesta = 1 + total;
	return respuesta;
}
//Programa 2
void segundo_despues(int hora, int minuto, int segundo) 
{
	cout << "El formato maximo de horas es: 23:59:59" << endl;
	cout << "Ingrese las horas: ";
	cin >> hour;
	cout << "Ingrese los minutos: ";
	cin >> minute;
	cout << "Igrese los segundos: ";
	cin >> second;
}
void segundo_despues_proceso(int hora, int minuto, int segundo) 
{
	if (hora >= 0 && hora <= 23 && minuto >= 0 && minuto <= 59 && segundo >= 0 && segundo <= 59)
	{
		segundo++;
		if (segundo == 60)
		{
			segundo = 00;
			minuto++;
			if (minuto == 60)
			{
				minuto = 00;
				hora++;
				if (hora == 24)
					hora = 0;
			}
		}
		cout << "Un segundo despues la hora es: " << hora << ":" << minuto << ":" << segundo << endl;
	}
	else
		cout << "SINTAXIS DE ERROR!!, INTENTA DE NUEVO" << endl;
}
//Programa 3
float hipotenusa() 
{
	float lado1, lado2;
	double hipotenusa, c;
	cout << "Ingrese el Lado numero 1: ";
	cin >> lado1;
	cout << "Ingrese el Lado numero 2: ";
	cin >> lado2;
	c = pow(lado1, 2) + pow(lado2, 2);
	hipotenusa = sqrt(c);
	return hipotenusa;
}
//Programa 4
void pedir_datos_cubo()
{
	cout << "Este programa hace la comprobacion de si un numero es igual a la suma de sus digitos al cubo" << endl;
	cout << "Ingrese el numero: ";
	cin >> numero_cubo;
}
void proceso_cubo(int x) 
{
	int i, cifras[10];
	i = 0;
	while (x > 0) {
		cifras[i] = x % 10;
		x = x / 10;
		i++;
	}
	for (int s = i - 1; s >= 0; s--) 
	{
		igualdad_cubo = igualdad_cubo + pow(cifras[s], 3);
	}
	cout << numero_cubo << "=" << igualdad_cubo << endl;
}
void comprobacion_cubo(int x, int y) 
{
	if (x == y) 
	{
		cout << "El numero SI es igual a la suma de los cubos de sus digitos" << endl;
	}
	else 
	{
		cout << "El numero NO es igual a la suma de los cubos de sus digitos" << endl;
	}
}
//Programa 5
void pedir_datos() 
{
	cout << "Ingrese el numero: ";
	cin >> numero;
	numero_2 = numero;
}
int Inverso(int x) 
{
	while (numero > 0) 
	{
		resto = numero % 10;
		numero = numero / 10;
		inverso = inverso * 10 + resto;
	}
	return inverso;
}
void impresion() 
{
	if (inverso == numero_2) 
	{
		cout << "El numero es capicua ya que " << numero_2 << " es igual al su invertido " << inverso << endl;
	}
	else 
	{
		cout << "El inverso es: " << inverso << endl;
	}
}
//Programa 6
void datos() 
{
	cout << "-- Este programa calcula el tiempo trasncurrido desde las 12h en segundos" << endl;
	cout << "El formato de la hora es: (22:45:08) " << endl;
	cout << "Por favor ingrese los datos " << endl;
	cout << "Hora: ";
	cin >> hora;
	cout << "Minutos: ";
	cin >> minuto;
	cout << "Segundos: ";
	cin >> segundo;
}
void calculo_hora(int x) 
{
	int retorno_hora;
	if (x == 12) {
		segundo1 = 0;
	}
	else {
		if (x > 12 && x < 24) {
			retorno_hora = x - 12;
			segundo1 = retorno_hora * 3600;
		}
		else {
			if (x < 12 && x>0) {
				retorno_hora = (x - 12) + 24;
				segundo1 = retorno_hora * 3600;
			}
			else {
				cout << "La hora ingresada es incorrecta" << endl;
			}
		}
	}
}
int calculo_minutos(int x) 
{
	int segundo2;
	if (x <= 60 && x >= 0) 
	{
		segundo2 = x * 60;
	}
	else 
	{
		cout << "Los minutos ingresados son incorrectos" << endl;
	}
	return segundo2;
}
int calculo_total() 
{
	int total;
	total = segundo1 + calculo_minutos(minuto) + segundo;
	return total;
}
/* Mateo Congo*/