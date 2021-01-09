//Найдите разницу между суммой квадратов первых ста натуральных чисел и квадратом суммы.
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