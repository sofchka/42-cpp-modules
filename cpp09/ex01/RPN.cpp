#include "RPN.hpp"

#include <stdexcept>
#include <cstdlib>

RPN::RPN()
{
}

RPN::RPN(const RPN& other)
	: _numbers(other._numbers)
{
}

RPN& RPN::operator=(const RPN& other)
{
	if (this != &other)
		_numbers = other._numbers;
	return *this;
}

RPN::~RPN()
{
}

bool RPN::isNumber(char c) const
{
	return c >= '0' && c <= '9';
}

bool RPN::isOperator(char c) const
{
	return c == '+' || c == '-' || c == '*' || c == '/';
}

void RPN::calculate(char operation)
{
	if (_numbers.size() < 2)
		throw std::runtime_error("Error");

	int right = _numbers.top();
	_numbers.pop();

	int left = _numbers.top();
	_numbers.pop();

	if (operation == '+')
		_numbers.push(left + right);
	else if (operation == '-')
		_numbers.push(left - right);
	else if (operation == '*')
		_numbers.push(left * right);
	else if (operation == '/')
	{
		if (right == 0)
			throw std::runtime_error("Error");
		_numbers.push(left / right);
	}
}

int RPN::evaluate(const std::string& expression)
{
	while (!_numbers.empty())
		_numbers.pop();

	for (size_t i = 0; i < expression.size(); ++i)
	{
		char token = expression[i];

		if (token == ' ')
			continue;

		if (isNumber(token))
		{
			if (i + 1 < expression.size() &&
				expression[i + 1] != ' ')
				throw std::runtime_error("Error");

			_numbers.push(token - '0');
		}
		else if (isOperator(token))
		{
			calculate(token);
		}
		else
		{
			throw std::runtime_error("Error");
		}
	}

	if (_numbers.size() != 1)
		throw std::runtime_error("Error");

	return _numbers.top();
}