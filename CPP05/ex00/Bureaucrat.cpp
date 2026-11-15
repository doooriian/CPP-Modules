#include "Bureaucrat.hpp"
#include <iostream>
#define RESET	"\033[0m"
#define RED		"\033[31m"


//Constructors and destructors
Bureaucrat::Bureaucrat()
: _name("Nobody"), _grade(150)
{
	std::cout << this->_name << ": Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name)
: _name(name), _grade(150)
{
	std::cout << this->_name << ": Bureaucrat name constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(int grade)
: _name("Unknown")
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
	std::cout << this->_name << ": Bureaucrat grade constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade)
: _name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
	std::cout << this->_name << ": Bureaucrat constructor called" << std::endl;
}


Bureaucrat::Bureaucrat(const Bureaucrat &other)
: _name(other._name), _grade(other._grade)
{
	std::cout << this->_name << ": Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &other)
{
	std::cout << this->_name << ": Bureaucrat copy assignment operator called" << std::endl;
	if (this != &other)
		this->_grade = other._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << RED << this->_name << ": Bureaucrat default Destructor called" << RESET << std::endl;
}

// Getters
std::string	Bureaucrat::getName() const
{
	return (this->_name);
}

int			Bureaucrat::getGrade() const
{
	return (this->_grade);
}

//Increments and decrements
void	Bureaucrat::promote()
{
	if (this->_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade--;
}

void	Bureaucrat::demote()
{
	if (this->_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade++;
}

//Exceptions
const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high: grade range is 1-150");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low: grade range is 1-150");
}

//Operator overload "<<"
std::ostream	&operator<<(std::ostream &out, const Bureaucrat &Bureaucrat)
{
	out << Bureaucrat.getName() << ", bureaucrat grade " << Bureaucrat.getGrade();
	return (out);
}
