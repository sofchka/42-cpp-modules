#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class Bureaucrat
{
private:
	const std::string _name;
	int _grade;

public:
	Bureaucrat();
	Bureaucrat(const std::string &name, int grade);
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &other);
	~Bureaucrat();

	const std::string &GetName() const;
	int GetGrade() const;

	void IncrementGrade();
	void DecrementGrade();

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

std::ostream &operator<<(std::ostream &output_stream, const Bureaucrat &bureaucrat);

#endif