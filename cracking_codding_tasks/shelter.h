#pragma once
#include "my_list.h"
#include <string>

template<typename T>
class shelter
{
public:
    shelter() {}
    void push(const T&& item);
    int get_size() { return l.get_size(); }
    void dequeueAny();
    void dequeueOne(const T& val);
    T& operator[](const int& el);
private:
    list<T> l;
};

template<typename T>
inline void shelter<T>::push(const T&& item)
{
    l.push_back(item);
}

template<typename T>
inline void shelter<T>::dequeueAny()
{
    l.pop_back();
}

template<typename T>
inline void shelter<T>::dequeueOne(const T& val)
{
    for (int i = 0; i < l.get_size(); ++i)
    {
        std::string str(l[i]);
        if (str._Starts_with(std::string(val)))
        {
            l.remove(str);
            return;
        }
    }
}

template<typename T>
inline T& shelter<T>::operator[](const int& el)
{
    return l[el];
}
