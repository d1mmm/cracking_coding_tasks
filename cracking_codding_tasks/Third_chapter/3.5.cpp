/*
* Напишите программу сортировки стека, в результате которой наименьший
элемент оказывается на вершине стека. Вы можете использовать дополнительный временный стек, но элементы не должны копироваться в другие
структуры данных (например, в массив). Стек должен поддерживать следующие операции: push, рор, peek, isEmpty. 
*/

#include "../my_stack.h"
#include <iostream>

int main()
{ 
    stack<int> q;
    q.push(1);
    q.push(2);
    q.push(5);
    q.push(3);
    q.push(4);

    for (auto i = 0; i < q.get_size(); ++i)
    {
        std::cout << q[i] << std::endl;
    }

    q.sort();
    
    std::cout << std::endl;

    for (auto i = 0; i < q.get_size(); ++i)
    {
        std::cout << q[i] << std::endl;
    }


    return 0;
}