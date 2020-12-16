#include<iostream>

using namespace std;

void printMenu()
{
	cout << "МЕНЮ" << endl;
	cout << "0 - Выход из программы" << endl;
	cout << "1 - Ввести несколько элеменетов с клавиатуры" << endl;
	cout << "2 - Добавить в массив n случайных чисел в промежутке от a до b(n, a, b вводится с клавиатуры)" << endl;
	cout << "3 - Вывести массив на экран" << endl;
	cout << "4 - Поиск индекса элемента" << endl;
	cout << "5 - Добавление массив к массиву" << endl;
	cout << "6 - Объединение массивов" << endl;
	cout << "7 - Вставка элемента в массив" << endl;
	cout << "8 - Удаление нескольких подряд идущих элементов массива" << endl;
	cout << "9 - Поиск подпоследовательности" << endl;
}
/// Инициализация массива
int* initArray(int capacity)
{
	int* result = new int[capacity + 2]{ 0 };
	*(result + 1) = capacity;
	result += 2;
	return result;
}

/// Освобождение памяти из-под массива
void deleteArray(int* arr)
{
	delete[](arr - 2);
}

// Расширение массива
void expandArray(int*& arr)
{
	int* temp = initArray(2 * (*(arr - 1)));
	for (int i = 0; i < *(arr - 1); ++i)
	{
		*(temp + i) = *(arr + i);
	}
	*(temp - 2) = *(arr - 2);
	deleteArray(arr);
	arr = temp;
}

//1 - Ввести эл с клавиатуры
void addElement(int*& arr, int element)
{
	if (*(arr - 2) == *(arr - 1))
	{
		expandArray(arr);
	}
	*(arr + *(arr - 2)) = element;
	++(*(arr - 2));

}

// 2 - добавить n элементов
void addRandomElements(int*& arr, int n, int a, int b)
{
	for (int i = 0; i < n; ++i)
	{
		addElement(arr, rand() % (b - a + 1) + a);
	}
}
// 3 - Вывод массива
void printArray(int* arr)
{
	cout << "[" << *(arr - 2) << "/" << *(arr - 1) << "] {";
	for (int i = 0; i < *(arr - 2); ++i)
	{
		cout << *(arr + i) << (i == *(arr - 2) - 1 ? "}\n" : ", ");
	}
}

//4 - поиск индекса эл
int search(int* arr, int element, int start = 0)
{
	for (int i = start; i < *(arr - 1); i++) {
		if (*(arr + i) == element) {
			return i;
		}
	}
	return -1;
} // 5 - Добавление массива элементов.

//5 - добавление к массиву
void add(int*& arr, int* addedArr)
{
	for (int i = 0; i < *(addedArr - 2); i++) {
		addElement(arr, *(addedArr + i))
	}
}
// 6 - Объединение двух массивов в один.
int* unify(int* a, int* b)
{
	int *result = initArray(*(a -2) + *(b - 2));
	int j = 0;
	int k = 0;
	for (int i = 0; i < *(a - 2) +*(b - 2) - 1; i++)
	{
		
		if (i % 2 == 0) 
		{
			addElement(result, *(a + j));
			j++;
        }
		else
		{
			addElement(result, *(b + k));
			k++;
		}
	}
	deleteArray(a);
	deleteArray(b);
	a = result;
	return result;
}
// 7 - Вставка элемента в массив. У вставляемого элемента в итоге должен быть индекс index,  
//все последующие элементы сдвигаются на 1 вправо.
int insert(int*& a, int index, int element)
{
	if (index > * (a - 1)) {
		return -1;
	}
	else {

		addElement(a, *(a + *(a - 1) - 1));
		for (int i = *(a - 1) - 2; i > index; i--) {
			*(a + i) = *(a + i - 1);
		}
		*(a + index) = element;
	}
	return 0;
}
// 8 - удаление цепочки элементов
int deleteGroup(int*& a, int startIndex, int count)
{
	if (startIndex + count > * (a - 2)) {
		return 1;
	}
	else if (startIndex + count == *(a - 2))
	{
		*(a - 2) -= count;
		return 0;

	}
	else {
		int tmp = 0;
		for (int i = startIndex; i < *(a - 2) - count + 1; i++)
		{
			*(a + i) = *(a + startIndex + count + tmp);
			tmp++;
		}
		*(a - 2) -= count;
		return 0;
	}

}
int proverca(int* a, int* b, int k, int l) {
	if (l == *(b - 2))
	{
		return 1;
	}
	else
	{
		if (*(a + k) == *(b + l))
		{
			proverca(a, b, k + 1, l + 1);
		}
		else
		{
			return 0;
		}
	}
}

//9 - Поиск подпоследовательности в массиве
int subSequence(int* a, int* b)
{
	for (int i = 0; i < *(a - 2); i++) {
		if (proverca(a, b, i, 0) == 1)
		{
			return i;
		}
	}
	return -1;
}
void processChoice(int*& arr1, int*& arr2, int choice) {
	switch (choice)
	{
	case 1: 
	{
		int tmp = 0;
		do {
			cin >> tmp;
			addElement(arr1, tmp);
		} while (tmp != 0);
	}
		break;
	case 2:
	{
		int n;
		cin >> n;
		int a, b;
		cin >> a >> b;
		addRandomElements(arr1, n, a, b);
	}
		break;
	case 3: {
		printArray(arr1);
	}
		break;
	case 4:
	{
		int temp = 0;
		cin >> temp;
		cout << search(arr1, temp, 0) << endl;
	}
		break;
	case 5:
	{
		int n = 0;
		cout << "Введите количесво элементов второго массива" << endl;
		cin >> n;
		addRandomElements(arr2, n, 0, 100);
		add(arr1, arr2);
		delete[] arr2;
	}
		break;
	case 6:
	{
		int n = 0;
		cout << "Введите количесво элементов второго массива" << endl;
		cin >> n;
		addRandomElements(arr2, n, 0, 100);
		unify(arr1, arr2);
		delete[] arr2;
	}
		break;
	case 7:
	{
		int index;
		cin >> index;
		int element;
		cin >> element;
		cout << insert(arr1, index, element) << endl;
	}
		break;
	case 8:
	{
		int start = 0;
		cin >> start;
		int count = 0;
		cin >> count;
		cout << deleteGroup(arr1, start, count);
	}
		break;
	case 9:
	{
		int n = 0;
		cout << "Введите длину подпоследоватльности" << endl;
		cin >> n;
		cout << "Введите подпоследовательность";
		for (int i = 0; i < n; i++)
		{
			int temp;
			cin >> temp;
			addElement(arr2, temp);
		}
		cout << subSequence(arr1, arr2) << endl;
	}
		break;
	}
}
int main() {
	srand(8);
	setlocale(LC_ALL, "Russian");
	int* a = initArray(10);
	int* b = initArray(10);

	int choice;
	do {
		printMenu();
			cin >> choice;
			processChoice(a, b, choice);	
	} while (choice != 0);

	deleteArray(a);
	deleteArray(b);

	//system("pause>nul");
	return 0;
}
