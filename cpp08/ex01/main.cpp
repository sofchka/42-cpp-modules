#include <iostream>
#include <vector>
#include "Span.hpp"

int main()
{
    Span span(5);

    span.addNumber(6);
    span.addNumber(3);
    span.addNumber(17);
    span.addNumber(9);
    span.addNumber(11);

    try
    {
        std::cout << "Shortest span: "
                  << span.shortestSpan() << std::endl;

        std::cout << "Longest span: "
                  << span.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;

    Span rangeSpan(10);
    int values[] = {20, 5, 100, 35, 42, 8};

    rangeSpan.addRange(values, values + 6);

    std::cout << "Range shortest: "
              << rangeSpan.shortestSpan() << std::endl;

    std::cout << "Range longest: "
              << rangeSpan.longestSpan() << std::endl;

    std::cout << std::endl;

    try
    {
        Span small(2);

        small.addNumber(10);
        small.addNumber(20);
        small.addNumber(30);
    }
    catch (const std::exception &e)
    {
        std::cout << "Expected error: "
                  << e.what() << std::endl;
    }

    return 0;
}