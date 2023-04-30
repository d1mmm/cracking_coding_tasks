/*
* Для кольцевого связного списка реализуйте алгоритм, возвращающий начальный узел петли.
Определение
Кольцевой связный список - это связный список, в котором указатель следующего узла ссылается на более ранний узел, образуя петлю.
Пример:
Ввод: A->B->C- >D->E->C (предыдущий узел с)
Вывод: с
*/

#include "../my_list.h"
#include <iostream>

int main()
{
    list<char> l{ 'a','b','c','d','e' };
    int num = 3;
    l.create_ring_list(num);
    auto res = l.get_ring_node();
    if (res == nullptr)
    {
        std::cout << "Ring node does not find\n";
    }
    else
    {
        std::cout << "First inode is -> " << res->data << std::endl;
    }
    return 0;
}