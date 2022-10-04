// Archivo.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;
int main()
{
    const int IVA = 12;
    string cedula, producto;
    int unidades;
    double precio, neto, total, iva;
    ifstream archivo;
    int contador =  0;
    char aux;

    archivo.open("Compras.txt");
    if (archivo.is_open())
    {
        archivo >> cedula;
        while (cedula != "X")
        {
            archivo >> unidades >> precio;
            //archivo.get(aux);
            archivo.ignore();
            getline(archivo, producto);
            contador++;
            neto = unidades * precio;
            iva = neto * IVA/100;
            total = neto + IVA;
            cout << "Compra " << contador << ".-" << endl;
            cout << producto << ": " << unidades << " x " << fixed << setprecision(2) 
                << precio << " = " << neto << " IVA: " << IVA << " Total: " << total << endl;
            archivo >> cedula;
        }
        archivo.close();
    }
    else
    {
        cout << "ERROR: No se ha podido abrir el archivo." << endl;
    }
    return 0;
}

