//Find the sum of all the primes below two million.
#include <iostream>
#include <list>
#include <cmath>
#include <ctime>
using namespace std;

void Loading(const int* iterator)
{
	int L_bar = 0;
	if (*iterator % 200000 == 0)
	{
		L_bar = *iterator / 20000;

		system("cls");
		cout << "Loading... " << L_bar << "%" << endl;
	}
}

void PrintList(const list<unsigned long long>& lst)
{
	for (auto i = lst.cbegin(); i != lst.cend(); ++i)
	{
		cout << *i << endl;
	}
}

void EazyNumber(list<unsigned long long>& lst)
{
	cout << "Loading... 0%" << endl;
	int limit = 100;
	bool TF = false;
	unsigned long long sum = 2;
	for (int i = 2; i < limit; i++)
	{
		for (int l = 2; l < i; l++)
		{
			if (i % l != 0) {
				TF = true;
			}
			else {
				TF = false; break;
			}
		}
		Loading(&i);
		if (TF)
		{
			sum += i;
			lst.push_back(i);

		}
	}
	cout << "sum=" << sum << endl;
}

int main()
{
	unsigned int start_time = clock();
	list<unsigned long long> myList = { 2 };
	/*auto it = myList.begin();*/
	EazyNumber(myList);
	PrintList(myList);
	myList.clear();
	unsigned int end_time = clock();
	unsigned int search_time = (end_time - start_time) / 1000;
	cout << "Spend time(sec) = " << search_time << endl;
	return 0;
}