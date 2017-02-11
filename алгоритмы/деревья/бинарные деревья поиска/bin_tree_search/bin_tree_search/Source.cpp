#include <iostream>
using namespace std;

#define Vtype int // это еще надо сделать:D

struct Node
{
	Node *left;
	Node *right;
	
	Vtype key;
	Node();
	Node(int Nkey) { this->key = Nkey; this->left = NULL; this->right = NULL; }
};

class Bin_tree
{
private:

	Node *root;


public:

	Bin_tree()
	{
		root = NULL;
	}

	Node* sys_insert(Vtype key, Node *p)
	{
		if (p == NULL)
		{
			Node *q = new Node(key);
			if (root == NULL)
			{
				root = q;
			}
			return q;
		}
		if (key > p->key)
		{
			p->right = sys_insert(key, p->right);
			return p;
		}
		else if (key < p->key)
		{
			p->left = sys_insert(key, p->left);
			return p;
		}
		else
		{
			return p;
		}
	}

	Node* insert(int value)
	{
		return sys_insert(value, root);
	}

	Node* find(int key)
	{
		Node *current = root;
		while (current != NULL)
		{
			if (current->key = key)
				return current;
			current = current->key > key ? current->right : current->left;
		}
		return NULL;
	}

	Node* sys_delete_by_key(Vtype key, Node* p)
	{
		if (p == NULL)
			return NULL;
		if (p->key == key)
		{
			if (p->left == NULL && p->right == NULL)
			{
				delete(p);
				return NULL;
			}
			else if (p->left == NULL)
			{
				Node *q = p->right;
				delete(p);
				return q;
			}
			else if (p->right == NULL)
			{
				Node *q = p->left;
				delete(p);
				return q;
			}
			else
			{
				Node *r = p->right;
				Node *r2 = p->right;
				while (r->left)
				{
					r = r->left;
				}
				r->left = p->left;
				delete(p);
				return r2;
			}
		}

		if (p->key > key)
		{
			p->right = sys_delete_by_key(key, p->right);
		}
		else
		{
			p->left = sys_delete_by_key(key, p->left);
		}
		return p;

	}


	Node* del(Vtype key)
	{
		root = sys_delete_by_key(key, root);
	}



};




int main()
{

	Bin_tree *a = new Bin_tree();

	a->insert(10);
	for (int i = 0; i < 10; i++)
	{
		a->insert(i*i);
	}
	for (int i = 0; i < 10; i++)
	{
		a->find(i*i);
	}


}