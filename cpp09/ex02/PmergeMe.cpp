#include "PmergeMe.hpp"

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <stdexcept>

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe& other)
	: _vector(other._vector), _deque(other._deque)
{
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
	{
		_vector = other._vector;
		_deque = other._deque;
	}
	return *this;
}

PmergeMe::~PmergeMe()
{
}

void PmergeMe::parseInput(int argc, char** argv)
{
	if (argc < 2)
		throw std::runtime_error("Error");

	for (int i = 1; i < argc; ++i)
	{
		std::string text(argv[i]);

		if (text.empty())
			throw std::runtime_error("Error");

		for (size_t j = 0; j < text.size(); ++j)
		{
			if (text[j] < '0' || text[j] > '9')
				throw std::runtime_error("Error");
		}

		char* end = NULL;
		long number = std::strtol(text.c_str(), &end, 10);

		if (*end != '\0' || number > 2147483647L)
			throw std::runtime_error("Error");

		_vector.push_back(static_cast<int>(number));
		_deque.push_back(static_cast<int>(number));
	}
}

std::vector<size_t> PmergeMe::jacobsthal(size_t count) const
{
	std::vector<size_t> result;

	size_t a = 1;
	size_t b = 3;

	while (b < count)
	{
		result.push_back(b);
		size_t next = b + 2 * a;
		a = b;
		b = next;
	}

	return result;
}

std::deque<size_t> PmergeMe::jacobsthalDeque(size_t count) const
{
	std::deque<size_t> result;

	size_t a = 1;
	size_t b = 3;

	while (b < count)
	{
		result.push_back(b);
		size_t next = b + 2 * a;
		a = b;
		b = next;
	}

	return result;
}

size_t PmergeMe::upperBoundVector(const std::vector<int>& values,
								   int value, size_t limit) const
{
	size_t left = 0;
	size_t right = limit;

	while (left < right)
	{
		size_t middle = left + (right - left) / 2;

		if (values[middle] <= value)
			left = middle + 1;
		else
			right = middle;
	}

	return left;
}

size_t PmergeMe::upperBoundDeque(const std::deque<int>& values,
								  int value, size_t limit) const
{
	size_t left = 0;
	size_t right = limit;

	while (left < right)
	{
		size_t middle = left + (right - left) / 2;

		if (values[middle] <= value)
			left = middle + 1;
		else
			right = middle;
	}

	return left;
}

void PmergeMe::insertVector(std::vector<int>& values,
							int value, size_t limit)
{
	size_t position = upperBoundVector(values, value, limit);
	values.insert(values.begin() + position, value);
}

void PmergeMe::insertDeque(std::deque<int>& values,
						   int value, size_t limit)
{
	size_t position = upperBoundDeque(values, value, limit);
	values.insert(values.begin() + position, value);
}

void PmergeMe::sortVector(std::vector<int>& values)
{
	if (values.size() <= 1)
		return;

	std::vector<int> large;
	std::vector<int> small;

	bool hasOdd = values.size() % 2 != 0;
	int oddValue = 0;

	if (hasOdd)
	{
		oddValue = values.back();
		values.pop_back();
	}

	for (size_t i = 0; i < values.size(); i += 2)
	{
		if (values[i] > values[i + 1])
		{
			large.push_back(values[i]);
			small.push_back(values[i + 1]);
		}
		else
		{
			large.push_back(values[i + 1]);
			small.push_back(values[i]);
		}
	}

	sortVector(large);

	std::vector<int> result = large;

	if (!small.empty())
	{
		insertVector(result, small[0], result.size());

		std::vector<size_t> order = jacobsthal(small.size());

		size_t previous = 1;

		for (size_t i = 0; i < order.size(); ++i)
		{
			size_t end = order[i];

			if (end > small.size())
				end = small.size();

			for (size_t j = end; j > previous; --j)
			{
				insertVector(result, small[j - 1], result.size());
			}

			previous = end;
		}

		for (size_t j = small.size(); j > previous; --j)
			insertVector(result, small[j - 1], result.size());
	}

	if (hasOdd)
		insertVector(result, oddValue, result.size());

	values = result;
}

void PmergeMe::sortDeque(std::deque<int>& values)
{
	if (values.size() <= 1)
		return;

	std::deque<int> large;
	std::deque<int> small;

	bool hasOdd = values.size() % 2 != 0;
	int oddValue = 0;

	if (hasOdd)
	{
		oddValue = values.back();
		values.pop_back();
	}

	for (size_t i = 0; i < values.size(); i += 2)
	{
		if (values[i] > values[i + 1])
		{
			large.push_back(values[i]);
			small.push_back(values[i + 1]);
		}
		else
		{
			large.push_back(values[i + 1]);
			small.push_back(values[i]);
		}
	}

	sortDeque(large);

	std::deque<int> result = large;

	if (!small.empty())
	{
		insertDeque(result, small[0], result.size());

		std::deque<size_t> order = jacobsthalDeque(small.size());

		size_t previous = 1;

		for (size_t i = 0; i < order.size(); ++i)
		{
			size_t end = order[i];

			if (end > small.size())
				end = small.size();

			for (size_t j = end; j > previous; --j)
			{
				insertDeque(result, small[j - 1], result.size());
			}

			previous = end;
		}

		for (size_t j = small.size(); j > previous; --j)
			insertDeque(result, small[j - 1], result.size());
	}

	if (hasOdd)
		insertDeque(result, oddValue, result.size());

	values = result;
}

void PmergeMe::sortWithVector()
{
	sortVector(_vector);
}

void PmergeMe::sortWithDeque()
{
	sortDeque(_deque);
}

void PmergeMe::printBefore() const
{
	std::cout << "Before:";

	for (size_t i = 0; i < _vector.size(); ++i)
		std::cout << " " << _vector[i];

	std::cout << std::endl;
}

void PmergeMe::printAfter() const
{
	std::cout << "After:";

	for (size_t i = 0; i < _vector.size(); ++i)
		std::cout << " " << _vector[i];

	std::cout << std::endl;
}

const std::vector<int>& PmergeMe::getVector() const
{
	return _vector;
}

const std::deque<int>& PmergeMe::getDeque() const
{
	return _deque;
}