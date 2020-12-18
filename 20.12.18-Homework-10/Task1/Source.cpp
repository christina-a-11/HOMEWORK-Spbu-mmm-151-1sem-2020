#include <iostream>

using namespace std;

void printArr(int n, int** a)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%2d ", a[i][j]);
		}
		cout << endl;
	}
}

void Arr1(int n, int**& a)
{
	cout << "1." << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[i][j] = 1 + i + j;
		}
	}
	printArr(n, a);
}

void Arr2(int n, int**& a)
{
	cout << "2." << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[i][j] = 2 * n - i - j - 1;
		}
	}
	printArr(n, a);
}

void Arr3(int n, int**& a)
{
	cout << "3." << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[i][j] = j + 1;
		}
	}
	printArr(n, a);
}

void Arr4(int n, int**& a)
{
	cout << "4." << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if(i > j)
			{ 
				a[i][j] = j + 1;
			}
			else if (j >= i)
			{
				a[i][j] = i + 1;
			}
		}
	}
	printArr(n, a);
}

void Arr5(int n, int**& a)
{
	cout << "5." << endl;
	int m = 1;
	if (n % 2 != 0) {
		a[(n / 2)][(n / 2)] = (n * n);
	}
	for (int i = 0; i < (n / 2); i++) {
		for (int j = i; j < (n - i); j++) {
			a[i][j] = m;
			m++;
		}
		for (int j = 1; j < (n - i - i); j++) {
			a[(j + i)][(n - i) - 1] = m;
			m++;
		}
		for (int j = (n - 2) - i; j >= i; j--)
		{
			a[(n - i) - 1][(j)] = m;
			m++;
		}
		for (int j = ((n - i) - 2); j > i; j--) {
			a[j][i] = m;
			m++;
		}
	}
	printArr(n, a);
}

int main()
{
	int n = 0;
	cin >> n;
	int** a = new int* [n];
	for (int i = 0; i < n; ++i)
	{
		a[i] = new int[n];
	}
	Arr1(n, a);
	Arr2(n, a);
	Arr3(n, a);
	Arr4(n, a);
	Arr5(n, a);
	for (int i = 0; i < n; ++i)
	{
		delete[] a[i];
	}
	delete[] a;
	system("pause>nul");
	return 0;
}