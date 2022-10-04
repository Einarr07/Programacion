

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
const int Max = 100;
//
typedef struct
{
	string nombre;
	string apellido;
	int edad;
	string cedula;
	double nota;
} tEstudiante;
//
typedef struct
{
	tEstudiante elementos[Max];
	int contador;
}tLista;
//Portotipos
int menu();
void cargar(tLista& lista, bool& ok);
void guardar(const tLista& lista, bool& ok);
void leerEstudiante(tEstudiante& estudiante);
void insertarEstuidante(tLista& lista, tEstudiante estudiante, bool& ok);
void eliminarEstudiante(tLista& lista, int pos, bool& ok);
void calificar(tLista& lista);
string nombreCompleto(tEstudiante estudiante);
double mediaClase(const tLista lista);
int mayorNota(const tLista lista);
void listado(const tLista lista, double media, int mayor);
int menu();

//
int main()
{
	tLista lista;
	tEstudiante estudiante;
	bool exito;
	int op, pos;
	cargar(lista, exito);
	if (!exito)
	{
		cout << "No se a podido cargar la lista";
	}
	else 
	{
		do{
			op = menu();
			switch (op)
			{
			case 1:
			{
				leerEstudiante(estudiante);
				insertarEstuidante(lista, estudiante, exito);
				if (!exito)
				{
					cout << "Lista llena, imposible insertar mas estudiantes" << endl;
				}
			}
			break;
			//
			case 2:
			{
				cout << "Posicion del estudiante a eliminar: ";
				cin >> pos;
				eliminarEstudiante(lista, pos - 1, exito);
				if (!exito)
				{
					cout << "Elemento inexistente" << endl;
				}
			}
			//
			break;
			case 3:
			{
				calificar(lista);
			}
			break;
			//
			case 4:
			{
				listado(lista, mediaClase(lista), mayorNota(lista));
			}
			}
		} while (op != 0);
		
	}
	return 0;
}
//
void cargar(tLista& lista, bool& ok)
{
	tEstudiante estudiante;
	ifstream archivo;
	char aux;
	lista.contador = 0;

	archivo.open("clase.txt");
	if (!archivo.is_open())
	{
		ok = false;
	}
	else
	{
		ok = true;
		getline(archivo, estudiante.nombre);
		while ((estudiante.nombre != "XXX") && (lista.contador < Max))
		{
		getline(archivo, estudiante.apellido);
		archivo >> estudiante.edad;
		archivo >> estudiante.cedula;
		archivo >> estudiante.nota;
		archivo.get(aux);
		lista.elementos[lista.contador] = estudiante;
		lista.contador++;
		getline(archivo, estudiante.nombre);
		}
		archivo.close();
	}
}
//
void guardar(const tLista& lista, bool& ok)
{
	ofstream archivo;
	archivo.open("clase.txt");
	for (int i = 0; i < lista.contador; i++)
	{
		archivo << lista.elementos[i].nombre << endl;
		archivo << lista.elementos[i].apellido << endl;
		archivo << lista.elementos[i].edad << endl;
		archivo << lista.elementos[i].cedula << endl;
		archivo << lista.elementos[i].nota << endl;
	}
	archivo << "XXX" << endl;
}
//
int menu()
{
	int op;
		do {
			cout << "1.- Añadir un nuevo estudiante" << endl;
			cout << "2.- Eliminar un estudiante" << endl;
			cout << "3.- Calificar a los estudiantes" << endl;
			cout << "4.-´Listado de estudiantes" << endl;
			cout << "0.- Salir" << endl;
			cout << "Opcion: ";
			cin >> op;
		} while ((op < 0) || (op > 4));
		return op;
}
//
void leerEstudiante(tEstudiante& estudiante)
{
	cin.ignore();
	cout << "Nombre: ";
	getline(cin, estudiante.nombre);
	cout << "Apellidos: ";
	getline(cin, estudiante.apellido);
	cout << "Edad: ";
	cin >> estudiante.edad;
	cout << "Cedula: ";
	cin >> estudiante.cedula;
	estudiante.nota = -1; //Sin calificar de momentoi
	cin.sync();
}
//
void insertarEstuidante(tLista& lista, tEstudiante estudiante, bool& ok)
{
	ok = true;
	if (lista.contador == Max)
	{
		ok = false;
	}
	else
	{
		lista.elementos[lista.contador] = estudiante;
		lista.contador++;
	}
}
//
void eliminarEstudiante(tLista& lista, int pos, bool& ok)
{
	if ((pos < 0) || pos > lista.contador - 1)
	{
		ok = false;
	}
	else
	{
		ok = true;
		for (int i = pos; i < lista.contador; i++)
		{
			lista.elementos[i] = lista.elementos[i + 1];
		}
		lista.contador--;
	}
}
//
void calificar(tLista& lista)
{
	for (int i = 0; i < lista.contador; i++)
	{
		cout << "Nota del estudiante " << lista.elementos[i].nombre << " " << lista.elementos[i].apellido << " : ";
		cout << "Nota del estudiante " << nombreCompleto(lista.elementos[i]) << ": ";
		cin >> lista.elementos[i].nota;
	}
}
//
string nombreCompleto(tEstudiante estudiante)
{
	return estudiante.nombre + " " + estudiante.apellido;
}
//
double mediaClase(const tLista lista)
{
	double total = 0;
	for (int i = 0; i < lista.contador; i++)
	{
		total = total + lista.elementos[i].nota;
	}
	return total / lista.contador;
}
//
int mayorNota(const tLista lista)
{
	double maximaN = 0;
	int pos = 0;
	for (int i = 0; i < lista.contador; i++)
	{
		if (lista.elementos[i].nota > maximaN)
		{
			maximaN = lista.elementos[i].nota;
			pos = i;
		}
	}
	return pos;
}
//
void mostrarEstudiante(tEstudiante estudiante)
{
	cout << setw(38) << left << nombreCompleto(estudiante);
	cout << estudiante.cedula << " ";
	cout << setw(2) << right << estudiante.edad << "años ";
	cout << fixed << setprecision(1) << estudiante.nota;

}
//
void listado(const tLista lista, double media, int mayor)
{
	for (int i = 0; i < lista.contador; i++)
	{
		cout << setw(3) << right << i + 1 << " : ";
		mostrarEstudiante(lista.elementos[i]);
		if (i == mayor)
		{
			cout << "Mayor nota!";
		}
		cout << endl;
	}
	cout << "Media de la clase: " << fixed << setprecision(1) << media << endl << endl;
}