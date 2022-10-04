#include <iostream>
#include <iomanip>
#include <locale.h>
#include <fstream>
using namespace std;

const int N = 15;

typedef struct {
	int codigo;
	string nombre;
	double sueldo;
} tDato;


typedef struct {
	tDato datos[N];
	int cont;
} tLista;

void mostrar(tLista lista);
bool operator>(tDato opIzq, tDato opDer);
void guardar(tLista lista);


int main()
{
	setlocale(LC_CTYPE, "Spanish");
	tLista lista;
	lista.cont = 0;
	ifstream archivo;
	archivo.open("datos.txt");
	if (!archivo.is_open())
	{
		cout << "No se a podido abrir el archivo";
	}
	else
	{
		tDato dato;
		archivo >> dato.codigo;
		while ((lista.cont < N) && (dato.codigo != -1))
		{
			archivo >> dato.nombre >> dato.sueldo;
			lista.datos[lista.cont] = dato;
			lista.cont++;
			archivo >> dato.codigo;
		}
		archivo.close();
		cout << "Antes de ordenar:" << endl;
		mostrar(lista);
		for (int i = 0; i < lista.cont; i++) //Dedede el segundo hasta el último
		{
			int pos = i;
			while ((pos > 0) && (lista.datos[pos - 1].nombre > lista.datos[pos].nombre)) //Mientras no se llegue al inicio y el anterior sea mayor
			{
				tDato tmp;
				tmp = lista.datos[pos];
				lista.datos[pos] = lista.datos[pos - 1];
				lista.datos[pos - 1] = tmp;
				pos--;
			}
		}
		cout << "Orden por nombre" << endl;
		mostrar(lista);
		guardar(lista);
		//
		for (int i = 0; i < lista.cont; i++) //Dedede el segundo hasta el último
		{
			int pos = i;
			while ((pos > 0) && (lista.datos[pos - 1].codigo > lista.datos[pos].codigo)) //Mientras no se llegue al inicio y el anterior sea mayor
			{
				tDato tmp;
				tmp = lista.datos[pos];
				lista.datos[pos] = lista.datos[pos - 1];
				lista.datos[pos - 1] = tmp;
				pos--;
			}
		}
		cout << "Ordenar por código" << endl;
		mostrar(lista);
	}
}

void mostrar(tLista lista)
{
	for (int i = 0; i < lista.cont; i++)
	{
		cout << setw(10)
			<< lista.datos[i].codigo
			<< setw(20)
			<< lista.datos[i].nombre
			<< setw(12)
			<< fixed
			<< setprecision(2)
			<< lista.datos[i].sueldo
			<< endl;
	}
}
bool operator>(tDato opIzq, tDato opDer)
{
	return opIzq.sueldo > opDer.sueldo;
}

void guardar(tLista lista)
{
	ofstream salida;
	salida.open("ordenacion.txt");
	for (int i = 0; i < lista.cont; i++) {
		salida << lista.datos[i].codigo
			<< setw(20)
			<< lista.datos[i].nombre
			<< setw(12)
			<< fixed
			<< setprecision(2)
			<< lista.datos[i].sueldo
			<< endl;
	}
	salida << -1 << endl;
	salida.close();
}