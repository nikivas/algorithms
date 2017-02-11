#include <iostream>
#include<vector>
using namespace std;



int N[10000];

int main()
{
	vector<int> Ans;

	Ans.push_back(1);

	for (int i = 2; i < 10000; i++)
	{
		if (N[i] == 0)
		{
			Ans.push_back(i);
		}

		for (int j = i + i; j < 10000; j += i)
		{
			N[j]++;
		}
	}
	for (int i = 0; i < Ans.size(); i++)
	{
		cout << Ans[i]<< " ";
	}
	int n;
	cin >> n;



}