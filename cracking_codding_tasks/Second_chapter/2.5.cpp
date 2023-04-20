/*
* Два числа хранятся в виде связных списков, в которых каждый узел представляет один разряд. Все цифры хранятся в обратном порядке, при этом
младший разряд (единицы) хранится в начале списка. Напишите функцию,
которая суммирует два числа и возвращает результат в виде связного списка.
Пример:
Ввод: (7->1->6) + (5->9->2), то есть 617 + 295.
Вывод: 2->1->9, то есть 912. 
*/

#include "../my_list.h"
#include <iostream>
#include <string>

std::optional<int> str_to_int(const char c)
{
    if (c >= '0' && c <= '9') {
        int i = 0;
        i = i * 10 + (c - '0');
        return i;
    }
    return std::nullopt;
}

//int main(int argc, const char* argv[])
//{
//    if (argc < 3)
//    {
//        std::cerr << "You input incorrect counts of agruments.\nYou need to input 2 numbers\n";
//    }
//
//    argv[1] = "95";
//    argv[2] = "617";
//
//    const std::string str = argv[1];
//    const std::string str2 = argv[2];
//
//    list<int> list1, list2;
//    for (char c : str)
//    {
//        const auto data = str_to_int(c);
//        if (!data.has_value())
//        {
//            std::cout << "Bad input\n";
//            return 1;
//        }
//        list1.push_front(data.value());
//    }
//    list1.print();
//
//    for (char c : str2)
//    {
//        const auto data = str_to_int(c);
//        if (!data.has_value())
//        {
//            std::cout << "Bad input\n";
//            return 1;
//        }
//        list2.push_front(data.value());
//    }
//    list2.print();
//
//    std::cout << "Result of sum lists\n";
//
//    auto res = list<int>::sum_lists(list1, list2);
//    
//    res.print();
//
//    return 0;
//}