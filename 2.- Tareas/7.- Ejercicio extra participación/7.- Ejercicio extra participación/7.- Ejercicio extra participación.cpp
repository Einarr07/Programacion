#include <iostream>
using namespace std;

int main()
{
    int numero, i, j, m;

    cout << "\t\t\t----------------------" << endl;
    cout << "\t\t\t| CUADRO CONCENTRICO |" << endl;
    cout << "\t\t\t----------------------" << endl;
    cout << "\t\tIngrese el numero deseado de cuadrado: ";
    cin >> numero;

    if (numero % 2 == 0)
    {
        numero++; //Para convertir el numero en inpar
    }
    for (i = 1; i <= numero; i++)
    {
        
        if (i <= (numero + 1) / 2)  //La primera mitad más uno de las filas
        {
            m = i;
        }
        else
        {
            m--; //Segunda mitad de las filas
        }
        for (int j = 0; j <= numero; j++) //Columnas
        {
            if (i % 2 != 0) //Filas impares
            {
                if (j >= m && j <= (numero - m)) //Contorno superior o inferior del cuadrdo
                {
                    cout << "* ";
                }
                else if (j % 2 != 0) //Dibuja los lados
                {
                    cout << "* ";
                }
                else //Dibuja los espacios
                {
                    cout << "  ";
                }
            }

            else //Para las filas pares
            {
                
                if ((j<m || j>(numero - m)) && j % 2 != 0) //Dibuja los lados
                {
                    cout << "* ";
                }
                else //Dibuja lso espacios
                {
                    cout << "  ";
                }   
            }
        }
        cout << endl;
    }
    return 0;
}