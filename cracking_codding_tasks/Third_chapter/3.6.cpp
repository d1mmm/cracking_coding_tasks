﻿/*
В приюте для животных есть только собаки и кошки, а работа осуществляется в порядке очереди. Люди должны каждый раз забирать •самое старое•
(по времени пребывания в питомнике) животное, но могут выбрать кошку
или собаку (животное в любом случае будет •самым старым•). Нельзя выбрать любое понравившееся животное. Создайте структуру данных, которая
обеспечивает функционирование этой системы и реализует операции enqueue,
dequeueAny, dequeueDog и dequeueCat. Разрешается использование встроенной
структуры данных Linked List.
*/

#include "../shelter.h"
#include <iostream>

int main()
{ 
    shelter<std::string> sh;
    sh.push("cat");
    sh.push("dog");
    sh.push("cat1");
    sh.push("dog1");


    for (int i = 0; i < sh.get_size(); ++i)
    {
        std::cout << sh[i] << std::endl;
    }
    std::cout << std::endl;

    sh.dequeueOne("cat");

    for (int i = 0; i < sh.get_size(); ++i)
    {
        std::cout << sh[i] << std::endl;
    }

    return 0;
}