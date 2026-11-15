#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"
#include <iostream>
#define RESET	"\033[0m"
#define RED		"\033[31m"


//Constructors and destructors
AForm::AForm()
: _name("Random AForm"), _isSigned(false), _gradeToSign(2), _gradeToExecute(1)
{
	std::cout << this->_name << ": AForm default constructor called" << std::endl;
}

AForm::AForm(const std::string &name)
: _name(name), _isSigned(false), _gradeToSign(2), _gradeToExecute(1)
{
	std::cout << this->_name << ": AForm name constructor called" << std::endl;
}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute)
: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
	else if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	std::cout << this->_name << ": AForm constructor called" << std::endl;
}

AForm::AForm(const AForm &other)
: _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	std::cout << this->_name << ": AForm copy constructor called" << std::endl;
}

AForm	&AForm::operator=(const AForm &other)
{
	std::cout << this->_name << ": AForm copy assignment operator called" << std::endl;
	if (this != &other)
		this->_isSigned = other._isSigned;
	return (*this);
}

AForm::~AForm()
{
	std::cout << RED << this->_name << ": AForm default destructor called" << RESET << std::endl;
}

//Getters
std::string	AForm::getName() const
{
	return (this->_name);
}

bool		AForm::getIsSigned() const
{
	return (this->_isSigned);
}

int			AForm::getGradeToSign() const
{
	return (this->_gradeToSign);
}

int			AForm::getGradeToExecute() const
{
	return (this->_gradeToExecute);
}

//Bureaucrat related function
void	AForm::beSigned(const Bureaucrat &Bureaucrat)
{
	if (this->_isSigned == true)
		throw AlreadySignedException();
	else if (Bureaucrat.getGrade() > this->_gradeToSign)
		throw GradeTooLowException();
	else
		this->_isSigned = true;
}

void	AForm::execute(const Bureaucrat &executor) const
{
	if (this->_isSigned == false)
		throw NotSignedException();
	else if (executor.getGrade() > this->getGradeToExecute())
		throw GradeTooLowException();
	else
		executeAction();
}

//Exceptions
const char	*AForm::GradeTooHighException::what() const throw()
{
	return ("the grade is too high");
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return ("the grade is too low");
}

const char	*AForm::AlreadySignedException::what() const throw()
{
	return ("it's already signed");
}

const char	*AForm::NotSignedException::what() const throw()
{
	return ("the form is not signed, so it can't be executed");
}

//Operator overload "<<"
std::ostream	&operator<<(std::ostream &out, const AForm &AForm)
{
	out << "The Aform " << AForm.getName() << " is ";
	if (AForm.getIsSigned())
		out << "signed, ";
	else
		out << "not signed, ";
	out << "it requires a minimum grade of " << AForm.getGradeToSign() << " to be signed " <<
	"and " << AForm.getGradeToExecute() << " to be executed";
	return (out);
}
