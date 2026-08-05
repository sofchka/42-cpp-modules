#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <exception>

class Bureaucrat;

class AForm
{
private:
	const std::string _name;
	bool _is_signed;
	const int _grade_to_sign;
	const int _grade_to_execute;

public:
	AForm();
	AForm(const std::string &name, int grade_to_sign, int grade_to_execute);
	AForm(const AForm &other);
	AForm &operator=(const AForm &other);
	virtual ~AForm();

	const std::string &GetName() const;
	bool GetIsSigned() const;
	int GetGradeToSign() const;
	int GetGradeToExecute() const;

	void BeSigned(const Bureaucrat &bureaucrat);

	void Execute(const Bureaucrat &executor) const;

	virtual void ExecuteAction() const = 0;

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

	class FormNotSignedException : public std::exception
	{
	public:
		const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &output_stream, const AForm &form);

#endif