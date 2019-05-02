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
void print(text);
void del(node*);

int main()
{	
    text T;
    char lit;
    T.head = new node;
    T.head->val=0;
    cout << "Enter text: ";
    enter(T);
 
    cout << "\nYou received the text:\n";

    //print(T);
    
    del(T.head);

    cout << endl;
    return 0;
}

void print(text T) {
    node* x = T.head;
    while (x->val != '.')
    {
        if (x->val == ' ' && x->next->val != ' ' || x == T.head)
        {
            node *j;
            if (x == T.head)
                j = T.head;
            else
                j = x->next;

            int num = 0;
            for (node *u = j; u->val != ' ' && u->val != '.'; u=u->next)
                num++;
            
            if (num%2)
            {
	            node *y = j->next;
                while(y->next->val != ' ' && y->next->val != '.') {
                    if (y->val == j->val || y->next->val == ' ')
                        y = y->next;
                    cout << y->val;
                    y = y->next;
                }
                cout << ' ';
            }
        }

        x = x->next;
    }
}

void enter(text T) {
    node* x = new node;
    char k;
    cin >> k;
    T.head->val=k;
    T.head->next=x;
    cin >> noskipws >> x->val;
    while (x->val!='.')
    {
	x->next = new node;
	x=x->next;
	cin >> noskipws >> x->val;
    }
    x->next=NULL;
}

void del(node* a)
{
    node *x = a;
    
    cout << endl << x->next << endl;

    while (x->next)
    {
        cout << x->val;
        node *tmp;
        tmp = x;
        x = x->next;
        delete tmp;
    }
    cout << endl << x->next;
    delete x;
}

