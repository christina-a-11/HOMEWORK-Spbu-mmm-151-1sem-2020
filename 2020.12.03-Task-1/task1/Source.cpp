#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double myFunction(double x, int n)
{
	double ans = 0;
	int i = 1;
	int k = -1;
	if (x == 1)
	{
	return 0.785398163;
	}
	else if (x == -1)
	{
		return -0.785398163;
	}
	else if (x >= 0)
	{
		while (x > 0.000000001 * i)
		{
			if (i % 2 != 0)
			{
				k *= -1;
				ans = ans + k * (x / (double)i);
			}
			x *= x;
			i++;
		}
	}
	else if (x < 0)
	{
		x *= -1;
		k = 1;
		while (x > 0.000000001 * i)
		{
			if (i % 2 != 0)
			{
				k *= -1;
				ans = ans + k * (x / (double)i);
			}
			x *= x;
			i++;
		}
	}
	return ans;
}

int main()
{
	double x = 0;
	int n = 0;
	cout << "x = ";
	cin >> x;
	cout << endl;
	cout << "n = ";
	cin >> n;
	cout << atan(x) << endl;
	cout << fixed << setprecision(n) << myFunction(x, n) << endl;

	system("pause>nul");
	return 0;
}