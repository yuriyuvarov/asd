#include <iostream>
#include <time.h>
//#include <fstream>
#include <cstdlib>
#define SIZE 100000
using namespace std;

int incr(int inc[]);
void shell(int a[], int *repl, int *comp);

int main()
{
	int *repl = new int(0);
	int *comp = new int(1);
	int mas[SIZE];
	
	for(int k=0; k<SIZE; k++)
		mas[k] = rand() % SIZE;

	double t1, t2;

	//ofstream out("sort.txt");
	cout << "Array: " << endl;
	
	for(int i=0; i<SIZE; i++)
		cout << mas[i] << ' ';
	cout << endl;
	t1 = clock();
	shell(mas, repl, comp);
	t2 = clock();
	cout << "Sorted array:" << endl;
	for(int i=0; i<SIZE; i++)
		cout << mas[i] << ' ';
	cout << endl << "Time of work: " << (t2-t1);//CLOCKS_PER_SEC;
	cout << endl << "The number of replacements:" << *repl;
	cout << endl << "The number of comperisons:" << *comp;
	
	return 0;
}

int increment(long inc[])
{
	int p1, p2, p3, s;
	
	p1 = p2 = p3 = 1;
	s = -1;
	do
	{
		if (++s % 2)
		{
			inc[s] = 8*p1 - 6*p2 + 1;
		}
		else
		{
			inc[s] = 9*p1 - 9*p3 + 1;
			p2 *= 2;
			p3 *= 2;
		}
        p1 *= 2;
	}
	while(3 * inc[s] < SIZE);
	return s > 0 ? --s : 0;
}

void shell(int a[], int *repl, int *comp)
{
	long inc, i, j, seq[40];
	int s;
	s = increment(seq);
	
	while (s >= 0)
	{
	    inc = seq[s--];

	    for (i = inc; i < SIZE; i++) {
	        int temp = a[i];

    	for (j = i-inc; ( (*comp)++) && (j >= 0) && (a[j] > temp); j -= inc)
	    	a[j+inc] = a[j];
	
	    a[j+inc] = temp;
	    (*repl)++;
    	}

	}
}

