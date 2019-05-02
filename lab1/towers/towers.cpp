#include <iostream>

using namespace std;

void towers(int quantity, int num[], int *count, int from = 1, int to = 3, int buf_peg = 2)
{
	if (quantity != 0)
	{
		towers(quantity - 1, num, count, from, buf_peg, to);
		cout << from << " -> " << to;
		num[from-1]--;
		num[to-1]++;
		cout << "	| ";
		for(int i=0; i<3; i++)
			cout << num[i] << " | ";
		cout << "		 # " << ++(*count) << endl;
		towers(quantity - 1, num, count,  buf_peg, to, from);
	}
}

int main()
{
	int plate_quantity;
	cout << "Enter number of disks: ";
	cin  >> plate_quantity;
	int *count = new int(0);
	int num[] = {plate_quantity, 0, 0};
	towers(plate_quantity, num, count);
	return 0;
}

