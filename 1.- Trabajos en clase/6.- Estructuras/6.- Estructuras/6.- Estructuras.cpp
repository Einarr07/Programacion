#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double x, y, f;

	cout << "Ingrese el valor de x: ";
	cin >> x;
	cout << "Ingrese el valor de y: ";
	cin >> y;

	f = (2 * pow(x, 5)) + (sqrt(pow(x, 3) / pow(y, 2))) / abs(x * y) - cos(y);

	cout << "El resultado es: " << f;

	return 0;
}