/*
Escribir un programa que imprima lo siguiente utilizando bucles while anidados:

12345678910
123456789
12346678
1234567
123456
12345
1234
123
12
1
*/

#include <iostream>
using namespace std;

int main()
{
	int a = 10;
	while (a > 0) 
	{
		int b = 1;
		while (b <= a) 
		{
			cout << b;
			b++;
		}
		cout << endl;
		a--;
    }
	return 0;
}

