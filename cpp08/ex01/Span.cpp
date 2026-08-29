#include "Span.hpp"

Span::Span() : _capacity(0)
{
}

Span::Span(unsigned int n) : _capacity(n)
{
}

Span::Span(const Span &other)
    : _capacity(other._capacity), _numbers(other._numbers)
{
}

Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        _capacity = other._capacity;
        _numbers = other._numbers;
    }
    return *this;
}

Span::~Span()
{
}

void Span::addNumber(int number)
{
    if (_numbers.size() >= _capacity)
        throw std::out_of_range("Span is full");

    _numbers.push_back(number);
}

unsigned int Span::shortestSpan() const
{
    if (_numbers.size() < 2)
        throw std::logic_error("Not enough numbers");

    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());

    unsigned int shortest = static_cast<unsigned int>(
        sorted[1] - sorted[0]
    );

    for (std::vector<int>::size_type i = 1; i < sorted.size(); ++i)
    {
        unsigned int current = static_cast<unsigned int>(
            sorted[i] - sorted[i - 1]
        );

        if (current < shortest)
            shortest = current;
    }

    return shortest;
}

unsigned int Span::longestSpan() const
{
    if (_numbers.size() < 2)
        throw std::logic_error("Not enough numbers");

    int minimum = *std::min_element(_numbers.begin(), _numbers.end());
    int maximum = *std::max_element(_numbers.begin(), _numbers.end());

    return static_cast<unsigned int>(maximum - minimum);
}