//What is the value of the first triangle number to have over five hundred divisors?
#include <iostream>
#include <ctime>
using namespace std;

int _globalDivider = 0;

void start(int* limit) {
	system("cls");
	cout << "Enter the desired number of divisors \n::";
	bool temp;
	while (true) {
		cin >> *limit;
		if (!cin) {
			cin.clear(); cin.ignore(cin.rdbuf()->in_avail()); _flushall();
			cout << "Error, please enter a number!\n::";
		}
		else
		{
			if (_globalDivider > 500) {
				cout << "It will take a long time, are you sure?(1/0)\n::";
				cin >> temp;
				if (temp == 1)
					break;
				else
					continue;
			}
			else
				break;
		}
	}
	system("cls");
}

unsigned long long factorial(unsigned long long* num) {
	unsigned long long temp = 0;
	for (unsigned long long i = 1; i <= *num; i++) {
		temp += i;
	}
	return temp;
}

void numDel(unsigned long long* num) {
	int _divider = 0;
	for (unsigned long long i = 1; i <= *num; i++) {
		if (*num % i == 0)
			_divider++;
	}
	if (_divider > _globalDivider) {
		_globalDivider = _divider;
		system("cls");
		cout << "Loading... " << "\nNumber: " << *num << "\nNumber of divisors: " << _globalDivider << endl;
	}
}

void finish(unsigned long long* answer, unsigned int* start_time)
{
	system("cls");
	cout << "Answer: " << *answer << endl;
	unsigned int end_time = clock();
	unsigned int minut = (end_time - *start_time) / 60000;
	unsigned int second = (end_time - *start_time) / 1000;

	cout << "Spend time: " << minut << " (min) or " << second << " (sec) or " << end_time - *start_time << " (msec)" << endl;
}

int main() {
	int limit{};
	start(&limit);
	unsigned int start_time = clock();
	unsigned long long i = 0;
	unsigned long long temp = 0;
	int loading = 0;
	cout << "Loading..." << endl;
	while (_globalDivider <= limit) {
		i++;
		temp = factorial(&i);
		numDel(&temp);
	}
	finish(&temp, &start_time);
	return 0;
}