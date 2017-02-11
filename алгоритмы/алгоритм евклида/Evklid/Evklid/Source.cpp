#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

int func(int a, int b) {
	return b ? func(b, a % b) : a;
}





int main()
{
	int a, b;
	cin >> a >> b;

	int ans;
	__asm {
		mov eax, a
		mov edx, b
		asmcikl :
		cmp eax, edx
			je the_end
			jl metka
			sub eax, edx
			jmp asmcikl
			metka :
		sub edx, eax
			jmp asmcikl
			the_end :
		mov ans, eax
	}


	cout << ans;

	cin >> a;
	return 0;
}