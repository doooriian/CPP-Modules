#include "../includes/RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>
#define RESET	"\033[0m"
#define RED		"\033[31m"

RobotomyRequestForm::RobotomyRequestForm()
: AForm("RobotomyRequestForm", 72, 45), _target("Default")
{
	std::cout << this->getName() << ": default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
: AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << this->getName() << ": constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
: AForm(other), _target(other._target)
{
	std::cout << this->getName() << ": copy constructor called" << std::endl;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << RED << this->getName() << ": default destructor called" << RESET << std::endl;
}

void	RobotomyRequestForm::executeAction() const
{
	std::cout << "Bzzzzz... Vrrrrr... *drilling noises" << std::endl;
	if (rand() % 2)
		std::cout << this->_target << " has been robotomized successfully!" << std::endl;
	else
		std::cout << this->_target << " robotomization has failed..." << std::endl;
}
