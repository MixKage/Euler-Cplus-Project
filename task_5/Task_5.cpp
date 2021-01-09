//What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
#include<iostream>
using namespace std;

bool _isGoodNumber(unsigned long long* num)
{
	for(int i=1;i<21;i++)
	{
		if(*num%i!=0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	unsigned long long limit = 18446744073709551615;
	for(unsigned long long i=2;i<limit;i++)
	{
		if(i%5==0&&i%10==0)
		{
			if(_isGoodNumber(&i))
			{
				cout << i << endl;
				break;
			}
		}
	}
	return 0;
}