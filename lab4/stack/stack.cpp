#include <iostream>
#include <string>
#include <cstdlib>
#include <stdlib.h>

using namespace std;

struct Node
{
    float d;
    Node *p;
};
 
class Stack
{
    Node *top;

public:
    Stack():top(NULL) {}
    ~Stack();
    void Push(float d);
    float Pop();
    bool isEmpty();
    void Print();
};

Stack::~Stack()
{
    while (top)
    {
        Node *pv = top;
        top = top->p;
        delete pv;
    }
}
 
void Stack::Push(float d)
{
    Node *pv = new Node;
    pv->d = d;
    pv->p = top;
    top = pv;
}
   
float Stack::Pop()
{
    if (isEmpty())
        return -1;
    
    float temp = top->d;
    Node *pv = top;
    top = top->p;
    delete pv;
    return temp;
}
    
bool Stack::isEmpty()
{
    return top ? false : true;
}
      
void Stack::Print()
{
    Node *u=top;
    while (u)
    {
        cout << u->d << ' ';
        u=u->p;
    }
    delete u;

    cout << endl;
}

float Calc(string s, Stack* a)
{
    for (int i=0; i<s.length(); i++)
    {
        cout << endl << s[i] << ":";
        //a->Print();
        //cout << endl;
        switch (s[i])
        {
            case '+': a->Push(a->Pop()+a->Pop());
//            cout <<"+";
                      break;
            case '-': a->Push(a->Pop()-a->Pop());
                      break;
            case '*': a->Push(a->Pop()*a->Pop());
                      break;
            case '/': a->Push(a->Pop()/a->Pop());
                      break;

            default: a->Push( s[i]-'0' );
                     break;
        }
        a->Print();
    }
    return a->Pop();
}

int main()
{
    Stack a;

    string s;
    //int b = 123;
    //cin >> s;
    //s=s + to_string(b);
    //cout << s;
    //cout << Calc(s, &a);
    s = "21-3*56+4/+";//example
    cout << Calc(s, &a);
   
    //s = "56*4-32-1-/";//1.
    //cout << Calc(s, &a);
    
    //s = "";//2.
    //cout << Calc(s, &a);
    
    //s = "";//3.
    //cout << Calc(s, &a);
    
    //s = "";//4.
    //cout << Calc(s, &a);

    //cout << "(((A - B) * C) + (D / (E + F))) <=> AB - C * DEF + / + "

  /*1. cout << "(А-B-С)/D-E*F <=> EF*D-CB-A-/";
    2. cout << "(A+B)*C-(D+E)/F <=> FDE+/AB+C*-";
    3. cout << "A/(B-C)+D*(E-F) <=> CB-DFE-*+A/";
    4. cout << "(A*B+C)/D-F/E <=> ";*/
    //a.Print();
    cout << endl;
    return 0;
}
