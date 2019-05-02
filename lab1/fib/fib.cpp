#include <iostream>

using namespace std;

int fib (int n);

int main()
{
	int n, a;
	cout << "enter num: ";
	cin >> n;
	
	for (int i = 1; i < n; i++)
	cout << "\nfib(" << i << ") = " << fib(i);
	//cout << "a = " << a;
	return 0;
}

int fib (int n)
{
	//cout << "\nprocessing fib " << n;
	if (n <= 2)
	{
	//cout << ".\nreturn 1";
	return 1;
	}

	else
	{
	//cout<<"\ncall fib "<<n-2<<" and fib "<<n-1;
	return ( fib(n-2) + fib(n-1) );
	}
}


