/*
Escriba un programa que pida al usuario su nombre y contraseña y le de tres oportunidades para introducir los datos correctos
que serán: "root" y "1234" respectivamente.

Si los datos introducidos son correctos se mostrará por pantalla “Bienvenido al sistema”. 
Caso contrario se mostrará un mensaje por pantalla indicando que se ha superado el número de intentos permitido.
*/

#include <iostream>
#include <string>
#include <cstdlib>
#define user "root"
#define pass "1234"
using namespace std;

int main()
{
	string usuario, contrasenia;
	int contador = 0;
	bool ingreso = false;

	do {
		system("cls");
		cout << "***Inicio de sesion***" << endl;
		cout << "--------------------" << endl;
		cout << "Usuario: ";
		getline(cin, usuario);
		cout << "Contraseña: ";
		getline(cin, contrasenia);

		if (usuario == user && contrasenia == pass) {
			ingreso = true;
		}
		else {
			cout << "El usuario o contraseña son incorrectos" << endl;
			contador++;
		}
	} while (ingreso == false && contador < 3);

	if (ingreso == false) {
		cout << "Se a suspendido el numero de intentos permitidos" << endl;
	}
	else {
		cout << "Bienvenido al sistema" << endl;
	}
	return 0;
}

