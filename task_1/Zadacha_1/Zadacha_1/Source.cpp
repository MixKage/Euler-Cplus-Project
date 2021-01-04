//Если выписать все натуральные числа меньше 10, кратные 3 или 5, то получим 3, 5, 6 и 9. Сумма этих чисел равна 23. 
//Найдите сумму всех чисел меньше 1000, кратных 3 или 5.
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