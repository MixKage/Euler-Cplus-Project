//Существует ровно одна пифагорова тройка, для которой a + b + c = 1000. Найдите произведение a*b*c
#include <iostream>
using namespace std;

int solve()
{
	int n = 1000;
	for (int a = 1;; ++a)
		for (int b = a + 1;; ++b) {
			int c = n - a - b;
			if (c <= b) break;
			if (a * a + b * b == c * c) {
				return a * b * c;
			}
		}
}
int main()
{
	cout << solve() << endl;
	return 0;
}