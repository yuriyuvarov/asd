#include <iostream>
#include <time.h>
//#include <fstream>
#include <cstdlib>
#define SIZE 100000

using namespace std;

void bubble(int arr[], int *repl, int *comp);

int main()
{
	int *repl = new int(0);
	int *comp = new int(0);
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
	bubble(mas, repl, comp);
	t2 = clock();
	cout << "Sorted array:" << endl;
	
	for(int i=0; i<SIZE; i++)
		cout << mas[i] << ' ';
		
	cout << endl << "Time of work: " << (t2-t1)/CLOCKS_PER_SEC;
	cout << endl << "The number of replacements:" << *repl;
	cout << endl << "The number of comperisons:" << *comp;
	
	return 0;
}

void bubble(int arr[], int* repl, int* comp)
{
	bool swapped = true;
	int j = 0;
	int tmp;
	while (swapped)
	{
		swapped = false;
		j++;
		for (int i = 0; i < SIZE - j; i++)
		{
			if ( (*comp)++ && (arr[i] > arr[i + 1]) )
			{
				tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
				swapped = true;
				(*repl)++;
			}
		}
	}
}

