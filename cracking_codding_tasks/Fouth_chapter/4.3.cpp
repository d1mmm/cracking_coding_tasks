//#include "my_tree.h"
//#include <vector>
//
//int main()
//{
//    std::vector<int> vec{ 1, 5, 3, 8, 0, 4, 2 };
//    std::vector<int> vec{ 10, 11, 5, 3, 8, 0, 4, 2 };
//
//    Tree<int> tree;
//
//    for (const auto& el : vec)
//    {
//        tree.push(el);
//    }
//
//    tree.show();
//
//    std::cout << "\n===========\n" << std::endl;
//
//    auto lists = tree.make_lists();
//
//    for (auto it = lists.begin(); it != lists.end(); ++it)
//    {
//        for (auto it2 = it->begin(); it2 != it->end(); ++it2)
//        {
//            std::cout << *it2 << " ";
//        }
//        std::cout << std::endl;
//    }
//
//    return 0;
//}