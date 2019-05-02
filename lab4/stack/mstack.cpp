#include <iostream>

using namespace std;

#define size 20

class Stack
{
    short top1;
    short top2;
    float* stack;

public:
    Stack();//:top1(NULL) {stack[size];}
    ~Stack();// {delete [] stack;}
    void Push(float d, bool a);
    float Pop(bool a);
    bool isEmpty();
    void Print();             
};

Stack::Stack()
{
    top1=0;
    top2=size;
    stack = new float[size];
}

Stack::~Stack()
{
    delete [] stack;
}

void Stack::Push(float d, bool a)
{
    switch (a) {
        case 0: if (top1 < top2)
                stack[top1++] = d;
                break;
        case 1: if (top1 < top2)
                stack[top2--] = d;
                break;
    }
    
    cout << " " << top1 << top2 << " ";

    if (top1==top2) cout << "\nstack underflow.\n";
}
   
float Stack::Pop(bool a)
{
    if (isEmpty())
        return -1;
    if (!a) return stack[--top1];
    
    else return stack[++top2];
}
    
bool Stack::isEmpty()
{
    if (top1==0 && top2==size) return true;
    else return false;
}
      
void Stack::Print()
{
    int u=top1;
    cout << "0: ";
    while (u)
        cout << stack[--u] << ' ';

    u=top2;
    cout << "\n1: ";
    while (u<size)
        cout << stack[++u] << ' ';
    
    cout << endl;
}

int main()
{
    Stack a;
    
    for (int i=0; i<size; i++)
        a.Push(i,i%2);
   
    a.Print();
    a.Pop(0);
    a.Pop(1);
    a.Print();

    return 0;
}
