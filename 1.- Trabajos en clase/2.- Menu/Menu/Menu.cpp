//menu
#include <iostream>
using namespace std;
//
int menu();
void programa1();
void programa2();
void programa3();
//
int main()
{
	int opcion = menu();
	while (opcion != 0)
	{
		switch (opcion)
		{
			//
		case 1:
		{
			programa1();
			cout << endl;
		}
		break;
		//
		case 2:
		{
			programa2();
		}
		break;
		//
		case 3:
		{
			programa3();
		}
		break;
		//
		}
	opcion = menu();
	}
	return 0;
}
//
int menu()
{
	int op = -1;
	while ((op < 0) || (op > 3))
	{
		cout << "*** MENU ***" << endl;
		cout << "1.- Opcion 1" << endl;
		cout << "2.- Opcion 2" << endl;
		cout << "3.- Opcion 3" << endl;
		cout << "0.- Salir" << endl;
		cout << "Escoja una opcion: ";
		cin >> op;
		if ((op < 0) || (op > 3))
		{
			cout << "La opcion que ingresaste no es valida";
		}
	}
	return op;
}
//
void programa1()
{
	cout << "Se ejecuto el programa 1 con exito";
	cout << endl;
}
//
void programa2()
{
	cout << "Se ejecuto el programa 2 con exito";
	cout << endl;
}
//
void programa3()
{
	cout << "Se ejecuto el programa 3 con exito";
	
}