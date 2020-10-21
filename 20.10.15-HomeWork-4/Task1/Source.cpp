#include<iostream>
#include<clocale>
#include<ctime>
#include"ArrayList.h"

using namespace std;

void printMenu()
{
	cout << "����" << endl;
	cout << "0 - ����� �� ���������" << endl;
	cout << "1 - ������� ������ �� �����" << endl;
	cout << "2 - �������� �������" << endl;
	cout << "3 - �������� ������� � �������" << endl;
	cout << "4 - ������� ������� �� �������" << endl;
	cout << "5 - ����� �������" << endl;
	cout << "6 - �������� ��������� ���������" << endl;
	cout << "7 - �������� ��������� ���������, ������� � ��������� �������" << endl;
}

void processChoice(ArrayList& a, int choice)
{
	switch (choice)
	{
	case 1:
	{
		a.print();
	}
	break;
	case 2:
	{
		int element = 0;
		cout << "������� �������\n";
		cin >> element;
		a.add(element);
	}
	break;
	case 3:
	{
		int ind = 0;
		cin >> ind;
		int element;
		cin >> element;
		a.add(ind, element);
	}
	break;
	case 4:
	{
		if (a.isEmpty() != true)
		{
			int index = 0;
			cin >> index;
			a.remove(index);
		}
		else
		{
			cout << "������ ����";
		}
	}
	break;
	case 5:
	{
		if (a.isEmpty() != true)
		{
			int elem = 0;
			cin >> elem;
			a.indexOf(elem);
		}
		else
		{
			cout << "������ ����";
		}
	}
	break;
	case 6:
	{
		cout << "������� ��������� ��������?\n";
		int c = 0;
		cin >> c;
		ArrayList list(c);
		srand(8);
		for (int i = 0; i < c; i++)
		{
			list.add(rand() % 100);
		}
		a.addAll(list);
	}
	break;
	case 7:
	{
		cout << "������� ��������� ��������?\n";
		int c = 0;
		cin >> c;

		cout << "� ����� ������� ���������?\n";
		int ind = 0;
		cin >> ind;
		
		ArrayList list(c);
		for (int i = 0; i < c; i++)
		{
			list.add(rand() % 100);
		}
		a.addAll(ind, list);
	}
	break;
	}
}

int main()
{
	srand(8);
	setlocale(LC_ALL, "Russian");
	ArrayList a;

	int choice = 0;
	do
	{
		system("cls");
		printMenu();
		cin >> choice;
		processChoice(a, choice);
		system("pause>nul");
	} while (choice != 0);

	return 0;
}
