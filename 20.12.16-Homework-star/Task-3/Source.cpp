#include <iostream>

using namespace std;

int main()
{
	double a = 0, b = 0, c = 0;
	cin >> a >> b;
	c = a - b;
	double h = 0;
	cin >> h;
	cout << ((h / c == (int)(h / c)) ? (h / c) : ((int)(h / c) + 1));
	system("pause>nul");
	return 0;
}