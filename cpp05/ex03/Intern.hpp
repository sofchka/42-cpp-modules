#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class Intern
{
private:

	typedef AForm *(*FormCreator)(std::string target);

	static AForm *CreateShrubbery(std::string target);
	static AForm *CreateRobotomy(std::string target);
	static AForm *CreatePresidential(std::string target);

public:

	Intern();
	~Intern();

	AForm *MakeForm(std::string form_name, std::string target);
};

#endif