#include "tree.h"

int str = 0;

Tree::Tree()
{
	key = ' ';
	p = NULL;
	left = NULL;
	right = NULL;
}

void Tree::Insert(char element, Tree *dad, Tree *l, Tree *r)
{
	key = element;
	p = dad;
	left = l;
	right = r;
}

Tree *Tree::Enter()
{
	//int i=0;
	unsigned short i = 0;
	string v = "987654+*32--+1+*+";
	Tree *curr, *currx, *prev1, *prev2, *next, *root;
	root = this;
	
	while ((v[i] != '+') && (v[i] != '-') && (v[i] != '*') && (i < v.length()))
	{
	    i++;
	}

	key = v[i];
	left = new Tree;
	left->Insert(v[i-2], this, NULL, NULL);
	right = new Tree;
	right->Insert(v[i-1], this, NULL, NULL);
	v.erase((i-2), 3);
	v.insert((i-2), "x");
	curr = this;

	while(i <= v.length())
	{
		i = 0;

		while ((v[i] != '+') && (v[i] != '-') && (v[i] != '*') && (i < v.length()))
			i++;
		
		next = new Tree;
		next->Insert(v[i], NULL, NULL, NULL);

		if((v[i-1] != 'x') && (v[i-1] != 'y'))
		{
			prev2 = new Tree;
			prev2->Insert(v[i-1], next, NULL, NULL);
		}
		else if(v[i-1] == 'x')
			prev2 = curr;
		else
			prev2 = currx;

		if((v[i-2] != 'x') && (v[i-2] != 'y'))
		{
			prev1 = new Tree;
			prev1->Insert(v[i-2], next, NULL, NULL);
		}
		else if(v[i-2] == 'x')
			prev1 = curr;
		else
			prev1 = currx;
		
		next->left = prev1;
		next->right = prev2;

		v.erase((i-2), 3);
		if(v.find('x') > v.length())
    		v.insert((i-2), "x");
		else 
			v.insert((i-2), "y");

		if(v.find('y') < v.length())
			currx = next;
		else
			curr = next;

		root = next;
	}
	return root;
}

void Tree::Show(Tree *root, int i)
{
	if (root == NULL)
		return;
	str++;
	int j = i;

	cout << "(" << root->key << ")" << endl;

	if(root->right != NULL)
	{
		while(j > 0)
			{
				if(j%3 == 0) 
					cout << "|";

				cout << " ";	
				j--;
			}
		cout << "|--";
		Show(root->right, (i+3));
	} 
	j = i;
	
	if (root->left != NULL)
	{
		while (j > 0)
			{
				if(j%3 == 0) cout << "|";
				cout << " ";	
				j--;
			}
		cout << "|--";
		Show(root->left, (i + 3));
	}
}

void Tree::Prefix(Tree *root)
{
	if(root == NULL)
		return;
	cout << root->key;

	Prefix(root->left);
	Prefix(root->right);
}

void Tree::Infix(Tree *root)
{
	if(root == NULL)
		return;
	Infix(root->left);
	cout << root->key;
	Infix(root->right);
}

void Tree::Postfix(Tree *root)
{
	if(root == NULL)
		return;
	Postfix(root->left);
	Postfix(root->right);
	cout << root->key;
}

