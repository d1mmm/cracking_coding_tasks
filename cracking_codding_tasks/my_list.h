#pragma once
#include <iostream>
#include <optional>
#include <assert.h>

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
    list(std::initializer_list<T> initializer_list);
    void push_back(const T& data);
    void push_back(const int* dataPtr);
    void pop_back();
    void push_front(const T& data);
    void pop_front();
    void print();
    size_t get_size() { return size; };
    void delete_duplicates();
    void remove(const T& val);
    void split(int& x);
    static list<T> sum_lists(list<T>& l_first, list<T>& l_second);
    bool is_palindrom();
    static int* intersection(list<T>& l_first, list<T>& l_second);
    std::optional<T> find_data_from_tail(const T& num);
    std::optional<int*> find_node_from_tail(const T& num);
    T& operator [](const int& el);
};

template<typename T>
inline list<T>::list(std::initializer_list<T> initializer_list)
{
    for (auto it = initializer_list.begin(); it != initializer_list.end(); ++it)
    {
        push_back(*it);
    }
}

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
inline void list<T>::push_back(const int* dataPtr)
{
    Node<T>* newItem =(Node<T>*)dataPtr;
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
    assert(head != nullptr);
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
                if (currentN->next != nullptr)
                {
                    currentN->next->prev = currentN->prev;
                }
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
    if (val == head->data && val == tail->data)
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
inline void list<T>::split(int& x)
{
    Node<T>* current = head;
    while (current->next != nullptr)
    {
        if (current->next->data < x)
        {
            if (current->next->next == nullptr)
            {
                break;
            }
            push_front(current->next->data);
            Node<T>* item = current->next;
            current->next = current->next->next;
            current->next->prev = current;
            delete item;
        }
        current = current->next;
    }

    if (tail->data < x)
    {
        push_front(tail->data);
        pop_back();
    }
}

template<typename T>
inline list<T> list<T>::sum_lists(list<T>& l_first, list<T>& l_second)
{
    list<T> res;
    int dec = 0;
    while (l_first.head != nullptr && l_second.head != nullptr)
    {
        int data = l_first.head->data + l_second.head->data + dec;
        int unit = 0;
        if (data > 10)
        {
            dec = 1;
            unit = data - 10;
            res.push_front(unit);
            if (l_first.head->next == nullptr && l_second.head->next == nullptr)
            {
                res.push_front(dec);
            }
        }
        else
        {
            res.push_front(data);
        }
        l_first.head = l_first.head->next;
        l_second.head = l_second.head->next;
    }

    if (l_first.head != nullptr)
    {
        res.push_front(l_first.head->data + dec);
    }
    else
    {
        res.push_front(l_second.head->data + dec);
    }

    return res;
}

template<typename T>
inline bool list<T>::is_palindrom()
{
    Node<T>* currentH = head; 
    Node<T>* currentT = tail;
    while (currentH != nullptr)
    {
        if (currentH->data != currentT->data)
        {
            return false;
        }
        currentH = currentH->next;
        currentT = currentT->prev;
    }
    return true;
}

template<typename T>
inline int* list<T>::intersection(list<T>& l_first, list<T>& l_second)
{
    Node<T>* currentFirst = l_first.head;
    while (currentFirst != nullptr)
    {
        Node<T>* currentSecond = l_second.head;
        while (currentSecond != nullptr)
        {
            if (currentFirst == currentSecond)
            {
                return (int*)currentFirst;
            }
            currentSecond = currentSecond->next;
        }
        currentFirst = currentFirst->next;
    }
    return nullptr;
}

template<typename T>
inline std::optional<T> list<T>::find_data_from_tail(const T& num)
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
inline std::optional<int*> list<T>::find_node_from_tail(const T& num)
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
            return reinterpret_cast<int*>(current);
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
