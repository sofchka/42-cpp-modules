#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat first_bureaucrat("Alice", 20);
	Bureaucrat second_bureaucrat("Bob", 100);

	Form first_form("Tax Form", 50, 20);

	std::cout << first_form << std::endl;

	second_bureaucrat.SignForm(first_form);

	first_bureaucrat.SignForm(first_form);

	std::cout << first_form << std::endl;

	return 0;
}