#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat boss("Boss", 1);

	ShrubberyCreationForm shrubbery("home");
	RobotomyRequestForm robot("Bender");
	PresidentialPardonForm pardon("Arthur");

	boss.SignForm(shrubbery);
	boss.ExecuteForm(shrubbery);

	boss.SignForm(robot);
	boss.ExecuteForm(robot);

	boss.SignForm(pardon);
	boss.ExecuteForm(pardon);

	return 0;
}