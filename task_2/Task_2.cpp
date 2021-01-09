//By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.
#include<iostream>
int main() {
	int f1 = 0;
	int f2 = 1;
	int vrem = 0;;
	int sum = 0;
	int limit = 4000000;
	while (f2 < limit) {
		vrem = f1 + f2;
		if (vrem < limit) {
			f1 = f2;
			f2 = vrem;
			if (vrem % 2 == 0) {
				sum += vrem;
			}
		}
		else {
			break;
		}
	}
	std::cout << sum << std::endl;
	return 0;
}