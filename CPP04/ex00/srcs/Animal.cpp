#include "../includes/Animal.hpp"
#include <iostream>

Animal::Animal()
: _type("Animal")
{
	std::cout << this->_type << ": Default constructor called" << std::endl;
}

Animal::Animal(const std::string &type)
: _type(type)
{
		std::cout << this->_type << ": Constructor called" << std::endl;
}

Animal::Animal(const Animal &other)
: _type(other._type)
{
	std::cout << this->_type << ": Copy constructor called" << std::endl;
}

Animal	&Animal::operator=(const Animal &other)
{
	if (this != &other)
		this->_type = other._type;
	std::cout << this->_type << ": Copy assignment operator called" << std::endl;
	return (*this);
}

Animal::~Animal()
{
	std::cout << this->_type << ": Destructor called" << std::endl;
}

std::string	Animal::getType() const
{
	return (this->_type);
}

void	Animal::makeSound() const
{
	std::cout << this->_type << ": *Unknown sound*" << std::endl;
}
