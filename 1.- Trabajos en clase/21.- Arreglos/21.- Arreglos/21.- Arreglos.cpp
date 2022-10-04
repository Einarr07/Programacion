#include <iostream>
#include <fstream>
using namespace std;

int main()
{

	double d, suma = 0;
	ifstream archivo;
	archivo.open("datos.txt");
	if (archivo.is_open())
	{
		archivo >> d;

		while (d != 0)
		{
			suma += d;
			archivo >> d;
		}
		archivo.close();
	}
	cout << suma << endl;
	return 0;
}
/*
#include <iostream>
using namespace std;

int main()
{
	int longitud = 0;
	char c;
	cout << "Ingrese un tecto que finalice en un punto (.): ";
	cin >> c;
	while (c != '.')
	{
		longitud++;
		cin >> c;
	}
	cout << "La longitud del texto es de " << longitud << " caracteres" << endl;
}
*/