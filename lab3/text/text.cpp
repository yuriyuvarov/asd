#include <iostream>

using namespace std;

int main()
{
    int size = 100;

    char *text = new char [size];
    //char text[size];

    for (int i=0; i<size; i++)
        text[i] = 0;

    cout << "enter text: ";
    cin.getline(text, size);

    if (!text[0])
    {
	cout << "\ntext is empty.\n";
	delete []text;
	return 0;
    }

    for (int i=0; text[i]; i++) {
	    if (text[i] == ' ' && text[i+1] != ' ' || i == 0) {
            int j;
            if (i==0)
                j=i;
            else j=i+1;

            int num=0;
            for (int u=j; text[u]!=' ' && text[u]; u++)
                num++;

            if (num%2) {
                int n = j;
                while (text[n+1] != ' ' && text[n+1]) {
                    if (n==j || text[n+1] == ' ')
                        for (int j=n; j<size; j++)
                            text[j]=text[j+1];
                    cout << text[n++];
                }
                cout << "  ";
            }
        }
    }

    delete []text;
    cout << endl;
    return 0;
}
