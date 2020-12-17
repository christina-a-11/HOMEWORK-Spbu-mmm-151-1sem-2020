#include <iostream>

using namespace std;

int main()
{
	int n = 1, m = 1;
	cin >> n >> m;
	double k = 0;
	k = (n / m > 0 ? (double)n / m : (double)m / n);
	cout << (k == (int)k ? 1 : 5);
	//system("pause>nul");
	return 0;
}
