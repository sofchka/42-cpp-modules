#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>

class Bureaucrat;

class Form
{
private:
	const std::string _name;
	bool _is_signed;
	const int _grade_to_sign;
	const int _grade_to_execute;

public:
	Form();
	Form(const std::string &name, int grade_to_sign, int grade_to_execute);
	Form(const Form &other);
	Form &operator=(const Form &other);
	~Form();

	const std::string &GetName() const;
	bool GetIsSigned() const;
	int GetGradeToSign() const;
	int GetGradeToExecute() const;

	void BeSigned(const Bureaucrat &bureaucrat);

	class GradeTooHighException : public std::exception
	{
	public:
		const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &output_stream, const Form &form);

#endif