#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm()
	: _name("Default"),
	  _is_signed(false),
	  _grade_to_sign(150),
	  _grade_to_execute(150)
{
}

AForm::AForm(const std::string &name,
	int grade_to_sign,
	int grade_to_execute)
	: _name(name),
	  _is_signed(false),
	  _grade_to_sign(grade_to_sign),
	  _grade_to_execute(grade_to_execute)
{
	if (grade_to_sign < 1 || grade_to_execute < 1)
		throw GradeTooHighException();

	if (grade_to_sign > 150 || grade_to_execute > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &other)
	: _name(other._name),
	  _is_signed(other._is_signed),
	  _grade_to_sign(other._grade_to_sign),
	  _grade_to_execute(other._grade_to_execute)
{
}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
		_is_signed = other._is_signed;

	return *this;
}

AForm::~AForm()
{
}

const std::string &AForm::GetName() const
{
	return _name;
}

bool AForm::GetIsSigned() const
{
	return _is_signed;
}

int AForm::GetGradeToSign() const
{
	return _grade_to_sign;
}

int AForm::GetGradeToExecute() const
{
	return _grade_to_execute;
}

void AForm::BeSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.GetGrade() > _grade_to_sign)
		throw GradeTooLowException();

	_is_signed = true;
}

void AForm::Execute(const Bureaucrat &executor) const
{
	if (!_is_signed)
		throw FormNotSignedException();

	if (executor.GetGrade() > _grade_to_execute)
		throw GradeTooLowException();

	ExecuteAction();
}


const char *AForm::GradeTooHighException::what() const throw()
{
	return "grade too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "grade too low";
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return "form is not signed";
}


std::ostream &operator<<(std::ostream &output_stream,
	const AForm &form)
{
	output_stream
		<< form.GetName()
		<< " signed: "
		<< form.GetIsSigned()
		<< " sign grade: "
		<< form.GetGradeToSign()
		<< " execute grade: "
		<< form.GetGradeToExecute();

	return output_stream;
}