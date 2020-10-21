//Ïîñ÷èòàòü ôàêòîðèàë ÷èñëà.

#include <iostream>

using namespace std;

int F(int a, int b) {
	if (a == b) {
		return a;
	}
	else if (a + 1 == b) {
		return a * b;
	}
	else {
		int m = (a + b) / 2;
		return F(a, m) * F(m + 1, b);
	}
}

int main() {
	int x;
	cin >> x;

	cout << F(1, x);
	//system("pause>nul");
	return 0;
}
