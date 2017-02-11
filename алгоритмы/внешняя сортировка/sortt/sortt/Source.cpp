#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<fstream>
#include<queue>
#include<sstream>

using namespace std;

template <typename T>
std::string toString(T val)
{
	std::ostringstream oss;
	oss << val;
	return oss.str();
}



int main()
{
	setlocale(0, "");

	ifstream fin("input.txt");

	priority_queue<string> s;
	priority_queue<string> s2;
	vector<string> FNames;

	
	int cnt = 0;
	while (!fin.eof() && cnt < 1024)
	{
		string sbuf;
		fin >> sbuf;
		std::cout << sbuf << '\n';
		s.push(sbuf);
		cnt++;
	}

	
	string sbuf;
	string sLast = s.top();

	priority_queue<string>* el = &s;
	priority_queue<string>* el2 = &s2;

	int flag = 1;

	int file_name_idx = 0;
	string filename = "tmp_"+toString(file_name_idx);
	FNames.push_back(filename);
	ofstream out(filename);

	
	while (!fin.eof())
	{
		printf("boroda");
		if (flag == 0)
		{
			while(!el->empty())
			{
				out << el->top();
				printf("go");
				//cout << el->top();
				el->pop();
				
			}
			out.close();
			printf("qwerty");
			//cout << "gotovo";
			//return 0;
			
			filename = "tmp_" + toString(++file_name_idx);
			FNames.push_back(filename);
			out.open(filename);

			if (el == &s) {
				el = &s2;
				el2 = &s;
			}
			else
			{
				el = &s;
				el2 = &s2;
			}
		}
		fin >> sbuf;
		if (sbuf < el->top() && sbuf > sLast){
			out << sbuf;
			std::cout << sbuf;
		}
		else
		{
			if (sbuf < el->top() && el2->size() < 1024)
			{
				el2->push(sbuf);
			}
			else if (sbuf < el->top())
			{
				el2->push(sbuf);
				flag = 0;
				continue;
			}
		}
		out << el->top()<<'\n';
		std::cout << el->top()<<'\n';
		s.pop();
	}


}