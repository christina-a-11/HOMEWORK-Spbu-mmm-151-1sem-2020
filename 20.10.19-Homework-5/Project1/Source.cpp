#include <iostream>
#include "ArrayList.h"

using namespace std;

void printMenu()
{
	cout << "����� ������ ����� ������?\n";
	cout << "1).�������� � ������ 10 ��������� ������������� ���������� ����� � ������� ������\n";
	cout << "2).�������� � ������ 10 ��������� ������������� ���������� ����� � ������� ������\n";
	cout << "3).�������� ������� ������ ����������� � ��������� ������������ ������� � ������� ������\n";
	cout << "4).���������� ��� �������� ������� � ������� ������.\n";
	cout << "5).�������� ������ ������������� ������� ������� �� 0.\n";
}

int main()
{
	setlocale(LC_ALL, "Russian");
	ArrayList are;
	int choice = 0;
	while (1)
	{
		printMenu();
		cin >> choice;
		switch (choice)
		{
		case 0:
			return 0;
		case 1:
		{
			srand(8);
			for (int i = 0; i < 10; i++)
			{
				are.add(10 + rand() % 90);
			}
			cout << are.toString() << endl;

		}
		break;
		case 2:
		{
			srand(8);
			for (int i = 0; i < 10; i++)
			{
				are.add(-1 * (10 + rand() % 90));
			}
			cout << are.toString() << endl;
		}
		break;
		case 3:
		{
			if (are.isEmpty() == false)
			{
				int min = 0; //������ ����� ��� � ���� ���������
				int max = 0;
				for (int i = 0; i < are.length(); i++)
				{
					if (are.get(i) < are.get(min))
					{
						min = i;
					}
					if (are.get(i) >= are.get(max))
					{
						max = i;
					}
				}
				are.swap(min, max);


			}
			cout << are.toString() << endl;
		}
		break;
		case 4:
		{
			srand(8);
			for (int i = 0; i < 171; i++)
			{
				are.swap(i, rand() % are.length());
			}
			cout << are.toString() << endl;
		}
		break;
		case 5:
		{
			for (int i = 0; i < are.length(); i++)
			{
				if (are.get(i) < 0) {
					are.set(i, 0);
				}
			}
			cout << are.toString() << endl;
		}
		break;
		}
		system("pause>nul");
	}
	return 0;
}