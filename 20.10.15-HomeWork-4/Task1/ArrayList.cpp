#include "ArrayList.h"

ArrayList::ArrayList()
{
	data = new int[10];
	count = 0;
	capacity = 10;
}
ArrayList::ArrayList(int cap)
{
	data = new int[cap];
	count = 0;
	capacity = cap;
}
ArrayList::~ArrayList()
{
	delete[] data;
}
void expand(int*& data, int& capacity)
{
	int* newData = new int[capacity * 2];
	for (int i = 0; i < capacity; ++i)
	{
		newData[i] = data[i];
	}
	delete[] data;
	data = newData;
	capacity *= 2;
}
bool ArrayList::add(int element) 
{
	if (count == capacity)
	{
		expand(data, capacity);
	}
	data[count] = element;
	++count;
	return true;
}
bool ArrayList::add(int index, int element)
{
	if (count == capacity)
	{
		expand(data, capacity);
	}
	for(int i = count; i > index; i--)
	{
		data[i] = data[i + 1];
	}
	data[index] = element;
	return true;
}
void  ArrayList::clear()
{
	delete[] data;
}
bool ArrayList::contains(int element)
{
	return true;
}
int ArrayList::get(int index)
{
	return 0;
}
int ArrayList::indexOf(int element)
{

	for (int i = 0; i < count; ++i)
	{
		if (data[i] == element)
		{
			return i;
		}
	}
	return -1;
}
bool ArrayList::isEmpty()
{
	if (count != 0) {
		return 0;
	}
	else return 1;
}
void ArrayList::print()
{
	printf("[%d/%d]{", count, capacity);
	for (int i = 0; i < count; ++i)
	{
		printf("%d%s", data[i], (i == count - 1 ? "" : ", "));
	}
	printf("}\n");
}
bool ArrayList::remove(int index)
{
	return true;
}
int ArrayList::swap(int index1, int index2)
{
	int temp = data[index1];
	data[index1] = data[index2];
	data[index2] = temp;
	return 0;
}