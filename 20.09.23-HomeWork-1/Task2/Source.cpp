//Íàïèñàòü ïðîãðàììó íàõîæäåíèÿ íåïîëíîãî ÷àñòíîãî îò äåëåíèÿ a íà b (öåëûå ÷èñëà),
//èñïîëüçóÿ òîëüêî îïåðàöèè ñëîæåíèÿ, âû÷èòàíèÿ è óìíîæåíèÿ.

#include <iostream>

using namespace std;

int main() {
	int a, b, i = 0;
	cin >> a >> b;

	if (a * b > 0) {
		a = abs(a);
		b = abs(b);
		while (a >= b) {
			i++;
			a -= b;
		}
		cout << i;
	}

	else if (a * b < 0) {
		a = abs(a);
		b = abs(b);
		while (a >= b) {
			i++;
			a -= b;
		}
		cout << -1 * i;
	}

	else if (a * b == 0) {
		if (a == 0) {
			cout << 0;
		}
		else if (b == 0) {
			cout << "Error";
		}
	}
	//system("pause>nul");
	return 0;
}