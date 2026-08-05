#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	srand(time(NULL));

	try
	{
		Bureaucrat boss("Boss",1);
		Bureaucrat worker("Worker",150);


		ShrubberyCreationForm shrubbery("home");

		RobotomyRequestForm robot("Bender");

		PresidentialPardonForm pardon("Arthur");


		boss.SignForm(shrubbery);
		boss.ExecuteForm(shrubbery);


		boss.SignForm(robot);
		boss.ExecuteForm(robot);


		boss.SignForm(pardon);
		boss.ExecuteForm(pardon);


		worker.ExecuteForm(pardon);
	}
	catch(std::exception &exception)
	{
		std::cout << exception.what() << std::endl;
	}

	return 0;
}