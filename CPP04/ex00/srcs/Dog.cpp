#include "../includes/Dog.hpp"
#include <iostream>

Dog::Dog()
: Animal("Dog")
{
	std::cout << this->_type << ": Default constructor called" << std::endl;
}

Dog::Dog(const Dog &other)
: Animal(other)
{
	std::cout << this->_type << ": Copy constructor called" << std::endl;
}

Dog	&Dog::operator=(const Dog &other)
{
	if (this != &other)
		Animal::operator=(other);
	std::cout << this->_type << ": Copy assignment operator called" << std::endl;
	return (*this);
}

Dog::~Dog()
{
	std::cout << this->_type << ": Destructor called" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << this->_type << ": *Woof Woof*" << std::endl;
}
