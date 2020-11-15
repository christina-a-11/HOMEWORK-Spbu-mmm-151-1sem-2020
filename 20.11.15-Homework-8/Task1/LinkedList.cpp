#include "LinkedList.h"
LinkedList::LinkedList(const LinkedList& list)
{
	tail = head = nullptr;
	count = 0;

	Node* temp = list.head;
	while (temp != nullptr)
	{
		addToTail(temp->data);
		temp = temp->next;
	}
}
LinkedList::~LinkedList()
{
	Node* temp = head;
	while (temp != nullptr)
	{
		Node* node = temp;
		temp = temp->next;
		delete node;
	}
}

bool LinkedList::indexValid(int index)
{
	return index >= 0 && index < count ;
}

int LinkedList::length()
{
	return count;
}

bool LinkedList::addToHead(int element)
{
	if (head == nullptr)
	{
		head = tail = new Node(element);
		count = 1;
	}
	else
	{
		head = new Node(element, head);
		count++;
	}
	return true;
}

bool LinkedList::addToTail(int element)
{
	if (tail == nullptr)
	{
	    tail = head = new Node(element);
		count = 1;
	}
	else
	{
		(*tail).next = new Node(element);
		tail = (*tail).next;
		count++;
	}
	return true;
}

bool LinkedList::add(int index, int element)
{
		if (index == 0)
		{
			return addToHead(element);
		}
		else if (index == count)
		{
			return addToTail(element);
		}
		else if (!indexValid(index))
		{
			return false;
		}
		else
		{
			Node* temp = head;
			while (index > 1)
			{
				temp = (*temp).next;
				--index;
			}
			(*temp).next = new Node(element, (*temp).next);
			++count;
			return true;
		}
		
}

int LinkedList::get(int index)
{
	if (!indexValid(index))
	{
		return -1;
	}
	if (index == 0)
	{
		return (*head).data;
	}
	if (index == count - 1)
	{
		return (*tail).data;
	}
	Node* temp = head;
	while (index > 0)
	{
		temp = (*temp).next;
		--index;
	}
	return (*temp).data;
}

bool LinkedList::set(int index, int element)
{
	if (!indexValid(index))
	{
		return false;
	}
	if (index == 0)
	{
		 (*head).data = element;
		 return true;
	}
	if (index == count - 1)
	{
		 (*tail).data = element;
		 return true;
	}
	Node* temp = head;
	while (index > 0)
	{
		temp = (*temp).next;
		--index;
	}
	(*temp).data = element;
	return true;
}

int& LinkedList::operator[](int index)
{
	if (head == nullptr)
	{
		addToHead(0);
		return head->data;
	}
	if (index <= 0)
	{
		return head->data;
	}
	if (index >= count)
	{
		addToTail(0);
		return tail->data;
	}
	if (index == count - 1)
	{
		return tail->data;
	}
	Node* temp = head;
	for (int i = 0; i < index; ++i)
	{
		temp = temp->next;
	}
	return temp->data;
}

void LinkedList::operator+=(int element)
{
	addToTail(element);
}

int LinkedList::extractHead()
{
	if (head != nullptr)
	{
		int del = (*head).data;
		Node* temp = head;
		head = (*temp).next;
		count--;
		return del;
	}
	else
	{
		return - 1;
	}
}

int LinkedList::extractTail()
{
	if (tail != nullptr)
	{
		if (count == 1) {
			head = tail = nullptr;
			count = 0;
		}
		else
		{
			int del = (*tail).data;
			Node* temp = head;
			for (int i = 0; i < count - 2; i++)
			{
				temp = (*temp).next;
			}
			tail = (*temp).next;
			(*temp).next = nullptr;
			count--;
			return del;
		}
	}
	else
	{
		return -1;
	}
	
}

int LinkedList::extract(int index)
{
	if (head != nullptr)
	{
		if (!indexValid(index))
		{
			return -1;
		}
		else
		{
			if (index == 0)
			{
				return extractHead();
			}
			if (index == count - 1)
			{
				return extractTail();
			}
			else
			{
				int del = 0;
				Node* temp1 = head;
				for (int i = 0; i < index - 2; i++)
				{
					temp1 = (*temp1).next;
				}
				Node* temp2 = (*temp1).next;
				del = (*temp2).data;
				(*temp1).next = (*temp2).next;
				--count;
				return del;
			}
		}
	}
		return -1;
}

void LinkedList::operator-=(int index)
{
	extract(index);
}

LinkedList& LinkedList::operator=(LinkedList& listic)
{
	head = listic.head;
	tail = listic.tail;
	count = listic.count;
	return *this;
}

int LinkedList::indexOf(int element)
{
	Node* temp = head;
	for(int i = 0; i < count; i++)
	{
		if ((*temp).data == element)
		{
			return i;
		}
		temp = (*temp).next;
	}
	return -1;
}

bool LinkedList::contains(int element)
{
	return indexOf(element) > -1 ? true : false;
}

bool LinkedList::swap(int index1, int index2)
{
	if (indexValid(index1) && indexValid(index2) && count > 1)
	{
		if (index1 > index2)
		{
			int temp = index1;
			index1 = index2;
			index2 = temp;
		}
		Node* tmp1 = head;
		Node* tmp2 = head;
		for (int i = 0; i < index1; i++)
		{
			tmp1 = (*tmp1).next;
		}
		for (int i = 0; i < index2; i++)
		{
			tmp2 = (*tmp2).next;
		}
		if (index2 - index1 == 1)
		{
			if (index1 == 0 && index2 == count - 1)
			{
				(*tail).next = head;
				(*head).next = nullptr;
				Node* temp = head;
				head = tail;
				tail = temp;
			}
			else if (index1 == 0)
			{
				Node* temp1 = head;
				head = (*head).next;
				Node* temp2 = (*head).next;
				(*head).next = temp1;
				(*temp1).next = temp2;
            }
			else if (index2 == count - 1)
			{
				Node* temp2 = head;
				for (int i = 0; i < count - 1; i++)
				{
					temp2 = (*temp2).next;
				}
				tail = (*temp2).next;
				temp2 = (*temp2).next;
				(*tail).next = nullptr;
				Node* temp1 = head;
				for (int i = 0; i < count - 2; i++)
				{
					temp1 = (*temp1).next;
				}
				(*temp1).next = temp2;
				(*temp2).next = tail;
			}
			else
			{
			}
		}
		else
		{
			if (index1 == 0 && index2 == count - 1)
			{
				(*tail).next = (*head).next;
				(*head).next = (*head).next;
				(*head).next = nullptr;
				Node* temp2 = head;
				for (int i = 0; i < count; i++)
				{
					temp2 = (*temp2).next;
				}
				(*temp2).next = (*head).next;
				Node* temp = head;
				head = tail;
				tail = temp;
			}
			else if (index1 == 0)
			{
			
			}
			else if (index2 == count - 1)
			{

			}
			else
			{

			}

		}
		return true;
	}
	return false;
}
std::ostream& operator<<(std::ostream& stream, const LinkedList list)
{
	stream << "[" << list.count << "] " << "{";
	if (list.head == nullptr)
	{
		stream << "empty";
	}
	else
	{
		Node* temp = list.head;
		while (temp != nullptr)
		{
			stream << (*temp).data;
			temp = (*temp).next;
			if (temp != nullptr)
			{
				stream << ", ";
			}
		}
	}
	stream << "}";
	return stream;
};
