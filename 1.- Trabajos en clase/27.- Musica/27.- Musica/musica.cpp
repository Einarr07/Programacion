#include <iostream>
#include <string>
using namespace std;
#include <fstream>
#include <iomanip>
#include "musica.h"

int menu() {
    int op;
    do {
        cout << endl << "*****Menú de opciones del Programa*****" << endl;
        cout << "1 - Listado de canciones" << endl;
        cout << "2 - Agregar canción en la play list" << endl;
        cout << "3 - Buscar canciones por artista" << endl;
        cout << "0 - Salir" << endl;
        cout << "Opcion: ";
        cin >> op;
    } while ((op < 0) || (op > 3));

    return op;
}
void cargar(tLista& lista, bool& ok) {
    tCancion cancion;
    ifstream archivo;
    char aux;
    lista.contador = 0; // Inicializamos la lista
    archivo.open("musica.txt");
    if (!archivo.is_open()) {
        ok = false;
    }
    else {
        ok = true;
        archivo >> cancion.numero; // Leemos el primer nuumero
        while ((cancion.numero != -1) && (lista.contador < MAX)) {
            archivo.get(aux);
            getline(archivo, cancion.titulo);
            getline(archivo, cancion.artista);
            archivo >> cancion.genero;
            archivo >> cancion.anio;
            lista.elementos[lista.contador] = cancion; // Al final
            lista.contador++;
            archivo >> cancion.numero; // Siguiente numero
        } // Si hay más de MAX canciones, ignoramos el resto
        archivo.close();
    }
}

void guardar(const tLista& lista) {
    ofstream archivo;
    archivo.open("musica.txt");
    for (int i = 0; i < lista.contador; i++) {
        archivo << lista.elementos[i].numero << endl;
        archivo << lista.elementos[i].titulo << endl;
        archivo << lista.elementos[i].artista << endl;
        archivo << lista.elementos[i].genero << endl;
        archivo << lista.elementos[i].anio << endl;
    }
    archivo << -1 << endl; // Centinela final
    archivo.close();
}

void leerCancion(tCancion& cancion) {
    cin.ignore();
    cout << "Titulo de la canción: ";
    getline(cin, cancion.titulo);
    cout << "Artista: ";
    getline(cin, cancion.artista);
    cout << "Género: ";
    cin >> cancion.genero;
    cout << "año de publicación: ";
    cin >> cancion.anio;
    cin.ignore(); // Descartamos cualquier entrada pendiente
}

void insertarCancion(tLista& lista, tCancion cancion, bool& ok) {
    ok = true;
    if (lista.contador == MAX) {
        ok = false;
    }
    else {
        cancion.numero = lista.contador + 1;
        lista.elementos[lista.contador] = cancion; // Insertamos al final
        lista.contador++;
    }
}

void mostrarCancion(tCancion cancion) {
    cout << setw(2) << left << cancion.numero << ". ";
    cout << setw(20) << left << cancion.titulo;
    cout << setw(20) << left << cancion.artista;
    cout << setw(10) << left << cancion.genero << " ";
    cout << setw(6) << right << cancion.anio << endl;
}

void listado(const tLista& lista) {
    for (int i = 0; i < lista.contador; i++) {
        mostrarCancion(lista.elementos[i]);
    }
}

void buscarArtista(const tLista lista, string artista, bool& ok) {
    ok = false;
    for (int i = 0; i < lista.contador; i++) {
        if (lista.elementos[i].artista == artista) {
            ok = true;
            mostrarCancion(lista.elementos[i]);
        }
    }
}