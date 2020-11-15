/*продемонстрировать работу всех функций
показать, что все функции и операторы корректно работают:
1). С пустым списком.
2). Со списком из 1 элемента.
3). Со списком из нескольких элементов.
*/
#include <iostream>
#include"LinkedList.h"

using namespace std;

int main()
{
	LinkedList list;
	cout << list << endl;
	list.addToHead(5);
	cout << list << endl;
	list.addToHead(6);
	cout << list << endl;
	list.addToTail(9);
	list.add(0, 0);
	list.add(4, 4);
	cout << list << endl;
	cout << list.get(0) << endl;
	cout << list.get(1) << endl;
	cout << list.get(-5) << endl;
	cout << list.get(100) << endl;
	cout << list.get(4) << endl;
	list.set(0, -5);
	list.set(4, -80);
	list.set(90, 90);
	cout << list << endl;
	list[3] = 33;
	cout << list << endl;
	cout << "list[3] = " << list[3] << endl << endl;
	
	cout << "List: " << list << endl;
	cout << "delete element[0]" << endl;
	list.extract(0);
	cout << list << endl;
	cout << "delete element[1]" << endl;
	list.extract(1);
	cout << list << endl;
	cout << "delete element[2]" << endl;
	list.extract(2);
	cout << list << endl;
	cout << "delete element[80]" << endl;
	list.extract(80);
	cout << list << endl;
	cout << "delete element[0]" << endl;
	list.extractHead();
	cout << list << endl;
	cout << "delete element[count - 1]" << endl;
	list.extractTail();
	cout << list << endl;
	LinkedList listic;
	listic.addToHead(1);
	listic.addToHead(-567);
	listic.addToHead(6732);
	listic.addToHead(0);
	list = listic;
	cout << "listic: " << listic << endl;
	cout << "list: ";
	cout << list << endl;
	list[0] = 0;
	list[1] = 1;
	list[2] = 2;
	list[3] = 3;
	cout << list << endl;
	system("pause>nul");
	return 0;
}