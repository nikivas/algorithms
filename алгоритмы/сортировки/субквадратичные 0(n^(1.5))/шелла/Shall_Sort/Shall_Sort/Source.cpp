#include <iostream>

using namespace std;


int incr(long n[], long size)
{
	long p1, p2, p3, s;
	p1 = p2 = p3 = 1;
	s = -1;
	do
	{
		if (++s % 2)
		{
			n[s] = 8 * p1 - 6 * p2 + 1;
		}
		else
		{
			n[s] = 9 * p1 - 9 * p3 + 1;
			p2 *= 2;
			p3 *= 2;
		}
		p1 *= 2;
	} while (3 * n[s] < size);
	p1 *= 2;
	return s > 0 ? --s : 0;
}


int Shell_Sort(long a[], long size)
{
	long p(1), p1(1), p2(1), seq[100];
	int s;
	int j(0);
	s = incr(seq, size);
	long inc;
	int i;
	while (s >= 0)
	{
		inc = seq[s--];
		for (i = inc; i < size; i++)
		{
			long temp = a[i];
			for ( j = i - inc; (j >= 0)  && (temp < a[j]); j-=inc)
			{
				a[j + inc] = a[j];
			}
			a[j+inc] = temp;

		}

	}
	return 0;

}



int main()
{
	const long size = 17;
	long a[size] = { 8,18,27,5,1,2,4,8,0,55,12,42,62,22,31,73,47 };
	Shell_Sort(a, size);
	for (int i = 0;i < size;i++)
	{
		cout << a[i] << ' ';
	}

}