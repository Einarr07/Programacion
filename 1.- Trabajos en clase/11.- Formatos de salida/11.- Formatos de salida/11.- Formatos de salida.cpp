#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    bool fin = false;
    cout << fin << "->" << boolalpha << fin << endl;
    double d = 123.45;
    char c = 'x';
    int i = 62;
    //
    cout << d << c << i << endl;
    cout << "|" << setw(8) << d << "|" << endl;
    cout << "|" << left << setw(8) << d << "|" << endl;
    cout << "|" << setw(4) << c << "|" << endl;
    cout << "|" << right << setw(5) << i << "|" << endl;

    double e = 96;

    cout << e << " - " << showpoint << e << endl;
    cout << scientific << d << endl;
    cout << fixed << setprecision(8) << d << endl;

    return 0;
}