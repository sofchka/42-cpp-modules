#include <iostream>
#include <string>

#include "whatever.hpp"

int main()
{
	int a = 2;
	int b = 3;

	::swap(a, b);

	std::cout << "a = " << a
			  << ", b = " << b << std::endl;

	std::cout << "min(a, b) = "
			  << ::min(a, b) << std::endl;

	std::cout << "max(a, b) = "
			  << ::max(a, b) << std::endl;

	std::string first = "chaine1";
	std::string second = "chaine2";

	::swap(first, second);

	std::cout << "first = " << first
			  << ", second = " << second << std::endl;

	std::cout << "min(first, second) = "
			  << ::min(first, second) << std::endl;

	std::cout << "max(first, second) = "
			  << ::max(first, second) << std::endl;

	return 0;
}