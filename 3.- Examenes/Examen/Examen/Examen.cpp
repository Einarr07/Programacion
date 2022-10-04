#include <iostream>
#include <iomanip>
using namespace std;
//función principal
int menu();
void ejercicio2();
int sumaPrimos(int min, int max);
void ejercicio3();
int seleccionProducto();

int main()
{
    cout << "***Bienvenido al programa de la prueba de la segunda prueba del primer bimestre***" << endl;
    int opcion = menu();
    while (opcion != 3) {
        switch (opcion)
        {
        case 1: {
            ejercicio2();
            break;
        }
        case 2: {
            ejercicio3();
            break;
        }
        }
        opcion = menu();
    }
    return 0;
}

int menu() {
    int opcion = 0;
    while (opcion < 1 || opcion > 3) {
        cout << "Seleccione el programa que desea ejecutar" << endl;
        cout << "1. Ejercicio 2" << endl;
        cout << "2. Ejercicio 3" << endl;
        cout << "3. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;
        if (opcion < 1 || opcion > 3) {
            cout << "Opcion no valida" << endl;
        }
    }
    return opcion;
}

void ejercicio2() {
    int min, max;
    cout << "Ejercicio 2: Se le solicitara ingresar dos numeros el primero" <<
        "menor que el segundo para calcular la suma de los numeros primos entre ellos" << endl;
    cout << "Ingrese el primero numero (limite menor): ";
    cin >> min;
    cout << "Ingrese el segundo numero (limite mayor): ";
    cin >> max;
    cout << "La suma total de los numeros primos entre " << min << "y " << max
        << " es: " << sumaPrimos(min, max) << endl;
}

int sumaPrimos(int min, int max) {
    int suma = 0;
    bool esPrimo = true;
    if (max - min <= 1) {
        suma = 0;
    }
    else {
        min++;//al considerar los numeros "entre" no se debería considerar el límite inferior
        while (min < max) {
            esPrimo = true;
            for (int i = 2; i <= min / 2; i++) {
                if (min % i == 0) {
                    esPrimo = false;
                    break;
                }
            }
            if (esPrimo == true) {
                suma += min;
            }
            min++;
        }
    }
    return suma;
}

void ejercicio3() {
    const float IVA = 0.12;
    //p--> precio, c-->cantidad, v-->valor de venta, desc--> descuento
    double pZapAdidas = 160, pZapNike = 160, pCamFEF = 80, pCalFEF = 145, pGorraNike = 25;
    double descNike = 0.2, descFEF = 0.5;
    double cZapAdidas = 0, cZapNike = 0, cCamFEF = 0, cCalFEF = 0, cGorraNike = 0;
    double vZapAdidas = 0, vZapNike = 0, vCamFEF = 0, vCalFEF = 0, vGorraNike = 0;
    float descAplicadoNike = 0, descAplicadoFEF = 0;
    float total_sin_descuentos = 0, total_con_descAplicados = 0;
    float descTotal = 0;
    float ventaTotal = 0;
    int seleccion = seleccionProducto();
    int cantidad;
    while (seleccion != 0) {
        cout << "Ingrese la cantidad:";
        cin >> cantidad;
        switch (seleccion)
        {
        case 1: {
            cZapAdidas = cZapAdidas + cantidad;
            break;
        }
        case 2: {
            cZapNike = cZapNike + cantidad;
            break;
        }
        case 3: {
            cCamFEF = cCamFEF + cantidad;
            break;
        }
        case 4: {
            cCalFEF = cCalFEF + cantidad;
            break;
        }
        case 5: {
            cGorraNike = cGorraNike + cantidad;
            break;
        }
        }
        seleccion = seleccionProducto();
    }
    vZapAdidas = cZapAdidas * pZapAdidas;
    vZapNike = cZapNike * pZapNike;
    vCamFEF = cCamFEF * pCamFEF;
    vCalFEF = cCalFEF * pCalFEF;
    vGorraNike = cGorraNike * pGorraNike;
    total_sin_descuentos = vZapAdidas + vZapNike + vCamFEF + vCalFEF + vGorraNike;
    if (total_sin_descuentos == 0) {
        cout << "En esta ocasión no ha comprado productos, vuelva pronto" << endl;
    }
    else {
        cout << "Ha finalizado su compra." << endl;
        cout << "**************************************" << endl;
        cout << "Factura de Compra:" << endl;
        cout << setw(22) << left << "Producto" << setw(10) << "Cantidad" << setw(10) << "Valor" << endl;
        if (cZapAdidas != 0) {
            cout << setw(22) << "Zapatillas Adidas" << setw(10) << cZapAdidas << setw(10) << vZapAdidas << endl;
        }
        if (cZapNike != 0) {
            cout << setw(22) << left << "Zapatillas Nike" << setw(10) << cZapNike << setw(10) << vZapNike << endl;
        }
        if (cCamFEF != 0) {
            cout << setw(22) << left << "Camiseta FEF" << setw(10) << cCamFEF << setw(10) << vCamFEF << endl;
        }
        if (cCalFEF != 0) {
            cout << setw(22) << left << "Calentador FEF" << setw(10) << cCalFEF << setw(10) << vCalFEF << endl;
        }
        if (cGorraNike != 0) {
            cout << setw(22) << left << "Gorra Nike" << setw(10) << cGorraNike << setw(10) << vGorraNike << endl;
        }
        cout << setw(32) << left << "Total sin descuentos: " << setw(8) << total_sin_descuentos << endl;
        //Descuentos
        if (cZapNike != 0 || cGorraNike != 0) {
            descAplicadoNike = (vZapNike + vGorraNike) * descNike;
            cout << setw(32) << left << "Descuento en productos Nike: " << setw(10) << descAplicadoNike << endl;
        }
        if (cCamFEF != 0 || cCalFEF != 0) {
            descAplicadoFEF = (vCamFEF + vCalFEF) * descFEF;
            cout << setw(32) << left << "Descuento en productos FEF: " << setw(10) << descAplicadoFEF << endl;
        }
        descTotal = descAplicadoNike + descAplicadoFEF;
        //Totales
        total_con_descAplicados = total_sin_descuentos - descTotal;
        cout << setw(32) << left << "Total con descuentos: " << setw(10) << total_con_descAplicados << endl;
        cout << setw(32) << left << "IVA (12%): " << setw(10) << IVA * total_con_descAplicados << endl;
        ventaTotal = total_con_descAplicados + (IVA * total_con_descAplicados);
        cout << setw(32) << left << "Total de la venta: " << setw(10) << ventaTotal << endl;
        cout << "**************************************" << endl;
    }
}

int seleccionProducto() {
    int seleccion = -1;
    while (seleccion < 0 || seleccion > 5) {
        cout << "Bienvenido a Marathon Sports" << endl;
        cout << "Seleccione uno de los siguientes productos o Finalice la compra." << endl;
        cout << "1. Zapatilla Adidas 1, $160.00" << endl;
        cout << "2. Zapatilla Nike, $180.00" << endl;
        cout << "3. Camiseta FEF, $80.00" << endl;
        cout << "4. Calentador FEF, $145.00 " << endl;
        cout << "5. Gorra Nike, $25.00" << endl;
        cout << "0. Finalizar la compra" << endl;
        cout << "Opcion: ";
        cin >> seleccion;
        if (seleccion < 0 || seleccion > 5) {
            cout << "Selección incorrecta" << endl;
        }
    }
    return seleccion;
}