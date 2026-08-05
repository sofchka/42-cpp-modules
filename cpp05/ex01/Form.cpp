#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form()
	: _name("Default"), _is_signed(false), _grade_to_sign(150), _grade_to_execute(150)
{
}

Form::Form(const std::string &name, int grade_to_sign, int grade_to_execute)
	: _name(name),
	  _is_signed(false),
	  _grade_to_sign(grade_to_sign),
	  _grade_to_execute(grade_to_execute)
{
	if (_grade_to_sign < 1 || _grade_to_execute < 1)
		throw GradeTooHighException();

	if (_grade_to_sign > 150 || _grade_to_execute > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &other)
	: _name(other._name),
	  _is_signed(other._is_signed),
	  _grade_to_sign(other._grade_to_sign),
	  _grade_to_execute(other._grade_to_execute)
{
}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
		_is_signed = other._is_signed;
	return *this;
}

Form::~Form()
{
}

const std::string &Form::GetName() const
{
	return _name;
}

bool Form::GetIsSigned() const
{
	return _is_signed;
}

int Form::GetGradeToSign() const
{
	return _grade_to_sign;
}

int Form::GetGradeToExecute() const
{
	return _grade_to_execute;
}

void Form::BeSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.GetGrade() > _grade_to_sign)
		throw GradeTooLowException();

	_is_signed = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "grade is too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "grade is too low";
}

std::ostream &operator<<(std::ostream &output_stream, const Form &form)
{
	output_stream
		<< "Name: " << form.GetName()
		<< ", Signed: " << form.GetIsSigned()
		<< ", Grade to sign: " << form.GetGradeToSign()
		<< ", Grade to execute: " << form.GetGradeToExecute();

	return output_stream;
}