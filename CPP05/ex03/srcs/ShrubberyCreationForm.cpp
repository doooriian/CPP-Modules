#include "../includes/ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>
#define RESET	"\033[0m"
#define RED		"\033[31m"

ShrubberyCreationForm::ShrubberyCreationForm()
: AForm("ShrubberyCreationForm", 145, 137), _target("Default")
{
	std::cout << this->getName() << ": default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
: AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << this->getName() << ": constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
: AForm(other), _target(other._target)
{
	std::cout << this->getName() << ": copy constructor called" << std::endl;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << RED << this->getName() << ": default destructor called" << RESET << std::endl;
}

void	ShrubberyCreationForm::executeAction() const
{
	std::ofstream	outfile(this->_target + "_shrubbery");

	if (!outfile.is_open())
	{
		std::cerr << "Error: could not create the file" << std::endl;
		return;
	}
	outfile << "           /\\                   /\\                   /\\\n";
	outfile << "          /**\\                 /**\\                 /**\\\n";
	outfile << "         /****\\               /****\\               /****\\\n";
	outfile << "        /******\\             /******\\             /******\\\n";
	outfile << "       /********\\           /********\\           /********\\\n";
	outfile << "      /**********\\         /**********\\         /**********\\\n";
	outfile << "           ||                   ||                   ||\n";
	outfile << "           ||                   ||                   ||\n";
	outfile << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	outfile.close();
}
