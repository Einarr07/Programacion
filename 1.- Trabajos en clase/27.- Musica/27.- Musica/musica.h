#include <string>
using namespace std;

const int MAX = 10;
typedef struct {
    int numero;
    string titulo;
    string artista;
    string genero;
    int anio;
} tCancion;
typedef struct {
    tCancion elementos[MAX];
    int contador;
} tLista;

int menu(); // Menú del programa - devuelve la opción elegida
void cargar(tLista& lista, bool& ok); // Carga el archivo en la lista
void guardar(const tLista& lista);    // Guarda la lista en el archivo
void leerCancion(tCancion& cancion);  // Lee los datos
void insertarCancion(tLista& lista, tCancion cancion,
    bool& ok); // Inserta una nueva cancion en la lista
void mostrarCancion(tCancion cancion);
void listado(const tLista& lista); // Lista de canciones
void buscarArtista(const tLista lista, string artista, bool& ok);