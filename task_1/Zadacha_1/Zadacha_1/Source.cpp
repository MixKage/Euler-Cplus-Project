//���� �������� ��� ����������� ����� ������ 10, ������� 3 ��� 5, �� ������� 3, 5, 6 � 9. ����� ���� ����� ����� 23. 
//������� ����� ���� ����� ������ 1000, ������� 3 ��� 5.
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