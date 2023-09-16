#include "my_tree.h"
#include <vector>

int main()
{
    std::vector<int> vec{1, 2, 3, 4, 5, 6};
    Tree<int> tree;

    for (const auto &el : vec)
    {
        tree.push(el);
    }


    return 0;
}