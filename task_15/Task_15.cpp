//How many such routes are there through a 20x20 grid?
#include <iostream>
#include <ctime>
using namespace std;

void spend_time(unsigned int* start_time) {
	unsigned int end_time = clock();
	auto search_time = end_time - *start_time;
	cout << "Spend time(msc): " << search_time << endl;
}

void start_program(unsigned long* limit) {
	system("cls");
	cout << "Task_15: How many such routes are there through a 20x20 grid?\nEnter the gridSize:\n::";
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
	unsigned long gridSize = 20;
	start_program(&gridSize);
	unsigned long long paths = 1;
	unsigned int start_time = clock();

	for (auto i = 0; i < gridSize; i++) {
		paths *= (2 * gridSize) - i;
		paths /= i + 1;
		if (paths > 18446744073709551614) {
			system("cls");
			cout << "ERROR: the temporary variable exceeded when counting 18446744073709551615" << endl;
			spend_time(&start_time);
			exit(0);
		}
	}

	spend_time(&start_time);
	cout << "Answer: " << paths << endl;
	if (restart_program())
		goto RESTART_PROGRAM;
	return 0;
}