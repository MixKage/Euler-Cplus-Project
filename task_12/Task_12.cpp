//What is the value of the first triangle number to have over five hundred divisors?
#include <iostream>
using namespace std;

int _globalDivider = 0;

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
		cout << "Loading... " /*<< *loading << "% (not work)"*/ << "\nNumber: " << *num << "\nNumber of divisors: " << _globalDivider << endl;
	}
}

int main() {
	unsigned int start_time = clock();
	unsigned long long i = 0;
	unsigned long long temp = 0;
	int loading = 0;
	cout << "Loading..." << endl;
	while (_globalDivider <= 500) {
		i++;
		temp = factorial(&i);
		if (temp == 76576500) {
			cout << "HI" << endl;
		}
		numDel(&temp);
		/*Loading(&loading, &temp);*/
	}
	cout << "Answer: " << temp << endl;
	unsigned int end_time = clock();
	unsigned int search_time = (end_time - start_time) / 1000;
	cout << "Spend time: " << search_time << endl;
	return 0;
}