#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#define RESET	"\033[0m"
#define RED		"\033[31m"


//Constructors and destructors
Form::Form()
: _name("Random Form"), _isSigned(false), _gradeToSign(2), _gradeToExecute(1)
{
	std::cout << this->_name << ": Form default constructor called" << std::endl;
}

Form::Form(const std::string &name)
: _name(name), _isSigned(false), _gradeToSign(2), _gradeToExecute(1)
{
	std::cout << this->_name << ": Form name constructor called" << std::endl;
}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
	else if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	std::cout << this->_name << ": Form constructor called" << std::endl;
}

Form::Form(const Form &other)
: _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	std::cout << this->_name << ": Form copy constructor called" << std::endl;
}

Form	&Form::operator=(const Form &other)
{
	std::cout << this->_name << ": Form copy assignment operator called" << std::endl;
	if (this != &other)
		this->_isSigned = other._isSigned;
	return (*this);
}

Form::~Form()
{
	std::cout << RED << this->_name << ": Form default destructor called" << RESET << std::endl;
}

//Getters
std::string	Form::getName() const
{
	return (this->_name);
}

bool		Form::getIsSigned() const
{
	return (this->_isSigned);
}

int			Form::getGradeToSign() const
{
	return (this->_gradeToSign);
}

int			Form::getGradeToExecute() const
{
	return (this->_gradeToExecute);
}

//Bureaucrat related function
void	Form::beSigned(const Bureaucrat &Bureaucrat)
{
	if (this->_isSigned == true)
		throw AlreadySignedException();
	else if (Bureaucrat.getGrade() > this->_gradeToSign)
		throw GradeTooLowException();
	else
		this->_isSigned = true;
}

//Exceptions
const char	*Form::GradeTooHighException::what() const throw()
{
	return ("the grade is too high");
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return ("the grade is too low");
}

const char	*Form::AlreadySignedException::what() const throw()
{
	return ("it's already signed");
}

//Operator overload "<<"
std::ostream	&operator<<(std::ostream &out, const Form &Form)
{
	out << "The form " << Form.getName() << " is ";
	if (Form.getIsSigned())
		out << "signed, ";
	else
		out << "not signed, ";
	out << "it requires a minimum grade of " << Form.getGradeToSign() << " to be signed " <<
	"and " << Form.getGradeToExecute() << " to be executed";
	return (out);
}
