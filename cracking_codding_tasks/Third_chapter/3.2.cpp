/*
* Как реализовать стек, в котором кроме стандартных функций push и рор будет
поддерживаться функция min, возвращающая минимальный элемент? Все
операции - push, рор и min - должны выполняться за время 0(1 ).
*/

#include "../my_stack.h"
#include <iostream>

//int main()
//{
//    stack<int> s;
//    s.push(2);
//    s.push(3);
//    s.push(4);
//    s.push(1);
//    s.push(5);
//
//    auto min = s.min();
//
//    std::cout << "Min element from stack -> " << min << std::endl;
//
//    return 0;
//}