#include <iostream>
#include <locale.h>
#include <fstream>
using namespace std;

const int N = 100;


typedef struct {
	int elementos[N];
	int contador;
}tLista;

void imprimir(tLista lista);


int main()
{
	setlocale(LC_CTYPE, "Spanish");
	tLista lista;
	ifstream archivo;
	int dato, pos, tmp;
	lista.contador = 0;
	archivo.open("insersion.txt");
	if (!archivo.is_open())
	{
		cout << "Error el archivo no se a cargado" << endl;
	}
	else
	{
		archivo >> dato;
		while ((lista.contador < N) && (dato != -1))
		{
			lista.elementos[lista.contador] = dato;
			lista.contador++;
			archivo >> dato;
		}
	}
	archivo.close();

	cout << "Antes de ordenar" << endl;
	imprimir(lista);
	//algoritmo de ordenación
	for (int i = 1; i < lista.contador; i++)
	{
		pos = i;
		while ((pos > 0) && (lista.elementos[pos - 1] > lista.elementos[pos]))
		{
			//intercambios
			tmp = lista.elementos[pos];
			lista.elementos[pos] = lista.elementos[pos - 1];
			lista.elementos[pos - 1] = tmp;
			pos--;
			/*
			tmp = c
			*/
		}
	}
	cout << "después de ordenar " << endl;
	imprimir(lista);

}

void imprimir(tLista lista)
{
	for (int i = 0; i < lista.contador; i++)
	{
		cout << "Lista: " << lista.elementos[i] << " ";
	}
	cout << endl;
}