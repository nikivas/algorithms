#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#define cmp(a,b) (a > b)

//
//��� ������ ���� ����� �������, �� ������ ��� �������..
//

struct Node // ��������� ������ �������� ������
{
	string key;
	int value;
	unsigned char height;
	bool isHead;
	Node* left;
	Node* right;
	Node(string k, int value) { this->key = k; this->value = value; this->left = NULL; this->right = NULL; }
};

class AVL_Tree
{
public:
	unsigned char height(Node* p) // ��� ���� ����� ������ �� �������� ����� �� ��������� ������ � �����
	{
		return p ? p->height : 0;
	}

	int bfactor(Node* p) // ������� ������� � ������� ����������������� ������
	{
		return height(p->right) - height(p->left);
	}

	void set_HEIGHT(Node* p) // ������� � �������, ��� ��� ������ �� �(1) [��� ��, ������� ����]
	{
		unsigned char hl = height(p->left);
		unsigned char hr = height(p->right);
		p->height = (hl>hr ? hl : hr) + 1;
	}

	Node* rotateL(Node* p) // ����� ��������
	{
		Node* q = p->right;
		p->right = p->left;
		p->left = q;

		set_HEIGHT(p);
		set_HEIGHT(q);

		return p;

	}

	Node* rotateR(Node* p)// ����� ��������
	{
		Node* q = p->left;
		p->left = p->right;
		p->right = q;

		set_HEIGHT(p);
		set_HEIGHT(q);

		return p;

	}

	Node* balance(Node* p) // ����� ����� - ��� �� �������, �� �� � ����� �������� � �����
	{

		set_HEIGHT(p);

		

		if (bfactor(p) >= 2) // �������� �����
		{
			if (bfactor(p->right) < 0)
			{
				rotateR(p->right);
			}
			return p;
		}
		if (bfactor(p) <= -2)
		{
			if (bfactor(p->left) > 0) // ��� ����� ��� ������ ��� ��� ������ ������� - ������� ����� � �� ���� � ������ � �� ������
			{
				rotateL(p->left); // � ������� ������ � �� �������
			}
			return p;
		}
		else // ���� ������ �� �����
			return p;
	}

	Node* sys_insert(string key, int value, Node* p) //�������, ��������� ���������
	{
		if (p == NULL)
		{	
			return new Node(key, value);
		}
		else if (p->key == key) //���� �� ��� �������� - ������ �� ������
			return p;
		else if (key < p->key)
			return p->left = sys_insert(key, value, p->left); // ����� ���������� � ���������
		else
			return p->right = sys_insert(key, value, p->right);// ����� ���������� � ���������

	}

	Node* head;
	AVL_Tree()
	{
		head = NULL; // �� ��� ���� ������� �� ����� , �� ��� ����� ������ ��� ����������
	}

	

	Node* insert(string key, int value) // �������-�������, ����� �� �������� � ����������� �� ������� ��� ������
	{
		if (head == NULL)
		{
			head = new Node(key, value);
			head->isHead = false;
			head->isHead = true;
			return head;
		}
		return sys_insert(key, value, head);
	}

	int get_Value_By_Key(string key) // ����� �� ����� (�-� �������)
	{
		Node* f = sys_get_Value_By_Key(key, head);
		if (f == NULL)
			return NULL;
		else
			return f->value;
	}

	Node* sys_get_Value_By_Key(string key, Node* p) // ��������������� ����� - ������ ���������� ���� �� ������, ����� ���������� NIL
	{
		if (p == NULL)
			return NULL;
		if (p->key == key)
			return p;
		else if (key < p->key)
		{
			return sys_get_Value_By_Key(key, p->left);
		}
		else
		{
			return sys_get_Value_By_Key(key, p->right);
		}

	}


	Node* remove(Node* p, string k) // �������� ����� k �� ������ p
	{

		


		if (!p) return 0;
		if (k < p->key)
			p->left = remove(p->left, k);
		else if (k > p->key)
			p->right = remove(p->right, k);
		else //  k == p->key 
		{
			int FLAG_KOSTIL = 0; // ������� , ����� �� ������� ������ ������
			Node* q = p->left;
			Node* r = p->right;// ������� ����������
			if ( p->key ==  head->key )
				FLAG_KOSTIL = 1;
			delete p; // ������� ������
			if (!r) return q;
			Node* min = minNode(r); // ��� ���� - ��������� �� ��� ����� ����������� �� ������������, ����� ��..
			min->right = rmMin(r);
			min->left = q;
			if (FLAG_KOSTIL)
				head = min;
			return balance(min);
		}
		return balance(p); // �����������
	}

	Node* minNode(Node* p) // ����� ���� � ����������� ������ � ������ p 
	{
		return p->left ? minNode(p->left) : p;
	}

	Node* rmMin(Node* p) // �������� ���� � ����������� ������ �� ������ p
	{
		if (p->left == 0)
			return p->right;
		p->left = rmMin(p->left);
		return balance(p);
	}


};






int main()
{
	//
	//������� ������)))
	//
	int c = 3, j = 5;
	AVL_Tree *AVL = new AVL_Tree();
	
	AVL->insert("a", 10);
	//cout << AVL->get_Value_By_Key(5);
	AVL->insert("b", 11);
	//cout << AVL->get_Value_By_Key(1);
	AVL->insert("v", 17);
	//cout << AVL->get_Value_By_Key(3);
	AVL->insert("d", 9);
	AVL->insert("c", 156);
	AVL->insert("z", 160);
	AVL->remove(AVL->head, "a");
	AVL->insert("a", 765);
	cout << AVL->get_Value_By_Key("a");

	return 0;
}