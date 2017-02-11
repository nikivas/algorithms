#include<iostream>
using namespace std;

int fact(int n)
{
	if (n < 1)
		return 1;
	return n*fact(n - 1);
}

int fibbo(int n)
{
	if (n <= 1)
		return 0;
	else
		return fibbo(n - 1) + fibbo(n - 2);
}

int NOD(int a, int b) { // алгоритм евклида НОД
	return b ? NOD(b, a%b) : a;
}

int LCM(int a, int b) { // НОК
	return a / NOD(a, b) * b;
}


int count(int a) { // сумма цифр числа
	return (!a) ? 0 : (a % 10 + count(a / 10));
}



bool prime(int n, int div) { // проверка на простое число
	return (div == 1) ? true : (n % div != 0) && (prime(n, div - 1));
}
bool prime(int n) { // оболочка для проверки, не писать же prime(100,sqrt(100));
	return (n == 1) ? 0 : (prime(n, int(sqrt(n))));
}


int poww(int a, int b, int p) { // число а в степень b по модулю р
	return b ? (a * poww(a - 1, b, p) % p) : 1;
}

int main()
{


	return 0;
}