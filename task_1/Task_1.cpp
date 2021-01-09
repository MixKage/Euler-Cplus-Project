//Find the sum of all the multiples of 3 or 5 below 1000.
#include <iostream>
int main() {
	int limit = 1000;
	int vrem = 0;
	for (int i = 0; i < limit; i++) {
		if ((i % 3 == 0) || (i % 5 == 0)) {
			std::cout << i << std::endl;
			vrem += i;
		}
	}
	std::cout << vrem << std::endl;
	return 0;
}