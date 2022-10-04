#include <iostream>
#include <string>
using namespace std;
//
const int Dias = 7;
const int Umbral = 250;
typedef int t_Ventas[Dias];
void inicializa(t_Ventas ventas, string ciudad); //typedef
void recorre(const t_Ventas recorre, string ciudad);
void ventas_Totales(const t_Ventas ventas, string ciudad);
int busqueda(const t_Ventas ventas);
//void inicializa(int ventas[Dias]);


//
int main()
{
    //
    t_Ventas ventas_quito = { 200,280,150,125,152,125,180 };
    t_Ventas ventas_guayaquil = { 0 };
    int ventas_manta[Dias] = { 5 };
    int indice;
    //
    cout << "Las ventas que se realizaron el dia miercoles en Quito son: " << ventas_quito[2] << endl;
    cout << "Las ventas que se realizaron el dia miercoles en Guayaquil son: " << ventas_guayaquil[2] << endl;
    cout << "Las ventas que se realizaron el dia miercoles en Manta son: " << ventas_manta[0] << endl;

    cout << "Recorido for:" << endl;
    //Buscar
    indice = busqueda(ventas_quito);
    if (indice == -1)
    {
        cout << "No existen ventas mayores a 250" << endl;
    }
    else
    {
        cout << "Las ventas del dia " << indice + 1 << " son mayores a 250 " << "El valor de vente ese dia es: " << ventas_quito[indice] << endl;
    }
    //UIO
    ventas_Totales(ventas_quito, "Quito");
    cout << endl;
    //GYE
    inicializa(ventas_guayaquil, "Guayaquil");
    recorre(ventas_guayaquil, "Guayaquil");
    ventas_Totales(ventas_guayaquil, "Guayaquil");
    cout << endl;
    //Manta
    inicializa(ventas_manta, "Manta");
    recorre(ventas_manta, "Manta");
    ventas_Totales(ventas_manta, "Manta");
    cout << endl;


    /*
    //UIO
    for (int i = 0; i < Dias; i++)
    {
        cout << "Las ventas que se realizaron en el dia " << i + 1 << " en Quito son: " << ventas_quito[i] << endl;
    }

    //GYE
    for (int i = 0; i < Dias; i++)
    {
        cout << "Las ventas que se realizaron en el dia " << i + 1 << " : ";
        cin >> ventas_guayaquil[i];
    }

    cout << "Imprime las ventas Guayaqul" << endl;
    //Imprime los valores de GYE
    for (int i = 0; i < Dias; i++)
    {
        cout << "Las ventas que se realizaron en el dia " << i + 1 << " en Guayaqil son: " << ventas_guayaquil[i] << endl;
        cout << endl;
    }
    //
    inicializa(ventas_guayaquil);
    for (int i = 0; i < Dias; i++)
    {
        cout << "Las ventas que se realizaron en el dia " << i + 1 << " en Guayaquil son: " << ventas_quito[i] << endl;

    }
    */


    return 0;
}
//Funcion para inicialiazar el arreglo t_Ventas
void inicializa(t_Ventas ventas, string ciudad)
{
    for (int i = 0; i < Dias; i++)
    {
        cout << " Ingrese las ventas de " << ciudad << " dia " << i + 1 << ": ";
        cin >> ventas[i];
    }
}
//Funcion recorre
void recorre(const t_Ventas ventas, string ciudad)
{
    for (int i = 0; i < Dias; i++)
    {
        cout << "Ventas en " << ciudad << " dia " << i + 1 << ": " << ventas[i] << endl;
    }
}
//Totales
void ventas_Totales(const t_Ventas ventas, string ciudad)
{
    int suma = 0;
    for (int i = 0; i < Dias; i++)
    {
        suma = suma + ventas[i];
    }
    cout << "Las suma de las ventas en " << ciudad << " es " << suma << endl;
}
//Busqueda
int busqueda(const t_Ventas ventas)
{
    bool encontrado = false;
    int indice = 0;
    while (indice < Dias && !encontrado)
    {
        if (ventas[indice] > Umbral)
        {
            encontrado = true;
        }
        else
        {
            indice++;
        }
    }
    if (!encontrado)
    {
        indice = -1;
    }
    return indice;
}