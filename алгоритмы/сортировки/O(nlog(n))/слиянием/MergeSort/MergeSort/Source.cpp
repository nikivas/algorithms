#include<iostream>

using namespace std;
const int sizeA = 5;
int a[sizeA] = { 5,4,3,1,2 };


void merge(int a[], int lb, int mid, int rb)
{
	int p1 = lb;
	int p2 = mid+1;
	int *buf = new int[rb - lb + 1];
	int idx = 0;
	while (p1 <= mid && p2 <= rb)
	{
		if (a[p1] < a[p2])
		{
			buf[idx++] = a[p1++];
		}
		else
		{
			buf[idx++] = a[p2++];
		}
	}
	while (p1 <= mid)
	{
		buf[idx++] = a[p1++];
	}
	while (p2 <= rb)
	{
		buf[idx++] = a[p2++];
	}

	for (int i = 0;i < rb - lb + 1;i++)
	{
		a[i+lb] = buf[i];
	}



}
void mergeSort(int a[], int l, int r)
{
	if (l < r)
	{
		long q = (r + l) / 2;
		mergeSort(a, l, q);
		mergeSort(a, q + 1, r);
		merge(a, l, q, r);
	}
}

int main()
{

	mergeSort(a, 0, 4);

	for (int i = 0;i < sizeA;i++)
	{
		cout << a[i] << ' ';
	}
}