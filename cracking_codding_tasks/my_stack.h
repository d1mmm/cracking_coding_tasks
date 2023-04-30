#pragma once

template<typename T>
class stack
{
    template<typename K>
    class Node
    {
    public:
        Node(K data = K()) : next(nullptr), data(data) {}
        Node* next;
        K data;
    };
    
private:
    Node<T>* top;
    int size;
public:
    stack() : top(nullptr), size(0) {}
    stack(std::initializer_list<T> list);
    void push(const T& item);
    void pop();
    int get_size();
    T& operator[](const int& el);
    T& peek();
    bool is_Empty();
};

template <typename T>
inline stack<T>::stack(std::initializer_list<T> list)
{
    for (auto it = list.begin(); it != list.end(); ++it)
    {
        push(*it);
    }
}

template <typename T>
inline void stack<T>::push(const T &item)
{
    Node<T>* new_item = new Node<T>(item);
    new_item->next = top;
    top = new_item;
    new_item = nullptr;
    delete new_item;
    ++size;
}

template<typename T>
inline void stack<T>::pop()
{
    if(is_Empty())
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

template <typename T>
inline T &stack<T>::operator[](const int &el)
{
    Node<T>* current = top;
    int count = 0;
    while(current!=nullptr)
    {
        if(count == el)
        {
            return current->data;
        }
        ++count;
        current = current->next;
    }
}

template <typename T>
inline T &stack<T>::peek()
{
   return top->data;
}

template <typename T>
inline bool stack<T>::is_Empty()
{
    if(top == nullptr)
    {
        return true;
    }
    return false;
}
