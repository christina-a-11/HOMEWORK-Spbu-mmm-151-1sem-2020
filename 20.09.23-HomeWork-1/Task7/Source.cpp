//Ïîñ÷èòàòü öåëóþ ñòåïåíü ÷èñëà

#include <iostream>

using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	int stepen = 1;

	for (int i = 1; i <= b; i++) {
		stepen *= a;
	}
	cout << stepen;
	//system("pause>nul");
	return 0;
}