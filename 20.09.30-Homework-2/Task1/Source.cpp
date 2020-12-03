#include <iostream>

using namespace std;

void printMenu() {
    cout << "MENU" << endl;
    cout << "0 - exit the program" << endl;
    cout << "1 - add number to array" << endl;
    cout << "2 - print array" << endl;
    cout << "3 - find the index of the max element of on array" << endl;
    cout << "4 - find the number of the min element of on array" << endl;
    cout << "5 - alculate the sun of yhe elements" << endl;
    cout << "6 - print the array in reverse order" << endl;
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

void reversePrintArray(int* arr, int count)
{
    if (count == 0)
    {
        cout << "{empty}";
    }
    else
    {
        cout << "{";
        for (int i = count - 1; i >= 0; i--)
        {
            cout << *(arr + i) << (i > 0 ? ", " : "");
        }
        cout << "}" << endl;
    }
}

int maxIndex(int* arr, int count)
{
    if (count == 0)
    {
        return -1;
    }
    int max0 = *(arr);
    int k = 0;
    for (int i = 0; i < count; i++)
    {
        if (*(arr + i) > max0)
        {
            max0 = *(arr + i);
            k = i;
        }
    }
    return k;
}

int minElement(int* arr, int count)
{
    if (count == 0)
    {
        return -1;
    }
    int min0 = *(arr);
    for (int i = 0; i < count; i++)
    {
        if (*(arr + i) < min0)
        {
            min0 = *(arr + i);
        }
    }
    return min0;
}

int sum(int* arr, int count)
{
    int sum = 0;
    for (int i = 0; i < count; i++)
    {
        sum += *(arr + i);
    }
    return sum;
}

void processChoice(int*& arr, int& count, int& cap, int choice)
{
    switch (choice)
    {
    case 1:
    {
        int element = 0;
        cin >> element;
        addElement(arr, count, cap, element);
    }
        break;
    case 2:
    {
        printArray(arr, count);
    }
        break;
    case 3:
    {
        cout << maxIndex(arr, count);
    }
        break;
    case 4:
    {
       cout << minElement(arr, count);
    }
        break;
    case 5:
    {
       cout << sum(arr, count);
    }
        break;
    case 6:
    {
        reversePrintArray(arr, count);
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
