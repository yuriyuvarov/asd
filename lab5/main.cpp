#include "tree.h"

int main()
{
	Tree *root;
	Tree Expr;
	root  =Expr.Enter();
	Expr.Show(root, 0);
	cout << "Prefix order:" << endl;
	Expr.Prefix(root);
	cout << endl << "Infix order: " << endl;
	Expr.Infix(root);
	cout << endl << "Postfix order: " << endl;
	Expr.Postfix(root);

	cout << endl;
	return 0;
}

