//Каков самый большой делитель числа 600851475143, являющийся простым числом?
#include <iostream>
using namespace std;
int main() {
	unsigned int start_time = clock();
	long long n = 600851475143;
	unsigned long d = 2;
	unsigned long prev_factor = 0;
	while (d < n)
		if (n % d == 0) {
			if (d != prev_factor) {
				//cout << d << " ";
				prev_factor = d;
			}
			n /= d;
		}
		else
			++d;
	unsigned int end_time = clock();
	unsigned int search_time = end_time - start_time;
	if (n != 1 && n != prev_factor)
		cout << "largest divisor 600851475143 = " << n << "\nSpend time (ms): "<< search_time << endl;;
	return 0;
}