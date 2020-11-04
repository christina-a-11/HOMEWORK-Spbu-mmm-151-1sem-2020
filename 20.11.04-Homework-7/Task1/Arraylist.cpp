#include "ArrayList.h"

ArrayList::ArrayList(const ArrayList& list)
{
	count = list.count;
	capacity = list.capacity;
	data = new int[capacity] {0};
	for (int i = 0; i < count; ++i)
	{
		data[i] = list.data[i];
	}
}

ArrayList:: ~ArrayList()
{
	delete[] data;
};

void ArrayList::expand()
{

	int* newData = new int[capacity * 2];
	for (int i = 0; i < capacity; ++i)
	{
		*(newData + i) = *(data + i);
	}
	delete[] data;
	data = newData;
	capacity *= 2;
};

bool ArrayList::add(int element)
{
	if (count == capacity)
	{
		expand();
	}
	data[count] = element;
	count++;
	return true;
};

bool ArrayList::add(int index, int element)
{
	if (count == capacity)
	{
		expand();
	}
	for (int i = count; i > index; i--)
	{
		*(data + i) = *(data + i - 1);
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
		expand();
	}
	for (int i = 0; i < list.count; i++)
	{
		data[count - 1 + list.count - i] = data[count - 1 - i];
	}
	for (int i = 0; i < list.count; i++, index++)
	{
		*(data + index) = list.data[i];
	}
	return true;
};

void ArrayList::clear()
{
	count = 0;
};

bool ArrayList::contains(int element)
{

	for (int i = 0; i < count; i++)
	{
		if (data[i] == element)
		{
			return true;
		}
	}
	return false;
};

int ArrayList::get(int index)
{
	return index < count&& index >= 0 ? *(data + index) : -1;
};

bool ArrayList::set(int index, int element)
{
	if (index >= 0 && index < count)
	{
		data[index] = element;
		return true;
	}
	return false;
};

int ArrayList::indexOf(int element)
{
	int index = -1;
	for (int i = 0; i < count; i++)
	{
		if (*(data + i) == element)
		{
			index = i;
		}
	}
	return index;
};

bool ArrayList::isEmpty()
{
	return (count == 0);
};

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
			*(data + i) = *(data + i + 1);
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
		tmp = *( data + index1);
		*(data + index1) = *(data + index2);
		*(data + index2) = tmp;
		return true;
	}
	else
	{
		return false;
	}
};

int ArrayList::length()
{
	return count;
}

void ArrayList::operator+=(int item)
{
	add(item);
};

void ArrayList::operator-=(int item)
{
	remove(indexOf(item));
};

ArrayList& ArrayList::operator=(const ArrayList& list)
{
	count = list.count;
	capacity = list.capacity;
	data = new int[capacity] { 0 };
	for (int i = 0; i < count; ++i)
	{
		*(data + i) = list.data[i];
	}
	return *this;
};

ArrayList operator+(const ArrayList& list, int item)
{
	ArrayList result;
	result.count = list.count;
	result.capacity = list.capacity;
	result.data = new int[list.capacity]{ 0 };
	for (int i = 0; i < list.count; ++i)
	{
		result.data[i] = list.data[i];
	}
	result.add(item);
	return result;
};

ArrayList operator+(int item, const ArrayList& list)
{
	ArrayList result;
	result.count = list.count;
	result.capacity = list.capacity;
	result.data = new int[list.capacity]{ 0 };
	for (int i = 0; i < list.count; ++i)
	{
		result.data[i] = list.data[i];
	}
	result.add(0, item);
	return result;
};

ArrayList operator+(const ArrayList& list1, const ArrayList& list2)
{
	ArrayList result;
	result.count = list1.count + list2.count;
	result.capacity = list1.capacity + list2.capacity;
	result.data = new int[result.capacity]{ 0 };
	for (int i = 0; i < list1.count; ++i)
	{
		result.data[i] = list1.data[i];
	}
	for (int i = list1.count; i < result.count; ++i)
	{
		result.data[i] = list2.data[i - list1.count];
	}
	return result;
};

ArrayList operator-(const ArrayList& list, int item)
{
	ArrayList result;
	result.count = list.count;
	result.capacity = list.capacity;
	result.data = new int[list.capacity]{ 0 };
	for (int i = 0; i < list.count; ++i)
	{
		result.data[i] = list.data[i];
	}
	result.remove(result.indexOf(item));
	return result;
}

ArrayList operator-(int item, const ArrayList& list)
{
	ArrayList result;
	result.count = list.count;
	result.capacity = list.capacity;
	result.data = new int[list.capacity]{ 0 };
	for (int i = 0; i < list.count; ++i)
	{
		result.data[i] = list.data[i];
	}
	result.remove(result.indexOf(item));
	return result;
};

std::ostream& operator<<(std::ostream & stream, const ArrayList& list)
{
	for (int i = 0; i < list.count; ++i)
	{
		stream << list.data[i] << " ";
	}
	return stream;
};
