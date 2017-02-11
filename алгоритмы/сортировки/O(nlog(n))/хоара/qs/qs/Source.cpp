#include <iostream>
using namespace std;
int a[100];
void quickSort(int l, int r)
{
	int p = a[(r + l) / 2];
	int i = l;
	int j = r;

	while (i <= j)
	{
		while (a[i] < p)i++;
		while (a[j] > p)j--;
		if (i <= j)
		{
			swap(a[i++], a[j--]);
		}

	}
	if (i < r)
	{
		quickSort(0, i);
	}
	if (j > l)
	{
		quickSort(j, r);
	}
}
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	quickSort(0, n - 1);
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	return 0;
}