#include <iostream>
using namespace std;
#define sizeN 10000


int BasicSearch(int a[], int size, int key)
{
	for (int i = 0; i < size; i++)
	{
		if (a[i] == key) {
			return i;
		}
	}
	return -1;
}

// for example a: 1,2,3,4,5,...,N
int BinSearch(int a[], int size, int key)
{
	int l = 0;
	int r = size - 1;

	int Ans = -1;

	while (l < r)
	{
		int mid = (l + r) / 2;
		int el = a[mid];
		if (el > key)
		{
			r = mid;
		}
		else if (el < key)
		{
			l = mid;
		}
		else
		{
			Ans = mid;
			break;
		}

	}
	
	return Ans;
}


int main()
{
	int N[10000];
	for (int i = 0; i < sizeN; i++)
	{
		N[i] = i*2;
	}

	cout << BinSearch(N, sizeN, 8);

	int z;cin >> z;
}