#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat boss("Boss", 1);
	Bureaucrat worker("Worker", 150);

	Form form("Contract", 50, 20);

	std::cout << form << std::endl;

	worker.SignForm(form);
	boss.SignForm(form);

	std::cout << form << std::endl;

	return 0;
}