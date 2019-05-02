#include <iostream>

using namespace std;

int euclid(int m, int n);

int main()
{
	int a, b;
	cout << "enter the first number: ";
	cin >> a;
	cout << endl << "enter the second  number: ";
	cin >> b;
	cout << endl << "the greatest common divisor of " << a << " and " << b << " is " << euclid(a, b);
 }

int euclid (int m, int n)
{
	if (n == 0)
	    return m;
	return euclid (n, m%n);
}
