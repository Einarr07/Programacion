#include <iostream>
#include <locale.h>
#include <string>
using namespace std;
#include <fstream>
#include <iomanip>
#include "musica.h"


int main() {
    setlocale(LC_ALL, ""); // permite imprimir caracteres con tildes
    tLista lista;
    tCancion cancion;
    bool exito;
    int op;
    string artista;

    cargar(lista, exito);

    if (!exito) {
        cout << "No se ha podido cargar la lista!" << endl;
    }
    else {
        do { // El bucle do evita tener que leer antes la primera opción
            op = menu();
            switch (op) {
            case 1: {
                listado(lista);

            } break;
            case 2: {
                leerCancion(cancion);
                insertarCancion(lista, cancion, exito);
                if (!exito) {
                    cout << "Lista llena: imposible insertar" << endl;
                }

            } break;
            case 3: {
                cin.ignore();
                cout << "Nombre del artista a buscar: ";
                getline(cin, artista);
                buscarArtista(lista, artista, exito);
                if (!exito) {
                    cout << "No hay canciones de ese artista!" << endl;
                }
            }
            }
        } while (op != 0);

        guardar(lista);
    }

    return 0;
}