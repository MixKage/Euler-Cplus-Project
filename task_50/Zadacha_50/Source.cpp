#include <iostream>
using namespace std;
int m_i = 0;
unsigned int limit = 0;
int work();
void start_program() {
	setlocale(LC_ALL, "ru"); system("cls");
	cout << "������: ����� �� ������� ����� ������ ������ �������� ����� �������� � ���� ����� ����������� �������� ���������������� ������� �����?" << endl;
	cout << "����� ���������� ��������� ����� �������������?\n::";
	cin >> m_i;
	if (m_i < 2) {
		cout << "������� ������� ��������� ����������" << endl;
		return;
	}
	cin.clear(); cin.ignore(cin.rdbuf()->in_avail()); _flushall();
	cout << "����� ����� �� ������ ��������� ����� ������� �����?\n::";
	cin >> limit;
	if (limit < 2) {
		cout << "������� ������� ��������� ����������" << endl;
		return;
	}
	cin.clear(); cin.ignore(cin.rdbuf()->in_avail()); _flushall();
	cout << "������� Enter ��� ������." << endl;
	cin.get();
	cin.clear(); cin.ignore(cin.rdbuf()->in_avail()); _flushall();
	work();
}

void loading(int *Loading, int *l){
	if (limit >= 100) {
		if (*l % (limit / 100) == 0) {
			system("cls");
			*Loading = *Loading + 1;
			cout << "��������... " << *Loading << "%" << endl;
		}
	}
}

int work() {
	system("cls");
	unsigned int start_time = clock();
	int* array = new int[m_i];
	int Vrem = 0;
	int k = 0;
	bool TF = false;
	int Loading = 0;
	int amount_of_numbers = 0;
	array[0] = 1;
	cout << "������������� ���������� ���������..." << endl;
	cout << "������ ��������� �����..." << endl;
	for (int l = 2; l < limit; l++) {
		for (int i = 2; i < l; i++) {
			if (l % i != 0) {
				TF = true;
			}
			else {
				TF = false;
				break;
			}
		}
		if (TF == true) {
			if (k > (m_i - 2)) {
				cout << "����� �� ����� �������!" << endl;
				break;
			}
			k = k + 1;
			array[k] = l;
			TF = false;
		}
		loading(&Loading, &l);
		if (l == 1000000) {
			cout << "����� ������� ��������..." << endl;
		}
	}

	system("cls");
	unsigned int end_time2 = clock();
	unsigned int search_time2 = (end_time2 - start_time) / CLK_TCK;
	cout << "�������� ������ ������� �����. ����������� ����� (���): " << search_time2 << endl;
	int Block = 0;
	int Block1 = 0;
	bool double_try = false;
	while (double_try == false) {
		unsigned int start_time_1 = clock();
		cout << "=" << endl;
		Block = Block1;
		Vrem = 0;
		amount_of_numbers = 0;
		for (Block; Block < m_i; Block++) {
			if (Vrem < limit) {
				Vrem += array[Block];
				if (Block > m_i - 2) {
					cout << "!!!���������� " << limit << " �� ���������!!!" << endl;
					return false;
				}
			}
			else {
				Vrem -= array[Block];
				amount_of_numbers = Block - Block1 - 1;
				cout << "��������� �������� ���� �����" << endl;
				Block = 0;
				for (int i = 2; i < sqrt(Vrem); i++) {
					if (Vrem % i != 0) {
						TF = true;
					}
					else {
						TF = false;
						break;
					}
				}
				if (!TF) {
					cout << "������! ������������ ����� (" << Vrem << ") �� �������� �������, ������� ��� ���!" << endl;
					Block1 = Block1 + 1;
				}
				else {
					cout << "����� �������:  " << Vrem << endl;
					int vvod = 0;
					unsigned int end_time_1 = clock();
					unsigned int search_time2 = (end_time_1 - start_time_1);
					cout << "��������� ������� (������������): " << search_time2 << endl;
					cout << "���������� ������� �����: " << amount_of_numbers << endl;
					while (true) {
						cout << "�������� ������� �����?(1/0)\n::";
						cin >> vvod;
						cin.clear(); cin.ignore(cin.rdbuf()->in_avail()); _flushall();
						if (vvod == 1) {
							Block = 0;
							for (int i = Block1; i < amount_of_numbers + Block1; i++) {
								cout << i + 1 << " - " << array[i] << endl;
							} break;
						}
						else if (vvod == 0) { break; }
						else { continue; }
					}
					vvod = 0;
					while (true) {
						cout << "������ ������� ����� �� ������?(1/0)\n::";
						cin >> vvod;
						cin.clear(); cin.ignore(cin.rdbuf()->in_avail()); _flushall();
						if (vvod == 1) { Block1 = Block1 + 1; break; }
						else if (vvod == 0) {
							double_try = true;	break;;
						}
						else { continue; }
					}
				}
				break;
			}
		}
	}
	unsigned int end_time = clock(); unsigned int search_time = (end_time - start_time) / CLK_TCK;
	cout << endl << "�����: " << Vrem << endl << "��������� ����� ������� (���): " << search_time << endl << "���������� ������� �����: " << amount_of_numbers << endl;; "\n\n\n\n\n\n\n";
	delete[] array; array = nullptr;
}
int main() {
	while (true) {
		start_program();
		cout << "������������� ���������? (1/0)\n";
		m_i = 0; limit = 0;
		cin >> m_i;
		cin.clear(); cin.ignore(cin.rdbuf()->in_avail()); _flushall();
		if (m_i == 1) {continue;}
		else {break;}
	}
}