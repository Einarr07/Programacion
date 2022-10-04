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

void guardar_medico(const tLista_m lista); //Guarda datos de médicos al cerrar el menú principal
void aniadir(tLista_m& lista);// Ingresar médicos a la lista
void eliminar(tLista_m& lista);//Elimina médicos de acuerdo con el número de cédula
void proceso(tLista_m& lista);// While con las diferentes opciónes
void mostrar(tLista_m lista);// Muestra la lista de médicos
int menu_ordenar();// Para elgir de acuerdo a que ordenar los datos
int menu_medicos();// menú principal de médicos con todas las opciones
void ordenar(tLista_m& lista);//ordena por nombre
void ordenar_especialidad(tLista_m& lista);//ordena por especialidad
void buscar(tLista_m lista); // Buscar datos de un médico por medio de la cédula
void cargar_medico(tLista_m& lista); // Carga los datos de médicos desde un archivo

#endif