#include <iostream>

using namespace std;

struct Node
{
    float d;
    Node *next;
    Node *prev;
};
 
class Queue
{
    Node *tail;
    Node *head;

public:
    Queue();
    ~Queue();
    void Enq(float d);
    float Deq();
    bool isEmpty();
    void Print();
};

Queue::Queue()
{
    head=tail=NULL;
}

Queue::~Queue()
{
    while (head)
    {
        Node *pv = head;
        head = head->next;
        delete pv;
    }
}
 
void Queue::Enq(float d)
{
    Node *pv = new Node;
    pv->d = d;
    pv->next = NULL;
    pv->prev = tail;
    if (!head) head=pv;
    if (!tail) { tail = pv; tail->next=NULL;}
    else tail->next=pv;
    tail = pv;
}
   
float Queue::Deq()
{
    if (isEmpty())
        return -1;
    
    float temp = tail->d;
    Node *pv = head;
    head = head->next;
    delete pv;
    return temp;
}
    
bool Queue::isEmpty()
{
    return tail ? false : true;
}
      
void Queue::Print()
{
    Node* u=head;
    while (u)
    {
        cout << u->d << ' ';
        u=u->next;
    }
    delete u;

    cout << endl;
}

int main()
{
    Queue a;
    for (int i = 0; i < 20; i++)
        a.Enq(i);

    a.Print();
    a.Deq();
    a.Deq();
    a.Deq();
    a.Enq(40);
    a.Enq(50);
    a.Deq();
    a.Print();

    cout << endl;
    return 0;
}
