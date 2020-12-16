#include <iostream>

using namespace std;

int main()
{
	int x = 0;
	int max_1 = -1;
	int max_2 = -1;
	int dist = 1000000;
	cin >> x;
	int i = 0;
	int i_max1 = 0;
	int i_max2 = 0;
	while (x != 0)
	{
		i++;
		if (x > max_2 )
		{
			int tmp = max_2;
			max_2 = x;
			max_1 = tmp;
			i_max1 = i_max2;
			i_max2 = i;
			if (dist > i_max2 - i_max1 - 1 && max_1 != -1)
			{
				dist = i_max2 - i_max1 - 1;
			}
		}
		
		cin >> x;
	}
	cout << dist;
	system("pause>nul");
	return 0;
}