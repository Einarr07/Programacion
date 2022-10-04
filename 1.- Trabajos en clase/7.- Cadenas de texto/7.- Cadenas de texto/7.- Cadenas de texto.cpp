#include <iostream>
using namespace std;

int main()
{
	//
	string nombre1, nombre2, apellido1, apellido2;

	cout << "Ingrese su primer nombre: ";
	cin >> nombre1;
	cout << "Ingrese su segundo nombreo: ";
	cin >> nombre2;
	cout << "Ingrese su primer apellido: ";
	cin >> apellido1;
	cout << "Ingrese su segundo apellido: ";
	cin >> apellido2;
	cout << "Su nombre completo es: " << nombre1 << " " << nombre2 << " " << apellido1 << " " << apellido2;

	return 0;
}
