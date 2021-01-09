//Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
#include<iostream>
using namespace std;

int square_1()
{
	int temp = 0;
	for (int i = 1; i < 101; i++)
	{
		temp += i * i;
	}
	return temp;
}

int square_2()
{
	int temp = 0;
	for (int i = 1; i < 101; i++)
	{
		temp += i;
	}
	temp *= temp;
	return temp;
}

int main()
{
	cout << square_2() - square_1();
	return 0;
}