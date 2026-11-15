#include "../includes/Dog.hpp"
#include <iostream>

Dog::Dog()
: Animal("Dog")
{
	this->_brain = new Brain;
	std::cout << this->_type << ": Default constructor called" << std::endl;
}

Dog::Dog(const Dog &other)
: Animal(other)
{
	this->_brain = new Brain(*other._brain);
	std::cout << this->_type << ": Copy constructor called" << std::endl;
}

Dog	&Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		*this->_brain = *other._brain;
	}
	std::cout << this->_type << ": Copy assignment operator called" << std::endl;
	return (*this);
}

Dog::~Dog()
{
	delete (this->_brain);
	std::cout << this->_type << ": Destructor called" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << this->_type << ": *Woof Woof*" << std::endl;
}

Brain	*Dog::getBrain() const
{
	return (_brain);
}
