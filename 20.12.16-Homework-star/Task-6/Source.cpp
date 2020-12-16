#include <iostream>

using namespace std;

int main()
{
	int n = 1;
	int t = 1;
	int i = 1;
	cin >> n;
	while (t < n)
	{
		i++;
		t += i;
	}
	cout << i;
	return 0;
}