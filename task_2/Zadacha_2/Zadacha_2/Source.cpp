//Рассмотрев члены последовательности Фибоначчи, значения которых не превышают четырех миллионов, найдите сумму четных членов.
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
}