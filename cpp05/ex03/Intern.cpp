#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


Intern::Intern()
{
}

Intern::~Intern()
{
}


AForm *Intern::CreateShrubbery(std::string target)
{
	return new ShrubberyCreationForm(target);
}


AForm *Intern::CreateRobotomy(std::string target)
{
	return new RobotomyRequestForm(target);
}


AForm *Intern::CreatePresidential(std::string target)
{
	return new PresidentialPardonForm(target);
}



AForm *Intern::MakeForm(std::string form_name, std::string target)
{
	std::string form_names[3] =
	{
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};


	FormCreator form_creators[3] =
	{
		&Intern::CreateShrubbery,
		&Intern::CreateRobotomy,
		&Intern::CreatePresidential
	};


	for (int index = 0; index < 3; index++)
	{
		if (form_name == form_names[index])
		{
			std::cout
				<< "Intern creates "
				<< form_name
				<< std::endl;

			return form_creators[index](target);
		}
	}


	std::cout
		<< "Intern couldn't create "
		<< form_name
		<< " because it does not exist"
		<< std::endl;


	return NULL;
}