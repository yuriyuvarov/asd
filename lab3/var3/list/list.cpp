#include <iostream>

using namespace std;

struct node
{
    node *next;
    char val;
};

struct text
{
    node *head;
};

void enter(text);
void del(text, char);
void print(text);
int word(text);

int main()
{	
    text T;
    char lit;
    T.head = new node;
    T.head->val=0;
    cout << "Enter text: ";
    enter(T);
    
    if (word(T) < 3) {
        cout << "\ntext has less than three words.\n";
        return 0;
    }

    cout << "\nYou received the text:\n";

    del(T, 'a');
    del(T, 'o');
    print(T);

    cout << endl;
    return 0;
}

void del(text T, char a) {
    node *x = T.head;
    while (x->next) {
    	if (x->next->val == a) {
            node *buf=x->next;
            x->next=x->next->next;
            delete buf;
        }
        else x=x->next;
    }
}

void print(text T) {
    node *x=T.head;
    while (x->val != '.') {
        if (x->val == ' ' && x->next->val != ' ') {
            if ( (x->next->val) != (T.head->val) ) {
	            node* y=x->next;
                while(y->val != ' ' && y->val != '.') {
                    cout << y->val;
                    y=y->next;
                }
                cout << ' ';
            }
        }

        x=x->next;
    }
}

void enter(text T) {
    node *x = new node;
    char k;
    cin >> k;
    T.head->val = k;
    T.head->next = x;
    cin >> noskipws >> x->val;
    while (x->val!='.') {
	x->next = new node;
	x=x->next;
	cin >> noskipws >> x->val;
    }
    x->next=NULL;
}

int word(text T) {
    node *x = T.head;
    int h = 1;
    while (x->val != '.') {
        if (x->val == ' ' && x->next->val != ' ') {
            h++;
        }
    x=x->next;
    }
    return h;
}

