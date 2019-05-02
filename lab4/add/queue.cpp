#include <iostream>
#include <queue>

using namespace  std;

void print(queue<int> c)
{
    if(c.empty())
        cout << "Queue is empty";
    else
    {
        queue<int> T;
        T = c;
        cout << "Elements of the queue: " << endl;
        while(!T.empty())
        {
            cout << T.front() << " ";
            T.pop();
        }
    }
    cout << endl;}


int main()
{
     queue <int> q;
     int x;
     cout << "Enter size of the queue:" << endl;
     int size = 0;
     cin >> size;
     cout << "Enter elements of the queue\n";
     for (int i=0; i<size; i++)
     {
        cin >> x;
        q.push(x);
     }
     cout << "What do you want to do with queue?" << endl
     <<"0-nothing"<<endl
     <<"1-add element"<<endl
     <<"2-delete element"<<endl
     <<"3-print queue"<<endl
     <<"4-print size"<<endl;
     int n;
     cin >> n;
     while (n!=0)
     {
     if (n==1)
     {
          cout<<"Enter new element:"<<endl;
          int k;
          cin>>k;
          q.push(k);
     }
     if (n==2)
     {
        if (!q.empty())
          q.pop();
          else
            cout<<"Queue is empty"<<endl;
     if (n==3)
        print(q);
     if (n==4)
        cout<<"Size of queue is:"<<endl<<q.size()<<endl;

     cout<<"What do you want to do with queue?"<<endl
     <<"0-nothing"<<endl
     <<"1-add element"<<endl
     <<"2-delete element"<<endl
     <<"3-print queue"<<endl
     <<"4-print size"<<endl;
     cin >> n;
    }
    }
    return 0;
}

