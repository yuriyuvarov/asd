#include <iostream>

using namespace std;

long long fnum( long long num )
{
	if ( num < 10 )
	    return 1;
	else
	    return 1 + fnum( num/10 );
}

int main()
{
	cout << "enter num: ";
	long long num;
	cin >> num;

	cout << fnum(num);

	cout << endl;
	return 0;
}
