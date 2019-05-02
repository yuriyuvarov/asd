#include <iostream>
#include <stack>
using namespace std;

void print(stack<int> c)
{
if(c.empty()) cout<<"Stack is empty";
else
{
stack<int> Temp; Temp=c;
cout<<"Elements of the stack:"<<endl;
while(!Temp.empty())
{
cout<<Temp.top()<<" ";
Temp.pop();
}
}
cout<<endl;}

int main()
{ stack <int> s;
 int x;
 cout<<"Enter size of the stack:"<<endl;
 int size=0;
 cin>>size;
 cout <<"Enter elements of the stack\n";
 for (int i=0; i<size; i++)
 {cin>>x;
 s.push(x);}
  cout<<"What do you want to do with stack?"<<endl
 <<"0-nothing"<<endl
 <<"1-add element"<<endl
 <<"2-delete element"<<endl
 <<"3-print stack"<<endl;
 int n;
 cin>>n;
 while (n!=0)
 {
 if (n==1)
 {
  cout<<"Enter new element:"<<endl;
  int k;
  cin>>k;
  s.push(k);
 }
 if (n==2) s.pop();
 if (n==3) print(s);
 cout<<"What do you want to do with stack?"<<endl
 <<"0-nothing"<<endl
 <<"1-add element"<<endl
 <<"2-delete element"<<endl
 <<"3-print stack"<<endl;
 cin>>n;
 }

return 0; }

