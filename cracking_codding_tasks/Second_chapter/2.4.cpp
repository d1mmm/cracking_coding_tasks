﻿/*
* Напишите код для разбиения связного списка вокруг значения х, так чтобы
все узлы, меньшие х, предшествовали узлам, большим или равным х. Если х
содержится в списке, то значения х должны следовать строго после элементов, меньших х (см. далее). Элемент разбивки х может находиться где угодно
в �правой части»; он не обязан располагаться между левой и правой частью.
Пример:
Ввод: 3->5->8->5- >10->2->1 [значение разбивки = 5]
Вывод: 3 ->1->2->10->5->5->8 
*/

#include "../my_list.h"
#include <iostream>

//int main()
//{
//    list<int> list({3,5,8,5,10,2,1});
//    int x = 0;
//    list.print();
//    std::cout << "Enter x -> ";
//    std::cin >> x;
//    std::cout << "List after spliting through " << x << std::endl << std::endl;
//    list.split(x);
//    list.print();
//    
//    return 0;
//}