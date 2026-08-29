#include <iostream>
#include <list>
#include "MutantStack.hpp"

int main()
{
    MutantStack<int> stack;

    stack.push(5);
    stack.push(17);

    std::cout << "Top: " << stack.top() << std::endl;

    stack.pop();

    std::cout << "Size: " << stack.size() << std::endl;

    stack.push(3);
    stack.push(5);
    stack.push(737);
    stack.push(0);

    std::cout << "Contents:" << std::endl;

    MutantStack<int>::iterator it = stack.begin();
    MutantStack<int>::iterator end = stack.end();

    while (it != end)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    std::cout << std::endl;

    std::list<int> list;

    list.push_back(5);
    list.push_back(3);
    list.push_back(5);
    list.push_back(737);
    list.push_back(0);

    std::cout << "List contents:" << std::endl;

    std::list<int>::iterator listIt = list.begin();
    std::list<int>::iterator listEnd = list.end();

    while (listIt != listEnd)
    {
        std::cout << *listIt << std::endl;
        ++listIt;
    }

    return 0;
}