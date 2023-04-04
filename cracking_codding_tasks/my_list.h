#pragma once
#include <iostream>
#include <optional>

template<typename T>
class list
{
	template <typename T>
	class Node
	{
	public:
		Node(T data = T()) : next(nullptr), prev(nullptr), data(data) {}
		T data;
		Node* next;
		Node* prev;
	};

private:
	Node<T>* head;
	Node<T>* tail;
	size_t size;
public:
	list() : head(nullptr), tail(nullptr), size(0) {}
	void push_back(const T& data);
	void pop_back();
	void push_front(const T& data);
	void pop_front();
	void print();
	size_t get_size() { return size; };
	void delete_duplicates();
	void remove(const T& val);
	std::optional<T> find(const T& num);
	T& operator [](const int& el);
};

template<typename T>
inline void list<T>::push_back(const T& data)
{
	Node<T>* newItem = new Node<T>(data);
	if (head == nullptr && tail == nullptr)
	{
		tail = newItem;
		head = tail;
	}
	else
	{
		Node<T>* current = tail;
		tail->next = newItem;
		tail = newItem;
		tail->prev = current;
	}
	newItem = nullptr;
	delete newItem;
	++size;
}

template<typename T>
inline void list<T>::pop_back()
{
	tail = tail->prev;
	tail->next = nullptr;
	Node<T>* current = tail;
	tail->prev = current->prev;
	--size;
}

template<typename T>
inline void list<T>::push_front(const T& data)
{
	Node<T>* newItem = new Node<T>(data);
	if (head == nullptr && tail == nullptr)
	{
		head = newItem;
		tail = head;
	}
	else
	{
		Node<T>* current = head;
		head->prev = newItem;
		head = newItem;
		head->next = current;
	}
	newItem = nullptr;
	delete newItem;
	++size;
}

template<typename T>
inline void list<T>::pop_front()
{
	head = head->next;
	Node<T>* current = head;
	head->next = current->next;
	head->prev = nullptr;
}

template<typename T>
inline void list<T>::print()
{
	Node<T>* current = head;
	while (current->next != nullptr)
	{
		std::cout << current->data << std::endl;
		current = current->next;
	}
	std::cout << current->data << std::endl << std::endl;
}

template<typename T>
inline void list<T>::delete_duplicates()
{
	Node<T>* current = head;
	while (current != nullptr)
	{
		Node<T>* currentN = current;
		while (currentN->next != nullptr)
		{
			if (current->data == currentN->next->data)
			{
				Node<T>* node = currentN->next;
				currentN->next = currentN->next->next;
				tail = currentN;
				delete node;
				--size;
			}
			else
			{
				currentN = currentN->next;
			}
		}
		current = current->next;
	}
}

template<typename T>
inline void list<T>::remove(const T& val)
{
	if (val == head->data || val == tail->data)
	{
		return;
	}

	Node<T>* current = head;
	while (current->next != nullptr)
	{
		if (current->next->data == val)
		{
			Node<T>* itemDel = current->next;
			current->next = current->next->next;
			current->next->prev = current;
			delete itemDel;
			--size;
		}
		current = current->next;
	}
}

template<typename T>
inline std::optional<T> list<T>::find(const T& num)
{
	if (num > size)
	{
		return std::nullopt;
	}

	Node<T>* current = tail;
	int count = 1;
	while (current->prev != nullptr)
	{
		if (num == count)
		{
			return current->data;
		}
		++count;
		current = current->prev;
	}
}

template<typename T>
inline T& list<T>::operator[](const int& el)
{
	int count = 0;
	Node<T>* current = head;
	while (current->next != nullptr)
	{
		if (count == el)
		{
			return current->data;
		}
		current = current->next;
		++count;
	}
}
