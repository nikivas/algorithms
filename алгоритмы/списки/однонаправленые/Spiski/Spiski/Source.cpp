#include<iostream>
using namespace std;

/*
вставка элемента: О(1)
удаление элемента: О(1)
поиск элемента : О(n)

*/



struct el
{
	int value;
	el *next;
	el *last;
};

class list
{

	el *head;


public:


	list()
	{
		head = NULL;
	}


	void addHead(int value)
	{
		el *tmp = new el;
		tmp->next = head;
		tmp->value = value;
		head = tmp;
	}

	void addAfterEl(el* elm, int value)
	{
		el *tmp = new el;
		tmp->value = value;
		tmp->next = elm->next;
		elm->next = tmp;
	}

	void deleteIdx(int idx)
	{
		el *tmp = getByIdx(idx - 1);

		if (tmp == NULL || tmp->next == NULL)
			return;

		el *tmp2 = tmp->next;

		tmp->next = tmp2->next;
		delete tmp2;
	}


	int search(int key) // возвращает индекс найденого
	{
		el *tmp = head;
		int Ans = -1;
		int i = 0;
		while (tmp != NULL)
		{
			if (tmp->value == key)
			{
				Ans = i;
				break;
			}
			tmp = tmp->next;
			i++;
		}
		return Ans;
	}


	el* getByIdx(int idx)
	{
		el *tmp = head;
		for (int i = 0; i < idx; i++)
		{
			if (tmp == NULL)
				return NULL;
			tmp = tmp->next;
		}
		return tmp;
	}


	void showAll()
	{
		el *tmp;
		tmp = head;
		while (tmp != NULL)
		{
			cout << tmp->value << " ";
			tmp = tmp->next;
		}
	}


	~list()
	{
		while (head != NULL)
		{
			el *tmp = head->next;
			delete head;
			head = tmp;
		}
	}


};



int main()
{
	list l1;

	for (int i = 0; i < 10; i++)
	{
		l1.addHead(i);
	}
	l1.showAll();
	l1.addAfterEl(l1.getByIdx(3), 1000);
	l1.deleteIdx(3);
	cout << "\n" << "1000's idx = " << l1.search(1000) << "\n";

	l1.showAll();

	return 0;
}