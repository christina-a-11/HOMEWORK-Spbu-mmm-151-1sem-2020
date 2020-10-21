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
		expand(data,capacity);
	}
	for (int i = count; i > index; i--)
	{
		data[i] = data[i - 1];
	}
	data[index] = element;
	return true;
};
bool ArrayList::addAll(ArrayList& list)
{
	for (int i = 0; i < list.count; ++i)
	{
		add(list.get(i));
	}
	return list.count != 0;
};
bool ArrayList::addAll(int index, ArrayList& list)
{
	if (index > count)
	{
		return false;
	}
	while (capacity < count + list.count)
	{
		expand(data,capacity);
	}
	for (int i = 0; i < list.count; i++)
	{
		data[count - 1 + list.count - i] = data[count - 1 - i];
	}
	for (int i = 0; i < list.count; i++, index++)
	{
		data[index] = list.data[i];
	}
	return true;
};
void  ArrayList::clear()
{
	count = 0;
}
bool ArrayList::contains(int element)
{
	for (int i = 0; i < count; i++)
	{
		if (element == data[i])
		{
			return true;
		}
	}
	return false;
}
int ArrayList::get(int index)
{
	if (index >= 0 && index < count)
	{
		return data[index];

	}
	return -1;
};
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
	return (count == 0);
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
	if (index == count - 1)
	{
		count--;
		return true;
	}
	else if (index < count - 1)
	{
		for (int i = index; i < count - 1; i++)
		{
			data[i] = data[i + 1];
		}
		--count;
		return true;
	}
	else
	{
		return false;
	}
};
bool ArrayList::swap(int index1, int index2)
{
	if (index1 >= 0 && index1 < count && index2 >= 0 && index2 < count)
	{
		int tmp = 0;
		tmp = data[index1];
		data[index1] = data[index2];
		data[index2] = tmp;
		return true;
	}
	else
	{
		return false;
	}
};