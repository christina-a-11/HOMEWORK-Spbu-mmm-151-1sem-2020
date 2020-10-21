//Ïîñ÷èòàòü 2^n - 1 ñ ïîìùüþ ïîáèòîâûõ ñäâèãîâ è èíâåðñèè

#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	unsigned x = 1;
	for (int i = 1; i < n; i++) {
		x = x << 1;
	}
	cout << ~x;
	system("pause>nul");
	return 0;
}