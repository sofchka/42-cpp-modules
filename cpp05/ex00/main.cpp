#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat first_bureaucrat("Alice", 2);

		std::cout << first_bureaucrat << std::endl;

		first_bureaucrat.IncrementGrade();

		std::cout << first_bureaucrat << std::endl;

		first_bureaucrat.IncrementGrade();
	}
	catch (std::exception &exception)
	{
		std::cout << exception.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		Bureaucrat second_bureaucrat("Bob", 151);
	}
	catch (std::exception &exception)
	{
		std::cout << exception.what() << std::endl;
	}
}