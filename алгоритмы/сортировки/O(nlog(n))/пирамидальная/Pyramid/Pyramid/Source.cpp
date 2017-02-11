#include <iostream>	

using namespace std;
const int sizeA = 10;
void down_heap(int a[], int k, int n)
{
	int el = a[k];
	int el_idx = k;
	while (el_idx <= n / 2)
	{
	
		int child = el_idx*2;
		int idx = el_idx; // idx - index(max_el)
		if (a[child] > a[idx])
			idx = child;
		if (child  < n  && a[child + 1] > a[idx])
			idx = child + 1;
		if (idx != el_idx)
		{
			int tmp = a[el_idx];
			a[el_idx] = a[idx];
			a[idx] = tmp;
			el_idx = idx;
		}
		else
		{
			break;
		}
	}
}


int main()
{
	
	int a[sizeA] = { 10,9,7,8,1,2,4,5,6,3 };
	
	for (int i = 0; i < sizeA /2  -1; i++)
	{
		down_heap(a, i, sizeA);
	}

	int r = sizeA - 1;
	for (int i = sizeA-1; i > 0; i--)
	{
		int tmp = a[i];
		
		a[i] = a[0];
		a[0] = tmp;
		down_heap(a, 0, i-1);
	}

	for (int el : a)
	{
		cout << el << ' ';
	}
	


	return 0;
}