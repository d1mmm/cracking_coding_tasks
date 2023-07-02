#pragma once
#include <iostream>
#include <optional>
#include <assert.h>

template<typename T>
class list
{
private:
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
    list(std::initializer_list<int> initializer_list);
    void push_back(const T& data);
    void push_back(list<T>::Node<T>* dataPtr);
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
    static list<T>::Node<T>* intersection(list<T>& l_first, list<T>& l_second);
    std::optional<T> find_data_from_tail(const T& num);
    list<T>::Node<T>* find_node_from_tail(const T& num);
    T& operator [](const int& el);
    void create_ring_list(const int& num);
    list<T>::Node<T>* get_ring_node();
    bool is_ring_list(list<T>::Node<T>* node);
};


template<typename T>
inline list<T>::list(std::initializer_list<int> initializer_list)
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
inline void list<T>::push_back(list<T>::Node<T>* dataPtr)
{
    if (head == nullptr && tail == nullptr)
    {
        tail = dataPtr;
        head = tail;
    }
    else
    {
        Node<T>* current = tail;
        tail->next = dataPtr;
        tail = dataPtr;
        tail->prev = current;
    }
    ++size;
    /*Node<T>* curr = dataPtr;
    while (curr != nullptr)
    {
        ++size;
        curr = curr->next;
    }*/
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
    while (current != nullptr)
    {
        std::cout << current->data << std::endl;
        current = current->next;
    }
    std::cout << std::endl;
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

    if (val == head->data)
    {
        pop_front();
        --size;
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
inline list<T>::Node<T>* list<T>::intersection(list<T>& l_first, list<T>& l_second)
{
    Node<T>* currentFirst = l_first.head;
    Node<T>* currentSecond = l_second.head;
    int count = 0, i = 0;

    if (l_first.size > l_second.size)
    {
        count = l_first.size - l_second.size;
        while (i != count)
        {
            currentFirst = currentFirst->next;
            ++i;
        }
    }
    else
    {
        count = l_second.size - l_first.size;
        while (i != count)
        {
            currentSecond = currentSecond->next;
            ++i;
        }
    }

    while (currentFirst != nullptr)
    {
        if (currentFirst == currentSecond)
        {
            return currentFirst;
        }
        currentSecond = currentSecond->next;
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
inline list<T>::Node<T>* list<T>::find_node_from_tail(const T& num)
{
    if (num > size)
    {
        return nullptr;
    }

    Node<T>* current = tail;
    int count = 1;
    while (current->prev != nullptr)
    {
        if (num == count)
        {
            return current;
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

template<typename T>
inline void list<T>::create_ring_list(const int& num)
{
    int count = 1;
    Node<T>* currentH = head;
    Node<T>* ring = nullptr;
    while (currentH != nullptr)
    {
        if (count == num)
        {
            ring = currentH;
            break;
        }
        currentH = currentH->next;
        ++count;
    }
    Node<T>* currentT = tail;
    tail->next = ring;
    tail = ring;
    tail->prev = currentT;
    ++size;
}

template<typename T>
inline list<T>::Node<T>* list<T>::get_ring_node()
{
    Node<T>* currentH = head;
    Node<T>* currentT = tail;

    if (currentH == currentT)
    {
        return currentH;
    }
    
    while (currentH->next != currentT->prev)
    {
        currentH->next = currentH->next->next;
        currentT->prev = currentT->prev->prev;
    }

    if (currentH->next == currentT->prev)
    {
        return currentH->next;
    }
    return nullptr;
}

template<typename T>
inline bool list<T>::is_ring_list(list<T>::Node<T>* node)
{
    Node<T>* current = node;
    while (current != nullptr)
    {

        current = current->next;
    }

    return false;
}

