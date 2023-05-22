#pragma once
#include "my_stack.h"
#include <vector>
#include <iostream>

template<typename T>
struct stacks_set
{
public:
    stacks_set(const int& limit) :vec_st(0), limit(limit), st(new stack<T>) {}
    //~stacks_set();
    void push(const T& el);
    void pop();
    void popAt(const int& index);
private:
    void over_stack();
    std::vector<stack<T>> vec_st;
    stack<T>* st;
    int limit;
};

template<typename T>
inline void stacks_set<T>::push(const T& el)
{
    st->push(el);
    if (st->get_size() == limit)
    {
        over_stack();
    }
}

template<typename T>
inline void stacks_set<T>::pop()
{
    if (!st->is_Empty())
    {
        st->pop();
    }
    else
    {
        *st = vec_st.at(vec_st.size() - 1);
        st->pop();
        vec_st.erase(vec_st.end() - 1);
        if (!st->is_Empty())
        {
            vec_st.push_back(*st);
            st->clear();
        }
    }
}

template<typename T>
inline void stacks_set<T>::popAt(const int& index)
{
    if (index > vec_st.size() - 1)
    {
        return;
    }
    *st = vec_st.at(index);
    st->pop();
    vec_st.erase(vec_st.begin() + index);
    if (!st->is_Empty())
    {
        vec_st.insert(vec_st.begin() + index, *st);
        st->clear();
    }
}

template<typename T>
inline void stacks_set<T>::over_stack()
{
    vec_st.push_back(*st);
    st->clear();
    st = new stack<T>();
}
