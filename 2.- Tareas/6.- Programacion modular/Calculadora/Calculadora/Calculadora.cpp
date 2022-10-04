#include <iostream>
#include<iomanip>
#include "calculos.h"
using namespace std;

int main() 
{
	int op;
	do {
	op = menu();
	switch (op)
	{
	case 1: 
	{
		suma();
		break;
	}
	case 2:
	{
		resta();
		break;
	}
	case 3:
	{
		multiplicacion();
		break;
	}
	case 4:
	{
		division();
		break;
	}
	case 5:
	{
		potencia();
		break;
	}
	case 6:
	{
		raiz();
		break;
	}
	case 7:
	{
		factorial();
		break;
	}
	case 0:
	{
		system("cls");
		cout << setw(8) << "--------------------------------------------" << endl;
		cout << setw(8) << "|    GRACIAS POR UTILIZAR EL PROGRAMA      |" << endl;
		cout << setw(8) << "--------------------------------------------" << endl;;
		break;
	}
	default:
	{
		system("cls");
		cout << setw(8) << "----------------------------------------------------" << endl;
		cout << setw(8) << "|    LA OPCION ES INCORRECTA, INTENTE DE NEUVO     |" << endl;
		cout << setw(8) << "----------------------------------------------------" << endl;
	}
	}
	} while (op != 0);
return 0;
}