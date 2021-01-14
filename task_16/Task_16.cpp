//What is the sum of the digits of the number 2^1000?
#include <iostream>
#include <ctime>
#include <string>
#include <algorithm>
using namespace std;

void my_pow(unsigned long long* num, int* limit) {
	for (int i = 0; i < *limit; i++) {
		*num *= 2;
	}
	cout << *num << endl;
}

//void int_to_str(unsigned long long* num, string* str) {
//	int lenght = 1;
//	while ((*num /= 10) > 0)
//		lenght++;
//	for (int i = 0; i < lenght; i++) {
//
//	}
//}

//void sum_num(string str) {
//	int lenght = str.length();
//	cout << lenght;
//}

//TODO: isNum, <=>,

string _sum(string str1, string str2) {
	int lenght1 = str1.length();
	int lenght2 = str2.length();
	string answer{};
	if (lenght1 > lenght2) {
		swap(lenght1, lenght2);
		swap(str1, str2);
	}

	reverse(str1.begin(), str1.end());
	reverse(str2.begin(), str2.end());

	int residue = 0;
	for (int i = 0; i < lenght1; i++) {
		int sum = ((str1[i] - '0') + (str2[i] - '0') + residue);
		answer.push_back(sum % 10 + '0');
		residue = sum / 10;
	}
	for (int i = lenght1; i < lenght2; i++) {
		int sum = ((str2[i] - '0') + residue);
		answer.push_back(sum % 10 + '0');
		residue = sum / 10;
	}
	if (residue) {
		answer.push_back(residue + '0');
	}
	reverse(answer.begin(), answer.end());
	return answer;
}

string _indegree(string num, string degree) {
	string one = "1";
	string degree_iterator = "0";
	int degree_iterator_int = 0;
	string answer = "1";
	string temp = answer;
	int degree_int = 0;
	int num_int = 0;
	for (unsigned int i = 0; i < degree.length(); i++) {
		degree_int = degree_int * 10 + degree[i] - 0x30;
	}
	for (unsigned int i = 0; i < num.length(); i++) {
		num_int = num_int * 10 + num[i] - 0x30;
	}
	while (degree_iterator_int < degree_int) {
		//string num_iterator = "1";
		int num_iterator_int = 1;
		while (num_iterator_int < num_int) {
			answer = _sum(answer, temp);
			num_iterator_int++;
			//num_iterator = _sum(num_iterator, one);
		}
		temp = answer;
		degree_iterator_int++;
		//degree_iterator = _sum(degree_iterator, one);
	}
	return temp;
}

int main() {
	//unsigned long long num = 2;
	//int extent = 100;

	string num = "2";
	string degree = "3";
	while (true) {
		cout << "Enter the num: ";
		cin >> num;
		cout << "Enter the degree: ";
		cin >> degree;
		cout << "Answer: " << _indegree(num, degree) << endl;
	}
	/*my_pow(&num, &extent);
	str = to_string(num);
	sum_num(str);*/
	return 0;
}