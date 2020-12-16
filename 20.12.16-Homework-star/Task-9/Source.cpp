#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector <int> x;
	double a = 0;
	double s = 0;
	long long n = 0;
	cin >> a;
	while (a != 0)
	{
		x.push_back(a);
		s += a;
		n++;
		cin >> a;
	}
	s /= n;
	double ans = 0;
	for (int i = 0; i < n; i++)
	{
		ans += (x[i] - s) * (x[i] - s);
	}
	ans = ans / (n - (double)1);
	cout << sqrt(ans);
	system("pause>nul");
	return 0;
}