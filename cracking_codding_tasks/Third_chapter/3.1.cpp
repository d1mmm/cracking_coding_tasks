#include "../my_stack.h"
#include <iostream>

int main()
{
    stack<int> stack({1,2,3});
    for(int i = 0; i < stack.get_size(); ++i)
    {
        std::cout << stack[i] << std::endl;
    }
    return 0;
}