//Find the largest palindrome made from the product of two 3-digit numbers.
#include <iostream>
#include <string>
using namespace std;

bool _isPol(int *temp)
{
	string str{};
	str = to_string(*temp);
	int len = str.length();
	for (int i = 0; i < len / 2; ++i)
	{
		if (str[i] != str[len - i - 1])
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int num_1 = 0;
	int num_2 = 0;
	int temp = 0;
	int sum = 0;

	for(int i=100;i<1000;i++)
	{
		for(int l=100;l<1000;l++)
		{
			temp = i * l;
			if(temp>sum)
			{
				if(_isPol(&temp))
				{
					sum = temp;
				}
			}
		}
	}
	cout << sum;
	return 0;
}