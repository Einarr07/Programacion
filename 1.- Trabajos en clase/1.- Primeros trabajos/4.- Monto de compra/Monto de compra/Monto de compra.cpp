// Monto de compra.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
using namespace std;

int main()
{
    //variables
    double huevos = 0.15, aceite = 1.10, leche = 0.90, libra_arroz = 0.60, cerveza = 1.80;
    int huevo, acei, lech, libra, cerve;
    double cerveza_impuesto, impuesto_del_5_porciento;
    double total_huevos, total_aceite, total_leche, total_libra, total_cerveza;
    double sub_total, iva, descuento, total_a_pagar;
    //presentaicon
    cout << " ---Tienda de viveres Sebastian--- " << endl;
    cout << endl;
    cout << "Le presentamos los productos para que pueda realizar su pedido" << endl;
    cout << endl;
    cout << "Productos" << endl;
    cout << "Huevos : $0.15" << endl;
    cout << "Aceite : $1.10" << endl;
    cout << "Leche : $0.90" << endl;
    cout << "Libra de arroz : $0.60" << endl;
    cout << "Cerveza : $ 1.80" << endl;
    cout << endl;
    //recoleccion de datos
    cout << "Ingrese la cantidad de huevos que desea comprar" << endl;
    cin >> huevo;
    cout << "Ingrese la cantidad de aceite que desea comprar" << endl;
    cin >> acei;
    cout << "Ingrese la cantidad de leche que desea comprar" << endl;
    cin >> lech;
    cout << "Ingrese la cantidad de libra de arroz que desea comprar" << endl;
    cin >> libra;
    cout << "Ingrese la cantidad de cerveza que desea comprar" << endl;
    cin >> cerve;
    //Operaciones
    total_huevos = huevos * huevo;
    total_aceite = aceite * acei;
    total_leche = leche * lech;
    total_libra = libra_arroz * libra;
    total_cerveza = cerveza * cerve;
    //Impuesto cerveza
    cerveza_impuesto = total_cerveza * 1.05;
    impuesto_del_5_porciento = total_cerveza * 0.05;
    //
    cout << endl;
    //
    cout << "Su compra fue realizada con exito" << endl;
    cout << " - Nº de huevos solicitados: " << huevo << endl;
    cout << " - Nº total de huevos: $" << total_huevos << endl;
    cout << " - Nº de aceites solicitados: " << acei << endl;
    cout << " - Nº total de aceites: $" << total_aceite << endl;
    cout << " - Nº de leches solicitadas: " << lech << endl;
    cout << " - Nº total de leches: $" << total_leche << endl;
    cout << " - Nº de libra de arroz solicitado: " << libra << endl;
    cout << " - Nº total de libra: $" << total_libra << endl;
    cout << " - Nº de cervezas solicitadas: " << cerve << endl;
    cout << " - El total de la cerveza sin impuesto: $" << total_cerveza << endl;
    cout << " - Impuesto de la cerveza: " << impuesto_del_5_porciento << endl;
    cout << " - Total cerveza con impuesto: " << cerveza_impuesto << endl;
    //opreaciones finales
    sub_total = total_huevos + total_aceite + total_leche + total_libra + cerveza_impuesto;
    iva = sub_total * 0.12;
    descuento = (iva + sub_total) * 0.01;
    total_a_pagar = (iva + sub_total) - descuento;
    //
    cout << endl;
    cout << "Sub total = $" << sub_total << endl;
    cout << "Iva = $" << iva << endl;
    cout << "Su descuento es de: " << descuento << endl;
    cout << "Total a pegar: " << total_a_pagar;

    return 0;
}

