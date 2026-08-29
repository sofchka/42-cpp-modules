#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main()
{
    std::vector<int> numbers;

    numbers.push_back(10);
    numbers.push_back(25);
    numbers.push_back(42);
    numbers.push_back(25);
    numbers.push_back(70);

    try
    {
        std::vector<int>::iterator it = easyfind(numbers, 25);
        std::cout << "Found: " << *it << std::endl;
        std::cout << "Position: " << (it - numbers.begin()) << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Value not found" << std::endl;
    }

    try
    {
        easyfind(numbers, 100);
    }
    catch (const std::exception &e)
    {
        std::cout << "100 was not found" << std::endl;
    }

    std::list<int> values;

    values.push_back(3);
    values.push_back(8);
    values.push_back(15);

    try
    {
        std::list<int>::iterator it = easyfind(values, 15);
        std::cout << "Found in list: " << *it << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Value not found in list" << std::endl;
    }

    return 0;
}
