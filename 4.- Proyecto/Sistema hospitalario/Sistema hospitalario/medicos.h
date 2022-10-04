#include <string>
#ifndef medicos_h
#define medicos_h

const int N = 100;

typedef struct {
	string nombre;
	string especialidad;
	string cedula;
	int edad;
	string celular;
	string correo;
}tMedicos;
typedef struct {
	tMedicos elementos_m[N];
	int cont;
}tLista_m;

void guardar_medico(const tLista_m lista); //Guarda datos de m�dicos al cerrar el men� principal
void aniadir(tLista_m& lista);// Ingresar m�dicos a la lista
void eliminar(tLista_m& lista);//Elimina m�dicos de acuerdo con el n�mero de c�dula
void proceso(tLista_m& lista);// While con las diferentes opci�nes
void mostrar(tLista_m lista);// Muestra la lista de m�dicos
int menu_ordenar();// Para elgir de acuerdo a que ordenar los datos
int menu_medicos();// men� principal de m�dicos con todas las opciones
void ordenar(tLista_m& lista);//ordena por nombre
void ordenar_especialidad(tLista_m& lista);//ordena por especialidad
void buscar(tLista_m lista); // Buscar datos de un m�dico por medio de la c�dula
void cargar_medico(tLista_m& lista); // Carga los datos de m�dicos desde un archivo

#endif