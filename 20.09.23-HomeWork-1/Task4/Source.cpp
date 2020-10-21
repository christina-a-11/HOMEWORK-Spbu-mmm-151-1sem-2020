//Íàïèñàòü ïðîãðàììó, ïå÷àòàþùóþ âñå ïðîñòûå ÷èñëà, íå ïðåâîñõîäÿùèå çàäàííîãî ÷èñëà.

#include <iostream>

using namespace std;

int main() {
	int x;
	cin >> x;

	int k = 0;
	for (int i = 2; i <= x; i++) {
		k = 0;
		for (int j = 2; j < i; j++) {
			if (i % j == 0) {
				k++;
			}
		}
		if (k == 0) {
			cout << i << " ";
		}
	}
	//system("pause>nul");
	return 0;
}