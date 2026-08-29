#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>

class Span
{
private:
    unsigned int        _capacity;
    std::vector<int>    _numbers;

public:
    Span();
    Span(unsigned int n);
    Span(const Span &other);
    Span &operator=(const Span &other);
    ~Span();

    void addNumber(int number);

    template <typename InputIterator>
    void addRange(InputIterator first, InputIterator last)
    {
        unsigned int amount = 0;
        InputIterator it = first;

        while (it != last)
        {
            ++amount;
            ++it;
        }

        if (_numbers.size() + amount > _capacity)
            throw std::out_of_range("Span capacity exceeded");

        _numbers.insert(_numbers.end(), first, last);
    }

    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;
};

#endif
