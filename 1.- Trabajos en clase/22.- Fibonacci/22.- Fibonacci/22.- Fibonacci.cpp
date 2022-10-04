#include <iostream>
using namespace std;

int main()
{
	int limite = 100, fibo, fibo_menos_2 = 0, fibo_menos_1 = 1;
	//
	fibo = fibo_menos_2 + fibo_menos_1;
	//
	cout << fibo_menos_1 << " ";
	while (fibo <= limite)
	{
		cout << fibo << " ";
		fibo_menos_2 = fibo_menos_1;
		fibo_menos_1 = fibo;
		fibo = fibo_menos_2 + fibo_menos_1;
	}
	cout << fibo << endl;
	return 0;
}