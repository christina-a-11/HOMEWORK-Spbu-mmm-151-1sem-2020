#include "ArrayList.h"

ArrayList:: ~ArrayList()
{
	delete[] data;
	delete[] str;
};

void ArrayList::expand()
{

	int* newData = new int[capacity * 2];
	for (int i = 0; i < capacity; ++i)
	{
		newData[i] = data[i];
	}
	delete[] data;
	data = newData;
	capacity *= 2;
};

int ArrayList::numLength(int number)
{   
	int result = 1;

	if (number < 0)
	{
		number *= -1;
		++result;
	}
	
	while (number > 9)
	{
		number /= 10;
		result++;
	}
	return result;
};

void ArrayList::addSymbolToStr(int& index, char symbol)
{
	str[index] = symbol;
	++index;
};

void ArrayList::addNumberToStr(int& index, int number)
{
	int length = numLength(number);
	for (int i = 0; i < length; ++i)
	{
		int digit = number % 10;
		str[index + length - 1 - i] = '0' + digit;
		number /= 10;
	}
	index += length;
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
	while (capacity < count + list.count)
	{
		expand();
	}
	int m = 0;
	for (int i = count - 1; i > index - 1; --i)
	{
		data[list.count + count - index - m] = data[i];
		++m;
	}
	for (int i = index; i < list.count; i++)
	{
		add(i, list.get(i));
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
	if (index >= 0 && index < count)
	{
		return data[index];

	}
	return -1;
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
	for (int i = 0; i < count; i++)
	{
		if (data[i] == element)
		{
			return i;
		}
	}
	return -1;
};

bool ArrayList::isEmpty()
{
	return (count == 0);
};
//  [count/capacity] {el1, el2, el3, ...}
char* ArrayList::toString()
{
	int lenght = 8 + numLength(count) + numLength(capacity) ;
	for (int i = 0; i < count; ++i)
	{
		lenght += numLength(data[count]) + 2;

	}
	lenght -= 2;
	str = new char[lenght];
	int index = 0;
	addSymbolToStr(index, '[');
	addNumberToStr(index, count);
	addSymbolToStr(index, '/');
	addNumberToStr(index, capacity);
	addSymbolToStr(index, ']');
	addSymbolToStr(index, ' ');
	addSymbolToStr(index, '{');
	for (int i = 0; i < count; i++)
	{
		if (data[i] >= 0)
		{
			addNumberToStr(index, data[i]);
			if (i != count - 1)
			{
				addSymbolToStr(index, ',');
				addSymbolToStr(index, ' ');
			}
		}
		else if (data[i] < 0)
		{

			addSymbolToStr(index,'-');
			addNumberToStr(index, data[i] * (-1));
			if (i != count - 1)
			{
				addSymbolToStr(index, ',');
				addSymbolToStr(index, ' ');
			}

		}
	}
	addSymbolToStr(index, '}');
	addSymbolToStr(index, '\0');
	return str;
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

int ArrayList::length()
{
	return count;
};
