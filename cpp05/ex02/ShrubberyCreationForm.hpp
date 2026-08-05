#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
	std::string _target;

public:
	ShrubberyCreationForm(std::string target);
	~ShrubberyCreationForm();

	void ExecuteAction() const;
};

#endif