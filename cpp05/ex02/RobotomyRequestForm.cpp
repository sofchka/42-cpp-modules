#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	:AForm("RobotomyRequestForm",72,45),
	_target(target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::ExecuteAction() const
{
	std::cout
		<< "Brrrrrrrrrrr drilling noises..."
		<< std::endl;

	if (rand() % 2)
	{
		std::cout
			<< _target
			<< " has been robotomized successfully"
			<< std::endl;
	}
	else
	{
		std::cout
			<< "Robotomy failed"
			<< std::endl;
	}
}