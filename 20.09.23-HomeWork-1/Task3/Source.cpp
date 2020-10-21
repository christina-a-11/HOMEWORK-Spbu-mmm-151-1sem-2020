//Âûâåñòè íà ýêðàí âñå ñ÷àñòëèâûå áèëåòû ñ çàäàííîé ñóììîé ÷èñåë.

#include <iostream>

using namespace std;

int main() {
	int k;
	cin >> k;
	for (int i = 100000; i <= 999999; i++) {
		int m = i / 1000;
		int n = i % 1000;
		m = m / 100 + m % 10 + (m / 10) % 10;
		n = n / 100 + n % 10 + (n / 10) % 10;
		if (m == n) {
			if (m == k) {
				cout << i << " ";
			}
		}
	}
	//system("pause>nul");
	return 0;
}
