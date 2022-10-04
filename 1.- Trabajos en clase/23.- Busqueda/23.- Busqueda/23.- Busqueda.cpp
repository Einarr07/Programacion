#include <iostream>
#include <fstream>
using namespace std;

int main()
{

	double d, num;
	bool encontrado = false;
	//
	cout << "Encontrar el primer numero mayor a: ";
	cin >> num;
	ifstream archivo;
	archivo.open("busquedaa.txt");
	//
	if (archivo.is_open())
	{
		archivo >> d;
		while (((d != -1) && !encontrado))
		{
			if (d > num)
			{
				encontrado = true;
				cout << "El primer numero mayor a " << num << " es: " << d;
			}
			else
			{
				archivo >> d;
			}
		}
		if (!encontrado)
		{
			cout << "El numero no a sido encontrado" << endl;
		}
		archivo.close();
	}
	return 0;
}