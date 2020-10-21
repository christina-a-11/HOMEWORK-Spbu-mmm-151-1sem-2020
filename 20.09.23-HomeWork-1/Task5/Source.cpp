//Ïîñ÷èòàòü êîëè÷åñòâî äåëèòåëåé ÷èñëà

#include <iostream>

using namespace std;

int main() {

	int x;
	cin >> x;
	int count = 0;

	if (x == sqrt(x) * sqrt(x)) {
		count++;
	}

	for (int i = 1; i < sqrt(x); i++) {
		if (x % i == 0) {
			count += 2;
		}
	}
	cout << count;
	//system("pause>nul");
	return 0;
}