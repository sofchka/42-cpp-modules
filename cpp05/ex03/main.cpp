#include "Bureaucrat.hpp"
#include "Intern.hpp"


int main()
{
	try
	{
		Intern random_intern;

		AForm *first_form;

		first_form = random_intern.MakeForm(
			"robotomy request",
			"Bender"
		);


		if (first_form)
		{
			Bureaucrat boss("Boss", 1);

			boss.SignForm(*first_form);
			boss.ExecuteForm(*first_form);

			delete first_form;
		}



		AForm *second_form;

		second_form = random_intern.MakeForm(
			"wrong form",
			"Nobody"
		);


		if (second_form)
			delete second_form;

	}
	catch(std::exception &exception)
	{
		std::cout
			<< exception.what()
			<< std::endl;
	}


	return 0;
}