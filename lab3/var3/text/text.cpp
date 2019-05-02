#include <iostream>

using namespace std;

int main()
{
    int size = 100;

    char* text = new char [size];
    //char text[size];

    for (int i=0; i<size; i++) text[i]=0;

    cout << "enter text: ";
    cin.getline(text,size);

    if (!text[0]) {
	cout << "\ntext is empty.\n";
	delete []text;
	return 0;
    }

    int i = 0, h = 1;
    while (text[i++])
        if (text[i] == ' ' && text[i+1] != ' ')
            h++;

    if (h<3) {
        cout << "\ntext has less than three words.\n";
        delete []text;
        return 0;
    }

    cout << "\ntext has " << h << " words.\n";
    cout << "first word starts from " << text[0] << "\n\n";

    i = 0;
    while (text[i]) {
	    if (text[i] == ' ' && text[i+1] != ' ') {
            if (text[i+1] != text[0]) {
                int n=i+1;
                while (text[n] != ' ' && text[n]) {
                    if (text[n] == 'a' || text[n] == 'o') {
                        for (int j=n; j<size; j++)
                            text[j]=text[j+1];
                    }
                    else cout << text[n++];
                }
                cout << "  ";
            }
        }
        i++;
    }

   delete []text;
   cout << endl;
   return 0;
}

