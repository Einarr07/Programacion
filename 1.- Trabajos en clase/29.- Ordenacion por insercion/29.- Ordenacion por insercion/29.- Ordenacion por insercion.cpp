#include <iostream>
#include <locale.h>
using namespace std;

const int N = 9;
void imprimir(int lista[N]);

int main()
{
	setlocale(LC_CTYPE, "Spanish");
	/*
	int lista[N] = { 5,4,6,7,3,7,45,765,87};
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
		//cout << "Iteración del for " << i << endl;
		//imprimir(lista);
		*/
		//Segundo algoridmo
	string mensaje = "Algoritmo de ordenación por insercciones e intercambios";
	int lista_1[N] = { 976, 45,23,54,12,34,4,5,32 };
	cout << mensaje << endl;
	imprimir(lista_1);
	int tmp, pos;
	for (int i = 1; i < N; i++)
	{
		pos = i;
		while ((pos > 0) && (lista_1[pos - 1] > lista_1[pos]))
		{
			//intercambiar
			tmp = lista_1[pos];
			lista_1[pos] = lista_1[pos - 1];
			lista_1[pos - 1] = tmp;
			pos--;
		}

	}

	cout << "Resultado final: ";
	imprimir(lista_1);
}

void imprimir(int lista[N])
{
	for (int i = 0; i < N; i++)
	{
		cout << lista[i] << " ";
	}
	cout << endl;
}