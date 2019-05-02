#include <iostream>
#include <string>

using namespace std;

class Tree
{
public:
	Tree();
	Tree* Enter();
	void Insert(char, Tree*, Tree*, Tree*);
	void Show(Tree*, int);
	void Postfix(Tree*);
	void Infix(Tree*);
	void Prefix(Tree*);
	
private:
	char key;
	Tree *left, *right, *p;
};
