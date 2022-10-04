#ifndef citas_h
#define citas_h
#include <string>
#include "medicos.h"
#include "pacientes.h"

const int N_c = 100;

typedef struct {
	int codigo;
	int turno;
	string nombre;// Nombre del paciente
	string area;
	string doctor;
}tCita;
typedef struct {
	tCita elementos_c[N_c];
	int cont;
}tLista_c;

void proceso_c(tLista_m& lista, tLista_p& lista_p, tLista_c& lista_c);// While con las diferentes opciónes
void modificar(tLista_p& lista_p, tLista_c& lista_c);//Modifica el turno de una cita
void consultar(tLista_p& lista_p, tLista_c& lista_c);// Consulta cita por medió del código del paciente
int menu_citas(); // Menú principal de citas con todas las opciones
void ingresar_citas(tLista_m& lista, tLista_p& lista_p, tLista_c& lista_c); // Ingresar citas
void guardar_citas(tLista_c& lista_c); //Guarda los datos al salir del menú de citas
void eliminar(tLista_p& lista_p, tLista_c& lista_c); //Elimina una cita por medio del código del paciente
void cargar_citas(tLista_c& lista_c); // Carga los datos desde un archivo
int menu_ordenar_c();// Para elgir de acuerdo a que ordenar los datos
void ordenar(tLista_c& lista_c); // Ordena los datos de acuerdo al nombre
void ordenar_turno(tLista_c& lista_c); // Ordena los datos de acuerdo al turno
void mostrar(tLista_c lista_c); // Muestra la lista de citas

#endif