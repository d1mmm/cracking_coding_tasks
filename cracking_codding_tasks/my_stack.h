#pragma once
#include <optional>

template<typename T>
class stack
{
    template<typename T>
    class Node
    {
    public:
        Node(const T& data = T()) : next(nullptr), data(data) {}
        Node(T&& data = T()) : next(nullptr), data(std::move(data)) {}
        Node* next;
        T data;
    };

private:
    Node<T>* top;
    int size;
    T min_el;
public:
    stack() : top(nullptr), size(0), min_el(T()) {}
    ~stack();
    void push(const T& item);
    void push(T&& item);
    void pop();
    int get_size();
    T& min();
    T& operator[](const int& el);
    std::optional<T> peek();
    bool is_Empty();
    void clear();
    void popAt(const int& value);
    void sort();
};

template<typename T>
inline stack<T>::~stack()
{
    clear();
}

template <typename T>
inline void stack<T>::push(const T& item)
{
    Node<T>* new_item = new Node<T>(item);
    new_item->next = top;
    top = new_item;
    if (top->next == nullptr)
    {
        min_el = top->data;
    }
    if (item < min_el)
    {
        min_el = item;
    }
    new_item = nullptr;
    delete new_item;
    ++size;
}

template<typename T>
inline void stack<T>::push(T&& item)
{
    Node<T>* new_item = new Node<T>(std::move(item));
    new_item->next = top;
    top = new_item;
    if (top->next == nullptr)
    {
        min_el = top->data;
    }
    if (item < min_el)
    {
        min_el = item;
    }
    new_item = nullptr;
    delete new_item;
    ++size;
}

template<typename T>
inline void stack<T>::pop()
{
    if (is_Empty())
    {
        return;
    }
    Node<T>* current = top;
    top = top->next;
    current = nullptr;
    delete current;
    --size;
}

template <typename T>
inline int stack<T>::get_size()
{
    return size;
}

template<typename T>
inline T& stack<T>::min()
{
    return min_el;
}

template <typename T>
inline T& stack<T>::operator[](const int& el)
{
    Node<T>* current = top;
    int count = 0;
    while (current != nullptr)
    {
        if (count == el)
        {
            return current->data;
        }
        ++count;
        current = current->next;
    }
}

template <typename T>
inline std::optional<T> stack<T>::peek()
{
    if (is_Empty())
    {
        return std::nullopt;
    }
    return top->data;
}

template <typename T>
inline bool stack<T>::is_Empty()
{
    if (top == nullptr)
    {
        return true;
    }
    return false;
}

template<typename T>
inline void stack<T>::clear()
{
    top = nullptr;
    size = 0;
    min_el = 0;
    delete top;
}

template<typename T>
inline void stack<T>::popAt(const int& value)
{
    if (value == top->data)
    {
        pop();
        return;
    }
    Node<T>* current = top;
    while (current->next != nullptr)
    {
        if (current->next->data == value)
        {
            Node<T>* itemDel = current->next;
            current->next = current->next->next;
            itemDel = nullptr;
            delete itemDel;
            --size;
            break;
        }
        current = current->next;
    }
}

template<typename T>
inline void stack<T>::sort()
{
    const auto temp_size = size;
    stack<T> temp_st;

    while (temp_st.get_size() != temp_size)
    {
        Node<T>* current = top->next;
        T max_data = top->data;
        while (current != nullptr)
        {
            if (max_data < current->data)
            {
                max_data = current->data;
            }
            current = current->next;
        }
        temp_st.push(max_data);
        popAt(max_data);
    }

    clear();

    for (int i = temp_st.get_size(); i > 0; --i)
    {
        push(temp_st[i]);
    }
}
