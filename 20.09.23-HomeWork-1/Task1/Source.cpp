//Íàïèñàòü ïðîãðàììó, ñ÷èòàþùóþ çíà÷åíèå ôîðìóëû
//x^4 + x^3 + x^2 + x + 1 çà äâà óìíîæåíèÿ.

#include <iostream>

using namespace std;

int main() {
	int x;
	cin >> x;
	int X = x * x;
	cout << (X + 1) * (X + x) + 1;
	//system("pause>nul");
	return 0;
}