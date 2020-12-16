#include <iostream>

using namespace std;

int main()
{
	int n = 1, m = 1;
	cin >> n >> m;
	double k = (double)max(n, m) / min(n, m);
	cout << (k == (int)k ? 1 : 5);
	system("pause>nul");
	return 0;
}