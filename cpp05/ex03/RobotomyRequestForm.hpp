#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
	std::string _target;

public:
	RobotomyRequestForm(std::string target);
	~RobotomyRequestForm();

	void ExecuteAction() const;
};

#endif