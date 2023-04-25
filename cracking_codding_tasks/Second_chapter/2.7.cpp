/*
* Проверьте, пересекаются ли два заданных (одно-)связных списка. Верните
узел пересечения. Учтите, что пересечение определяется ссылкой, а не значением. Иначе говоря, если k-й узел первого связного списка точно совпадает
(по ссылке) сj-м узлом второго связного списка, то списки считаются пересекающимися. 
*/

#include "../my_list.h"
#include <iostream>

//int main()
//{
//    list<int> list1{ 1,2,3,4,5 };
//    auto el = list1.find_node_from_tail(4);
//    list<int> list2{ 1,3 };
//    if (!el.has_value())
//    {
//        std::cout << "list1 has not value\n";
//        return -1;
//    }
//    list2.push_back(el.value());
//    list2.push_back(4);
//   
//    list1.print();
//    list2.print();
//
//    auto res = list<int>::intersection(list1, list2);
//    if (res == nullptr)
//    {
//        std::cout << "Lists are not cross\n";
//    }
//    else
//    {
//        std::cout << "Lists are cross " << *res;
//    }
//
//    return 0;
//}