#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	:AForm("ShrubberyCreationForm",145,137),
	_target(target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::ExecuteAction() const
{
	std::ofstream output_file;

	output_file.open((_target + "_shrubbery").c_str());

	output_file
		<< "      *\n"
		<< "     ***\n"
		<< "    *****\n"
		<< "   *******\n"
		<< "      ||\n";

	output_file.close();
}