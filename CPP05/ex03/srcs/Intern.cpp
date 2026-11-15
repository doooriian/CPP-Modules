#include "../includes/Intern.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include <iostream>
#define RESET	"\033[0m"
#define RED		"\033[31m"

//Canonical Form
Intern::Intern()
{
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern &other)
{
	std::cout << "Intern copy constructor called" << std::endl;
}

Intern	&Intern::operator=(const Intern &other)
{
	std::cout << "Intern copy assignment operator called" << std::endl;
	return (*this);
}

Intern::~Intern()
{
	std::cout << RED << "Intern default destructor called" << RESET << std::endl;
}

//Form related functions

AForm	*Intern::makePresidential(const std::string &target) const
{
	return (new PresidentialPardonForm(target));
}

AForm	*Intern::makeRobotomy(const std::string &target) const
{
	return (new RobotomyRequestForm(target));
}

AForm	*Intern::makeShrubbery(const std::string &target) const
{
	return (new ShrubberyCreationForm(target));
}

AForm	*Intern::makeForm(const std::string &name, const std::string &target) const
{
	const int	formSize = 3;
	const std::string	formNames[formSize] =
	{
		"presidential pardon",
		"robotomy request",
		"shrubbery creation",
	};
	AForm	*(Intern::*const creators[formSize])(const std::string &) const =
	{
		&Intern::makePresidential,
		&Intern::makeRobotomy,
		&Intern::makeShrubbery,
	};

	for (int i = 0; i < formSize; i++)
		if (formNames[i] == name)
		{
			std::cout << "Intern creates " << name << std::endl;
			return ((this->*creators[i])(target));
		}
	std::cout << "Intern couldn't creates " << name << ": he didn't find this type of form" << std::endl;
	return (NULL);
}
