#include <iostream>
#include "ArrayList.h"

using namespace std;

void printMenu()
{
	cout << "Какую задачу будем решать?" << endl;
	cout << "0 - выход из программы" << endl;
	cout << "1 - добавить элемент, введенный с клавиатуры" << endl;
	cout << "2 - вывести массив" << endl;
	cout << "3 - проверить, является ли массив симметричным" << endl;
	cout << "4 - циклический сдвинуть массив на n элементов.n > 0 - сдвиг вправо, n < 0 - сдвиг влево" << endl;
	cout << "5 - проверить, может ли массив стать симметричным, если из него удалить один элемент" << endl;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	ArrayList are;
	int choice = 0;
	do
	{
		printMenu();
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			cout << "Введите добавляемый элемент" << endl;
			int tmp = 0;
			cin >> tmp;
			are.add(tmp);

		}
		break;
		case 2:
		{
			cout << are.toString() << endl;
		}
		break;
		case 3:
		{
			bool flag = true;
			for (int i = 0; i < are.length() / 2; i++)
			{
				if (are.get(i) != are.get(are.length() - 1 - i))
				{
					cout << "Массив не симметричен" << endl;
					i += are.length();
					flag = false;

				}
			}
			if (flag == true)
			{
				cout << "Массив симметричен" << endl;
			}
		}
		break;
		case 4:
		{
			if (are.length() > 0)
			{
				int n = 0;
				cin >> n;
				if (n > 0)
				{
					n = are.length() - n % are.length();
					for (int i = 0; i < n / 2; i++)
					{
						are.swap(i, n - 1 - i);
					}
					for (int i = 0; i < (are.length() - n) / 2; i++)
					{
						are.swap(n + i, are.length() - 1 - i);
					}
					for (int i = 0; i < are.length() / 2; i++)
					{
						are.swap(i, are.length() - 1 - i);
					}
				}
				else  if (n < 0)
				{
					n *= -1;
					for (int i = 0; i < n / 2; i++)
					{
						are.swap(i, n - 1 - i);
					}
					for (int i = 0; i < (are.length() - n) / 2; i++)
					{
						are.swap(n + i, are.length() - 1 - i);
					}
					for (int i = 0; i < are.length() / 2; i++)
					{
						are.swap(i, are.length() - 1 - i);
					}

				}
			}
		}
			break;
		case 5:
		{
			bool flag = true;

			for (int i = 0; i < are.length() - 1; i++)
			{
				int temp = 0;
				temp = are.get(i); 
				are.remove(i); // delete element i

				for (int j = 0; j < are.length() / 2; j++)
				{
					if (are.get(j) != are.get(are.length() - 1 - j))
					{
						flag = false;
						break;
					}
				}

				if (flag == true)
				{
					cout << "Массив симметричен, если удалить элемент" << endl;
					i += are.length() + 1;
				}
				are.set(i, temp); // add element i
			}
			if (flag == false)
			{
				cout << "Массив не может стать симметричным" << endl;
			}
		}
		break;
		system("pause>nul");
		}
	} while (choice != 0);
	return 0;
}