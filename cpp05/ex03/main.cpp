#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
	Intern intern;
	Bureaucrat boss("Boss", 1);

	AForm *form;

	form = intern.MakeForm("robotomy request", "Bender");

	if (form)
	{
		boss.SignForm(*form);
		boss.ExecuteForm(*form);

		delete form;
	}


	form = intern.MakeForm("wrong form", "Nobody");

	delete form;

	return 0;
}