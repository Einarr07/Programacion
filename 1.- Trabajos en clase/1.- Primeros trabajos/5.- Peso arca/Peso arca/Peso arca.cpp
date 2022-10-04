// Peso arca.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
using namespace std;

int main()
{
    //
    int numero_de_perros, numero_de_gatos, numero_de_conejos, numero_de_iguanas, numero_de_cocodrilos, numero_de_aves;
    double peso_perros, peso_gatos, peso_conejos, peso_iguanas, peso_cocodrilos, peso_aves;
    double perros, gatos, conejos, iguanas, cocodrilos, aves, total_arca;
    //
    cout << "---Calcular el peso del arca---" << endl;
    cout << "Por favor indique el numero de animales de cada especie que se subiran al arca" << endl;
    cout << endl;
    cout << "Numero de perros: ";
    cin >> numero_de_perros;
    cout << "Numero de gatos: ";
    cin >> numero_de_gatos;
    cout << "Numero de conejos: ";
    cin >> numero_de_conejos;
    cout << "Numero de iguanas: ";
    cin >> numero_de_iguanas;
    cout << "Numero de cocodrilos: ";
    cin >> numero_de_cocodrilos;
    cout << "Numero de aves: ";
    cin >> numero_de_aves;

    cout << endl;

    cout << "Ingrese el peso de cada animal en Kilos" << endl;
    cout << "Peso perros: ";
    cin >> peso_perros;
    cout << "Peso gatos: ";
    cin >> peso_gatos;
    cout << "Peso conejos: ";
    cin >> peso_conejos;
    cout << "Peso iguanas: ";
    cin >> peso_iguanas;
    cout << "Peso cocodrilos: ";
    cin >> peso_cocodrilos;
    cout << "Peso aves: ";
    cin >> peso_aves;
    //
    perros = numero_de_perros * peso_perros;
    gatos = numero_de_gatos * peso_gatos;
    conejos = numero_de_conejos * peso_conejos;
    iguanas = numero_de_iguanas * peso_conejos;
    cocodrilos = numero_de_cocodrilos * peso_cocodrilos;
    aves = numero_de_aves * peso_aves;
    total_arca = (perros + gatos + conejos + iguanas + cocodrilos + aves);
    //
    cout << endl;
    cout << "El peso total del arca es: " << total_arca << "KG" << endl;

    return 0;
}

