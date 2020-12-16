#include <iostream>

using namespace std;

int main()
{
	double ans = 1;
	int n = 0;
	cin >> n;
	int t = 1;
	for (int i = 0; i < n; i++)
	{
		ans += (double)1 / t;
		t *= (t + 1);
	}
	cout << ans;
	return 0;
}