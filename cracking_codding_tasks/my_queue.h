#pragma once
#include "my_stack.h"
#include <iostream>

template<typename T>
class queue
{
public:
    queue() : size(0) {}
    void push(const T& el);
    void pop();
    T& operator[](const int& el);
    size_t get_size() { return size; }
private:
    stack<T> st1;
    stack<T> st2;
    size_t size;
};

template<typename T>
inline void queue<T>::push(const T& el)
{
    st1.push(el);
    st2.push(el);

    if (st1.get_size() >= 2)
    {
        st2.clear();
        for (int i = 0; i < st1.get_size(); ++i)
        {
            const auto t = st1[i];
            st2.push(t);
        }
    }    

    ++size;
}

template<typename T>
inline void queue<T>::pop()
{
    st2.pop();
    --size;
}

template<typename T>
inline T& queue<T>::operator[](const int& el)
{
    return st2[el];
}
