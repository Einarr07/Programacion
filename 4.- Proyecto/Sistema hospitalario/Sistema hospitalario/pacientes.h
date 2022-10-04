#ifndef pacientes_h
#define pacientes_h
#include <string>

const int N_p = 100;

typedef struct {
	int codigo;
	string cedula;
	string nombre;
	int edad;
}tPacientes;

typedef struct {
	tPacientes elementos_p[N_p];
	int cont;
}tLista_p;

void guardar_pacientes(const tLista_p lista_p); //Guarda información de pacientes al cerrar el menú principal
void aniadir(tLista_p& lista_p);//Ingresa paciente a la lista
void eliminar(tLista_p& lista_p);//Elimina paciente de acuerdo con su código
void proceso_p(tLista_p& lista_p); // While con las diferentes opciónes
void mostrar(tLista_p lista_p);// Muestra lista de pacientes
int menu_pacientes();//Menú principal de pacientes con las diferentes opciones
void ordenar(tLista_p& lista_p);//Ordena pacientes de acuerdo con su nombre
void buscar(tLista_p lista_p);//Busca información de acuerdo con su código
void cargar_paciente(tLista_p& lista_p);// Carga la lista de pacientes desde un archivo

#endif