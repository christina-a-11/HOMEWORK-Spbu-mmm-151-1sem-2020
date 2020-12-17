#include <iostream>

using namespace std;

int main()
{
	int k = 1, m = 1, n = 1;
	cin >> k >> m >> n;
	int t = 0;
	t = n / k * m * 2;
	if ((n % k) > 0)
	{
	  t += m;
	}
	cout << t;
	system("pause>nul");
	return 0;
}
