#include <iostream>
#include <locale.h>
using namespace std;

const int N = 9;
void imprimir(int lista[N]);

int main()
{
	setlocale(LC_CTYPE, "Spanish");
	int lista[N] = { 5,4,6,7,3,7,45,765,87 };
	imprimir(lista);
	int nuevo, pos;
	//Desde el segundo elemneto hasta el ultimo 
	for (int i = 1; i < N; i++)
	{
		nuevo = lista[i];
		pos = 0;
		while ((pos < i) && !(lista[pos] > nuevo))
		{
			pos++;
		}
		//pos = indice del primer elemento mayor; i si no lo hay
		for (int j = i; j > pos; j--)
		{
			lista[j] = lista[j - 1];
		}

		lista[pos] = nuevo;
		cout << "Iteración del for " << i << endl;
		imprimir(lista);
	}
	//
	cout << "Resultado final: ";
	imprimir(lista);
}

void imprimir(int lista[N])
{
	for (int i = 0; i < N; i++)
	{
		cout << lista[i] << " ";
	}
	cout << endl;
}