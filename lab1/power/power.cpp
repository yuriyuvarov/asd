#include <iostream>
using namespace std;

double power(double n, int p);

int main()
{
	double a;
	int b;
	cout << "enter a number: ";
	cin >> a;
	cout << endl << "enter the power: ";
	cin >> b;
	cout << endl << a << "^" << b << " = " << power(a, b);
	
	return 0;
}

double power(double n, int p)
{
	if (p == 0)
	    return 1;
	if ((n!=0) && (p>0))
	{
		double d  = n * power(n, p-1);
		return d;
	}
}

