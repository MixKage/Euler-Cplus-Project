#include<iostream>
using namespace std;

int limit = 2000000000;

int main()
{
	cout << "Loading...";
	int Loading = 0;
	bool TF = false;
	int number[10001]{};;
	int a_i = 0; //array_index
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
			a_i = a_i + 1;
			number[a_i] = l;
			TF = false;
			if(a_i==10000)
			{
				break;
			}
		}
	}
	cout << " 100%\nAnswer: " << number[10000] << endl;
	return 0;
}