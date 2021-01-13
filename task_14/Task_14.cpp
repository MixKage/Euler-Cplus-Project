//Which starting number, under one million, produces the longest chain?
#include <iostream>
#include <list>
#include <ctime>
using namespace std;

bool even_num(unsigned long long* num) {
	if (*num % 2 == 0)
		return true;
	else
		return false;
}

void search_max_iterator(unsigned long long* max_iterator, unsigned long long* iterator, int* limit, unsigned long long* max_limit) {
	if (*iterator > *max_iterator) {
		*max_iterator = *iterator;
		*max_limit = *limit;
	}
	*iterator = 0;
}

void start_program(int* limit) {
	system("cls");
	cout << "Task_14: Which starting number, under one million, produces the longest chain?\nEnter the limit\n::";
	while (true) {
		cin >> *limit;
		if (!cin) {
			cout << "Enter the number!\n::";
			cin.clear(); cin.ignore(cin.rdbuf()->in_avail()); _flushall();
		}
		else
			break;
	}
	system("cls");
	cout << "Loading..." << endl;
}

void spend_time(unsigned int* start_time) {
	unsigned int end_time = clock();
	auto search_time = end_time - *start_time;
	cout << "Spend time(msc): " << search_time << endl;
}

void finish_program(unsigned long long* max_limit, unsigned long long* max_iterator) {
	system("cls");
	cout << "Answer: " << *max_limit << "\nIteration: " << *max_iterator << endl;
}

bool restart_program() {
	int temp;
	cout << "Restart the program? (0/1)\n::";
	while (true) {
		cin >> temp;
		if (!cin) {
			cout << "Enter the number!\n::";
			cin.clear(); cin.ignore(cin.rdbuf()->in_avail()); _flushall();
		}
		else {
			if (temp == 1) {
				return true;
			}
			else {
				return false;
			}
		}
	}
}

int main() {
	RESTART_PROGRAM:
	int limit = 1000000;
	unsigned long long max_iterator = 0;
	unsigned long long iterator = 0;
	unsigned long long max_limit = 0;
	start_program(&limit);
	unsigned int start_time = clock();
	limit--;

	for (limit; limit > 1; limit--) {
		unsigned long long num = limit;
		while (num > 1) {
			if (even_num(&num))
				num /= 2;
			else
				num = 3 * num + 1;
			if (num > 18446744073709551614) {
				system("cls");
				cout << "ERROR: the temporary variable exceeded when counting 18446744073709551615" << endl;
				spend_time(&start_time);
				exit(0);
			}
			iterator++;
		}
		iterator++;
		search_max_iterator(&max_iterator, &iterator, &limit, &max_limit);
	}
	system("cls");
	finish_program(&max_limit, &max_iterator);
	spend_time(&start_time);
	if (restart_program())
		goto RESTART_PROGRAM;
	return 0;
}