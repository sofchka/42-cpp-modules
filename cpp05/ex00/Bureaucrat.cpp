#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
}

Bureaucrat::Bureaucrat(const std::string &name, int grade)
	: _name(name), _grade(grade)
{
	if (_grade < 1)
		throw GradeTooHighException();
	if (_grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
	: _name(other._name), _grade(other._grade)
{
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
		_grade = other._grade;
	return *this;
}

Bureaucrat::~Bureaucrat()
{
}

const std::string &Bureaucrat::GetName() const
{
	return _name;
}

int Bureaucrat::GetGrade() const
{
	return _grade;
}

void Bureaucrat::IncrementGrade()
{
	if (_grade == 1)
		throw GradeTooHighException();
	_grade--;
}

void Bureaucrat::DecrementGrade()
{
	if (_grade == 150)
		throw GradeTooLowException();
	_grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "grade is too low";
}

std::ostream &operator<<(std::ostream &output_stream, const Bureaucrat &bureaucrat)
{
	output_stream << bureaucrat.GetName()
				  << ", bureaucrat grade "
				  << bureaucrat.GetGrade();
	return output_stream;
}