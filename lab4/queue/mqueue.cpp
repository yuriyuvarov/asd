#include <iostream>

using namespace std;

#define size 20

class Queue
{
    short head;
    short tail;
    float queue[size];

public:
    Queue();
    void Enq(float d);
    float Deq();
    void Print();             
};

Queue::Queue()
{
    tail = 1;
    head = 0;
}

void Queue::Enq(float d)
{
    if(head == tail)
    {
        cout << "\nqueue underflow.\n";
        return;
    }

    if (tail == size)
        tail = 0;
    queue[++tail] = d;
}
   
float Queue::Deq()
{
    return queue[++head];
}
    
void Queue::Print()
{
    int u = head;

    if (tail > head) {
    while (u < tail)
        cout << queue[++u] << ' ';
    }

    else {
    //cout << endl << head << tail << endl;
    do {
        if (u==size) u=0;
        cout << queue[++u] << ' ';
        }
    while (u!=tail);
    }

    cout << endl;
}

int main()
{
    Queue a;
    
    for (int i=1; i<size; i++)
        a.Enq(i);
   
    a.Deq();
    a.Print();
    //a.Enq(29);
    //a.Enq(28);
    a.Deq();
    a.Deq();
    a.Deq();
    a.Deq();
    a.Deq();
    a.Deq();
    a.Deq();
    a.Deq();
    a.Print();
    a.Enq(30);
    a.Enq(31);
    a.Enq(32);
    a.Enq(33);
    a.Enq(34);
    a.Enq(35);
    a.Enq(36);
    a.Print();

    return 0;
}
