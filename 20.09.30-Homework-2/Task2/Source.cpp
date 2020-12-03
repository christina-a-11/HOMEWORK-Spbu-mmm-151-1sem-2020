#include<iostream>
#include<clocale>

using namespace std;

void printMenu()
{
    cout << "MENU" << endl;
    cout << "0 - выход из программы" << endl;
    cout << "1 - добавить в массив n случайных чисел в промежутке от a до b" << endl;
    cout << "2 - развернуть массив" << endl;
    cout << "3 - поменять элементы массива местами в парах.Если число элементов нечетно, последний элемент остается на своем месте." << endl;
    cout << "4 - циклический сдвиг вправо на 1" << endl;
    cout << "5 - развернуть две половинки массива. n - индекс элемента, разделяющего половинки." << endl;
    cout << "6 - вывести массив" << endl;
}

void expandArray(int*& arr, int& cap)
{
    int* temp = new int[cap * 2];
    for (int i = 0; i < cap; ++i)
    {
        temp[i] = arr[i];
    }
    delete[] arr;
    arr = temp;
    cap *= 2;
}

void addElement(int*& arr, int& count, int& cap, int element)
{
    if (count == cap)
    {
        expandArray(arr, cap);
    }
    arr[count] = element;
    count++;
}

void addRandomElements(int*& arr, int& count, int& cap, int n, int min, int max)
{
    srand(8);
    for (int i = 0; i < n; i++)
    {
        addElement(arr, count, cap, min + rand() % (max - min + 1));
    }
}

void printArray(int* arr, int count)
{
    if (count == 0)
    {
        cout << "{empty}" << endl;
    }
    else
    {
        cout << "{";
        for (int i = 0; i < count; i++)
        {
            cout << *(arr + i) << (i < count - 1 ? ", " : "");
        }
        cout << "}" << endl;
    }
}

void reverseArray(int* arr, int count)
{
    for (int i = 0; i < count / 2; i++)
    {
        int tmp = arr[i];
        arr[i] = arr[count - 1 - i];
        arr[count - 1 - i] = tmp;
    }
}

void swapPairsArray(int* arr, int count)
{
 
    for (int i = 1; i < count; i += 2)
    {
        int tmp;
        tmp = *(arr + i);
        *(arr + i) = *(arr + i - 1);
        *(arr + i - 1) = tmp;
    }
}

void shiftArray(int* arr, int count)
{
    int tmp = *(arr + count - 1);
    for (int i = count - 1; i > 0; i--)
    {
        *(arr + i) = *(arr + i - 1);
    }
    *(arr) = tmp;
}

void shiftPartsArray(int* arr, int count, int n)
{
    if (n < 0 || n >= count)
    {
        ;
    }
    else  if (n == 0 || n == count - 1)
    {
        reverseArray(arr, count);
    }
    else
    {
        reverseArray(arr, n);
        reverseArray(arr + n + 1, count - n - 1);
    }
}

void processChoice(int*& arr, int& count, int& cap, int choice)
{
    switch (choice)
    {
    case 1:
    {
        int n = 0;
        cin >> n;
        int a = 0;
        int b = 0;
        cin >> a >> b;
        if (a > b) {
            int tmp = a;
            a = b;
            b = tmp;
        }
        addRandomElements(arr, count, cap, n, a, b);
    }
        break;
    case 2:
    {
        reverseArray(arr, count);
    }
        break;
    case 3:
    {
        swapPairsArray(arr, count - 1);
    }
        break;
    case 4:
    {
        shiftArray(arr, count);
    }
        break;
    case 5:
    {
        int n = 0;
        cin >> n;
        shiftPartsArray(arr, count, n);
    }
    break;
    case 6:
    {
        printArray(arr, count);
    }
        break;
    }
}



int main()
{
    setlocale(LC_ALL, "Russian");
    int choice = 0;
    int capacity = 10;
    int count = 0;
    int* arr = new int[capacity];
    do
    {
        system("cls");
        printMenu();
        cin >> choice;
        processChoice(arr, count, capacity, choice);
        system("pause");
    } while (choice != 0);
    delete[] arr;
    return 0;
}
